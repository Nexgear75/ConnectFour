//
// Created by Alex Fougeroux on 29/03/2025.
//

#include "Player.h"

Player::Player(std::string name, char symbol, std::string color)
    : name(std::move(name)), symbol(symbol), color(std::move(color)) {}


int Player::chooseColumn() {
    int col;
    std::cout << "\n" << name << " (" << symbol << "), enter column number (1-7) : ";
    std::cin >> col;
    return col - 1;
}

char Player::getSymbol() const {
    return symbol;
}

std::string Player::getColoredSymbol() const {
    return color + symbol + "\033[0m";
}
