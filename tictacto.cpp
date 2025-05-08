#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;
int columnOwner[3] = {0, 0, 0}; // Tracks which player owns each column (0 = unowned, 1 = Player 1, 2 = Player 2)

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    // Check if the column is already owned by a player
    if (columnOwner[col] != 0) {
        cout << "This column is already selected by Player " << columnOwner[col] << "! Choose a different column.\n";
        return false;
    }

    // Check if the slot is available
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;

        // If the column is now fully occupied, assign ownership to the current player
        bool columnFullyOccupied = true;
        for (int i = 0; i < 3; i++) {
            if (board[i][col] != 'X' && board[i][col] != 'O') {
                columnFullyOccupied = false;
                break;
            }
        }
        if (columnFullyOccupied) {
            columnOwner[col] = currentPlayer;
        }

        return true;
    } else {
        cout << "Slot already occupied! Choose a different slot.\n";
        return false;
    }
}

int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int winner = 0;
    for (int i = 0; i < 9; i++) {
        cout << "It's Player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            i--;
            continue;
        }

        drawBoard();

        winner = checkWinner();
        if (winner != 0) {
            cout << "Player " << winner << " wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0) {
        cout << "It's a tie!\n";
    }
}

int main() {
    game();
    return 0;
}