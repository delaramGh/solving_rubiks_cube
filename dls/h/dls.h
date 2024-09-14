#ifndef _DLS_H
#define _DLS_H

#include "cube.h"

bool DLS(Cube &c,std::vector<int> &dir);
bool DLS(Cube &c,std::vector<int> &dir, size_t limit);
bool IDDFS(size_t max_depth, Cube c, std::vector<int> &dir);
void ui_solve(const char*);

#endif
