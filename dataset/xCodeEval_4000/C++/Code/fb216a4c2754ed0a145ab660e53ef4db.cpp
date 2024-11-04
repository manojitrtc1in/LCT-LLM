#define ONLINE_JUDGE 1

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

typedef complex<double> Point;

vector<Point> ans;

bool in(const double &c, const double &a, const double &b) {
    return (min(a, b) - 1e-9 <= c && c <= max(a, b) + 1e-9);
}

bool on(const Point &p, const Point &a, const Point &b) {
    return (in(p.real(), a.real(), b.real()) && in(p.imag(), a.imag(), b.imag()));
}

void intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    double A1 = (a - b).imag(), B1 = (b - a).real(), C1 = (conj(a) * b).imag();
    double A2 = (c - d).imag(), B2 = (d - c).real(), C2 = (conj(c) * d).imag();
    if(abs(A1 * B2 - B1 * A2) <= 1e-9)
        return;
    double D = A1 * B2 - A2 * B1;
    double Dx = C2 * B1 - C1 * B2;
    double Dy = A2 * C1 - A1 * C2;
    Point p(Dx / D, Dy / D);
    if(on(p, a, b) && on(p, c, d))
        ans.push_back(p);
}

double cross(const Point &a, const Point &b) {
    return (conj(a) * b).imag();
}

bool cw(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a) < 0.0;
}

bool ccw(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a) > 0.0;
}

double area(const vector<Point> &v) {
    double res = 0.0;
    for(int i = 0;i < v.size();i++)
        res += cross(v[i], v[(i + 1) % v.size()]);
    return abs(res) / 2.0;
}

void solve() {
    double w, h, a;
    scanf("%lf %lf %lf", &w, &h, &a);
    a = a / 180.0 * acos(-1);
    Point rect1[4], rect2[4];
    rect1[0] = {w / 2.0, h / 2.0};
    rect1[1] = {w / 2.0, -h / 2.0};
    rect1[2] = {-w / 2.0, -h / 2.0};
    rect1[3] = {-w / 2.0, h / 2.0};
    for(int i = 0;i < 4;i++)
        rect2[i] = rect1[i] * exp(Point(0.0, a));
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            intersect(rect1[i], rect1[(i + 1) % 4], rect2[j], rect2[(j + 1) % 4]);
    sort(all(ans), [](const Point &p1, const Point &p2) {
        if(p1.real() == p2.real())
            return p1.imag() < p2.imag();
        return p1.real() < p2.real();
    });
    vector<Point> up, dw;
    up.push_back(ans[0]);
    dw.push_back(ans[0]);
    for(int i = 1;i < ans.size();i++) {
        if(i == ans.size() - 1 || cw(ans[0], ans[i], ans.back())) {
            while(up.size() >= 2 && !cw(up[up.size() - 2], up.back(), ans[i]))
                up.pop_back();
            up.push_back(ans[i]);
        }
        if(i == ans.size() - 1 || ccw(ans[0], ans[i], ans.back())) {
            while(dw.size() >= 2 && !ccw(dw[dw.size() - 2], dw.back(), ans[i]))
                dw.pop_back();
            dw.push_back(ans[i]);
        }
    }
    vector<Point> yopta = up;
    for(int i = dw.size() - 2;i > 0;i--)
        yopta.push_back(dw[i]);
    printf("%.9f", area(yopta));
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
