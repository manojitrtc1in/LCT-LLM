#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class FastIO {
public:
    FastIO(istream &is, ostream &os) : is(is), os(os) {}

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
        os.flush();
    }

    void append(const string &str) {
        os << str;
    }

private:
    istream &is;
    ostream &os;
};

class Geometry {
public:
    class Point2 {
    public:
        double x, y;

        Point2(double x, double y) : x(x), y(y) {}

        Point2 operator-(const Point2 &other) const {
            return Point2(x - other.x, y - other.y);
        }
    };

    static double cross(const Point2 &a, const Point2 &b) {
        return a.x * b.y - a.y * b.x;
    }
};

class Task {
public:
    Task(FastIO &io) : io(io) {}

    void run() {
        solve();
    }

private:
    FastIO &io;

    void solve() {
        int n = io.readInt();
        vector<array<int, 4>> points(n);
        for (int i = 0; i < n; i++) {
            points[i][0] = io.readInt();
            points[i][1] = io.readInt();
            points[i][3] = i + 1;
        }

        auto last = points[0];
        for (const auto &pt : points) {
            if (pt[0] == last[0]) {
                if (pt[1] < last[1]) {
                    last = pt;
                }
            } else if (pt[0] > last[0]) {
                last = pt;
            }
        }

        last[2] = 1;
        io.append(to_string(last[3]) + " ");
        for (int i = 0; i < n - 2; i++) {
            char c = io.readChar();
            auto cmp = [this, &last, c](const array<int, 4> &a, const array<int, 4> &b) {
                return (c == 'L' ? -1 : 1) * (Geometry::cross(Point2(a[0] - last[0], a[1] - last[1]), Point2(b[0] - last[0], b[1] - last[1])) < 0);
            };

            array<int, 4> choose = {-1, -1, -1, -1};
            for (const auto &pt : points) {
                if (pt[2] == 1) continue;
                if (choose[2] == -1 || cmp(pt, choose) < 0) {
                    choose = pt;
                }
            }
            last = choose;
            last[2] = 1;
            io.append(to_string(last[3]) + " ");
        }

        for (const auto &pt : points) {
            if (pt[2] == 1) continue;
            io.append(to_string(pt[3]) + " ");
        }
    }
};

int main() {
    bool local = getenv("ONLINE_JUDGE") == nullptr;
    FastIO io(local ? ifstream("D:\\DATABASE\\TESTCASE\\Code.in") : cin, cout);

    Task task(io);
    task.run();
    io.flush();

    return 0;
}
