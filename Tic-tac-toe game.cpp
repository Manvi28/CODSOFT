/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

// Function to draw the game board
void drawBoard(char board[3][3]) {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;

    while (true) {
        drawBoard(board);
        std::cout << "Player " << player << ", enter your move (row and column numbers, 1-3): ";
        std::cin >> row >> col;

        // Validate user input
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }

        // Check if the space is already occupied
        if (board[row - 1][col - 1] != ' ') {
            std::cout << "Space already occupied. Please try again." << std::endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = player;

        // Check for a win
        if (checkWin(board, player)) {
            drawBoard(board);
            std::cout << "Player " << player << " wins! Congratulations!" << std::endl;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    // Ask if the players want to play again
    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Call the main function recursively to start a new game
    }

   return 0;
}
