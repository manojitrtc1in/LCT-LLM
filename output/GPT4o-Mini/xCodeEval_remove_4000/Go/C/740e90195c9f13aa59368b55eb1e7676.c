#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 1000
#define MAX_VISITED 1000000

typedef struct {
    int x, y;
} Position;

bool visited[MAX_VISITED];

void nextWord(char *buffer) {
    scanf("%s", buffer);
}

int main() {
    char path[MAX_PATH_LENGTH];
    nextWord(path);

    Position pos = {0, 0};
    visited[0] = true;

    for (int i = 0; path[i] != '\0'; i++) {
        char c = path[i];
        switch (c) {
            case 'U':
                pos.y--;
                break;
            case 'D':
                pos.y++;
                break;
            case 'L':
                pos.x--;
                break;
            case 'R':
                pos.x++;
                break;
        }

        long long index = (long long)(pos.x * 1000 + pos.y);
        if (visited[index]) {
            printf("BUG\n");
            return 0;
        }

        int count = 0;
        if (visited[(pos.x - 1) * 1000 + pos.y]) count++;
        if (visited[(pos.x + 1) * 1000 + pos.y]) count++;
        if (visited[pos.x * 1000 + (pos.y - 1)]) count++;
        if (visited[pos.x * 1000 + (pos.y + 1)]) count++;

        if (count > 1) {
            printf("BUG\n");
            return 0;
        }

        visited[index] = true;
    }

    printf("OK\n");
    return 0;
}
