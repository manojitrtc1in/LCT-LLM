






using namespace std;

















template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
ii mini(ii a,ii b){
    if(a<b) return a; return b;
}
ii maxi(ii a,ii b){
    if(a>b) return a; return b;
}




struct point { 

    double x, y;
    point() {}
    point( double xx, double yy ) { x = xx, y = yy; }
    

    bool operator <(point b)const{
        if(!eq(x,b.x) ) return x < b.x;
        return y < b.y;
    }
    bool operator == (point b) const{
        if(eq(x,b.x) && eq(y,b.y))  return true;
        return false;
    }

};

struct point3D { 

    double x, y, z;
};
struct line { 

    double a, b, c;
    line() {}
    line( point p1,point p2 ) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};
struct circle { 

    point center;
    double r;
    circle() {}
    circle( point P, double rr ) { center = P; r = rr; }
};
struct segment { 

    point A, B;
    segment() {}
    segment( point P1, point P2 ) { A = P1, B = P2; }
    bool operator < (const segment &a)const{
        return A<a.A;
    }
};
struct quad { 

    point p[5];
    quad(){}
    quad(point a,point b,point c,point d){
        p[0]=a; p[1]=b; p[2]=c; p[3]=d;
    }
};




inline double distancepp( point a, point b ) {
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}


inline double sq_distance( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}


inline double distancepl( point P, line L ) {
    return fabs( L.a * P.x + L.b * P.y + L.c ) / sqrt( L.a * L.a + L.b * L.b );
}


inline double cross( point p0, point p1, point p2 ) {
    return( ( p1.x - p0.x ) * ( p2.y - p0.y ) - ( p2.x - p0.x ) * ( p1.y - p0.y ) );
}



inline bool intersection( line L1, line L2, point &p ) {
    double det = L1.a * L2.b - L1.b * L2.a;
    if( eq ( det, 0 ) ) return false;
    p.x = ( L1.b * L2.c - L2.b * L1.c ) / det;
    p.y = ( L1.c * L2.a - L2.c * L1.a ) / det;
    return true;
}



inline bool intersection( segment L1, segment L2, point &p ) {
    if( !intersection( line( L1.A, L1.B ), line( L2.A, L2.B ), p) ) {
        return false; 

    }
    return(eq(distancepp(L1.A,p)+distancepp(L1.B,p),distancepp(L1.A,L1.B)) &&
        eq(distancepp(L2.A,p)+distancepp(L2.B,p),distancepp(L2.A,L2.B)));
}


inline line id8( line L, point P ) {
    line res; 

    res.a = L.b, res.b = -L.a;
    res.c = -res.a * P.x - res.b * P.y;
    return res;
}


inline double distanceps( point P, segment S ) {
    line L1 = line(S.A,S.B), L2; point P1;
    L2 = id8( L1, P );
    if( intersection( L1, L2, P1 ) )
        if( eq ( distancepp( S.A, P1 ) + distancepp( S.B, P1 ), distancepp( S.A, S.B ) ) )
            return distancepl(P,L1);
    return mini ( distancepp( S.A, P), distancepp( S.B, P) );
}



double areaPoly(point P[],int n){
    double area=0;
    for( int i = 0, j = n - 1; i < n; j = i++ ) area += P[j].x * P[i].y - P[j].y * P[i].x;
    return fabs(area)*.5;
}


inline bool intersectioncl(circle C,line L,point &p1,point &p2) {
    if( distancepl( C.center, L ) > C.r + eps ) return false;
    double a, b, c, d, x = C.center.x, y = C.center.y;
    d = C.r*C.r - x*x - y*y;
    if( eq( L.a, 0) ) {
        p1.y = p2.y = -L.c / L.b;
        a = 1;
        b = 2 * x;
        c = p1.y * p1.y - 2 * p1.y * y - d;
        d = b * b - 4 * a * c;
        d = sqrt( fabs (d) );
        p1.x = ( b + d ) / ( 2 * a );
        p2.x = ( b - d ) / ( 2 * a );
    }
    else {
        a = L.a *L.a + L.b * L.b;
        b = 2 * ( L.a * L.a * y - L.b * L.c - L.a * L.b * x);
        c = L.c * L.c + 2 * L.a * L.c * x - L.a * L.a * d;
        d = b * b - 4 * a * c;
        d = sqrt( fabs(d) );
        p1.y = ( b + d ) / ( 2 * a );
        p2.y = ( b - d ) / ( 2 * a );
        p1.x = ( -L.b * p1.y -L.c ) / L.a;
        p2.x = ( -L.b * p2.y -L.c ) / L.a;
    }
    return true;
}



inline bool id5(point A,double r1,point B, double r2,point &p1,point &p2) {
    line L;
    circle C;
    L.a = 2 * (B.x - A.x );
    L.b = 2 * (B.y - A.y );
    L.c = A.x * A.x + A.y * A.y - B.x * B.x - B.y * B.y + r2 * r2 - r1 * r1;
    C.center = A;
    C.r = r1;
    return intersectioncl( C, L, p1, p2 );
}



inline double id7( circle C1, circle C2 ) {
    C2.center.x = distancepp( C1.center, C2.center );
    C1.center.x = C1.center.y = C2.center.y = 0;
    if( C1.r < C2.center.x - C2.r + eps ) return 0;
    if( -C1.r + eps > C2.center.x - C2.r ) return pi * C1.r * C1.r;
    if( C1.r + eps > C2.center.x + C2.r ) return pi * C2.r * C2.r;
    double c, CAD, CBD, res;
    c = C2.center.x;
    CAD = 2 * acos( (C1.r * C1.r + c * c - C2.r * C2.r) / (2 * C1.r * c) );
    CBD = 2 * acos( (C2.r * C2.r + c * c - C1.r * C1.r) / (2 * C2.r * c) );
    res=C1.r * C1.r * ( CAD - sin( CAD ) ) + C2.r * C2.r * ( CBD - sin ( CBD ) );
    return .5 * res;
}



circle id6( point A, point B, point C) {
    double den; circle c;
    den = 2.0 *((B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x));
    c.center.x =( (C.y-A.y)*(B.x*B.x+B.y*B.y-A.x*A.x-A.y*A.y)- (B.y-A.y)*(C.x*C.x+C.y*C.y-A.x*A.x-A.y*A.y) );
    c.center.x /= den;
    c.center.y =( (B.x-A.x)*(C.x*C.x+C.y*C.y-A.x*A.x-A.y*A.y) - (C.x-A.x)*(B.x*B.x+B.y*B.y-A.x*A.x-A.y*A.y) );
    c.center.y /= den;
    c.r = distancepp( c.center, A );
    return c;
}



inline point id10( point P ,double theta) {
    point Q;
    Q.x = P.x * cos( theta ) - P.y * sin( theta );
    Q.y = P.x * sin( theta ) + P.y * cos( theta );
    return Q;
}


double ang(point a,point b,point c){    

    double absq = sq_distance(a , b);
    double id3 = sq_distance(c , b), acsq = sq_distance(a , c);
    double cosp = (absq+acsq - id3)/(2.0*sqrt(absq * acsq) );
    return acos(cosp);
}


double convrd(double theta){
    double ret=180; ret/=pi; return ret*theta;
}


double convdr(double theta){
    double ret=pi; ret/=(double)180.0; return ret*theta;
}




bool inside_quad(quad q,point p){

    double val=cross(q.p[0],q.p[1],p)*cross(q.p[3],q.p[2],p);
    if(val>0) return 0;

    val=cross(q.p[0],q.p[3],p)*cross(q.p[1],q.p[2],p);
    if(val>0) return 0;

    return 1;
}


bool inside_segment(segment S,point P){
    if( eq ( distancepp( S.A, P ) + distancepp( S.B, P ), distancepp( S.A, S.B ) ) )   return 1;
    return 0;
}



double inline id4(point p1,point p2){
    double num,den;
    num=p2.y-p1.y;
    den=p2.x-p1.x;
    if(iseq(den,0)) return inf;
    return num/den;
}

bool sort_x(point a,point b){
    if(iseq(a.x,b.x)) return a.y<b.y;
    return a.x<b.x;
}
bool sort_y(point a,point b){
    if(iseq(a.y,b.y)) return a.x<b.x;
    return a.y<b.y;
}





point p[maxm*maxm]; 


bool normal(const point &a, const point &b) {   return (iseq(a.x,b.x) ? a.y < b.y : a.x < b.x);}
bool issame(const point &a, const point &b) {   return (iseq(a.x,b.x) && iseq(a.y,b.y));}
void makeUnique(point p[],int &np) {  sort(&p[0], &p[np], normal);    np = unique(&p[0], &p[np], issame) - p;}



bool comp(point a,point b){
    double d = cross(p[0], a, b);
    if(d<0) return false;
    if(iseq(d,0) && dist(p[0], b) < dist(p[0], a)) return false;
    return true;

}

void id9(point ans[],point p[],int &n,int &nc){

    makeUnique(p,n);
    int i,pos = 0;
    for(i=1; i<n; i++)
        if(p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x))
            pos = i;
    swap(p[0], p[pos]);
    sort(p+1, p+n, comp);

    ans[0] = p[0];
    if(n>=2)    ans[1] = p[1];
    for(i=nc=2; i<n; i++)
    {
        while(nc>=2 && cross(ans[nc-2], ans[nc-1], p[i])<0||iseq(cross(ans[nc-2], ans[nc-1], p[i]),0)) nc--;
        ans[nc++] = p[i];
    }
    if(n==1)        nc=1;
    else if(nc==2)
    {
        if(p[0].x == p[1].x && p[0].y == p[1].y)   nc=1;
    }

}




int n,K;
int P[maxm][maxm];
double ans[maxm];

point tmp1[maxm],tmp2[maxm];
int id2,id0;

vector<point>v,tmp;

void reset(int x){
    v.clear();
    v.push_back(point(x,0));
    v.push_back(point(x+1,0));
}

void split(double x,segment piv,segment &id11,segment &id1){

    segment now=segment(point(x,-inf),point(x,inf));
    point ip; 

    if(!intersection(piv,now,ip)) return ;

    id11=segment(piv.A,ip);
    id1=segment(ip,piv.B);
}

bool equal(point a,point b){
    if(!iseq(a.x,b.x)) return 0;
    if(!iseq(a.y,b.y)) return 0;
    return 1;
}

double add(segment piv){

    int i,n=0,x=piv.B.x;

    tmp.clear();
    point ip; 

    segment id11,id1;
    point newp;
    for(i=0;i<v.size()-1;i++){
        

        split(v[i+1].x,piv,id11,id1);
        segment now=segment(v[i],v[i+1]);
        piv=id11;
        if(intersection(now,piv,ip)){

            newp=point(now.A.x,maxi(now.A.y,piv.A.y));
            if((int)tmp.size()==0 || !equal(tmp.back(),newp)) tmp.push_back(newp);

            if((int)tmp.size()==0 || !equal(tmp.back(),ip)) tmp.push_back(ip);

            newp=point(now.B.x,maxi(now.B.y,piv.B.y));
            if((int)tmp.size()==0 || !equal(tmp.back(),newp)) tmp.push_back(newp);
        }

        else{
            newp=point(now.A.x,maxi(now.A.y,piv.A.y));
            if((int)tmp.size()==0 || !equal(tmp.back(),newp)) tmp.push_back(newp);

            newp=point(now.B.x,maxi(now.B.y,piv.B.y));
            if((int)tmp.size()==0 || !equal(tmp.back(),newp)) tmp.push_back(newp);
        }
        piv=id1;
    }

    v.clear();
    for(i=0;i<tmp.size();i++) v.push_back(tmp[i]);
    tmp.clear();

    for(i=0;i<v.size();i++){
        p[n++]=v[i];
    }
    p[n++]=point(x,0);  p[n++]=point(x-1,0);

    return areaPoly(p,n);
}

int main(){

    int i,j,k,l,test,t=1;

    


    scanf("%d %d",&n,&K);

    for(i=1;i<=n;i++){
        for(j=0;j<=K;j++){
            scanf("%d",&P[i][j]);
        }
    }

    for(i=0;i<K;i++){
        double prev=0;
        reset(i);
        for(j=1;j<=n;j++){
            double now=add(segment(point(i,P[j][i]),point(i+1,P[j][i+1])));
            ans[j]+=(now-prev);
            prev=now;
        }
    }

    for(i=1;i<=n;i++){
        printf("%.8lf\n",ans[i]);
    }

    return 0;
}
