#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class Geometry {
public:
    class Point2 {
    public:
        double x, y;

        Point2(double x, double y) : x(x), y(y) {}

        Point2 add(Point2 other) {
            return Point2(x + other.x, y + other.y);
        }

        Point2 sub(Point2 other) {
            return Point2(x - other.x, y - other.y);
        }

        friend ostream& operator<<(ostream& os, const Point2& p) {
            return os << "(" << p.x << "," << p.y << ")";
        }
    };

    class Line2 {
    public:
        Point2 begin, end;

        Line2(Point2 begin, Point2 end) : begin(begin), end(end) {}

        Point2 getVector() {
            return end.sub(begin);
        }

        Point2 getPointAt(double alpha) {
            return Point2((1 - alpha) * begin.x + alpha * end.x, (1 - alpha) * begin.y + alpha * end.y);
        }

        friend ostream& operator<<(ostream& os, const Line2& line) {
            return os << line.begin << "->" << line.end;
        }
    };

    static long long cross(int x1, int y1, int x2, int y2) {
        return (long long)x1 * y2 - (long long)y1 * x2;
    }

    static double cross(double x1, double y1, double x2, double y2) {
        return x1 * y2 - y1 * x2;
    }

    static double cross(Point2 a, Point2 b) {
        return a.x * b.y - a.y * b.x;
    }

    static double distance2(Point2 p) {
        return p.x * p.x + p.y * p.y;
    }

    static double distance(Point2 p) {
        return sqrt(distance2(p));
    }

    static Point2 lineIntersection(Line2 s1, Line2 s2, double prec) {
        double m11 = s1.end.x - s1.begin.x;
        double m01 = s2.end.x - s2.begin.x;
        double m10 = s1.begin.y - s1.end.y;
        double m00 = s2.begin.y - s2.end.y;

        double div = m00 * m11 - m01 * m10;
        if (fabs(div) < prec) {
            return Point2(0, 0); // No intersection
        }

        double v0 = (s2.begin.x - s1.begin.x) / div;
        double v1 = (s2.begin.y - s1.begin.y) / div;

        double alpha = m00 * v0 + m01 * v1;

        return s1.getPointAt(alpha);
    }
};

class FastIO {
public:
    stringstream cache;
    istream& is;
    ostream& os;

    FastIO(istream& is, ostream& os) : is(is), os(os) {}

    int readInt() {
        int val;
        is >> val;
        return val;
    }

    char readChar() {
        char c;
        is >> c;
        return c;
    }

    void flush() {
        os << cache.str();
        os.flush();
        cache.str("");
    }
};

class Task {
    FastIO& io;

public:
    Task(FastIO& io) : io(io) {}

    void solve() {
        int n = io.readInt();
        vector<vector<int>> points(n, vector<int>(4));
        for (int i = 0; i < n; i++) {
            points[i][0] = io.readInt();
            points[i][1] = io.readInt();
            points[i][3] = i + 1;
        }

        vector<int> last = points[0];
        for (const auto& pt : points) {
            if (pt[0] == last[0]) {
                if (pt[1] < last[1]) {
                    last = pt;
                }
            } else if (pt[0] > last[0]) {
                last = pt;
            }
        }

        last[2] = 1;
        io.cache << last[3] << ' ';
        for (int i = 0; i < n - 2; i++) {
            char c = io.readChar();
            auto cmp = [c, last](const vector<int>& a, const vector<int>& b) {
                long long crossProduct = Geometry::cross(a[0] - last[0], a[1] - last[1], b[0] - last[0], b[1] - last[1]);
                return (c == 'L') ? -crossProduct : crossProduct;
            };

            vector<int>* choose = nullptr;
            for (auto& pt : points) {
                if (pt[2] == 1) continue;
                if (choose == nullptr || cmp(pt, *choose) < 0) {
                    choose = &pt;
                }
            }
            last = *choose;
            last[2] = 1;
            io.cache << last[3] << ' ';
        }

        for (const auto& pt : points) {
            if (pt[2] == 1) continue;
            io.cache << pt[3] << ' ';
        }
    }
};

int main() {
    bool local = getenv("ONLINE_JUDGE") == nullptr;
    FastIO io(local ? ifstream("D:\\DATABASE\\TESTCASE\\Code.in") : cin, cout);
    Task task(io);
    task.solve();
    io.flush();
    return 0;
}
