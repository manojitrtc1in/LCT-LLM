























const double Pi = acos(-1.0);;
const double Ee = 2.718281828459045235360;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-8;
const int MOD = 1000000009;

const int dx4[] = {-1, 0, 1,  0};
const int dy4[] = { 0, 1, 0, -1};
const int dx8[] = {-1, 0, 1,  0, -1, -1,  1, 1};
const int dy8[] = {0 , 1, 0, -1, -1,  1, -1, 1};
const int dxhorse[] = {-2, -2, -1, -1, 1,  1, 2,  2};
const int dyhorse[] = {1 , -1,  2, -2, 2, -2, 1, -1};

using namespace std;

inline int cmp(int a, int b){return a > b;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}

namespace Math{
    typedef long long typec;
    

    typec GCD(typec a, typec b)
    {
        return b ? GCD(b, a % b) : a;
    }
    typec id1(typec a, typec b, typec& x, typec& y)
    {
        if(!b) return x = 1, y = 0, a;
        typec res = id1(b, a % b, x, y), tmp = x;
        x = y, y = tmp - (a / b) * y;
        return res;
    }
    

    typec power(typec x, typec k)
    {
        typec res = 1;
        while(k)
        {
            if(k&1) res *= x;
            x *= x, k >>= 1;
        }
        return res;
    }
    

    typec powerMod(typec x, typec k, typec m)
    {
        typec res = 1;
        while(x %= m, k)
        {
            if(k&1) res *= x, res %= m;
            x *= x, k >>=1;
        }
        return res;
    }
    
    typec inverse(typec a, typec p, typec t = 1)
    {
        typec pt = power(p, t);
        typec x, y;
        y = id1(a, pt, x, y);
        return x < 0 ? x += pt : x;
    }
    
    typec id0(typec a, typec b, typec p, typec q)
    {
        typec x, y;
        y = id1(p, q, x, y);
        while(b < a) b += q / y;
        x *= b - a, x = p * x + a, x %= p * q;
        if(x < 0) x += p * q;
        return x;
    }
    
    const int id2 = 1000000;
    int prime[id2 + 1];
    int mobius[id2 + 1];
    int getPrime()
    {
        memset (prime, 0, sizeof (int) * (id2 + 1));
        memset(mobius , 0 , sizeof(mobius));
        mobius[1] = 1;
        for (int i = 2; i <= id2; i++)
        {
            if (!prime[i]) prime[++prime[0]] = i , mobius[i] = -1;
            for (int j = 1; j <= prime[0] && prime[j] <= id2 / i; j++)
            {
                prime[prime[j]*i] = 1;
                if (i % prime[j] == 0) break;
                else mobius[i * prime[j]] = -mobius[i];
            }
        }
        return prime[0]; 

    }
    
    

    int factor[100][3], facCnt;
    int getFactors(int x)
    {
        facCnt = 0;
        int tmp = x;
        for(int i = 1; prime[i] <= tmp / prime[i]; i++)
        {
            factor[facCnt][1] = 1, factor[facCnt][2] = 0;
            if(tmp % prime[i] == 0)
                factor[facCnt][0] = prime[i];
            while(tmp % prime[i] == 0)
                factor[facCnt][2]++, factor[facCnt][1] *= prime[i], tmp /= prime[i];
            if(factor[facCnt][1] > 1) facCnt++;
        }
        if(tmp != 1)
            factor[facCnt][0] = tmp, factor[facCnt][1] = tmp, factor[facCnt++][2] = 1;
        return facCnt;
    }
    

    typec id3(typec n, typec k, typec p)
    {
        if(k > n) return 0;
        if(n - k < k) k = n - k;
        typec a = 1, b = 1, x, y;
        int pcnt = 0;
        for(int i = 1; i <= k; i++)
        {
            x = n - i + 1, y = i;
            while(x % p == 0) x /= p, pcnt++;
            while(y % p == 0) y /= p, pcnt--;
            x %= p, y %= p, a *= x, b *= y;
            b %= p, a %= p;
        }
        if(pcnt) return 0;
        id1(b, p, x, y);
        if(x < 0) x += p;
        a *= x, a %= p;
        return a;
    }
    

    typec inv[100005];
    typec ba[100005];
    typec rba[100005];
    void Init_Com()
    {
        inv[0] = inv[1] = 1;
        ba[0] = ba[1] = 1;
        rba[0] = rba[1] = 1;
        for(int i = 2; i < 100005; i++) {
            inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
            ba[i] = (ba[i - 1] * i)%MOD;
            rba[i] = (rba[i - 1] * inv[i])%MOD;
        }
    }
    typec C(int n, int m)
    {
        return (ba[n]*rba[m]%MOD)*rba[n-m]%MOD;
    }
};using namespace Math;

namespace Geo{
    
    const typec eps=1e-9;
int dblcmp(double d){
    return d < -eps ? -1 : d > eps;
}
inline double sqr(double x){return x*x;}
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):
    x(_x),y(_y){};
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(Point a)const{
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(Point a)const{
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len(){
        return hypot(x,y);
    }
    double len2(){
        return x*x+y*y;
    }
    double distance(Point p){
        return hypot(x-p.x,y-p.y);
    }
    double distance2(Point p){
        return sqr(x-p.x)+sqr(y-p.y);
    }
    Point add(Point p){
        return Point(x+p.x,y+p.y);
    }
    Point operator + (const Point & p) const{
        return Point(x+p.x,y+p.y);
    }
    Point sub(Point p){
        return Point(x-p.x,y-p.y);
    }
    Point operator - (const Point & p) const{
        return Point(x-p.x,y-p.y);
    }
    Point mul(double b){
        return Point(x*b,y*b);
    }
    Point div(double b){
        return Point(x/b,y/b);
    }
    double dot(Point p){
        return x*p.x+y*p.y;
    }
    double operator * (const Point & p) const{
        return x*p.x+y*p.y;
    }
    double det(Point p){
        return x*p.y-y*p.x;
    }
    double operator ^ (const Point & p) const{
        return x*p.y-y*p.x;
    }
    double rad(Point a,Point b){
        Point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    Point trunc(double r){
        double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return Point(x*r,y*r);
    }
    Point rotleft(){
        return Point(-y,x);
    }
    Point rotright(){
        return Point(y,-x);
    }
    Point rotate(Point p,double angle){

        Point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }

};
struct Line{
    Point a, b;
};
};using namespace Geo;

template<class T> inline T& RD(T &);
template<class T> inline T& RDD(T &);
inline LL RD(){LL x; return RD(x);}
inline LL RDD(){LL x; return RDD(x);}
inline double& RF(double &);
inline double RF(){double x; return RF(x);}
template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}
template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}
template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}
template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}
template<class T0,class T1>inline void RDD(T0&a, T1&b){RDD(a),RDD(b);}
template<class T0,class T1,class T2>inline void RDD(T0&a, T1&b, T2&c){RDD(a),RDD(b),RDD(c);}
inline double& RF(double &a, double &b){RF(a), RF(b); return a;}
inline double& RF(double &a, double &b, double &c){RF(a), RF(b), RF(c); return a;}
inline double& RF(double &a, double &b, double &c, double &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline double& RF(double &a, double &b, double &c, double &d, double &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline double& RF(double &a, double &b, double &c, double &d, double &e, double &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline double& RF(double &a, double &b, double &c, double &d, double &e, double &f, double &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}








template<class T> inline T& RD(T &x){
    char c;while(!d);x=c-'0';while(d)p;
    return x;
}
template<class T> inline T& RDD(T &x){
    char c;while(g,c!='-'&&!isdigit(c));
    if (c=='-'){x='0'-g;while(d)n;}
    else{x=c-'0';while(d)p;}
    return x;
}
inline double& RF(double &x){
    

    char c;while(g,c!='-'&&c!='.'&&!isdigit(c));
    if(c=='-')if(g=='.'){x=0;double l=1;while(d)nn;x*=l;}
        else{x='0'-c;while(d)n;if(c=='.'){double l=1;while(d)nn;x*=l;}}
    else if(c=='.'){x=0;double l=1;while(d)pp;x*=l;}
        else{x=c-'0';while(d)p;if(c=='.'){double l=1;while(d)pp;x*=l;}}
    return x;
}











int T;
int n;
char Map[105][105];

bool Judge(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n){
        return true;
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%c", &Map[i][j]);
        }
        getchar();
    }
    bool flag = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
                int cnt = 0;
                if(Judge(i-1, j) && Map[i-1][j] == 'o'){
                    cnt++;
                }
                if(Judge(i+1, j) && Map[i+1][j] == 'o'){
                    cnt++;
                }
                if(Judge(i, j-1) && Map[i][j-1] == 'o'){
                    cnt++;
                }
                if(Judge(i, j+1) && Map[i][j+1] == 'o'){
                    cnt++;
                }
            if(cnt % 2 == 1){
                flag = false;
                break;
            }
        }
        if(flag == false){
            break;
        }
    }
    if(flag){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}



