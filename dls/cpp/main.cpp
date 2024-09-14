#include <iostream>
#include "cube.h"
#include "dls.h"


int main()
{
    color_detection(0);
    std::cout<<"          -------------------------------    \n";
    std::cout<<"          *** WELCOME TO CUBE SOLVER! ***    \n";
    std::cout<<"          -------------------------------    \n\n";
    color_reset();
    std::cout<<"Enter the mothod you want to use to slove your cube. (1:DLS  2:IDDFS)\n";
    int method;
    std::cin>>method;
    
    if(method == 1)
        ui_solve("DLS");
    if(method == 2)
        ui_solve("IDDFS");
        
    return 0;
}

