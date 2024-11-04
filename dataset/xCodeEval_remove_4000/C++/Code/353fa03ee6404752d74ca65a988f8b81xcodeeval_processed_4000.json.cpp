














using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;















const int MOD = 1e9+7;
const int INF = 1e9;
const int base = 1e9;
const int MAX = 2e5;
const double EPS = 1e-10;
const double PI = acos(-1.);

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {};
    point operator-(const point& p)const
    {
        return point (x - p.x, y - p.y);
    }
    point operator+(const point& p)const
    {
        return point (x + p.x, y + p.y);
    }
    double operator*(const point & p) const
    {
        return x * p.y - y * p.x;
    }
    point operator*(double k) const
    {
        return point(k * x, k * y);
    }
    double d2() const
    {
        return x * x + y * y;
    }
    double len() const
    {
        return sqrt(d2());
    }
    bool operator==(const point & p) const
    {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }
    bool operator<(const point & p) const
    {
        if (abs(x - p.x) > EPS)return x < p.x;
        if (abs(y - p.y) > EPS)return y < p.y;
        return 0;
    }
    point rotate(double cosx, double sinx) const 

    {
        double xx = x * cosx - y * sinx;
        double yy = x * sinx + y * cosx;
        return point(xx, yy);
    }
    point rotate(double ang) const 

    {
        return rotate(cos(ang), sin(ang));
    }
    point scale(double l) const 

    {
        l /= len();
        return point(l * x, l * y);
    }
    double dot(const point& p) const
    {
        return x * p.x + y * p.y;
    }
    double polar() const 

    {
        double ang = atan2(y, x);
        

        return ang;
    }
    int hp() const 

    {
        return y < -EPS || (abs(y) < EPS && x < -EPS);
    }
};
bool cmpVec(const point& p, const point& q) 

{
    if (p.hp() != q.hp())
        return p.hp() < q.hp();
    return p * q > EPS;
}
int sign(double x)
{
    if (abs(x) < EPS)return 0;
    return x > 0 ? 1 : -1;
}
struct line
{
    point n;
    double c;
    line() {}
    line(double a, double b, double c)
    {
        n = point(a, b);
        this->c = c;
    }
    line(point a, point b) 

    {
        double A = b.y - a.y;
        double B = a.x - b.x;
        double C = -a.x * A - a.y * B;
        n = point(A, B);
        c = C;
    }
    double dist(const point & p) const 

    {
        return (n.dot(p) + c) / n.len();
    }
    point clothestPoint(const point& p) const
    {
        return p + n.scale(-dist(p));
    }
    bool paralel(const line& l) const
    {
        return abs(n * l.n) < EPS;
    }
    point intersect(const line &l) const
    {
        

        double z = n * l.n;
        double x = - (c * l.n.y - n.y * l.c) / z;
        double y = - (n.x * l.c - c * l.n.x) / z;
        return point(x, y);
    }
};
struct segment
{
    point a, b;
    segment() {}
    segment(point a, point b)
    {
        this -> a = a;
        this -> b = b;
    }
    line getLine() const
    {
        return line(a, b);
    }
    bool contains(const point& p) const
    {
        return abs((a - b).len() - (a - p).len() - (b - p).len())
            < EPS;
    }
    bool intersect(const segment& s) const
    {
        if (min(s.a.x, s.b.x) > max(a.x, b.x))return false;
        if (min(s.a.y, s.b.y) > max(a.y, b.y))return false;
        if (max(s.a.x, s.b.x) < min(a.x, b.x))return false;
        if (max(s.a.y, s.b.y) < min(a.y, b.y))return false;
        ll s1 = sign((a - s.a) * (b - s.a));
        ll s2 = sign((a - s.b) * (b - s.b));
        ll s3 = sign((s.a - a) * (s.b - a));
        ll s4 = sign((s.a - b) * (s.b - b));
        return s1 * s2 <= 0 && s3 * s4 <= 0;
    }
    double dist(const point& p) const 

    {
        point q = getLine().clothestPoint(p);
        if (contains(q))return (p-q).len();
        return min((a-p).len(), (b-p).len());
    }
    double dist(const segment& s) const
    {
        if (intersect(s))return 0;
        double ans = min(dist(s.a), dist(s.b));
        ans = min(ans, s.dist(a));
        ans = min(ans, s.dist(b));
        return ans;
    }
};
bool triangleContains(const point& a, const point& b, const point&
c, const point& p)
{
    int s1 = sign((b - a) * (p - a));
    int s2 = sign((c - b) * (p - b));
    int s3 = sign((a - c) * (p - c));
    return (s1 >= 0 && s2 >= 0 && s3 >= 0) || (s1 <= 0 && s2 <= 0
        && s3 <= 0);
}
struct polygon
{
    vector<point> p;
    polygon() {}
    polygon(const vector<point> &a)
    {
        p = a;
        if (SZ(a))p.pb(a[0]);
    }
    int sz() const
    {
        return max(SZ(p) - 1, 0);
    }
    polygon convex() const 

    {
        vector<point> pp = p;
        if (SZ(pp))pp.pop_back();
        sort(ALL(pp));
        vector<point> U, D;
        FOR(i, 0, SZ(pp))
        {
            while(SZ(D) > 1 && sign((D.back() - D[SZ(D) - 2]) *
                (pp[i] - D[SZ(D) - 2])) <= 0)D.pop_back();
            while(SZ(U) > 1 && sign((U.back() - U[SZ(U) - 2]) *
                (pp[i] - U[SZ(U) - 2])) >= 0)U.pop_back();
            U.pb(pp[i]);
            D.pb(pp[i]);
        }
        reverse(ALL(U));
        FOR(i, 1, SZ(U)-1)
            D.pb(U[i]);
        return polygon(D);
    }
    

    bool contains(const point& x) const
    {
        double MX = sqrt(3) * PI / 47.7 + 123.23424;
        double MY = sqrt(2) * acos(0.47747) + 4 * PI;
        point v = point(MX, MY).scale(1e8); 

        segment S = segment(x, v);
        int cnt = 0;
        FOR(i, 0, SZ(p)-1)
        {
            segment seg = segment(p[i], p[i+1]);
            if (seg.contains(x))return 1;
            if (seg.intersect(S))cnt++;
        }
        return cnt % 2;
    }
    

    

    

    bool contains2(const point& q) const
    {
        if (!sz())return false;
        if (sz() == 1)return p[0] == q;
        int l = 1, r = sz()-1;
        int s1 = sign((p[l] - p[0]) * (q - p[0]));
        int s2 = sign((p[r] - p[0]) * (q - p[0]));
        if (s1 == -1)return 0;
        if (s2 == 1)return 0;
        while(r - l > 1)
        {
            int m = (l + r) / 2;
            int s = sign((p[m] - p[0]) * (q - p[0]));
            if (s <= 0)r = m;
            else l = m;
        }
        return triangleContains(p[0], p[l], p[r], q);
    }
    int _minVertex() const
    {
        

        int id = 0;
        FOR(i, 1, sz())
            if (p[i].y < p[id].y || (p[i].y == p[id].y && p[i].x <
                p[id].x))
                id = i;
        return id;
    }
    

    polygon minkowskySum(const polygon& a) const
    {
        int i = _minVertex();
        int j = a._minVertex();
        int n = sz(), m = a.sz();
        vector<point> res;
        if (sz() == 0 || a.sz() == 0)return res;
        int ci = 0, cj = 0;
        while(ci < n || cj < m)
        {
            res.pb(p[i] + a.p[j]);
            int ii = i == n - 1 ? 0 : i + 1;
            int jj = j == m - 1 ? 0 : j + 1;
            if (ci == n)
            {
                j = jj, cj++;
                continue;
            }
            if (cj == m)
            {
                i = ii, ci++;
                continue;
            }
            if (cmpVec(p[ii] - p[i], a.p[jj] - a.p[j]))i = ii,
                    ci++;
            else j = jj, cj++;
        }
        return res;
    }
    

    

    

    

    bool _visible(int idx, const point& x) const
    {
        if (idx >= sz())idx -= sz();
        return (p[idx] - x) * (p[idx+1] - x) < 0; 

    }
    int _findOppositeToFirst(const point& x) const
    {
        int v = _visible(0, x);
        int l = 1, r = sz() - 1;
        int s1 = sign((p[l] - x) * (p[0] - x));
        int s2 = sign((p[r] - x) * (p[0] - x));
        if (s1 * s2 >= 0)
        {
            if (_visible(l, x) != v)return l;
            if (_visible(r, x) != v)return r;
            if (_visible(l + 1, x) != v)return l + 1;
            if (_visible(r - 1, x) != v)return r - 1;
            return -1;
        }
        while(r - l > 1)
        {
            int m = (l + r) / 2;
            if (sign((p[m] - x) * (p[0] - x)) == s1)l = m;
            else r = m;
        }
        if (_visible(l, x) == v)return -1;
        return l;
    }
    int _findChangePoint(int l, int r, const point& x) const
    {
        int v = _visible(l, x);
        while(r - l > 1)
        {
            int m = (l + r) / 2;
            if (_visible(m, x) == v)l = m;
            else r = m;
        }
        return l;
    }
    

    

    

        ii findTangents(const point& x) const
    {
        int l = 0;
        int r = _findOppositeToFirst(x);
        if (r == -1) return mp(-1, -1);
        int p1 = _findChangePoint(l, r, x);
        int p2 = _findChangePoint(r, l + sz(), x);
        if (p2 >= sz())p2 -= sz();
        if (_visible(l, x))
            swap(p2, p1);
        p1++; p2++;
        if (p1 >= sz())p1 -= sz();
        if (p2 >= sz())p2 -= sz();
        return mp(p1, p2);
    }
};
struct circle
{
    point O;
    double r;
    circle() {}
    circle(point O, double r)
    {
        this->O = O;
        this->r = r;
    }
    vector<point> intersect(const line& l) const
    {
        vector<point> ans;
        double d = l.dist(O);
        if (abs(d) > r + EPS)return ans;
        double cosx = r < EPS ? 1.0 : min(1.0, max(-1.0, -d/r));
        double sinx = sqrt(max(0.0, 1.0 - cosx * cosx));
        ans.pb(O + l.n.rotate(cosx, sinx).scale(r));
        if (abs(sinx) > EPS)ans.pb(O + l.n.rotate(cosx, -
                sinx).scale(r));
        return ans;
    }
    vector<point> intersect(const circle& c) const
    {
        point P = c.O - O;
        double A = -2.0 * P.x;
        double B = -2.0 * P.y;
        double C = P.d2() + r * r - c.r * c.r;
        line l = line(A, B, C);
        vector<point> ans = circle(point(), r).intersect(l);
        FOR(i, 0, SZ(ans))
            ans[i] = ans[i] + O;
        return ans;
    }
    vector<line> tangents(const point& p) const
    {
        point v = p - O;
        vector<line> ans;
        double d = v.len();
        if (d < r + EPS)return ans;
        double cosx = r/d;
        double sinx = sqrt(max(0.0, 1.0 - cosx * cosx));
        point p1 = O + v.rotate(cosx, sinx).scale(r);
        point p2 = O + v.rotate(cosx, -sinx).scale(r);
        ans.pb(line(p, p1));
        if (!(p2 == p1))ans.pb(line(p, p2));
        return ans;
    }
    void _add_tan(const point& c, double r1, double r2,
                  vector<line>& res) const
    {
        double rr = r2 - r1;
        double z = c.d2();
        double d = z - rr * rr;
        if (d < -EPS)return ;
        d = sqrt(abs(d));
        double a = (c.x * rr + c.y * d) / z;
        double b = (c.y * rr - c.x * d) / z;
        res.pb(line(a, b, r1 - a * O.x - b * O.y));
    }
    vector<line> common_tangents(const circle& C) const
    {
        vector<line> ans;
        if (O == C.O)return ans;
        point OO = C.O - O;
        _add_tan(OO, -r, -C.r, ans);
        _add_tan(OO, -r, C.r, ans);
        _add_tan(OO, r, -C.r, ans);
        _add_tan(OO, r, C.r, ans);
        return ans;
    }
    double distOnCircle(const point& p1, const point& p2) const
    {
        

        double a1 = (p1 - O).polar();
        double a2 = (p2 - O).polar();
        if(a1 > a2) swap(a1,a2);
        return min(a2 - a1, 2 * PI - (a2 - a1)) * r;
    }
    bool contains(const point& p) const
    {
        return (O-p).d2() < r * r + EPS;
    }
};


int n;
vector<segment> foo;
int gcd(int x, int y)
{
	if (!x)
		return y;
	return gcd(y%x, x);
}

ll f(segment x)
{
	x.a = x.a - x.b;
	x.a.x = abs(x.a.x);
	x.a.y = abs(x.a.y);
	return gcd(x.a.x, x.a.y)+1;
}

int main()
{
	

	ios_base::sync_with_stdio(0);
	cin >> n;
	FOR(i,0,n)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		foo.pb(segment(point(a, b), point(c,d)));
	}

	ll ans = 0;
	map<ii, vector<int> > M;
	FOR(i,0,n)
	{
		ans += f(foo[i]);
		FOR(j, 0, i)
		{
			if (foo[i].intersect(foo[j]))
			{
				line x1(foo[i].a, foo[i].b);
				line x2(foo[j].a, foo[j].b);

				point cur = x1.intersect(x2);
				double a = cur.x;
				if (cur.x < 0)
				{
					a -= (int)(cur.x-0.05);
				} else
				{
					a -= (int)(cur.x+0.05);
				}
				double b = cur.y;
				if (cur.y < 0)
				{
					b -= (int)(cur.y-0.05);
				} else
				{
					b -= (int)(cur.y+0.05);
				}
				if (abs(a) < EPS && abs(b) < EPS)
				{
					int a, b;
					if (cur.x < 0)
					{
						a = (int)(cur.x-0.05);
					} else
					{
						a = (int)(cur.x+0.05);
					}
					if (cur.y < 0)
					{
						b = (int)(cur.y-0.05);
					} else
					{
						b = (int)(cur.y+0.05);
					}

					M[mp(a, b)].pb(i);
					M[mp(a, b)].pb(j);
				}
			}
		}
	}
	

	for (auto &iter : M)
	{
		sort(ALL(iter.s));
		ans -= unique(ALL(iter.s))-iter.s.begin()-1;
	}
	cout << ans << endl;







	return 0;
}
