#include <fstream>
#include <iostream>
#include <string>

#include "grid.h"

int main()
{
    std::cout << "Hello! This is a sudoku program!\n";

    //Create and load sudoku grid at given path.
    Grid grid;
    
    if (grid.load_file("sudoku_1.txt"))
        std::cout << "File loaded successfully." << std::endl;
    else
        std::cout << "File failed to load successfully." << std::endl;
        
    std::cout << "Grid at (1,1): " << grid.get_num(1,1) << std::endl;
    std::cout << "Grid at (0,1): " << grid.get_num(0,1) << std::endl;
    std::cout << "Grid at (1,10): " << grid.get_num(1,10) << std::endl;
    
    std::cout << "Set grid (1,1) to 0: " << grid.set_num(1,1,0) << std::endl;
    std::cout << "Grid at (1,1): " << grid.get_num(1,1) << std::endl;
    
    grid.clear();
    std::cout << "Clear grid to -1" << std::endl;
    
    std::cout << "Grid at (1,1): " << grid.get_num(1,1) << std::endl;
    
    return 0;
}

//sudoku_1.txt
/*

This sudoku grid
was created from the one at
http://en.wikipedia.org/wiki/Sudoku_solving_algorithms

{02X,45X,78X}
{4X6,7X9,1X3}
{78X,12X,45X}
-------------
{X34,X67,X91}
{5X7,8X1,2X4}
{89X,23X,56X}
-------------
{X45,X78,X12}
{6X8,9X2,3X5}
{91X,34X,67X}

------------------------
| Parser Specification |
------------------------

The program will ignore everything that is not {}, 0-9, and X or x.
You can use this to comment in files or even within the rows.
For example, I put commas to separate the rows and dashes for the box line.

The program won't read past 9 rows.

{ = Signifies that the row is beginning. More than 1 in a row will not give an error.
} = Row is ending. More than 1 in a row will not give an error.
1-9 = The number values. Stored in grid as is.
0, X, x = Placeholder or empty space. Will be stored as -1.

*/
