﻿


















using namespace std;



const int INF = 1e9 + 1;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef vector<tuple<int, int, int>> viii;




















int fast_pow(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b % 2) {
            b--;
            res = (res * a) % m;
        }
        else {
            b /= 2;
            a = (a * a) % m;
        }
    }
    return res;
}

void pref(const vector<int>& a, vector<ll>& p) {
    int n = int(a.size());
    p[0] = a[0];
    for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
}

bool rbs(string s) {
    int bal = 0;
    int n = int(s.size());
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') bal++;
        else if (s[i] == ')') bal--;
        if (bal < 0) return 0;
    }
    return bal == 0;
}

ll merge(const vll& a) {
    ll res = 0;
    vector<pair<ll, int>> b;
    int n = int(a.size());
    for (int i = 0; i < n; i++) {
        b.pb(mp(a[i].first, 1));
        b.pb(mp(a[i].second, -1));
    }
    sort(all(b));
    int bal = 0;
    ll l = -1;
    for (int i = 0; i < n * 2; i++) {
        if (!bal) {
            l = b[i].first;
        }
        bal += b[i].second;
        if (!bal) {
            res += b[i].first - l + 1;
        }
    }
    return res;
}

void pf(string s, vector<int>& p) {
    int n = int(s.size());
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int prev = p[i - 1];
        while (prev > 0 && s[prev] != s[i]) prev = p[prev - 1];
        p[i] = (s[prev] == s[i]) ? prev + 1 : 0;
    }
}

void zf(string s, vector<int>& z) {
    int n = int(s.size());
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i; r = i + z[i] - 1;
        }
    }
}

int tern_search(const vector<int>& p, bool mn) {
    int n = int(p.size());
    int l = 0, r = n;
    while (r - l > 2) {
        int k = (r - l) / 3;
        int a = l + k;
        int b = a + k;
        if (p[a] < p[b]) {
            if (mn) r = b;
            else l = a;
        }
        else {
            if (mn) l = a;
            else r = b;
        }
    }
    if (mn) return min(p[l], min(p[l + 1], p[r]));
    else return max(p[l], max(p[l + 1], p[r]));
}

void get_hash(string s, vector<int>& h, char c, int p, int m) {
    int n = int(s.size());
    h[0] = s[0] - c + 1;
    for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * p + (s[i] - c + 1)) % m;
    }
}

void get_hash(string s, vector<int>& h1, vector<int>& h2, char c, int p, int m1, int m2) {
    int n = int(s.size());
    h1[0] = s[0] - c + 1;
    h2[0] = s[0] - c + 1;
    for (int i = 1; i < n; i++) {
        h1[i] = (h1[i - 1] * p + (s[i] - c + 1)) % m1;
        h2[i] = (h2[i - 1] * p + (s[i] - c + 1)) % m2;
    }
}

int get_hash(const vector<int>& h, int l, int r, int p, int m) { 

    return (h[r - 1] - ((l > 1) ? (h[l - 2] * fast_pow(p, r - l + 1, m)) : 0)) % m;
}

string get_string(int h, char c, int p) {
    string res = "";
    while (h) {
        int x = h % p;
        h /= p;
        char nxt = char(c + x - 1);
        res += nxt;
    }
    string ret = "";
    int n = int(res.size());
    for (int i = n - 1; i >= 0; i--) {
        ret += res[i];
    }
    return ret;
}

void use_mask(int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "Count of elements " << __builtin_popcount(mask) << ": ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}

void id0(int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "mask: ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << endl << "submasks: " << endl;
        for (int subm = mask; subm > 0; subm = ((subm - 1) & mask)) {
            for (int i = 0; i < n; i++) {
                if (subm & (1 << i)) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
}



struct Point {
    ld x;
    ld y;
};

struct Vct {
    ld x;
    ld y;

    Vct& operator += (const Vct& b) {
        x += b.x;
        y += b.y;
        return *this;
    }

    Vct& operator *= (ld k) {
        x *= k;
        y *= k;
        return *this;
    }

    ld len() {
        return sqrtl(x * x + y * y);
    }

    void norm() {
        ld l = len();
        x /= l;
        y /= l;
    }

    void resize(ld k) {
        norm();
        x *= k;
        y *= k;
    }

    void rotate(ld r, Vct& res) {
        res.x = x * cosl(r) - y * sinl(r);
        res.y = y * cosl(r) + x * sinl(r);
    }

    
    

};

struct Line {
    ld a, b, c;

    Line(ld x0, ld y0, ld x1, ld y1) {
        a = y1 - y0;
        b = x0 - x1;
        c = -x0 * y1 + x1 * y0;
    }

    Line(const Point& p, const Point& q) {
        a = q.y - p.y;
        b = p.x - q.x;
        c = -p.x * q.y + q.x * p.y;
    }

    Line(ld _a, ld _b, const Point& p) {
        a = _a;
        b = _b;
        c = -(a * p.x + b * p.y);
    }

    void get_point1(Point& res) {
        res.x = (-c * a) / (a * a + b * b); res.y = (-c * b) / (a * a + b * b);
    };

    void get_point2(Point& res) {
        res.x = (-c * a) / (a * a + b * b) - b; res.y = (-c * b) / (a * a + b * b) + a;
    }

    ld dist(const Point& p) {
        return abs((a * p.x + b * p.y + c) / sqrtl(a * a + b * b));
    }

    void cross(const Line& l, vector<Point>& p) {
        Point q;
        ld d = a * l.b - b * l.a;
        ld dx = b * l.c - c * l.b;
        ld dy = c * l.a - l.c * a;
        if (d == 0) return;
        q.x = dx / d;
        q.y = dy / d;
        p.pb(q);
        

    }

    Point& move_to_line(Point& p, Point& res) {
        ld d = dist(p);
        Vct v1{ a, b };
        Vct v2{ -a, -b };
        v1.resize(d); v2.resize(d);
        Point r; r.x = p.x + v1.x; r.y = p.y + v1.y;
        Point l; l.x = p.x + v2.x; l.y = p.y + v2.y;
        if (dist(r) < dist(l)) res = r;
        else return res = l;
    }
};

struct Circle {
    ld x;
    ld y;
    ld r;

    Circle() {
        x = 0;
        y = 0;
        r = 0;
    }

    Circle(ld _x, ld _y, ld _r) {
        x = _x; y = _y; r = _r;
    }

    Circle(const Point& p, ld _r) {
        x = p.x; y = p.y; r = _r;
    }

    ld len() {
        return 2 * M_PI * r;
    }

    ld s() {
        return M_PI * r * r;
    }

    void cross(Line& l, vector<Point>& p) {
        ld d = l.dist(Point{ x, y });
        if (d > r) return;
        else if (d == r) {
            Point c;
            c.x = x;
            c.y = y;
            Point a;  l.move_to_line(c, a);
            p.pb(a);
        }
        else {
            Point a, b, aa, bb;
            Vct v1{ l.a, l.b }, v2{ -l.a, -l.b }, n{ l.b, -l.a }, m{ -l.b, l.a };
            ld dd = sqrtl(r * r - d * d);
            v1.resize(d); v2.resize(d);
            n.resize(dd); m.resize(dd);
            a.x = x + v1.x; a.y = y + v1.y;
            b.x = x + v2.x; b.y = y + v2.y;
            if (l.dist(a) < l.dist(b)) {
                aa.x = a.x + n.x; aa.y = a.y + n.y;
                bb.x = a.x + m.x; bb.y = a.y + m.y;
            }
            else {
                aa.x = b.x + n.x; aa.y = b.y + n.y;
                bb.x = b.x + m.x; bb.y = b.y + m.y;
            }
            p.pb(aa);
            p.pb(bb);
        }
    }

    void cross(const Circle& c, vector<Point>& res) {
        Vct v{ c.x - x, c.y - y };
        ld d = v.len();
        if (r + c.r < d || (x == c.x && y == c.y && r == c.r) || d + min(r, c.r) < max(r, c.r)) return;
        else if (r + c.r == d || d + min(r, c.r) == max(r, c.r)) {
            v.resize(r);
            Point p;
            p.x = x + v.x; p.y = y + v.y;
            res.pb(p);
        }
        else {
            ld xx = (r * r - c.r * c.r + d * d) / (2 * d);
            ld h = sqrtl(r * r - xx * xx);
            v.resize(xx);
            Point a;
            a.x = x + v.x; a.y = y + v.y;
            Vct b{ v.y, -v.x }, c{ -v.y, v.x };
            b.resize(h); c.resize(h);
            Point p, q;
            p.x = a.x + b.x; p.y = a.y + b.y;
            q.x = a.x + c.x; q.y = a.y + c.y;
            res.pb(p);
            res.pb(q);
        }
    }

    void tangent(const Point& p, vector<Line>& res) {
        Vct v{ x - p.x, y - p.y };
        ld h = v.len();
        if (h < r) return;
        else if (h == r) {
            Line l(v.x, v.y, p);
            res.pb(l);
        }
        else {
            ld d = sqrtl(h * h - r * r);
            v.resize(d);
            ld aa = asinl(r / h);
            Vct v1, v2;
            v.rotate(aa, v1);
            v.rotate(-aa, v2);
            Point a, b;
            a.x = p.x + v1.x; a.y = p.y + v1.y;
            b.x = p.x + v2.x; b.y = p.y + v2.y;
            Line l1(p, a);
            Line l2(p, b);
            res.pb(l1);
            res.pb(l2);
        }
    }

    void tangent(const Circle& c, vector<Line>& res) {
        vector<Line> l;
        Circle c1(x, y, r + c.r);
        Circle c2(x, y, r - c.r);
        c1.tangent(Point{ c.x, c.y }, l);
        c2.tangent(Point{ c.x, c.y }, l);
        for (size_t i = 0; i < l.size(); i++) {
            Line l1 = l[i];
            Vct nrm{ l1.a, l1.b };
            nrm.resize(c.r);
            if (i % 2) nrm *= -1;
            Point p;
            p.x = c.x + nrm.x; p.y = c.y + nrm.y;
            Line lll(nrm.x, nrm.y, p);
            res.pb(lll);
        }
    }
};



void Area(const vector<Point>& a, ld& res) {
    int n = int(a.size());
    Point p, q;
    p = a[n - 1];
    q = a[0];
    res += (q.x - p.x) * (p.y + q.y) / 2;
    for (int i = 0; i < n - 1; i++) {
        p = a[i];
        q = a[i + 1];
        res += (q.x - p.x) * (p.y + q.y) / 2;
    }
}

void Create1(const vector<Point>& a, vector<Point>& res) {
    

    ld mn = a[0].x;
    int n = int(a.size());
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i].x);
    }
    int s = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].x == mn) {
            if (s == -1) {
                s = i;
            }
            else if (a[s].y > a[i].y) {
                s = i;
            }
        }
    }
    res.push_back(a[s]);
    int c = s;
    int ii = 0;
    while (ii < n) {
        bool f = false;
        int next = -1;
        Vct v;
        for (int i = 0; i < n; i++) {
            if (i != c) {
                if (!f) {
                    next = i;
                    v.x = a[i].x - a[c].x;
                    v.y = a[i].y - a[c].y;
                    f = true;
                }
                else {
                    Vct vv;
                    vv.x = a[i].x - a[c].x;
                    vv.y = a[i].y - a[c].y;
                    ld d = vv.x * v.y - vv.y * v.x;
                    if (d < 0) {
                        v = vv;
                        next = i;
                    }
                    else if (d == 0) {
                        Vct v1; Vct v2;
                        v1.x = a[next].x - a[c].x; v1.y = a[next].y - a[c].y;
                        v2.x = a[i].x - a[c].x; v2.y = a[i].y - a[c].y;
                        if (v2.len() > v1.len()) {
                            v = vv;
                            next = i;
                        }
                    }
                }
            }
        }
        if (next == s) break;
        res.pb(a[next]);
        c = next;
        ii++;
    }
}

struct point_cmp
{
    point_cmp(Point _c) {
        c = _c;
    }

    Point c;

    inline bool operator() (const Point& a, const Point& b)
    {
        Vct x, y;
        x.x = a.x - c.x; x.y = a.y - c.y;
        y.x = b.x - c.x; y.y = b.y - c.y;
        auto d = x.x * y.y - x.y * y.x;
        if (d != 0) {
            return d > 0;
        }
        return x.len() < y.len();
    }
};

void Create2(vector<Point>& a, vector<Point>& res) {
    

    ld mn = a[0].x;
    int n = int(a.size());
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i].x);
    }
    int s = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].x == mn) {
            if (s == -1) {
                s = i;
            }
            else if (a[s].y > a[i].y) {
                s = i;
            }
        }
    }
    swap(a[0], a[s]);
    sort(a.begin() + 1, a.end(), point_cmp(a[0]));
    stack<Point> r;
    r.push(a[0]);
    r.push(a[1]);
    int m = 2;
    for (int i = 2; i < n; i++) {
        Vct v1, v2;
        Point b = r.top();
        r.pop();
        Point c = r.top();
        r.push(b);
        Point d = a[i];
        v1.x = b.x - c.x; v1.y = b.y - c.y;
        v2.x = d.x - b.x; v2.y = d.y - b.y;
        ld f = v1.x * v2.y - v1.y * v2.x;
        if (f >= 0) {
            r.push(a[i]);
            m++;
        }
        else {
            r.pop();
            m--;
            i--;
        }
    }
    res.resize(m);
    for (int i = 0; i < m; i++) {
        res[m - 1 - i] = r.top();
        r.pop();
    }
}

ld Angle(const Vct& a, const Vct& b) {
    return atan2(b.y * a.x - a.y * b.x, a.x * b.x + a.y * b.y);
}





Vct operator + (const Vct& a, const Vct& b) {
    return { a.x + b.x, a.y + b.y };
}

Vct operator * (const Vct& a, double k) {
    return { a.x * k, a.y * k };
}





ostream& operator << (ostream& out, const Vct& v) {
    out << v.x << " " << v.y;
    return out;
}

istream& operator >> (istream& in, Vct& v) {
    in >> v.x >> v.y;
    return in;
}

ostream& operator << (ostream& out, const Point& p) {
    out << p.x << " " << p.y;
    return out;
}

istream& operator >> (istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator << (ostream& out, const Line& l) {
    out << l.a << " " << l.b << " " << l.c;
    return out;
}

istream& operator >> (istream& in, Line& l) {
    in >> l.a >> l.b >> l.c;
    return in;
}

ostream& operator << (ostream& out, const Circle& c) {
    out << c.x << " " << c.y << " " << c.r;
    return out;
}

istream& operator >> (istream& in, Circle& c) {
    in >> c.x >> c.y >> c.r;
    return in;
}

ostream& operator << (ostream& out, const vi& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) out << v[i] << " ";
    return out;
}

istream& operator >> (istream& in, vi& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) in >> v[i];
    return in;
}

ostream& operator << (ostream& out, const vl& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) out << v[i] << " ";
    return out;
}

istream& operator >> (istream& in, vl& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) in >> v[i];
    return in;
}

ostream& operator << (ostream& out, const vs& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) out << v[i] << " ";
    return out;
}

istream& operator >> (istream& in, vs& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) in >> v[i];
    return in;
}

ostream& operator << (ostream& out, const vvi& v) {
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) out << v[i][j] << " ";
        if (i < n - 1) out << endl;
    }
    return out;
}

istream& operator >> (istream& in, vvi& v) {
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) in >> v[i][j];
    }
    return in;
}

ostream& operator << (ostream& out, const pii& p) {
    out << p.first << " " << p.second;
    return out;
}

istream& operator >> (istream& in, pii& p) {
    in >> p.first >> p.second;
    return in;
}

ostream& operator << (ostream& out, const pll& p) {
    out << p.first << " " << p.second;
    return out;
}

istream& operator >> (istream& in, pll& p) {
    in >> p.first >> p.second;
    return in;
}

ostream& operator << (ostream& out, const vii& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        out << v[i];
        if (i < n - 1) out << endl;
    }
    return out;
}

istream& operator >> (istream& in, vii& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) in >> v[i];
    return in;
}

ostream& operator << (ostream& out, const vll& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        out << v[i];
        if (i < n - 1) out << endl;
    }
    return out;
}

istream& operator >> (istream& in, vll& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) in >> v[i];
    return in;
}





struct heap {
    vector<int> h;
    bool mn;

    heap(bool _mn) {
        h.pb((_mn) ? -INF : INF);
        mn = _mn;
    }

    void add(int x) {
        h.pb(x);
        up(int(h.size()) - 1);
    }

    int pop() {
        if (int(h.size()) == 1) return -1;
        else {
            int res = h[1];
            swap(h[int(h.size()) - 1], h[1]);
            h.pop_back();
            down(1);
            return res;
        }
    }

    void up(int v) {
        if (mn) {
            if (h[v] >= h[v / 2]) return;
            else {
                swap(h[v], h[v / 2]);
                up(v / 2);
            }
        }
        else {
            if (h[v] <= h[v / 2]) return;
            else {
                swap(h[v], h[v / 2]);
                up(v / 2);
            }
        }
    }

    void down(int v) {
        if (v * 2 >= int(h.size())) return;
        if (mn) {
            if (h[v] > h[v * 2] || h[v] > h[((v * 2 + 1 >= int(h.size())) ? v : v * 2 + 1)]) {
                if (v * 2 + 1 >= int(h.size()) || h[v * 2] < h[v * 2 + 1]) {
                    swap(h[v], h[v * 2]);
                    down(v * 2);
                }
                else {
                    swap(h[v], h[v * 2 + 1]);
                    down(v * 2 + 1);
                }
            }
        }
        else {
            if (h[v] < h[v * 2] || h[v] < h[((v * 2 + 1 >= int(h.size())) ? v : v * 2 + 1)]) {
                if (v * 2 + 1 >= int(h.size()) || h[v * 2] > h[v * 2 + 1]) {
                    swap(h[v], h[v * 2]);
                    down(v * 2);
                }
                else {
                    swap(h[v], h[v * 2 + 1]);
                    down(v * 2 + 1);
                }
            }
        }
    }

    int size() {
        return int(h.size()) - 1;
    }

    int GetV(int v) {
        return h[v];
    }

    void debug() {
        for (int i = 0; i < int(h.size()); i++) cout << h[i] << " ";
        cout << endl;
    }
};

struct id1 { 

    const int MAXN = 1 << 17;
    int Size = MAXN;
    const int NEUTRAL = 0;

    vector<ll> t;

    id1(const vector<int>& a, bool sz) {
        if (sz) {
            Size = 2;
            while (int(a.size()) > Size) Size *= 2;
        }
        else Size = MAXN;
        t.resize(2 * Size);
        Build(1, 0, Size, a);
    }

    void Build(int v, int l, int r, const vector<int>& a) {
        if (l + 1 == r) {
            t[v] = (l < int(a.size())) ? a[l] : NEUTRAL;
            return;
        }
        int m = (l + r) / 2;
        Build(v * 2, l, m, a);
        Build(v * 2 + 1, m, r, a);
        Update(v);
    }

    void Update(int v) {
        t[v] = t[v * 2] + t[v * 2 + 1]; 

        

    }

    long long Query(int l, int r) { 

        return Query(1, 0, Size, l - 1, r);
    }

    long long Query(int v, int vl, int vr, int l, int r) { 

        if (vr <= l || r <= vl) {
            return NEUTRAL;
        }
        if (vl >= l && vr <= r) {
            return t[v];
        }
        int vm = (vl + vr) / 2;
        return Query(v * 2, vl, vm, l, r) + Query(v * 2 + 1, vm, vr, l, r); 

        

    }

    void Update(int pos, int x) {
        pos += Size - 1; 

        t[pos] = x;
        while (pos > 1) {
            pos /= 2;
            Update(pos);
        }
    }
};

void solve() {
    ci(n);
    veci(d, n);
    bool res = true;
    vi a(n);
    a[0] = d[0];
    for (int i = 1; i < n; i++) {
        int x = a[i - 1] + d[i];
        int y = a[i - 1] - d[i];
        if (x >= 0 && y >= 0 && x != y) {
            res = false;
            break;
        }
        else if (x >= 0) a[i] = x;
        else a[i] = y;
    }
    if (res) cout << a << endl;
    else cout << -1 << endl;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
