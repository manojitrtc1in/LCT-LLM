#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Edge {
    struct Point* vertex0;
    struct Point* vertex1;
    int bidirectional;
} Edge;

typedef struct Vertex {
    int index;
    struct Edge** edges;
    int num_edges;
} Vertex;

typedef struct Graph {
    struct Vertex** vertices;
    int num_vertices;
} Graph;

int countLines(Point** points, int num_points) {
    int* xs = (int*)malloc(num_points * sizeof(int));
    int* ys = (int*)malloc(num_points * sizeof(int));
    int num_xs = 0;
    int num_ys = 0;
    for (int i = 0; i < num_points; i++) {
        int x = points[i]->x;
        int y = points[i]->y;
        int found_x = 0;
        int found_y = 0;
        for (int j = 0; j < num_xs; j++) {
            if (xs[j] == x) {
                found_x = 1;
                break;
            }
        }
        for (int j = 0; j < num_ys; j++) {
            if (ys[j] == y) {
                found_y = 1;
                break;
            }
        }
        if (!found_x) {
            xs[num_xs++] = x;
        }
        if (!found_y) {
            ys[num_ys++] = y;
        }
    }
    free(xs);
    free(ys);
    return num_xs + num_ys;
}

long modMultiply(long a, long b, long mod) {
    return ((a % mod) * (b % mod)) % mod;
}

long modAdd(long a, long b, long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

long modSubtract(long a, long b, long mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

long id12(int a, long mod) {
    long result = 1;
    for (int i = 0; i < a; i++) {
        result = modMultiply(result, 2, mod);
    }
    return result;
}

void solve() {
    int n;
    scanf("%d", &n);
    Point** points = (Point**)malloc(n * sizeof(Point*));
