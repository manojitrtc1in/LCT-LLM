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

void touch_pos(size_t r, size_t c, size_t d, const size_t *len, size_t **dist, size_t *q, size_t *front, size_t *rear) {
    pos_t pos = {r, (c < len[r]) ? c : len[r]};
    if (d < dist[r][pos.second]) {
        dist[r][pos.second] = d;
        q[++(*rear)] = pos.first * MAX_SIZE + pos.second; // Store as a single integer
    }
}

void c253() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    size_t len[MAX_SIZE];
    size_t nrow;
    fscanf(fin, "%zu", &nrow);
    for (size_t i = 0; i < nrow; ++i) {
        fscanf(fin, "%zu", &len[i]);
    }

    pos_t first, last;
    fscanf(fin, "%zu %zu", &first.first, &last.first);
    first.first--;
    last.first--;

    if (first.first == last.first) {
        fprintf(fout, "0\n");
        fclose(fin);
        fclose(fout);
        return;
    }

    const size_t INF = SIZE_MAX;
    size_t **dist = (size_t **)malloc(nrow * sizeof(size_t *));
    for (size_t j = 0; j < nrow; ++j) {
        dist[j] = (size_t *)malloc((len[j] + 1) * sizeof(size_t));
        for (size_t k = 0; k <= len[j]; ++k) {
            dist[j][k] = INF;
        }
    }

    size_t *q = (size_t *)malloc(MAX_SIZE * sizeof(size_t));
    size_t front = 0, rear = -1;
    q[++rear] = first.first * MAX_SIZE + first.second;
    dist[first.first][first.second] = 0;

    while (front <= rear) {
        size_t pos = q[front++];
        size_t r = pos / MAX_SIZE;
        size_t c = pos % MAX_SIZE;
        size_t d = dist[r][c] + 1;

        if (r > 0 && last.first == touch_pos(r - 1, c, d, len, dist, q, &front, &rear)) break;
        if (r + 1 < nrow && last.first == touch_pos(r + 1, c, d, len, dist, q, &front, &rear)) break;
        if (c > 0 && last.first == touch_pos(r, c - 1, d, len, dist, q, &front, &rear)) break;
        if (c < len[r] && last.first == touch_pos(r, c + 1, d, len, dist, q, &front, &rear)) break;
    }

    fprintf(fout, "%zu\n", dist[last.first][last.second]);

    for (size_t j = 0; j < nrow; ++j) {
        free(dist[j]);
    }
    free(dist);
    free(q);
    fclose(fin);
    fclose(fout);
}

int main() {
    c253();
    return EXIT_SUCCESS;
}
