#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int x, y;
} Point;

typedef struct {
    int *edges[MAX_N];
    int size[MAX_N];
    int n;
} Tree;

Tree tree;
Point points[MAX_N];
int subtree_sz[MAX_N];
int xy_mapping[MAX_N];

void read_tree() {
    for (int i = 0; i < tree.n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        tree.edges[u][tree.size[u]++] = v;
        tree.edges[v][tree.size[v]++] = u;
    }
}

void read_points() {
    for (int i = 0; i < tree.n; i++) {
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

void sort_by_angle(int l, int r, int cur_xy, double *angles, int *indices) {
    if (r < l) return;
    for (int i = l; i <= r; i++) {
        angles[i] = get_angle(cur_xy, indices[i]);
    }
    double max_angle = angles[l];
    for (int i = l; i <= r; i++) {
        if (angles[i] + M_PI < max_angle) {
            angles[i] += 2 * M_PI;
        }
    }
    // Simple bubble sort for demonstration; replace with a more efficient sort if needed
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (angles[i] > angles[j]) {
                double temp_angle = angles[i];
                angles[i] = angles[j];
                angles[j] = temp_angle;

                int temp_index = indices[i];
                indices[i] = indices[j];
                indices[j] = temp_index;
            }
        }
    }
}

void solve_rec(int l, int r, int root, int parent, double *angles, int *indices) {
    int curr_xy = indices[r--];
    xy_mapping[curr_xy] = root;
    sort_by_angle(l, r, curr_xy, angles, indices);
    int cur_l = l;
    for (int i = 0; i < tree.size[root]; i++) {
        int child = tree.edges[root][i];
        if (child == parent) continue;
        int cur_r = cur_l + subtree_sz[child] - 1;
        int nxt_l = cur_r + 1;
        solve_rec(cur_l, cur_r, child, root, angles, indices);
        cur_l = nxt_l;
    }
}

void calculate_subtree_sizes(int i, int p) {
    subtree_sz[i] = 1;
    for (int j = 0; j < tree.size[i]; j++) {
        int child = tree.edges[i][j];
        if (child == p) continue;
        calculate_subtree_sizes(child, i);
        subtree_sz[i] += subtree_sz[child];
    }
}

void solve() {
    scanf("%d", &tree.n);
    for (int i = 0; i < tree.n; i++) {
        tree.size[i] = 0;
    }
    read_tree();
    read_points();
    calculate_subtree_sizes(0, -1);
    int indices[MAX_N];
    double angles[MAX_N];
    for (int i = 0; i < tree.n; i++) {
        indices[i] = i;
    }
    // Sort points based on y-coordinate
    qsort(indices, tree.n, sizeof(int), [](const void *a, const void *b) {
        return points[*(int *)b].y - points[*(int *)a].y;
    });
    solve_rec(0, tree.n - 1, 0, -1, angles, indices);
    for (int i = 0; i < tree.n; i++) {
        printf("%d ", xy_mapping[i] + 1);
    }
    printf("\n");
}

int main() {
    tree.n = MAX_N;
    solve();
    return 0;
}
