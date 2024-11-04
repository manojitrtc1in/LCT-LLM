#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_POINTS 1000
#define MOD 1000000007
#define INF 100000000

typedef struct {
    int x, y, index, used;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int count;
} PointList;

typedef struct {
    char *cache;
    size_t cache_size;
    size_t cache_offset;
    FILE *input;
    FILE *output;
} FastIO;

void initFastIO(FastIO *io, FILE *input, FILE *output) {
    io->cache_size = 1 << 13;
    io->cache = (char *)malloc(io->cache_size);
    io->cache_offset = 0;
    io->input = input;
    io->output = output;
}

void flush(FastIO *io) {
    fwrite(io->cache, 1, io->cache_offset, io->output);
    io->cache_offset = 0;
}

void appendToCache(FastIO *io, const char *str) {
    size_t len = strlen(str);
    if (io->cache_offset + len >= io->cache_size) {
        flush(io);
    }
    strcpy(io->cache + io->cache_offset, str);
    io->cache_offset += len;
}

int readInt(FastIO *io) {
    int value = 0, sign = 1;
    char c;
    while ((c = fgetc(io->input)) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        sign = -1;
        c = fgetc(io->input);
    } else if (c == '+') {
        c = fgetc(io->input);
    }
    do {
        value = value * 10 + (c - '0');
    } while ((c = fgetc(io->input)) >= '0' && c <= '9');
    return value * sign;
}

char readChar(FastIO *io) {
    char c;
    while ((c = fgetc(io->input)) <= 32);
    return c;
}

long long cross(int x1, int y1, int x2, int y2) {
    return (long long)x1 * y2 - (long long)y1 * x2;
}

void solve(FastIO *io, PointList *points, int n) {
    Point *last = &points->points[0];
    for (int i = 1; i < n; i++) {
        if (points->points[i].x == last->x) {
            if (points->points[i].y < last->y) {
                last = &points->points[i];
            }
        } else if (points->points[i].x > last->x) {
            last = &points->points[i];
        }
    }

    last->used = 1;
    char buffer[20];
    sprintf(buffer, "%d ", last->index);
    appendToCache(io, buffer);

    for (int i = 0; i < n - 2; i++) {
        char c = readChar(io);
        Point *choose = NULL;
        for (int j = 0; j < n; j++) {
            if (points->points[j].used) continue;
            if (choose == NULL || (c == 'L' ? cross(points->points[j].x - last->x, points->points[j].y - last->y, choose->x - last->x, choose->y - last->y) < 0 : cross(points->points[j].x - last->x, points->points[j].y - last->y, choose->x - last->x, choose->y - last->y) > 0)) {
                choose = &points->points[j];
            }
        }
        last = choose;
        last->used = 1;
        sprintf(buffer, "%d ", last->index);
        appendToCache(io, buffer);
    }

    for (int i = 0; i < n; i++) {
        if (!points->points[i].used) {
            sprintf(buffer, "%d ", points->points[i].index);
            appendToCache(io, buffer);
        }
    }
}

int main() {
    FastIO io;
    initFastIO(&io, stdin, stdout);
    
    int n = readInt(&io);
    PointList points;
    points.count = n;

    for (int i = 0; i < n; i++) {
        points.points[i].x = readInt(&io);
        points.points[i].y = readInt(&io);
        points.points[i].index = i + 1;
        points.points[i].used = 0;
    }

    solve(&io, &points, n);
    flush(&io);
    free(io.cache);
    return 0;
}
