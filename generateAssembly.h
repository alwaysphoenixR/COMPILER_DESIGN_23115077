#ifndef GENERATEASSEMBLY_H
#define GENERATEASSEMBLY_H

#include "ast.h"
#include <vector>
#include <ostream>


void generateAssembly(const std::vector<Assignment>& program, std::ostream& out);

#endif
