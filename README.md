👤 Author: RAJVEER SINGH
📧 Email: rajveersinghofficial.cse@gmail.com
🎓 Roll No: 23115077
📚 Semester: 4th
🏫 College: NIT Raipur
🧠 Branch: Computer Science and Engineering

# 🔧 Custom Compiler for SIGMOID Instruction

## 🚀 Project Overview

This project is a fully custom-built compiler pipeline that:
- Accepts input in a custom `.sage` language.
- Parses and tokenizes mathematical expressions with a **custom activation function** like `SIGMOID()`.
- Builds an Abstract Syntax Tree (AST).
- Generates **Three Address Code (TAC)** for intermediate representation.
- Compiles into **x86 Assembly**, then links it into a Windows `.exe`.
- Optionally shows the result:
  - via **Command Line**, or
  - using a **Windows MessageBox** (GUI style)!


---

## 📁 File Structure

```
.
├── main.cpp                 # Entry point: live interpreter + full compiler
├── tokenizer.cpp/.h        # Converts input into tokens
├── parser.cpp/.h           # Parses tokens into AST
├── ast.h                   # AST node definitions
├── interpreter.cpp/.h      # Interprets expressions & calculates results
├── tac_gen.cpp/.h          # Generates Three Address Code (TAC)
├── generateAssembly.cpp/.h # Converts AST to NASM-style x86 Assembly
├── input.sage              # Sample custom source code input (SIGMOID)
├── program.asm             # Generated NASM-style Assembly code
├── program.obj             # Assembled object file (x86)
├── program.exe             # Final Windows executable
├── dump.txt                # Disassembled view from objdump
├── README.md               # You are here
```

---

## 💻 How to Run

### ✅ 1. Write Custom Code

Edit `input.sage` with your custom expression, like:

```sage
x = SIGMOID(10)
```

You can use variables and arithmetic too:

```sage
a = 4 + 6
b = SIGMOID(a)
```

---

### 🛠️ 2. Build the Compiler

Compile the C++ project:

```bash
g++ main.cpp tokenizer.cpp parser.cpp interpreter.cpp tac_gen.cpp generateAssembly.cpp -o compiler
```

---

### 🧪 3. Run the Compiler

Choose one of two modes:

#### Option A: Command Line Mode

x = 5 + 7 * 8 + SIGMOID(12)
Enter your expression (or type 'exit'):
> x=5+7*8+SIGMOID(12)

 Step 1: Token Generation
----------------------------
   Token: x
   Token: =
   Token: 5
   Token: +
   Token: 7
   Token: *
   Token: 8
   Token: +
   Token: SIGMOID
   Token: (
   Token: 12
   Token: )

 Step 2: AST Construction
----------------------------
 Assignment to: x
    BinaryExpr: +
      BinaryExpr: +
        Number: 5
        BinaryExpr: *
          Number: 7
          Number: 8
      Function: SIGMOID
        Number: 12

 Step 3: Interpreter Evaluation
----------------------------
 x = 62.0000

 Step 4: TAC Generation
----------------------------
t0 = 7 * 8  
t1 = 5 + t0  
t2 = SIGMOID(12)  
t3 = t1 + t2  
x = t3  

 Step 5: Assembly Generation
----------------------------
 program.asm generated successfully.




#### Option B: Batch Mode (input from input.sage)

Update `main.cpp` to read from `input.sage` instead of live input — or modify the compiler to support both modes.

---

### ⚙️ 4. Assemble & Link



Assemble the generated `program.asm`:

```bash
nasm -f win32 program.asm -o program.obj
```

Link with system libraries:

```bash
GoLink program.obj user32.dll kernel32.dll
```

This creates:

```bash
program.exe
```

---

### 🎯 5. Output Options

#### ✅ Option 1: Command Line Output
x = 62.0000


#### ✅ Option 2: Windows MessageBox

The generated `program.exe` will show a MessageBox with your result 


## 📌 Summary Stats Example

 compiler even gives a summary like this:

 --- Compiler Summary Stats ---
 Compiled in: 0.0843s  
 Total Tokens: 13  
 Functions Used: SIGMOID  
 Variables Defined: x  

---

