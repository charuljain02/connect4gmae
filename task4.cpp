#include <iostream>
#include <vector>
#include <string>

// Global constants for the game board dimensions
const int ROWS = 6;
const int COLS = 7;

// Function prototypes
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, int col, char player);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool isBoardFull(const std::vector<std::vector<char>>& board);

int main() {
    // Initialize a 6x7 board filled with empty spaces '.'
    std::vector<std::vector<char>> board(ROWS, std::vector<char>(COLS, '.'));
    
    char currentPlayer = 'X'; // Player 1 is 'X', Player 2 is 'O'
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "=================================\n";
    std::cout << "      WELCOME TO CONNECT 4       \n";
    std::cout << "=================================\n\n";

    while (!gameWon && !gameDraw) {
        displayBoard(board);
        
        int colChoice;
        std::cout << "Player " << currentPlayer << ", enter a column (1-" << COLS << "): ";
        std::cin >> colChoice;

        // Input validation
        if (std::cin.fail() || colChoice < 1 || colChoice > COLS) {
            std::cin.clear(); // clear error state
            std::cin.ignore(10000, '\n'); // discard invalid input
            std::cout << "Invalid column! Please choose between 1 and " << COLS << ".\n\n";
            continue;
        }

        // Adjust for 0-indexed vector mapping
        int actualCol = colChoice - 1;

        // Try to place the piece
        if (!makeMove(board, actualCol, currentPlayer)) {
            std::cout << "Column " << colChoice << " is full! Try a different one.\n\n";
            continue;
        }

        // Check for win or draw conditions
        gameWon = checkWin(board, currentPlayer);
        if (gameWon) {
            displayBoard(board);
            std::cout << "\nCONGRATULATIONS! Player " << currentPlayer << " wins!\n";
            break;
        }

        gameDraw = isBoardFull(board);
        if (gameDraw) {
            displayBoard(board);
            std::cout << "\nIt's a draw! The board is completely full.\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        std::cout << "\n";
    }

    return 0;
}

// Renders the board layout to the console
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (int i = 0; i < ROWS; ++i) {
        std::cout << "| ";
        for (int j = 0; j < COLS; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "|\n";
    }
    
    // Print bottom boundary and column numbers
    std::cout << "-----------------\n  ";
    for (int j = 1; j <= COLS; ++j) {
        std::cout << j << " ";
    }
    std::cout << "\n\n";
}

// Drops the piece down to the lowest available row in the selected column
bool makeMove(std::vector<std::vector<char>>& board, int col, char player) {
    // Start scanning from the bottom row up
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == '.') {
            board[i][col] = player;
            return true; // Successfully placed
        }
    }
    return false; // Column is completely full
}

// Scans the board to detect any 4-in-a-row streaks
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // 1. Horizontal verification
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i][j+1] == player && 
                board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }

    // 2. Vertical verification
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && board[i+1][j] == player && 
                board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }

    // 3. Diagonal verification (Descending: Top-Left to Bottom-Right)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i+1][j+1] == player && 
                board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }

    // 4. Diagonal verification (Ascending: Bottom-Left to Top-Right)
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i-1][j+1] == player && 
                board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return true;
            }
        }
    }

    return false;
}

// Helper to determine if the top row is completely choked up with pieces
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (int j = 0; j < COLS; ++j) {
        if (board[0][j] == '.') {
            return false; // Found an empty spot on top row, game continues
        }
    }
    return true;
}
