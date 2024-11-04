#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i, tp;
    int t1, t2;
    int ans;
} col;

int cmp(const void *a, const void *b) {
    col *colA = (col *)a;
    col *colB = (col *)b;
    return (colA->t1 * colB->t2) - (colB->t1 * colA->t2);
}

int main() {
    int n;
    scanf("%d", &n);
    int policy[n-1][4];
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < 4; j++) {
            policy[i][j] = 1;
        }
    }
    int x[n], v[n], p[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &v[i], &p[i]);
    }
    int ans = 0;
    col cols[(n-1)*3];
    int colIndex = 0;
    for (i = 0; i < n-1; i++) {
        col tmp;
        tmp.i = i;
        tmp.t1 = x[i + 1] - x[i];
        tmp.tp = 2;
        tmp.t2 = v[i] + v[i + 1];
        cols[colIndex++] = tmp;
        if (v[i] > v[i + 1]) {
            tmp.tp = 1;
            tmp.t2 = v[i] - v[i + 1];
            cols[colIndex++] = tmp;
        }
        if (v[i] < v[i + 1]) {
            tmp.tp = 0;
            tmp.t2 = v[i + 1] - v[i];
            cols[colIndex++] = tmp;
        }
    }
    qsort(cols, colIndex, sizeof(col), cmp);
    for (i = 0; i < colIndex; i++) {
        int old[4];
        for (j = 0; j < 4; j++) {
            old[j] = policy[cols[i].i][j];
            policy[cols[i].i][j] = 0;
        }
        policy[cols[i].i][cols[i].tp] = 1;
        ans += policy[cols[i].i][0] * policy[cols[i].i][1] * policy[cols[i].i][2] * policy[cols[i].i][3] * cols[i].ans;
        for (j = 0; j < 4; j++) {
            policy[cols[i].i][j] = old[j];
        }
        if (policy[cols[i].i][0] * policy[cols[i].i][1] * policy[cols[i].i][2] * policy[cols[i].i][3] == 0) {
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
