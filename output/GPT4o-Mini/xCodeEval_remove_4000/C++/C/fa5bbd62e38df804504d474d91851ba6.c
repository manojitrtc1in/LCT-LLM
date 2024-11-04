#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100005
#define PI 3.14159265358979323846264338327950288419716939937510

typedef struct {
    int x, y;
} Point;

typedef struct {
    int *data;
    int size;
} Vector;

typedef struct {
    int *edges[MAX_N];
    int size[MAX_N];
    int n;
} Graph;

Graph graph;
Point points[MAX_N];
int subtree_sz[MAX_N];
int xy_mapping[MAX_N];
double angles[MAX_N];

void read_tree() {
    for (int i = 0; i < graph.n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        graph.edges[u][graph.size[u]++] = v;
        graph.edges[v][graph.size[v]++] = u;
    }
}

void read_points() {
    for (int i = 0; i < graph.n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

long long x_dist(int i, int j) {
    return (long long)points[j].x - (long long)points[i].x;
}

long long y_dist(int i, int j) {
    return (long long)points[j].y - (long long)points[i].y;
}

double get_angle(int i, int j) {
    return atan2(y_dist(i, j), x_dist(i, j));
}

void sort_by_angle(int l, int r, int cur_xy) {
    if (r < l) return;
    for (int i = l; i <= r; i++) {
        angles[i] = get_angle(cur_xy, i);
    }
    double max_angle = angles[l];
    for (int i = l; i <= r; i++) {
        if (angles[i] + PI < max_angle) {
            angles[i] += 2 * PI;
        }
    }
    // Simple bubble sort for demonstration
    for (int i = l; i <= r; i++) {
        for (int j = l; j < r; j++) {
            if (angles[j] > angles[j + 1]) {
                double temp_angle = angles[j];
                angles[j] = angles[j + 1];
                angles[j + 1] = temp_angle;
            }
        }
    }
}

void solve_rec(int l, int r, int root, int parent) {
    int curr_xy = r--;
    xy_mapping[curr_xy] = root;
    sort_by_angle(l, r, curr_xy);
    int cur_l = l;
    for (int i = 0; i < graph.size[root]; i++) {
        int child = graph.edges[root][i];
        if (child == parent) continue;
        int cur_r = cur_l + subtree_sz[child] - 1;
        solve_rec(cur_l, cur_r, child, root);
        cur_l = cur_r + 1;
    }
}

void calculate_subtree_sizes(int i, int p) {
    subtree_sz[i] = 1;
    for (int j = 0; j < graph.size[i]; j++) {
        int child = graph.edges[i][j];
        if (child == p) continue;
        calculate_subtree_sizes(child, i);
        subtree_sz[i] += subtree_sz[child];
    }
}

void solve() {
    scanf("%d", &graph.n);
    for (int i = 0; i < graph.n; i++) {
        graph.size[i] = 0;
    }
    read_tree();
    read_points();
    calculate_subtree_sizes(0, -1);
    for (int i = 0; i < graph.n; i++) {
        angles[i] = i;
    }
    solve_rec(0, graph.n - 1, 0, -1);
    for (int i = 0; i < graph.n; i++) {
        printf("%d ", xy_mapping[i] + 1);
    }
    printf("\n");
}

int main() {
    graph.n = MAX_N;
    solve();
    return 0;
}
