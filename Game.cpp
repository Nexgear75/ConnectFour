//
// Created by Alex Fougeroux on 29/03/2025.
//

#include "Game.h"

Game::Game(std::string name1, std::string name2)
    : player1(name1, 'X', "\033[31m"),  //Red
      player2(name2, 'O', "\033[33m"),  //Yellow
      currentPlayer(&player1),
      isGameOver(false) {}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void Game::play() {
    while (!board.isFull() && !isGameOver) {
        board.display();
        int column;
        do {
            column = currentPlayer->chooseColumn();
        } while (!board.dropDisc(column, currentPlayer->getSymbol()));

        if (board.checkWin(currentPlayer->getSymbol())) {
            board.display();
            std::cout << "\n" <<currentPlayer->getColoredSymbol() << " wins!\n";
            isGameOver = true;
        } else {
            switchPlayer();
        }
    }
    if (!isGameOver) {
        board.display();
        std::cout << "It's a tie!\n";
    }
}
