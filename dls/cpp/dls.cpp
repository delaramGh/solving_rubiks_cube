#include "dls.h"

//main DLF function! :)
bool DLS(Cube &c,std::vector<int> &dir)
{
    size_t depth_lim = 9;
    static size_t depth{0};
    Cube c2{};
    if( c.check() )
        return true;

    if( depth < depth_lim )
    {
        for (size_t i{1}; i <= 6; i++)
        {
            if(!c.check_this_choice(dir, i))
                continue;
            c2 = c;
            dir.push_back(i);
            c2.move(i);
            depth++;
            if( DLS(c2, dir) )
                return true;
            depth--;            
        }
        dir.pop_back();
        return false;
    }
    else
    {
        dir.pop_back();
        return false;
    }
}

//DLF function used in IDDFS.
bool DLS(Cube &c,std::vector<int> &dir, size_t limit)
{
    size_t depth_lim = limit;
    static size_t depth{0};
    if(limit == 0)
    {
        depth = 0;
        return false;
    }
    Cube c2{};
    if( c.check() )
        return true;

    if( depth < depth_lim )
    {
        for (size_t i{1}; i <= 6; i++)
        {
            if(!c.check_this_choice(dir, i))  //to avoid uneffective moves.
                continue;
            c2 = c;
            dir.push_back(i);
            c2.move(i);
            depth++;
            if( DLS(c2, dir, limit) )
                return true;
            depth--;            
        }
        dir.pop_back();
        return false;
    }
    else
    {
        dir.pop_back();
        return false;
    }
}

bool IDDFS(size_t max_depth, Cube c, std::vector<int> &dir)
{
    for (size_t i = 2; i <= max_depth; i++)
    {
        std::cout<<"_IDDFS: checking limit "<<i<<" . . . . ."<<std::endl;
        if( DLS(c, dir, i) )
            return true;
        if( ! DLS(c, dir, 0) )  //refresh the static varible of DLS.
            dir.clear();
    }
    return false;
}

void ui_solve(const char* method)
{
    std::cout<<"Input << 0 >> if you want to enter your cube order, or\nInput << 1 >> if you want the cube to shuffle automaticly!\n";
    int a;
    std::cin>>a;
    color_detection(0);
    std::cout<<"-----------------------------------------------------------------------------\n";
    color_reset();
    Cube c(a);
    if(a) c.shuffle(8); //if automatic.
    std::cout<<"your cube is: \n";
    c.show();
    color_detection(0);
    std::cout<<"-----------------------------------------------------------------------------\n";
    color_reset();
    if( !strcmp(method, "DLS") )
    {
        std::vector<int> dir;
        color_detection(0);
        std::cout<<"DLS Method: Solving . . . . . . . . . . . \n";
        color_reset();
        bool dls = DLS(c, dir);
        if( dls )
        {
            std::cout<<"cube solved in depth: ";
            color_detection(0);
            std::cout<<dir.size()<<std::endl;
            color_reset();
            color_detection(0);
            std::cout<<"-----------------------------------------------------------------------------\n";
            color_reset();
            c.solve(dir);
            color_detection(0);
            std::cout<<"-----------------------------------------------------------------------------\n";
            color_reset();
            c.show();
        }
        else
        {
            color_detection(5);
            std::cout<<"Unable to solve with depth 8. :( \n";   
            color_reset();
        }
    }

    if( !strcmp(method, "IDDFS") )
    {
        std::vector<int> dir;
        std::cout<<"Enter maximum limit of the IDDFS method: ";
        size_t max_limit;
        std::cin>>max_limit;
        color_detection(0);
        std::cout<<"IDDFS Method: Solving . . . . . . . . . . . . . . . . \n";
        color_reset();
        bool iddfs = IDDFS(max_limit, c, dir);
        if( iddfs )
        {
            std::cout<<"cube solved in depth: ";
            color_detection(0);
            std::cout<<dir.size()<<std::endl;
            color_reset();
            color_detection(0);
            std::cout<<"-----------------------------------------------------------------------------\n";
            color_reset();
            c.solve(dir);
            color_detection(0);
            std::cout<<"-----------------------------------------------------------------------------\n";
            color_reset();
            c.show();
        }
        else
        {
            color_detection(5);
            std::cout<<"Unable to solve with depth "<<max_limit<<" :( \n";   
            color_reset();
        }
    }
}

