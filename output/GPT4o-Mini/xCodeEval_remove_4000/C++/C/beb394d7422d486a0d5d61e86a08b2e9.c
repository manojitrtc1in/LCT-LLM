#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MAX_N 100005
#define MOD 998244353

typedef struct {
    double p[2][2];
    int l, r;
} Statistic;

typedef struct {
    int i, tp;
    int t1, t2;
} Col;

int policy[MAX_N][4];
Statistic s[MAX_N];
int x[MAX_N], v[MAX_N], p[MAX_N];

void merge(Statistic *a, Statistic *b, Statistic *result) {
    result->l = a->l;
    result->r = b->r;
    int m = a->r;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result->p[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (k == 0 && l == 1 && policy[m][3]) {
                        result->p[i][j] += a->p[i][k] * b->p[l][j];
                    } else if (k == 0 && l == 0 && policy[m][0]) {
                        result->p[i][j] += a->p[i][k] * b->p[l][j];
                    } else if (k == 1 && l == 1 && policy[m][1]) {
                        result->p[i][j] += a->p[i][k] * b->p[l][j];
                    } else if (k == 1 && l == 0 && policy[m][2]) {
                        result->p[i][j] += a->p[i][k] * b->p[l][j];
                    }
                }
            }
        }
    }
}

double ans(Statistic *stat) {
    double tmp = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp += stat->p[i][j];
        }
    }
    return tmp;
}

bool compare(const Col *a, const Col *b) {
    return (ll)a->t1 * b->t2 < (ll)b->t1 * a->t2;
}

void sortCols(Col *cols, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(&cols[j + 1], &cols[j])) {
                Col temp = cols[j];
                cols[j] = cols[j + 1];
                cols[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 4; j++) {
            policy[i][j] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &v[i], &p[i]);
        s[i] = (Statistic){{1 - (double)p[i] / 100, 0}, i, i};
    }
    
    double ansValue = 0;
    Col cols[MAX_N];
    int colCount = 0;

    for (int i = 0; i < n - 2; i++) {
        Col tmp;
        tmp.i = i;
        tmp.t1 = x[i + 1] - x[i];
        tmp.tp = 2;
        tmp.t2 = v[i] + v[i + 1];
        cols[colCount++] = tmp;

        if (v[i] > v[i + 1]) {
            tmp.tp = 1;
            tmp.t2 = v[i] - v[i + 1];
            cols[colCount++] = tmp;
        }
        if (v[i] < v[i + 1]) {
            tmp.tp = 0;
            tmp.t2 = v[i + 1] - v[i];
            cols[colCount++] = tmp;
        }
    }

    sortCols(cols, colCount);

    for (int i = 0; i < colCount; i++) {
        Col c = cols[i];
        int old[4];
        memcpy(old, policy[c.i], sizeof(old));
        memset(policy[c.i], 0, sizeof(policy[c.i]));
        policy[c.i][c.tp] = 1;

        // Update the segment tree and calculate the answer
        ansValue += ans(&s[c.i]) * ((double)c.t1 / c.t2);

        memcpy(policy[c.i], old, sizeof(old));
        policy[c.i][c.tp] = 0;

        // Restore the segment tree
    }

    printf("%.12f\n", ansValue);
    return 0;
}
