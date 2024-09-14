#include <iostream>
#include "cube.h"
#include "bidirectional.h"


int main()
{
    color_detection(0);
    std::cout<<"          -------------------------------    \n";
    std::cout<<"          *** WELCOME TO CUBE SOLVER! ***    \n";
    std::cout<<"          -------------------------------    \n\n";
    color_reset();

    ui_solve();
    
    return 0;
}


