# DSPTool

DspTool is a library for encoding and decoding audio in Nintendo's GameCube DSP-ADPCM format.\
This is an open-source implementation of Nintendo's `dsptool.dll` library. It can be used as a drop-in replacement for Nintendo's `dsptool.dll`.

## Building

### Unix

Install dependencies. Use GCC for Linux and Clang for macOS (assuming you have [Homebrew](https://github.com/homebrew) installed).

```bash
sudo apt-get update
sudo apt-get install gcc
```

```bash
brew install clang
```

Create the dynamic library. Use `.so` for Linux and `.dylib` for macOS.

```bash
<compiler> -shared -o dsptool.<os> dsptool/decode.c dsptool/encode.c dsptool/math.c
```

You should have the `.so` or `.dylib` file in the root directory of the project.\
For more information on how to use a dynamic library, see [**this article**](https://progidea.com/post/creating-and-using-dynamic-libraries-in-linux-c-programming/).

### Windows

1. Clone the repository.

```bash
git clone https://github.com/Thealexbarney/DspTool.git
```

2. Install the latest Microsoft [Visual Studio 2022](https://visualstudio.microsoft.com/) version with the Desktop Development with C++ workload.
    - You might need to install the C++/CLI support (v143) from the Individual Components tab.
3. Open the solution file (`dsptool.sln`) in Visual Studio.
4. Build the project using the Release configuration for the desired architecture.

For more information on how to use a dynamic library, check out the official [**Microsoft Learn**](https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170#create-a-client-app-that-uses-the-dll) tutorial.

## License

See the [**LICENSE**](LICENSE) file for full information and details.
