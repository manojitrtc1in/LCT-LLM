


using namespace std;

const int MAXN = 300010;

struct Geometry {
    struct point {
        long double x;
        long double y;
        
        point() {}
        point(long double ix, long double iy) {
            x = ix;
            y = iy;
        }
        
        bool operator < (const point &a) const {
            return x != a.x ? x < a.x : y > a.y;
        }
        bool operator == (const point &a) const {
            return a.x == x && a.y == y;
        }
    };
    
    struct vec {
        long double a1;
        long double a2;
        vec() {}
        vec(long double ia1, long double ia2) {
            a1 = ia1;
            a2 = ia2;
        }
        vec operator - (const vec &s) const {
            return vec(a1 - s.a1, a2 - s.a2);
        }
        vec operator + (const vec &s) const {
            return vec(a1 + s.a1, a2 + s.a2);
        }
        vec scalp(const vec &s, long double x) const {
            return vec(s.a1 * x, s.a2 * x);
        }
        long double inner_vector(const vec &s) const {
            return a1 * s.a1 + a2 * s.a2;
        }
        long double dist_vector(const vec &s) const {
            return sqrtl((a1 - s.a1) * (a1 - s.a1) + (a2 - s.a2) * (a2 - s.a2));
        }
        long double inner() const {
            return a1 * a1 + a2 * a2;
        }
        long double dist() const {
            return sqrtl(inner());
        }
        long double get_cos(const vec &s) const {
            return inner_vector(s) / (dist() * s.dist());
        }
        vec proj(const vec &s) const { 

            return scalp(*this, (inner_vector(s) / inner()));
        }
    };
    
    struct lineseg {
        vec x1;
        vec x2;
        lineseg() {}
        lineseg(vec ix1, vec ix2) {
            x1 = ix1;
            x2 = ix2;
        }
        
        long double dist() const {
            return (x2 - x1).dist();
        }
        long double dist_vector(const vec &a) const {
            vec k = (a - x1);
            vec l = (x2 - x1).proj(k);
            return (k - l).dist();
        }
    };
    
    int N;
    int pointsz, vecsz;
    int sz; 

    int midl;
    vec p1, p2, p3; 

    lineseg li; 

    point o[MAXN]; 

    vec u[MAXN];
    point convex[MAXN];
    
    pair<point, point> lis;
    pair<point, point> rec;
    point r1, r2, r3, r4;
    
    

    void init(int n) {
        N = n;
        pointsz = 0;
        

        sz = 0;
    }
    
    void add_vec(long double ix, long double iy) {
        u[vecsz++] = vec(ix, iy);
    }
    void add_point(long double ix, long double iy) {
        o[pointsz++] = point(ix, iy);
    }
    
    int ccw(point a, point b, point c) {
        long double tmp = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
        if(tmp < -((long double)1e-9)) return -1; 

        else if(tmp > ((long double)1e-9)) return 1; 

        return 0;
    }
    
    
    long double get_area(point *hull) { 

        long double ans = 0;
        for(int i=0;i<N;i++) {
            int a = i, b = i + 1 == N ? 0 : i + 1;
            ans += hull[a].x * hull[b].y - hull[a].y * hull[b].x;
        }
        if(ans < 0) ans = -ans;
        return ans / 2;
    }
    
    int across(point a1, point a2, point b1, point b2) { 

        int tmp1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
        int tmp2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
        if(tmp1 <= 0 && tmp2 <= 0) {
            if(tmp1 == 0 && tmp2 == 0) {
                if((a1.x - a2.x) * (b1.y - b2.y) - (a1.y - a2.y) * (b1.x - b2.x) != 0) return 3;
                
                if(a1.x == a2.x) {
                    if(a2.y < a1.y) swap(a1, a2);
                    if(b2.y < b1.y) swap(b1, b2);
                    
                    if(a1.y < b1.y && a2.y > b1.y) return 4;
                    if(a1.y < b2.y && a2.y > b2.y) return 4;
                    if(b1.y < a1.y && b2.y > a1.y) return 4;
                    if(b1.y < a2.y && b2.y > a2.y) return 4;
                    if(a1 == b1 && a2 == b2) return 4;
                    if(a1 == b1 || a2 == b1 || a1 == b2 || a2 == b2) return 3;
                    return 0;
                }
                if(a2.x < a1.x) swap(a1, a2);
                if(b2.x < b1.x) swap(b1, b2);
                
                if(a1.x < b1.x && a2.x > b1.x) return 4;
                if(a1.x < b2.x && a2.x > b2.x) return 4;
                if(b1.x < a1.x && b2.x > a1.x) return 4;
                if(b1.x < a2.x && b2.x > a2.x) return 4;
                if(a1 == b1 && a2 == b2) return 4;
                if(a1 == b1 || a2 == b1 || a1 == b2 || a2 == b2) return 3;
                return 0;
            }
            else if(tmp1 == 0) return 2;
            else if(tmp2 == 0) return 2;
            return 1;
        }
        return 0;
    }
    
    void make_hull() {
        int i, t;
        
        sort(o, o+N);
        
        convex[sz++] = o[0];
        for(i = 1, t = 1; i < N; i++) {
            while(sz > t && ccw(convex[sz-2], convex[sz-1], o[i]) >= 0) sz--;
            convex[sz++] = o[i];
        }
        midl = sz;
        for(i= N - 2, t = midl; i >= 0; i--) {
            while(sz > t && ccw(convex[sz-2], convex[sz-1], o[i]) >= 0) sz--;
            convex[sz++] = o[i];
        }
        sz--;
    }
    
    void rotating_caliphers() {
        p1 = vec(0, 1);
        p2 = vec(0, -1);
        
        vec sub1, sub2;
        
        int l = 0, r = midl-1;
        long double cos1, cos2;
        
        while(l < midl || r < sz) {
            int pl = l, pr = r == sz ? 0 : r;
            int nl = pl + 1, nr = pr + 1 == sz ? 0 : pr + 1;
            
            if(l == midl) r++;
            else if(r == sz) l++;
            else {
                sub1 = vec(convex[nl].x - convex[pl].x, convex[nl].y - convex[pl].y);
                sub2 = vec(convex[nr].x - convex[pr].x, convex[nr].y - convex[pr].y);
                
                cos1 = p1.get_cos(sub1);
                cos2 = p2.get_cos(sub2);
                
                if(cos1 > cos2) {
                    p1 = sub1;
                    p2 = vec(-p1.a1, -p1.a2);
                    l++;
                }
                else {
                    p2 = sub2;
                    p1 = vec(-p2.a1, -p2.a2);
                    r++;
                }
            }
        }
    }
};

Geometry dec;

long double _abs(long double x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    int i, n;
    long double x, y;
    long double x1, y1, x2, y2;
    long double max1;
    max1 = 0;
    scanf("%d",&n);
    scanf("%Lf %Lf %Lf %Lf",&x1,&y1,&x2,&y2);
    if(x1 == x2 || y1 == y2) {
        printf("-1");
        return 0;
    }
    dec.init(n);
    for(i=0;i<n;i++){
        scanf("%Lf %Lf",&x,&y);
        dec.add_point(x, y);
        scanf("%Lf %Lf",&x,&y);
        dec.add_vec(x, y);
    }
    dec.r1 = Geometry::point(x1, y1);
    dec.r2 = Geometry::point(x2, y1);
    dec.r3 = Geometry::point(x1, y2);
    dec.r4 = Geometry::point(x2, y2);
    int cnt[7] = {0,};
    for(i=0;i<n;i++) {
        bool sw = false;
        int tmp1, tmp2, tmp3, tmp4;
        dec.lis.first = Geometry::point(dec.o[i].x, dec.o[i].y);
        dec.lis.second = Geometry::point(dec.o[i].x + 100000*dec.u[i].a1, dec.o[i].y + 100000*dec.u[i].a2);
        
        if(dec.ccw(dec.r1, dec.r2, dec.lis.first) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.first) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.first) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.first) >= 0) {
            if(dec.ccw(dec.r1, dec.r2, dec.lis.first) != 0 && dec.ccw(dec.r2, dec.r4, dec.lis.first) != 0 && dec.ccw(dec.r4, dec.r3, dec.lis.first) != 0 && dec.ccw(dec.r3, dec.r1, dec.lis.first) != 0) continue;
        }
        
        tmp1 = dec.across(dec.lis.first, dec.lis.second, dec.r1, dec.r2);
        tmp2 = dec.across(dec.lis.first, dec.lis.second, dec.r1, dec.r3);
        tmp3 = dec.across(dec.lis.first, dec.lis.second, dec.r2, dec.r4);
        tmp4 = dec.across(dec.lis.first, dec.lis.second, dec.r3, dec.r4);
        
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
        cnt[tmp1]++;
        cnt[tmp2]++;
        cnt[tmp3]++;
        cnt[tmp4]++;
        if(cnt[4] > 0) sw = true;
        else if(cnt[3] == 4) continue;
        else if(cnt[3] == 2 && cnt[0] == 2) sw = true;
        else if(cnt[3] == 2 && cnt[2] >= 1) continue;
        else if(cnt[3] == 2 && cnt[1] >= 1) continue;
        else if(cnt[2] == 2 && cnt[0] == 2) {
            if((dec.ccw(dec.r1, dec.r2, dec.lis.first) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.first) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.first) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.first) >= 0) || (dec.ccw(dec.r1, dec.r2, dec.lis.second) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.second) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.second) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.second) >= 0)) continue;
            else sw = true;
        }
        else if(cnt[2] > 2 || cnt[1] >= 2) continue;
        else if(cnt[2] >= 1 && cnt[1] >= 1) continue;
        else if(cnt[2] == 1 || cnt[1] == 1) sw = true;
        else sw = true;
        if(sw) {
            printf("-1\n");
            return 0;
        }
    }
    
    for(i=0;i<n;i++) {
        long double min1 = (long long)1 << 60;
        int tmp1, tmp2, tmp3, tmp4;
        dec.lis.first = Geometry::point(dec.o[i].x, dec.o[i].y);
        dec.lis.second = Geometry::point(dec.o[i].x + 100000*dec.u[i].a1, dec.o[i].y + 100000*dec.u[i].a2);
        
        if(dec.ccw(dec.r1, dec.r2, dec.lis.first) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.first) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.first) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.first) >= 0) continue;
        
        tmp1 = dec.across(dec.lis.first, dec.lis.second, dec.r1, dec.r2);
        tmp2 = dec.across(dec.lis.first, dec.lis.second, dec.r1, dec.r3);
        tmp3 = dec.across(dec.lis.first, dec.lis.second, dec.r2, dec.r4);
        tmp4 = dec.across(dec.lis.first, dec.lis.second, dec.r3, dec.r4);
        
        if(tmp1 == 1 || tmp1 == 2 || tmp1 == 3) {
            if(min1 > _abs((dec.r1.y-dec.o[i].y)/dec.u[i].a2))
                min1 = _abs((dec.r1.y-dec.o[i].y)/dec.u[i].a2);
        }
        if(tmp2 == 1 || tmp2 == 2 || tmp2 == 3) {
            if(min1 > _abs((dec.r1.x-dec.o[i].x)/dec.u[i].a1))
                min1 = _abs((dec.r1.x-dec.o[i].x)/dec.u[i].a1);
        }
        if(tmp3 == 1 || tmp3 == 2 || tmp3 == 3) {
            if(min1 > _abs((dec.r2.x-dec.o[i].x)/dec.u[i].a1))
                min1 = _abs((dec.r2.x-dec.o[i].x)/dec.u[i].a1);
        }
        if(tmp4 == 1 || tmp4 == 2 || tmp4 == 3) {
            if(min1 > _abs((dec.r3.y-dec.o[i].y)/dec.u[i].a2))
                min1 = _abs((dec.r3.y-dec.o[i].y)/dec.u[i].a2);
        }
        if(max1 < min1) max1 = min1;
    }
    for(i=0;i<n;i++) {
        dec.lis.first = Geometry::point(dec.o[i].x, dec.o[i].y);
        dec.lis.second = Geometry::point(dec.o[i].x + max1*dec.u[i].a1, dec.o[i].y + max1*dec.u[i].a2);
        
        if(dec.ccw(dec.r1, dec.r2, dec.lis.second) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.second) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.second) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.second) >= 0) {
            if(dec.ccw(dec.r1, dec.r2, dec.lis.second) == 0) {
                if((long long)dec.u[i].a2 < 0) break;
            }
            if(dec.ccw(dec.r4, dec.r3, dec.lis.second) == 0) {
                if((long long)dec.u[i].a2 > 0) break;
            }
            if(dec.ccw(dec.r3, dec.r1, dec.lis.second) == 0) {
                if((long long)dec.u[i].a1 < 0) break;
            }
            if(dec.ccw(dec.r2, dec.r4, dec.lis.second) == 0) {
                if((long long)dec.u[i].a1 > 0) break;
            }
            continue;
        }
        break;
    }
    if(i == n) printf("%.6Lf\n",max1);
    else printf("-1\n");
    return 0;
}