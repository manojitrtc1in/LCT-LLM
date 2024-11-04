#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288419716939937510

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int u;
    int v;
} Edge;

typedef struct {
    int n;
    Edge* edges;
    Point* points;
    int* subtree_sizes;
    int* xy_mapping;
    double* angles;
} Solver;

Solver* create_solver(int n) {
    Solver* solver = (Solver*)malloc(sizeof(Solver));
    solver->n = n;
    solver->edges = (Edge*)malloc((n-1) * sizeof(Edge));
    solver->points = (Point*)malloc(n * sizeof(Point));
    solver->subtree_sizes = (int*)malloc(n * sizeof(int));
    solver->xy_mapping = (int*)malloc(n * sizeof(int));
    solver->angles = (double*)malloc(n * sizeof(double));
    return solver;
}

void destroy_solver(Solver* solver) {
    free(solver->edges);
    free(solver->points);
    free(solver->subtree_sizes);
    free(solver->xy_mapping);
    free(solver->angles);
    free(solver);
}

void read_tree(Solver* solver) {
    for (int i = 0; i < solver->n - 1; i++) {
        scanf("%d %d", &(solver->edges[i].u), &(solver->edges[i].v));
    }
}

void read_points(Solver* solver) {
    for (int i = 0; i < solver->n; i++) {
        scanf("%d %d", &(solver->points[i].x), &(solver->points[i].y));
    }
}

double x_dist(Point p1, Point p2) {
    return (double)(p2.x - p1.x);
}

double y_dist(Point p1, Point p2) {
    return (double)(p2.y - p1.y);
}

double get_angle(Point p1, Point p2) {
    double x_diff = x_dist(p1, p2);
    double y_diff = y_dist(p1, p2);
    return atan2(y_diff, x_diff);
}

void sort_by_angle(Solver* solver, int l, int r, int cur_xy) {
    if (r < l) return;
    for (int i = l; i <= r; i++) {
        solver->angles[i] = get_angle(solver->points[cur_xy], solver->points[i]);
    }
    double max_angle = solver->angles[l];
    for (int i = l; i <= r; i++) {
        if (solver->angles[i] + PI < max_angle) {
            solver->angles[i] += 2 * PI;
        }
        if (solver->angles[i] > max_angle) {
            max_angle = solver->angles[i];
        }
    }
    // TODO: Implement sorting by angle
}

void solve_rec(Solver* solver, int l, int r, int root, int parent) {
    int curr_xy = solver->xy_mapping[r];
    solver->xy_mapping[curr_xy] = root;
    sort_by_angle(solver, l, r, curr_xy);
    int cur_l = l;
    for (int i = 0; i < solver->n - 1; i++) {
        if (solver->edges[i].u == root || solver->edges[i].v == root) {
            int cur_r = cur_l + solver->subtree_sizes[i] - 1;
            int id3 = cur_r + 1;
            solve_rec(solver, cur_l, cur_r, (solver->edges[i].u == root) ? solver->edges[i].v : solver->edges[i].u, root);
            cur_l = id3;
        }
    }
}

void calculate_subtree_sizes(Solver* solver, int i, int p) {
    solver->subtree_sizes[i] = 1;
    for (int j = 0; j < solver->n - 1; j++) {
        if (solver->edges[j].u == i || solver->edges[j].v == i) {
            int child = (solver->edges[j].u == i) ? solver->edges[j].v : solver->edges[j].u;
            calculate_subtree_sizes(solver, child, i);
            solver->subtree_sizes[i] += solver->subtree_sizes[child];
        }
    }
}

void solve(Solver* solver) {
    read_tree(solver);
    read_points(solver);
    calculate_subtree_sizes(solver, 0, -1);
    for (int i = 0; i < solver->n; i++) {
        solver->xy_mapping[i] = i;
    }
    solve_rec(solver, 0, solver->n - 1, 0, -1);
    for (int i = 0; i < solver->n; i++) {
        solver->xy_mapping[i]++;
    }
    for (int i = 0; i < solver->n; i++) {
        printf("%d ", solver->xy_mapping[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Solver* solver = create_solver(n);
    solve(solver);
    destroy_solver(solver);
    return 0;
}
