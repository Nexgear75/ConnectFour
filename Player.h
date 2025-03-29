//
// Created by Alex Fougeroux on 29/03/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
    private:
    std::string name;
    char symbol;
    std::string color;

    public:
    Player(std::string name, char symbol, std::string color);

    int chooseColumn();
    char getSymbol() const;
    std::string getColoredSymbol() const;
};

#endif //PLAYER_H
