#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point2 {
    double x, y;

    Point2(double x, double y) : x(x), y(y) {}

    Point2 add(Point2 other) {
        return Point2(x + other.x, y + other.y);
    }

    Point2 sub(Point2 other) {
        return Point2(x - other.x, y - other.y);
    }

    string toString() {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};

struct Line2 {
    Point2 begin, end;

    Line2(Point2 begin, Point2 end) : begin(begin), end(end) {}

    Point2 getVector() {
        return end.sub(begin);
    }

    Point2 getPointAt(double alpha) {
        return Point2((1 - alpha) * begin.x + alpha * end.x, (1 - alpha) * begin.y + alpha * end.y);
    }

    string toString() {
        return begin.toString() + "->" + end.toString();
    }
};

int compare(double a, double b, double prec) {
    return abs(a - b) < prec ? 0 : a < b ? -1 : 1;
}

long cross(int x1, int y1, int x2, int y2) {
    return (long) x1 * y2 - (long) y1 * x2;
}

double cross(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

double cross(Point2 a, Point2 b) {
    return a.x * b.y - a.y * b.x;
}

bool onSection(Point2 p, Line2 section, double precision) {
    return abs(cross(p.sub(section.begin), section.getVector())) < precision
           && p.x >= min(section.begin.x, section.end.x) - precision && p.x <= max(section.begin.x, section.end.x) + precision;
}

double distance2(Point2 p) {
    return p.x * p.x + p.y * p.y;
}

double distance(Point2 p) {
    return sqrt(distance2(p));
}

Point2 lineIntersection(Line2 s1, Line2 s2, double prec) {
    double m11 = s1.end.x - s1.begin.x;
    double m01 = s2.end.x - s2.begin.x;
    double m10 = s1.begin.y - s1.end.y;
    double m00 = s2.begin.y - s2.end.y;

    double div = m00 * m11 - m01 * m10;
    if (abs(div) < prec) {
        return Point2(0, 0);
    }

    double v0 = (s2.begin.x - s1.begin.x) / div;
    double v1 = (s2.begin.y - s1.begin.y) / div;

    double alpha = m00 * v0 + m01 * v1;

    return s1.getPointAt(alpha);
}

Point2 sectionIntersection(Line2 s1, Line2 s2, double prec) {
    double m11 = s1.end.x - s1.begin.x;
    double m01 = s2.end.x - s2.begin.x;
    double m10 = s1.begin.y - s1.end.y;
    double m00 = s2.begin.y - s2.end.y;

    double div = m00 * m11 - m01 * m10;
    if (abs(div) < prec) {
        return Point2(0, 0);
    }

    double v0 = (s2.begin.x - s1.begin.x) / div;
    double v1 = (s2.begin.y - s1.begin.y) / div;

    double alpha = m00 * v0 + m01 * v1;
    double beta = m10 * v0 + m11 * v1;

    if (-prec <= alpha && alpha <= 1 + prec && -prec <= beta && beta <= 1 + prec) {
        return s1.getPointAt(alpha);
    }
    return Point2(0, 0);
}

class CF1158D {
public:
    static void solve() {
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(4));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> points[i][j];
            }
            points[i][3] = i + 1;
        }

        vector<int> last = points[0];
        for (auto pt : points) {
            if (pt[0] == last[0]) {
                if (pt[1] < last[1]) {
                    last = pt;
                }
            } else if (pt[0] > last[0]) {
                last = pt;
            }
        }

        last[2] = 1;
        cout << last[3] << " ";
        for (int i = 0; i < n - 2; i++) {
            char c;
            cin >> c;
            auto cmp = [&](vector<int>& a, vector<int>& b) {
                return -1 * sign(cross(a[0] - last[0], a[1] - last[1], b[0] - last[0], b[1] - last[1]));
            };
            vector<int> choose;
            for (auto pt : points) {
                if (pt[2] == 1) {
                    continue;
                }
                if (choose.empty() || cmp(pt, choose) < 0) {
                    choose = pt;
                }
            }
            last = choose;
            last[2] = 1;
            cout << last[3] << " ";
        }

        for (auto pt : points) {
            if (pt[2] == 1) {
                continue;
            }
            cout << pt[3] << " ";
        }
    }
};

int main() {
    CF1158D::solve();
    return 0;
}
