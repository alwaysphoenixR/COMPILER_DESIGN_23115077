# COMPILER_DESIGN_23115077
custom_instruction 
# 🧠 SIGMOID Instruction Simulation using Custom Compiler

This project is a simulation of a custom compiler that supports a new instruction called `SIGMOID`. It demonstrates the full pipeline of compiling a custom language into x86 NASM assembly and simulating the result through Windows message boxes.

The compiler takes a high-level code file (like `x = 4.98\ny = SIGMOID(x)`), tokenizes and parses it, and then generates NASM assembly. The `SIGMOID` instruction is simulated in the output assembly, and the result (computed in advance) is displayed in a dialog box.

---

## 🚀 Features

- ✅ Custom syntax support for SIGMOID function
- ✅ Parses assignment and function expressions
- ✅ Generates NASM x86 assembly code
- ✅ Uses Windows API (`MessageBoxA`) for output
- ✅ Simple and clean structure for tokenizer, parser, and codegen

---

## 📂 Project Structure
│
├── main.cpp                     # Entry point for the compiler
├── tokenizer.cpp               # Lexical analyzer (tokenizer)
├── tokenizer.h
├── parser.cpp                  # Parses tokens into AST
├── parser.h
├── ast.h                       # Abstract Syntax Tree definitions
├── generateAssembly.cpp        # Converts AST to NASM assembly
├── generateAssembly.h
│
├── input.sage                  # Source code written in custom syntax (e.g., x = SIGMOID(10))
├── program.asm                 # Generated NASM assembly code
├── program.obj                 # Object file from NASM
├── program.exe                 # Final Windows executable showing MessageBox
│
├── README.md                   # Project documentation
---

## 📄 Example Input (`input.sage`)


x = 4.98
y = SIGMOID(x)
SIGMOID Applied: 0.9932


🛠️ How to Build & Run Everything
# 1. Compile the custom compiler to generate NASM assembly
g++ -o main.exe main.cpp generateAssembly.cpp parser.cpp tokenizer.cpp -std=c++11

# 2. Run the compiler on input.sage
main.exe

# ✅ This creates: program.asm

# 3. Assemble the generated NASM code
nasm -f win32 program.asm -o program.obj

# 4. Link the object file using GoLink
GoLink /entry _start program.obj user32.dll kernel32.dll

# ✅ This creates: program.exe

# 5. Run the final executable
program.exe

➡️ You’ll see a Windows MessageBox pop up with:
SIGMOID Applied: 0.9932

