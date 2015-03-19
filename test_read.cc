#include <fstream>
#include <iostream>
#include <string>

class Grid
{
public:
    Grid(const std::string& path);
    
    bool is_good() {return !corrupt;}
    
    
private:
    bool load_file(std::string path);

    bool corrupt;
};

Grid::Grid(const std::string& path)
    : corrupt(false)
{ 
    //Open file
    std::fstream file;
    file.open("sudoku_1.txt");
    
    std::cout << '\n';
    
    char c;
    int i = 0;
    int j = 0;
    int buffer;
    
    bool row_flag = false;
    
    //Read file by character
    while (file >> std::noskipws >> c && i < 8)
    {
        //Stop until you read c
        if (c != '{')
            continue;
        else if (row_flag == false)
            row_flag = true;
            
        while(j < 9)
        {
            file >> std::noskipws >> c;
            
            if (c == 'X' || c == 'x')
            {
                std::cout << "X";
                ++j;
            }
            else if (c == '}')
            {
                corrupt = true;
                break;
            }
            else 
            {
                buffer = c - '0';
            
                if (buffer >= 0 && buffer <= 9 || j > 8)
                {
                    std::cout << buffer;
                    ++j;
                }
                else;
            }
            
        }
        
        std::cout << '\n';
        j = 0;
        ++i;
    }
    
    //Close file
    file.close();
    
    if (file.fail())
        corrupt = true;
}

int main()
{
    Grid grid("sudoku_1.txt");
    
    if (grid.is_good())
        std::cout << "Good!\n";
    else
        std::cout << "Bad!\n";
    
    return 0;
}
