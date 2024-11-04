














using namespace std;






















struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b)
{
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}
bool operator <(const Point &a, const Point &b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}




double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }








double id2(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

double id8(double a, double b, double c) { return a * b * c / (4 * id2(a, b, c)); }

double id2(double a, double b, double c, double d)
{
    double s = (a + b + c + d) / 2;
    return sqrt((s-a) * (s-b) * (s-c) * (s-d));
}

double id8(double a, double b, double c, double d) { return sqrt((a*b + c*d) * (a*c + b*d) * (a*d + b*c))  / (4 * id2(a, b, c, d)); }



bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}

bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}



bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);
    
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) 
            return true;
    
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}



bool sameLine(Point P1, Point P2, Point P3, Point P4)
{
    return area(P1, P2, P3) == 0 && area(P1, P2, P4) == 0;
}


bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
    return cross(P2 - P1, P4 - P3) == 0;
}



Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

Point id6(const Point &A, const Point &B, const Point &C)
{
    return (A + B + (A - B).ort() * dot(C - B, A - C) / cross(A - B, A - C)) / 2;
}



bool id0(const vector <Point> &P)
{
    int n = P.size(), pos = 0, neg = 0;
    for(int i=0; i<n; i++)
    {
        double A = area(P[i], P[(i+1)%n], P[(i+2)%n]);
        if(A < 0) neg++;
        else if(A > 0) pos++;
    }
    return neg == 0 || pos == 0;
}

double area(const vector <Point> &P)
{
    int n = P.size();
    double A = 0;
    for(int i=1; i<=n-2; i++)
        A += area(P[0], P[i], P[i+1]);
    return abs(A/2);
}

bool id5(const vector <Point> &P, const Point &A)
{
    int n = P.size(), cnt = 0;
    for(int i=0; i<n; i++)
    {
        int inf = i, sup = (i+1)%n;
        if(P[inf].y > P[sup].y) swap(inf, sup);
        if(P[inf].y <= A.y && A.y < P[sup].y)
            if(area(A, P[inf], P[sup]) > 0)
                cnt++;
    }
    return (cnt % 2) == 1;
}



vector <Point> id7(vector <Point> P)
{
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    return vector <Point> (H,H+k-1);
}






bool id9(vector <Point> &A, const Point &P)
{
    int n = A.size(), lo = 1, hi = A.size() - 1;
    
    if(area(A[0], A[1], P) <= 0) return 0;
    if(area(A[n-1], A[0], P) <= 0) return 0;
    
    while(hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        
        if(area(A[0], A[mid], P) > 0) lo = mid;
        else hi = mid;
    }
    
    return area(A[lo], A[hi], P) > 0;
}



Point norm(const Point &A, const Point &O)
{
    Vector V = A - O;
    V = V * 10000000000.0 / V.mod();
    return O + V;
}

bool id9(vector <Point> &A, vector <Point> &B)
{
    if(!id9(A, B[0])) return 0;
    else
    {
        int n = A.size(), p = 0;
        
        for(int i=1; i<B.size(); i++)
        {
            while(!intersects(A[p], A[(p+1)%n], norm(B[i], B[0]), B[0])) p = (p+1)%n;
            
            if(area(A[p], A[(p+1)%n], B[i]) <= 0) return 0;
        }
        
        return 1;
    }
}
       







pair <Point, double> id3(vector <Point> P)
{
    random_shuffle(P.begin(), P.end());
    
    Point O(0, 0);
    double R2 = 0;
    
    for(int i=0; i<P.size(); i++)
    {
        if((P[i] - O).mod2() > R2 + EPS)
        {
            O = P[i], R2 = 0;
            for(int j=0; j<i; j++)
            {
                if((P[j] - O).mod2() > R2 + EPS)
                {
                    O = (P[i] + P[j])/2, R2 = (P[i] - P[j]).mod2() / 4;
                    for(int k=0; k<j; k++)
                        if((P[k] - O).mod2() > R2 + EPS)
                            O = id6(P[i], P[j], P[k]), R2 = (P[k] - O).mod2();
                }
            }
        }
    }
    return make_pair(O, sqrt(R2));
}



bool XYorder(Point P1, Point P2)
{
    if(P1.x != P2.x) return P1.x < P2.x;
    return P1.y < P2.y;
}
bool YXorder(Point P1, Point P2)
{
    if(P1.y != P2.y) return P1.y < P2.y;
    return P1.x < P2.x;
}
double closest_recursive(vector <Point> vx, vector <Point> vy)
{
    if(vx.size()==1) return 1e20;
    if(vx.size()==2) return dist(vx[0], vx[1]);
    
    Point cut = vx[vx.size()/2];
    
    vector <Point> vxL, vxR;
    for(int i=0; i<vx.size(); i++)
        if(vx[i].x < cut.x || (vx[i].x == cut.x && vx[i].y <= cut.y))
            vxL.push_back(vx[i]);
        else vxR.push_back(vx[i]);
    
    vector <Point> vyL, vyR;
    for(int i=0; i<vy.size(); i++)
        if(vy[i].x < cut.x || (vy[i].x == cut.x && vy[i].y <= cut.y))
            vyL.push_back(vy[i]);
        else vyR.push_back(vy[i]);
    
    double dL = closest_recursive(vxL, vyL);
    double dR = closest_recursive(vxR, vyR);
    double d = min(dL, dR);
    
    vector <Point> b;
    for(int i=0; i<vy.size(); i++)
        if(abs(vy[i].x - cut.x) <= d)
            b.push_back(vy[i]);
    
    for(int i=0; i<b.size(); i++)
        for(int j=i+1; j<b.size() && (b[j].y - b[i].y) <= d; j++)
            d = min(d, dist(b[i], b[j]));
    
    return d;
}
double closest(vector <Point> points)
{
    vector <Point> vx = points, vy = points;
    sort(vx.begin(), vx.end(), XYorder);
    sort(vy.begin(), vy.end(), YXorder);
    
    for(int i=0; i+1<vx.size(); i++)
        if(vx[i] == vx[i+1])
            return 0.0;
    
    return closest_recursive(vx,vy);
}



vector <Point> id1(Point O1, double r1, Point O2, double r2)
{
    vector <Point> X;
    
    double d = dist(O1, O2);

    if(d > r1 + r2 || d < max(r2, r1) - min(r2, r1)) return X;
    else
    {
        double a = (r1*r1 - r2*r2 + d*d) / (2.0*d);
        double b = d - a;
        double c = sqrt(abs(r1*r1 - a*a));

        Vector V = (O2-O1).unit();
        Point H = O1 + V * a;

        X.push_back(H + V.ort() * c);
        
        if(c > EPS) X.push_back(H - V.ort() * c);
    }
    
    return X;
}








vector <Point> id4(Point A, Point B, Point O, long double r)
{
    vector <Point> X;
    
    Point H1 = O + (B - A).ort() * cross(O - A, B - A) / (B - A).mod2();
    long double d2 = cross(O - A, B - A) * cross(O - A, B - A) / (B - A).mod2();

    if(d2 <= r*r + EPS)
    {
        long double k = sqrt(abs(r * r - d2));
        
        Point P1 = H1 + (B - A) * k / (B - A).mod();
        Point P2 = H1 - (B - A) * k / (B - A).mod();
        
        if(between(A, B, P1)) X.push_back(P1);
        
        if(k > EPS && between(A, B, P2)) X.push_back(P2);
    }
    
    return X;
}

struct triangle{
    vector<Point> V;
    vector<Point> I[3];
    triangle(){}
    void read(){
        for(int i = 0 ; i < 3 ; i++){
            Point R;
            cin >> R.x >> R.y;
            V.pb(R);
        }
            
        I[0].pb( V[0] ) , I[0].pb( V[1] );
        I[1].pb( V[1] ) , I[1].pb( V[2] );
        I[2].pb( V[0] ) , I[2].pb( V[2] );
    }
    void intersecta( triangle A ){
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++){
                if( isParallel( V[i] , V[(i+1)%3] , A.V[j] , A.V[(j+1)%3] ) ) continue;
                if( intersects( V[i] , V[(i+1)%3] , A.V[j] , A.V[(j+1)%3] ) )
                    I[i].pb( lineIntersection( V[i] , V[(i+1)%3] , A.V[j] , A.V[(j+1)%3] ) );
            }
    }
    void ordena(){
        for(int i = 0 ; i < 3 ; i++)
            sort( all(I[i]) );
    }
    void print(){
        for(int i = 0 ; i < 3 ; i++)
            cout << V[i].x << " - " << V[i].y << endl;
    }
};

int main(){
    int n;
    while( cin >> n ){
        vector<triangle> v( n );
        for(int i = 0 ; i < n ; i++)
            v[i].read();
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) if( i != j ){
                v[i].intersecta( v[j] );
            }
        
        
        
        for(int i = 0 ; i < n ; i++)
            v[i].ordena();
       
        double ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < v[i].I[j].size() - 1 ; k++){
                    Point A = v[i].I[j][k] , B = v[i].I[j][k+1];
                    

                    Point M = (A+B)/2;
                    bool ok = 1;
                    for(int r = 0 ; ok && r < n ; r++)if( r != i )
                        if( id5( v[r].V , M ) ) ok = 0;
                        
                    if( ok ) ans += (B-A).mod();
                }
            }
        }
        printf("%.7lf\n",ans);
    }
    return 0;
}
