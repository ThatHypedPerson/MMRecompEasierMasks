# Majora's Mask: Recompiled Easier Masks Mod

This is a mod for Majora's Mask: Recompiled that lets you switch out of your current transformation back to human by selecting and wearing a new mask.

This is meant to replicate how Majora's Mask 3D handles masks and saves a few annoying button presses.

## Building
> The following will let you build the mod from source. For more detailed instructions and information on the modding framework, see the [modding template](https://github.com/Zelda64Recomp/MMRecompModTemplate).

### Tools
You'll need to install `clang` and `make` to build this mod.
* On Windows, using [chocolatey](https://chocolatey.org/) to install both is recommended. The packages are `llvm` and `make` respectively.
  * The LLVM 19.1.0 [llvm-project](https://github.com/llvm/llvm-project) release binary, which is also what chocolatey provides, does not support MIPS correctly. The solution is to install 18.1.8 instead, which can be done in chocolatey by specifying `--version 18.1.8` or by downloading the 18.1.8 release directly.
* On Linux, these can both be installed using your distro's package manager.
* On MacOS, these can both be installed using Homebrew. Apple clang won't work, as you need a mips target for building the mod code.

On Linux and MacOS, you'll need to also ensure that you have the `zip` utility installed.

You'll also need to build [N64Recomp](https://github.com/N64Recomp/N64Recomp) for the `RecompModTool` utility.

### Building
* First, run `make` (with an optional job count) to build the mod code itself.
* Next, run the `RecompModTool` utility with `mod.toml` as the first argument and the build dir (`build` in the case of this mod) as the second argument.
  * This will produce your mod's `.nrm` file in the build folder.