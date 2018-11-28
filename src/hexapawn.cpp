#include "controller.h"
#include<iostream>

int main()
{
    int r,c;

    std::cout<<"The board is rotated on each turn. The player who's moving is at the top.";
    std::cout<<"\nEnter the number of rows in the board: (if you'd like the default, enter 3, max 8):\n";
    std::cin>>r;
    std::cout<<"\nEnter the number of columns on the board: (if you'd like the default, enter 3, max 8):\n";
    std::cin>>c;

    hexapawn::Controller(r,c).run();

    return 0;
}
