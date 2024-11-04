#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

const long long inf = 1e10;
const long long mod = 998244353;
const long long num = 1e9 + 7;

struct Point {
    static const double EPS;
    double x, y;

    Point(double a, double b) : x(a), y(b) {}

    int compareTo(Point p) const {
        if (fabs(x - p.x) > EPS)
            return x > p.x ? 1 : -1;
        if (fabs(y - p.y) > EPS)
            return y > p.y ? 1 : -1;
        return 0;
    }

    double dist(Point p) const {
        return sqrt(sq(x - p.x) + sq(y - p.y));
    }

    static double sq(double x) {
        return x * x;
    }

    // Other methods omitted for brevity...
};

const double Point::EPS = 1e-9;

struct Polygon {
    vector<Point> g;

    Polygon(vector<Point> o) : g(o) {}

    double perimeter() {
        double sum = 0.0;
        for (size_t i = 0; i < g.size() - 1; ++i)
            sum += g[i].dist(g[i + 1]);
        return sum;
    }

    // Other methods omitted for brevity...
};

struct Line {
    double a, b, c;

    Line(Point p, Point q) {
        if (fabs(p.x - q.x) < Point::EPS) {
            a = 1;
            b = 0;
            c = -p.x;
        } else {
            a = (p.y - q.y) / (q.x - p.x);
            b = 1.0;
            c = -(a * p.x + p.y);
        }
    }

    // Other methods omitted for brevity...
};

struct Scanner {
    string line;
    size_t index;

    Scanner() : index(0) {}

    void nextLine() {
        getline(cin, line);
        index = 0;
    }

    string next() {
        while (index < line.size() && line[index] == ' ') index++;
        size_t start = index;
        while (index < line.size() && line[index] != ' ') index++;
        return line.substr(start, index - start);
    }

    int nextInt() {
        return stoi(next());
    }

    // Other methods omitted for brevity...
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Scanner sc;
    int t;
    cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        unordered_map<int, int> hm;
        vector<int> occ(n + 1, 0);
        int id = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (hm.find(a[i]) == hm.end()) {
                hm[a[i]] = id++;
            }
        }

        for (int i = 0; i < n; i++)
            a[i] = hm[a[i]];

        int ans = 0;
        for (int i = 0; i < d; i++) {
            occ[a[i]]++;
            if (occ[a[i]] == 1)
                ans++;
        }

        int ansl = ans;
        for (int i = d; i < n; i++) {
            int ans1 = ansl;
            occ[a[i]]++;
            if (occ[a[i]] == 1)
                ans1++;
            occ[a[i - d]]--;
            if (occ[a[i - d]] == 0)
                ans1--;
            ans = min(ans, ans1);
            ansl = ans1;
        }
        cout << ans << '\n';
    }
    return 0;
}
