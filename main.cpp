#include <iostream>
#include <bits/ranges_algobase.h>
#include <limits>

int main() {
    class Game {
    public:
        //Enums used for clarity
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

    Game game;
    bool play = true;
    while (play) {
        std::cout << "Welcome to Rock Paper Scissors!" << std::endl;
        std::cout << "Pick a move by typing in a number and pressing Enter: 0-Rock 1-Paper 2-Scissors" << std::endl;
        int i;
        std::cin >> i;

        // Handle invalid input such as large numbers, characters, etc.
        while (i < 0 || i > 2 || std::cin.fail()) {
            std::cin.clear(); // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid move, please choose between 0-Rock 1-Paper 2-Scissors: ";
            std::cin >> i;
        }

        auto playerMove = static_cast<Game::Move>(i);
        std::cout << "You chose: " << (playerMove == Game::ROCK ? "Rock" : playerMove == Game::PAPER ? "Paper" : "Scissors") << std::endl;

        Game::Move computerMove = game.computerMove();
        std::cout << "The computer chose: " << (computerMove == Game::ROCK ? "Rock" : computerMove == Game::PAPER ? "Paper" : "Scissors") << std::endl;

        if (playerMove == computerMove) {
            std::cout << "It's a tie!" << std::endl;
        } else if (game.isWinner(playerMove, computerMove)) {
            std::cout << "You Win! :)" << std::endl;
        } else {
            std::cout << "You lose :(" << std::endl;
        }

        std::cout << "Play again? Press Y to continue: ";
        char c;
        std::cin >> c;
        if (c != 'Y' && c != 'y') {
            play = false;
        }

        std::cout << std::endl;
    }

    return 0;
}
