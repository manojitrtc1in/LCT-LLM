
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define MAX 
const double EPS = 1e-7; 

const double PI = acos(-1.0);

ll gcd (ll a, ll b) {
    if (!b)
        return a;
    else
        return gcd(b, a%b);
}

template <class T>
class Point {
public:
    T x, y;

    Point () { }

    Point (T x, T y) : x(x), y(y) {}

    
    bool operator == (const Point &b) const {
        return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
    }

    
    bool operator < (const Point &b) const {
        return ((x < b.x) or ((x == b.x) and y < b.y));
    }

    

    

    

    

    

    

    T operator ^ (const Point &b) const {
        return (this->x * b.y) - (this->y * b.x); 
    }

    

    

    

    

    T operator * (const Point &b) const {
        return (this->x * b.x) + (this->y * b.y);
    }

    
    Point operator * (T k) const {
        return Point (x*k, y*k);
    }

    Point operator / (T k) const {
        if (k == 0) cout << "Class Point (operador /): divisao por zero" << endl;
        return Point (x/k, y/k);
    }
    
    
    Point operator + (const Point &b) const {
        return Point (x + b.x, y + b.y);
    }

    
    Point operator - (const Point &b) const {
        return Point (x - b.x, y - b.y);
    }

    
    T len2 () const {
        return x*x + y*y;
    }

    
    T len () const {
        return sqrt (x*x + y*y);
    }

    
    T dpp2 (const Point &b) const {
        return ((*this)-b)*((*this)-b);
    }

    
    T dpp (const Point &b) const {
        return ((*this)-b).len();
    }

    
    T relative_proj (Point &b) const {
        return ((*this)*b)/(b.len()*b.len());
    }

    Point norm () const {
        return Point (x/this->len(), y/this->len());
    }

    
    Point perp () const {
        return Point (this->y, -1.0 * this->x);
    }

    

    

    T distToSegment (const Point a, const Point b, Point &c) const {
        

        Point p = *this;
        if (a == b) return p.dpp(a);
        Point ap = Point(p - a), ab = Point(b - a);
        T u = ap.relative_proj(ab);
        if (u < 0.0) u = 0.0;
        if (u > 1.0) u = 1.0;
        c = a + ab * u;
        return p.dpp(c);
    }

    

    Point proj (const Point &v) const {
        return v*((*this)*v);
    }

    
    Point rotaciona (T ang) const {
        T c = cos(ang), s = sin(ang);
        T X = x*c - y*s;
        T Y = x*s + y*c;
        return Point(X,Y);
    }

    
    static T area (vector <Point> v) {
        T area = 0.0;
        for (int i = 0; i < (int)v.size(); i++) 
            area += v[i] ^ v[(i+1)%v.size()];
        return abs(area/2.0);
    }

    
    static vector <Point> convex_hull (vector <Point> p) {
        if (p.size() <= 2) return p;

        int n = p.size(), k = 0;
        vector <Point> H(2*n);

        sort(p.begin(), p.end());

        for (int i = 0; i < n; i++) {
            while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
            H[k++] = p[i];
        }

        for (int i = n-2, t = k+1; i >= 0; i--) {
            while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
            H[k++] = p[i];
        }

        H.resize(k-1);

        return H;
    }
    

    
    static T inter (Point p1, Point v1, Point p2, Point v2) {
        if (abs(v2 ^ v1) >= EPS) {
            Point c = p1 - p2;
            return (c ^ v2)/(v2 ^v1);
        } else {
            cout << "Class Point (funcao inter): retas paralelas" << endl;
            cout << "Talvez deva ajustar o EPS" << endl;
        }
        return 0.0;
    }

    
    static bool inside(const vector<Point> &v, const Point &p) {
        

        int n = v.size();

        if(n < 3)
            return false;
    
        

        if(((v[1]-v[0])^(p-v[0])) <= 0)
            return false;

        int bot = 2, top = n-1;
        int ans = -1;
        while(bot <= top) {
            int mid = (bot+top)>>1;

            

            if(((v[mid]-v[0])^(p-v[0])) < 0) {
                ans = mid;
                top = mid-1;
            } else {
                bot = mid+1;
            }
        }

        if(ans == -1)
            return false;

        

        if(((v[ans]-v[ans-1])^(p-v[ans-1])) <= 0)
            return false;

        return true;
    }

    
    static vector <Point> minRetangulo (vector <Point> v) {
        vector <Point> at;
        at.pb(Point(-1e18, -1e18));
        at.pb(Point(1e18, -1e18));
        at.pb(Point(1e18, 1e18));
        at.pb(Point(-1e18, 1e18));
        v = convex_hull(v);
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int j = (i+1)%n;
            Point vec = v[j] - v[i];
            T ang = atan2(vec.y, vec.x);
            vector <Point> ve;
            for (int j = 0; j < n; j++) {
                ve.pb(v[j].rotaciona(ang));
            }
            T minx, miny, maxx, maxy;

            minx = miny = numeric_limits<T>::max();
            maxx = maxy = numeric_limits<T>::min();

            for (int j = 0; j < n; j++) {
                if (ve[j].x < minx) minx = ve[j].x;
                if (ve[j].x > maxx) maxx = ve[j].x;
                if (ve[j].y < miny) miny = ve[j].y;
                if (ve[j].y > maxy) maxy = ve[j].y;
            }
            T mini = min(maxx - minx, maxy - miny);
            if (mini < min(at[2].x - at[0].x, at[2].y - at[0].y)) {
                at.clear();
                at.pb(Point(minx, miny));
                at.pb(Point(maxx, miny));
                at.pb(Point(maxx, maxy));
                at.pb(Point(minx, maxy));
            }
        }

        return at;
    }

    

    

    static T max_dist (vector <Point> p) {
        T ret = 0;
        p = Point::convex_hull(p);

        int n = p.size();
        if (n <= 1)
            return 0;
        if (n == 2)
            return p[0].dpp(p[1]);

        int at = 1;
        for (int i = 0; i < n; i++) {
            int j = (i + 1)%n;

            Point v = p[j] - p[i];
            int nxt = (at + 1)%n;
            while (nxt != i and (v^(p[nxt]-p[i])) >= (v^(p[at]-p[i]))) {
                at = nxt;
                nxt = (at + 1)%n;
            }

            ret = max (ret, max (p[i].dpp(p[at]), p[j].dpp(p[at])));
        }

        return ret;
    }



    static bool compy (const Point &a, const Point &b) {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }

    static void min_dist (const Point &p, const vector <Point> &v, int i, T &d) {
        while (i < (int)v.size() and v[i].y - p.y < d) {
            d = min (d, p.dpp(v[i]));
            i++;
        }
    }

    

    static vector <Point> min_dist (const vector <Point> &p, int l, int r, T &d) {
        vector <Point> ret;
        if (l == r) {
            ret.pb(p[l]);
            return ret;
        }
        int mid = (l + r)>>1;

        vector <Point> L = min_dist (p, l, mid, d);
        vector <Point> R = min_dist (p, mid + 1, r, d);

        vector <Point> vl, vr;
        for (auto it : L) 
            if (p[mid].x - it.x < d)
                vl.pb(it);

        for (auto it : R) 
            if (it.x - p[mid + 1].x < d)
                vr.pb(it);

        int i = 0, j = 0;

        while (i < (int)vl.size() and j < (int)vr.size()) {
            if (vl[i].y < vr[j].y) {
                min_dist (vl[i], vr, j, d);
                i++;
            } else {
                min_dist (vr[j], vl, i, d);
                j++;
            }
        }

        ret.resize(r - l + 1);
        merge (L.begin(), L.end(), R.begin(), R.end(),
                ret.begin(), compy);
        return ret;
    }

    

    static T min_dist (vector <Point> p) {
        if (p.size() <= 1)  return 0.0;
        sort (p.begin(), p.end());

        T dist = p[0].dpp(p[1]);
        min_dist (p, 0, p.size() - 1, dist);
        return dist;
    }





    

    static T max_ab (const vector <Point> &p, int bot, int top, const Point &ab) {
        if (bot > top)  return -1e18;
        T ret = max (ab*p[bot], ab*p[top]);
        top--;

        while (bot <= top) {
            int mid = (bot + top)>>1;

            ret = max (ret, max(p[mid]*ab, p[mid+1]*ab));

            if (p[mid]*ab > p[mid+1]*ab) {
                top = mid - 1;
            } else {
                bot = mid + 1;
            }
        }

        return ret;
    }

    static T max_ab (const vector <Point> &p, const Point &ab) {
        int n = p.size();

        if (n < 10) {
            T ret = ab*p[0];
            for (int i = 1; i <= n; i++)
                ret = max(ret, ab*p[i]);
            return ret;
        }

        Point perp = ab.perp();

        int split = 0;
        int bot = 0, top = n - 1;

        T dir = perp^(p[1]-p[0]);
        if (!dir) {
            bot = 1;
            dir = perp^(p[2]-p[0]);
        }

        if (dir > 0)
            dir = 1;
        else 
            dir = -1;

        

        while (bot <= top) {
            int mid = (bot + top)>>1;

            if ((perp^(p[mid]-p[0])) * dir > 0) {
                bot = mid + 1;
                split = mid;
            } else {
                top = mid - 1;
            }
        }

        return max (max_ab(p, 0, split, ab), max_ab(p, split + 1, n, ab));
    }

    

    

    static vector <T> max_ab (vector <Point> p, const vector <Point> &ab) {
        

        p = Point::convex_hull(p);
        vector <T> ans(ab.size());

        int n = ab.size();
        for (int i = 0; i < n; i++) 
            ans[i] = max_ab(p, ab[i]);

        return ans;
    }


    
    static ll pick_theorem(const vector<Point> &p) {
        int n = p.size();
        ll A = 0, b = 0;

        for(int i = 0; i < n; i++) {
            int j = (i+1)%n;
            A += p[i]^p[j];

            ll xx = abs(p[j].x - p[i].x);
            ll yy = abs(p[j].y - p[i].y);

            b += gcd(xx, yy);
        }

        if(A < 0)   A *= -1;
        A>>=1;

        ll ans = A - (b>>1) + 1;
        return ans;
    }
};

template <class T>
ostream &operator<<(ostream &os, Point<T> const &p) {
    return os << p.x << " " << p.y;
}

template <class T>
class Circle {
public:
    Point<T> c;
    T r;

    Circle () {}

    Circle (const Point<T> &c, T r) : c(c), r(r) {}

    
    vector <Point<T> > intersect (Circle b) {
        vector <Point<T> > ret;
        Point<T> c1 = this->c, c2 = b.c;
        T r1 = this->r, r2 = b.r;

        if (c1 == c2) return ret;

        T d = c1.dpp(c2);
        
        if (d > r1 + r2 + EPS) return ret;
        if (d + EPS < abs(r1 - r2)) return ret;

        T a = (r1*r1 - r2*r2 + d*d)/(2.0*d);
        T h = sqrt(max(0.0, r1*r1 - a*a));

        Point<T> pc = c1 + ((c2 - c1)*a)/d;

        
        T x = pc.x - ((h*(c2.y - c1.y))/d);
        T y = pc.y + ((h*(c2.x - c1.x))/d);
        ret.pb(Point<T>(x,y));

        x = pc.x + ((h*(c2.y - c1.y))/d);
        y = pc.y - ((h*(c2.x - c1.x))/d);
        ret.pb(Point<T>(x,y));

        return ret;
    }

    

    static Circle circumcircle (const Point<T> &a, const Point<T> &b, const Point<T> &c) {
        Point<T> ab = b - a, bc = c - b;
        Point<T> mab = a + ab * 0.5;
        Point<T> mbc = b + bc * 0.5;

        T a1 = ab.x, b1 = ab.y;
        T c1 = -a1 * mab.x - b1 * mab.y;
        
        T a2 = bc.x, b2 = bc.y;
        T c2 = -a2 * mbc.x - b2 * mbc.y;
        
        T den = a1 * b2 - a2 * b1;

        T x = (-c1 * b2 + b1 * c2)/den;
        T y = (-c2 * a1 + a2 * c1)/den;
        
        Point<T> center(x, y);
        return Circle(center, (a-center).len());
    }

    

    

    

    

    

    static Circle cover (vector <Point<T> > p, vector <Point<T> > border = vector <Point<T> >()) {
        random_shuffle(p.begin(), p.end());

        Circle res;
        if (border.size() == 0) 
            res = Circle(p[0], 0.0);
        else if (border.size() == 1) 
            res = Circle(border[0], 0.0);
        else if (border.size() == 2)
            res = Circle((border[0] + border[1])*0.5, (border[0].dpp(border[1]))/2.0);
        else 
            return circumcircle (border[0], border[1], border[2]);

        vector <Point<T> > p2;
        for (auto pt : p) {
            if (res.c.dpp(pt) > res.r) {
                border.pb(pt);
                res = cover (p2, border);
                border.pop_back();
            }
            p2.pb(pt);
        }

        return res;
    }
};


template <class T>
T getAreaTriangle (T a, T b, T c) {
    T p = (a + b + c)/2.0;
    return sqrt (p * (p - a) * (p - b) * (p - c));
}
vector<Point<double > > v; 

int n;
bool check(double m,Point<double> p0)
{
    vector<Point<double > > foi,fora;
    for(int i=0;i<n;i++)
    {
        Point<double> at = v[i];
        if(abs((at.y - p0.y) - 1LL*m*(at.x-p0.x)) < EPS)
        {
            foi.pb(at);
        }
        else
            fora.pb(at);
    }   
    

    if(foi.size() == n)
        return false;
    if(foi.size() == n-1)
        return true;
    Point<double> pp0 = fora[0];
   

    for(int i=1;i<fora.size();i++)
    {
        Point<double> at = fora[i];
        

        

        if(fabs((double)(at.y-pp0.y)/(double)(at.x-pp0.x) - m) > EPS)
        {
           

            return false;
        }
    }
    return true;
}

int main()
{   
    fastcin;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        long double a;
        cin >> a;
        Point<double> aux;
        aux.x = i+1;
        aux.y = a;
        v.pb(aux);
    }
    
    if(check(1.0*(v[1].y-v[0].y),v[0]) or check(0.5*(v[2].y-v[0].y),v[0]) or check(1.0*(v[2].y-v[1].y),v[1]))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}