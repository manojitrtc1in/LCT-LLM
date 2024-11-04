#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using ldb = long double;
using pa = pair < ll, ll >;
using vec = vector < ll >;
 
template < typename T > using index_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

#define pb push_back
#define po pop_back
#define mp make_pair
#define mt make_tuple
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))
#define F  first
#define S  second
#define f(i,x,n) for(ll i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
#define str string
#define edl "\n"
#define int ll
#define add insert
#define tm (tl+tr)/2
#define child 2*v
#define ceils(s,n) (s+n-1)/n
#define cot continue
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MOD = 1e9 + 7,  N = 1e5 + 10;
const ll LINF = LLONG_MAX;
ll seg[4*N];
ll a[N],n,query;
typedef long double f80;
f80 INF = 1e100;
f80 EPS = 1e-7;
#define pb push_back
#define fr(a,b,c) for(int a=b; a<=c; a++)
const f80 PI = acos(-1);
struct PT {
    f80 x, y;
    PT() {}
    PT(f80 x, f80 y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (f80 c) const { return PT(x * c, y * c); }
    PT operator / (f80 c) const { return PT(x / c, y / c); }
};
f80 dot(PT p, PT q)  { return p.x * q.x + p.y * q.y; }
f80 dist2(PT p, PT q)   { return dot(p - q, p - q); }
f80 dist(PT p, PT q)    { return sqrtl(dist2(p, q)); }
f80 cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }
f80 abs2(PT a)  { return a.x * a.x + a.y * a.y; }
f80 abs(PT a)   { return sqrtl(abs2(a)); }
ostream &operator<<(ostream &os, const PT &p) {
    return os << "(" << p.x << "," << p.y << ")";
}


PT RotateCCW90(PT p)    { return PT(-p.y, p.x); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }
PT RotateCCW(PT p, f80 t) {
    return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}




PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}


PT ProjectPointSegment(PT a, PT b, PT c) {
    f80 r = dot(b - a, b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a ) * r;
}


f80 DistancePointSegment(PT a, PT b, PT c) {
    return sqrtl(dist2(c, ProjectPointSegment(a, b, c)));
}


f80 DistancePointPlane(f80 x, f80 y, f80 z, f80 a, f80 b, f80 c, f80 d)
{ return fabs(a * x + b * y + c * z - d) / sqrtl(a * a + b * b + c * c); }


bool LinesParallel(PT a, PT b, PT c, PT d)
{ return fabs(cross(b - a, c - d)) < EPS; }
bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS
            && fabs(cross(c - d, c - a)) < EPS;
}




bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
                dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
            return 0;
        return 1;
    }
    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
    return 1;
}








PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b * cross(c, d) / cross(b, d);
}


PT ComputeCircleCenter(PT a, PT b, PT c) {
    b = (a + b) / 2;
    c = (a + c) / 2;
    return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
}














bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    fr(i, 0, p.size() - 1) {
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}


bool PointOnPolygon(const vector<PT> &p, PT q) {
    fr(i, 0, p.size() - 1)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
        return 1;
    return 0;
}




vector<PT> CLIntersection(PT a, PT b, PT c, f80 r) {
    vector<PT> ret;
    b = b - a;
    a = a - c;
    f80 A = dot(b, b);
    f80 B = dot(a, b);
    f80 C = dot(a, a) - r * r;
    f80 D = B * B - A * C;
    if (D < -EPS) return ret;
    ret.pb(c + a + b * (-B + sqrtl(D + EPS)) / A);
    if (D > EPS)
        ret.pb(c + a + b * (-B - sqrtl(D)) / A);
    return ret;
}




vector<PT> CCIntersection(PT a, PT b, f80 r, f80 R) {
    vector<PT> ret;
    f80 d = sqrtl(dist2(a, b));
    if (d > r + R || d + min(r, R) < max(r, R)) return ret;
    f80 x = (d * d - R * R + r * r) / (2 * d);
    f80 y = sqrtl(r * r - x * x);
    PT v = (b - a) / d;
    ret.pb(a + v * x + RotateCCW90(v)*y);
    if (y > 0)
        ret.pb(a + v * x - RotateCCW90(v)*y);
    return ret;
}








f80 ComputeSignedArea(const vector<PT> &p) {
    f80 area = 0;
    fr(i, 0, p.size() - 1) {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area / 2.0;
}
f80 ComputeArea(const vector<PT> &p) {
    return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> &p) {
    PT c(0, 0);
    f80 scale = 6.0 * ComputeSignedArea(p);
    fr(i, 0, p.size() - 1) {
        int j = (i + 1) % p.size();
        c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
    }
    return c / scale;
}


bool IsSimple(const vector<PT> &p) {
    fr(i, 0, p.size() - 1) {
        fr(k, i + 1, p.size() - 1) {
            int j = (i + 1) % p.size();
            int l = (k + 1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return 0;
        }
    }
    return 1;
}
bool RayOnPoint(PT a, PT v, PT b) { 

    b = b - a;
    if (abs(b.x * v.y - b.y * v.x) < EPS) { 

        if (b.x * v.x >= -EPS && b.y * v.y >= -EPS) 

            return 1;
        return 0;
    }
    return 0;
}
int sign(PT a, PT b, PT c) { return (cross(b - a, c - b) < 0 ? -1 : 1 ); }
f80 ArcArea(PT a, PT b, PT c, f80 r) {
    f80 cosa = dot(a - c, b - c) / (abs(a - c) * abs(b - c));
    f80 ang = acos(cosa);
    if (ang > 2 * PI) ang = 2 * PI - ang;
    return 0.5 * r * r * ang;
}
f80 TCArea(PT a1, PT a2, PT c, f80 r) {
    f80 ans = 0;
    f80 d1 = dist2(a1, c), d2 = dist2(a2, c);
    if (d1 > d2) swap(d1, d2), swap(a1, a2);
    if (d2 <= r * r) {
        ans = 0.5 * abs(cross(a1 - c, a2 - c));
    }
    else if (d1 <= r * r) {
        auto vv = CLIntersection(a1, a2, c, r);
        PT C = vv[0];
        if (vv.size() > 1 && dot(vv[1] - a1, vv[1] - a2) < 0)
            C = vv[1];
        vv = CLIntersection(a2, c, c, r);
        PT D = vv[0];
        if (vv.size() > 1 && dot(vv[1] - a2, vv[1] - c) < 0)
            D = vv[1];
        ans = ArcArea(C, D, c, r) + 0.5 * abs(cross(C - c, a1 - c));
    }
    else {
        auto vv = CLIntersection(a1, a2, c, r);
        if (vv.size() <= 1 || dot(a1 - vv[0], a2 - vv[0]) > 0) {
            ans = ArcArea(a1, a2, c, r);
        }
        else {
            if (dist2(a1, vv[1]) < dist2(a1, vv[0]))
                swap(vv[0], vv[1]);
            ans = ArcArea(a1, vv[0], c, r) + ArcArea(a2, vv[1], c, r) + 0.5 * abs(cross(vv[0] - c, vv[1] - c));
        }
    }
    return abs(ans);
}
f80 PolyCircArea(vector<PT> &a, PT c, f80 r) { 

    

    int n = a.size();
    if (n <= 2) return 0;
    f80 ans = 0;
    fr(i, 0, n - 1)
    ans += TCArea(a[i], a[(i + 1) % n], c, r) * sign(c, a[i], a[(i + 1) % n]);
    return abs(ans);
}
struct line {
    f80 a, b, c;
    line() {}
    line(f80 A, f80 B, f80 C) {
        a = A, b = B, c = C;
    }
};
bool areParallel(line l1, line l2) {
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}
bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}
struct Circle : PT {
    f80 r;
    Circle() {}
    Circle(PT c, f80 r) : PT(c.x, c.y),
        r(r) {}
    bool strictContains(PT p) {
        return dist2((*this), p) < r * r;
    }
    bool onBorder(PT p) {
        return abs(dist2((*this), p) - r * r) < EPS;
    }
    bool contains(PT p) {
        return strictContains(p) || onBorder(p);
    }
};
#define sqr(x) ((x) * (x))




void tangents(PT c, f80 r1, f80 r2,
            vector<line> & ans) {
    f80 r = r2 - r1;
    f80 z = sqr(c.x) + sqr(c.y);
    f80 d = z - sqr(r);
    if (d < -EPS) return;
    d = sqrt(fabs(d));
    line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
    ans.push_back(l);
}


vector<line> tangents(Circle a, Circle b) { 

    vector<line> ans; ans.clear();
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2)
            tangents(b - a, a.r * i, b.r * j, ans);
    for (int i = 0; i < ans.size(); ++i)
        ans[i].c -= ans[i].a * a.x + ans[i].b *
                    a.y;
    vector<line> ret;
    for (int i = 0; i < (int) ans.size(); ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j)
            if (areSame(ret[j], ans[i])) {
                ok = false;
                break;
            }
        if (ok) ret.push_back(ans[i]);
    }
    return ret;
}
void solve(string a, string b) {
    string ans = "";
    while (a.size() != b.size()) {
        if (b.size() > a.size()) {
            a = '0' + a;
        } else {
            b = '0' + b;
        }
    }
    int sz = a.size(), car = 0;
    for (int i = sz - 1; i >= 0; --i) {
        int temp = a[i] + b[i] - 2 * '0' + car;
        car = temp / 10;
        ans += char(temp % 10 + '0');
    }
    if (car) {
        ans += char(car + '0');
    }
    reverse(all(ans));
}
#ifndef ONLINE_JUDGE
  #include "Debug.h"
#else
  #define debug(...) 42
#endif
void solution();
int dp[201][201][201];
vector<int>R,G,B;
int r,g,b;
int ma;
int32_t main() {    
    fast();
    solution();
    
    cerr << "\nTime taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}

int dfs(int rr,int gg,int bb){
    if(rr > r or gg > g or bb > b){
        return 0;
    }
    if(dp[rr][gg][bb] != -1){
        return dp[rr][gg][bb];
    }
    int &ans = dp[rr][gg][bb];
    ans = dfs(rr+1,gg+1,bb+1);
    ans = max(ans,R[rr]*G[gg] + dfs(rr+1,gg+1,bb));
    ans = max(ans,R[rr]*B[bb] + dfs(rr+1,gg,bb+1));
    ans = max(ans,B[bb]*G[gg] + dfs(rr,gg+1,bb+1));
    ans = max(ans,dfs(rr+1,gg,bb));
    ans = max(ans,dfs(rr+1,gg,bb+1));
    ans = max(ans,dfs(rr,gg,bb+1));
    ans = max(ans,dfs(rr,gg+1,bb));
    ans = max(ans,dfs(rr+1,gg+1,bb));
    ans = max(ans,dfs(rr,gg+1,bb+1));
    debug(R[rr],G[gg],B[bb]);
    debug(ans);
    return ans;
}
void solution(){
    cin >> r >> g >> b;
    R.resize(r+1);
    G.resize(g+1);
    B.resize(b+1);
    f(i,0,r){
        cin >> R[i];
    }
    f(i,0,g){
        cin >> G[i];
    }
    f(i,0,b){
        cin >> B[i];
    }
    sort(R.rbegin(),R.rend());
    sort(G.rbegin(),G.rend());
    sort(B.rbegin(),B.rend());
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0);
}



