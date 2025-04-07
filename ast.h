

#ifndef AST_H
#define AST_H

#include <memory>
#include <string>

struct Expr {
    virtual ~Expr() = default;
};

struct Variable : Expr {
    std::string name;
    Variable(const std::string& n) : name(n) {}
};

struct Number : Expr {
    int value;
    Number(int v) : value(v) {}
};

struct FunctionExpr : Expr {
    std::string funcName;
    std::shared_ptr<Expr> arg;
    FunctionExpr(const std::string& f, std::shared_ptr<Expr> a) : funcName(f), arg(a) {}
};

struct Assignment {
    std::shared_ptr<Variable> target;
    std::shared_ptr<Expr> expr;
};

#endif
