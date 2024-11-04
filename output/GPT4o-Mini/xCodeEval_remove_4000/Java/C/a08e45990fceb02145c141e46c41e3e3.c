#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    bool enter;
    int index;
} Event;

bool id33[MAX_N];
bool used[MAX_N];
bool wasBefore[MAX_N];
int n, m;

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        id33[i] = true;
    }

    Event inputEvents[MAX_M];
    for (int i = 0; i < m; ++i) {
        char type[2];
        int index;
        scanf("%s %d", type, &index);
        inputEvents[i].enter = (type[0] == '+');
        inputEvents[i].index = index - 1;
    }

    int meetingSize = 0;
    for (int i = 0; i < m; ++i) {
        if (!inputEvents[i].enter && !used[inputEvents[i].index]) {
            wasBefore[inputEvents[i].index] = true;
        }
        used[inputEvents[i].index] = true;
    }

    int zeros[MAX_N];
    int zeroCount = 0;

    meetingSize = 0;
    for (int i = 0; i < m; ++i) {
        if (inputEvents[i].enter) {
            if (meetingSize != 0) {
                id33[inputEvents[i].index] = false;
            } else {
                zeros[zeroCount++] = inputEvents[i].index;
            }
            ++meetingSize;
        } else {
            --meetingSize;
            if (meetingSize != 0) {
                id33[inputEvents[i].index] = false;
            } else {
                zeros[zeroCount++] = inputEvents[i].index;
            }
        }
    }

    if (zeroCount > 1) {
        for (int i = 0; i < zeroCount; ++i) {
            id33[zeros[i]] = false;
        }
    } else if (zeroCount == 1) {
        int zeroEnter = zeros[0];
        if (wasBefore[zeroEnter]) {
            id33[zeroEnter] = false;
        }
    }

    int id14[MAX_N];
    int id14Size = 0;
    for (int i = 0; i < n; ++i) {
        if (id33[i]) {
            id14[id14Size++] = i + 1; // Store 1-based index
        }
    }

    printf("%d\n", id14Size);
    for (int i = 0; i < id14Size; ++i) {
        printf("%d ", id14[i]);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}
