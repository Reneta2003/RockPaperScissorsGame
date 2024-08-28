#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>

class Game {
public:
    // Enums used for clarity
    enum Move {
        ROCK,
        PAPER,
        SCISSORS
    };

    static bool isWinner(Move playerMove, Move computerMove) {
        if (playerMove == ROCK && computerMove == SCISSORS) return true;
        if (playerMove == PAPER && computerMove == ROCK) return true;
        if (playerMove == SCISSORS && computerMove == PAPER) return true;
        return false;
    }

    static Move computerMove() {
        return static_cast<Move>(rand() % 3);
    }
};

#endif // MAIN_H
