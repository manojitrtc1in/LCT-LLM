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

bool canBeLeader[MAX_N];
bool used[MAX_N];
int n, m;

void solve() {
    scanf("%d %d", &n, &m);
    memset(canBeLeader, true, sizeof(canBeLeader));
    Event inputEvents[MAX_M];

    for (int i = 0; i < m; ++i) {
        char type[2];
        int index;
        scanf("%s %d", type, &index);
        inputEvents[i].enter = (type[0] == '+');
        inputEvents[i].index = index - 1;
    }

    int meetingSize = 0;
    int wasBefore[MAX_N] = {0};
    int wasBeforeCount = 0;

    for (int i = 0; i < m; ++i) {
        if (!inputEvents[i].enter && !used[inputEvents[i].index]) {
            wasBefore[wasBeforeCount++] = inputEvents[i].index;
        }
        used[inputEvents[i].index] = true;
    }

    int zeros[MAX_N];
    int zerosCount = 0;

    meetingSize = wasBeforeCount;
    for (int i = 0; i < m; ++i) {
        if (inputEvents[i].enter) {
            if (meetingSize != 0) {
                canBeLeader[inputEvents[i].index] = false;
            } else {
                zeros[zerosCount++] = inputEvents[i].index;
            }
            ++meetingSize;
        } else {
            --meetingSize;
            if (meetingSize != 0) {
                canBeLeader[inputEvents[i].index] = false;
            } else {
                zeros[zerosCount++] = inputEvents[i].index;
            }
        }
    }

    if (zerosCount > 1) {
        for (int i = 0; i < zerosCount; ++i) {
            canBeLeader[zeros[i]] = false;
        }
    } else if (zerosCount == 1) {
        int zeroEnter = zeros[0];
        if (wasBeforeCount > 0 && !wasBefore[zeroEnter]) {
            canBeLeader[zeroEnter] = false;
        }
    }

    int possibleLeaders[MAX_N];
    int possibleLeadersCount = 0;
    for (int i = 0; i < n; ++i) {
        if (canBeLeader[i]) {
            possibleLeaders[possibleLeadersCount++] = i;
        }
    }

    printf("%d\n", possibleLeadersCount);
    for (int i = 0; i < possibleLeadersCount; ++i) {
        printf("%d ", possibleLeaders[i] + 1);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}
