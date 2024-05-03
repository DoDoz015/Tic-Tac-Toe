#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // No winner yet
    return '-';
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-')); // Initialize empty board

    char currentPlayer = 'X'; // Player X starts

    while (true) {
        cout << "Current board:" << endl;
        printBoard(board);

        // Input position from player
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input position is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
            cout << "Invalid move. Try again." << endl;
            cin.ignore(); // Clear the buffer
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for a winner or a tie
        char winner = checkWinner(board);
        if (winner != '-') {
            cout << "Player " << winner << " wins!" << endl;
            break;
        }
        else if (isBoardFull(board)) {
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
