




using namespace std;

using T = long double;
const T EPS = 1e-10;
const T PI = acos(-1.0);
T torad(int deg) {return (T)(deg) * PI / 180;}
T id3(T ang) {return ang * 180 / PI;}


using P = complex<T>;


template <typename T> inline bool eq(T p, T q) { return abs(p - q) < EPS; }
inline int sgn(T x) { return (0.0 < x) - (x < 0.0); }
inline T dot(P v, P w) { return (conj(v) * w).x; }
inline T cross(P v, P w) { return (conj(v) * w).y; }
inline bool isOrth(P v, P w) { return dot(v, w) == 0; }
inline bool isPara(P v, P w) { return cross(v, w) == 0; }
inline P unit(P v) { return v / abs(v); }
inline P translate(P p, P v) { return p + v; }
inline P scale(P p, P c, T k) { return c + (p - c) * k; }
inline P rot(P p, T a) { return p * polar(T(1), a); }
inline P rot90(P p) { return {-p.y, p.x}; }
inline T orient(P a, P b, P c) { return cross(b - a, c - a); }
istream& operator>>(istream& is, P& p) { T xx, yy; is >> xx >> yy; p = P(xx, yy); return is; }
bool cmpX(const P& a, const P& b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
bool cmpY(const P& a, const P& b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
namespace std {
    bool operator < (const P& a, const P& b) { return cmpX(a, b); }
}

P linearTransform(P p, P q, P fp, P fq, P r) {
    return fp + (r - p) * (fq - fp) / (q - p);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0) return +1;      

    if (cross(b, c) < 0) return -1;      

    if (dot(b, c) < 0) return +2;        

    if (norm(b) < norm(c)) return -2;    

    return 0;                            

}

T angle(P v, P w) {
    T cosTheta = dot(v, w) / abs(v) / abs(w);
    return acos(max(T(-1.0), min(T(1.0), cosTheta)));
}
T id9(P a, P b, P c) {
    if (orient(a, b, c) >= 0) return angle(b - a, c - a);
    return 2 * PI - angle(b - a, c - a);
}
bool inAngle(P a, P b, P c, P p) {
    assert(abs(orient(a, b, c)) != 0);
    if (orient(a, b, c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}



bool half(P p) {
    assert(p.x != 0 || p.y != 0);
    return p.y > 0 || (p.y == 0 && p.x < 0);
}
void polarSort(vector<P>& v, P o = P(0.0, 0.0)) {
    sort(v.begin(), v.end(), [&](P v, P w) {
        return make_tuple(half(v - o), 0, norm(v - o)) <
            make_tuple(half(w - o), cross(v - o, w - o), norm(w - o));
    });
}


struct L : array<P, 2> {
    P v; T c;
    L(P a = P(0.0, 0.0), P b = P(0.0, 0.0)) : array<P, 2>({a, b}), v(b - a), c(cross(v, a)) {}
    T side(P p) { return cross(v, p) - c; }
    P proj(P p) { return p - rot90(v) * side(p) / norm(v); }
    P refl(P p) { return p - rot90(v) * T(2) * side(p) / norm(v); }
    friend istream& operator>>(istream& is, L& l) { P p, q; is >> p >> q; l = L(p, q); return is; }
    friend ostream& operator<<(ostream& os, const L& l) { return os << '{' << l[0] << ", " << l[1] << '}'; }
};


struct C : P {
    T r;
    C(P p = P(0.0, 0.0), T r = 0.0) : P(p), r(r) {}
    friend istream& operator>>(istream& is, C& c) { P p; T r; is >> p >> r; c = C(p, r); return is; }
    friend ostream& operator<<(ostream& os, const C& c) { return os << '(' << c.x << ", " << c.y << ", " << c.r << ')'; }
};

P id6(P a, P b, P c) {
    b -= a, c -= a;
    assert(cross(b, c) != 0);
    return a + rot90(b * norm(c) - c * norm(b)) / cross(b, c) / T(2);
}

vector<P> id1(C c, P p) {
    if (eq(abs(p - c), c.r)) return vector<P>{p};
    vector<P> res;
    T t = acos(c.r / abs(p - c));
    P q = (p - c) / abs(p - c) * c.r;
    res.push_back(c + q * polar(T(1), t));
    res.push_back(c + q * polar(T(1), -t));
    sort(res.begin(), res.end(), cmpX);
    return res;
}

vector<L> id12(C c1, C c2, bool inner) {
    if (inner) c2.r = -c2.r;
    vector<L> res;
    P d = c2 - c1;
    T dr = c1.r - c2.r, d2 = norm(d), h2 = d2 - dr * dr;
    if (d2 == 0 || h2 < 0) { assert(h2 != 0); return res; }
    for (T sign : {-1, 1}) {
        P v = (d * dr + rot90(d) * sqrt(h2) * sign) / d2;
        res.emplace_back(c1 + v * c1.r, c2 + v * c2.r);
    }
    return res;
}



bool id18(P p, L l) { return (ccw(l[0], l[1], p) != 1); }
bool id0(P p, L s) { return (ccw(s[0], s[1], p) == 0); }
bool id4(L l, L m) { return (!isPara(l.v, m.v)); }
bool id23(L l, L s) {
    if (eq(s[0], s[1])) return id18(s[0], l);
    return (ccw(l[0], l[1], s[0]) * ccw(l[0], l[1], s[1]) <= 0);
}
bool id21(L s, L t) {
    if (eq(s[0], s[1])) return id18(s[0], t);
    if (eq(t[0], t[1])) return id18(t[0], s);
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}
int id24(C a, C b) {
    T d = abs(b - a);
    if (a == b && a.r == b.r) return 0;         

    if (a.r + d - b.r < -EPS) return +1;        

    if (b.r + d - a.r < -EPS) return -1;        

    if (abs(a.r + d - b.r) < EPS) return +2;    

    if (abs(b.r + d - a.r) < EPS) return -2;    

    if (abs(a.r + b.r - d) < EPS) return 3;     

    if (a.r + b.r - d < -EPS) return 4;         

    return 5;                                   

}
 


T distancePL(P p, L l) { return (abs(p - l.proj(p))); }
T distancePS(P p, L s) {
    P h = s.proj(p);
    if (id0(h, s)) return abs(p - h);
    return min(abs(p - s[0]), abs(p - s[1]));
}
T distanceLL(L l, L m) {
    if (id4(l, m)) return 0.0;
    return distancePL(m[0], l);
}
T distanceLS(L l, L s) {
    if (id23(l, s)) return 0;
    return min(distancePL(s[0], l), distancePL(s[1], l));
}
T distanceSS(L s, L t) {
    if (id21(s, t)) return 0;
    return min({distancePS(s[0], t), distancePS(s[1], t), distancePS(t[0], s), distancePS(t[1], s)});
}



vector<P> id19(L l, L m) {
    if (!id4(l, m)) return vector<P>();
    vector<P> res;
    T d = cross(m[1] - m[0], l[1] - l[0]);
    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);
    return res;
}
vector<P> id14(L l, L s) {
    if (!id23(l, s)) return vector<P>();
    vector<P> res;
    T d = cross(s[1] - s[0], l[1] - l[0]);
    res.push_back(l[0] + (l[1] - l[0]) * cross(s[1] - s[0], s[1] - l[0]) / d);
    return res;
}
vector<P> id11(L l, C c, bool dupl = false) {
    if (abs(c - l.proj(c)) > c.r) return vector<P>();
    vector<P> res;
    T d = distancePL(c, l), h2 = c.r * c.r - d * d;
    assert(h2 >= 0);
    P p = l.proj(c), h = l.v * sqrt(h2) / abs(l.v);
    res.push_back(p - h);
    if (dupl || abs(h) > 0) res.push_back(p + h);
    if (res.size() == 2 && !(res[0] < res[1])) swap(res[0], res[1]);
    return res;
}
vector<P> id13(L s, L t) {
    if (!id21(s, t)) return vector<P>();
    vector<P> res;
    if (unit(s.v) != unit(t.v)) {
        T d = cross(t[1] - t[0], s[1] - s[0]);
        res.push_back(s[0] + (s[1] - s[0]) * cross(t[1] - t[0], t[1] - s[0]) / d);
    } else {
        if (ccw(s[0], s[1], t[0]) == 0) res.push_back(t[0]);
        if (ccw(s[0], s[1], t[1]) == 0) res.push_back(t[1]);
        if (ccw(t[0], t[1], s[0]) == 0) res.push_back(s[0]);
        if (ccw(t[0], t[1], s[1]) == 0) res.push_back(s[1]);
    }
    return res;
}
vector<P> id2(L s, C c, bool dupl = false) {
    if (abs(c - s.proj(c)) > c.r) return vector<P>();
    vector<P> res;
    T d = distancePL(c, s), h2 = c.r * c.r - d * d;
    assert(h2 >= 0);
    P p = s.proj(c), h = s.v * sqrt(h2) / abs(s.v);
    if (ccw(s[0], s[1], p - h) == 0) res.push_back(p - h);
    if (dupl || (abs(h) > 0 && id0(p + h, s))) res.push_back(p + h);
    if (res.size() == 2 && !(res[0] < res[1])) swap(res[0], res[1]);
    return res;
}
vector<P> id7(C c1, C c2, bool dupl = false) {
    P d = c2 - c1; T d2 = norm(d);
    if (d2 == 0) { assert(c1.r != c2.r); return vector<P>(); }
    vector<P> res;
    T pd = (d2 + c1.r * c1.r - c2.r * c2.r) / 2;
    T h2 = c1.r * c1.r - pd * pd / d2;
    if (h2 >= 0) {
        P p = c1 + d * pd / d2, h = rot90(d) * sqrt(h2 / d2);
        res.push_back(p - h);
        if (dupl || abs(h) > 0) res.push_back(p + h);
        if (res.size() == 2 && !(res[0] < res[1])) swap(res[0], res[1]);
    }
    return res;
}




vector<P> makeStandard(vector<P> p) {
    int n = p.size(), j = -1;
    for (int i = 0; i < n; ++i) {
        if (j == -1 || p[i].y < p[j].y) j = i;
    }
    vector<P> res;
    if (p[(j - 1 + n) % n].x <= p[j].x && p[j].x <= p[(j + 1) % n].x) {
        for (int i = 0; i < n; ++i) {
            res.push_back(p[(i + j) % n]);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            res.push_back(p[(i - j + n) % n]);
        }
    }
    return res;
}
bool id5(vector<P> p) {
    p = makeStandard(p);
    for (int i = 0, n = p.size(); i < n; ++i) {
        P a = p[i], b = p[(i + 1) % n], c = p[(i + 2) % n];
        if (orient(a, b, c) < 0) return false;
        if (b.y != p[0].y && b.y < min(a.y, c.y)) return false;
        if (b.y != p[0].y && a.y == b.y && b.y == c.y && a.x <= b.x && b.x <= c.x) return false;
    }
    return true;
}
T areaTriangle(P a, P b, P c) {
    return abs(cross(b - a, c - a)) / 2.0;
}
T areaPolygon(vector<P> p) {
    T res = 0;
    for (int i = 0, n = p.size(); i < n; ++i) {
        res += cross(p[i], p[(i + 1) % n]);
    }
    return abs(res) / 2.0;
}
T areaCC(C p, C q) {
    int in = id24(p, q);
    if (abs(in) <= 2) return pow(min(p.r, q.r), 2) * PI;
    if (in <= 4) return 0.0;
    T d = abs(p - q), res = 0;
    T pt = acos((p.r * p.r + d * d - q.r * q.r) / (2 * p.r * d));
    res += p.r * p.r * pt - p.r * p.r * sin(pt) * cos(pt);
    T qt = acos((q.r * q.r + d * d - p.r * p.r) / (2 * q.r * d));
    res += q.r * q.r * qt - q.r * q.r * sin(qt) * cos(qt);
    return res;
}
P centroid(vector<P> p) {
    P c; T sumA = 0;
    for (int i = 0, n = p.size(); i < n; ++i) {
        T a = cross(p[i], p[(i + 1) % n]);
        sumA += abs(a);
        c += (p[i] + p[(i + 1) % n]) * a;
    }
    return 1.0 / 3.0 / sumA * c;
}






int id20(vector<P> p, P a) {
    int n = p.size();
    P g = (p[0] + p[n / 2]) / T(2);
    if (g == a) return 1;
    P ga = a - g;
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        P gl = p[l] - g, gm = p[m] - g;
        if (cross(gl, gm) > EPS) {
            if (cross(gl, ga) > -EPS && cross(gm, ga) < EPS) r = m;
            else l = m;
        } else {
            if (cross(gl, ga) < EPS && cross(gm, ga) > -EPS) l = m;
            else r = m;
        }
    }
    r %= n;
    int c = ccw(a, p[l], p[r]);
    return (c == 2 || c == -2 || c == 0) ? 2 : c == -1 ? 0 : 1;
}
bool above(P a, P p) { return p.y >= a.y; }
bool id15(P a, P p, P q) {
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}






int inPolygon(vector<P> p, P a) {
    int id16 = 0;
    for (int i = 0, n = p.size(); i < n; ++i) {
        if (ccw(p[i], p[(i + 1) % n], a) == 0) return 2;
        id16 += id15(a, p[i], p[(i + 1) % n]);
    }
    return id16 & 1;
}
vector<P> id17(vector<P> p) {
    int n = p.size(), k = 0;
    sort(p.begin(), p.end(), cmpX);
    vector<P> res(2 * n);
    for (int i = 0; i < n; res[k++] = p[i++])
        while (k >= 2 && ccw(res[k - 2], res[k - 1], p[i]) <= 0) --k;
    for (int i = n - 2, t = k + 1; i >= 0; res[k++] = p[i--])
        while (k >= t && ccw(res[k - 2], res[k - 1], p[i]) <= 0) --k;
    res.resize(k - 1);
    return res;
}
vector<P> id10(vector<P> p) {
    int n = p.size(), k = 0;
    sort(p.begin(), p.end(), cmpX);
    vector<P> res(2 * n);
    for (int i = 0; i < n; res[k++] = p[i++])
        while (k >= 2 && ccw(res[k - 2], res[k - 1], p[i]) == -1) --k;
    for (int i = n - 2, t = k + 1; i >= 0; res[k++] = p[i--])
        while (k >= t && ccw(res[k - 2], res[k - 1], p[i]) == -1) --k;
    res.resize(k - 1);
    return res;
}
vector<P> id22(vector<P> p, L l) {
    vector<P> res;
    for (int i = 0, n = p.size(); i < n; ++i) {
        int ccwc = ccw(l[0], l[1], p[i]);
        if (ccwc != -1) res.push_back(p[i]);
        int ccwn = ccw(l[0], l[1], p[(i + 1) % n]);
        if (ccwc * ccwn == -1) res.push_back(id19(l, L(p[i], p[(i + 1) % n]))[0]);
    }
    return res;
}
pair<int, int> id8(const vector<P>& p) {
    int i = min_element(p.begin(), p.end()) - p.begin();
    int j = max_element(p.begin(), p.end()) - p.begin();
    int maxI, maxJ;
    T maxD = 0;
    for (int k = 0, n = p.size(); k < 2 * n; ++k) {
        if (maxD < norm(p[i] - p[j]) - EPS) {
            maxD = norm(p[i] - p[j]);
            maxI = i;
            maxJ = j;
        }
        if (cross(p[i] - p[(i + 1) % n], p[(j + 1) % n] - p[j]) < EPS) j = (j + 1) % n;
        else i = (i + 1) % n;
    }
    return make_pair(maxI, maxJ);
}
T closest_pair(vector<P>& a, int l = 0, int r = -1) {
    if (r < 0) {
        r = a.size();
        sort(a.begin(), a.end());
    }
    if (r - l <= 1) return abs(a[0] - a[1]);
    int m = (l + r) >> 1;
    T amx = a[m].x, d = min(closest_pair(a, l, m), closest_pair(a, m, r));
    inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r, cmpY);
    vector<P> b;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - amx) > d - EPS) continue;
        for (int j = 0, n = b.size(); j < n; ++j) {
            if (a[i].y - b[n - j - 1].y > d - EPS) break;
            d = min(d, abs(a[i] - b[n - j - 1]));
        }
        b.push_back(a[i]);
    }
    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    C p, q;
    cin >> p >> q;
    cout << areaCC(p, q) << endl;
}