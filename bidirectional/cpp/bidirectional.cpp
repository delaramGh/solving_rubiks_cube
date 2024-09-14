#include "bidirectional.h"


std::vector<Cube> next_breadth(std::vector<Cube> &prev_breadth)
{
    std::vector<Cube> next_breadth;
    size_t size = prev_breadth.size();
    for (size_t j = 0; j < size; j++)
    {
        Cube c = prev_breadth[j];
        for (size_t i = 1; i <= 6; i++)
        {
            Cube c2 = c;
            c2.move(i);
            next_breadth.push_back(c2);
        }
    }
    return next_breadth;
}

//puts breadth_node, first.
std::vector<Cube> find_similar_node(std::vector<std::vector<Cube>> &all_nodes, std::vector<Cube> &breadth)
{
    bool flag = false;
    size_t breadth_size = breadth.size();
    size_t all_nodes_size = all_nodes.size();
    std::vector<Cube> ans;
    for (size_t x = 0; x < breadth_size; x++)
    {
        Cube breadth_node = breadth[x];
        for (size_t i = 0; i < all_nodes_size; i++)
        {
            size_t size = all_nodes[i].size();
            for (size_t j = 0; j < size; j++)
            {
                if(breadth_node == all_nodes[i][j])
                {
                    ans.push_back(breadth_node);
                    ans.push_back(all_nodes[i][j]);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if(flag)
            break;   
    }
    return ans;
}

//puts breadth_node, second.
std::vector<Cube> _find_similar_node(std::vector<std::vector<Cube>> &all_nodes, std::vector<Cube> &breadth)
{
    bool flag = false;
    size_t breadth_size = breadth.size();
    size_t all_nodes_size = all_nodes.size();
    std::vector<Cube> ans;
    for (size_t x = 0; x < breadth_size; x++)
    {
        Cube breadth_node = breadth[x];
        for (size_t i = 0; i < all_nodes_size; i++)
        {
            size_t size = all_nodes[i].size();
            for (size_t j = 0; j < size; j++)
            {
                if(breadth_node == all_nodes[i][j])
                {
                    ans.push_back(all_nodes[i][j]);
                    ans.push_back(breadth_node);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if(flag)
            break;   
    }
    return ans;
}

std::vector<Cube> bidirectional(Cube &c, size_t limit)
{
    std::vector<std::vector<Cube>> problem_nodes;
    std::vector<std::vector<Cube>> target_nodes;
    std::vector<Cube> problem_new_breadth;
    std::vector<Cube> target_new_breadth;
    problem_new_breadth.push_back(c);
    Cube ct(1);
    target_new_breadth.push_back(ct);
    problem_nodes.push_back(problem_new_breadth);
    target_nodes.push_back(target_new_breadth);

    for (size_t i = 0; i < limit; i++)
    {
        std::vector<Cube> check_1 = find_similar_node(problem_nodes, target_new_breadth);
        if(check_1.size() == 2)
            return check_1;  //puts target node first.
        
        std::vector<Cube> check_2 = _find_similar_node(target_nodes, problem_new_breadth);
        if(check_2.size() == 2)
            return check_2;  //puts target node first.
        
        problem_new_breadth = next_breadth(problem_new_breadth);
        problem_nodes.push_back(problem_new_breadth);
        target_new_breadth = next_breadth(target_new_breadth);
        target_nodes.push_back(target_new_breadth);    
    }
    std::vector<Cube> empty;
    return empty;
}

void bidirectional_answer(Cube &c, size_t limit)
{
    c.clear_applied_moves();
    std::vector<Cube> ans = bidirectional(c, limit);
    if (ans.size() == 2)
    {
        std::vector<int> first = ans[0].get_applied_moves();  //target moves.
        std::vector<int> second = ans[1].get_applied_moves(); //problem moves.
        std::vector<int> _first, temp;
        for (size_t i = 0; i < first.size(); i++)  //to put the target moves in correct order.
        {
            if(first[i] == 1)
                temp.push_back(2);
            if(first[i] == 2)
                temp.push_back(1);
            if(first[i] == 3)
                temp.push_back(4);
            if(first[i] == 4)
                temp.push_back(3);
            if(first[i] == 5)
                temp.push_back(6);
            if(first[i] == 6)
                temp.push_back(5);
        }
        for (size_t i = 0; i < first.size(); i++)  //to put the target moves in correct order
        {
            _first.push_back( temp[first.size()-1-i] );
        }  

        std::vector<int> dir;
        for (size_t i = 0; i < second.size(); i++)
            dir.push_back(second[i]);
        for (size_t i = 0; i < first.size(); i++)
            dir.push_back(_first[i]);

        c.solve(dir);
        c.show();
    }
    else
        std::cout<<"Bidirectional: could not solve with limit "<<limit<<". :( \nTry again hatman :)\n";
}

void ui_solve()
{
    std::cout<<"Input << 0 >> if you want to enter your cube order, or\nInput << 1 >> if you want the cube to shuffle automaticly!\n";
    int a;
    std::cin>>a;
    color_detection(0);
    std::cout<<"-----------------------------------------------------------------------------\n";
    color_reset();
    Cube c(a);
    if(a) c.shuffle(7); //if automatic.

    std::cout<<"your cube is: \n";
    c.show();
    color_detection(0);
    std::cout<<"-----------------------------------------------------------------------------\n";
    color_reset();
    std::cout<<"Input BiDirectional limit: \n";
    size_t limit;
    std::cin>>limit;
    std::cout<<"BiDirectional Method: Solving . . . . . . . . . . . \n";
    bidirectional_answer(c, limit);
}


