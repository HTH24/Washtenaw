//
//  cps271MP7.hpp
//  cps271MP7
//
//  Created by TianHang Hu on 3/30/24.
//

#ifndef cps271MP7_hpp
#define cps271MP7_hpp

#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
// somehow cannot include Stanford C++ Library's grid.h
using namespace std;

// in this problem, T is of type char, character. One side is R, the other side is Y
class Grid {
    // 6 rows, 7 columns
public:
    int num_Row;
    int num_Column;
    // smart pointer to a vector of a vector
    vector<vector<char>> grid;
    // default constructor. smart pointer initialized to nullptr
    Grid() : num_Row(0), num_Column(0), grid() {}
    // parameter constructor
    Grid(int row, int col) : num_Row(row), num_Column(col) {
        grid.resize(row);
        for (auto &row : grid) {
            row.resize(col, 'E');
        }
    }
    // get number of row or column
    int numCols() { return num_Column; }
    int numRows() { return num_Row; }
    // get the Grid's size
    int gridSize() { return num_Row * num_Column; }
    // get grid object
    vector<vector<char>> &getGrid() { return grid; }
    // user sets a new value to a specific position
    void userMakeMove();
    // computer chooses a position at random, assuming within boundary of the 2D Grid
    void computerMakeMove();
    // print the entire Grid
    void printGrid();
    // initialize the grid with E, standing for Empty
    void fillGrid();
    // method to check if a column is filled
    bool columnFilled(int);
    // check if the grid has been filled by oneself
    int selectedPositionFilled(int col_index, int row_index = 5);
    // determines human player or computer goes first
    bool whoGoesFirst();
    // check row for 4 consecutive discs
    bool checkRow();
    // check column
    bool checkColumn();
    // check left diagonal
    bool checkLeftDiagnol();
    // check right diagonal
    bool checkRightDiagonal();
    // Master check function to check all 4 situations
    void masterCheck();
    // When the Grid is filled, but no winner, a draw
    bool isDraw();
};

#endif /* cps271MP7_hpp */
