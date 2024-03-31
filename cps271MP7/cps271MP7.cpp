//
//  cps271MP7.cpp
//  cps271MP7
//
//  Created by TianHang Hu on 3/30/24.
//

#include "cps271MP7.hpp"

void Grid::userMakeMove() {
    /*
     assuming both r and c are within respective
     set the position the user chooses
     */
    int c; // select a column index
    cout << "Human Player: choose a column number between 0 and 6" << endl;
    cin >> c;
    // player has R discs. The computer has Y discs
    char v('R');
    
    int rIndex = selectedPositionFilled(c);
    if (rIndex != -1) {
        // column not full
        grid[rIndex][c] = v;
    }
    else {
        cout << "Column is full. Choose another column to drop disc" << endl;
        userMakeMove();
    }
        
}

void Grid::printGrid() {
    // number of rows
    for (size_t i = 0; i < num_Row; ++i) {
        // number of columns
        for (size_t j = 0; j < num_Column; ++j) {
            cout << grid.at(i).at(j);
            
            // if not the last element in the Grid, print a space
            if (j != (num_Column - 1)) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
}

void Grid::fillGrid() {
    // Fill the entire grid with E, indicating an empty position
    grid.resize(num_Row, vector<char>(num_Column, 'E'));
}

// default parameter values need to be compil-time const
// recursively check if grids within the same column has been filled

int Grid::selectedPositionFilled(int col_index, int row_index) {
    // Start from the bottom
    // return the row index to fill user's chosen disc
    
    // Check if the current row is filled
    if (grid[row_index][col_index] == 'E') {
        // If the current row is empty, return its index
        return row_index;
    } else if (row_index > 0) {
        // If the current row is filled and not the bottom row, recursively check the row above
        return selectedPositionFilled(col_index, --row_index);
    } else {
        // If the current row is filled and it's the bottom row, the column is full
        return -1; // Indicate that the column is full
    }
}

void Grid::computerMakeMove() {
    std::random_device rd;
    const int range_from = 0;
    const int range_to = 6;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(range_from, range_to);
    
    // c is the selected column index
    auto c = dist(gen);
    char v('Y');
    
    int rIndex = selectedPositionFilled(c);
    if (rIndex != -1) {
        // column not full
        grid[rIndex][c] = v;
    }
    else {
        cout << "Column is full. Choose another column to drop disc" << endl;
        computerMakeMove();
    }
}

bool Grid::whoGoesFirst() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    auto result = dist(gen);
    
    bool user_goes_first = false;
    if (result > 0.5) {
        user_goes_first = true;
    }
    cout << "Value of result is: " << result << endl;
    return user_goes_first;
}

void Grid::masterCheck() {
    checkRow();
    checkColumn();
    checkLeftDiagnol();
    checkRightDiagonal();
    isDraw();
}

bool Grid::checkRow() {
    bool flag = false;
    // left-right
    for (size_t i = 0; i < num_Row; ++i) {
        string s("");
        for (auto it = grid[i].begin(); it != grid[i].end(); ++it) {
            // make sure we do not get an "out-of-range" error
            if (distance(it, grid[i].end()) >= 4) {
                // string concatenation
                s = std::accumulate(it, it + 4, string(""));
                if (s == "RRRR" || s == "YYYY") {
                    // someone wins
                    flag = true;
                    cout << "We have a winner" << endl;
                    if (s == "RRRR") {
                        cout << "You won!" << endl;
                    }
                    else {
                        cout << "The computer won." << endl;
                    }
                    // found a winner, exit the program
                    exit(0);
                }
            }
        }
    }
    
    return flag;
}

bool Grid::checkColumn() {
    bool flag = false;
    // Iterate through each cell in the grid
    for (int row_index = 5; row_index >= 3; --row_index) {
        for (int col_index = 0; col_index < numCols(); ++col_index) {
            // Get the disc in the current position
            char disc = grid[row_index][col_index];
            
            if (disc != 'E') {
                // Check if there are four consecutive discs of the same type in the column
                if (grid[row_index - 1][col_index] == disc &&
                    grid[row_index - 2][col_index] == disc &&
                    grid[row_index - 3][col_index] == disc) {
                    flag = true;
                    cout << "We have a winner" << endl;
                    if (disc == 'R') {
                        cout << "You won!" << endl;
                    } else {
                        cout << "The computer won." << endl;
                    }
                    // Exit the program since we found a winner
                    exit(0);
                }
            }
        }
    }

    return flag;
}

bool Grid::checkLeftDiagnol() {
    bool flag = false;
    
    for (int row_index = numRows() - 1; row_index >= 3; --row_index) {
        for (int col_index = numCols() - 1; col_index >= 3; --col_index) {
            char disc = grid[row_index][col_index];
            
            if (disc != 'E') {
                if (grid[row_index - 1][col_index - 1] == disc && grid[row_index - 2][col_index - 2] == disc
                    && grid[row_index - 3][col_index - 3] == disc) {
                    flag = true;
                    cout << "We have a winner" << endl;
                    if (disc == 'R') {
                        cout << "You won!" << endl;
                    } else {
                        cout << "The computer won." << endl;
                    }
                    // Exit the program since we found a winner
                    exit(0);
                    
                }
            }
        }
    }
    
    return flag;
}

bool Grid::checkRightDiagonal() {
    bool flag = false;
    
    for (int row_index = 5; row_index >= 3; --row_index) {
        for (int col_index = 0; col_index <= 3; ++col_index) {
            char disc = grid[row_index][col_index];
            
            if (disc != 'E') {
                if (grid[row_index - 1][col_index + 1] == disc && grid[row_index - 2][col_index + 2] == disc
                    && grid[row_index - 3][col_index + 3] == disc) {
                    flag = true;
                    cout << "We have a winner" << endl;
                    if (disc == 'R') {
                        cout << "You won!" << endl;
                    } else {
                        cout << "The computer won." << endl;
                    }
                    // Exit the program since we found a winner
                    exit(0);
                }
            }
            
        }
    }
    return flag;
}

// When the Grid is filled, but no winner, a draw
bool Grid::isDraw() {
    bool flag = false;
    int count = 0;
    
    for (int row_index = 0; row_index < numRows(); ++row_index) {
        for (int col_index = 0; col_index < numCols(); ++col_index) {
            if (grid[row_index][col_index] == 'E') {
                ++count;
            }
        }
    }
    
    if (count == 0 && !checkRow() && !checkColumn() && !checkLeftDiagnol() && !checkRightDiagonal()) {
        flag = true;
    }
    
    return flag;
}

