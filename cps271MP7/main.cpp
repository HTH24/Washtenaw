//
//  main.cpp
//  cps271MP7
//
//  Created by TianHang Hu on 3/30/24.
//

#include "cps271MP7.hpp"

int main() {
    const int row(6);
    const int column(7);
    Grid g(row, column);
    
    g.fillGrid();
    g.printGrid();
    cout << endl;
    
    bool decision = g.whoGoesFirst();
    // while there is no draw --- the whole Grid is not filled yet, I keep playing against the computer
    while (!g.isDraw()) {
        
        g.masterCheck();
        
        if (decision) { // user moves first
            cout << "Human player moves first" << endl;
            g.userMakeMove();
            g.computerMakeMove();
        }
        else {
            cout << "Computer moves first" << endl;
            g.computerMakeMove();
            g.userMakeMove();
        }
        
        g.printGrid();
    }
    
    return 0;
}
