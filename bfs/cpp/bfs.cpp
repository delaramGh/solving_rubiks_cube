#include "bfs.h"

int check_cube_vector(std::vector<Cube> cube_v)  //returns the index. (or -1 if no answer)
{
    for (size_t i = 0; i < cube_v.size(); i++)
        if(cube_v[i].check())
            return i;
    return -1;
}

int BFS(Cube &c, std::vector<Cube> &breadth, size_t limit)
{
    //if you wanted to change this "7", you SHOULD change that also in ui_solve_.
    if(limit == 7) breadth.push_back(c);
    if(limit <= 0) return -1;

    std::vector<Cube> breadth_copy{breadth};  //keeps the previous vector and cleans main vector.
    breadth.clear();
    size_t size = breadth_copy.size();
    for (size_t j = 0; j < size; j++)
    {
        Cube c1 = breadth_copy[j];
        for (size_t i{1}; i <= 6; i++)
        {
            Cube c2 = c1;
            c2.move(i);
            breadth.push_back(c2);
        }
    }
    int check = check_cube_vector(breadth);  //returns the index.
    if(check != -1)
        return check;
    return BFS(c, breadth, limit-1);    
}

void ui_solve_()
{
    std::cout<<"Input << 0 >> if you want to enter your cube order, or\nInput << 1 >> if you want the cube to shuffle automaticly!\n";
    int a;
    std::cin>>a;
    color_detection(0);
    std::cout<<"-----------------------------------------------------------------------------\n";
    color_reset();
    Cube c(a);
    if(a) c.shuffle(9); //if automatic.

    std::cout<<"your cube is: \n";
    c.show();
    color_detection(0);
    std::cout<<"-----------------------------------------------------------------------------\n";
    color_reset();

    std::vector<Cube> breadth;

    std::cout<<"BFS Method: Solving . . . . . . . . . . . \n";

    //if you wanted to change this "7", you SHOULD change that also in BFS.
    int bfs = BFS(c, breadth, 7);
    
    if( bfs != -1 )
    {
        std::vector<int> dir = breadth[bfs].get_applied_moves();
        c.solve(dir);
        c.show();
    }
    else
        std::cout<<"BFS: could not solve with limit 7. :(\nTry again hatman :)\n";
}


