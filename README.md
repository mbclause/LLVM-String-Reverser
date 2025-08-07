# LLVM String Reverser

This project is a minimal example of writing and using a custom LLVM pass to reverse string literals during compilation. It was created by following the tutorial ["Creating an LLVM Pass from Scratch"](https://www.youtube.com/watch?v=zlD2MpU7XIw) by **Jonathan Smith**.

The project includes a sample LLVM pass, IR files, and test code to demonstrate the transformation.

---

## 📁 Structure

- `LLVM-Tutorial/` – Main source folder containing:
  - `lib/` – Your custom LLVM pass
  - `include/` – Header files
  - `test.c` – Sample test file with string literals
  - `myfile.ll`, `reversed.ll` – Example LLVM IR before and after transformation
  - `build-project-debug/`, `out/` – Build outputs (may be empty without build steps)

---

## ⚙️ Requirements

To build and run this project, you will need:

- **LLVM** (tested with version used in the tutorial)
- **CMake**
- A C++ compiler (e.g., `clang++`, `g++`)
- Optionally, `ninja` or `make` for build configuration

---

## 🚀 How to Run

1. **Install LLVM** using your package manager or from source.
2. **Clone this repo** and navigate into the `LLVM-Tutorial/` directory.
3. Create a build directory:
   ```bash
   mkdir build
   cd build
   cmake .. -DLLVM_DIR=/path/to/your/llvm/cmake/modules
   make
  4. Run the custom pass on an LLVM IR file (e.g., myfile.ll) to produce reversed.ll.

    ❗ Note: You will need to update CMake paths to point to your LLVM installation.

📦 Missing Files

Due to GitHub size limits, the .vs directory (used by Visual Studio) was not included in this repo. If you're using Visual Studio, you may need to regenerate solution files or open the CMakeLists.txt directly.
🙏 Acknowledgments

  Based on the YouTube tutorial by Jonathan Smith

  Thanks to the LLVM community for documentation and tooling

📜 License

This project is for educational purposes and experimentation with LLVM pass development.
