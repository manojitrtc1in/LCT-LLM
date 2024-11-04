                                                                                                                                                                                                                                                                                              
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
using ll = long long;
using ld = long double;

struct Point
{
    ld x, y;
    Point(){}
    Point(ld _x, ld _y): x(_x), y(_y){}
    ld len() {
        return sqrt(x * x + y * y);
    }
};
 
Point operator +(const Point& a, const Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}


Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}


ld operator *(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}


ld operator ^(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}


const double Pi = acos(-1);


const int MAXN = 100228;


int n, k;
Point p[MAXN];


bool ok(double r) {
    vector<pair<double, int> > st;
    int add = 0;
    for (int i = 0; i < n; i++) {
        double f = p[i].len();
        if (f > 2 * r + 1e-9) {
            continue;
        }
        if (abs(p[i].x) < 1e-9 && abs(p[i].y) < 1e-9) {
            add++;
            continue;
        }
        Point q = p[i];
        swap(q.x, q.y);
        q.x *= -1;
        double fm = sqrt(q.x * q.x + q.y * q.y);
        q.x /= fm;
        q.y /= fm;
        double h = sqrt(r * r - (f / 2) * (f / 2));
        q.x *= h;
        q.y *= h;
        Point s = p[i];
        s.x /= 2;
        s.y /= 2;
        Point e = s + q;
        Point e1 = s - q;
      

        double l = atan2(e.y, e.x) + 2 * Pi;
        double rr = atan2(e1.y, e1.x) + 2 * Pi;
        while (l < 0) {
            l += 2 * Pi;
        }
        while (rr < 0) {
            rr += 2 * Pi;
        }
        while (l >= 2 * Pi) {
            l -= 2 * Pi;
        }
        while (rr >= 2 * Pi) {
            rr -= 2 * Pi;
        }
        if (l > rr) {
            swap(l, rr);
        }
      

        if (rr - l <= Pi + 1e-9) {
            st.pb(mp(l, 1));
            st.pb(mp(rr, -1));
        } else {
            st.pb(mp(0, 1));
            st.pb(mp(l, -1));
            st.pb(mp(rr, 1));
            st.pb(mp(2 * Pi, -1));
        }
    }
    sort(all(st));
    int cur = 0;
    int tm = 0;
    for (auto x: st) {
        cur += x.second;
        chkmax(tm, cur);
    }  
    return tm + add >= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }
    double l = 0.0;
    double r = 200228;
    for (int it = 0; it < 36; it++) {
        double mid = (l + r) / 2.0;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << l << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    int t = 1;
    

    while (t--) {
        solve();
    }
    return 0;
}
