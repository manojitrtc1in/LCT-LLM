#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    size_t first;
    size_t second;
} pair_t;

pair_t make_pair(size_t first, size_t second) {
    pair_t pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

pair_t touch_pos(size_t r, size_t c, size_t d, size_t* len, size_t** dist, pair_t* q, size_t nrow) {
    pair_t pos = make_pair(r, c < len[r] ? c : len[r]);
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

    size_t first_row, first_col, last_row, last_col;
    scanf("%zu %zu %zu %zu", &first_row, &first_col, &last_row, &last_col);

    pair_t first = make_pair(first_row - 1, first_col - 1);
    pair_t last = make_pair(last_row - 1, last_col - 1);

    if (first.first == last.first && first.second == last.second) {
        printf("0");
        return;
    }

    size_t** dist = malloc(nrow * sizeof(size_t*));
    for (size_t i = 0; i < nrow; i++) {
        dist[i] = malloc((len[i] + 1) * sizeof(size_t));
        for (size_t j = 0; j <= len[i]; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    pair_t* q = malloc(nrow * nrow * sizeof(pair_t));
    size_t q_start = 0;
    size_t q_end = 0;

    q[q_end++] = first;
    dist[first.first][first.second] = 0;

    pair_t (*touch)(size_t, size_t, size_t, size_t*, size_t**, pair_t*, size_t) = touch_pos;

    while (q_start < q_end) {
        pair_t pos = q[q_start++];
        size_t r = pos.first;
        size_t c = pos.second;
        size_t d = dist[r][c] + 1;

        if (r > 0 && last.first == touch(r - 1, c, d, len, dist, q, q_end)) {
            break;
        }

        if (r + 1 < nrow && last.first == touch(r + 1, c, d, len, dist, q, q_end)) {
            break;
        }

        if (c > 0 && last.first == touch(r, c - 1, d, len, dist, q, q_end)) {
            break;
        }

        if (c < len[r] && last.first == touch(r, c + 1, d, len, dist, q, q_end)) {
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

    size_t* a = malloc((n - 1) * sizeof(size_t));
    for (size_t i = 0; i < n - 1; i++) {
        scanf("%zu", &a[i]);
    }

    size_t NIL = n + 1;
    size_t* tag = malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        tag[i] = NIL;
    }

    size_t* adj = malloc(n * sizeof(size_t));
    size_t adj_count = 0;
    for (size_t i = 0; i < n - 1; i++) {
        size_t u = i < fst - 1 ? i : i + 1;
        size_t v = a[i];
        adj[adj_count++] = u;
        adj[adj_count++] = v;
    }

    tag[lst - 1] = lst - 1;
    size_t q_start = 0;
    size_t q_end = 0;
    size_t* q = malloc(n * sizeof(size_t));
    q[q_end++] = lst - 1;

    while (q_start < q_end) {
        size_t u = q[q_start++];
        for (size_t i = 0; i < adj_count; i += 2) {
            size_t v = adj[i];
            if (tag[v] == NIL && adj[i + 1] == u) {
                tag[v] = u;
                q[q_end++] = v;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (i != lst - 1) {
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
        soln[i] = 0;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (l[j][i] != j + 1) {
                size_t k = pos[l[j][i]];
                size_t run_min = a[k] != j + 1 ? a[k] : b[k];
                if (l[j][i] <= run_min) {
                    soln[j] = l[j][i];
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
        bool unique = true;
        for (size_t j = 0; j < 4; j++) {
            if (xs[i][j] != xs[i - 1][j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            count++;
        }
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

    int64_t* a = malloc(n * sizeof(int64_t));
    bool* b = malloc(n * sizeof(bool));
    for (size_t i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = false;
    }

    for (size_t i = 0; i < n; i++) {
        x = (x * 37 + 10007) % 1000000007;
        size_t j = x % (i + 1);
        int64_t tmp = a[i];
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

    int64_t* soln = malloc(n * sizeof(int64_t));
    for (size_t i = 0; i < n; i++) {
        soln[i] = 0;
    }

    size_t* idx = malloc(n * sizeof(size_t));
    size_t idx_count = 0;
    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            idx[idx_count++] = i;
        }
    }

    size_t budget = 1000000;
    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            budget--;
        }
    }

    size_t heap_size = 0;
    int64_t* heap = malloc(budget * sizeof(int64_t));
    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            heap[heap_size++] = a[i];
        }
    }

    for (size_t i = 0; i < heap_size; i++) {
        size_t j = i;
        while (j > 0) {
            size_t k = (j - 1) / 2;
            if (heap[j] < heap[k]) {
                int64_t tmp = heap[j];
                heap[j] = heap[k];
                heap[k] = tmp;
                j = k;
            } else {
                break;
            }
        }
    }

    for (size_t i = heap_size; i < n; i++) {
        size_t j = i;
        while (j > 0) {
            size_t k = (j - 1) / 2;
            if (a[i] < heap[k]) {
                int64_t tmp = heap[k];
                heap[k] = a[i];
                a[i] = tmp;
                j = k;
            } else {
                break;
            }
        }
    }

    for (size_t i = heap_size; i < n; i++) {
        size_t j = 0;
        while (true) {
            size_t k = 2 * j + 1;
            if (k >= i) {
                break;
            }
            if (k + 1 < i && heap[k + 1] < heap[k]) {
                k++;
            }
            if (a[i] < heap[k]) {
                break;
            }
            heap[j] = heap[k];
            j = k;
        }
        heap[j] = a[i];
    }

    for (size_t i = 0; i < heap_size; i++) {
        soln[idx[i]] = heap[i];
    }

    for (size_t i = heap_size; i < n; i++) {
        size_t j = 0;
        while (true) {
            size_t k = 2 * j + 1;
            if (k >= heap_size) {
                break;
            }
            if (k + 1 < heap_size && heap[k + 1] < heap[k]) {
                k++;
            }
            if (a[i] < heap[k]) {
                break;
            }
            heap[j] = heap[k];
            j = k;
        }
        heap[j] = a[i];
    }

    for (size_t i = 0; i < n; i++) {
        if (soln[i] == 0) {
            for (size_t j = 0; j < heap_size; j++) {
                if (i < idx[j]) {
                    break;
                }
                soln[i] = heap[j];
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        printf("%lld\n", soln[i]);
    }

    free(a);
    free(b);
    free(soln);
    free(idx);
    free(heap);
}

int main() {
    b444();
    return 0;
}
