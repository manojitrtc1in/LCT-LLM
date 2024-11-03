#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int v[MAX_SIZE];
    int q[MAX_SIZE];
    int p;
    int z;
} Population;

void add(Population *pop, int t) {
    pop->q[t] = pop->v[t];
}

void remove(Population *pop, int t) {
    pop->q[t] = 0;
}

Population *createPopulation(int n, int p) {
    Population *pop = malloc(sizeof(Population));
    memset(pop->v, 0, sizeof(pop->v));
    memset(pop->q, 0, sizeof(pop->q));
    pop->p = p;
    pop->z = 0;
    for (int i = 0; i < n; i++) {
        if (i != p) {
            add(pop, i);
        }
    }
    return pop;
}

int maxElement(Population *pop, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (pop->v[i] > pop->v[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

bool isPopulation(Population *pop, int n) {
    return pop->v[maxElement(pop, n)] >= pop->z;
}

void change(Population *pop, int t, int val) {
    if (t == pop->p) {
        pop->z += val;
    } else {
        remove(pop, t);
        pop->v[t] += val;
        add(pop, t);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
    } else {
        int v[MAX_SIZE];
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            v[i]--;
        }
        int q[MAX_SIZE], qq[MAX_SIZE];
        int mx = 0;
        for (int i = 0; i < n; i++) {
            q[v[i]]++;
            if (q[v[i]] > q[mx]) {
                mx = v[i];
            }
        }
        int p = mx;
        int u[MAX_SIZE][MAX_SIZE];
        memset(u, 0, sizeof(u));
        for (int i = 0; i < n; i++) {
            if (i != p) {
                u[q[i]][++u[q[i]][0]] = i;
            }
        }
        int uu[MAX_SIZE], uul = 0;
        for (int i = n; i >= 0; i--) {
            if (u[i][0] > 0) {
                uu[uul++] = i;
            }
        }
        int last = 0;
        int leftmost[MAX_SIZE][MAX_SIZE];
        memset(leftmost, 0, sizeof(leftmost));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= q[i]; j++) {
                leftmost[i][j] = n + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != p) {
                q[v[i]]++;
            }
        }
        for (int y = 0; y < n && y < 100; y++) {
            if (y != p) {
                int g[MAX_SIZE], gl = 0;
                memset(g, -1, sizeof(g));
                int b = 0;
                for (int i = 0; i < n; i++) {
                    if (v[i] == p) {
                        ans = ans > i - g[gl - b - 1] - 1 ? ans : i - g[gl - b - 1] - 1;
                        if (b > 0) {
                            b--;
                        } else {
                            g[gl++] = i;
                        }
                    } else if (v[i] == y) {
                        b++;
                    }
                }
                ans = ans > n - g[gl - b - 1] - 1 ? ans : n - g[gl - b - 1] - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
