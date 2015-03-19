#include <iostream>
#include <fstream>
#include <string>

class Grid
{
public:
    //Will automatically load the file
    Grid(std::string path);
    ~Grid();
    
    bool is_good() { return !corrupt };
    
private:
    void load(const ifstream& file);
    
    
    //Raw array for storing the grid.
    int grid[9][9];
    
    //Flag for checking if the grid is corrupt
    bool corrupt;
}

//Loads the file from the path 
Grid::Grid(const std::string& path)
    : corrupt(false)
{
    //Input file stream
    ifstream file;
    
    //Open the file
    file.open(path);
    
    if(file.is_open())
    {
        //Load grid
        this->load(file);
        
        //Close the file
        file.close();
    }
    else
    {
        std::err << "Error: grid file at " << path << "unable to be opened.\n";
        corrupt = true;
    }
}

void Grid::load(cosnt ifstream& file)
{
    //Buffer
    char c;
    int buffer;
    //Rows and columns
    int i = 0;
    int j = 0;
    
    while (i < 9 && file.good())
    {
        //Read until the next { character
        while (file >> c && c != '{');
        
        while (j < 9)
        {
            //Read a character
            while (file >> c)
            {
            
                if (c == '}')
                    break;
                buffer = c;
                
                //If buffer is valid value
                if (buffer >= 0 && buffer <= 9)
                    break;
                else; //Continue reading
            }
            
            //Transfer value to grid.
            grid[i][j] = buffer;
            
            ++j;
        }
        
        //Read until you hit the next } character
        while (file >> c && c !- '}');
        
        j = 0;
        ++i;
    }
    
    if (file.is_good() == false)
        corrupt = true;
    
}
