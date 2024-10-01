#include <iostream>
using namespace std;
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char player = 'X';
    int move;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;

        // Map move to board indices
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;  // Make the move
        } else {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Check if the player wins
        if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) || // Rows
            (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
            (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
            (board[0][0] == player && board[1][0] == player && board[2][0] == player) || // Columns
            (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
            (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
            (board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Diagonals
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            printBoard(board);
            cout << "Player " << player << " wins!\n";
            gameOver = true;
        }
        
        else {
            bool draw = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] != 'X' && board[i][j] != 'O') {
                        draw = false;
                        break;
                    }
                }
            }
            if (draw) {
                printBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            }
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
