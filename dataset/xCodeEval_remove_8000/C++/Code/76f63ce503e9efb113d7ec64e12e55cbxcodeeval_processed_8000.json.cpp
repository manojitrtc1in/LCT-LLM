


using namespace __gnu_pbds;
using namespace std;




























const LL inf = 1000000000;
const LL mod = 1000000000 + 7;


inline void IO() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template<typename T>
inline int dcmp (T x) { const T eps = EPS; return x < -eps ? -1 : (x > eps); }


template<class T> inline int CHECK(T MASK, int i) { return (MASK >> i) & 1; }
template<class T> inline T ON(T MASK, int i) { return MASK | (T(1) << i); }
template<class T> inline T OFF(T MASK, int i) { return MASK & (~(T(1) << i)); }
template<typename T> inline int CNT(T MASK) {
    if (numeric_limits<T>::digits <= numeric_limits<unsigned int>::digits) return __builtin_popcount(MASK);
    else return __builtin_popcountll(MASK);
}
template<class T> inline int RIGHT(T MASK) { return log2(MASK & -MASK); }


int dx4[] = { 0, 0, -1, +1 }; int dy4[] = { +1, -1, 0, 0 };
int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1, 0 }; int dy8[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };


inline void I(int& a) { scanf("%d", &a); } inline void I(LL& a) { scanf("%lld", &a); }
inline void I(ULL& a) { scanf("%llu", &a); } inline void I(char* a) { scanf("%s", a); }
char Iarr[S_SIZE]; inline void I(string& a) { scanf("%s", Iarr); a = Iarr; }
inline void I(LD& a) { cin >> a; } inline void I(double& a) { cin >> a; }
inline void I(bool& a) { int aa; I(aa); a = aa; }
template<typename T1, typename T2>
void I(pair<T1, T2>& a) { I(a.ff); I(a.ss); }
template<typename T>
void I(vector<T>& a) { for (int i = 0; i < SZ(a); i++) I(a[i]); }
template<typename T, typename... Args>
void I(T& a, Args&... args) { I(a); I(args...); }


inline void OUT(int a) { printf("%d", a); } inline void OUT(LL a) { printf("%lld", a); }
inline void OUT(const char* a) { printf("%s", a); } inline void OUT(char* a) { printf("%s", a); }
inline void OUT(bool a) { printf("%d", a); } inline void OUT(string a) { rep(it, a.begin(), a.end()) printf("%c", *it); }
inline void OUT(ULL a) { printf("%llu", a); } inline void OUT(char a) { printf("%c", a); }
template<typename T, typename... Args>
void OUT(T a, Args... args) { OUT(a); OUT(" "); OUT(args...); }
template<typename... Args>
void O(Args... args) { OUT(args...); OUT("\n"); }


template<typename T1, typename T2>
inline ostream& operator<<(ostream& os, pair<T1, T2> p) { os << "{" << p.first << ", " << p.second << "}"; return os; }
template<typename T>
inline ostream& operator<<(ostream& os, vector<T>& a) { os << "["; for (int i = 0; i < (int)a.size(); i++) { if (i) os << ", "; os << a[i]; } os << "]"; return os; }



void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t id17 = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + id17); }
};


void faster(auto &unorderedMap, int n) { int num = 2; while (num < n) num *= 2; unorderedMap.reserve(num); unorderedMap.max_load_factor(0.25); }









const int M = 200010; 



template<typename T1, typename T2>
class DirectedGraph
{
    typedef pair<T1, int> ii;
    const T1 INF = numeric_limits<T1>::max();

public:
    int nodes;
    vector<vector<pair<int, T2>>> AdjList;
    vector<T1> dist;
    vector<int> par;
    DirectedGraph(int n)
    {
        nodes = n;
        AdjList.resize(n);
        dist.resize(n);
        par.resize(n);
    }
    void addEdge(int u, int v, T2 c)
    {
        AdjList[u].push_back(make_pair(v, c));
    }
    void dijkstra(int s)
    {
        for (int i = 0; i < nodes; i++) {
            dist[i] = INF;
            par[i] = -1;
        }
        dist[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, s)); 

        while (!pq.empty()) {
            ii top = pq.top(); pq.pop();       

            T1 d = top.first;
            int u = top.second; 

            if (dcmp(d - dist[u]) == 0) {
                for (auto it = AdjList[u].begin(); it != AdjList[u].end(); it++) {
                    int v = it->first; T2 id12 = it->second;
                    if (dcmp(dist[u] + id12 - dist[v]) == -1) {
                        dist[v] = dist[u] + id12;
                        par[v] = u;
                        pq.push(ii(dist[v], v)); 

                    }
                }
            }
        }
    }
    void path(int dest)
    {
        if (par[dest] == -1) {
            printf("-1\n");
            return;
        }
        vector<int> v;
        int curr = dest;
        while (curr != -1) {
            v.pb(curr);
            curr = par[curr];
        }
        reverse(all(v));
        for (int x : v) {
            printf("%d ", x);
        }
        printf("\n");
    }
};





































class PT {
public:
    LD x, y;
    PT() {}
    PT(LD x, LD y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    LD Magnitude() {return sqrt(x*x+y*y);}

    bool operator == (const PT& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const PT& u) const { return !(*this == u); }
    bool operator < (const PT& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const PT& u) const { return u < *this; }
    bool operator <= (const PT& u) const { return *this < u || *this == u; }
    bool operator >= (const PT& u) const { return *this > u || *this == u; }
    PT operator + (const PT& u) const { return PT(x + u.x, y + u.y); }
    PT operator - (const PT& u) const { return PT(x - u.x, y - u.y); }
    PT operator * (const LD u) const { return PT(x * u, y * u); }
    PT operator / (const LD u) const { return PT(x / u, y / u); }
    LD operator * (const PT& u) const { return x*u.y - y*u.x; }
};

LD dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
LD dist2(PT p, PT q)   { return dot(p-q,p-q); }
LD dist(PT p, PT q)   { return sqrt(dist2(p,q)); }
LD cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

LD id28(LD val) {
    if(val>1) return PI*0.5;
    if(val<-1) return -PI*0.5;
    return asin(val);
}

LD id33(LD val) {
    if(val>1) return 0;
    if(val<-1) return PI;
    return acos(val);
}

ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

istream &operator>>(istream &is, PT &p) {
    is >> p.x >> p.y;
    return is;
}



PT id16(PT p)   { return PT(-p.y,p.x); }
PT id31(PT p)    { return PT(p.y,-p.x); }

PT id3(PT p,LD t) {
    return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}

PT id2(PT p,PT pivot,LD t) {
    PT trans=p-pivot;
    PT ret=id3(trans,t);
    ret=ret+pivot;
    return ret;
}





PT id23(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

LD id19(PT a,PT b,PT c) {
    return dist(c,id23(a,b,c));
}



PT id32(PT a, PT b, PT c) {
    LD r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}



LD id0(PT a, PT b, PT c) {
    return sqrt(dist2(c, id32(a, b, c)));
}



LD id4(LD x, LD y, LD z,
                          LD a, LD b, LD c, LD d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}



bool LinesParallel(PT a, PT b, PT c, PT d) {
    return dcmp(cross(b-a, c-d)) == 0;
}

bool id35(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
      && dcmp(cross(a-b, a-c)) == 0
      && dcmp(cross(c-d, c-a)) == 0;
}







bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (id35(a, b, c, d)) {
        if (dcmp(dist2(a, c)) == 0 || dcmp(dist2(a, d)) == 0 ||
            dcmp(dist2(b, c)) == 0 || dcmp(dist2(b, d)) == 0) return true;
        if (dcmp(dot(c-a, c-b)) > 0 && dcmp(dot(d-a, d-b)) > 0 && dcmp(dot(c-b, d-b)) > 0)
            return false;
        return true;
    }
    if (dcmp(cross(d-a, b-a)) * dcmp(cross(c-a, b-a)) > 0) return false;
    if (dcmp(cross(a-c, d-c)) * dcmp(cross(b-c, d-c)) > 0) return false;
    return true;
}









PT id26(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}



PT id40(PT a, PT b, PT c) {
    b=(a+b)/2;
    c=(a+c)/2;
    return id26(b, b+id31(a-b), c, c+id31(a-c));
}

bool id13(PT s, PT e, PT p) {
    if(p == s || p == e)    return 1;
    return dcmp(cross(s-p, s-e)) == 0
        && dcmp(dot(PT(s.x-p.x, s.y-p.y), PT(e.x-p.x, e.y-p.y))) < 0;
}

int id41(vector < PT > p, PT q) {
    int i, j, cnt = 0;
    int n = p.size();
    for(i = 0, j = n-1; i < n; j = i++) {
        if(id13(p[i], p[j], q))
            return 1;
        if(p[i].y > q.y != p[j].y > q.y &&
           q.x < (LD)(p[j].x-p[i].x)*(q.y-p[i].y)/(LD)(p[j].y-p[i].y) + p[i].x)
           cnt++;
    }
    return cnt&1;
}



bool id14(const vector<PT> &p, PT q) {
    for (int i = 0; i < p.size(); i++)
        if (dist2(id32(p[i], p[(i+1)%p.size()], q), q) < EPS)
            return true;
    return false;
}







vector<PT> id5(PT a, PT b, PT c, LD r) {
    vector<PT> ret;
    b = b-a;
    a = a-c;
    LD A = dot(b, b);
    LD B = dot(a, b);
    LD C = dot(a, a) - r*r;
    LD D = B*B - A*C;
    if (D < -EPS) return ret;
        ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}





vector<PT> id18(PT a, PT b, LD r, LD R) {
    vector<PT> ret;
    LD d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    LD x = (d*d-R*R+r*r)/(2*d);
    LD y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + id16(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - id16(v)*y);
    return ret;
}









LD id10(const vector<PT> &p) {
    LD area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

LD ComputeArea(const vector<PT> &p) {
    return fabs(id10(p));
}

LD id29(vector<PT> &vec) {
    int i,n;
    LD ans=0;
    n=vec.size();
    for(i=0;i<n;i++) ans+=vec[i].x*vec[NEX(i)].y-vec[i].y*vec[NEX(i)].x;
    return fabs(ans)*0.5;
}

PT id39(const vector<PT> &p) {
    PT c(0,0);
    LD scale = 6.0 * id10(p);
    for (int i = 0; i < p.size(); i++){
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

LD id42(PT a,PT b,PT c) { 

    PT temp1(a.x-b.x,a.y-b.y),temp2(c.x-b.x,c.y-b.y);
    LD ans=id28((temp1.x*temp2.y-temp1.y*temp2.x)/(temp1.Magnitude()*temp2.Magnitude()));
    if((ans<0&&(temp1.x*temp2.x+temp1.y*temp2.y)<0)||(ans>=0&&(temp1.x*temp2.x+temp1.y*temp2.y)<0))
        ans=PI-ans;
    ans=ans<0?2*PI+ans:ans;
    return ans;
}

LD SignedArea(PT a,PT b,PT c){ 

    PT temp1(b.x-a.x,b.y-a.y),temp2(c.x-a.x,c.y-a.y);
    return 0.5*(temp1.x*temp2.y-temp1.y*temp2.x);
}

bool id6(PT a,PT b) {
    if(abs(a.x-b.x)<EPS) return a.y<b.y;
    return a.x<b.x;
}







void id38(vector<PT>given,vector<PT>&ans){
    int i,n=given.size(),j=0,k=0;
    vector<PT>U,L;
    ans.clear();
    sort(given.begin(),given.end(),id6);
    for(i=0;i<n;i++){
        while(true){
            if(j<2) break;
            if(SignedArea(L[j-2],L[j-1],given[i])<=EPS) j--;
            else break;
        }
        if(j==L.size()){
            L.push_back(given[i]);
            j++;
        }
        else{
            L[j]=given[i];
            j++;
        }
    }
    for(i=n-1;i>=0;i--){
        while(1){
            if(k<2) break;
            if(SignedArea(U[k-2],U[k-1],given[i])<=EPS) k--;
            else break;
        }
        if(k==U.size()){
            U.push_back(given[i]);
            k++;
        }
        else{
            U[k]=given[i];
            k++;
        }
    }
    for(i=0;i<j-1;i++) ans.push_back(L[i]);
    for(i=0;i<k-1;i++) ans.push_back(U[i]);
}

typedef PT Vector;
typedef vector<PT> Polygon;

struct DirLine {
    PT p;
    Vector v;
    LD ang;
    DirLine () {}


    

    DirLine (PT p, PT q) { this->p = p; this->v.x = q.x-p.x; this->v.y = q.y-p.y; ang = atan2(v.y, v.x); }
    bool operator < (const DirLine& u) const { return ang < u.ang; }
};

bool getIntersection (PT p, Vector v, PT q, Vector w, PT& o) {
    if (dcmp(cross(v, w)) == 0) return false;
    Vector u = p - q;
    LD k = cross(w, u) / cross(v, w);
    o = p + v * k;
    return true;
}

bool onLeft(DirLine l, PT p) { return dcmp(l.v * (p-l.p)) >= 0; }

int id11(DirLine* li, int n, vector<PT>& poly) { 

    sort(li, li + n);

    int first, last;
    PT* p = new PT[n];
    DirLine* q = new DirLine[n];
    q[first=last=0] = li[0];

    for (int i = 1; i < n; i++) {
        while (first < last && !onLeft(li[i], p[last-1])) last--;
        while (first < last && !onLeft(li[i], p[first])) first++;
        q[++last] = li[i];

        if (dcmp(q[last].v * q[last-1].v) == 0) {
            last--;
            if (onLeft(q[last], li[i].p)) q[last] = li[i];
        }

        if (first < last)
            getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
    }

    while (first < last && !onLeft(q[first], p[last-1])) last--;
    if (last - first <= 1) { delete [] p; delete [] q; return 0; }
    getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);
    poly.resize(last - first + 1); 

    int m = 0;
    for (int i = first; i <= last; i++) poly[m++] = p[i];
    delete [] p; delete [] q;
    return m;
}




LD id37(PT a, PT b, PT cen, LD r) {
    LD ang = fabs(atan2((a-cen).y, (a-cen).x) - atan2((b-cen).y, (b-cen).x));
    if (ang > PI) ang = 2*PI - ang;
    return (ang * r * r) / 2.0;
}


LD id22(PT a, PT b, PT c, LD radius) {
    vector<PT>g = id5(a, b, c, radius);
    if (b < a) swap(a, b);
    if (g.size() < 2) return id37(a, b, c, radius);
    else {
        PT l = g[0], r = g[1];
        if (r < l) swap(l, r);
        if (b < l || r < a) return id37(a, b, c, radius);
        else if (a < l && b < r) return fabs(SignedArea(c, b, l)) + id37(a, l, c, radius);
        else if (r < b && l < a) return fabs(SignedArea(a, c, r)) + id37(r, b, c, radius);
        else if (a < l && r < b) return fabs(SignedArea(c, l, r)) + id37(a, l, c, radius) + id37(b, r, c, radius);
        else return fabs(SignedArea(a, b, c));
    }
    return 0;
}


LD id20(vector<PT> &p, PT c, LD r) {
    int i, j, k, n = p.size();
    LD sum = 0;
    for (i = 0; i < p.size(); i++) {
        LD temp = id22(p[i], p[(i+1)%n], c, r);
        LD sign = SignedArea(c, p[i], p[(i+1)%n]);
        if (dcmp(sign) == 1) sum += temp;
        else if (dcmp(sign) == -1) sum -= temp;
    }
    return sum;
}



vector<PT> CutPolygon(vector<PT> &u, PT a, PT b) {
    vector<PT> ret;
    int n = u.size();
    for (int i = 0; i < n; i++) {
        PT c = u[i], d = u[(i+1)%n];
        if (dcmp((b-a)*(c-a)) >= 0) ret.push_back(c);
        if (id23(a, b, c) == c || id23(a, b, d) == d) continue;
        if (dcmp((b-a)*(d-c)) != 0) {
            PT t;
            getIntersection(a, b-a, c, d-c, t);
            if (id13(c, d, t))
                ret.push_back(t);
        }
    }
    return ret;
}

typedef pair < PT, PT > seg_t;

vector<PT> tanCP(PT c, LD r, PT p) {
    LD x = dot(p - c, p - c);
    LD d = x - r * r;
    vector<PT> res;
    if (d < -EPS) return res;
    if (d < 0) d = 0;
    PT q1 = (p - c) * (r * r / x);
    PT q2 = id16((p - c) * (-r * sqrt(d) / x));
    res.push_back(c + q1 - q2);
    res.push_back(c + q1 + q2);
    return res;
}


vector<seg_t> tanCC(PT c1, LD r1, PT c2, LD r2) {
    vector<seg_t> res;
    if (fabs(r1 - r2) < EPS) {
    PT dir = c2 - c1;
    dir = id16(dir * (r1 / dir.Magnitude()));
    res.push_back(seg_t(c1 + dir, c2 + dir));
    res.push_back(seg_t(c1 - dir, c2 - dir));
    } else {
    PT p = ((c1 * -r2) + (c2 * r1)) / (r1 - r2);
    vector<PT> ps = tanCP(c1, r1, p), qs = tanCP(c2, r2, p);
    for (int i = 0; i < ps.size() && i < qs.size(); ++i) {
      res.push_back(seg_t(ps[i], qs[i]));
    }
    }
    PT p = ((c1 * r2) + (c2 * r1)) / (r1 + r2);
    vector<PT> ps = tanCP(c1, r1, p), qs = tanCP(c2, r2, p);
    for (int i = 0; i < ps.size() && i < qs.size(); ++i) {
    res.push_back(seg_t(ps[i], qs[i]));
    }
    return res;
}


pair < PT, PT > id15(PT a, PT b, LD d) {
    LD l = dist(a, b);
    PT p = ((id16(b - a) * d) / l) + a;
    return mp(p, p + b - a);
}

void id9(PT A, PT B, LD &a, LD &b, LD &c) {
    a=A.y-B.y; b=B.x-A.x; c=A.x*B.y-A.y*B.x;
}

LD Sector(LD r, LD alpha) {
    return r * r * 0.5 * (alpha - sin(alpha));
}
LD id25(LD r1, LD r2, LD d) {
    if (dcmp(d - r1 - r2) != -1) return 0;
    if (dcmp(d + r1 - r2) != 1) return PI * r1 * r1;
    if (dcmp(d + r2 - r1) != 1) return PI * r2 * r2;
    

    LD ans = Sector(r1, 2 * acos((r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d)));
    ans += Sector(r2, 2 * acos((r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d)));
    return ans;
}



LD id30(vector <PT> &p, PT s, PT t) {
    int n = p.size();
    LD sm = 0;
    for(int i=0;i<n;i++) sm+=p[i]*p[(i+1)%n];
    if(dcmp(sm) == -1)reverse(p.begin(), p.end()); 

    vector< pair<LD,int> >event;
    for(int i=0; i<n; i++) {
        int lef = dcmp(cross(p[i]-s, t-s));
        int rig = dcmp(cross(p[NEX(i)]-s, t-s));
        if(lef == rig) continue;
        LD r = cross(p[NEX(i)]-s, p[NEX(i)]-p[i])/cross(t-s, p[NEX(i)]-p[i]);
        if(lef>rig) event.push_back(make_pair(r,(!lef || !rig ? -1 : -2)));
        else event.push_back(make_pair(r,(!lef || !rig ? 1 : 2)));
    }
    sort(event.begin(),event.end());
    int cnt = 0;
    LD sum = 0,la = 0;
    for(int i=0; i<(int)event.size(); i++) {
        if (cnt>0) sum += event[i].first-la;
        la = event[i].first;
        cnt += event[i].second;
    }
    return sum*(t-s).Magnitude();
}






typedef pair < PT, LD > circle;
bool id27(circle C, PT p) {
    return dcmp(C.second - dist(C.first, p)) >= 0;
}
circle id24(vector < PT > &p, int m, int n) {
    circle D = mp((p[m]+p[n])/2.0, dist(p[m], p[n])/2.0);
    for (int i = 0; i < m; i++)
        if (!id27(D, p[i])) {
            D.first = id40(p[i], p[m], p[n]);
            D.second = dist(D.first, p[i]);
        }
    return D;
}
circle id1(vector < PT > &p, int n) {
    circle D = mp((p[0]+p[n])/2.0, dist(p[0], p[n])/2.0);
    for (int i = 1; i < n; i++)
        if (!id27(D, p[i])) {
            D = id24(p, i, n);
        }
    return D;
}


circle id8(vector < PT > p) {
    srand(time(NULL));
    sort(p.begin(), p.end()); 

    p.resize(distance(p.begin(), unique(p.begin(), p.end()))); 

    random_shuffle(p.begin(), p.end()); 

    if (p.size() == 1) return mp(p[0], 0);
    circle D = mp((p[0]+p[1])/2.0, dist(p[0], p[1])/2.0);
    for (int i = 2; i < p.size(); i++)
        if (!id27(D, p[i])) {
            D = id1(p, i);
        }
    return D;
}








PT polygonCenter;

bool less_comp(PT a, PT b)
{
    if (dcmp(a.x - polygonCenter.x) != -1 && dcmp(b.x - polygonCenter.x) == -1)
        return true;
    if (dcmp(a.x - polygonCenter.x) == -1 && dcmp(b.x - polygonCenter.x) != -1)
        return false;
    if (dcmp(a.x - polygonCenter.x) == 0 && dcmp(b.x - polygonCenter.x) == 0) {
        if (dcmp(a.y - polygonCenter.y) != -1 || dcmp(b.y - polygonCenter.y) != -1)
            return a.y > b.y;
        return b.y > a.y;
    }

    

    LD det = (a.x - polygonCenter.x) * (b.y - polygonCenter.y) - (b.x - polygonCenter.x) * (a.y - polygonCenter.y);
    if (dcmp(det) == -1)
        return true;
    if (dcmp(det) == 1)
        return false;

    

    

    LD d1 = (a.x - polygonCenter.x) * (a.x - polygonCenter.x) + (a.y - polygonCenter.y) * (a.y - polygonCenter.y);
    LD d2 = (b.x - polygonCenter.x) * (b.x - polygonCenter.x) + (b.y - polygonCenter.y) * (b.y - polygonCenter.y);
    return (d1 - d2) == 1; 

    

}





void sortCW(vector<PT>& given)
{
    if ((int)given.size() < 3) return;
    polygonCenter = id8(given).first;
    sort(given.begin(), given.end(), less_comp);
}



void id36(vector<PT>& given)
{
    sortCW(given);
    reverse(given.begin(), given.end());
}



int id7(vector<PT> p1, vector<PT> p2, vector<PT>& poly) 

{
    DirLine d[(int)p1.size()+(int)p2.size()];
    for (int i = 0; i < (int)p1.size(); i++) {
        d[i] = DirLine(p1[i], p1[(i+1)%(int)p1.size()]);
    }
    for (int i = 0; i < (int)p2.size(); i++) {
        d[i+(int)p1.size()] = DirLine(p2[i], p2[(i+1)%(int)p2.size()]);
    }
    int n = id11(d, (int)p1.size() + (int)p2.size(), poly);
    id36(poly); 

    return n;
}







int id21(const vector<PT>& poly, PT p)
{
    int n = (int)poly.size();
    

    if (poly[0] == p) return 0;
    else if (onLeft(DirLine(poly[0], poly[1]), p) && onLeft(DirLine(poly[n-1], poly[0]), p)) return 1;
    

    int low = 1, high = n - 1;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        DirLine d(poly[0], poly[mid]);
        if (onLeft(d, p) || dcmp(id19(poly[0], poly[mid], p)) == 0) {
            high = mid - 1;
        }
        else {
            low = mid;
        }
    }
    

    if (low == 1) {
        if (id13(poly[0], poly[1], p)) return 0;
        else if (onLeft(DirLine(poly[0], poly[1]), p)) return 1;
    }
    

    if (low == n - 1) {
        return 1;
    }
    else if (low == n - 2) {
        if (id13(poly[n-2], poly[n-1], p) || id13(poly[0], poly[n-1], p))
            return 0;
        else if (onLeft(DirLine(poly[n-1], poly[n-2]), p))
            return -1;
        else
            return 1;
    }
    else {
        if (id13(poly[low], poly[low+1], p))
            return 0;
        else if (onLeft(DirLine(poly[low+1], poly[low]), p))
            return -1;
        else
            return 1;
    }
}




int main()
{
    int a, b;
    I(a, b);
    PT A, B;
    I(A.x, A.y, B.x, B.y);
    int n;
    I(n);
    vector<pair<PT, PT>> v;
    v.pb({A, A});
    for (int i = 0; i < n; i++) {
        PT x, y;
        I(x.x, x.y, y.x, y.y);
        v.pb({x, y});
    }
    v.pb({B, B});
    DirectedGraph<LD, LD> G(n + 2);
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < i; j++) {


                double minn = id34;
                vector<double> vv;
                vv.pb(id0(v[i].ff, v[i].ss, v[j].ff));
                vv.pb(id0(v[i].ff, v[i].ss, v[j].ss));
                vv.pb(id0(v[j].ff, v[j].ss, v[i].ff));
                vv.pb(id0(v[j].ff, v[j].ss, v[i].ss));
                for (auto x : vv) {
                    if (dcmp(minn - x) == 1) {
                        minn = x;
                    }
                }
                if (dcmp(minn - a) != 1) {
                    if (i != (n + 1)) minn = a + b;
                    G.addEdge(i, j, minn);
                    G.addEdge(j, i, minn);


                }


        }
    }
    G.dijkstra(0);
    if (G.par[n+1] == -1) {
        O(-1);
    }
    else {
        cout << sp(12) << G.dist[n+1] << "\n";
    }

    return 0;
}

