





using namespace std;





typedef long long ll;
typedef long double ld;
typedef int baby;










    

    

ld pi=3.141592653589793238;
const ll INF = ll(1e18);
ll mo(const ll input, const ll ceil)
{
  return input >= ceil ? input % ceil : input;
}

ld EPS = 1e-7;
const ld PI = acos(-1);
struct PT 
{
    ld x, y;
    PT() {}
    PT(ld x, ld y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (ld c) const { return PT(x * c, y * c); }
    PT operator / (ld c) const { return PT(x / c, y / c); }
};
ld dot(PT p, PT q)  { return p.x * q.x + p.y * q.y; }
ld dist2(PT p, PT q)   { return dot(p - q, p - q); }
ld dist(PT p, PT q)    { return sqrtl(dist2(p, q)); }
ld cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }
ld abs2(PT a)  { return a.x * a.x + a.y * a.y; }
ld abs(PT a)   { return sqrtl(abs2(a)); }
ostream &operator<<(ostream &os, const PT &p) 
{
    return os << "(" << p.x << "," << p.y << ")";
}


PT id5(PT p)    { return PT(-p.y, p.x); }
PT id10(PT p) { return PT(p.y, -p.x); }
PT id1(PT p, ld t) 
{
    return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}




PT id8(PT a, PT b, PT c) 
{
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}


PT id11(PT a, PT b, PT c) 
{
    ld r = dot(b - a, b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a ) * r;
}


ld id0(PT a, PT b, PT c) 
{
    return sqrtl(dist2(c, id11(a, b, c)));
}


ld id2(ld x, ld y, ld z, ld a, ld b, ld c, ld d)
{ 
    return fabs(a * x + b * y + c * z - d) / sqrtl(a * a + b * b + c * c); 
}


bool LinesParallel(PT a, PT b, PT c, PT d)
{ 
    return fabs(cross(b - a, c - d)) < EPS; 
}
bool id13(PT a, PT b, PT c, PT d) 
{
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}




bool SegmentsIntersect(PT a, PT b, PT c, PT d) 
{
    if (id13(a, b, c, d)) 
    {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) 
            return 1;
        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
            return 0;
        return 1;
    }
    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
    return 1;
}








PT id9(PT a, PT b, PT c, PT d) 
{
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b * cross(c, d) / cross(b, d);
}


PT id16(PT a, PT b, PT c) 
{
    b = (a + b) / 2;
    c = (a + c) / 2;
    return id9(b, b + id10(a - b), c, c + id10(a - c));
}














bool id17(const vector<PT> &p, PT q) 
{
    bool c = 0;
    for(int i = 0;i <= p.size() - 1; i++) 
    {
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}


bool id4(const vector<PT> &p, PT q) 
{
    for(int i = 0;i <= p.size() - 1; i++)
    if (dist2(id11(p[i], p[(i + 1) % p.size()], q), q) < EPS)
        return 1;
    return 0;
}




vector<PT> CLIntersection(PT a, PT b, PT c, ld r) 
{
    vector<PT> ret;
    b = b - a;
    a = a - c;
    ld A = dot(b, b);
    ld B = dot(a, b);
    ld C = dot(a, a) - r * r;
    ld D = B * B - A * C;
    if (D < -EPS) return ret;
    ret.pb(c + a + b * (-B + sqrtl(D + EPS)) / A);
    if (D > EPS)
        ret.pb(c + a + b * (-B - sqrtl(D)) / A);
    return ret;
}




vector<PT> CCIntersection(PT a, PT b, ld r, ld R) 
{
    vector<PT> ret;
    ld d = sqrtl(dist2(a, b));
    if (d > r + R || d + min(r, R) < max(r, R)) return ret;
    ld x = (d * d - R * R + r * r) / (2 * d);
    ld y = sqrtl(r * r - x * x);
    PT v = (b - a) / d;
    ret.pb(a + v * x + id5(v)*y);
    if (y > 0)
        ret.pb(a + v * x - id5(v)*y);
    return ret;
}








ld id3(const vector<PT> &p) 
{
    ld area = 0;
    for(int i = 0;i <= p.size() - 1; i++) 
    {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area / 2.0;
}
ld ComputeArea(const vector<PT> &p) 
{
    return fabs(id3(p));
}
PT id15(const vector<PT> &p) 
{
    PT c(0, 0);
    ld scale = 6.0 * id3(p);
    for(int i = 0;i <= p.size() - 1; i++) {
        int j = (i + 1) % p.size();
        c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
    }
    return c / scale;
}


bool IsSimple(const vector<PT> &p) 
{
    for(int i = 0;i <= p.size() - 1; i++) 
    {
        for(int k = i+1;k <= p.size() - 1; k++)
        {
            int j = (i + 1) % p.size();
            int l = (k + 1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return 0;
        }
    }
    return 1;
}
bool id6(PT a, PT v, PT b) { 

    b = b - a;
    if (abs(b.x * v.y - b.y * v.x) < EPS) { 

        if (b.x * v.x >= -EPS && b.y * v.y >= -EPS) 

            return 1;
        return 0;
    }
    return 0;
}
int sign(PT a, PT b, PT c) { return (cross(b - a, c - b) < 0 ? -1 : 1 ); }
ld ArcArea(PT a, PT b, PT c, ld r) 
{
    ld cosa = dot(a - c, b - c) / (abs(a - c) * abs(b - c));
    ld ang = acos(cosa);
    if (ang > 2 * PI) ang = 2 * PI - ang;
    return 0.5 * r * r * ang;
}
ld id7(PT a1, PT a2, PT c, ld r) 
{
    ld ans = 0;
    ld d1 = dist2(a1, c), d2 = dist2(a2, c);
    if (d1 > d2) swap(d1, d2), swap(a1, a2);
    if (d2 <= r * r) 
    {
        ans = 0.5 * abs(cross(a1 - c, a2 - c));
    }
    else if (d1 <= r * r) 
    {
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
    else 
    {
        auto vv = CLIntersection(a1, a2, c, r);
        if (vv.size() <= 1 || dot(a1 - vv[0], a2 - vv[0]) > 0) 
        {
            ans = ArcArea(a1, a2, c, r);
        }
        else 
        {
            if (dist2(a1, vv[1]) < dist2(a1, vv[0]))
                swap(vv[0], vv[1]);
            ans = ArcArea(a1, vv[0], c, r) + ArcArea(a2, vv[1], c, r) + 0.5 * abs(cross(vv[0] - c, vv[1] - c));
        }
    }
    return abs(ans);
}
ld id14(vector<PT> &a, PT c, ld r) { 

    

    int n = a.size();
    if (n <= 2) return 0;
    ld ans = 0;
    for(int i = 0;i <= n - 1; i++)
    ans += id7(a[i], a[(i + 1) % n], c, r) * sign(c, a[i], a[(i + 1) % n]);
    return abs(ans);
}
struct line 
{
    ld a, b, c;
    line() {}
    line(ld A, ld B, ld C) 
    {
        a = A, b = B, c = C;
    }
};
bool areParallel(line l1, line l2) 
{
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}
bool areSame(line l1, line l2) 
{
    return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}
struct Circle : PT 
{
    ld r;
    Circle() {}
    Circle(PT c, ld r) : PT(c.x, c.y),
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





void id12(PT c, ld r1, ld r2, vector<line> & ans) 
{
    ld r = r2 - r1;
    ld z = sqr(c.x) + sqr(c.y);
    ld d = z - sqr(r);
    if (d < -EPS) return;
    d = sqrt(fabs(d));
    line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
    ans.push_back(l);
}


vector<line> id12(Circle a, Circle b) { 

    vector<line> ans; ans.clear();
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2)
            id12(b - a, a.r * i, b.r * j, ans);
    for (int i = 0; i < ans.size(); ++i)
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    vector<line> ret;
    for (int i = 0; i < (int) ans.size(); ++i) 
    {
        bool ok = true;
        for (int j = 0; j < i; ++j)
            if (areSame(ret[j], ans[i])) 
            {
                ok = false;
                break;
            }
        if (ok) ret.push_back(ans[i]);
    }
    return ret;
}


void solve(int tc)
{
    ld n,x,y;
    cin>>n>>x>>y;
    ld mi=xINF,ma=0;
    vector<PT> lol;
    for(ll i=1;i<=n;i++) 
    {
        ld xx,yy;
        cin>>xx>>yy;
        lol.pb({xx,yy});
    }
    lol.pb(lol[0]);
    for(ll i=1;i<=n;i++) 
    {
        mi=min(mi,id0(lol[i-1], lol[i], PT{x,y}));
        ma=max(ma,id0(lol[i], lol[i], PT{x,y}));
    }
    cout<<fixed<<setprecision(12)<<PI*(ma*ma-mi*mi)<<"\n";
}

signed main()
{
    fio
    
    

    

    
    int tt = 1;
    

    for (int i = 0; i < tt; i++)
    {
      solve(i+1);
      

      

    }
    return 0;
}