#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX_SIZE 1000000

typedef struct {
    size_t first;
    size_t second;
} pos_t;

void touch_pos(size_t r, size_t c, size_t d, const size_t *len, size_t **dist, size_t **q, size_t *q_size) {
    pos_t pos = {r, (c < len[r]) ? c : len[r]};
    if (d < dist[r][pos.second]) {
        dist[r][pos.second] = d;
        q[(*q_size)++] = pos;
    }
}

void c253() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    size_t len[MAX_SIZE];
    size_t nrow;
    fscanf(fin, "%zu", &nrow);
    for (size_t i = 0; i < nrow; i++) {
        fscanf(fin, "%zu", &len[i]);
    }

    pos_t first, last;
    fscanf(fin, "%zu %zu", &first.first, &first.second);
    fscanf(fin, "%zu %zu", &last.first, &last.second);

    first.first -= 1;
    first.second -= 1;
    last.first -= 1;
    last.second -= 1;

    if (first.first == last.first && first.second == last.second) {
        fprintf(fout, "0");
        fclose(fin);
        fclose(fout);
        return;
    }

    const size_t INF = SIZE_MAX;
    size_t **dist = (size_t **)malloc(nrow * sizeof(size_t *));
    for (size_t j = 0; j < nrow; j++) {
        dist[j] = (size_t *)malloc((len[j] + 1) * sizeof(size_t));
        for (size_t k = 0; k <= len[j]; k++) {
            dist[j][k] = INF;
        }
    }

    pos_t **q = (pos_t **)malloc(MAX_SIZE * sizeof(pos_t *));
    size_t q_size = 0;
    q[q_size++] = first;
    dist[first.first][first.second] = 0;

    while (q_size > 0) {
        pos_t current = q[--q_size];
        size_t r = current.first;
        size_t c = current.second;
        size_t d = dist[r][c] + 1;

        if (r > 0 && (last.first == r - 1 && last.second == c)) {
            break;
        }
        if (r + 1 < nrow && (last.first == r + 1 && last.second == c)) {
            break;
        }
        if (c > 0 && (last.first == r && last.second == c - 1)) {
            break;
        }
        if (c < len[r] && (last.first == r && last.second == c + 1)) {
            break;
        }

        touch_pos(r - 1, c, d, len, dist, q, &q_size);
        touch_pos(r + 1, c, d, len, dist, q, &q_size);
        touch_pos(r, c - 1, d, len, dist, q, &q_size);
        touch_pos(r, c + 1, d, len, dist, q, &q_size);
    }
    fprintf(fout, "%zu", dist[last.first][last.second]);

    for (size_t j = 0; j < nrow; j++) {
        free(dist[j]);
    }
    free(dist);
    free(q);
    fclose(fin);
    fclose(fout);
}

int main() {
    c253();
    return 0;
}
