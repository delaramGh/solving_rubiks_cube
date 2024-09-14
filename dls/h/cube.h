#ifndef _CUBE_H
#define _CUBE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
#include <time.h>


/*
        00 01              (top, w)
        10 11

80 81   20 21   100 101    (right, o)
90 91   30 31   110 111

        40 41              (bottom, y)
        50 51

        60 61              (back, g)
        70 71
*/


class Cube
{
private:
    std::vector<std::vector<int>> data;

public:
    Cube(int a = 1);      //if 0, gets input from the client.
    void show();

    void top2right();       //move 1.
    void top2left();        //move 2.
    void front2right();     //move 3.
    void front2left();      //move 4.
    void left2up();         //move 5.
    void left2down();       //move 6.

    bool check();
    bool check_this_choice(std::vector<int> &dir, int i);
    void move(size_t i);
    void shuffle(size_t j);
    bool solve(std::vector<int> dir);
};

void color_detection(int a);
void color_reset();

#endif
