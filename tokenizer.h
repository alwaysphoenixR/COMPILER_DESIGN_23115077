#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

enum class TokenType {
    Identifier,
    Number,
    Equal,
    LParen,
    RParen,
    EndOfFile,
    Keyword_SIGMOID,
    Keyword_RELU
};

struct Token {
    TokenType type;
    std::string text;
};

std::vector<Token> tokenize(const std::string& input);

#endif
