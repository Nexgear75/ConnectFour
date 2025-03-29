//
// Created by Alex Fougeroux on 29/03/2025.
//

#include "Board.h"

Board::Board() : grid(ROWS, std::vector<char>(COLUMNS, ' ')){}

void Board::display() {
    std::cout << "\n";
    for (auto& row : grid) {
        for (char cell : row) {
            if (cell == 'X') {
                std::cout << "| \033[31mX\033[0m "; //Red color
            } else if (cell == 'O') {
                std::cout << "| \033[33mO\033[0m "; //Yellow color
            } else {
                std::cout << "|   ";
            }
        }
        std::cout << "|\n";
    }
    std::cout << "-----------------------------\n  1   2   3   4   5   6   7\n";
}

bool Board::isFull() {
    for (int c = 0; c < COLUMNS; c++) {
        if (grid[0][c] == ' ') return false;
    }
    return true;
}


bool Board::dropDisc(int column, char playerSymbol) {
    if (column < 0 || column >= COLUMNS || grid[0][column] != ' ') {
        return false;
    }
    for (int r = ROWS -1; r >= 0; r--) {
        if (grid[r][column] == ' ') {
            grid[r][column] = playerSymbol;
            return true;
        }
    }
    return false;
}

// This function will check if a player has won
bool Board::checkWin(char playerSymbol) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLUMNS; c++) {
            if (grid[r][c] == playerSymbol) {
                //Horizontal checking
                if (c + 3 < COLUMNS && grid[r][c + 1] == playerSymbol && grid[r][c + 2] == playerSymbol && grid[r][c + 3] == playerSymbol)
                    return true;
                // Vertical checking
                if (r + 3 < ROWS && grid[r + 1][c] == playerSymbol && grid[r + 2][c] == playerSymbol && grid[r + 3][c] == playerSymbol)
                    return true;
                // Diagonal right checking
                if (r + 3 < ROWS && c + 3 < COLUMNS && grid[r + 1][c + 1] == playerSymbol && grid[r + 2][c + 2] == playerSymbol && grid[r + 3][c + 3] == playerSymbol)
                    return true;
                // Diagonal left checking
                if (r + 3 < ROWS && c - 3 >= 0 && grid[r + 1][c - 1] == playerSymbol && grid[r + 2][c - 2] == playerSymbol && grid[r + 3][c - 3] == playerSymbol)
                    return true;
            }
        }
    }
    return false;
}