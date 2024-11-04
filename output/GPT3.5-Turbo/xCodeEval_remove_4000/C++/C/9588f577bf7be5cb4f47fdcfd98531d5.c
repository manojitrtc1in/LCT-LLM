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

Pair touch_pos(size_t r, size_t c, size_t d, size_t* len, size_t** dist, Pair* q, size_t nrow) {
    Pair pos = make_pair(r, c < len[r] ? c : len[r]);
    if (d < dist[r][pos.second]) {
        dist[r][pos.second] = d;
        q[nrow * r + pos.second] = pos;
    }
    return pos;
}

void c253() {
    size_t n;
    scanf("%zu", &n);

    size_t* len = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        scanf("%zu", &len[i]);
    }

    Pair first, last;
    scanf("%zu %zu", &first.first, &first.second);
    scanf("%zu %zu", &last.first, &last.second);

    first.first--;
    first.second--;
    last.first--;
    last.second--;

    if (first.first == last.first && first.second == last.second) {
        printf("0");
        return;
    }

    size_t INF = ULONG_MAX;
    size_t** dist = (size_t**)malloc(n * sizeof(size_t*));
    for (size_t i = 0; i < n; i++) {
        dist[i] = (size_t*)malloc((len[i] + 1) * sizeof(size_t));
        for (size_t j = 0; j <= len[i]; j++) {
            dist[i][j] = INF;
        }
    }

    Pair* q = (Pair*)malloc(n * n * sizeof(Pair));
    size_t q_front = 0;
    size_t q_back = 0;

    q[q_back++] = first;
    dist[first.first][first.second] = 0;

    Pair (*touch)(size_t, size_t, size_t) = touch_pos;

    while (q_front < q_back) {
        Pair p = q[q_front++];
        size_t r = p.first;
        size_t c = p.second;
        size_t d = dist[r][c] + 1;

        if (r > 0 && last.first == touch(r - 1, c, d)) {
            break;
        }

        if (r + 1 < n && last.first == touch(r + 1, c, d)) {
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
    for (size_t i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
    free(q);
}

void d34() {
    size_t n, fst, lst;
    scanf("%zu %zu %zu", &n, &fst, &lst);

    size_t* a = (size_t*)malloc((n - 1) * sizeof(size_t));
    for (size_t i = 0; i < n - 1; i++) {
        scanf("%zu", &a[i]);
    }

    size_t NIL = n + 1;
    size_t* tag = (size_t*)malloc(n * sizeof(size_t));
    for (size_t i = 0; i < n; i++) {
        tag[i] = NIL;
    }

    fst--;
    lst--;
    tag[lst] = lst;

    size_t* q = (size_t*)malloc(n * sizeof(size_t));
    size_t q_front = 0;
    size_t q_back = 0;

    q[q_back++] = lst;

    while (q_front < q_back) {
        size_t u = q[q_front++];
        for (size_t i = 0; i < n - 1; i++) {
            if (a[i] == u && tag[i] == NIL) {
                tag[i] = u;
                q[q_back++] = i;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (tag[i] != NIL) {
            tag[i]++;
        }
        printf("%zu ", tag[i]);
    }

    free(a);
    free(tag);
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
        if (xs[i][0] != xs[i - 1][0] ||
            xs[i][1] != xs[i - 1][1] ||
            xs[i][2] != xs[i - 1][2] ||
            xs[i][3] != xs[i - 1][3]) {
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
    }

    for (size_t i = 0; i < d; i++) {
        x = (x * 37 + 10007) % 1000000007;
        size_t j = x % (i + 1);
        bool tmp = b[i];
        b[i] = b[j];
        b[j] = tmp;
    }

    int64_t* soln = (int64_t*)malloc(n * sizeof(int64_t));
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

    size_t budget = 1000000;
    size_t heap_size = 0;
    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            heap_size++;
        }
    }

    size_t* heap = (size_t*)malloc(heap_size * sizeof(size_t));
    size_t heap_front = 0;
    size_t heap_back = 0;

    for (size_t i = 0; i < n; i++) {
        if (b[i]) {
            heap[heap_back++] = a[i];
            if (heap_back > budget) {
                size_t min_idx = 0;
                for (size_t j = 1; j < heap_size; j++) {
                    if (heap[j] < heap[min_idx]) {
                        min_idx = j;
                    }
                }
                heap[min_idx] = heap[--heap_back];
            }
        }
    }

    for (size_t i = 0; i < heap_size; i++) {
        soln[heap[i]] = heap[i];
    }

    for (size_t i = 0; i < n; i++) {
        if (soln[i] == 0) {
            for (size_t j = 0; j < idx_size; j++) {
                if (i < idx[j]) {
                    break;
                }
                soln[i] = a[i - idx[j]];
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
