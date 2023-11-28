#!/bin/bash
# Packs up the created files by the release workflow
# which are then uploaded as release assets in any release.
# These files are required to use the library.
#
# Arguments:
# [0]: The filename of the script, reserved by Bash.
# [1]: The mode that will be used. `0` for Windows and `1` for Unix.

if [ "$1" != "0" ] && [ "$1" != "1" ]; then
    echo "Usage: ./$0 <mode>"
    echo "Check the script for full argument information."
    exit 1
fi

mkdir -p library

if [ "$1" == "0" ]; then # Windows
    mkdir -p library/windows

    if [ ! -d Release ] && [ ! -d x64/Release ]; then
        echo "Library files not found. Exiting script."
        exit 1
    fi

    # 64-bit ZIP
    cd x64/Release
    7z a -mx=9 -tzip ../../dsptool-win64.zip dsptool.dll dsptool.lib dsptool.exp
    cd ../../dsptool
    7z a -mx=9 -tzip ../dsptool-win64.zip dsptool.h

    # 64-bit TAR
    cd ../x64/Release
    7z a -mx=9 -ttar ../../dsptool-win64.tar dsptool.dll dsptool.lib dsptool.exp
    cd ../../dsptool
    7z a -mx=9 -ttar ../dsptool-win64.tar dsptool.h

    cd ..

    # 32-bit ZIP
    cd Release
    7z a -mx=9 -tzip ../dsptool-win32.zip dsptool.dll dsptool.lib dsptool.exp
    cd ../dsptool
    7z a -mx=9 -tzip ../dsptool-win32.zip dsptool.h

    # 32-bit TAR
    cd ../Release
    7z a -mx=9 -ttar ../dsptool-win32.tar dsptool.dll dsptool.lib dsptool.exp
    cd ../dsptool
    7z a -mx=9 -ttar ../dsptool-win32.tar dsptool.h

    cd ..

    # Use the GZip compression algorithm
    7z a -mx=9 -tgzip dsptool-win64.tar.gz dsptool-win64.tar
    7z a -mx=9 -tgzip dsptool-win32.tar.gz dsptool-win32.tar

    # We're going to use TAR.GZ files
    rm dsptool-win64.tar
    rm dsptool-win32.tar

    mv dsptool-win64.zip library/windows
    mv dsptool-win32.zip library/windows
    mv dsptool-win64.tar.gz library/windows
    mv dsptool-win32.tar.gz library/windows
elif [ "$1" == "1" ]; then # Unix
    os=""
    filename=""

    if [ "$OSTYPE" == "linux-gnu" ]; then
        os="linux"
        filename="dsptool.so"
    else
        os="macos"
        filename="dsptool.dylib"
    fi

    mkdir -p "library/unix"

    # Does the file exist?
    if [ ! -f $filename ]; then
        echo "Library files not found. Exiting script."
        exit 1
    fi

    7z a -mx=9 -tzip dsptool-$os.zip $filename
    7z a -mx=9 -ttar dsptool-$os.tar $filename

    # Use the GZip compression algorithm
    7z a -mx=9 -tgzip dsptool-$os.tar.gz dsptool-$os.tar
    rm dsptool-$os.tar

    mv dsptool-$os.zip library/unix
    mv dsptool-$os.tar.gz library/unix
fi
