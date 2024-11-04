






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
		if(!eq(x,b.x) )	return x < b.x;
		return y < b.y;
	}
	bool operator == (point b) const{
		if(eq(x,b.x) && eq(y,b.y))	return true;
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


inline line id5( line L, point P ) {
	line res; 

	res.a = L.b, res.b = -L.a;
	res.c = -res.a * P.x - res.b * P.y;
	return res;
}


inline double distanceps( point P, segment S ) {
	line L1 = line(S.A,S.B), L2; point P1;
	L2 = id5( L1, P );
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



inline bool id2(point A,double r1,point B, double r2,point &p1,point &p2) {
	line L;
	circle C;
	L.a = 2 * (B.x - A.x );
	L.b = 2 * (B.y - A.y );
	L.c = A.x * A.x + A.y * A.y - B.x * B.x - B.y * B.y + r2 * r2 - r1 * r1;
	C.center = A;
	C.r = r1;
	return intersectioncl( C, L, p1, p2 );
}



inline double id4( circle C1, circle C2 ) {
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



circle id3( point A, point B, point C) {
	double den; circle c;
	den = 2.0 *((B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x));
	c.center.x =( (C.y-A.y)*(B.x*B.x+B.y*B.y-A.x*A.x-A.y*A.y)- (B.y-A.y)*(C.x*C.x+C.y*C.y-A.x*A.x-A.y*A.y) );
	c.center.x /= den;
	c.center.y =( (B.x-A.x)*(C.x*C.x+C.y*C.y-A.x*A.x-A.y*A.y) - (C.x-A.x)*(B.x*B.x+B.y*B.y-A.x*A.x-A.y*A.y) );
	c.center.y /= den;
	c.r = distancepp( c.center, A );
	return c;
}



inline point id7( point P ,double theta) {
	point Q;
	Q.x = P.x * cos( theta ) - P.y * sin( theta );
	Q.y = P.x * sin( theta ) + P.y * cos( theta );
	return Q;
}


double ang(point a,point b,point c){    

    double absq = sq_distance(a , b);
    double id0 = sq_distance(c , b), acsq = sq_distance(a , c);
    double cosp = (absq+acsq - id0)/(2.0*sqrt(absq * acsq) );
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



double inline id1(point p1,point p2){
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





point p[maxm]; 


bool normal(const point &a, const point &b) {   return (iseq(a.x,b.x) ? a.y < b.y : a.x < b.x);}
bool issame(const point &a, const point &b) {   return (iseq(a.x,b.x) && iseq(a.y,b.y));}
void makeUnique(point p[],int &np) {  sort(&p[0], &p[np], normal);    np = unique(&p[0], &p[np], issame) - p;}



bool comp(point a,point b){
    double d = cross(p[0], a, b);
    if(d<0) return false;
    if(iseq(d,0) && dist(p[0], b) < dist(p[0], a)) return false;
    return true;

}

void id6(point ans[],point p[],int &n,int &nc){

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

bool issquare(point p0,point p1,point p2,point p3){

    if(!iseq(sq_distance(p0,p1),sq_distance(p1,p2))) return 0;
    if(!iseq(sq_distance(p1,p2),sq_distance(p2,p3))) return 0;
    if(!iseq(sq_distance(p2,p3),sq_distance(p3,p0))) return 0;

    double alpha,req=pi/2.0;

    alpha=ang(p1,p0,p2);
    if(!iseq(alpha,req)) return 0;

    alpha=ang(p2,p1,p3);
    if(!iseq(alpha,req)) return 0;

    alpha=ang(p3,p2,p0);
    if(!iseq(alpha,req)) return 0;

    alpha=ang(p0,p3,p1);
    if(!iseq(alpha,req)) return 0;

    return 1;
}

bool isrect(point p0,point p1,point p2,point p3){

    if(!iseq(sq_distance(p0,p1),sq_distance(p2,p3))) return 0;
    if(!iseq(sq_distance(p0,p3),sq_distance(p1,p2))) return 0;

    double alpha,req=pi/2.0;

    alpha=ang(p1,p0,p2);
    if(!iseq(alpha,req)) return 0;

    alpha=ang(p2,p1,p3);
    if(!iseq(alpha,req)) return 0;

    alpha=ang(p3,p2,p0);
    if(!iseq(alpha,req)) return 0;

    alpha=ang(p0,p3,p1);
    if(!iseq(alpha,req)) return 0;

    return 1;
}




int n;
int a[]={1,2,3,4,5,6,7,8};

int main(){

    int i,j,k,l,test,t=1;

    


    for(i=1;i<=8;i++){
        scanf("%d %d",&k,&l);
        p[i]=point(k,l);
    }

    do{
        if(!issquare(p[a[0]],p[a[1]],p[a[2]],p[a[3]])) continue;
        if(!isrect(p[a[4]],p[a[5]],p[a[6]],p[a[7]])) continue;
        printf("YES\n");
        for(i=0;i<8;i++){
            if(i!=0 && i!=4) printf(" ");
            if(i==4) printf("\n");
            printf("%d",a[i]);
        }
        printf("\n");
        return 0;

    }while(next_permutation(a,a+8));

    printf("NO\n");

    return 0;
}
