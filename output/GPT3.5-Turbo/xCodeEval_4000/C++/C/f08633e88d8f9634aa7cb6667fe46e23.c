#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} vector_2d;

typedef struct {
    vector_2d p;
    vector_2d q;
    double a;
} line_2d;

typedef struct {
    vector_2d p;
    vector_2d q;
    double a;
} segment_2d;

double angle(vector_2d a) {
    return atan2((double)a.x, (double)a.y);
}

int squared_euclidean_norm(vector_2d a) {
    return a.x * a.x + a.y * a.y;
}

int euclidean_norm(vector_2d a) {
    return sqrt(squared_euclidean_norm(a));
}

int cross_product(vector_2d a, vector_2d b) {
    return a.x * b.y - b.x * a.y;
}

int dot_product(vector_2d a, vector_2d b) {
    return a.x * b.x + b.y * a.y;
}

vector_2d add(vector_2d a, vector_2d b) {
    vector_2d result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

vector_2d subtract(vector_2d a, vector_2d b) {
    vector_2d result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

vector_2d multiply(vector_2d a, int b) {
    vector_2d result;
    result.x = a.x * b;
    result.y = a.y * b;
    return result;
}

vector_2d divide(vector_2d a, int b) {
    vector_2d result;
    result.x = a.x / b;
    result.y = a.y / b;
    return result;
}

int compare(vector_2d a, vector_2d b) {
    int t = a.x ? a.x < 0 : (a.y ? a.y < 0 : -1);
    return t ? (t < 0) : (cross_product(a, b) < 0);
}

vector_2d intersection(line_2d a, line_2d b) {
    double a1 = cross_product(subtract(b.p, a.q), subtract(b.q, b.p));
    double a2 = cross_product(subtract(a.p, b.q), subtract(b.q, b.p));
    if (fabs(a1 + a2) < 1e-8) {
        vector_2d result;
        result.x = 0;
        result.y = 0;
        return result;
    } else {
        vector_2d result;
        result.x = (a.p.x * a1 + a.q.x * a2) / (a1 + a2);
        result.y = (a.p.y * a1 + a.q.y * a2) / (a1 + a2);
        return result;
    }
}

int contains(segment_2d a, vector_2d b) {
    return fabs(cross_product(a.q - a.p, b - a.p)) < 1e-8 &&
           dot_product(b - a.p, b - a.q) < 1e-8;
}

vector_2d* intersection_segments(segment_2d a, segment_2d b, int* size) {
    line_2d line_a;
    line_a.p = a.p;
    line_a.q = a.q;
    line_a.a = angle(subtract(a.p, a.q));
    line_2d line_b;
    line_b.p = b.p;
    line_b.q = b.q;
    line_b.a = angle(subtract(b.p, b.q));
    vector_2d* i = (vector_2d*)malloc(sizeof(vector_2d));
    *size = 0;
    vector_2d* r = (vector_2d*)malloc(sizeof(vector_2d));
    if (i != NULL && r != NULL) {
        i = intersection(line_a, line_b);
        if (i->x != 0 || i->y != 0) {
            r = i;
            *size = 1;
        } else {
            r[0] = a.p;
            r[1] = a.q;
            r[2] = b.p;
            r[3] = b.q;
            *size = 4;
        }
    }
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    vector_2d* a = (vector_2d*)malloc(n * sizeof(vector_2d));
    int* index = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
        index[a[i].x][a[i].y] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].x > a[j].x) {
                vector_2d temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    char d[1000];
    scanf("%s", d);
    int d_len = strlen(d);
    for (int i = 0; i < d_len / 2; i++) {
        char temp = d[i];
        d[i] = d[d_len - i - 1];
        d[d_len - i - 1] = temp;
    }
    vector_2d* ans = (vector_2d*)malloc(n * sizeof(vector_2d));
    int ans_size = 0;
    ans[0] = a[0];
    for (int i = 0; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
    while (n > 0) {
        int td;
        if (d_len == 0) {
            td = 1;
        } else if (d[d_len - 1] == 'L') {
            td = 1;
        } else {
            td = -1;
        }
        if (d_len > 0) {
            d_len--;
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (cross_product(subtract(a[cur], ans[ans_size - 1]),
                              subtract(a[i], ans[ans_size - 1])) * td < 0) {
                cur = i;
            }
        }
        ans[ans_size] = a[cur];
        for (int i = cur; i < n; i++) {
            a[i] = a[i + 1];
        }
        n--;
        ans_size++;
    }
    int* aaa = (int*)malloc(ans_size * sizeof(int));
    for (int i = 0; i < ans_size; i++) {
        aaa[i] = index[ans[i].x][ans[i].y] + 1;
    }
    for (int i = 0; i < ans_size; i++) {
        printf("%d ", aaa[i]);
    }
    printf("\n");
    free(a);
    free(index);
    free(ans);
    free(aaa);
    return 0;
}
