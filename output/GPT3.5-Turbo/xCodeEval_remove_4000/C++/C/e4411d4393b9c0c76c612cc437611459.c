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
        q[r] = pos;
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
            dist[i][j] = SIZE_MAX;
        }
    }

    pair_t* q = malloc(nrow * sizeof(pair_t));
    for (size_t i = 0; i < nrow; i++) {
        q[i] = make_pair(i, i < len[i] ? i : len[i]);
    }

    size_t INF = SIZE_MAX;
    while (true) {
        size_t r = SIZE_MAX;
        size_t c = SIZE_MAX;
        size_t d = SIZE_MAX;
        for (size_t i = 0; i < nrow; i++) {
            if (q[i].first != SIZE_MAX && dist[q[i].first][q[i].second] < d) {
                r = q[i].first;
                c = q[i].second;
                d = dist[q[i].first][q[i].second];
            }
        }
        if (r == SIZE_MAX) {
            break;
        }
        q[r].first = SIZE_MAX;
        if (r > 0) {
            pair_t pos = touch_pos(r - 1, c, d + 1, len, dist, q, nrow);
            if (pos.first == last.first && pos.second == last.second) {
                break;
            }
        }
        if (r + 1 < nrow) {
            pair_t pos = touch_pos(r + 1, c, d + 1, len, dist, q, nrow);
            if (pos.first == last.first && pos.second == last.second) {
                break;
            }
        }
        if (c > 0) {
            pair_t pos = touch_pos(r, c - 1, d + 1, len, dist, q, nrow);
            if (pos.first == last.first && pos.second == last.second) {
                break;
            }
        }
        if (c < len[r]) {
            pair_t pos = touch_pos(r, c + 1, d + 1, len, dist, q, nrow);
            if (pos.first == last.first && pos.second == last.second) {
                break;
            }
        }
    }

    printf("%zu", dist[last.first][last.second]);

    for (size_t i = 0; i < nrow; i++) {
        free(dist[i]);
    }
    free(dist);
    free(len);
    free(q);
}

int main() {
    c253();
    return 0;
}
