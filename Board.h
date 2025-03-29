//
// Created by Alex Fougeroux on 29/03/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board {
private:
    static const int ROWS = 6, COLUMNS = 7;
    std::vector<std::vector<char> > grid;
public:
    Board();
    void display();
    bool isFull();
    bool dropDisc(int column, char playerSymbol);
    bool checkWin(char playerSymbol);

};

#endif //BOARD_H
