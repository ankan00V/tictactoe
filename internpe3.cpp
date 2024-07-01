#include <iostream>
#include <vector>

using namespace std;

// Constants for the board size and player symbols
const int SIZE = 3;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

// Function to initialize the Tic Tac Toe board
vector<vector<char> > initializeBoard() {
    return vector<vector<char> >(SIZE, vector<char>(SIZE, EMPTY));
}

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char> >& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
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

// Function to check if the board is full
bool isBoardFull(const vector<vector<char> >& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) return false;
        }
    }
    return true;
}

// Function to make a move
bool makeMove(vector<vector<char> >& board, int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
        return false;
    }
    board[row][col] = player;
    return true;
}

int main() {
    vector<vector<char> > board = initializeBoard();
    char currentPlayer = PLAYER_X;
    bool gameWon = false;
    
    while (!gameWon && !isBoardFull(board)) {
        printBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        if (makeMove(board, row, col, currentPlayer)) {
            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!" << endl;
            } else {
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    
    return 0;
}
