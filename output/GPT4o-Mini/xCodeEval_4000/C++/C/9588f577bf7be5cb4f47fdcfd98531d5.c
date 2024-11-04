#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef long long int int64;

#define INF SIZE_MAX

typedef struct {
    size_t first;
    size_t second;
} pos_t;

void touch_pos(size_t r, size_t c, size_t d, const size_t *len, size_t **dist, size_t *q, size_t *front, size_t *rear) {
    pos_t pos = {r, (c < len[r]) ? c : len[r]};
    if (d < dist[r][pos.second]) {
        dist[r][pos.second] = d;
        q[(*rear)++] = pos.first;
        q[(*rear)++] = pos.second;
    }
}

void c253() {
    size_t len[100]; // Adjust size as needed
    size_t nrow;
    scanf("%zu", &nrow);
    for (size_t i = 0; i < nrow; i++) {
        scanf("%zu", &len[i]);
    }

    pos_t first, last;
    scanf("%zu %zu", &first.first, &first.second);
    scanf("%zu %zu", &last.first, &last.second);

    first.first--;
    first.second--;
    last.first--;
    last.second--;

    if (first.first == last.first && first.second == last.second) {
        printf("0\n");
        return;
    }

    size_t **dist = malloc(nrow * sizeof(size_t *));
    for (size_t j = 0; j < nrow; j++) {
        dist[j] = malloc((len[j] + 1) * sizeof(size_t));
        for (size_t k = 0; k <= len[j]; k++) {
            dist[j][k] = INF;
        }
    }

    size_t *q = malloc(nrow * len[0] * sizeof(size_t)); // Adjust size as needed
    size_t front = 0, rear = 0;

    q[rear++] = first.first;
    q[rear++] = first.second;
    dist[first.first][first.second] = 0;

    while (front < rear) {
        size_t r = q[front++];
        size_t c = q[front++];
        size_t d = dist[r][c] + 1;

        if (r > 0 && last.first == touch_pos(r - 1, c, d, len, dist, q, &front, &rear)) break;
        if (r + 1 < nrow && last.first == touch_pos(r + 1, c, d, len, dist, q, &front, &rear)) break;
        if (c > 0 && last.first == touch_pos(r, c - 1, d, len, dist, q, &front, &rear)) break;
        if (c < len[r] && last.first == touch_pos(r, c + 1, d, len, dist, q, &front, &rear)) break;
    }

    printf("%zu\n", dist[last.first][last.second]);

    for (size_t j = 0; j < nrow; j++) {
        free(dist[j]);
    }
    free(dist);
    free(q);
}

void d34() {
    size_t n, fst, lst;
    scanf("%zu %zu %zu", &n, &fst, &lst);
    fst--;
    lst--;

    size_t a[100]; // Adjust size as needed
    for (size_t j = 0; j < n - 1; j++) {
        scanf("%zu", &a[j]);
        a[j]--;
    }

    size_t adj[100][100] = {0}; // Adjust size as needed
    for (size_t j = 0; j < n - 1; j++) {
        size_t u = (j < fst) ? j : j + 1;
        size_t v = a[j];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    size_t NIL = n + 1;
    size_t tag[100] = {NIL}; // Adjust size as needed
    size_t q[100]; // Adjust size as needed
    size_t front = 0, rear = 0;

    tag[lst] = lst;
    q[rear++] = lst;
    while (front < rear) {
        size_t u = q[front++];
        for (size_t v = 0; v < n; v++) {
            if (adj[u][v] && tag[v] == NIL) {
                tag[v] = u;
                q[rear++] = v;
            }
        }
    }

    for (size_t j = 0; j < n; j++) {
        if (tag[j] != NIL) {
            printf("%zu ", tag[j] + 1);
        }
    }
    printf("\n");
}

void b140() {
    size_t n;
    scanf("%zu", &n);
    size_t l[100][100]; // Adjust size as needed
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%zu", &l[i][j]);
        }
    }

    size_t xs[100]; // Adjust size as needed
    for (size_t i = 0; i < n; i++) {
        scanf("%zu", &xs[i]);
    }

    size_t a[100], b[100];
    a[0] = xs[0];
    b[0] = INF;

    for (size_t j = 1; j < n; j++) {
        if (xs[j] < a[j - 1]) {
            b[j] = a[j - 1];
            a[j] = xs[j];
        } else {
            a[j] = a[j - 1];
            b[j] = fmin(b[j - 1], xs[j]);
        }
    }

    size_t pos[101] = {0}; // Adjust size as needed
    for (size_t j = 0; j < n; j++) {
        pos[xs[j]] = j;
    }

    size_t soln[100] = {0}; // Adjust size as needed
    for (size_t j = 0; j < n; j++) {
        for (size_t i = 0; i < n; i++) {
            if (l[j][i] != j + 1) {
                size_t k = pos[l[j][i]];
                size_t run_min = (a[k] != j + 1) ? a[k] : b[k];

                if (l[j][i] <= run_min) {
                    soln[j] = l[j][i];
                    break;
                }
            }
        }
    }

    for (size_t j = 0; j < n; j++) {
        printf("%zu ", soln[j]);
    }
    printf("\n");
}

size_t a51() {
    size_t n;
    scanf("%zu", &n);

    size_t xs[100][4]; // Adjust size as needed
    for (size_t j = 0; j < n; j++) {
        size_t a, b;
        scanf("%zu %zu", &a, &b);
        xs[j][0] = a / 10;
        xs[j][1] = a % 10;
        xs[j][2] = b % 10;
        xs[j][3] = b / 10;

        if (j + 1 != n) {
            char str[100]; // Adjust size as needed
            scanf("%s", str);
        }
    }

    for (size_t j = 0; j < n; j++) {
        size_t b[4] = {xs[j][0], xs[j][1], xs[j][2], xs[j][3]};
        for (size_t i = 0; i < 4; i++) {
            size_t temp = b[0];
            for (size_t k = 0; k < 3; k++) {
                b[k] = b[k + 1];
            }
            b[3] = temp;
            if (memcmp(b, xs[j], sizeof(xs[j])) < 0) {
                memcpy(xs[j], b, sizeof(xs[j]));
            }
        }
    }

    qsort(xs, n, sizeof(xs[0]), (int (*)(const void *, const void *))strcmp);
    return (size_t)(unique(xs, xs + n) - xs);
}

void b444() {
    size_t n, d;
    int64 x;
    scanf("%zu %zu %lld", &n, &d, &x);

    int64 a[100]; // Adjust size as needed
    bool b[100] = {false}; // Adjust size as needed
    for (size_t i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    for (size_t i = 0; i < n; i++) {
        x = (x * 37 + 10007) % 1000000007LL;
        int64 temp = a[i];
        a[i] = a[x % (i + 1)];
        a[x % (i + 1)] = temp;
    }

    for (size_t i = 0; i < d; i++) {
        b[i] = true;
    }

    for (size_t i = 0; i < n; i++) {
        x = (x * 37 + 10007) % 1000000007LL;
        bool temp = b[i];
        b[i] = b[x % (i + 1)];
        b[x % (i + 1)] = temp;
    }

    int64 soln[100] = {0}; // Adjust size as needed
    size_t idx[100]; // Adjust size as needed
    size_t idx_count = 0;

    for (size_t j = 0; j < n; j++) {
        if (b[j]) {
            idx[idx_count++] = j;
        }
    }

    for (size_t j = 0; j < n; j++) {
        if (soln[j] == 0) {
            for (size_t i = 0; i < idx_count; i++) {
                if (j < idx[i]) {
                    break;
                } else {
                    soln[j] = fmax(soln[j], a[j - idx[i]]);
                }
            }
        }
    }

    for (size_t j = 0; j < n; j++) {
        printf("%lld\n", soln[j]);
    }
}

int main() {
    b444();
    return 0;
}
