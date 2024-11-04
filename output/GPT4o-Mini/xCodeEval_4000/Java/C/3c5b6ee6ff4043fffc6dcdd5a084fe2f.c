#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100
#define MAX_RUNS 100

typedef struct {
    char *x;
    char *y;
} State;

int hashCode(State *state) {
    int prime = 31;
    int result = 1;
    result = prime * result + (state->x ? (int)strlen(state->x) : 0);
    result = prime * result + (state->y ? (int)strlen(state->y) : 0);
    return result;
}

bool equals(State *a, State *b) {
    return strcmp(a->x, b->x) == 0 && strcmp(a->y, b->y) == 0;
}

int *runs(const char *s, int *size) {
    int *ret = malloc(MAX_RUNS * sizeof(int));
    *size = 0;
    int run = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (i != strlen(s) - 1 && s[i + 1] != s[i]) {
            ret[(*size)++] = run;
            run = 0;
        }
        run++;
    }
    ret[(*size)++] = run;
    return ret;
}

int slow(const char *s, const char *t) {
    State *queue[MAX_LEN];
    int front = 0, rear = 0;

    State *initialState = malloc(sizeof(State));
    initialState->x = strdup(s);
    initialState->y = strdup(t);
    queue[rear++] = initialState;

    int dist[MAX_LEN] = {0};
    dist[hashCode(initialState)] = 0;

    while (front < rear) {
        State *st = queue[front++];
        char *x = st->x;
        char *y = st->y;
        int curD = dist[hashCode(st)];

        if ((strchr(x, 'a') == NULL || strchr(x, 'b') == NULL) &&
            (strchr(y, 'a') == NULL || strchr(y, 'b') == NULL)) {
            return dist[hashCode(st)];
        }

        for (int i = 0; i <= strlen(x); i++) {
            for (int j = 0; j <= strlen(y); j++) {
                char *x0 = strndup(x, i);
                char *x1 = strdup(x + i);
                char *y0 = strndup(y, j);
                char *y1 = strdup(y + j);

                char *nx = malloc(strlen(y0) + strlen(x1) + 1);
                char *ny = malloc(strlen(x0) + strlen(y1) + 1);
                sprintf(nx, "%s%s", y0, x1);
                sprintf(ny, "%s%s", x0, y1);

                State *nst = malloc(sizeof(State));
                nst->x = nx;
                nst->y = ny;

                if (dist[hashCode(nst)] == 0) {
                    dist[hashCode(nst)] = curD + 1;
                    queue[rear++] = nst;
                }

                free(x0);
                free(x1);
                free(y0);
                free(y1);
                free(nst);
            }
        }
        free(st->x);
        free(st->y);
        free(st);
    }

    return -1; // Should not reach here
}

int fast(const char *s, const char *t) {
    int ret[MAX_RUNS];
    int rsSize, rtSize;
    int *rs = runs(s, &rsSize);
    int *rt = runs(t, &rtSize);
    bool areSame = s[0] == t[0];

    while (areSame) {
        int p = rsSize;
        int q = rtSize;
        int x = -1, y = -1;

        for (int xx = 0; xx <= 3 && xx <= p; xx++) {
            for (int yy = 0; yy <= 3 && yy <= q; yy++) {
                if (xx + yy == 0 || x + y == xx + yy) continue;
                if (xx % 2 == yy % 2) continue;

                int nx = p - xx + yy;
                if (xx != p && yy != 0) nx--;
                int ny = q - yy + xx;
                if (yy != q && xx != 0) ny--;

                if (nx == 0 || ny == 0) continue;
                if (nx + ny == p + q) continue;

                int val = (xx == 0 || yy == 0) && (xx + yy) % 2 == 1 ? 1 : 0; // Placeholder for fastSame and fastDiff

                if (val == 0) { // Placeholder for fastSame(p, q)
                    x = xx;
                    y = yy;
                    break;
                }
            }
        }

        if ((x == 0 || y == 0) && (x + y) % 2 == 1) {
            areSame = false;
        }

        // Handle deletions and updates to rs and rt here
        // This part needs to be implemented based on the logic of the original Java code
    }

    // Final processing and output
    free(rs);
    free(rt);
    return 0; // Placeholder return
}

void submit() {
    char s[MAX_LEN], t[MAX_LEN];
    scanf("%s %s", s, t);
    fast(s, t);
}

int main() {
    submit();
    return 0;
}
