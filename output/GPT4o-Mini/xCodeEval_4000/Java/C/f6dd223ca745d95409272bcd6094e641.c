#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 100000
#define MOD 1000000007
#define INF 100000000

typedef struct {
    int x, y, id, used;
} Point;

Point points[MAX_POINTS];
int n;

void readInt(int *val) {
    scanf("%d", val);
}

char readChar() {
    char c;
    scanf(" %c", &c);
    return c;
}

long long cross(int x1, int y1, int x2, int y2) {
    return (long long)x1 * y2 - (long long)y1 * x2;
}

void solve() {
    readInt(&n);
    for (int i = 0; i < n; i++) {
        readInt(&points[i].x);
        readInt(&points[i].y);
        points[i].id = i + 1;
        points[i].used = 0;
    }

    Point *last = &points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x > last->x || (points[i].x == last->x && points[i].y < last->y)) {
            last = &points[i];
        }
    }

    last->used = 1;
    printf("%d ", last->id);

    for (int i = 0; i < n - 2; i++) {
        char c = readChar();
        Point *choose = NULL;

        for (int j = 0; j < n; j++) {
            if (points[j].used) continue;

            if (choose == NULL || (c == 'L' ? 
                cross(points[j].x - last->x, points[j].y - last->y, choose->x - last->x, choose->y - last->y) > 0 :
                cross(points[j].x - last->x, points[j].y - last->y, choose->x - last->x, choose->y - last->y) < 0)) {
                choose = &points[j];
            }
        }

        last = choose;
        last->used = 1;
        printf("%d ", last->id);
    }

    for (int i = 0; i < n; i++) {
        if (!points[i].used) {
            printf("%d ", points[i].id);
        }
    }
}

int main() {
    solve();
    return 0;
}
