#include "grid.h"

int Grid::get_num(int row, int column)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 9 || column > 9)
    {
        std::cout << "Error: Cannot get invalid grid space at ";
        std::cout << "(" << row << "," << column << ")\n";
        return -1;
    }
    else
    {
        return table[row-1][column-1];
    }
}

bool Grid::set_num(int row, int column, int n)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 9 || column > 9)
    {
        std::cout << "Error: Cannot set invalid grid space at ";
        std::cout << "(" << row << "," << column << ")\n";
        return false;
    }
    
    //Number bounds check
    if (n < 0 || n > 9)
    {
        std::cout << "Error: Cannot set grid space at ";
        std::cout << "(" << row << "," << column << ")";
        std::cout << " to " << n;
        return false;
    }
    else
    {
        table[row-1][column-1] = n;
        return true;
    }
}

//Loads a file from path string
bool Grid::load_file (const std::string& path)
{
    std::cout << "Begin loading grid at " << path << std::endl;

    //Open file
    std::fstream file;
    file.open("sudoku_1.txt");
    
    char c;
    int i = 0;
    int j = 0;
    int buffer;
    
    bool row_flag = false;
    
    //Read file by character
    while (file >> std::noskipws >> c && i < 9)
    {
        //Keep going until you read {
        if (c != '{')
            continue;
        //If new row, flip flag
        else if (row_flag == false)
        {
            row_flag = true;
            ++i;
        }
            
        while(row_flag)
        {
            //Read a character
            file >> std::noskipws >> c;
            
            //Check if end of row
            if (c == '}')
            {
                //If row end early, bad
                if (j < 9)
                {
                    row_flag = false;
                    std::cout << "\nError: Grid row " << i << " is missing { or";
                    std::cout << " has less than 9 numbers" << std::endl;
                    corrupt = true;
                    break;
                }
                //Else set end of row
                else
                    row_flag = false;
            }
            
            //Check for "variable" or empty space
            if (c == 'X' || c == 'x' || c == '0')
            {
                ++j;
                std::cout << "x";
                set_num(i,j,0);
                buffer = 0;

            }
            //Convert to number
            else 
            {
                buffer = c - '0';
            
                //Check if 1-9
                if (buffer >= 1 && buffer <= 9)
                {
                    ++j;
                    set_num(i,j,buffer);
                    std::cout << buffer;

                }
                //Discard all else
                else;
            }
            
            //If more than 9 numbers, bad
            if (j > 9)
            {
                std::cout << "\nError: Grid row " << i << " has more than 9 numbers";
                std::cout << " or is not closed with }" << std::endl;
                corrupt = true;
            }
            
            //If corrupt, stop reading file
            if (corrupt)
                break;
            
        }
        
        //Increment row
        std::cout << '\n';
        j = 0;
    }
    
    //If grid less than 9 rows, bad
    if (i < 9)
    {
        std::cout << "\nError: Grid is less than 9 rows" << std::endl;
        corrupt = true;
    }
    
    //Close file
    file.close();
    
    if (file.fail())
    {
        std::cout << "\nError: File I/O error. ( std::ifstream.fail() )" << std::endl;
        corrupt = true;
    }
    
    //If file is not corrupt, file is successfully loaded
    loaded = !corrupt;
    
    return loaded;
}

//Clears table to -1
bool Grid::clear()
{
    //Set all spots to -1
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            table[i][j] = -1;
        }
    }
    
    return true;
}

