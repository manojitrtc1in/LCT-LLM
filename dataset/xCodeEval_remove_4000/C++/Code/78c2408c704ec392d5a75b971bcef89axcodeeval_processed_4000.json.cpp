


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef std::string str;


























const ld PI = 3.141592653589793238462643383279;
const ll inf = std::numeric_limits<ll>::max();
const int infint = std::numeric_limits<int>::max();
const ll mod = 1e9+7;
using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef ld ft; 

typedef pair<ft,ft> pff;

int sgn(ft val){
    return val > 0 ? 1 : (val == 0 ? 0 : -1);
}




struct pt { 

    ft x, y;
    pt() {}
    pt(ft x, ft y): x(x), y(y) {}
    pt& operator+=(const pt &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    pt& operator-=(const pt &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    pt& operator+=(const ft &t) {
        x += t;
        y += t;
        return *this;
    }
    pt& operator-=(const ft &t) {
        x -= t;
        y -= t;
        return *this;
    }
    pt& operator*=(ft t) {
        x *= t;
        y *= t;
        return *this;
    }
    pt& operator/=(ft t) {
        x /= t;
        y /= t;
        return *this;
    }
    pt operator+(const pt &t) const {
        return pt(*this) += t;
    }
    pt operator-(const pt &t) const {
        return pt(*this) -= t;
    }
    pt operator+(const ft &t) const {
        return pt(*this) += t;
    }
    pt operator-(const ft &t) const {
        return pt(*this) -= t;
    }
    pt operator*(ft t) const {
        return pt(*this) *= t;
    }
    pt operator/(ft t) const {
        return pt(*this) /= t;
    }

    

    inline bool operator < (const pt &other) const {
        return x != other.x ? x < other.x : y < other.y;
    }
    inline bool operator == (const pt &other) const {
        return x == other.x && y == other.y;
    }
    inline bool operator != (const pt &other) const {
        return x != other.x || y != other.y;
    }
};


ostream& operator<<(ostream& os,pt p){
    return os << '(' << p.x << ',' << p.y << ')' << endl;
}

pt operator*(ft a, pt b) {
    return b * a;
}



ft dot(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}



ft cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

ft norm(pt a) {
    return dot(a, a);
}
ld abs(pt a) {  

    return (ld)sqrt(norm(a));
}
ld dis(pt a,pt b){
    return abs(a-b);
}
ld proj(pt a, pt b) {
    return (ld)dot(a, b) / abs(b);
}

pt intersect(pt a1, pt d1, pt a2, pt d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}

ft id9(pt p1, pt p2, pt p3) {
    return cross(p2 - p1, p3 - p2);
}

ld triangle_area(pt p1, pt p2, pt p3) { 

    return (ld)abs(id9(p1, p2, p3)) / 2.0;
}

bool clockwise(pt p1, pt p2, pt p3) {
    return id9(p1, p2, p3) < 0;
}

bool id6(pt p1, pt p2, pt p3) {
    return id9(p1, p2, p3) > 0;
}

pt scale(pt p, ft factor, pt center = pt(0,0)){
    return center + (p-center)*factor;
}



pt rot(pt p,ld a,pt center = pt(0,0)){
    p -= center;
    return center + pt(p.x*cos(a)-p.y*sin(a),p.x*sin(a)+p.y*cos(a));
}



pt rot90(pt p,pt center = pt(0,0)){
    p -= center;
    return center + pt(-p.y,p.x);
}



ft orient(pt a,pt b,pt c){
    return cross(b-a,c-a);
}



bool inAngle(pt a,pt b,pt c,pt p){
    assert(orient(a,b,c) != 0);
    if(orient(a,b,c) < 0) swap(b,c);
    return orient(a,b,p) >= 0 && orient(a,c,p) <= 0;
}



ld angle(pt a, pt b) {
    return acos(max((ld)-1,min((ld)1,(ld)dot(a, b) / abs(a) / abs(b))));
}



ld id2(pt a,pt b,pt c){
    if(orient(a,b,c) >= 0)
        return angle(b-a,c-a);
    else
        return 2*PI - angle(b-a,c-a);
}



bool id12(vector<pt> &v){
    if(v.size() <= 2) return true;
    bool haspos = false, hasneg = false;
    int sv = v.size();
    fo(i,0,sv){
        ft o = orient(v[i],v[(i+1)%sv],v[(i+2)%sv]);
        if(o > 0) haspos = true;
        if(o < 0) hasneg = true;
    }
    return !(haspos && hasneg);
}



ld area(const vector<pt>& fig) {
    ld res = 0;
    for (int i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return abs(res)/2;
}

bool half(pt a){
    assert(a.x != 0 || a.y != 0); 

    return a.y > 0 || (a.y == 0 && a.x < 0);
}


bool polarcmp(pt v,pt w){
    return (pff){half(v),0} < (pff){half(w),cross(v,w)};
}



void id10(vector<pt> &p){
    sort(p.begin(),p.end(),polarcmp);
}








struct line { 

    pt v; ft c;
    

    line(pt v, ft c) : v(v), c(c) {}

    

    line(ft a, ft b, ft c) : v({b,-a}), c(c) {}

    

    line(pt p, pt q) : v(q-p), c(cross(v,p)) {}

    

    inline bool operator < (const line &other) const {
        return v != other.v ? v < other.v : c < other.c;
    }
    inline bool operator == (const line &other) const {
        return v == other.v && c == other.c;
    }
    inline bool operator != (const line &other) const {
        return v != other.v || c != other.c;
    }

    


    

    ft side(pt p) {return cross(v,p)-c;}

    

    ld dist(pt p){
        return abs(side(p))/abs(v);
    }

    

    ld sqDist(pt p){
        return dist(p)*dist(p);
    }
    

    line perpThrough(pt p) {return line(p, p + rot90(v));}

    

    bool cmpProj(pt p, pt q) {
        return dot(v,p) < dot(v,q);
    }

    

    line translate(pt t) {
        return line(v, c + cross(v,t));
    }

    

    line shiftLeft(ld dist){
        return line(v, c + dist*abs(v) + 1e-15); 

    }

    

    pt proj(pt p) {return p - rot90(v)*side(p)/norm(v);}

    

    pt refl(pt p) {return p - rot90(v)*2*side(p)/norm(v);}
};



pair<bool,pt> inter(line l1, line l2){
    ft d = cross(l1.v, l2.v);
    if (d == 0) return {false,pt(0,0)};
    pt out = (l2.v*l1.c - l1.v*l2.c) / d; 

    return {true,out};
}







pair<line,line> bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); 

    return {line(l2.v/abs(l2.v) + l1.v/abs(l1.v) * 1,l2.c/abs(l2.v) + l1.c/abs(l1.v) * 1),
            line(l2.v/abs(l2.v) + l1.v/abs(l1.v) * -1, l2.c/abs(l2.v) + l1.c/abs(l1.v) * -1)};
}









bool inDisk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= 0;
}



bool onSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}





pair<bool,pt> properInter(pt a, pt b, pt c, pt d) {
    ft oa = orient(c,d,a),ob = orient(c,d,b),oc = orient(a,b,c),od = orient(a,b,d);
    if(oc < 0) oc = -1;
    if(oc > 0) oc = 1;
    if (((oa > 0 && ob > 0) || (oa < 0 && ob < 0)) && oc*od < 0) {
        pt out = (a*ob - b*oa) / (ob-oa);
        return {true,out};
    }
    return {false,pt(0,0)};
}



vector<pt> inters(pt a, pt b, pt c, pt d) {
    pair<bool,pt> out = properInter(a,b,c,d);
    if (out.F == true) return {out.S};
    vector<pt> v;
    if (onSegment(c,d,a)) v.pb(a);
    if (onSegment(c,d,b)) v.pb(b);
    if (onSegment(a,b,c)) v.pb(c);
    if (onSegment(a,b,d)) v.pb(d);
    sort(all(v));
    if(v.size() <= 1) return v;
    else return {v[0],v[1]};
}



ld id3(pt a, pt b, pt p) {
    if (a != b) {
        line l(a,b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) 

            return l.dist(p);                 

    }
    return min(abs(p-a), abs(p-b)); 

}



ld id11(pt a, pt b, pt c, pt d) {
    pair<bool,pt> dummy = properInter(a,b,c,d);
    if (dummy.F)
        return 0;
    return min({id3(a,b,c), id3(a,b,d),
                id3(c,d,a), id3(c,d,b)});
}









bool above(pt a, pt p) {
    return p.y >= a.y;
}


bool id8(pt a, pt p, pt q) {
    return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}


bool inPolygon(vector<pt> &p, pt a, bool strict = false) {
    int id0 = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n], a))
            return !strict;
        id0 += id8(a, p[i], p[(i+1)%n]);
    }
    return id0 & 1; 

}







pt id1(pt a, pt b, pt c) {
    b = b-a, c = c-a; 

    assert(cross(b,c) != 0); 

    return a + rot90(b*norm(c) - c*norm(b))/cross(b,c)/2;
}



vector<pt> id7(pt o, ld r, line l) {
    ld h2 = r*r - l.sqDist(o);
    if (h2 >= 0) { 

        pt p = l.proj(o); 

        pt h = l.v*sqrt(h2)/abs(l.v); 

        if(dis(h,pt(0,0)) < 1e-15) return {p};
        else return {p-h, p+h};
    }
    return vector<pt>();
}



vector<pt> circleCircle(pt o1, ld r1, pt o2, ld r2) {
    pt d=o2-o1; ld d2=norm(d);
    if (d2 == 0) {assert(r1 != r2); return vector<pt>();} 

    ld pd = (d2 + r1*r1 - r2*r2)/2; 

    ld h2 = r1*r1 - pd*pd/d2; 

    if (h2 >= 0) {
        pt p = o1 + d*pd/d2, h = rot90(d)*sqrt(h2/d2);
        if(h2 != 0) return {p-h, p+h};
        else return {p};
    }
    return vector<pt>();
}



vector<pair<pt,pt>> id13(pt o1, ld r1, pt o2, ld r2, bool inner) {
    vector<pair<pt,pt>> out;
    if (inner) r2 = -r2;
    pt d = o2-o1;
    ld dr = r1-r2, d2 = norm(d), h2 = d2-dr*dr;
    if (d2 == 0 || h2 < 0) {assert(h2 != 0); return vector<pair<pt,pt>>();}
    for (ld sign : {-1,1}) {
        pt v = (d*dr + rot90(d)*sqrt(h2)*sign)/d2;
        out.push_back({o1 + v*r1, o2 + v*r2});
    }
    return out;
}







bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void id14(vector<pt> &a) { 

    if (a.size() <= 1)
        return;

    set<pt> ss;
    foa(i,a) ss.insert(i); 

    a.clear();
    foa(i,ss) a.pb(i);

    if(a.size() <= 1)
        return;

    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

bool id4(pt a, pt b, pt c, pt point){
    ft s1 = abs(cross(b-a, c-a));
    ft s2 = abs(cross(a-point, b-point)) + abs(cross(b-point, c-point)) + abs(cross(c-point, a-point));
    return abs(s1-s2) < 1e-9; 

}



void prepare(vector<pt> &points,vector<pt> &seq){
    int n = points.size();
    int pos = 0;
    for(int i = 1; i < n; i++){
        if(points[i] < points[pos])
            pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;
    seq.resize(n);
    for(int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
}



bool id5(vector<pt> &seq,pt point){
    int n = seq.size();
    if(cross(seq[0],point) != 0 && sgn(cross(seq[0],point)) != sgn(cross(seq[0],seq[n - 1])))
        return false;
    if(cross(seq[n - 1],point) != 0 && sgn(cross(seq[n - 1],point)) != sgn(cross(seq[n - 1],seq[0])))
        return false;

    if(cross(seq[0],point) == 0)
        return norm(seq[0]) >= norm(point);

    int l = 0, r = n - 1;
    while(r - l > 1){
        int mid = (l + r)/2;
        int pos = mid;
        if(cross(seq[pos],point) >= 0)l = mid;
        else r = mid;
    }
    int pos = l;
    return id4(seq[pos], seq[pos + 1], pt(0, 0), point);
}




int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<pt> a(n);
    fo(i,0,n){
        int x,y;
        cin >> x >> y;
        a[i] = pt(x,y);
    }
    fo(i,0,n) a[i].y -= a[i].x*a[i].x;
    ld mnx,mxx;
    mnx = 1e18;
    mxx = -1e18;
    fo(i,0,n) mnx = min(mnx,a[i].x),mxx = max(mxx,a[i].x);
    a.pb(pt(mnx,-2e12));
    a.pb(pt(mxx,-2e12));
if(mnx==mxx) return cout << 0,0;
    id14(a);
    cout << a.size()-3;


    return 0;
}