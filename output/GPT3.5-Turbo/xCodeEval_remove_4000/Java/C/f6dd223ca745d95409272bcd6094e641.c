#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point2;

typedef struct {
    Point2 begin, end;
} Line2;

int compare(double a, double b, double prec) {
    return abs(a - b) < prec ? 0 : a < b ? -1 : 1;
}

double cross(Point2 a, Point2 b) {
    return a.x * b.y - a.y * b.x;
}

Point2 id0(Line2 line, double alpha) {
    Point2 result;
    result.x = (1 - alpha) * line.begin.x + alpha * line.end.x;
    result.y = (1 - alpha) * line.begin.y + alpha * line.end.y;
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int points[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &points[i][j]);
        }
        points[i][3] = i + 1;
    }

    int* last = points[0];
    for (int i = 0; i < n; i++) {
        if (points[i][0] == last[0]) {
            if (points[i][1] < last[1]) {
                last = points[i];
            }
        } else if (points[i][0] > last[0]) {
            last = points[i];
        }
    }

    last[2] = 1;
    printf("%d ", last[3]);
    for (int i = 0; i < n - 2; i++) {
        char c;
        scanf(" %c", &c);
        int* choose = NULL;
        if (c == 'L') {
            for (int j = 0; j < n; j++) {
                if (points[j][2] == 1) {
                    continue;
                }
                if (choose == NULL || compare(cross(points[j][0] - last[0], points[j][1] - last[1], choose[0] - last[0], choose[1] - last[1]), 0, 1e-9) < 0) {
                    choose = points[j];
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (points[j][2] == 1) {
                    continue;
                }
                if (choose == NULL || compare(cross(points[j][0] - last[0], points[j][1] - last[1], choose[0] - last[0], choose[1] - last[1]), 0, 1e-9) > 0) {
                    choose = points[j];
                }
            }
        }
        last = choose;
        last[2] = 1;
        printf("%d ", last[3]);
    }

    for (int i = 0; i < n; i++) {
        if (points[i][2] == 1) {
            continue;
        }
        printf("%d ", points[i][3]);
    }

    return 0;
}
