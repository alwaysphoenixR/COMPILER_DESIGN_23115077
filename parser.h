#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include "ast.h"
#include <vector>

std::vector<Assignment> parse(const std::vector<Token>& tokens);

#endif
