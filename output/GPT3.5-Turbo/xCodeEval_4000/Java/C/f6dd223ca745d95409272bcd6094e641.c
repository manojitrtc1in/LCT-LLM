#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x, y;
} Point2;

typedef struct {
    Point2 begin, end;
} Line2;

int compare(double a, double b, double prec) {
    return fabs(a - b) < prec ? 0 : a < b ? -1 : 1;
}

long long cross(int x1, int y1, int x2, int y2) {
    return (long long)x1 * y2 - (long long)y1 * x2;
}

double cross_double(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

double cross_point2(Point2 a, Point2 b) {
    return a.x * b.y - a.y * b.x;
}

int on_section(Point2 p, Line2 section, double precision) {
    return fabs(cross_point2(point2_sub(p, section.begin), line2_get_vector(section))) < precision
        && p.x >= fmin(section.begin.x, section.end.x) - precision && p.x <= fmax(section.begin.x, section.end.x) + precision;
}

double distance2(Point2 p) {
    return p.x * p.x + p.y * p.y;
}

double distance(Point2 p) {
    return sqrt(distance2(p));
}

Point2 line_intersection(Line2 s1, Line2 s2, double prec) {
    double m11 = s1.end.x - s1.begin.x;
    double m01 = s2.end.x - s2.begin.x;
    double m10 = s1.begin.y - s1.end.y;
    double m00 = s2.begin.y - s2.end.y;

    double div = m00 * m11 - m01 * m10;
    if (fabs(div) < prec) {
        Point2 null_point = {0, 0};
        return null_point;
    }

    double v0 = (s2.begin.x - s1.begin.x) / div;
    double v1 = (s2.begin.y - s1.begin.y) / div;

    double alpha = m00 * v0 + m01 * v1;

    return line2_get_point_at(s1, alpha);
}

Point2 section_intersection(Line2 s1, Line2 s2, double prec) {
    double m11 = s1.end.x - s1.begin.x;
    double m01 = s2.end.x - s2.begin.x;
    double m10 = s1.begin.y - s1.end.y;
    double m00 = s2.begin.y - s2.end.y;

    double div = m00 * m11 - m01 * m10;
    if (fabs(div) < prec) {
        Point2 null_point = {0, 0};
        return null_point;
    }

    double v0 = (s2.begin.x - s1.begin.x) / div;
    double v1 = (s2.begin.y - s1.begin.y) / div;

    double alpha = m00 * v0 + m01 * v1;
    double beta = m10 * v0 + m11 * v1;

    if (-prec <= alpha && alpha <= 1 + prec && -prec <= beta && beta <= 1 + prec) {
        return line2_get_point_at(s1, alpha);
    }
    Point2 null_point = {0, 0};
    return null_point;
}

Point2 point2_add(Point2 a, Point2 b) {
    Point2 result = {a.x + b.x, a.y + b.y};
    return result;
}

Point2 point2_sub(Point2 a, Point2 b) {
    Point2 result = {a.x - b.x, a.y - b.y};
    return result;
}

Point2 line2_get_vector(Line2 line) {
    Point2 result = {line.end.x - line.begin.x, line.end.y - line.begin.y};
    return result;
}

Point2 line2_get_point_at(Line2 line, double alpha) {
    Point2 result = {(1 - alpha) * line.begin.x + alpha * line.end.x, (1 - alpha) * line.begin.y + alpha * line.end.y};
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    Point2 points[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &points[i][j].x);
            scanf("%lf", &points[i][j].y);
        }
        points[i][3].x = i + 1;
        points[i][3].y = i + 1;
    }

    Point2 last = points[0];
    for (int i = 0; i < n; i++) {
        if (points[i][0].x == last.x) {
            if (points[i][1].y < last.y) {
                last = points[i];
            }
        } else if (points[i][0].x > last.x) {
            last = points[i];
        }
    }

    last.z = 1;
    printf("%lf ", last.w);
    for (int i = 0; i < n - 2; i++) {
        char c;
        scanf(" %c", &c);
        int cmp;
        Point2 final_last = last;
        Point2* choose = NULL;
        if (c == 'L') {
            cmp = -cross_double(a[0] - final_last[0], a[1] - final_last[1], b[0] - final_last[0], b[1] - final_last[1]);
        } else {
            cmp = cross_double(a[0] - final_last[0], a[1] - final_last[1], b[0] - final_last[0], b[1] - final_last[1]);
        }
        for (int i = 0; i < n; i++) {
            if (points[i][2] == 1) {
                continue;
            }
            if (choose == NULL || cmp.compare(pt, choose) < 0) {
                choose = pt;
            }
        }
        last = choose;
        last.z = 1;
        printf("%lf ", last.w);
    }

    for (int i = 0; i < n; i++) {
        if (points[i][2] == 1) {
            continue;
        }
        printf("%lf ", points[i][3].w);
    }

    return 0;
}
