#include "cube.h"

//if 1: solved. if 0: client should enter. (default = 1)
Cube::Cube(int a)  
{
    //w:1  b:2  y:3  g:4  r:5  o:6
    if(a)
    {
        data.push_back(std::vector<int>(2, 1));  //row 0, 1: top
        data.push_back(std::vector<int>(2, 1));
        data.push_back(std::vector<int>(2, 3));  //row 2, 3: front
        data.push_back(std::vector<int>(2, 3));
        data.push_back(std::vector<int>(2, 5));  //row 4, 5: bottom
        data.push_back(std::vector<int>(2, 5));
        data.push_back(std::vector<int>(2, 6));  //row 6, 7: back
        data.push_back(std::vector<int>(2, 6));
        data.push_back(std::vector<int>(2, 2));  //row 8, 9: left
        data.push_back(std::vector<int>(2, 2));
        data.push_back(std::vector<int>(2, 4));  //row 10, 11: right
        data.push_back(std::vector<int>(2, 4));
    }
    else
    {
        std::vector<std::vector<int>> Data;
        std::vector<int> temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11;
        int a0{}, a1{}, b0{}, b1{};
        char va;

        std::cout<<"enter surface "<<1<<" values: \n";   //top
        std::cin>>a0>>va>>a1>>va>>b0>>va>>b1;
        temp0.push_back(a0);
        temp0.push_back(a1);
        temp1.push_back(b0);
        temp1.push_back(b1);
        std::cout<<"enter surface "<<2<<" values: \n";   //left
        std::cin>>a0>>va>>a1>>va>>b0>>va>>b1;
        temp8.push_back(a0);
        temp8.push_back(a1);
        temp9.push_back(b0);
        temp9.push_back(b1);
        std::cout<<"enter surface "<<3<<" values: \n";   //front
        std::cin>>a0>>va>>a1>>va>>b0>>va>>b1;
        temp2.push_back(a0);
        temp2.push_back(a1);
        temp3.push_back(b0);
        temp3.push_back(b1);
        std::cout<<"enter surface "<<4<<" values: \n";   //right
        std::cin>>a0>>va>>a1>>va>>b0>>va>>b1;
        temp10.push_back(a0);
        temp10.push_back(a1);
        temp11.push_back(b0);
        temp11.push_back(b1);
        std::cout<<"enter surface "<<5<<" values: \n";   //bottom
        std::cin>>a0>>va>>a1>>va>>b0>>va>>b1;
        temp4.push_back(a0);
        temp4.push_back(a1);
        temp5.push_back(b0);
        temp5.push_back(b1);
        std::cout<<"enter surface "<<6<<" values: \n";   //back
        std::cin>>a0>>va>>a1>>va>>b0>>va>>b1;
        temp6.push_back(a0);
        temp6.push_back(a1);
        temp7.push_back(b0);
        temp7.push_back(b1);
        
        Data.push_back(temp0); //top
        Data.push_back(temp1);
        Data.push_back(temp2);  //front
        Data.push_back(temp3);
        Data.push_back(temp4);  //bottom
        Data.push_back(temp5);
        Data.push_back(temp6);  //back
        Data.push_back(temp7);
        Data.push_back(temp8);  //left
        Data.push_back(temp9);
        Data.push_back(temp10);  //right
        Data.push_back(temp11);
        data = Data;
    }
}

void Cube::show()
{
    std::cout<<std::endl<<std::setw(3)<<""<<std::setw(3)<<""<<std::setw(3)<<"";
    color_detection(data[0][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[0][0];  //top
    color_detection(data[0][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[0][1];
    std::cout<<std::endl;
    std::cout<<std::setw(3)<<""<<std::setw(3)<<""<<std::setw(3)<<"";
    color_detection(data[1][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[1][0];  //top
    color_detection(data[1][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[1][1];
    std::cout<<std::endl;
    std::cout<<std::endl;
    color_detection(data[8][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[8][0];  //left
    color_detection(data[8][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[8][1];
    std::cout<<std::setw(3)<<"";
    color_detection(data[2][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[2][0];  //front
    color_detection(data[2][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[2][1];
    std::cout<<std::setw(3)<<"";
    color_detection(data[10][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[10][0];  //right
    color_detection(data[10][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[10][1];
    std::cout<<std::endl;  
    color_detection(data[9][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[9][0];  //left
    color_detection(data[9][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[9][1];
    std::cout<<std::setw(3)<<"";
    color_detection(data[3][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[3][0];  //front
    color_detection(data[3][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[3][1];
    std::cout<<std::setw(3)<<"";
    color_detection(data[11][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[11][0];  //right
    color_detection(data[11][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[11][1];
    std::cout<<std::endl;  
    std::cout<<std::endl; 
    std::cout<<std::setw(3)<<""<<std::setw(3)<<""<<std::setw(3)<<"";
    color_detection(data[4][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[4][0];  //bottom
    color_detection(data[4][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[4][1];
    std::cout<<std::endl;
    std::cout<<std::setw(3)<<""<<std::setw(3)<<""<<std::setw(3)<<"";
    color_detection(data[5][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[5][0];  //bottom
    color_detection(data[5][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[5][1];
    std::cout<<std::endl;  
    std::cout<<std::endl; 
    std::cout<<std::setw(3)<<""<<std::setw(3)<<""<<std::setw(3)<<"";
    color_detection(data[6][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[6][0];  //back
    color_detection(data[6][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[6][1];
    std::cout<<std::endl;
    std::cout<<std::setw(3)<<""<<std::setw(3)<<""<<std::setw(3)<<"";
    color_detection(data[7][0]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[7][0];  //back
    color_detection(data[7][1]);
    std::cout<<std::setiosflags(std::ios::left)<<std::setw(3)<<data[7][1];
    std::cout<<"\u001b[0m";
    std::cout<<std::endl;
}

std::vector<int> Cube::get_applied_moves()
{
    return applied_moves;
}

void Cube::top2right()  //move 1.
{
    std::vector<std::vector<int>> Data{data};
    Data[0][0] = data[0][1];  //top side rotation to right.
    Data[0][1] = data[1][1];
    Data[1][0] = data[0][0];
    Data[1][1] = data[1][0];
    Data[2][0] = data[8][0]; //first row of left replace first row of front side.
    Data[2][1] = data[8][1];
    Data[10][0] = data[2][0];  //first row of front replace first row of right side.
    Data[10][1] = data[2][1];
    Data[7][1] = data[10][0];  //first row of right replace first row of back side.
    Data[7][0] = data[10][1];
    Data[8][0] = data[7][1];  //first row of back replace first row of left side.
    Data[8][1] = data[7][0];
    data = Data;
}

void Cube::top2left()  //move 2.
{
    std::vector<std::vector<int>> Data{data};
    Data[0][0] = data[1][0];  //top side rotation to left.
    Data[0][1] = data[0][0];
    Data[1][0] = data[1][1];
    Data[1][1] = data[0][1];
    Data[8][0] = data[2][0]; //first row of front replace first row of left side.
    Data[8][1] = data[2][1];
    Data[7][1] = data[8][0];  //first row of left replace first row of back side. (*)
    Data[7][0] = data[8][1];
    Data[10][0] = data[7][1];  //first row of back replace first row of right side.
    Data[10][1] = data[7][0];
    Data[2][0] = data[10][0];  //first row of right replace first row of front side.
    Data[2][1] = data[10][1];
    data = Data; 
}

void Cube::front2right() //move 3.
{
    std::vector<std::vector<int>> Data{data};
    Data[2][0] = data[3][0];  //front side rotation to right.
    Data[2][1] = data[2][0];
    Data[3][0] = data[3][1];
    Data[3][1] = data[2][1];
    Data[10][0] = data[1][0]; //last row of top replace first column of right side.
    Data[11][0] = data[1][1];
    Data[4][1] = data[10][0];  //first column of right replace first row of bottom side.
    Data[4][0] = data[11][0];
    Data[8][1] = data[4][0];  //first row of bottom replace last column of left side.
    Data[9][1] = data[4][1];
    Data[1][0] = data[9][1];  //last column of left replace last row of top side.
    Data[1][1] = data[8][1];
    data = Data; 
}

void Cube::front2left() //move 4.
{
    std::vector<std::vector<int>> Data{data};
    Data[2][0] = data[2][1];  //front side rotation to left.
    Data[2][1] = data[3][1];
    Data[3][0] = data[2][0];
    Data[3][1] = data[3][0];
    Data[8][1] = data[1][1]; //last row of top replace last column of left side.
    Data[9][1] = data[1][0];
    Data[4][0] = data[8][1];  //last column of left replace first row of bottom side.
    Data[4][1] = data[9][1];
    Data[10][0] = data[4][1];  //first row of bottom replace first column of right side.
    Data[11][0] = data[4][0];
    Data[1][0] = data[10][0];  //first column of right replace last row of top side.
    Data[1][1] = data[11][0];
    data = Data; 
}

void Cube::left2up() //move 5.
{
    std::vector<std::vector<int>>  Data{data};
    Data[8][0] = data[8][1];  //left side rotation to up.
    Data[8][1] = data[9][1];
    Data[9][0] = data[8][0];
    Data[9][1] = data[9][0];
    Data[0][0] = data[2][0]; //first column of front replace first column of top side.
    Data[1][0] = data[3][0];
    Data[7][0] = data[1][0];  //first column of top replace first column of back side.
    Data[6][0] = data[0][0];
    Data[5][0] = data[7][0];  //first culomn of back replace first column of bottom side.
    Data[4][0] = data[6][0];
    Data[2][0] = data[4][0];  //first column of bottom replace first culomn of front side.
    Data[3][0] = data[5][0];
    data = Data; 
}

void Cube::left2down() //move 6.
{
    std::vector<std::vector<int>>  Data{data};
    Data[8][0] = data[9][0];  //left side rotation to down.
    Data[8][1] = data[8][0];
    Data[9][0] = data[9][1];
    Data[9][1] = data[8][1];
    Data[4][0] = data[2][0]; //first column of front replace first column of bottom side.
    Data[5][0] = data[3][0];
    Data[7][0] = data[5][0];  //first column of bottom replace first column of back side.
    Data[6][0] = data[4][0];
    Data[0][0] = data[6][0];  //first culomn of back replace first column of top side.
    Data[1][0] = data[7][0];
    Data[2][0] = data[0][0];  //first column of top replace first culomn of front side.
    Data[3][0] = data[1][0];
    data = Data; 
}

bool Cube::check()
{
    for (size_t i = 0; i < 12; i+=2)
    {
        if( !(data[i][0] == data[i][1] && data[i][0] == data[i+1][0] && data[i][0] == data[i+1][1]) )
            return false;
    }
    return true;
}

bool Cube::check_this_choice(std::vector<int> &dir, int i) //to not allow effectless moves.
{
    size_t size{dir.size()};
    if(size < 1)
        return true;
    if(dir[size-1] == 1 && i == 2)
        return false;
    if(dir[size-1] == 2 && i == 1)
        return false;
    if(dir[size-1] == 3 && i == 4)
        return false;
    if(dir[size-1] == 4 && i == 3)
        return false;
    if(dir[size-1] == 5 && i == 6)
        return false;
    if(dir[size-1] == 6 && i == 5)
        return false;
    if(dir[size-1] == dir[size-2] && dir[size-1] == i)
        return false;
    return true;
}

void Cube::move(size_t i)  //apply moves in an ordered sequence.
{
    if( i < 1 || i > 6 )
        std::cout<<"cube move: invalid input.\n";
    else
    {
        applied_moves.push_back(i);
        if( i == 1 )this->top2right();
        if( i == 2 )this->top2left();
        if( i == 3 )this->front2right();
        if( i == 4 )this->front2left();
        if( i == 5 )this->left2up();
        if( i == 6 )this->left2down();
    }
}

void Cube::shuffle(size_t j)  //moves the Cube randomly j times.
{
    srand(time(NULL));
    size_t r{};
    for (size_t i = 0; i < j; i++)
    {
        r = rand() % 6;
        this->move(r+1);
    }
    clear_applied_moves();
}

bool Cube::operator== (Cube c)  //checks if 2 cubes are equal.
{
    for (size_t i = 0; i < 12; i++)
    {
        if( data[i][0] == c.data[i][0] && data[i][1] == c.data[i][1] )
            continue;
        return false;    
    }
    return true;
}

void Cube::operator= (Cube& c)
{
    data = c.data;
}

bool Cube::solve(std::vector<int> dir)  //moves the cube with order "dir".
{
    size_t size = dir.size();
    for (size_t i = 0; i < size; i++)
        move(dir[i]);
    if(check())
    {
        std::cout<<"Cube solved in depth: ";
        color_detection(0);
        std::cout<<dir.size()<<std::endl;
        color_reset();
        
        color_detection(0);
        std::cout<<"-----------------------------------------------------------------------------\n";
        std::cout<<"Solve: take the following steps to solve your cube: \n\n";
        color_reset();
        for (size_t i = 0; i < size; i++)
        {
            if(dir[i] == 1)
                std::cout<<i+1<<": top to right. \n";
            if(dir[i] == 2)
                std::cout<<i+1<<": top to left. \n";
            if(dir[i] == 3)
                std::cout<<i+1<<": front to right. \n";
            if(dir[i] == 4)
                std::cout<<i+1<<": front to left. \n";
            if(dir[i] == 5)
                std::cout<<i+1<<": left to up. \n";
            if(dir[i] == 6)
                std::cout<<i+1<<": left to down. \n";
        }
    }
    //show();
    return check();
}

void Cube::clear_applied_moves()
{
    applied_moves.clear();
}

//handeling colors.
void color_detection(int a)
{
    if(a == 1) std::cout<<"\u001b[37m"; //white
    if(a == 2) std::cout<<"\u001b[34m"; //blue
    if(a == 3) std::cout<<"\u001b[33m"; //yellow
    if(a == 4) std::cout<<"\u001b[32m"; //green
    if(a == 5) std::cout<<"\u001b[31m"; //red
    if(a == 6) std::cout<<"\u001b[35m"; //purple
    if(a == 0) std::cout<<"\u001b[36m"; 
}

void color_reset()
{
    std::cout<<"\u001b[0m";
}

