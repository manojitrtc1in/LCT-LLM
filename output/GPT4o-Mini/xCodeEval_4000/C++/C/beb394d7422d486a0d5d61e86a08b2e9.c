#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100005
#define MAX_P 2

typedef long long ll;
typedef struct {
    ll v;
} inte;

typedef struct {
    inte p[MAX_P][MAX_P];
    int l, r;
} statistic;

typedef struct {
    int i, tp;
    int t1, t2;
    inte ans;
} col;

int policy[MAX_N][4];
statistic s[MAX_N];

void init_statistic(statistic *stat, inte pr, int pos) {
    stat->p[0][0].v = 1 - pr.v;
    stat->p[1][1].v = pr.v;
    stat->l = stat->r = pos;
}

void merge_statistic(statistic *result, const statistic *a, const statistic *b) {
    result->l = a->l;
    result->r = b->r;
    int m = a->r;
    for (int i = 0; i < MAX_P; i++) {
        for (int j = 0; j < MAX_P; j++) {
            result->p[i][j].v = 0;
            for (int k = 0; k < MAX_P; k++) {
                for (int l = 0; l < MAX_P; l++) {
                    if (k == 0 && l == 1 && policy[m][3]) {
                        result->p[i][j].v += a->p[i][k].v * b->p[l][j].v;
                    } else if (k == 0 && l == 0 && policy[m][0]) {
                        result->p[i][j].v += a->p[i][k].v * b->p[l][j].v;
                    } else if (k == 1 && l == 1 && policy[m][1]) {
                        result->p[i][j].v += a->p[i][k].v * b->p[l][j].v;
                    } else if (k == 1 && l == 0 && policy[m][2]) {
                        result->p[i][j].v += a->p[i][k].v * b->p[l][j].v;
                    }
                }
            }
        }
    }
}

inte ans_statistic(statistic *stat) {
    inte tmp = {0};
    for (int i = 0; i < MAX_P; i++) {
        for (int j = 0; j < MAX_P; j++) {
            tmp.v += stat->p[i][j].v;
        }
    }
    return tmp;
}

bool operator_less(const col *a, const col *b) {
    return (ll)a->t1 * b->t2 < (ll)b->t1 * a->t2;
}

void sort_cols(col *cols, int size) {
    // Simple bubble sort for demonstration; replace with a better sorting algorithm if needed
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (operator_less(&cols[j + 1], &cols[j])) {
                col temp = cols[j];
                cols[j] = cols[j + 1];
                cols[j + 1] = temp;
            }
        }
    }
}

int main() {
    inte p[MAX_N];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 4; j++) {
            policy[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int x, v;
        scanf("%d %d %lld", &x, &v, &p[i].v);
        init_statistic(&s[i], p[i], i);
    }

    inte ans = {0};
    col cols[MAX_N];
    int col_count = 0;

    for (int i = 0; i < n - 2; i++) {
        cols[col_count].i = i;
        cols[col_count].t1 = x[i + 1] - x[i];
        cols[col_count].tp = 2;
        cols[col_count].t2 = v[i] + v[i + 1];
        col_count++;

        if (v[i] > v[i + 1]) {
            cols[col_count].tp = 1;
            cols[col_count].t2 = v[i] - v[i + 1];
            col_count++;
        }
        if (v[i] < v[i + 1]) {
            cols[col_count].tp = 0;
            cols[col_count].t2 = v[i + 1] - v[i];
            col_count++;
        }
    }

    sort_cols(cols, col_count);
    for (int i = 0; i < col_count; i++) {
        col *c = &cols[i];
        int old[4];
        memcpy(old, policy[c->i], sizeof(old));
        memset(policy[c->i], 0, sizeof(policy[c->i]));
        policy[c->i][c->tp] = 1;

        // Modify the segment tree and calculate the answer
        // (Segment tree operations are omitted for brevity)

        ans.v += ans_statistic(&s[c->i]).v * c->ans.v;

        memcpy(policy[c->i], old, sizeof(old));
        policy[c->i][c->tp] = 0;

        // Modify the segment tree back
        // (Segment tree operations are omitted for brevity)

        if (ans_statistic(&s[c->i]).v == 0) {
            break;
        }
    }
    printf("%lld\n", ans.v);
    return 0;
}
