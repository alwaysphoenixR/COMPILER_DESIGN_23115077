#include "tokenizer.h"
#include <cctype>

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t pos = 0;
    while (pos < input.size()) {
        if (isspace(input[pos])) {
            ++pos;
            continue;
        }
        if (input.substr(pos, 7) == "SIGMOID") {
            tokens.push_back({TokenType::Keyword_SIGMOID, "SIGMOID"});
            pos += 7;
            continue;
        }
        if (input.substr(pos, 4) == "RELU") {
            tokens.push_back({TokenType::Keyword_RELU, "RELU"});
            pos += 4;
            continue;
        }
        if (isalpha(input[pos])) {
            std::string id;
            while (isalnum(input[pos])) id += input[pos++];
            tokens.push_back({TokenType::Identifier, id});
            continue;
        }
        if (isdigit(input[pos])) {
            std::string num;
            while (isdigit(input[pos])) num += input[pos++];
            tokens.push_back({TokenType::Number, num});
            continue;
        }
        switch (input[pos]) {
            case '=': tokens.push_back({TokenType::Equal, "="}); break;
            case '(': tokens.push_back({TokenType::LParen, "("}); break;
            case ')': tokens.push_back({TokenType::RParen, ")"}); break;
        }
        ++pos;
    }
    tokens.push_back({TokenType::EndOfFile, ""});
    return tokens;
}
