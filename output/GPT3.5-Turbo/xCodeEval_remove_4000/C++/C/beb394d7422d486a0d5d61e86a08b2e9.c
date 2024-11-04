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
    int s_size = n;
    int s[s_size][2][2];
    for (i = 0; i < s_size; i++) {
        s[i][0][0] = 1 - (p[i] / 100);
        s[i][0][1] = 0;
        s[i][1][0] = 0;
        s[i][1][1] = p[i] / 100;
    }
    int ans = 0;
    int cols_size = (n-1) * 3;
    col cols[cols_size];
    int cols_index = 0;
    for (i = 0; i < n-1; i++) {
        cols[cols_index].i = i;
        cols[cols_index].t1 = x[i + 1] - x[i];
        cols[cols_index].tp = 2;
        cols[cols_index].t2 = v[i] + v[i + 1];
        cols_index++;
        if (v[i] > v[i + 1]) {
            cols[cols_index].i = i;
            cols[cols_index].t1 = x[i + 1] - x[i];
            cols[cols_index].tp = 1;
            cols[cols_index].t2 = v[i] - v[i + 1];
            cols_index++;
        }
        if (v[i] < v[i + 1]) {
            cols[cols_index].i = i;
            cols[cols_index].t1 = x[i + 1] - x[i];
            cols[cols_index].tp = 0;
            cols[cols_index].t2 = v[i + 1] - v[i];
            cols_index++;
        }
    }
    qsort(cols, cols_size, sizeof(col), cmp);
    for (i = 0; i < cols_size; i++) {
        int old[4];
        for (j = 0; j < 4; j++) {
            old[j] = policy[cols[i].i][j];
        }
        for (j = 0; j < 4; j++) {
            policy[cols[i].i][j] = 0;
        }
        policy[cols[i].i][cols[i].tp] = 1;
        s[cols[i].i][0][0] = 1 - (p[cols[i].i] / 100);
        s[cols[i].i][0][1] = 0;
        s[cols[i].i][1][0] = 0;
        s[cols[i].i][1][1] = p[cols[i].i] / 100;
        int tmp = 0;
        for (j = 0; j < s_size; j++) {
            tmp += s[j][0][0] + s[j][0][1] + s[j][1][0] + s[j][1][1];
        }
        cols[i].ans = tmp;
        ans += cols[i].ans * (cols[i].t1 / cols[i].t2);
        for (j = 0; j < 4; j++) {
            policy[cols[i].i][j] = old[j];
        }
        s[cols[i].i][0][0] = 1 - (p[cols[i].i] / 100);
        s[cols[i].i][0][1] = 0;
        s[cols[i].i][1][0] = 0;
        s[cols[i].i][1][1] = p[cols[i].i] / 100;
    }
    printf("%d\n", ans);
    return 0;
}
