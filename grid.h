#ifndef GRID_H
#define GRID_H

#include <fstream>
#include <iostream>
#include <string>

class Grid
{
public:
    //Init & Overloads
    Grid() : corrupt(false), loaded(false) { clear();}
    
    //Get
    int get_num(int row, int column);
    
    //Set
    bool set_num(int row, int column, int n);
    
    //Status
    bool is_good() {return !corrupt;}
    bool is_loaded() {return loaded;}
    
    //Utility
    bool load_file(const std::string& path);
    bool clear();
    
private:
    int table[9][9];
    
    //Status flags
    bool corrupt;
    bool loaded;
};

#endif //GRID_H
