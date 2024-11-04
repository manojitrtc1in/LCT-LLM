#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

typedef long long int int64;

void touch_pos(size_t r, size_t c, size_t d, const size_t *len, size_t **dist, size_t *q, size_t *front, size_t *rear) {
    size_t pos_c = (c < len[r]) ? c : len[r];
    if (d < dist[r][pos_c]) {
        dist[r][pos_c] = d;
        q[(*rear)++] = r;
        q[(*rear)++] = pos_c;
    }
}

void c253() {
    size_t nrow;
    scanf("%zu", &nrow);

    size_t *len = (size_t *)malloc(nrow * sizeof(size_t));
    for (size_t i = 0; i < nrow; i++) {
        scanf("%zu", &len[i]);
    }

    size_t first[2], last[2];
    scanf("%zu %zu", &first[0], &first[1]);
    scanf("%zu %zu", &last[0], &last[1]);

    first[0]--;
    first[1]--;
    last[0]--;
    last[1]--;

    if (first[0] == last[0] && first[1] == last[1]) {
        printf("0\n");
        free(len);
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

    size_t *q = (size_t *)malloc(nrow * len[0] * 2 * sizeof(size_t));
    size_t front = 0, rear = 0;

    q[rear++] = first[0];
    q[rear++] = first[1];
    dist[first[0]][first[1]] = 0;

    while (front < rear) {
        size_t r = q[front++];
        size_t c = q[front++];
        size_t d = dist[r][c] + 1;

        if (r > 0 && last[0] == touch_pos(r - 1, c, d, len, dist, q, &front, &rear)) break;
        if (r + 1 < nrow && last[0] == touch_pos(r + 1, c, d, len, dist, q, &front, &rear)) break;
        if (c > 0 && last[0] == touch_pos(r, c - 1, d, len, dist, q, &front, &rear)) break;
        if (c < len[r] && last[0] == touch_pos(r, c + 1, d, len, dist, q, &front, &rear)) break;
    }

    printf("%zu\n", dist[last[0]][last[1]]);

    for (size_t j = 0; j < nrow; j++) {
        free(dist[j]);
    }
    free(dist);
    free(len);
    free(q);
}

int main() {
    c253();
    return 0;
}
