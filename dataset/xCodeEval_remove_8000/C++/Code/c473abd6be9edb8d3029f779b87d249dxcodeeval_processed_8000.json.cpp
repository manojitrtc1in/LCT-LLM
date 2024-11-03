
using namespace std;









const LD ERR = 1e-6;
const LD PI = acos(-1.0);
bool isZero( LD );
bool areEqual( LD, LD );
LD id1( LD );
bool id4( LD );




struct point{
    LD x, y;

    point(){ x = y = 0; }
    point( LD _x, LD _y ) : x(_x) , y(_y) {}

    bool input(){ return bool(cin >> x >> y); }
    void print(){ cout << "(" << x << "," << y << ")" << endl; }
    bool operator < ( const point &o ) const{
        if( !areEqual( x, o.x ) ) return x < o.x;
        return y < o.y;
    }
    bool operator == ( const point &o ) const{ return areEqual( x, o.x ) && areEqual( y, o.y ); }
} const INVALID_POINT(NAN,NAN), ORIGIN(0,0) ;
LD angle( point, point, point );
LD distance( point, point );
bool ccw( point, point, point );
bool collinear( point, point, point );

struct Vector{
    LD x, y;

    Vector(){}
    Vector( LD _x, LD _y ) : x(_x) , y(_y) {}

    LD operator * ( const Vector &o ) const{ return x * o.x + y * o.y; }
    LD modulo(){ return sqrt( x*x + y*y ); }
    LD moduloNSQ(){ return x*x + y*y; }
};
Vector toVector( point, point );
Vector scale( Vector, LD );
point translate( point, Vector );

struct lineSegment{
    point T1, T2;
    LD a, b, c;

    lineSegment(){}
    lineSegment( point t1, point t2 ) : T1(t1) , T2(t2) {
        if( fabs(t1.x - t2.x) < ERR ) { a = 1.0; b = 0.0; c = -t1.x; }
        else{
            a = -(LD)(t1.y - t2.y) / (t1.x - t2.x);
            b = 1.0;
            c = -(LD)(a * t1.x) - t1.y;
        }
    }

    LD length(){
        return toVector(T1,T2).modulo();
    }
    bool input(){

        if( !T1.input() ) return false;
        if( !T2.input() ) return false;
        if( fabs(T1.x - T2.x) < ERR ) { a = 1.0; b = 0.0; c = -T1.x; }
        else{
            a = -(LD)(T1.y - T2.y) / (T1.x - T2.x);
            b = 1.0;
            c = -(LD)(a * T1.x) - T1.y;
        }
        return true;

    }
    bool contains( point P ){
        if( !isZero( a*P.x + b*P.y + c ) ) return false;
        LD Lx = min( T1.x, T2.x );
        LD Rx = max( T1.x, T2.x );
        LD Ly = min( T1.y, T2.y );
        LD Ry = max( T1.y, T2.y );
        return ( Lx < P.x || areEqual( Lx, P.x ) ) && ( P.x < Rx || areEqual( P.x, Rx ) ) && ( Ly < P.y || areEqual( Ly, P.y ) ) && ( P.y < Ry || areEqual( P.y, Ry ) );
    }
    bool operator == ( lineSegment &o ) const{
        return areEqual( a, o.a ) && areEqual( b, o.b ) && areEqual( c, o.c ) && T1 == o.T1 && T2 == o.T2;
    }
};

struct line{
    LD a, b, c;

    line(){}
    line( LD _a, LD _b, LD _c ) : a(_a) , b(_b) , c(_c) { line::fix(); }
    line( point A, point B ){
        if( fabs(A.x - B.x) < ERR ) { a = 1.0; b = 0.0; c = -A.x; }
        else{
            a = -(LD)(A.y - B.y) / (A.x - B.x);
            b = 1.0;
            c = -(LD)(a * A.x) - A.y;
        } 
    }
    line( lineSegment LS ){
        a = LS.a; b = LS.b; c = LS.c;
        line::fix();
    }

    bool input(){ return bool( cin >> a >> b >> c ); }
    void print(){ cout << a << "x + " << b << "y + " << c << " = " << 0 << endl; }
    bool operator == ( const line &o ) const{ return areEqual( a, o.a ) && areEqual( b, o.b ) && areEqual( c, o.c ); }
    bool contains( point P ){ return isZero( a*P.x + b*P.y + c ); }
    void fix(){
        if( isZero(b) ) return;
        a /= b;
        c /= b;
        b = 1.0;
    }
    line findPerpendicular( point M ){

        line::fix();

        if( isZero(a) ) return line( 1, 0, -M.x );
        if( isZero(b) ) return line( 0, 1, -M.y );

        LD a2 = -1.0/a;
        LD k2 = -M.y - a2*M.x;

        return line( a2, 1, k2 );

    }
};
point intersectionPoint( line, line );

struct circle{
    point O; LD r;

    circle(){}
    circle( LD _r ) : r(_r) { O = ORIGIN; }
    circle( point _p, LD _r ) : O(_p) , r(_r) {}
    circle( point P1, point P2, LD _r ) : r(_r) {
        LD _T = (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y);
        LD __T = r * r / _T - 0.25;
        if( __T < -ERR ){ O = INVALID_POINT; return; }
        LD h = sqrt( __T );
        O = point( (P1.x + P2.x) * 0.5 + (P1.y - P2.y) * h, (P1.y + P2.y) * 0.5 + (P2.x - P1.x) * h );
    }

    void print(){
        if( isZero( O.x ) ){
            cout << "x^2";
        }else{
            cout << "(x ";
            if( O.x > 0 ) cout << '-';
            else          cout << '+';
            cout << ' ' << fabs(O.x) << ")^2";
        }
        cout << " + ";
        if( isZero( O.y ) ){
            cout << "y^2";
        }else{
            cout << "(y ";
            if( O.y > 0 ) cout << '-';
            else          cout << '+';
            cout << ' ' << fabs(O.y) << ")^2";
        }
        cout << " = " << r << "^2" << endl;
    }
    LD diameter(){ return 2*r; }
    LD perimeter(){ return 2*PI*r; }
    LD area(){ return PI*r*r; }
    LD arc( LD ANG ){ return ANG * circle::perimeter() / 360.0; }
    LD chord( LD ANG ){ return 2*r*sin(id1(ANG)/2); }
    LD sector( LD ANG ){ return ANG * circle::area() / 360.0; }
    LD segment( LD ANG ){
        LD s = ( r + r + circle::chord(ANG) ) / 2;
        LD TA = sqrt( s*(s-r)*(s-r)*(s-circle::chord(ANG)) );
        return circle::sector(ANG) - TA;
    }
    bool contains( point T ){
        return r*r - (T.x-O.x)*(T.x-O.x) - (T.y-O.y)*(T.y-O.y) > -ERR; 

        return r*r - (T.x-O.x)*(T.x-O.x) - (T.y-O.y)*(T.y-O.y) > 0; 

    }
};

struct triangle{

    point A, B, C;
    lineSegment a, b, c;
    lineSegment ha, hb, hc;
    LD a_, b_, c_;
    LD ha_, hb_, hc_;

    triangle(){
        triangle::reset();
    }
    triangle( point _a, point _b, point _c ){
        triangle::reset();
        A = _a; B = _b; C = _c;
        a = lineSegment(B,C); b = lineSegment(A,C); c = lineSegment(A,B);
        a_ = a.length(); b_ = b.length(); c_ = c.length();
    }
    triangle( LD q, LD w, LD e ) : a_(q) , b_(w) , c_(e) {}

    void refreshLineLengths(){
        a_ = a.length(); b_ = b.length(); c_ = c.length();
        ha_ = ha.length(); hb_ = hb.length(); hc_ = hc.length();
    }
    void reset(){
        A = B = C = INVALID_POINT;
        a.T1 = a.T2 = b.T1 = b.T2 = c.T1 = c.T2 = INVALID_POINT;
        ha.T1 = ha.T2 = hb.T1 = hb.T2 = hc.T1 = hc.T2 = INVALID_POINT;
        a_ = b_ = c_ = NAN;
        ha_ = hb_ = hc_ = NAN;
    }
    bool isValid(){
        return a_ + b_ > c_ && a_ + c_ > b_ && b_ + c_ > a_;
    }
    bool isEquilateral(){
        return areEqual( a_, b_ ) && areEqual( b_, c_ );
    }
    bool isIsosceles(){
        return triangle::isEquilateral() == triangle::isScalene();
    }
    bool isScalene(){
        return !areEqual( a_, b_ ) && !areEqual( a_, c_ ) && !areEqual( b_, c_ );
    }
    LD baseArea(){
        if( id4( ha.T1.x ) && id4( a.T1.x ) ) return 0.5 * ha_ * a_;
        if( id4( hb.T1.x ) && id4( b.T1.x ) ) return 0.5 * hb_ * b_;
        if( id4( hc.T1.x ) && id4( c.T1.x ) ) return 0.5 * hc_ * c_;
        return NAN;
    }
    LD perimeter(){
        return a_ + b_ + c_;
    }
    LD semiperimeter(){
        return triangle::perimeter()/2;
    }
    LD heronArea(){
        LD s = triangle::semiperimeter();
        return sqrt( s*(s-a_)*(s-b_)*(s-c_) );
    }
    LD inCircleRadius(){
        return triangle::heronArea() / triangle::semiperimeter();
    }
    point inCirclePoint(){

        LD r = triangle::inCircleRadius();
        if( fabs(r) < 0 ) return INVALID_POINT;

        line L1, L2;
        LD RATIO = distance( A, B ) / distance( A, C );
        point P = translate( B, scale( toVector( B, C ), RATIO / ( 1+RATIO ) ) );
        L1 = line( A, P );
        RATIO = distance( B, A ) / distance( B, C );
        P = translate( A, scale( toVector( A, C ), RATIO / ( 1+RATIO ) ) );
        L2 = line( B, P );
        return intersectionPoint( L1, L2 );

    }
    LD outCircleRadius(){
        return a_*b_*c_ / ( 4*triangle::heronArea() );
    }
    point outCirclePoint(){
        point P1( (A.x+B.x)/2, (A.y+B.y)/2 );
        line L1 = line(c).findPerpendicular( P1 );
        point P2( (C.x+B.x)/2, (C.y+B.y)/2 );
        line L2 = line(a).findPerpendicular( P2 );
        return intersectionPoint( L1, L2 );
    }
    bool contains( point P ){

        LD L1 = (  (B.y-C.y)*(P.x-C.x) + (C.x-B.x)*(P.y-C.y)  ) / (  (B.y-C.y)*(A.x-C.x) + (C.x-B.x)*(A.y-C.y)  );
        LD L2 = (  (C.y-A.y)*(P.x-C.x) + (A.x-C.x)*(P.y-C.y)  ) / (  (B.y-C.y)*(A.x-C.x) + (C.x-B.x)*(A.y-C.y)  );
        LD L3 = 1 - L1 - L2;

        return 0-ERR <= L1 && L1 <= 1+ERR && 0-ERR <= L2 && L2 <= 1+ERR && 0-ERR <= L3 && L3 <= 1+ERR; 

        return 0 < L1 && L1 < 1 && 0 < L2 && L2 < 1 && 0 < L3 && L3 < 1; 


    }
    bool isObtuse(){
        LD x = a_*a_, y = b_*b_, z = c_*c_;
        if( x == max( x, max( y, z ) ) ) swap( x, z );
        else if( y == max( x, max( y, z ) ) ) swap( y, z );
        return x + y < z;
    }
    bool isRight(){
        LD x = a_*a_, y = b_*b_, z = c_*c_;
        if( x == max( x, max( y, z ) ) ) swap( x, z );
        else if( y == max( x, max( y, z ) ) ) swap( y, z );
        return areEqual( x+y, z );
    }
    bool isAcute(){
        LD x = a_*a_, y = b_*b_, z = c_*c_;
        if( x == max( x, max( y, z ) ) ) swap( x, z );
        else if( y == max( x, max( y, z ) ) ) swap( y, z );
        return x + y > z;
    }
};

struct rectangle{
    

    point UL, BL, UR, BR;
    lineSegment a, b, c, d;
    LD a_, b_, c_, d_;

    rectangle(){
        rectangle::reset();
    }
    rectangle( point pa, point pb ){
        rectangle::reset();
        LD minX, maxX, minY, maxY;
        minX = min( pa.x, pb.x );
        maxX = max( pa.x, pb.x );
        minY = min( pa.y, pb.y );
        maxY = max( pa.y, pb.y );
        UL = point( minX, minY ); BR = point( maxX, maxY );
        BL = point( BR.x, UL.y );
        UR = point( UL.x, BR.y );
        a = lineSegment( UL, UR );
        b = lineSegment( BL, BR );
        c = lineSegment( UL, BL );
        d = lineSegment( UR, BR );
        a_ = a.length();
        b_ = b.length();
        c_ = c.length();
        d_ = d.length();
    }
    rectangle( point pa, point pb, bool id3 ){
        rectangle::reset();
        if( id3 ){
            UL = pa; BR = pb;
            BL = point( BR.x, UL.y );
            UR = point( UL.x, BR.y );
        }else{
            BL = pa; UR = pb;
            BR = point( UR.x, BL.y );
            UL = point( BL.x, UR.y );
        }
        a = lineSegment( UL, UR );
        b = lineSegment( BL, BR );
        c = lineSegment( UL, BL );
        d = lineSegment( UR, BR );
        a_ = a.length();
        b_ = b.length();
        c_ = c.length();
        d_ = d.length();
    }
    rectangle( LD _a, LD _b ){
        rectangle::reset();
        a_ = b_ = _a;
        c_ = d_ = _b;
    }

    void reset(){
        UL = BL = UR = BR = INVALID_POINT;
        a.T1 = a.T2 = b.T1 = b.T2 = c.T1 = c.T2 = d.T1 = d.T2 = INVALID_POINT;
        a_ = b_ = c_ = d_ = NAN;
    }
    LD area(){
        return a_ * c_;
    }
    LD perimeter(){
        return 2*a_ + 2*c_;
    }
    bool contains( point P ){
        LD minX = min( UL.x, BR.x );
        LD maxX = max( UL.x, BR.x );
        LD minY = min( UL.y, BR.y );
        LD maxY = max( UL.y, BR.y );
        return ( areEqual( P.x, minX ) || minX < P.x ) && ( areEqual( P.y, minY ) || minY < P.y ) && ( areEqual( P.x, maxX ) || maxX > P.x ) && ( areEqual( P.y, maxY ) || maxY > P.y );
        return minX < P.x && minY < P.y && maxX > P.x && maxY > P.y; 

    }
    void print(){
        cout << "= = = = = = = = = = = = = = = =" << endl;
        cout << "(" << UL.x << ',' << UL.y << ")         (" << UR.x << ',' << UR.y << ")" << endl;
        cout << endl;
        cout << "(" << BL.x << ',' << BL.y << ")         (" << BR.x << ',' << BR.y << ")" << endl;
        cout << "= = = = = = = = = = = = = = = =" << endl;
    }
};

struct polygon{
    int N;
    vector <point> P;

    polygon(){}
    polygon( vector <point> &_P ){
        if( _P.empty() ) { N = 0; return; }
        if( _P.size() == 1 || !( _P[(int)_P.size()-1] == _P[0] ) ) _P.push_back(_P[0]);
        N = _P.size();
        P = _P;
    }

    void print(){

    cout << endl;
    for(int i=0;i<P.size();i++) P[i].print();
    cout << endl;

}
    LD perimeter(){
        LD rv = 0.0;
        for (int i = 0; i < N-1; i++)
            rv += distance(P[i], P[i+1]);
        return rv;
    }
    LD area(){
        if( N < 3 ) return 0;
        LD rv = 0.0, x1, y1, x2, y2;
        for( int i = 0 ; i < N-1 ; i++ ){
            x1 = P[i].x;
            x2 = P[i + 1].x;
            y1 = P[i].y;
            y2 = P[i + 1].y;
            rv += (x1 * y2 - x2 * y1);
        }
        return fabs(rv) / 2.0;
    }
    bool isConvex(){
        if( N <= 3 ) return false;        
        bool isLeft = ccw(P[0], P[1], P[2]);
        for( int i = 1 ; i < N - 1 ; i++ ) if( ccw(P[i], P[i + 1], P[(i + 2) == N ? 1 : i + 2] ) != isLeft ) return false;
        return true;
    }
    bool contains( point pt ){
        if( !N ) return false;
        LD SUM = 0;
        for( int i=0 ; i < N-1 ; i++ ){
            if( pt == P[i] ) return true;
            if( ccw(pt, P[i], P[i + 1]) ) SUM += id1(angle(P[i], pt, P[i + 1]));
            else                          SUM -= id1(angle(P[i], pt, P[i + 1]));
        }
        

        return fabs(fabs(SUM) - 2*PI) < ERR;
    }
    void fixOrientation(){

        if( !N ) return;
        for(int i=0;i+2<N;i++){
            if( collinear( P[i], P[i+1], P[i+2] ) ) continue;
            if( !ccw( P[i], P[i+1], P[i+2] ) ) reverse( P.begin(), P.end() );
            return;
        }
        if( P[0] < P[1] ) reverse( P.begin(), P.end() );

    }
    point convexCentroid(){

        LD Cx = 0, Cy = 0;
        LD A = polygon::area() * 6.0;
        for(int i=0;i<N-1;i++) Cx += ( P[i].x + P[i+1].x ) * ( P[i].x*P[i+1].y - P[i+1].x*P[i].y ) / A;
        for(int i=0;i<N-1;i++) Cy += ( P[i].y + P[i+1].y ) * ( P[i].x*P[i+1].y - P[i+1].x*P[i].y ) / A;
        return point( Cx, Cy );

    }
};




LD id5( point, point );
point rotate( point, LD );
int sgn( LD );
point rotateRelative( point, point, LD );
point movePoint( point, LD, LD );
point movePoint( point, point );
bool areParallel( line, line );
LD distance( point, line );
point intersectionPoint( point, point, point );
LD pointSide( point, point, point );
bool id10( line );
LD distance( point, lineSegment );
point intersectionPoint( point, lineSegment );
point intersectionPoint( lineSegment, lineSegment );
bool lineIntersection( lineSegment, lineSegment );
point divPoint( lineSegment, LD );
Vector toVector( point, point );
LD cross( Vector, Vector );
LD cross( point&, point&, point& );
int id6( point, circle );
int intersectionPoints( point, point, circle, point&, point& );
int intersectionPoints( line, circle, point&, point& );
void intersectionPoints( circle, circle, point&, point& );
bool id8( lineSegment, lineSegment, lineSegment );
bool id8( point, point, point );
bool id2( LD, LD, LD, LD );
bool id11( LD, LD, LD, LD );
bool id12( LD, LD, LD, LD );
rectangle intersectionRectangle( rectangle, rectangle );
rectangle intersectionRectangle( vector <rectangle>& );
polygon cutPolygon( point, point, polygon );
void cutPolygon( point, point, polygon&, polygon&, polygon& );
polygon id7( vector <point>& );




bool isZero( LD x ){
    return fabs(x) < ERR;
}
bool areEqual( LD x, LD y ){
    return fabs(x-y) < ERR;
}
LD id1( LD ANG ){
    return  ANG * PI / 180.0;
}
int sgn( LD x ){
    if( x < -ERR ) return -1;
    return 1;
}
bool id4( LD x ){
    return areEqual( x, x );
}




LD distance( point A, point B ){
    return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
}
LD id5( point A, point B ){
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}
point rotate( point P, LD ANG ){
    LD RAD = id1( ANG );
    return point( P.x * cos(RAD) - P.y * sin(RAD) , P.x * sin(RAD) + P.y * cos(RAD) );
}
point rotateRelative( point P, point R, LD ANG ){
    Vector RO = toVector( R, point(0,0) );
    P = translate( P, RO );
    P = rotate( P, ANG );
    Vector OR = toVector( point(0,0), R );
    P = translate( P, OR );
    return P;
}
LD angle( point A, point O, point B ){
    Vector OA = toVector( O, A ), OB = toVector( O, B );
    return acos( OA*OB / sqrt( OA.moduloNSQ() * OB.moduloNSQ() ) ) * 180.0 / PI;
}
point movePoint( point P, LD x, LD y ){
    return point( P.x+x, P.y+y );
}
point movePoint( point P, point T ){
    return point( P.x+T.x, P.y+T.y );
}
bool ccw( point A, point B, point C ){
    LD CROSS = cross( toVector( A, B ), toVector( A, C ) );
    return CROSS > 0 || isZero( CROSS ); 

}




bool areParallel( line A, line B ){

    if( isZero(A.a) && areEqual( A.a, B.a ) ) return true;
    if( isZero(A.b) && areEqual( A.b, B.b ) ) return true;
    return areEqual( A.a, B.a ) && areEqual( A.b, B.b );

}
point intersectionPoint( line A, line B ){

    point P;

    if( id10(A) || id10(B) ) return INVALID_POINT;
    if( areParallel(A, B) ) return INVALID_POINT;

    P.x = (B.b * A.c - A.b * B.c) / (B.a * A.b - A.a * B.b);

    if( !isZero(A.b) ) P.y = -(A.a * P.x + A.c);
    else               P.y = -(B.a * P.x + B.c);
    return P;

}
LD distance( point M, line L ){
    return fabs( ( L.a*M.x + L.b*M.y + L.c ) / ( sqrt( L.a*L.a + L.b*L.b ) ) );
}
point intersectionPoint( point P, point A, point B ){
    Vector AP = toVector( A, P );
    Vector AB = toVector( A, B );
    LD u = AP*AB/AB.moduloNSQ();
    return translate( A, scale( AB, u ) );
}
LD pointSide( point A, point B, point P ){
    

    

    

    return cross( toVector( A, B ), toVector( A, P ) );
}
bool collinear( point A, point B, point P ){
    return fabs(pointSide( A, B, P )) < ERR;
}
bool id10( line L ){
    return isZero(L.a) && isZero(L.b);
}




LD distance( point P, lineSegment L ){
    Vector AP = toVector( L.T1, P ), AB = toVector( L.T1, L.T2 );
    LD u = AP*AB/AB.moduloNSQ();
    if( u < 0.0 ) return distance( P, L.T1 );
    if( u > 1.0 ) return distance( P, L.T2 );
    return distance( P, intersectionPoint( P, L.T1, L.T2 ) );
}
point intersectionPoint( point P, lineSegment L ){
    Vector AP = toVector( L.T1, P ), AB = toVector( L.T1, L.T2 );
    LD u = AP*AB/AB.moduloNSQ();
    if( u < 0.0 ) return L.T1;
    if( u > 1.0 ) return L.T2;
    return intersectionPoint( P, L.T1, L.T2 );
}
point intersectionPoint( lineSegment _A, lineSegment _B ){

    line A( _A.a, _A.b, _A.c );
    line B( _B.a, _B.b, _B.c );

    point P;

    if( id10(A) || id10(B) ) return INVALID_POINT;
    if( _A.T1 == _B.T1 ) return _A.T1;
    if( _A.T1 == _B.T2 ) return _A.T1;
    if( _A.T2 == _B.T1 ) return _A.T2;
    if( _A.T2 == _B.T2 ) return _A.T2;
    if( areParallel(A, B) ) return INVALID_POINT;

    P.x = (B.b * A.c - A.b * B.c) / (B.a * A.b - A.a * B.b);

    if( !isZero(A.b) ) P.y = -(A.a * P.x + A.c);
    else               P.y = -(B.a * P.x + B.c);
    
    if( _A.contains(P) && _B.contains(P) ) return P;
    return INVALID_POINT;

}
bool lineIntersection( lineSegment A, lineSegment B ){
    int K =  A.contains( B.T1 ) + A.contains( B.T2 ) + B.contains( A.T1 ) + B.contains( A.T2 );
    if( A.T1 == B.T2 || A.T1 == B.T1 ) K--;
    if( A.T2 == B.T2 || A.T2 == B.T1 ) K--;
    return K >= 2;
}
point divPoint( lineSegment LS, LD ratio ){
    return point( ( LS.T1.x + ratio*LS.T2.x ) / ( 1 + ratio ), ( LS.T1.y + ratio*LS.T2.y ) / ( 1 + ratio ) );
}




Vector toVector( point A, point B ){
    return Vector( B.x-A.x , B.y-A.y );
}
Vector scale( Vector V, LD S ){
    return Vector( V.x * S, V.y * S );
}
point translate( point P, Vector V ){
    return point( P.x + V.x, P.y + V.y );
}
LD cross( Vector A, Vector B ){ return A.x * B.y - A.y * B.x; }
LD cross( point &O, point &A, point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}




int id6( point P, circle C ){
    point _P( P.x - C.O.x, P.y - C.O.y );
    LD _E = _P.x*_P.x + _P.y*_P.y, _R = C.r*C.r;
    if( areEqual( _E, _R ) ) return 0; 

    if( _E < _R ) return -1; 

    return 1; 

}
int intersectionPoints( point A, point B, circle C, point &IP1, point &IP2 ){

    LD dx = B.x - A.x;
    LD dy = B.y - A.y;
    LD dr = sqrt( dx*dx + dy*dy );
    LD D = A.x*B.y - B.x*A.y;
    if( C.r*C.r*dr*dr - D*D < 0 ){
        IP1 = IP2 = INVALID_POINT; return 0;
    }
    LD DELTA = sqrt( C.r*C.r*dr*dr - D*D );
    
    IP1 = point( ( D*dy + sgn(dy)*dx*DELTA )/(dr*dr), ( -D*dx + fabs(dy)*DELTA )/(dr*dr)  );
    IP2 = point( ( D*dy - sgn(dy)*dx*DELTA )/(dr*dr), ( -D*dx - fabs(dy)*DELTA )/(dr*dr)  );

    if( isZero( DELTA ) ) return 1;
    else                  return 2;

}
int intersectionPoints( line A, circle C, point &IP1, point &IP2 ){

    

    

    LD a = A.a; LD b = A.b; LD c = A.c;
    LD x0 = C.O.x; LD y0 = C.O.y; LD r = C.r;

    if( isZero( A.b ) ){

        LD _A = 1;
        LD _B = -2*y0;
        LD _C = c*c/a/a + 2*c/a*x0 + x0*x0 + y0*y0 - r*r;

        LD DELTA = _B*_B - 4*_A*_C;
        if( DELTA < -ERR ){
            IP1 = IP2 = INVALID_POINT; return 0;
        }

        IP1 = point( -c/a, ( -_B + sqrt( DELTA ) ) / (2*_A) );
        IP2 = point( -c/a, ( -_B - sqrt( DELTA ) ) / (2*_A) );

        return 2 - isZero( DELTA );

    }

    LD _A = a+1;
    LD _B = 2*a*y0 + 2*a*c - 2*x0;
    LD _C = c*c + 2*c*y0 + x0*x0 + y0*y0 - r*r;

    LD DELTA = _B*_B - 4*_A*_C;
    if( DELTA < -ERR ){
        IP1 = IP2 = INVALID_POINT; return 0;
    }

    IP1 = point( ( -_B + sqrt( DELTA ) ) / (2*_A), -a*( ( -_B + sqrt( DELTA ) ) / (2*_A) ) - c );
    IP2 = point( ( -_B - sqrt( DELTA ) ) / (2*_A), -a*( ( -_B - sqrt( DELTA ) ) / (2*_A) ) - c ); 

    return 2 - isZero( DELTA );   


}
void intersectionPoints( circle C1, circle C2, point &IP1, point &IP2 ){

    point T1 = C1.O, T2 = C2.O;

    LD W = C2.r*C2.r - C1.r*C1.r - T2.x*T2.x - T2.y*T2.y + T1.x*T1.x + T1.y*T1.y;
    LD k = 2*T2.y - 2*T1.y;
    LD Q = 2*T1.x - 2*T2.x;

    if( isZero(Q) ){ 

        LD y = ( C2.r*C2.r - C1.r*C1.r + T1.x*T1.x + T1.y*T1.y - T2.x*T2.x - T2.y*T2.y ) / ( -2*T2.y + 2*T1.y );
        LD x1 = T1.x + sqrt( C1.r*C1.r - (T1.y-y)*(T1.y-y) );
        LD x2 = T1.x - sqrt( C1.r*C1.r - (T1.y-y)*(T1.y-y) );
        IP1 = point( x1, y );
        IP2 = point( x2, y ); 
        return;

    }

    W /= Q; k /= Q; Q = 1.0;

    LD _A = k*k + Q*Q;
    LD _B = -Q*2*k*T1.x - Q*Q*2*T1.y + 2*W*k;
    LD _C = W*W - Q*2*T1.x*W + Q*Q*T1.x*T1.x + Q*Q*T1.y*T1.y - Q*Q*C1.r*C1.r;

    LD DELTA = _B*_B - 4*_A*_C;
    
    if( DELTA < 0 ){
        IP1 = IP2 = INVALID_POINT; return;
    }

    LD y1 = ( -_B + sqrt( DELTA ) ) / ( 2*_A );
    LD x1 = ( W + k*y1 ) / Q;
    LD y2 = ( -_B - sqrt( DELTA ) ) / ( 2*_A );
    LD x2 = ( W + k*y2 ) / Q;

    IP1 = point( x1, y1 );
    IP2 = point( x2, y2 );

}
circle id9( circle C1, circle C2 ){

    LD r1 = C1.r, r2 = C2.r;
    LD x1 = C1.O.x, y1 = C1.O.y, x2 = C2.O.x, y2 = C2.O.y;
    LD A = r2*r2 - r1*r1;
    LD B = 2*r1*r1*x2 - 2*r2*r2*x1;
    LD C = 2*r1*r1*y2 - 2*r2*r2*y1;
    LD D = r2*r2*x1*x1 + r2*r2*y1*y1 - r1*r1*x2*x2 - r1*r1*y2*y2;

    return circle( point( -B/A/2, -C/A/2 ), sqrt(-D/A + (B/A/2*B/A/2) + (C/A/2*C/A/2)) );

}




bool id8( lineSegment a, lineSegment b, lineSegment c ){
    return a.length() + b.length() > c.length() && a.length() + c.length() > b.length() && b.length() + c.length() > a.length();
}
bool id8( point A, point B, point C ){
    return id8( lineSegment(A,B), lineSegment(B,C), lineSegment(A,C) );
}




bool id2( LD a, LD b, LD c, LD d ){
    return areEqual( a, b ) && areEqual( b, c ) && areEqual( c, d );
}
bool id11( LD a, LD b, LD c, LD d ){
    return ( areEqual( a, b ) && areEqual( c, d ) ) || ( areEqual( a, c ) && areEqual( b, d ) ) || ( areEqual( a, d ) && areEqual( b, c ) );
}
bool id12( LD a, LD b, LD c, LD d ){
    LD maxSide = max( max( a, b ), max( c, d ) );
    if( areEqual( a, maxSide ) ) return a < b + c + d;
    if( areEqual( b, maxSide ) ) return b < a + c + d;
    if( areEqual( c, maxSide ) ) return c < a + b + d;
    if( areEqual( d, maxSide ) ) return d < a + b + c;
    return false;
}
rectangle intersectionRectangle( rectangle A, rectangle B ){

    vector <point> intersectionPoints;

    if( A.contains( B.UL ) ) intersectionPoints.push_back( B.UL );
    if( A.contains( B.UR ) ) intersectionPoints.push_back( B.UR );
    if( A.contains( B.BL ) ) intersectionPoints.push_back( B.BL );
    if( A.contains( B.BR ) ) intersectionPoints.push_back( B.BR );
    if( B.contains( A.UL ) ) intersectionPoints.push_back( A.UL );
    if( B.contains( A.UR ) ) intersectionPoints.push_back( A.UR );
    if( B.contains( A.BL ) ) intersectionPoints.push_back( A.BL );
    if( B.contains( A.BR ) ) intersectionPoints.push_back( A.BR );

    vector <lineSegment> L1, L2;

    L1.push_back( A.a ); L1.push_back( A.b ); L1.push_back( A.c ); L1.push_back( A.d );
    L2.push_back( B.a ); L2.push_back( B.b ); L2.push_back( B.c ); L2.push_back( B.d );

    for(int i=0;i<L1.size();i++) for(int j=0;j<L2.size();j++){
        point IP = intersectionPoint( L1[i], L2[j] );
        if( id4( IP.x ) ) intersectionPoints.push_back( IP );
    }

    if( intersectionPoints.empty() ) return rectangle( INVALID_POINT, INVALID_POINT );

    point UL( INF, INF ), BR( -INF, -INF );

    for(int i=0;i<intersectionPoints.size();i++){
        UL.x = min( UL.x, intersectionPoints[i].x );
        UL.y = min( UL.y, intersectionPoints[i].y );
        BR.x = max( BR.x, intersectionPoints[i].x );
        BR.y = max( BR.y, intersectionPoints[i].y );
    }

    return rectangle( UL, BR );

}
rectangle intersectionRectangle( vector <rectangle> &V ){

    rectangle rv = V[0];

    for(int i=1;i<V.size();i++) rv = intersectionRectangle( rv, V[i] );

    return rv;

}




polygon cutPolygon( point a, point b, polygon &Q ){
    vector <point> P;
    for( int i=0 ; i < Q.N ; i++ ){
        LD left1 = cross( toVector(a, b), toVector(a, Q.P[i]) );
        LD left2 = 0;
        if (i != Q.N - 1) left2 = cross( toVector(a, b), toVector(a, Q.P[i + 1]) );
        if (left1 > -ERR) P.push_back(Q.P[i]);
        if (left1 * left2 < -ERR) P.push_back( intersectionPoint( lineSegment( Q.P[i], Q.P[i + 1] ) , lineSegment(a, b) ) );
    }
    if (!P.empty() && !(P.back() == P.front())) P.push_back(P.front());
    return polygon(P);
}
void cutPolygon( point a, point b, polygon &Q, polygon &p1, polygon &p2 ){
    vector <point> P1, P2;
    for( int i=0 ; i < Q.N ; i++ ){
        LD left1 = cross( toVector(a, b), toVector(a, Q.P[i]) );
        LD left2 = 0;
        if (i != Q.N - 1) left2 = cross( toVector(a, b), toVector(a, Q.P[i + 1]) );
        if (left1 > -ERR) P1.push_back(Q.P[i]); else P2.push_back(Q.P[i]);
        if (left1 * left2 < -ERR){
            point IP = intersectionPoint( lineSegment( Q.P[i], Q.P[i + 1] ) , lineSegment(a, b) );
            P1.push_back( IP );
            P2.push_back( IP );
        }
    }
    p1 = polygon(P1);
    p2 = polygon(P2);
}
polygon id7( vector <point> &P ){
	int n = P.size(), k = 0;
	if (n <= 3){
        polygon rv(P);
        rv.fixOrientation();
        return rv;
    }
	vector <point> H(2*n);

	sort(P.begin(), P.end());

	for (int i = 0; i < n; i++) {
        if( i && P[i] == P[i-1] ) continue;
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < ERR) k--;
		H[k++] = P[i];
	}

	for (int i = n-1, t = k+1; i > 0; i--) {
        if( i && P[i] == P[i-1] ) continue;
		while (k >= t && cross(H[k-2], H[k-1], P[i-1]) < ERR) k--;
		H[k++] = P[i-1];
	}

	H.resize(k);
	polygon rv = H;
    rv.fixOrientation();
	return rv;
}
polygon intersectionPolygon( polygon A, polygon B ){
    vector <point> pointSet;

    for(int i=0;i<A.N-1;i++) if( B.contains( A.P[i] ) ) { pointSet.push_back( A.P[i] ); }
    for(int i=0;i<B.N-1;i++) if( A.contains( B.P[i] ) ) { pointSet.push_back( B.P[i] ); }

    for(int i=0;i<A.N-1;i++){
        for(int j=0;j<B.N-1;j++){
            point IP = intersectionPoint( lineSegment( A.P[i], A.P[i+1] ), lineSegment( B.P[j], B.P[j+1] ) );
            

            

            

            if( id4( IP.x ) ) pointSet.push_back( IP );
        }
    }

    return id7( pointSet );

}




circle C[3];

point lineSolve();
point circleSolve();
point id0();

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cout << fixed << setprecision(5);

    for(int i=0;i<3;i++){
        int x, y, r; cin >> x >> y >> r;
        C[i] = circle( point(x, y), r );
    }

    for(int i=0;i<3;i++) for(int j=i+1;j<3;j++){
        if( C[i].r > C[j].r ) swap( C[i], C[j] );
    }

    point RES;
    if( areEqual( C[0].r, C[1].r ) && areEqual( C[0].r, C[2].r ) ) RES = lineSolve();
    else if( !areEqual( C[0].r, C[1].r ) && !areEqual( C[0].r, C[2].r ) && !areEqual( C[1].r, C[2].r ) ) RES = circleSolve();
    else RES = id0(); 

    if( id4(RES.x) ) cout << RES.x << ' ' << RES.y << endl;

}

point lineSolve(){

    line L1 = line( C[0].O, C[1].O ).findPerpendicular( translate( C[0].O, scale( toVector( C[0].O, C[1].O ), 0.5 ) ) );
    line L2 = line( C[0].O, C[2].O ).findPerpendicular( translate( C[0].O, scale( toVector( C[0].O, C[2].O ), 0.5 ) ) );

    point IP = intersectionPoint( L1, L2 );

    return IP;

}

point circleSolve(){

    circle C1 = id9( C[0], C[1] );
    circle C2 = id9( C[0], C[2] );

    point IP1, IP2;
    intersectionPoints( C1, C2, IP1, IP2 );

    if( distance( IP1, C[0].O ) < distance( IP2, C[0].O ) ) return IP1;
    else                                                    return IP2;

}

point id0(){

    line L; circle CIR;

    if( areEqual( C[0].r, C[1].r ) ){
        L = line( C[0].O, C[1].O ).findPerpendicular( translate( C[0].O, scale( toVector( C[0].O, C[1].O ), 0.5 ) ) );
        CIR = id9( C[0], C[2] );
    }else{
        L = line( C[1].O, C[2].O ).findPerpendicular( translate( C[1].O, scale( toVector( C[1].O, C[2].O ), 0.5 ) ) );
        CIR = id9( C[0], C[1] );
    }

    

    


    point IP1, IP2;
    intersectionPoints( L, CIR, IP1, IP2 );

    

    


    if( distance( IP1, C[0].O ) < distance( IP2, C[0].O ) ) return IP1;
    else                                                    return IP2;

}