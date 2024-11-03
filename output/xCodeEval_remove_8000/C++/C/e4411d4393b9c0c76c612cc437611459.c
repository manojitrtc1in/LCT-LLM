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

    size_t* len = (size_t*)malloc(nrow * sizeof(size_t));
    for (size_t i = 0; i < nrow; i++) {
        scanf("%zu", &len[i]);
    }

    size_t first_r, first_c, last_r, last_c;
    scanf("%zu %zu %zu %zu", &first_r, &first_c, &last_r, &last_c);
    pair_t first = make_pair(first_r - 1, first_c - 1);
    pair_t last = make_pair(last_r - 1, last_c - 1);

    if (first.first == last.first && first.second == last.second) {
        printf("0");
        return;
    }

    size_t INF = ULONG_MAX;
    size_t** dist = (size_t**)malloc(nrow * sizeof(size_t*));
    for (size_t i = 0; i < nrow; i++) {
        dist[i] = (size_t*)malloc((len[i] + 1) * sizeof(size_t));
        for (size_t j = 0; j <= len[i]; j++) {
            dist[i][j] = INF;
        }
    }

    pair_t* q = (pair_t*)malloc(nrow * sizeof(pair_t));
    size_t front = 0;
    size_t rear = 0;
    q[rear++] = first;
    dist[first.first][first.second] = 0;

    pair_t (*touch)(size_t, size_t, size_t) = touch_pos;

    while (front < rear) {
        pair_t pos = q[front++];
        size_t r = pos.first;
        size_t c = pos.second;
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

    size_t* adj = (size_t*)malloc(n * sizeof(size_t));
    size_t* adj_size = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        adj_size[i] = 0;
    }

    for (size_t i = 0; i < n - 1; i++) {
        size_t u = i < fst ? i : i + 1;
        size_t v = a[i];
        adj[u * n + adj_size[u]++] = v;
        adj[v * n + adj_size[v]++] = u;
    }

    size_t front = 0;
    size_t rear = 0;
    tag[lst] = lst;
    size_t* q = (size_t*)malloc(n * sizeof(size_t));
    q[rear++] = lst;
    while (front < rear) {
        size_t u = q[front++];
        for (size_t i = 0; i < adj_size[u]; i++) {
            size_t v = adj[u * n + i];
            if (tag[v] == NIL) {
                tag[v] = u;
                q[rear++] = v;
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
    free(adj_size);
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
    b[0] = ULONG_MAX;
    for (size_t i = 1; i < n; i++) {
        if (xs[i] < a[i - 1]) {
            b[i] = a[i - 1];
            a[i] = xs[i];
        } else {
            a[i] = a[i - 1];
            b[i] = xs[i] < b[i - 1] ? xs[i] : b[i - 1];
        }
    }

    size_t* pos = (size_t*)malloc((n + 1) * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        pos[xs[i]] = i;
    }

    size_t* soln = (size_t*)malloc(n * sizeof(size_t));
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

    size_t** xs = (size_t**)malloc(n * sizeof(size_t*));
    for (size_t i = 0; i < n; i++) {
        xs[i] = (size_t*)malloc(4 * sizeof(size_t));
        for (size_t j = 0; j < 4; j++) {
            scanf("%zu", &xs[i][j]);
        }
    }

    for (size_t i = 0; i < n; i++) {
        size_t* b = xs[i];
        for (size_t j = 0; j < 4; j++) {
            size_t* a = xs[i];
            for (size_t k = 0; k < 4; k++) {
                size_t tmp = a[0];
                a[0] = a[1];
                a[1] = a[2];
                a[2] = a[3];
                a[3] = tmp;
                if (a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] < b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3]) {
                    b = a;
                }
            }
        }
        xs[i] = b;
    }

    size_t* soln = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        soln[i] = xs[i][0] * 1000 + xs[i][1] * 100 + xs[i][2] * 10 + xs[i][3];
    }

    free(xs);
    size_t* end = unique(soln, soln + n);
    return end - soln;
}

void b444() {
    size_t n, d;
    int64_t x;
    scanf("%zu %zu %lld", &n, &d, &x);

    int64_t* a = (int64_t*)malloc(n * sizeof(int64_t));
    bool* b = (bool*)malloc(n * sizeof(bool));
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
        bool c = b[i];
        b[i] = b[j];
        b[j] = c;
    }

    size_t* soln = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        soln[i] = 0;
    }

    size_t* idx = (size_t*)malloc(n * sizeof(size_t));
    size_t idx_size = 0;
    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            idx[idx_size++] = i;
        }
    }

    typedef struct {
        int64_t val;
        size_t idx;
    } value_type;

    Heap<value_type> heap;
    for (size_t i = 0; i < n; i++) {
        heap.push((value_type){a[i], i});
        if (heap.size() > 1000000) {
            heap.pop();
        }
    }

    while (!heap.empty()) {
        value_type val = heap.front();
        heap.pop();
        for (size_t i = 0; i < idx_size; i++) {
            if (idx[i] + val.idx < n) {
                soln[idx[i] + val.idx] = val.val;
            } else {
                break;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (soln[i] == 0) {
            for (size_t j = 0; j < idx_size; j++) {
                if (i < idx[j]) {
                    break;
                } else {
                    soln[i] = a[i - idx[j]];
                }
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        printf("%zu\n", soln[i]);
    }

    free(a);
    free(b);
    free(soln);
    free(idx);
}

int main() {
    b444();
    return 0;
}
