





































































































































































































































































































































































































































































































































































































































int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

using namespace std;

template< class T > T sq(T n) {
    return n*n;
}
template< class T > T gcd(T a, T b) {
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b) {
    return (a / gcd<T>(a, b) * b);
}
template< class T > bool inside(T a, T b, T c) {
    return a<=b && b<=c;
}
template< class T > void setmax(T &a, T b) {
    if(a < b) a = b;
}
template< class T > void setmin(T &a, T b) {
    if(b < a) a = b;
}
template< class T > T power(T N,T P) {
    return (P==0)?  1: N*power(N,P-1);
}

struct point {
    LLD x,y ;
} C[100010], a, b, c ;

LLD id1(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

bool out = 1;

bool id0(int nc, const point &p) {
    LLD st = 1, en = nc - 1, mid, c;
    while(en - st > 1) {
        mid = (st + en)>>1;
        if(id1(C[0], C[mid], p) < 0) en = mid;
        else st = mid;
    }

    LLD r0 = abs(id1(C[0], C[st], C[en]));
    LLD r1 = abs(id1(C[0], C[st], p));
    LLD r2 = abs(id1(C[0], C[en], p));
    LLD r3 = abs(id1(C[st], C[en], p));
    LLD r4 = id1(C[0], C[1], p);
    LLD r5 = id1(C[0], C[nc-1], p);

    if(r0 == (r1 + r2 + r3) && r3 != 0 && r4 != 0 && r5 != 0);
    else
        out = 0;
}


int main() {
    int n,T,t=1,m,i,j,k;
    

    

    

    

    















    scanf("%d",&n) ;

    rep(i,0,n) {
        scanf("%d",&m);
        C[i].x = m ;
        scanf("%d",&m);
        C[i].y = m ;
    }
    reverse(C,C+n) ;
    C[n] = C[0] ;
    SD(k) ;
    bool f = 1 ;
    point p ;
    while(k--) {
        scanf("%d",&m);
        p.x = m ;
        scanf("%d",&m);
        p.y = m ;
        if(!id0(n,p))
            f = 0;
    }

    if(out)    puts("YES") ;
    else  puts("NO") ;

    return 0;
}
