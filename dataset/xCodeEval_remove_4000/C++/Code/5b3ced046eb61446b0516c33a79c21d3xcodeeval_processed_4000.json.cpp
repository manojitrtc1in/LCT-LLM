


using namespace std;
namespace geometry {


    constexpr db eps = 1e-7;
    int sign(db k) {
        if (k > eps) return 1;
        else if (k < -eps) return -1;
        return 0;
    }
    int cmp(db k1, db k2) { 

        return sign(k1 - k2);
    }
    int inmid(db k1, db k2, db k3) { 

        return sign(k1 - k3) * sign(k2 - k3) <= 0;
    }

    struct point { 

        db x, y;
        point() {}
        point(db x_, db y_) :x(x_), y(y_) {}
        point operator + (const point& k) const { return point(k.x + x, k.y + y); }
        point operator - (const point& k) const { return point(x - k.x, y - k.y); }
        point operator * (db k) const { return point(x * k, y * k); }
        point operator / (db k1) const { return point(x / k1, y / k1); }
        point turn(db k1) { return point(x * cos(k1) - y * sin(k1), x * sin(k1) + y * cos(k1)); } 

        point turn90() { return point(-y, x); } 

        point iturn90() { return point(y, -x); }
        db len() { return sqrt(x * x + y * y); } 

        db len2() { return x * x + y * y; } 

        db getPolarAngle() { return atan2(y, x); } 

        db dis(point k) { return ((*this) - k).len(); } 

        point unit() { db d = len(); return point(x / d, y / d); } 

        point getdel() { 

            if (sign(x) == -1 || (sign(x) == 0 && sign(y) == -1))
                return (*this) * (-1);
            else return (*this);
        }
        bool operator < (const point& k) const { 

            return x == k.x ? y < k.y : x < k.x;
        }
        bool getP() const { 

            return sign(y) == 1 || (sign(y) == 0 && sign(x) == -1);
        }
    };
    db cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; } 

    db dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }   

    db rad(point k1, point k2) { 

        return atan2(cross(k1, k2), dot(k1, k2));
    }
    int inmid(point k1, point k2, point k3) { 

        return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y);
    }
    int compareAngle(point k1, point k2) { 

        

        return k1.getP() < k2.getP() || (k1.getP() == k2.getP() && sign(cross(k1, k2)) > 0);
    }
    point proj(point k1, point k2, point q) { 

        point k = k2 - k1; return k1 + k * (dot(q - k1, k) / k.len2());
    }
    point reflect(point k1, point k2, point q) { return proj(k1, k2, q) * 2 - q; } 

    int id2(point k1, point k2, point k3) { 

        return sign(cross(k2 - k1, k3 - k1));
    }
    int checkLL(point k1, point k2, point k3, point k4) { 

        

        return sign(cross(k2 - k1, k4 - k3)) != 0;
    }
    point getLL(point k1, point k2, point k3, point k4) { 

        db w1 = cross(k1 - k3, k4 - k3), w2 = cross(k4 - k3, k2 - k3);
        return (k1 * w2 + k2 * w1) / (w1 + w2);
    }
    int intersect(db l1, db r1, db l2, db r2) { 

        if (l1 > r1) swap(l1, r1);
        if (l2 > r2) swap(l2, r2);
        return cmp(r1, l2) != -1 && cmp(r2, l1) != -1;
    }
    int checkSS(point k1, point k2, point k3, point k4) { 

        return intersect(k1.x, k2.x, k3.x, k4.x) && intersect(k1.y, k2.y, k3.y, k4.y) &&
            sign(cross(k3 - k1, k4 - k1)) * sign(cross(k3 - k2, k4 - k2)) <= 0 &&
            sign(cross(k1 - k3, k2 - k3)) * sign(cross(k1 - k4, k2 - k4)) <= 0;
    }
    db disSP(point k1, point k2, point q) { 

        point k3 = proj(k1, k2, q);
        if (inmid(k1, k2, k3)) return q.dis(k3);
        else return min(q.dis(k1), q.dis(k2));
    }
    db disLP(point k1, point k2, point q) { 

        point k3 = proj(k1, k2, q);
        return q.dis(k3);
    }
    db disSS(point k1, point k2, point k3, point k4) { 

        if (checkSS(k1, k2, k3, k4)) return 0;
        else return min(min(disSP(k1, k2, k3), disSP(k1, k2, k4)),
            min(disSP(k3, k4, k1), disSP(k3, k4, k2)));
    }
    bool onLine(point k1, point k2, point q) { 

        return sign(cross(k1 - q, k2 - q)) == 0;
    }
    bool onSegment(point k1, point k2, point q) { 

        if (!onLine(k1, k2, q)) return false; 

        return inmid(k1, k2, q);
    }
    void id7(vector<point>& p, point t) { 

        sort(p.begin(), p.end(), [&](const point& k1, const point& k2) {
            return compareAngle(k1 - t, k2 - t);
        });
    }

    struct line { 

        point p[2];
        line() {}
        line(point k1, point k2) { p[0] = k1, p[1] = k2; }
        point& operator [] (int k) { return p[k]; }
        point dir() { return p[1] - p[0]; } 

        bool include(point k) { 

            return sign(cross(p[1] - p[0], k - p[0])) > 0;
        }
        bool includeS(point k) { 

            return onSegment(p[0], p[1], k);
        }
        line push(db len) { 

            point delta = (p[1] - p[0]).turn90().unit() * len;
            return line(p[0] - delta, p[1] - delta);
        }
    };

    bool parallel(line k1, line k2) { 

        return sign(cross(k1.dir(), k2.dir())) == 0;
    }
    bool sameLine(line k1, line k2) { 

        return parallel(k1, k2) && parallel(k1, line(k2.p[0], k1.p[0]));
    }
    bool sameDir(line k1, line k2) { 

        return parallel(k1, k2) && sign(dot(k1.dir(), k2.dir())) == 1;
    }
    bool operator < (line k1, line k2) {
        if (sameDir(k1, k2)) return k2.include(k1[0]);
        return compareAngle(k1.dir(), k2.dir());
    }
    point getLL(line k1, line k2) {  

        return getLL(k1[0], k1[1], k2[0], k2[1]);
    }
    bool checkpos(line k1, line k2, line k3) {  

        return k3.include(getLL(k1, k2));
    }

    struct circle { 

        point o;
        double r;
        circle() {}
        circle(point o_, double r_) : o(o_), r(r_) {}
        int inside(point k) {  

            return cmp(r, o.dis(k)); 

        }
    };

    int id6(circle k1, circle k2) { 

        if (cmp(k1.r, k2.r) == -1) swap(k1, k2);
        db dis = k1.o.dis(k2.o);
        int w1 = cmp(dis, k1.r + k2.r), w2 = cmp(dis, k1.r - k2.r);
        if (w1 > 0) return 4; 

        else if (w1 == 0) return 3; 

        else if (w2 > 0) return 2;  

        else if (w2 == 0) return 1; 

        else return 0; 

    }
    vector<point> getCL(circle k1, point k2, point k3) { 

        

        point k = proj(k2, k3, k1.o);
        db d = k1.r * k1.r - (k - k1.o).len2();
        if (sign(d) == -1) return {};
        point del = (k3 - k2).unit() * sqrt(max((db)0.0, d));
        return { k - del,k + del };
    }
    vector<point> getCC(circle k1, circle k2) { 

        

        int pd = id6(k1, k2); if (pd == 0 || pd == 4) return {};
        db a = (k2.o - k1.o).len2(), cosA = (k1.r * k1.r + a -
            k2.r * k2.r) / (2 * k1.r * sqrt(max(a, (db)0.0)));
        db b = k1.r * cosA, c = sqrt(max((db)0.0, k1.r * k1.r - b * b));
        point k = (k2.o - k1.o).unit(), m = k1.o + k * b, del = k.turn90() * c;
        return { m - del,m + del };
    }
    vector<point> id8(circle k1, point k2) { 

        db a = (k2 - k1.o).len(), b = k1.r * k1.r / a, c = sqrt(max((db)0.0, k1.r * k1.r - b * b));
        point k = (k2 - k1.o).unit(), m = k1.o + k * b, del = k.turn90() * c;
        return { m - del,m + del };
    }
    vector<line> id4(circle k1, circle k2) {
        int pd = id6(k1, k2);
        if (pd == 0) return {};
        if (pd == 1) {
            point k = getCC(k1, k2)[0];
            return { line(k,k) };
        }
        if (cmp(k1.r, k2.r) == 0) {
            point del = (k2.o - k1.o).unit().turn90().getdel();
            return { line(k1.o - del * k1.r,k2.o - del * k2.r),
                line(k1.o + del * k1.r,k2.o + del * k2.r) };
        } else {
            point p = (k2.o * k1.r - k1.o * k2.r) / (k1.r - k2.r);
            vector<point> A = id8(k1, p), B = id8(k2, p);
            vector<line> ans; for (int i = 0; i < A.size(); i++)
                ans.push_back(line(A[i], B[i]));
            return ans;
        }
    }
    vector<line> id3(circle k1, circle k2) {
        int pd = id6(k1, k2);
        if (pd <= 2) return {};
        if (pd == 3) {
            point k = getCC(k1, k2)[0];
            return { line(k, k) };
        }
        point p = (k2.o * k1.r + k1.o * k2.r) / (k1.r + k2.r);
        vector<point> A = id8(k1, p), B = id8(k2, p);
        vector<line> ans;
        for (int i = 0; i < (int)A.size(); i++) ans.push_back(line(A[i], B[i]));
        return ans;
    }
    vector<line> id9(circle k1, circle k2) { 

        int flag = 0;
        if (k1.r < k2.r) swap(k1, k2), flag = 1;
        vector<line> A = id4(k1, k2), B = id3(k1, k2);
        for (line k : B) A.push_back(k);
        if (flag) for (line& k : A) swap(k[0], k[1]);
        return A;
    }
    db id10(circle k1, point k2, point k3) { 

        point k = k1.o; k1.o = k1.o - k; k2 = k2 - k; k3 = k3 - k;
        int pd1 = k1.inside(k2), pd2 = k1.inside(k3);
        vector<point> A = getCL(k1, k2, k3);
        if (pd1 >= 0) {
            if (pd2 >= 0) return cross(k2, k3) / 2;
            return k1.r * k1.r * rad(A[1], k3) / 2 + cross(k2, A[1]) / 2;
        } else if (pd2 >= 0) {
            return k1.r * k1.r * rad(k2, A[0]) / 2 + cross(A[0], k3) / 2;
        } else {
            int pd = cmp(k1.r, disSP(k2, k3, k1.o));
            if (pd <= 0) return k1.r * k1.r * rad(k2, k3) / 2;
            return cross(A[0], A[1]) / 2 + k1.r * k1.r * (rad(k2, A[0]) + rad(A[1], k3)) / 2;
        }
    }
    circle getCircle(point k1, point k2, point k3) { 

        db a1 = k2.x - k1.x, b1 = k2.y - k1.y, c1 = (a1 * a1 + b1 * b1) / 2;
        db a2 = k3.x - k1.x, b2 = k3.y - k1.y, c2 = (a2 * a2 + b2 * b2) / 2;
        db d = a1 * b2 - a2 * b1;
        point o = point(k1.x + (c1 * b2 - c2 * b1) / d, k1.y + (a1 * c2 - a2 * c1) / d);
        return circle(o, k1.dis(o));
    }

    struct polygon { 

        int n; 

        vector<point> p;
        polygon() {}
        polygon(vector<point> a) {
            n = (int)a.size();
            p = a;
        }
        db area() { 

            if (n < 3) return 0;
            db ans = 0;
            for (int i = 1; i < n - 1; i++)
                ans += cross(p[i] - p[0], p[i + 1] - p[0]);
            return 0.5 * ans;
        }
        int inConvexHull(point a) { 

            

            

            auto check = [&](int x) {
                int id5 = id2(p[0], a, p[x]),
                    id15 = id2(p[0], a, p[x + 1]);
                if (id5 == -1 && id15 == -1) return 1;
                else if (id5 == 1 && id15 == 1) return -1;
                else if (id5 == -1 && id15 == 1) return 0;
                else return 0;
            };
            if (id2(p[0], a, p[1]) <= 0 && id2(p[0], a, p.back()) >= 0) {
                int l = 1, r = n - 2, mid;
                while (l <= r) {
                    mid = (l + r) >> 1;
                    int chk = check(mid);
                    if (chk == 1) l = mid + 1;
                    else if (chk == -1) r = mid;
                    else break;
                }
                int res = id2(p[mid], a, p[mid + 1]);
                if (res < 0) return 1;
                else if (res == 0) return 0;
                else return -1;
            } else return -1;
        }
    };

    int id13(polygon poly, point q) { 

        

        int pd = 0;
        for (int i = 0; i < poly.n; i++) {
            point u = poly.p[i], v = poly.p[(i + 1) % poly.n];
            if (onSegment(u, v, q)) return 1;
            if (cmp(u.y, v.y) > 0) swap(u, v);
            if (cmp(u.y, q.y) >= 0 || cmp(v.y, q.y) < 0) continue;
            if (sign(cross(u - v, q - v)) < 0) pd ^= 1;
        }
        return pd << 1;
    }
    bool id14(polygon poly) { 

        int sgn = id2(poly.p[0], poly.p[1], poly.p[2]);
        for (int i = 1; i < poly.n; i++) {
            int ccw = id2(poly.p[i], poly.p[(i + 1) % poly.n], poly.p[(i + 2) % poly.n]);
            if (sgn != ccw) return false;
        }
        return true;
    }
    db id1(polygon poly) { 

        int n = poly.n; 

        db ans = 0;
        for (int i = 0, j = n < 2 ? 0 : 1; i < j; i++) {
            for (;; j = (j + 1) % n) {
                ans = max(ans, (poly.p[i] - poly.p[j]).len2());
                if (sign(cross(poly.p[i + 1] - poly.p[i], poly.p[(j + 1) % n] - poly.p[j])) <= 0) break;
            }
        }
        return ans;
    }

    vector<point> id11(vector<point> A, int flag = 1) { 

        int n = A.size(); vector<point> ans(n + n);
        sort(A.begin(), A.end()); int now = -1;
        for (int i = 0; i < A.size(); i++) {
            while (now > 0 && sign(cross(ans[now] - ans[now - 1], A[i] - ans[now - 1])) < flag)
                now--;
            ans[++now] = A[i];
        }
        int pre = now;
        for (int i = n - 2; i >= 0; i--) {
            while (now > pre && sign(cross(ans[now] - ans[now - 1], A[i] - ans[now - 1])) < flag)
                now--;
            ans[++now] = A[i];
        }
        ans.resize(now);
        return ans;
    }
    polygon id0(vector<point> A, int flag = 1) { 

        return polygon(id11(A, flag));
    }
    vector<point> id12(vector<point> A, point k1, point k2) { 

        int n = A.size(); 

        A.push_back(A[0]);
        vector<point> ans;
        for (int i = 0; i < n; i++) {
            int id5 = id2(k1, k2, A[i]);
            int id15 = id2(k1, k2, A[i + 1]);
            if (id5 >= 0) ans.push_back(A[i]);
            if (id5 * id15 <= 0) ans.push_back(getLL(k1, k2, A[i], A[i + 1]));
        }
        return ans;
    }

    vector<line> getHL(vector<line>& L) { 

        sort(L.begin(), L.end());
        deque<line> q;
        for (int i = 0; i < (int)L.size(); ++i) {
            if (i && sameDir(L[i], L[i - 1])) continue;
            while (q.size() > 1 && !checkpos(q[q.size() - 2], q[q.size() - 1], L[i])) q.pop_back();
            while (q.size() > 1 && !checkpos(q[1], q[0], L[i])) q.pop_front();
            q.push_back(L[i]);
        }
        while (q.size() > 2 && !checkpos(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
        while (q.size() > 2 && !checkpos(q[1], q[0], q[q.size() - 1])) q.pop_front();
        vector<line> ans;
        for (int i = 0; i < q.size(); ++i) ans.push_back(q[i]);
        return ans;
    }

    db closestPoint(vector<point>& A, int l, int r) { 

        if (r - l <= 5) {
            db ans = 1e20;
            for (int i = l; i <= r; ++i)
                for (int j = i + 1; j <= r; j++)
                    ans = min(ans, A[i].dis(A[j]));
            return ans;
        }
        int mid = l + r >> 1;
        db ans = min(closestPoint(A, l, mid), closestPoint(A, mid + 1, r));
        vector<point> B;
        for (int i = l; i <= r; i++)
            if (abs(A[i].x - A[mid].x) <= ans)
                B.push_back(A[i]);
        sort(B.begin(), B.end(), [&](const point& k1, const point& k2) {
            return k1.y < k2.y;
            });
        for (int i = 0; i < B.size(); i++)
            for (int j = i + 1; j < B.size() && B[j].y - B[i].y < ans; j++)
                ans = min(ans, B[i].dis(B[j]));
        return ans;
    }
}
using namespace geometry;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<point> p(n);
    vector<point> mid(n), du(n), dv(n);
    vector<db> dis2(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = point(x, y);
        du[i] = p[i].turn90().unit();
        dv[i] = p[i].iturn90().unit();
        mid[i] = (p[i] / 2.0);
        dis2[i] = (1LL * x * x + 1LL * y * y) / 4.0;
    }
    db l = 0, r = 2e5, md;

    auto fork = [&](point p, point q) {
        if (sign(p.x) == sign(q.x) && sign(p.y) == sign(q.y)) return true;
        return false;
    };

    auto check = [&](double r) {
        vector<pair<long double, int>> angle;
        db r2 = r * r;
        int maxc = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            if (cmp(dis2[i], r2) == 1) continue;
            long double len = sqrtl(r2 - dis2[i]);
            point lo = mid[i] + dv[i] * len;
            point hi = mid[i] + du[i] * len;
            if (lo.getP() == 1 && hi.getP() == 0) {
                maxc++, tmp++;
            }
            angle.emplace_back(atan2l(lo.y, lo.x), 1);
            angle.emplace_back(atan2l(hi.y, hi.x), -1);
        }
        sort(angle.begin(), angle.end(), [&](auto& i, auto& j) {
            if (cmp(i.first, j.first) == 0) return i.second > j.second;
            return i.first < j.first;
        });
        for (auto [x, y] : angle) {
            tmp += y;
            maxc = max(maxc, tmp);
        }
        return (maxc >= k);
    };

    for (int times = 60; times; times--) {
        md = (l + r) / 2.0;
        if (check(md)) {
            r = md;
        } else {
            l = md;
        }
    }
    cout << fixed << setprecision(12) << md << "\n";
    return 0;
}
