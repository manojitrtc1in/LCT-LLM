






























































































































































































#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }


struct P {
    long long x, y;

    P() : x(0), y(0) {}
    P(long long x, long long y) : x(x), y(y) {}

    P operator-() const {
        return P(-x, -y);
    }

    P operator-(const P &r) const {
        return P(x - r.x, y - r.y);
    }

    bool operator<(const P &r) const {
        return x != r.x ? x < r.x : y < r.y;
    }

};
ostream &operator<<(ostream &o, const P &v) {  o << "(" << v.x << ", " << v.y<< ")"; return o; }

long long cross(P a, P b) {
    return a.x * b.y - a.y * b.x;
}













const long long NIL = LLONG_MIN;
vector<P> upper_hull(vector<P> &ps) {
    if (ps.size() <= 1) return ps;
    vector<P> a(ps.size());
    int s = 0;
    for (auto p : ps) {
        if (p.x == NIL) continue;
        while (s >= 2 && cross(a[s - 2] - a[s - 1], p - a[s - 1]) <= 0) s--;
        a[s++] = p;
    }
    a.resize(s);
    return a;
}













long long maximum(vector<P> &hull, long long q) {
    if (hull.empty()) return NIL;
    long long pass = hull.size() - 1;
    long long fail = -1;

    while (pass - fail > 1) {
        long long mid = (pass + fail) / 2;
        if (hull[mid].x * q + hull[mid].y > hull[mid + 1].x * q + hull[mid + 1].y) {
            pass = mid;
        } else {
            fail = mid;
        }
    }

    return hull[pass].x * q + hull[pass].y;
}

int INSERT = 1;
int ERASE = 2;
int GET = 3;
int main() {
    

    int n; cin >> n;

    

    

    

    

    

    

    

    

    

    

    

    

    

    vector<long long> t(n), x(n), y(n);
    vector<pair<P, int>> ps(n, make_pair(P(NIL, NIL), -1));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t[i]);
        ps[i].second = i;
        if (t[i] == INSERT) {
            scanf("%lld %lld", &x[i], &y[i]);
            ps[i] = make_pair(P(x[i], y[i]), i);
        } else if (t[i] == ERASE) {
            scanf("%lld", &x[i]);
            x[i]--;
        } else { 

            scanf("%lld", &x[i]);
        }
    }

    

    sort(ps.begin(), ps.end());

    

    vector<bool> activated(n);

    

    const int B = 1000;

    for (int i = 0; i < n; i += B) {
        

        int R = min(n, i + B); 

        

        vector<bool> bucket(n);
        for (int j = i; j < R; j++) {
            if (t[j] == INSERT) {
                bucket[j] = true;
            } else if (t[j] == ERASE) {
                bucket[x[j]] = true;
            }
        }

        

        

        

        

        

        vector<int> curr;
        vector<P> prev;
        for (auto p : ps) {
            int j = p.second;
            if (j >= R) continue;
            if (t[j] == INSERT && activated[j]) { 

                if (bucket[j]) { 

                    curr.push_back(j);
                } else { 

                    prev.emplace_back(p.first);
                }
            } else if (j >= i && t[j] == INSERT) { 

                curr.push_back(j);
            }
        }

        

        auto prev_upper = upper_hull(prev);
        

        for (int j = i; j < R; j++) {
            if (t[j] == INSERT) {
                activated[j] = true;
            } else if (t[j] == ERASE) {
                activated[x[j]] = false;
            } else { 

                

                

                

                

                


                

                long long mx = NIL;
                mx = max(mx, maximum(prev_upper, x[j]));

                

                for (int l = 0; l < curr.size(); l++) {
                    int id = curr[l];
                    if (activated[id]) 
                        mx = max(mx, x[id] * x[j] + y[id]);
                }

                if (mx == NIL) {
                    puts("EMPTY SET");
                } else {
                    printf("%lld\n", mx);
                }
            }
        }
    }
}
