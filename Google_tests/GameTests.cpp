#include <gtest/gtest.h>
#include "main.h"
#include <sstream>

// Test fixture for the Game class
class GameTest : public ::testing::Test {
protected:
    Game game;
};

// Tests for the isWinner Function for Win/Lose condition
TEST_F(GameTest, IsWinner_PlayerWinsWithRockVsScissors) {
    EXPECT_TRUE(game.isWinner(Game::ROCK, Game::SCISSORS));
}

TEST_F(GameTest, IsWinner_PlayerWinsWithPaperVsRock) {
    EXPECT_TRUE(game.isWinner(Game::PAPER, Game::ROCK));
}

TEST_F(GameTest, IsWinner_PlayerWinsWithScissorsVsPaper) {
    EXPECT_TRUE(game.isWinner(Game::SCISSORS, Game::PAPER));
}

TEST_F(GameTest, IsWinner_PlayerLosesWithRockVsPaper) {
    EXPECT_FALSE(game.isWinner(Game::ROCK, Game::PAPER));
}

TEST_F(GameTest, IsWinner_PlayerLosesWithPaperVsScissors) {
    EXPECT_FALSE(game.isWinner(Game::PAPER, Game::SCISSORS));
}

TEST_F(GameTest, IsWinner_PlayerLosesWithScissorsVsRock) {
    EXPECT_FALSE(game.isWinner(Game::SCISSORS, Game::ROCK));
}

// Tests for Tie Scenarios
TEST_F(GameTest, IsWinner_TieWithRock) {
    EXPECT_FALSE(game.isWinner(Game::ROCK, Game::ROCK));
}

TEST_F(GameTest, IsWinner_TieWithPaper) {
    EXPECT_FALSE(game.isWinner(Game::PAPER, Game::PAPER));
}

TEST_F(GameTest, IsWinner_TieWithScissors) {
    EXPECT_FALSE(game.isWinner(Game::SCISSORS, Game::SCISSORS));
}

TEST_F(GameTest, PlayerInput_TestValidInputs) {
    std::istringstream input("0\n1\n2\n");
    std::cin.rdbuf(input.rdbuf());

    int i;
    Game::Move playerMove;

    // Test for input "0\n" (Rock)
    std::cin >> i;
    EXPECT_EQ(i, 0);
    playerMove = static_cast<Game::Move>(i);
    EXPECT_EQ(playerMove, Game::ROCK);

    // Test for input "1\n" (Paper)
    std::cin >> i;
    EXPECT_EQ(i, 1);
    playerMove = static_cast<Game::Move>(i);
    EXPECT_EQ(playerMove, Game::PAPER);

    // Test for input "2\n" (Scissors)
    std::cin >> i;
    EXPECT_EQ(i, 2);
    playerMove = static_cast<Game::Move>(i);
    EXPECT_EQ(playerMove, Game::SCISSORS);
}

//Tests for Invalid Player Inputs - too large number
TEST_F(GameTest, PlayerInput_InvalidInputTooLargeNumber) {
    std::istringstream input("444444444444444444444444444444\n");
    std::cin.rdbuf(input.rdbuf());

    int i;
    std::cin >> i;
    EXPECT_TRUE(std::cin.fail());

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

TEST_F(GameTest, PlayerInput_InvalidInputNonNumeric) {
    std::istringstream input("invalid\n");  // Simulating non-numeric input
    std::cin.rdbuf(input.rdbuf());

    int i;
    std::cin >> i;
    EXPECT_TRUE(std::cin.fail());

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

TEST_F(GameTest, PlayerInput_InvalidInputOutOfRange) {
    std::istringstream input("4\n-1\n");  // Out of range and negative input test
    std::cin.rdbuf(input.rdbuf());

    int i;
    std::cin >> i;
    EXPECT_FALSE(i >= 0 && i <= 2);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin >> i;
    EXPECT_FALSE(i >= 0 && i <= 2);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Tests for Game Ending Condition Input
TEST_F(GameTest, GameEnding_HandlesEndingConditionInput) {
    std::istringstream input("Y\ny\nn\n"); //Pressing Y/y + Enter should pass while pressing n + Enter should fail
    std::cin.rdbuf(input.rdbuf());

    char c;
    std::cin >> c;
    EXPECT_TRUE(c == 'Y' || c == 'y');

    std::cin >> c;
    EXPECT_TRUE(c == 'Y' || c == 'y');

    std::cin >> c;
    EXPECT_FALSE(c == 'Y' || c == 'y');
}


