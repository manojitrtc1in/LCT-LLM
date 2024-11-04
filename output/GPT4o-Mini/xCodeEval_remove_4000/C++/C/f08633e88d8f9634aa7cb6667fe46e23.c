#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    ll x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointArray;

PointArray create_point_array(int size) {
    PointArray arr;
    arr.points = (Point *)malloc(size * sizeof(Point));
    arr.size = size;
    return arr;
}

void free_point_array(PointArray *arr) {
    free(arr->points);
    arr->size = 0;
}

double cross_product(Point a, Point b) {
    return a.x * b.y - b.x * a.y;
}

double angle(Point a) {
    return atan2((double)a.x, (double)a.y);
}

bool contains(Point a, Point b, Point c) {
    return fabs(cross_product((Point){b.x - a.x, b.y - a.y}, (Point){c.x - a.x, c.y - a.y})) < 1e-8 &&
           (b.x - a.x) * (c.x - b.x) < 1e-8;
}

void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    PointArray a = create_point_array(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a.points[i].x, &a.points[i].y);
    }

    char d[100];
    scanf("%s", d);
    reverse_string(d);

    PointArray ans = create_point_array(n);
    ans.points[0] = a.points[0];
    int ans_size = 1;

    for (int i = 1; i < n; i++) {
        a.points[i - 1] = a.points[i];
    }
    n--;

    while (n > 0) {
        int td = (d[ans_size - 1] == 'L' || ans_size == 1) ? 1 : -1;
        if (ans_size > 0) {
            ans_size--;
        }

        int cur = 0;
        for (int i = 1; i < n; i++) {
            if (cross_product((Point){a.points[cur].x - ans.points[ans_size - 1].x, a.points[cur].y - ans.points[ans_size - 1].y},
                              (Point){a.points[i].x - ans.points[ans_size - 1].x, a.points[i].y - ans.points[ans_size - 1].y}) * td < 0) {
                cur = i;
            }
        }

        ans.points[ans_size++] = a.points[cur];
        for (int i = cur; i < n - 1; i++) {
            a.points[i] = a.points[i + 1];
        }
        n--;
    }

    for (int i = 0; i < ans_size; i++) {
        printf("%lld %lld\n", ans.points[i].x, ans.points[i].y);
    }

    free_point_array(&a);
    free_point_array(&ans);
    return 0;
}
