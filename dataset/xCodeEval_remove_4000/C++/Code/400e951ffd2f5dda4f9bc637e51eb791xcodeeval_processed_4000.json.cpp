
using namespace std;

typedef long long int LL;
typedef long double LD;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};
















const LD PI=acos(-1.0);

inline int dcmp (LD x) { return x < -EPS ? -1 : (x > EPS); }



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

LD id15(LD val) {
    if(val>1) return PI*0.5;
    if(val<-1) return -PI*0.5;
    return asin(val);
}

LD id19(LD val) {
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



PT id10(PT p)   { return PT(-p.y,p.x); }
PT id17(PT p)    { return PT(p.y,-p.x); }

PT id2(PT p,LD t) {
    return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}

PT id1(PT p,PT pivot,LD t) {
    PT trans=p-pivot;
    PT ret=id2(trans,t);
    ret=ret+pivot;
    return ret;
}





PT id13(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

LD id12(PT a,PT b,PT c) {
    return dist(c,id13(a,b,c));
}



PT id18(PT a, PT b, PT c) {
    LD r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}



LD id0(PT a, PT b, PT c) {
    return sqrt(dist2(c, id18(a, b, c)));
}



LD id3(LD x, LD y, LD z,
                          LD a, LD b, LD c, LD d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}



bool LinesParallel(PT a, PT b, PT c, PT d) {
    return dcmp(cross(b-a, c-d)) == 0;
}

bool id20(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
      && dcmp(cross(a-b, a-c)) == 0
      && dcmp(cross(c-d, c-a)) == 0;
}







bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (id20(a, b, c, d)) {
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









PT id14(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}



PT id23(PT a, PT b, PT c) {
    b=(a+b)/2;
    c=(a+c)/2;
    return id14(b, b+id17(a-b), c, c+id17(a-c));
}

bool id8(PT s, PT e, PT p) {
    if(p == s || p == e)    return 1;
    return dcmp(cross(s-p, s-e)) == 0
        && dcmp(dot(PT(s.x-p.x, s.y-p.y), PT(e.x-p.x, e.y-p.y))) < 0;
}

int id24(vector < PT > p, PT q) {
    int i, j, cnt = 0;
    int n = p.size();
    for(i = 0, j = n-1; i < n; j = i++) {
        if(id8(p[i], p[j], q))
            return 1;
        if(p[i].y > q.y != p[j].y > q.y &&
           q.x < (LD)(p[j].x-p[i].x)*(q.y-p[i].y)/(LD)(p[j].y-p[i].y) + p[i].x)
           cnt++;
    }
    return cnt&1;
}



bool id9(const vector<PT> &p, PT q) {
    for (int i = 0; i < p.size(); i++)
        if (dist2(id18(p[i], p[(i+1)%p.size()], q), q) < EPS)
            return true;
    return false;
}







vector<PT> id4(PT a, PT b, PT c, LD r) {
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





vector<PT> id11(PT a, PT b, LD r, LD R) {
    vector<PT> ret;
    LD d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    LD x = (d*d-R*R+r*r)/(2*d);
    LD y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + id10(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - id10(v)*y);
    return ret;
}









LD id6(const vector<PT> &p) {
    LD area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

LD ComputeArea(const vector<PT> &p) {
    return fabs(id6(p));
}

LD id16(vector<PT> &vec) {
    int i,n;
    LD ans=0;
    n=vec.size();
    for(i=0;i<n;i++) ans+=vec[i].x*vec[NEX(i)].y-vec[i].y*vec[NEX(i)].x;
    return fabs(ans)*0.5;
}

PT id22(const vector<PT> &p) {
    PT c(0,0);
    LD scale = 6.0 * id6(p);
    for (int i = 0; i < p.size(); i++){
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

LD id25(PT a,PT b,PT c) { 

    PT temp1(a.x-b.x,a.y-b.y),temp2(c.x-b.x,c.y-b.y);
    LD ans=id15((temp1.x*temp2.y-temp1.y*temp2.x)/(temp1.Magnitude()*temp2.Magnitude()));
    if((ans<0&&(temp1.x*temp2.x+temp1.y*temp2.y)<0)||(ans>=0&&(temp1.x*temp2.x+temp1.y*temp2.y)<0))
        ans=PI-ans;
    ans=ans<0?2*PI+ans:ans;
    return ans;
}

LD SignedArea(PT a,PT b,PT c){ 

    PT temp1(b.x-a.x,b.y-a.y),temp2(c.x-a.x,c.y-a.y);
    return 0.5*(temp1.x*temp2.y-temp1.y*temp2.x);
}

bool id5(PT a,PT b) {
    if(abs(a.x-b.x)<EPS) return a.y<b.y;
    return a.x<b.x;
}







void id21(vector<PT>given,vector<PT>&ans){
    int i,n=given.size(),j=0,k=0;
    vector<PT>U,L;
    ans.clear();
    sort(given.begin(),given.end(),id5);
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

int id7(DirLine* li, int n, vector<PT>& poly) { 

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




int main()
{
    LD w, h, a;
    cin >> w >> h >> a;
    PT arr[4], arr2[4];
    arr[0].x = arr2[0].x = -w / 2;
    arr[0].y = arr2[0].y = -h / 2;
    arr[1].x = arr2[1].x = w / 2;
    arr[1].y = arr2[1].y = -h / 2;
    arr[2].x = arr2[2].x = w / 2;
    arr[2].y = arr2[2].y = h / 2;
    arr[3].x = arr2[3].x = -w / 2;
    arr[3].y = arr2[3].y = h / 2;
    for (int i = 0; i < 4; i++) {
        arr2[i] = id2(arr2[i], (LD)RAD(a));
    }
    DirLine d[8];
    for (int i = 0; i < 4; i++) {
        d[i] = DirLine(arr[i], arr[(i+1)%4]);
    }
    for (int i = 0; i < 4; i++) {
        d[i+4] = DirLine(arr2[i], arr2[(i+1)%4]);
    }
    vector<PT> v;
    int n = id7(d, 8, v);
    LD res = ComputeArea(v);
    cout << setprecision(12) << fixed << res << endl;

    return 0;
}
