
#include "generateAssembly.h"
#include <cmath>
#include <iomanip>
#include <sstream>

void generateAssembly(const std::vector<Assignment>& program, std::ostream& out) {
    out << "section .data\n";

    for (const auto& stmt : program) {
        if (auto func = std::dynamic_pointer_cast<FunctionExpr>(stmt.expr)) {
            std::ostringstream msg;

            if (auto numberArg = std::dynamic_pointer_cast<Number>(func->arg)) {
                double x = numberArg->value;
                double result = 1.0 / (1 + std::exp(-x));
                msg << "Sigmoid(" << x << ") = " << std::fixed << std::setprecision(4) << result;
            } else if (auto varArg = std::dynamic_pointer_cast<Variable>(func->arg)) {
                msg << "Sigmoid(" << varArg->name << ") = [dynamic]";
            } else {
                msg << "Sigmoid applied.";
            }

            out << "    title db \"Sigmoid Result\",0\n";
            out << "    message db \"" << msg.str() << "\",0\n";
        }
    }

    out << R"(
section .text
global _start
extern MessageBoxA
extern ExitProcess

_start:
    push 0
    push title
    push message
    push 0
    call [MessageBoxA]
    push 0
    call [ExitProcess]
)";
}
