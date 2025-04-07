

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip> 
#include "tokenizer.h"
#include "parser.h"
#include "generateAssembly.h"
#include "ast.h"

void printAST(const std::shared_ptr<Expr>& expr, int indent = 2) {
    std::string space(indent, ' ');
    if (auto var = std::dynamic_pointer_cast<Variable>(expr)) {
        std::cout << space << " Variable: " << var->name << "\n";
    } else if (auto func = std::dynamic_pointer_cast<FunctionExpr>(expr)) {
        std::cout << space << " Function: " << func->funcName << "\n";
        printAST(func->arg, indent + 2);
    } else if (auto num = std::dynamic_pointer_cast<Number>(expr)) {
        std::cout << space << " Number: " << num->value << "\n";
    }
}

int main() {
    std::ifstream in("input.sage");
    std::string input((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    std::cout << "🔹 Step 1: Token Generation\n----------------------------\n";
    auto tokens = tokenize(input);
    for (const auto& token : tokens) {
        std::cout << std::setw(10) << " Token: " << token.text << "\n";
    }

    std::cout << "\n Step 2: Parse Tree (AST)\n----------------------------\n";
    auto program = parse(tokens);
    for (const auto& stmt : program) {
        std::cout << " Assignment to: " << stmt.target->name << "\n";
        printAST(stmt.expr, 4);
    }

    std::cout << "\n Step 3: Assembly Generation\n-------------------------------\n";
    std::ofstream out("program.asm");
    generateAssembly(program, out);
    std::cout << "Compiled successfully to program.asm\n";

    return 0;
}
