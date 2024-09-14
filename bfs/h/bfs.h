#ifndef _BFS_H
#define _BFS_H

#include "cube.h"

int check_cube_vector(std::vector<Cube> cube_v);
int BFS(Cube &c, std::vector<Cube> &breadth, size_t limit);

void ui_solve_();

#endif
