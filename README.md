# LLVM String Analysis & Transformation Plugin

This project implements a custom LLVM plugin with both **analysis** and **transformation** passes. It identifies global string literals in LLVM IR and optionally reverses them in-place.

The plugin is built using LLVM’s **modern pass manager**, and integrates with the `opt` tool for pass testing and pipeline configuration.

> **Note:** This project is based on the excellent tutorial series by Jonathan Smith on YouTube:  
> [🔗 LLVM Plugin Development Tutorial (YouTube)](https://www.youtube.com/watch?v=zlD2MpU7XIw)

---

## 🛠 Features

- **StringAnalyzer**: An analysis pass that scans global variables in the module and identifies null-terminated string literals.
- **StringReverser**: A transformation pass that reverses the content of each detected string literal directly in the IR.
- Passes can be run independently or chained via `opt`.

---

## 📦 Requirements

- **LLVM** (tested with version X.X.X – fill in your version)
  - Must be **built from source or installed with `opt` and development headers**
  - The plugin is compatible with LLVM built in either Debug or Release mode — but your plugin build must match the `_ITERATOR_DEBUG_LEVEL`

- **CMake 3.16+**
- A C++ compiler (Clang or MSVC; this project was developed with `clang-cl` targeting MSVC ABI)
- `opt` command-line tool from the LLVM distribution

---

## 🧪 Example Usage

### 1. Compile a `.c` test file to LLVM IR:

```bash
clang -S -emit-llvm test.c -o test.ll
```

2. Run the plugin with opt:

```bash
opt -load-pass-plugin ./build/lib/LLVM-Tutorial.dll \
     -passes="string-reverser,print<string-analyzer>" \
     test.ll -S -o transformed.ll
```

🛠 Building the Plugin

This project uses a CMake-based build system. Example:

```bash
cmake --preset project-debug
cmake --build --preset project-debug
```
If you’re not using presets, set LLVM_DIR manually to your LLVM install:

```bash
cmake -DLLVM_DIR="path/to/llvm/lib/cmake/llvm" ..
```

The resulting plugin (LLVM-Tutorial.dll) can be loaded into opt.
🚫 .vs Folder Not Included

Due to GitHub file size limits and best practices, the .vs folder (Visual Studio metadata) is not included in this repository. To build using Visual Studio:

  Open the project root with CMake Tools for VS

  Configure the project

  Select your desired build preset (Debug or Release)

  Build the solution to generate the DLL

📚 Credits

This project is based on the tutorial by Jonathan Smith on YouTube:
LLVM Plugin Tutorial – Jonathan Smith

Additional development, integration, and debugging work by Michael Clausen.
🧠 License

This project is intended for learning and demonstration purposes. Derivatives based on the original tutorial code should comply with any license conditions Jonathan Smith provides. Otherwise, you’re free to adapt and use this code as needed.

