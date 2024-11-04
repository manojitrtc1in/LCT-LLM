#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    size_t first;
    size_t second;
} Pair;

Pair make_pair(size_t first, size_t second) {
    Pair pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

Pair touch_pos(size_t r, size_t c, size_t d, size_t* len, size_t** dist, Pair* q, size_t nrow) {
    Pair pos = make_pair(r, c < len[r] ? c : len[r]);
    if (d < dist[r][pos.second]) {
        dist[r][pos.second] = d;
        q[nrow] = pos;
        nrow++;
    }
    return pos;
}

void c253() {
    size_t nrow;
    scanf("%zu", &nrow);

    size_t* len = malloc(nrow * sizeof(size_t));
    for (size_t i = 0; i < nrow; i++) {
        scanf("%zu", &len[i]);
    }

    size_t first_r, first_c, last_r, last_c;
    scanf("%zu %zu %zu %zu", &first_r, &first_c, &last_r, &last_c);

    Pair first = make_pair(first_r - 1, first_c - 1);
    Pair last = make_pair(last_r - 1, last_c - 1);

    if (first.first == last.first && first.second == last.second) {
        printf("0");
        return;
    }

    size_t INF = ULONG_MAX;
    size_t** dist = malloc(nrow * sizeof(size_t*));
    for (size_t i = 0; i < nrow; i++) {
        dist[i] = malloc((len[i] + 1) * sizeof(size_t));
        for (size_t j = 0; j <= len[i]; j++) {
            dist[i][j] = INF;
        }
    }

    Pair* q = malloc(nrow * nrow * sizeof(Pair));
    size_t qhead = 0;
    size_t qtail = 0;
    q[qtail++] = first;
    dist[first.first][first.second] = 0;

    Pair (*touch)(size_t, size_t, size_t) = touch_pos;

    while (qhead < qtail) {
        Pair u = q[qhead++];
        size_t r = u.first;
        size_t c = u.second;
        size_t d = dist[r][c] + 1;

        if (r > 0 && last.first == touch(r - 1, c, d)) {
            break;
        }

        if (r + 1 < nrow && last.first == touch(r + 1, c, d)) {
            break;
        }

        if (c > 0 && last.first == touch(r, c - 1, d)) {
            break;
        }

        if (c < len[r] && last.first == touch(r, c + 1, d)) {
            break;
        }
    }

    printf("%zu", dist[last.first][last.second]);

    free(len);
    for (size_t i = 0; i < nrow; i++) {
        free(dist[i]);
    }
    free(dist);
    free(q);
}

void d34() {
    size_t n;
    scanf("%zu", &n);

    size_t fst, lst;
    scanf("%zu %zu", &fst, &lst);
    fst--;
    lst--;

    size_t* a = malloc((n - 1) * sizeof(size_t));
    for (size_t i = 0; i < n - 1; i++) {
        scanf("%zu", &a[i]);
        a[i]--;
    }

    size_t NIL = n + 1;
    size_t* tag = malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        tag[i] = NIL;
    }

    size_t* adj = malloc(n * n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        adj[i * n + i] = 0;
        for (size_t j = i + 1; j < n; j++) {
            adj[i * n + j] = adj[j * n + i] = NIL;
        }
    }

    for (size_t i = 0; i < n - 1; i++) {
        size_t u = i < fst ? i : i + 1;
        size_t v = a[i];
        adj[u * n + v] = adj[v * n + u] = 1;
    }

    tag[lst] = lst;

    size_t qhead = 0;
    size_t qtail = 0;
    size_t* q = malloc(n * sizeof(size_t));
    q[qtail++] = lst;

    while (qhead < qtail) {
        size_t u = q[qhead++];
        for (size_t v = 0; v < n; v++) {
            if (adj[u * n + v] == 1 && tag[v] == NIL) {
                tag[v] = u;
                q[qtail++] = v;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (i != lst) {
            printf("%zu ", tag[i] + 1);
        }
    }

    free(a);
    free(tag);
    free(adj);
    free(q);
}

void b140() {
    size_t n;
    scanf("%zu", &n);

    size_t** l = malloc(n * sizeof(size_t*));
    for (size_t i = 0; i < n; i++) {
        l[i] = malloc(n * sizeof(size_t));
        for (size_t j = 0; j < n; j++) {
            scanf("%zu", &l[i][j]);
        }
    }

    size_t* xs = malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        scanf("%zu", &xs[i]);
    }

    size_t* a = malloc(n * sizeof(size_t));
    size_t* b = malloc(n * sizeof(size_t));
    a[0] = xs[0];
    b[0] = SIZE_MAX;

    for (size_t i = 1; i < n; i++) {
        if (xs[i] < a[i - 1]) {
            b[i] = a[i - 1];
            a[i] = xs[i];
        } else {
            a[i] = a[i - 1];
            b[i] = b[i - 1] < xs[i] ? b[i - 1] : xs[i];
        }
    }

    size_t* pos = malloc((n + 1) * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        pos[xs[i]] = i;
    }

    size_t* soln = malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        soln[i] = SIZE_MAX;
    }

    for (size_t j = 0; j < n; j++) {
        for (size_t i = 0; i < n; i++) {
            if (l[j][i] != j + 1 && l[j][i] <= (a[pos[l[j][i]]] != j + 1 ? a[pos[l[j][i]]] : b[pos[l[j][i]]])) {
                soln[j] = l[j][i];
                break;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        printf("%zu ", soln[i]);
    }

    free(l);
    free(xs);
    free(a);
    free(b);
    free(pos);
    free(soln);
}

size_t a51() {
    size_t n;
    scanf("%zu", &n);

    size_t** xs = malloc(n * sizeof(size_t*));
    for (size_t i = 0; i < n; i++) {
        xs[i] = malloc(4 * sizeof(size_t));
        for (size_t j = 0; j < 4; j++) {
            scanf("%zu", &xs[i][j]);
        }
    }

    for (size_t i = 0; i < n; i++) {
        size_t* b = xs[i];
        for (size_t j = 0; j < 4; j++) {
            size_t* a = xs[i];
            for (size_t k = 0; k < 4; k++) {
                if (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]) ||
                    (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]) ||
                    (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] < b[3])) {
                    b = a;
                }
                size_t tmp = a[0];
                a[0] = a[1];
                a[1] = a[2];
                a[2] = a[3];
                a[3] = tmp;
            }
        }
        xs[i] = b;
    }

    size_t count = 1;
    for (size_t i = 1; i < n; i++) {
        if (xs[i][0] != xs[i - 1][0] || xs[i][1] != xs[i - 1][1] ||
            xs[i][2] != xs[i - 1][2] || xs[i][3] != xs[i - 1][3]) {
            count++;
        }
    }

    for (size_t i = 0; i < n; i++) {
        printf("%zu %zu %zu %zu\n", xs[i][0], xs[i][1], xs[i][2], xs[i][3]);
    }

    for (size_t i = 0; i < n; i++) {
        free(xs[i]);
    }
    free(xs);

    return count;
}

void b444() {
    size_t n, d;
    int64_t x;
    scanf("%zu %zu %lld", &n, &d, &x);

    size_t* a = malloc(n * sizeof(size_t));
    bool* b = malloc(n * sizeof(bool));
    for (size_t i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = false;
    }

    for (size_t i = 0; i < n; i++) {
        x = (x * 37 + 10007) % 1000000007;
        size_t j = x % (i + 1);
        size_t tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    for (size_t i = 0; i < d; i++) {
        x = (x * 37 + 10007) % 1000000007;
        size_t j = x % (i + 1);
        bool tmp = b[i];
        b[i] = b[j];
        b[j] = tmp;
    }

    size_t* soln = malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        soln[i] = 0;
    }

    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            count++;
            for (size_t j = i; j < n; j++) {
                soln[j] = a[i];
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        printf("%zu\n", soln[i]);
    }

    free(a);
    free(b);
    free(soln);
}

int main() {
    b444();
    return 0;
}
