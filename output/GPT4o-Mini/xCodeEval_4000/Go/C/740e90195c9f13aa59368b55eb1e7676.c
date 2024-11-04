#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 10000
#define MAX_VISITED 1000000

typedef struct {
    int x;
    int y;
} Point;

bool visited[MAX_VISITED];

void init_visited() {
    for (int i = 0; i < MAX_VISITED; i++) {
        visited[i] = false;
    }
}

int main() {
    char path[MAX_PATH_LENGTH];
    fgets(path, sizeof(path), stdin);

    int x = 0, y = 0;
    init_visited();
    visited[0] = true;

    for (int i = 0; path[i] != '\0'; i++) {
        char c = path[i];
        switch (c) {
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
        }

        int pos = x * 1000 + y;
        if (visited[pos]) {
            printf("BUG\n");
            return 0;
        }

        int count = 0;
        if (visited[(x - 1) * 1000 + y]) count++;
        if (visited[(x + 1) * 1000 + y]) count++;
        if (visited[x * 1000 + (y - 1)]) count++;
        if (visited[x * 1000 + (y + 1)]) count++;

        if (count > 1) {
            printf("BUG\n");
            return 0;
        }

        visited[pos] = true;
    }

    printf("OK\n");
    return 0;
}
