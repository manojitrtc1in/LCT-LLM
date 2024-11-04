















using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }






const double eps = 1e-5;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 120;



int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}


inline double sqr(double x) {return x * x;}
struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    void output() {
        printf("%.8f %.8f\n", x, y);
    }
    bool operator == (Point b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (Point b) const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    

    double operator * (const Point &b) const {
        return x * b.x + y * b.y;
    }
    

    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
    

    double len() {
        return hypot(x, y); 

    }
    

    double len2() {
        return x * x + y * y;
    }
    

    double distance(Point p) {
        return hypot(x - p.x, y - p.y);
    }
	

	double distance2(Point p) {
        return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
    }
    Point operator + (const Point &b) const {
        return Point(x + b.x, y + b.y);
    }
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
    }
    Point operator / (const double &k) const {
        return Point(x / k, y / k);
    }
    

    

    

    double rad(Point a, Point b) {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
    

    Point trunc(double r) {
        double l = len();
        if (!sgn(l)) return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    

    Point rotleft() {
        return Point(-y, x);
    }
    

    Point rotright() {
        return Point(y, -x);
    }
    

    Point rotat(Point p, double angle) {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
}po[maxp];


double cross(Point A,Point B,Point C){
	return (B-A)^(C-A);
}


double dot(Point A,Point B,Point C){
	return (B-A)*(C-A);
}
struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e) {
        s = _s;
        e = _e;
    }
    bool operator == (Line v) {
        return (s == v.s) && (e == v.e);
    }
    

    Line (Point p, double angle) {
        s = p;
        if (sgn(angle - pi / 2) == 0) {
            e = (s + Point(0, 1));
        } else {
            e = (s + Point(1, tan(angle)));
        }
    }
    

    Line(double a, double b, double c) {
        if (sgn(a) == 0) {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        } else if (sgn(b) == 0) {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        } else {
            s = Point(0, -c / b);
            e = Point(1, (-c - a) / b);
        }
    }
    void input() {
        s.input();
        e.input();
    }
    void adjust() {
        if (e < s) swap(s, e);
    }
    

    double length() {
        return s.distance(e);
    }
    

    double angle() {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    

    }
    

    

    

    int relation(Point p) {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0) return 1;
        else if (c > 0) return 2;
        else return 3;
    }
    

    bool pointonseg(Point p) {
        return sgn((p - s) ^ (e-s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    

    bool parallel(Line v) {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    

    

    

    

    int segcrossseg(Line v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
            (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
            (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
            (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    

    

    

    

    

    int linecrossseg(Line v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2) return 2;
        return (d1 == 0 || d2 == 0);
    }
    

    

    

    

    int linecrossline(Line v) {
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }
    

    

    Point crosspoint(Line v) {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1),
                     (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    

    double dispointtoline(Point p) {
        return fabs((p - s) ^ (e - s)) / length();
    }
    

    double dispointtoseg(Point p) {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    

    

    double dissegtoseg(Line v) {
        return min(min(dispointtoseg(v.s), dispointtoseg(v.e)),
                   min(v.dispointtoseg(s), dispointtoseg(e)));
    }
    

    Point lineprog(Point p) {
        return s + ( ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()) );
    }
    

    Point symmetrypoint(Point p) {
        Point q = lineprog(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }
};
struct polygon{
    int n;
    Point p[maxp];
    Line l[maxp];
    void input(int _n){
        n=_n;
        for(int i=0; i<n; ++i) p[i].input();
    }
    void add(Point q){
        p[n++]=q;
    }
    void getline(){
        for(int i=0; i<n; ++i) l[i]=Line(p[i],p[(i+1)%n]);
    }
    struct cmp{
        Point p;
        cmp(const Point &p0){p=p0;}
        bool operator()(const Point &aa,const Point &bb){
            Point a=aa,b=bb;
            int d=sgn((a-p)^(b-p));
            if(d==0){
                return sgn(a.distance(p)-b.distance(p))<0;
            }
            return d>0;
        }
    };
    

    

    

    void norm(){
        Point mi=p[0];
        for(int i=1;i<n;++i) mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    

    

    

    

    

    void getconvex(polygon &convex){
        sort(p,p+n);
        convex.n=n;
        for(int i=0; i<min(n,2); ++i) convex.p[i]=p[i];
        if(convex.n==2 && (convex.p[0]==convex.p[1])) convex.n--; 

        if(n<=2) return;
        int &top=convex.n;
        top=1;
        for(int i=2; i<n; ++i){
            while(top && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0) --top;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for(int i=n-3; i>=0; --i){
            while(top!=temp && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<=0) top--;
            convex.p[++top]=p[i];
        }
        if(convex.n==2 && (convex.p[0]==convex.p[1])) convex.n--;

        convex.norm(); 

    }
	

    

    void Graham(polygon &convex){
        norm();
        int &top=convex.n;
        top=0;
        if(n==1){
            top=1;
            convex.p[0]=p[0];
            return;
        }
        if(n==2){
            top=2;
            convex.p[0]=p[0];
            convex.p[1]=p[1];
            if(convex.p[0]==convex.p[1]) --top;
            return;
        }
        convex.p[0]=p[0];
        convex.p[1]=p[1];
        top=2;
        for(int i=2; i<n; ++i){
            while(top>1 && sgn((convex.p[top-1]-convex.p[top-2])^
                               (p[i]-convex.p[top-2]))<=0) --top;  

            convex.p[top++]=p[i];
        }
        if(convex.n==2 && convex.p[0]==convex.p[1]) convex.n--; 

    }
    

    bool isconvex(){
        bool s[3];
        memset(s,false,sizeof(s));
        for(int i=0; i<n; ++i){
            int j=(i+1)%n;
            int k=(j+1)%n;
            s[sgn((p[j]-p[i])^(p[k]-p[i]))+1]=true;
            if(s[0] && s[2]) return false;
        }
        return true;
    }
	

    double rotate_calipers(){
        double ans=0;
        if(n==1) return ans;
        else if(n==2){
            ans=max(ans,p[0].distance(p[1]));
            return ans;
        }
        else if(n==3){
            ans=max(ans, p[0].distance(p[1]));
            ans=max(ans, p[0].distance(p[2]));
            ans=max(ans, p[1].distance(p[2]));
            return ans;
        } else{
            int i,j=1;
            p[n++]=p[0];
            for(int i=0; i<n; ++i){
                for(;cross(p[i+1],p[j+1],p[i])>cross(p[i+1],p[j],p[i]);j=(j+1)%n);
                ans=max(ans, max(p[i].distance(p[j]),p[i+1].distance(p[j])));

            }
            return ans;
        }
    }
	

    

    double getcircumference(){
        double sum=0;
        for(int i=0; i<n; ++i){
            sum+=p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
	

    double getarea(){
        double sum=0;
        for(int i=0; i<n; ++i) sum+=(p[i]^p[(i+1)%n]);
        return fabs(sum)/2;
    }
};
bool squ(Point a,Point b,Point c,Point d){
    vector<double> temp;
    double l11=a.distance(b); temp.eb(l11);
    double l22=b.distance(c); temp.eb(l22);
    double l33=c.distance(d); temp.eb(l33);
    double l44=d.distance(a); temp.eb(l44);
    double l55=a.distance(c); temp.eb(l55);
    double l66=b.distance(d); temp.eb(l66);
    sort(all(temp));
    if(!sgn(temp[0]-temp[1]) && !sgn(temp[1]-temp[2]) && !sgn(temp[2]-temp[3]) && !sgn(temp[4]-temp[5]) && sgn(temp[3]-temp[4])==-1) return true;
    return false;
}
bool rec(Point a,Point b,Point c,Point d){
    Point ct=Point((a.x+b.x+c.x+d.x)/4,(a.y+b.y+c.y+d.y)/4);
    double l11=ct.distance(a);
    double l22=ct.distance(b);
    double l33=ct.distance(c);
    double l44=ct.distance(d);
    if(!sgn(l11-l22) && !sgn(l11-l33) && !sgn(l11-l44)) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    freopen("input.txt", "r", stdin);

    forn(i, 8) scanf("%lf%lf",&po[i].x,&po[i].y);
    for(int a=0; a<8; ++a){
        for(int b=a+1; b<8; ++b){
            for(int c=b+1; c<8; ++c){
                for(int d=c+1; d<8; ++d){
                    vector<Point> temp;
                    vector<int> idx;
                    for(int i=0; i<8; ++i){
                        if(i!=a && i!=b && i!=c && i!=d){
                            temp.eb(po[i]);
                            idx.eb(i);
                        }
                    }
                    if(squ(po[a],po[b],po[c],po[d]) && rec(temp[0],temp[1],temp[2],temp[3])){
                        puts("YES");
                        printf("%d %d %d %d\n",a+1,b+1,c+1,d+1);
                        printf("%d %d %d %d\n",idx[0]+1,idx[1]+1,idx[2]+1,idx[3]+1);
                        return 0;
                    }
                    if(rec(po[a],po[b],po[c],po[d]) && squ(temp[0],temp[1],temp[2],temp[3])){
                        puts("YES");
                        printf("%d %d %d %d\n",idx[0]+1,idx[1]+1,idx[2]+1,idx[3]+1);
                        printf("%d %d %d %d\n",a+1,b+1,c+1,d+1);
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
