#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 128

typedef struct {
    int enter;
    int index;
} Event;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    bool canBeLeader[n];
    memset(canBeLeader, true, sizeof(canBeLeader));

    Event inputEvents[m];
    for (int i = 0; i < m; ++i) {
        char type[2];
        scanf("%s %d", type, &inputEvents[i].index);
        inputEvents[i].enter = strcmp(type, "+") == 0 ? 1 : 0;
        inputEvents[i].index--;
    }

    int startMeetingSize = 0;

    int wasBefore[n];
    memset(wasBefore, 0, sizeof(wasBefore));

    bool used[n];
    memset(used, false, sizeof(used));
    for (int i = 0; i < m; ++i) {
        if (!inputEvents[i].enter && !used[inputEvents[i].index]) {
            wasBefore[inputEvents[i].index] = 1;
        }

        used[inputEvents[i].index] = true;
    }

    int zeros[n];
    int zerosCount = 0;

    int meetingSize = 0;
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

        if (wasBefore[zeroEnter] > 0 && !wasBefore[zeroEnter]) {
            canBeLeader[zeroEnter] = false;
        }
    }

    int possibleLeaders[n];
    int possibleLeadersCount = 0;
    for (int i = 0; i < n; ++i) {
        if (canBeLeader[i]) possibleLeaders[possibleLeadersCount++] = i;
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
