#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    bool enter;
    int index;
} Event;

int n, m;
bool id33[MAX_N];
Event inputEvents[MAX_M];
bool used[MAX_N];
bool wasBefore[MAX_N];
bool zeros[MAX_N];
int zerosSize;
int meetingSize;

void solve() {
    scanf("%d %d", &n, &m);

    memset(id33, true, sizeof(id33));
    memset(used, false, sizeof(used));
    memset(wasBefore, false, sizeof(wasBefore));
    memset(zeros, false, sizeof(zeros));
    zerosSize = 0;
    meetingSize = 0;

    for (int i = 0; i < m; ++i) {
        char type[2];
        int index;
        scanf("%s %d", type, &index);
        inputEvents[i].enter = (strcmp(type, "+") == 0);
        inputEvents[i].index = index - 1;
    }

    for (int i = 0; i < m; ++i) {
        Event inputEvent = inputEvents[i];
        if (!inputEvent.enter && !used[inputEvent.index]) {
            wasBefore[inputEvent.index] = true;
        }

        used[inputEvent.index] = true;
    }

    for (int i = 0; i < m; ++i) {
        Event event = inputEvents[i];
        if (event.enter) {
            if (meetingSize != 0) {
                id33[event.index] = false;
            } else {
                zeros[event.index] = true;
                zerosSize++;
            }

            meetingSize++;
        } else {
            meetingSize--;

            if (meetingSize != 0) {
                id33[event.index] = false;
            } else {
                zeros[event.index] = true;
                zerosSize++;
            }
        }
    }

    if (zerosSize > 1) {
        for (int i = 0; i < n; ++i) {
            if (zeros[i]) {
                id33[i] = false;
            }
        }
    } else if (zerosSize == 1) {
        int zeroEnter = -1;
        for (int i = 0; i < n; ++i) {
            if (zeros[i]) {
                zeroEnter = i;
                break;
            }
        }

        if (zeroEnter != -1 && wasBefore[zeroEnter] == false) {
            id33[zeroEnter] = false;
        }
    }

    int id14[MAX_N];
    int id14Size = 0;
    for (int i = 0; i < n; ++i) {
        if (id33[i]) {
            id14[id14Size++] = i;
        }
    }

    printf("%d\n", id14Size);
    for (int i = 0; i < id14Size; ++i) {
        printf("%d ", id14[i] + 1);
    }
    printf("\n");
}

int main() {
    solve();

    return 0;
}
