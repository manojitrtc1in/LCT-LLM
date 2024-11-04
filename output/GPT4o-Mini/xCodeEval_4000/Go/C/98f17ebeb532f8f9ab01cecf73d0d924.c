#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

void nextLine(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        perror("nextLine: EOF reached");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char board[SIZE][SIZE + 1]; // +1 for null terminator
    int total = 0;

    for (int i = 0; i < SIZE; i++) {
        nextLine(board[i], sizeof(board[i]));
        board[i][strcspn(board[i], "\n")] = 0; // Remove newline character
    }

    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'B') {
                count++;
            }
        }
        if (count == SIZE) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = 'A';
            }
            total++;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[j][i] == 'B') {
                total++;
                break;
            }
        }
    }

    printf("%d\n", total);
    return 0;
}
