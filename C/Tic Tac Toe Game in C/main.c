#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];
char currentPlayer;
int userWins;

void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

bool isBoardFull() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin() {
    int i;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }
    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}

void updateScoreFile() {
    FILE *file = fopen("score.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", userWins);
        fclose(file);
    }
}

void readScoreFile() {
    FILE *file = fopen("score.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &userWins);
        fclose(file);
    }
}

int main() {
    initializeBoard();
    readScoreFile();
    int row, col;
    char playAgain;

    do {
        currentPlayer = 'X';
        int moves = 0;
        bool gameOver = false;

        printf("Tic Tac Toe\n");
        printf("User Wins: %d\n", userWins);
        printBoard();

        while (!gameOver) {
            printf("Player %c's turn\n", currentPlayer);
            printf("Enter the row (0-2): ");
            scanf("%d", &row);
            printf("Enter the column (0-2): ");
            scanf("%d", &col);

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                printBoard();
                moves++;

                if (checkWin()) {
                    printf("Player %c wins!\n", currentPlayer);
                    if (currentPlayer == 'X') {
                        userWins++;
                    }
                    gameOver = true;
                } else if (isBoardFull()) {
                    printf("It's a tie!\n");
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                printf("Invalid move. Try again.\n");
            }
        }

        updateScoreFile();

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain == 'n' || playAgain == 'N') {
            break;
        } else {
            initializeBoard();
            printf("\n");
        }
    } while (1);

    return 0;
}
