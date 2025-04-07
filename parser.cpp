
#include "parser.h"
#include <stdexcept>

size_t current = 0;
Token currentToken;
std::vector<Token> tokenList;

Token advance() {
    if (current < tokenList.size()) currentToken = tokenList[current++];
    return currentToken;
}

bool match(TokenType type) {
    if (currentToken.type == type) {
        advance();
        return true;
    }
    return false;
}

Token consume(TokenType type) {
    if (!match(type)) throw std::runtime_error("Expected token");
    return currentToken;
}

std::shared_ptr<Expr> parseExpression() {
    if (currentToken.type == TokenType::Keyword_SIGMOID || currentToken.type == TokenType::Keyword_RELU) {
        std::string funcName = currentToken.text;
        advance();
        consume(TokenType::LParen);

        std::shared_ptr<Expr> argExpr;
        if (currentToken.type == TokenType::Number) {
            int value = std::stoi(currentToken.text);
            advance();
            argExpr = std::make_shared<Number>(value);
        } else if (currentToken.type == TokenType::Identifier) {
            std::string var = currentToken.text;
            advance();
            argExpr = std::make_shared<Variable>(var);
        } else {
            throw std::runtime_error("Expected number or identifier inside function call");
        }

        consume(TokenType::RParen);
        return std::make_shared<FunctionExpr>(funcName, argExpr);
    }

    if (currentToken.type == TokenType::Number) {
        int value = std::stoi(currentToken.text);
        advance();
        return std::make_shared<Number>(value);
    }

    if (currentToken.type == TokenType::Identifier) {
        std::string name = currentToken.text;
        advance();
        return std::make_shared<Variable>(name);
    }

    throw std::runtime_error("Unknown expression");
}

std::vector<Assignment> parse(const std::vector<Token>& tokens) {
    tokenList = tokens;
    current = 0;
    advance();
    std::vector<Assignment> program;
    while (currentToken.type != TokenType::EndOfFile) {
        std::string target = consume(TokenType::Identifier).text;
        consume(TokenType::Equal);
        auto expr = parseExpression();
        program.push_back({std::make_shared<Variable>(target), expr});
    }
    return program;
}
