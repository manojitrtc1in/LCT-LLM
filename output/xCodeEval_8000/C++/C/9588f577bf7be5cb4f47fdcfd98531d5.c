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

    size_t first_row, first_col, last_row, last_col;
    scanf("%zu %zu %zu %zu", &first_row, &first_col, &last_row, &last_col);

    Pair first = make_pair(first_row - 1, first_col - 1);
    Pair last = make_pair(last_row - 1, last_col - 1);

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

    Pair* q = (Pair*)malloc(sizeof(Pair) * nrow * nrow);
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

        if (r < nrow - 1 && last.first == touch(r + 1, c, d, len, dist, q + q_end)) {
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

int main() {
    c253();
    return 0;
}
