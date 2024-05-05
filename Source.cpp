#include <iostream>
#include <climits>

using namespace std;

const int EMPTY = 0;
const int PLAYER_X = 1;
const int PLAYER_O = 2;

int evaluateBoard(int board[3][3]) {
    // Evaluate the current state of the board
    // Returns +10 if player X wins, -10 if player O wins, 0 if draw
    // Returns INT_MIN if game is not yet over
    for (int player : {PLAYER_X, PLAYER_O}) {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return (player == PLAYER_X) ? 10 : -10;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return (player == PLAYER_X) ? 10 : -10;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return (player == PLAYER_X) ? 10 : -10;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return (player == PLAYER_X) ? 10 : -10;
    }
    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) draw = false;
        }
    }
    if (draw) return 0;
    // Game is not yet over
    return INT_MIN;
}

int minimax(int board[3][3], int depth, int alpha, int beta, bool maximizingPlayer) {
    // Minimax algorithm with alpha-beta pruning
    // Returns the optimal score for the current player
    int score = evaluateBoard(board);
    if (score != INT_MIN) return score;
    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int eval = minimax(board, depth + 1, alpha, beta, false);
                    board[i][j] = EMPTY;
                    maxEval = max(maxEval, eval);
                    alpha = max(alpha, eval);
                    if (beta <= alpha) break;
                }
            }
        }
        return maxEval;
    }
    else {
        int minEval = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int eval = minimax(board, depth + 1, alpha, beta, true);
                    board[i][j] = EMPTY;
                    minEval = min(minEval, eval);
                    beta = min(beta, eval);
                    if (beta <= alpha) break;
                }
            }
        }
        return minEval;
    }
}

pair<int, int> getBestMove(int board[3][3]) {
    // Returns the best move for the AI player using minimax algorithm
    int bestMoveScore = INT_MIN;
    pair<int, int> bestMove = { -1, -1 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_X;
                int moveScore = minimax(board, 0, INT_MIN, INT_MAX, false);
                board[i][j] = EMPTY;
                if (moveScore > bestMoveScore) {
                    bestMoveScore = moveScore;
                    bestMove = { i, j };
                }
            }
        }
    }
    return bestMove;
}

void printBoard(int board[3][3]) {
    // Print the current state of the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char symbol = (board[i][j] == PLAYER_X) ? 'X' : ((board[i][j] == PLAYER_O) ? 'O' : ' ');
            cout << symbol;
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----" << endl;
    }
}

int main() {
    int board[3][3] = { {EMPTY, EMPTY, EMPTY},
                       {EMPTY, EMPTY, EMPTY},
                       {EMPTY, EMPTY, EMPTY} };

    while (true) {
        printBoard(board);
        pair<int, int> move;
        cout << "Enter row and column for your move (0-2, space-separated): ";
        cin >> move.first >> move.second;

        if (board[move.first][move.second] != EMPTY) {
            cout << "Invalid move! That cell is already taken." << endl;
            continue;
        }

        board[move.first][move.second] = PLAYER_O;

        int gameResult = evaluateBoard(board);
        if (gameResult == 10) {
            cout << "Congratulations! You win!" << endl;
            break;
        }
        else if (gameResult == 0) {
            cout << "It's a draw!" << endl;
            break;
        }

        pair<int, int> aiMove = getBestMove(board);
        board[aiMove.first][aiMove.second] = PLAYER_X;

        gameResult = evaluateBoard(board);
        if (gameResult == -10) {
            cout << "The AI wins! Better luck next time." << endl;
            break;
        }
        else if (gameResult == 0) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
