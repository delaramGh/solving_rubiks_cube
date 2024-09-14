#ifndef _BD_H__
#define _BD_H_

#include "cube.h"

std::vector<Cube> next_breadth(std::vector<Cube> &prev_breadth);
std::vector<Cube> find_similar_node(std::vector<std::vector<Cube>> &all_nodes, std::vector<Cube> &breadth);
std::vector<Cube> _find_similar_node(std::vector<std::vector<Cube>> &all_nodes, std::vector<Cube> &breadth);
std::vector<Cube> bidirectional(Cube &c, size_t limit);
void bidirectional_answer(Cube &c, size_t limit);

void ui_solve();

#endif
