#include <iostream>
#include <map>
#include <string>
#include "game.h"
#include "tictactoe.h"

char board[3][3] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
};
Game::Game()
{

}
Game::~Game()
{

}
// A neat looking board
void printBoard(const char board[3][3]) {

    std::cout << "    A   B   C" << std::endl;

    for (int row = 0; row < 3; ++row) {

        std::cout << "  +---+---+---+" << std::endl;

        std::cout << row + 1 << " ";

        for (int col = 0; col < 3; ++col) {
            std::cout << "| " << board[row][col] << " ";
        }

        std::cout << "|" << std::endl;
    }

    std::cout << "  +---+---+---+" << std::endl;
}
bool checkForWin(const char board[3][3], char turn)
{
    // rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
        {
            std::cout << turn << " won!\n";
            return true;
        }
    }
    // columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
        {
            std::cout << turn << " won!\n";
            return true;
        }
    }
    // diagonal
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
        std::cout << turn << " won!\n";
        return true;
    }
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
        std::cout << turn << " won!\n";
        return true;
    }
    return false;
}

void Game::Run()
{
    for (;;)
    {
        printBoard(board);
        
        std::string input;
        std::cin >> input;
        static char turn = 'X';

        if (input.length() > 2)
        {
            std::cout << "Invalid input\n";
            continue;
        }
        
        std::cout << input[0] << "\n";
        std::cout << input[1] << "\n";
        std::map<char, int> stringToInt = {
        {'a', 1},
        {'b', 2},
        {'c', 3},
        {'A', 1},
        {'B', 2},
        {'C', 3}
        };
        if (stringToInt.find(input[0]) != stringToInt.end()) {
            int yCoordinate = stringToInt[input[0]];
            int xCoordinate = std::stoi(input.substr(1, 1));
            std::cout << "Parsed value: " << yCoordinate << std::endl;
            if (board[xCoordinate - 1][yCoordinate -1] == ' ')
            {
                board[xCoordinate - 1][yCoordinate - 1] = turn;
                checkForWin(board, turn);
                turn = (turn == 'X') ? 'O' : 'X';
            }
            else
            {
                std::cout << "occupied\n";
                continue;
            }
        }
        else {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
    }
}


