//
// Created by Alex Fougeroux on 29/03/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
    private:
    Board board;
    Player player1, player2;
    Player* currentPlayer;
    bool isGameOver;

    void switchPlayer();

    public:
    Game(std::string name1, std::string name2);
    void play();
};

#endif //GAME_H
