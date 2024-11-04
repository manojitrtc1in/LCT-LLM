#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <cassert>
#include <climits>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define trav(a,x) for(auto &a:x)
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debug4(x, y, z, w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl;
#define debug5(x, y, z, w, u) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << endl;
#define debug6(x, y, z, w, u, v) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << endl;
#define debug7(x, y, z, w, u, v, t) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << endl;
#define debug8(x, y, z, w, u, v, t, s) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << endl;
#define debug9(x, y, z, w, u, v, t, s, r) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << endl;
#define debug10(x, y, z, w, u, v, t, s, r, q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << endl;
#define debug11(x, y, z, w, u, v, t, s, r, q, p) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << endl;
#define debug12(x, y, z, w, u, v, t, s, r, q, p, o) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << endl;
#define debug13(x, y, z, w, u, v, t, s, r, q, p, o, a) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << endl;
#define debug14(x, y, z, w, u, v, t, s, r, q, p, o, a, b) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << endl;
#define debug15(x, y, z, w, u, v, t, s, r, q, p, o, a, b, c) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << endl;
#define debug16(x, y, z, w, u, v, t, s, r, q, p, o, a, b, c, d) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << endl;
#define debug17(x, y, z, w, u, v, t, s, r, q, p, o, a, b, c, d, e) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << endl;
#define debug18(x, y, z, w, u, v, t, s, r, q, p, o, a, b, c, d, e, f) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << endl;
#define debug19(x, y, z, w, u, v, t, s, r, q, p, o, a, b, c, d, e, f, g) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << ", " << #g << " = " << g << endl;
#define debug20(x, y, z, w, u, v, t, s, r, q, p, o, a, b, c, d, e, f, g, h) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << ", " << #u << " = " << u << ", " << #v << " = " << v << ", " << #t << " = " << t << ", " << #s << " = " << s << ", " << #r << " = " << r << ", " << #q << " = " << q << ", " << #p << " = " << p << ", " << #o << " = " << o << ", " << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << ", " << #g << " = " << g << ", " << #h << " = " << h << endl;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int gigamod = 1e9 + 7;
const int inf = 1e9 + 5;
const ll linf = 1e18 + 5;

int t = 1;

class CFPS {
public:
    static void solve() {
        int n;
        cin >> n;

        vector<int> sOG(n);
        for (int i = 0; i < n; i++) {
            cin >> sOG[i];
        }

        if (n == 1) {
