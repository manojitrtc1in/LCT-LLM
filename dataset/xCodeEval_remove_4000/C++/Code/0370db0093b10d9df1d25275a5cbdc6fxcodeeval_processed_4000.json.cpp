
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ii> vii;
typedef vector <vii> vvii;










void read_file(bool id0 = true){

    
    freopen("in.in", "rt", stdin);
    if(id0)
    freopen("out.out", "wt", stdout);

    

}











struct point;
struct vec;
struct line;
struct circle;
struct triangle;


long double to_rad(long double theta);
long double to_deg(long double theta);
long double dist(point p, point q);
point middle(point p, point q);
point translate(point p, vec u);
long double norm_sq(vec u);
long double dot(vec u, vec v);
long double cross(vec u, vec v);
bool are_parallel(line l, line d);
bool are_same(line l, line d);
long double id3(point p, point a, point b);
bool ccw(point p, point q, point r);
bool collinear(point p, point q, point r);


long double angle(point a, point o, point b);
point rotate(point p, long double theta, point q);
point intersection(line l, line d);
bool check_range(long double v, long double l1, long double r1, long double l2, long double r2);
point id7(point p, point q, point r, point t);
bool id8(point p, point a, point b);
bool id2(point p, point a, point b);
point projection(point p, point a, point b);
long double id4(point p, point a, point b);
point reflection(point p, point a, point b);
line perpendicular(point p, point a, point b);
line bisector(point a, point o, point b);
circle find_circle(point p, point q, long double r);
circle in_circle(triangle t);
circle id6(triangle t);


long double perimeter(poly P);
long double area(poly P);
bool id1(poly P);
bool is_in(point p, poly P);
poly cut(poly P, point a, point b);
bool ch_cmp(point a, point b);
poly id5(poly P);
void print(poly P);


struct point{
    long double x, y;
    point(long double nx = 0, long double ny = 0){
        x = nx, y = ny;
    }
    bool operator== (point p){
        return fabs(x - p.x) <= EPS && fabs(y - p.y) <= EPS;
    }
    bool operator!= (point p){
        return fabs(x - p.x) > EPS || fabs(y - p.y) > EPS;
    }
    bool operator< (point p){
        if(fabs(x - p.x) > EPS)
            return x < p.x - EPS;
        return y < p.y - EPS;
    }
    friend istream &operator>> (istream &is, point &p){
        return is>>p.x>>p.y;
    }
    friend ostream &operator<< (ostream &os, point p){
        return os<<p.x<<' '<<p.y;
    }
};
struct vec{
    long double x, y;
    vec(long double nx = 0, long double ny = 0){
        x = nx, y = ny;
    }
    vec(point p, point q){
        x = q.x - p.x, y = q.y - p.y;
    }
    vec operator+ (vec u){
        return vec(x + u.x, y + u.y); 
    }
    vec operator- (vec u){
        return vec(x - u.x, y - u.y); 
    }
    vec operator* (long double k){
        return vec(k*x, k*y);
    }
    friend istream &operator>> (istream &is, vec u){
        return is>>u.x>>u.y;
    }
    friend ostream &operator<< (ostream &os, vec u){
        return os<<u.x<<' '<<u.y;
    }
};
struct line{
    long double a, b, c;
    line(long double na = 0, long double nb = 0, long double nc = 0){
        a = na, b = nb, c = nc;
    }
    line(point p, point q){
        long double dx = q.x - p.x;
        long double dy = q.y - p.y;
        
        if(fabs(dx) <= EPS)
        {
            a = 1, b = 0, c = -p.x;
            return;
        }

        a = -dy/dx;
        b = 1.0;
        c = dy/dx * p.x - p.y;
    }
    line(point p, long double m){
        a = -m;
        b = 1.0;
        c = -(a * p.x + p.y);
    }
    pp to_points(){
        point p, q;
        if(fabs(b) <= EPS)
            p.x = -c/a, q.x = p.x, p.y = 0, q.y = 1;
        else
            p.x = 0, q.x = 1, p.y = - (a * p.x + c), q.y = -(a * q.x + c);
        return MP(p, q);
    }
};
struct circle{
    long double x, y, r;
    circle(point c = origin, long double nr = 0){
        x = c.x, y = c.y, r = nr;
    }
    int is_in(point p){
        long double dx = p.x - x, dy = p.y - y;
        long double d = dx*dx + dy*dy, R = r*r;
        return (d < R - EPS)? 0 : (fabs(d - R) <= EPS)? 1 : 2;
    }
    long double perimeter(long double theta = 360){
        theta = to_rad(theta);
        return theta * r;
    }
    long double area(long double theta = 360){
        theta = to_rad(theta);
        return theta * r*r /2;
    }
};
struct triangle{
    point A, B, C;
    long double a, b, c;
    triangle(long double na = 0, long double nb = 0, long double nc = 0){
        a = na, b = nb, c = nc;
    }
    triangle(point nA, point nB, point nC){
        A = nA, B = nB, C = nC;
        c = dist(A, B), a = dist(B, C),b = dist(C, A);
    }
    bool is_triangle(){
        return a+b>c+EPS && b+c>a+EPS && c+a>b+EPS;
    }
    long double perimeter(){
    return a + b + c;
}
    long double area(){
        long double s = perimeter()/2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
};


long double to_rad(long double theta){
    return theta * PI / 180;
}
long double to_deg(long double theta){
    return theta * 180 / PI;
}
long double dist(point p, point q){
    return hypot(p.x - q.x, p.y - q.y);
}
point middle(point p, point q){
    return point((p.x + q.x)/2, (p.y + q.y)/2);
}
point translate(point p, vec u){
    return point(p.x + u.x, p.y + u.y);
}
long double norm_sq(vec u){
    return u.x * u.x + u.y * u.y;
}
long double dot(vec u, vec v){
    return u.x * v.x + u.y * v.y;
}
long double cross(vec u, vec v){
    return u.x * v.y - u.y * v.x;
}
bool are_parallel(line l, line d){
    return fabs(l.a - d.a) <= EPS && fabs(l.b - l.b) <= EPS;
}
bool are_same(line l, line d){
    return are_parallel(l, d) && fabs(l.c - d.c) <= EPS;
}
long double id3(point p, point a, point b){
    return dist(p, projection(p, a, b));
}
bool ccw(point p, point q, point r){
    return cross(vec(p, q), vec(p, r)) > 0 + EPS;
}
bool collinear(point p, point q, point r){
    return fabs( cross( vec(p, q), vec(p, r)) ) <= EPS;
}


long double angle(point a, point o, point b){
    vec oa = vec(o, a), ob = vec(o, b);
    return acos( dot(oa, ob) / sqrt( norm_sq(oa) * norm_sq(ob) ) );
}
point rotate(point p, long double theta, point q = origin){
    vec oq = vec(origin, q);
    p = translate(p, oq * -1);
    
    theta = to_rad(theta);
    long double x = p.x * cos(theta) - p.y * sin(theta);
    long double y = p.x * sin(theta) + p.y * cos(theta);
    
    p = point(x, y);
    p = translate(p, oq);
    return p;
}
point intersection(line l, line d){
    if(are_parallel(l, d)) return undefined;
    
    point p;
    p.x = (d.b * l.c - l.b * d.c) / (d.a * l.b - l.a * d.b);
    
    if(fabs(l.b) > EPS)
        p.y = -(l.a * p.x + l.c);
    else
        p.y = -(d.a * p.x + d.c);
    
    return p;
}
bool check_range(long double v, long double l, long double r){
    if(l > r + EPS) swap(l, r);
    if(fabs(r - l) <= EPS) return fabs(v - l) <= EPS;
    return l < v - EPS && v < r - EPS;
    return l <= v + EPS && v <= r + EPS;
}
point id7(point p, point q, point r, point t){
    point c = intersection( line(p, q) , line(r, t) );
    if(id2(c, p, q) && id2(c, r, t)) return c;
    return undefined;
}
bool id8(point p, point a, point b){
    

    vec ap = vec(a, p), ab = vec(a, b);
    return collinear(p, a, b) && dot(ap, ab) >= -EPS;
}
bool id2(point p, point a, point b){
    

    return id8(p, a, b) && id8(p, b, a);
}
point projection(point p, point a, point b){
    vec ap = vec(a, p), ab = vec(a, b);
    long double u = dot(ap, ab) / norm_sq(ab);
    return translate(a, ab * u);
}
long double id4(point p, point a, point b){
    vec ap = vec(a, p), ab = vec(a, b);
    long double u = dot(ap, ab) / norm_sq(ab);
    
    if(u < 0 - EPS)
        return dist(p, a);
    if(u > 1 + EPS)
        return dist(p, b);
    
    return id3(p, a, b);
}
point reflection(point p, point a, point b){
    point c = projection(p, a, b);
    vec pc = vec(p, c);
    return translate(p, pc * 2);
}
line perpendicular(point p, point a, point b){
    if(!collinear(p, a, b))
        return line(p, projection(p, a, b));
    
    line l = line(a, b);
    if(fabs(l.b) <= EPS)
        return line(p, point(p.x+1, p.y));
    
    if(fabs(l.a) <= EPS)
        return line(p, point(p.x, p.y+1));
    
    return line(p, 1/l.a);
}
line bisector(point a, point o, point b){
    long double ratio = dist(o, a)/dist(o, b);
    ratio /= ratio+1;
    vec ab = vec(a, b);
    point c = translate(a, ab * ratio);
    return line(o, c);
}
circle find_circle(point p, point q, long double r){
    point m = middle(p, q);
    vec mp = vec(m, p);
    
    long double mc = r*r - norm_sq(mp);
    if(mc < 0 - EPS) return circle();
    mc = sqrt(mc);
    
    long double u = mc/dist(m, p);
    point c = translate(m, mp * u);
    c = rotate(c, 90, m);
    
    return circle(c, r);
}
circle in_circle(triangle t){
    long double r = 2 * t.area()/t.perimeter();
    if(fabs(r) <= EPS)  return circle();
    line l = bisector(t.B, t.A, t.C);
    line d = bisector(t.C, t.B, t.A);
    point c = intersection(l, d);
    return circle(c, r);
}
circle id6(triangle t){
    long double r = (t.a * t.b * t.c)/(4 * t.area());
    if(fabs(r) <= EPS)  return circle();
    line l = perpendicular(middle(t.A, t.B), t.A, t.B);
    line d = perpendicular(middle(t.A, t.C), t.A, t.C);
    point c = intersection(l, d);
    return circle(c, r);
}






point pivot;
long double perimeter(poly P){
    int n = P.size();
    long double ret = 0;
    for(int i=0; i<n-1; i++)
        ret += dist(P[i], P[i+1]);
    return ret;
}
long double area(poly P){
    P.PB(P[0]);
    int n = P.size();
    long double ret = 0;
    long double x1, x2, y1, y2;
    for(int i=0; i<n-1; i++)
    {
        x1 = P[i].x, x2 = P[i+1].x;
        y1 = P[i].y, y2 = P[i+1].y;
        ret += x1 * y2 - x2 * y1;
    }
    ret /= 2, ret = fabs(ret);
    return ret;
}
bool id1(poly P){
    int n = P.size();
    if(n <= 3)  return false;
    bool turn = ccw(P[0], P[1], P[2]);
    for(int i=1; i<n-1; i++)
        if(ccw(P[i], P[i+1], P[i+2 != n ? i+2 : 1]) != turn)
            return false;
    return true;
}
bool is_in(point p, poly P){
    int n = P.size();
    long double sum = 0;
    
    for(int i=0; i<n-1; i++)
        if(ccw(P[i], p, P[i+1]))
            sum += angle(P[i], p, P[i+1]);
        else
            sum -= angle(P[i], p, P[i+1]);
    
    sum = fabs(sum);
    return fabs(sum - 2*PI) <= EPS;
}
poly cut(poly P, point a, point b){
    int n = P.size();
    poly ret;
    
    for(int i=0; i<n; i++)
    {
        long double left1 = cross(vec(a, b), vec(a, P[i]));
        long double left2 = (i != n-1)? cross(vec(a, b), vec(a, P[i+1])) : 0;
        
        if(left1 >= -EPS)
            ret.PB(P[i]);
        if(left1 * left2 < -EPS)
            ret.PB( intersection(line(a, b), line(P[i], P[i+1])) );
    }
    
    if(!ret.empty() && ret.front() != ret.back())
        ret.PB(ret.front());
    return ret;
}
bool ch_cmp(point a, point b){
    if(collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b) - EPS;
    
    long double dx1 = a.x - pivot.x, dy1 = a.y - pivot.y;
    long double dx2 = b.x - pivot.x, dy2 = b.y - pivot.y;
    
    return atan2(dy1, dx1) < atan2(dy2, dx2) - EPS;
}
poly id5(vp P){
    int n = P.size();
    if(n <= 3)
    {
        if(n != 0 && P[0] != P[n-1])
            P.PB(P[0]);
        return P;
    }
    
    int idx = 0;
    for(int i=1; i<n; i++)
        if( P[idx].y > P[i].y + EPS || (fabs(P[idx].y - P[i].y) <= EPS && P[idx].x < P[i].x - EPS) )
            idx = i;
    swap(P[0], P[idx]);
    
    pivot = P[0];
    sort(P.begin()+1, P.end(), ch_cmp);
    
    poly ch;
    ch.PB(P[n-1]), ch.PB(P[0]), ch.PB(P[1]);
    int i = 2;
    
    while(i < n)
    {
        int j = ch.size()-1;
        if(ccw(ch[j-1], ch[j], P[i]))
            ch.PB(P[i]), i++;
        else
            ch.pop_back();
    }
    
    return ch;
}
void print(poly P){
    

    int n = P.size();
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<< P[i] <<endl;
    cout<<endl;
}



    ll n ;
ll fix ( ll x )
{
    x%=n;
    x+=n;
    x%=n;
    return x ;
}point p[N];
int main () 
{
    
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        ll x , y ;
        cin >> x >> y ;
        p[i] = point ( x , y ) ;
    }
    ld ans = inf ;
    for ( int i =0 ; i < n ; i ++ )
    {
        point l = p [fix ( i - 1 )];
        point r = p [fix ( i + 1 )];
        
        
        ans = min  ( ans, id4 (p[i],l,r));
       

    }
    cout <<fixed << setprecision(8) << ans / 2 ;
}