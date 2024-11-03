#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    size_t first;
    size_t second;
} Pair;

Pair make_pair(size_t first, size_t second) {
    Pair p;
    p.first = first;
    p.second = second;
    return p;
}

Pair touch_pos(size_t r, size_t c, size_t d, size_t* len, size_t** dist, Pair* q) {
    Pair pos = make_pair(r, c < len[r] ? c : len[r]);
    if (d < dist[r][pos.second]) {
        dist[r][pos.second] = d;
        q->first = pos.first;
        q->second = pos.second;
    }
    return pos;
}

void c253() {
    size_t nrow;
    scanf("%zu", &nrow);
    size_t* len = (size_t*)malloc(nrow * sizeof(size_t));
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

    const size_t INF = SIZE_MAX;
    size_t** dist = (size_t**)malloc(nrow * sizeof(size_t*));
    for (size_t i = 0; i < nrow; i++) {
        dist[i] = (size_t*)malloc((len[i] + 1) * sizeof(size_t));
        for (size_t j = 0; j <= len[i]; j++) {
            dist[i][j] = INF;
        }
    }

    Pair* q = (Pair*)malloc(sizeof(Pair) * nrow * (nrow + 1));
    size_t q_start = 0;
    size_t q_end = 0;
    q[q_end++] = first;
    dist[first.first][first.second] = 0;

    Pair (*touch)(size_t, size_t, size_t, size_t*, size_t**, Pair*) = touch_pos;

    while (q_start < q_end) {
        Pair u = q[q_start++];
        size_t r = u.first;
        size_t c = u.second;
        size_t d = dist[r][c] + 1;

        if (r > 0 && last.first == touch(r - 1, c, d, len, dist, q + q_end)) {
            break;
        }

        if (r + 1 < nrow && last.first == touch(r + 1, c, d, len, dist, q + q_end)) {
            break;
        }

        if (c > 0 && last.first == touch(r, c - 1, d, len, dist, q + q_end)) {
            break;
        }

        if (c < len[r] && last.first == touch(r, c + 1, d, len, dist, q + q_end)) {
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

    size_t* a = (size_t*)malloc((n - 1) * sizeof(size_t));
    for (size_t i = 0; i < n - 1; i++) {
        scanf("%zu", &a[i]);
        a[i]--;
    }

    size_t NIL = n + 1;
    size_t* tag = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        tag[i] = NIL;
    }

    size_t* adj = (size_t*)malloc(n * (n - 1) * sizeof(size_t));
    size_t* adj_count = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        adj_count[i] = 0;
    }

    for (size_t i = 0; i < n - 1; i++) {
        size_t u = i < fst ? i : i + 1;
        size_t v = a[i];
        adj[u * (n - 1) + adj_count[u]++] = v;
        adj[v * (n - 1) + adj_count[v]++] = u;
    }

    tag[lst] = lst;
    size_t q_start = 0;
    size_t q_end = 0;
    size_t* q = (size_t*)malloc(n * sizeof(size_t));
    q[q_end++] = lst;
    while (q_start < q_end) {
        size_t u = q[q_start++];
        for (size_t i = 0; i < adj_count[u]; i++) {
            size_t v = adj[u * (n - 1) + i];
            if (tag[v] == NIL) {
                tag[v] = u;
                q[q_end++] = v;
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
    free(adj_count);
    free(q);
}

void b140() {
    size_t n;
    scanf("%zu", &n);
    size_t** l = (size_t**)malloc(n * sizeof(size_t*));
    for (size_t i = 0; i < n; i++) {
        l[i] = (size_t*)malloc(n * sizeof(size_t));
        for (size_t j = 0; j < n; j++) {
            scanf("%zu", &l[i][j]);
        }
    }

    size_t* xs = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        scanf("%zu", &xs[i]);
    }

    size_t* a = (size_t*)malloc(n * sizeof(size_t));
    size_t* b = (size_t*)malloc(n * sizeof(size_t));
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

    size_t* pos = (size_t*)malloc((n + 1) * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        pos[xs[i]] = i;
    }

    size_t* soln = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        soln[i] = SIZE_MAX;
    }

    for (size_t j = 0; j < n; j++) {
        for (size_t i = 0; i < n; i++) {
            if (l[j][i] != j + 1 && l[j][i] <= (a[i] != j + 1 ? a[i] : b[i])) {
                soln[j] = l[j][i];
                break;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (soln[i] == SIZE_MAX) {
            for (size_t j = 0; j < n; j++) {
                if (l[j][i] != j + 1) {
                    soln[i] = l[j][i];
                    break;
                }
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

    size_t** xs = (size_t**)malloc(n * sizeof(size_t*));
    for (size_t i = 0; i < n; i++) {
        xs[i] = (size_t*)malloc(4 * sizeof(size_t));
        for (size_t j = 0; j < 4; j++) {
            scanf("%zu", &xs[i][j]);
        }

        if (i + 1 != n) {
            char str[2];
            scanf("%s", str);
        }
    }

    for (size_t i = 0; i < n; i++) {
        size_t* a = xs[i];
        size_t* b = xs[i];
        for (size_t j = 0; j < 4; j++) {
            size_t* c = a;
            for (size_t k = 0; k < 4; k++) {
                if (c[0] * 10 + c[1] < b[0] * 10 + b[1]) {
                    b = c;
                }
                c++;
                if (c == a + 4) {
                    c = a;
                }
            }
            a++;
        }
        xs[i] = b;
    }

    size_t* sorted = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        sorted[i] = i;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (xs[sorted[i]][0] * 10 + xs[sorted[i]][1] > xs[sorted[j]][0] * 10 + xs[sorted[j]][1]) {
                size_t temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    size_t count = 1;
    for (size_t i = 1; i < n; i++) {
        if (xs[sorted[i]][0] * 10 + xs[sorted[i]][1] != xs[sorted[i - 1]][0] * 10 + xs[sorted[i - 1]][1]) {
            count++;
        }
    }

    free(xs);
    free(sorted);
    return count;
}

int main() {
    printf("%zu\n", a51());
    return 0;
}
