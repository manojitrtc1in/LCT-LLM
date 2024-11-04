#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p;
    Point q;
    double angle;
} Line;

double getAngle(Point p, Point q) {
    return atan2((double)(q.x - p.x), (double)(q.y - p.y));
}

int compareLines(const void* a, const void* b) {
    Line* lineA = (Line*)a;
    Line* lineB = (Line*)b;
    return (lineA->angle > lineB->angle) - (lineA->angle < lineB->angle);
}

int main() {
    int n;
    scanf("%d", &n);
    Point* points = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    char* d = (char*)malloc(n * sizeof(char));
    scanf("%s", d);

    Line* lines = (Line*)malloc(n * sizeof(Line));
    for (int i = 0; i < n; i++) {
        lines[i].p = points[i];
        lines[i].q = points[i];
        lines[i].angle = getAngle(points[i], points[i]);
    }

    qsort(lines, n, sizeof(Line), compareLines);

    Point* ans = (Point*)malloc(n * sizeof(Point));
    int ansIndex = 0;
    ans[ansIndex++] = lines[0].p;
    for (int i = 1; i < n; i++) {
        int td;
        if (d[i-1] == 'L') {
            td = 1;
        } else {
            td = -1;
        }
        int cur = 0;
        for (int j = 1; j < n; j++) {
            if (crossProduct(lines[cur].p, ans[ansIndex-1], lines[j].p, ans[ansIndex-1]) * td < 0) {
                cur = j;
            }
        }
        ans[ansIndex++] = lines[cur].p;
        lines[cur].p = lines[cur].q;
    }

    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i].x == points[j].x && ans[i].y == points[j].y) {
                result[i] = j + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(points);
    free(d);
    free(lines);
    free(ans);
    free(result);

    return 0;
}
