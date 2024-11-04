#include <bits/stdc++.h>


#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#include <set>

using namespace std;
#define output freopen("output.txt","w",stdout)
#define input freopen("input.txt","r",stdin)
#define inputfile(x) freopen(x,"r",stdin)
#define outpufile(x) freopen(x,"w",stdout)


#define pb(x)  push_back(x)
#define pf  printf
#define sc scanf
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))
#define SUM(a,n)   (accumulate(a,a+n,0))
#define countbit(x) __builtin_popcount(x)
#define lb  lower_bound 

#define ub  upper_bound 

#define bs  binary_search
#define SQ(a)  ((a)*(a))
#define _PI (acos(-1.0))
#define mid(l,r)    ((l+r)>>1)


#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


#define xx first
#define yy second
#define mp(x,y) make_pair(x,y)


#define si1(n) sc("%d",&n)
#define sl1(n) sc("%lld",&n)
#define slu1(n) sc("%llu",&n)
#define sd1(n) sc("%lf",&n)
#define ss1(n) sc("%s",n)


#define si2(n,m) sc("%d %d",&n,&m)
#define sl2(n,m) sc("%lld %lld",&n,&m)
#define slu2(n,m) sc("%llu %llu",&n,&m)
#define sd2(n,m) sc("%lf %lf",&n,&m)


#define si3(n,m,l) sc("%d %d %d",&n,&m,&l)
#define sl3(n,m,l) sc("%lld %lld %lld",&n,&m,&l)
#define slu3(n,m,l) sc("%llu %llu %llu",&n,&m,&l)
#define sd3(n,m,l) sc("%lf %lf %lf",&n,&m,&l)



#define pi1(n) pf("%d",n)
#define pl1(n) pf("%lld",n)
#define plu1(n) pf("%llu",n)
#define pd1(n,pre) pf("%.*f",pre,n)
#define ps1(n) pf("%s",n)


#define pi2(n,m) pf("%d %d",n,m)
#define pl2(n,m) pf("%lld %lld",n,m)
#define plu2(n,m) pf("%llu %llu",n,m)
#define pd2(n,m,pre) pf("%.*f %.*f",pre,n,pre,m)


#define pi3(n,m,l) pf("%d %d %d",n,m,l)
#define pl3(n,m,l) pf("%lld %lld %lld",n,m,l)
#define plu3(n,m,l) pf("%llu %llu %llu",n,m,l)


#define nln putchar(10)
#define sps putchar(' ')
#define pch(c) putchar(c)
#define tcsp(i) pf("Case %d: ",++i)
#define tcnl(i) pf("Case %d:\n",++i)
#define dg()   pf("-----------here\n")

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sc1(n) cin>>n
#define sc2(n,m) cin>>n>>m
#define sc3(n,m,k) cin>>n>>m>>k
#define sc4(n,m,k,l) cin>>n>>m>>k>>l

#define pr1(n) cout<<n
#define pr2(n,m) cout<<n<<" "<<m
#define pr3(n,m,k) cout<<n<<" "<<m<<" "<<k
#define pr4(n,m,k,l) cin<<n<<" "<<m<<" "<<k<<" "<<l
#define NL cout<<"\n"
#define SPS cout<<" "

#define setPre(x) setprecision(x)
#define fixP cout<<fixed





#define fr0(i,n) for(i=0;i<n;i++)
#define fr1(i,n) for(i=1;i<=n;i++)
#define FR(i,b,e) for(i=b;i<=e;i++)
#define FRR(i,e,b) for(i=e;i>=b;i--)




#define frf(c, it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define frr(c, it) for(typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)


#define set0(x) memset(x,0,sizeof x)
#define set(x,v) memset(x,v,sizeof x)
#define setn1(x) memset(x,-1,sizeof x)
#define setinf(x) memset(x,125,sizeof x)


#define SZ(v)   ((int) (v).size())
#define all(v)  (v).begin(), (v).end()


#define On(x,i)  (x|=(1<<(i)))
#define Off(x,i) (x&= ~(1<<(i)))
#define isOn(x,i) (x&(1<<(i)))
#define Toggle(x,i) (x^=(1<<(i)))
#define tmod(x,i)  (x&(~(-1<<i)))
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))




template <class _T>inline void ina(_T a[],int n){int i; fr0(i,n)sc1(a[i]);}
template <class _T>inline void outa(_T a[],int n){int i; fr0(i,n-1)pr1(a[i]),SPS;if(i)pi1(i);NL;}



const double EPS = 1e-9;
const int SIZE=1e6;











template<class _T>inline _T pow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans*=a,ans%=m;a*=a;a%=m;b>>=1;}return ans;}
template<class _T>inline _T pow(_T a,_T b){_T ans=1;while(b){if(b&1)ans*=a;a*=a;b>>=1;}return ans;}
template<class _T>inline _T add(_T a,_T b,_T m){return a>=m-b?a-(m-b):a+b;}

template<class _T>inline _T multiply(_T a,_T b,_T m){_T ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=add(ans,a,m);b>>=1;a=add(a,a,m);}return ans;}

template<class _T>inline _T bigpow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans=multiply(ans,a,m);a=multiply(a,a,m);b>>=1;}return ans;}
template<class _T>inline _T modinvers(_T a,_T m){return m>2000000000LL?bigpow(a,m-2,m):pow(a,m-2,m);}



template<class _T> _T _egcd(_T a, _T b, _T &x,_T &y){if(!b){x=1,y=0;return a;}_T _g=_egcd(b,a%b,x,y);_T xt=x;x=y,y=xt-(a/b)*y;return _g;}
template<class _T>inline _T fmodinvers(_T a,_T m){_T x,y;_egcd(a,m,x,y);x%=m;if(x<0)x+=m;return x;} 

template<class _T>inline _T _lcm(_T a, _T b){return (a*b)/__gcd(a,b);}

int par[100];
int findp(int _n){return par[_n]==_n?_n:par[_n]=findp(par[_n]);}






typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<pii ,pii > ppii;
typedef set<int> si;
typedef set<ll> sl;
typedef map<int,int> mii;
typedef map<ll,int> mli;
typedef map<string,int> msi;
typedef long double ld;
const double PI=_PI;
double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }
struct point { double x, y;   

  point() { x = y = 0.0; }                      

  point(double _x, double _y) : x(_x), y(_y) {}        

  bool operator < (point other) const { 

    if (fabs(x - other.x) > EPS)                 

      return x < other.x;          

    return y < other.y; }          

  

  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
   point operator -(const point &other )const{
        return point(x-other.x,y-other.y);
   }
   };

struct vec { double x, y;  

  vec(double _x, double _y) : x(_x), y(_y) {}
  vec(point a, point b) {       

    x=b.x - a.x,y=b.y - a.y; }
    vec(point a){x=a.x,y=a.y;}

};
point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta);    

  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}
struct line { double a, b, c;


    line(point p1, point p2) {
  if (fabs(p1.x - p2.x) < EPS) {              

    a = 1.0;   b = 0.0;   c = -p1.x;           

  } else {
    a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    b = 1.0;              

    c = -(double)(a * p1.x) - p1.y;
} }
};
bool areParallel(line l1, line l2) {       

 return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }


bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;            

  

  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  

  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c);
  return true; }
struct segment
{
    point a,b;
    segment(){}
    segment(point _a,point _b){a=_a,b=_b;}
    double xmin(){return min(a.x,b.x);}
    double xmax(){return max(a.x,b.x);}
    double ymin(){return min(a.y,b.y);}
    double ymax(){return max(a.y,b.y);}



};
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool onSegment(segment x,point p)
{
    return p.x>=x.xmin()&&p.x<=x.xmax()&&
        p.y>=x.ymin()&&p.y<=x.ymax();

}

bool segmentIntersect(segment a,segment b)
{
    double d1=cross(vec(a.a,a.b),vec(a.a,b.a));
    double d2=cross(vec(a.a,a.b),vec(a.a,b.b));

    double d3=cross(vec(b.a,b.b),vec(b.a,a.a));
    double d4=cross(vec(b.a,b.b),vec(b.a,a.b));

    


   if(((d1>-EPS && d2 <EPS)|| (d2>-EPS && d1 <EPS))&&          

       ((d3>-EPS && d4 <EPS)|| (d4>-EPS && d3 <EPS)))
           return 1;

    if(fabs(d1)<EPS && onSegment(a,b.a)) return 1;
    if(fabs(d2)<EPS && onSegment(a,b.b)) return 1;

    if(fabs(d3)<EPS && onSegment(b,a.a)) return 1;
    if(fabs(d4)<EPS && onSegment(b,a.b)) return 1;
    return 0;
}

double dist(point a,point b)
{
    return sqrt(SQ(a.x-b.x)+SQ(a.y-b.y));
}


ll mod=1000000007;

int main()
{

    double h,w,alp;
    sd3(h,w,alp);

    if(w>h)swap(w,h);

    if(alp<EPS || (180-alp)<EPS){pd1(h*w,10);nln;return 0;}


    point p1=point(h/2,w/2);
    point p2=point(-h/2,w/2);
    point p3=point(-h/2,-w/2);
    point p4=point(h/2,-w/2);

    point pp1=rotate(p1,alp);
    point pp2=rotate(p2,alp);
    point pp3=rotate(p3,alp);
    point pp4=rotate(p4,alp);

    double ans;
    if(segmentIntersect(segment(p2,p3),segment(pp1,pp2)))
    {


        point t1;
        point t2;
        point t3;
        point t4;

        if(alp<90)
        {

          areIntersect(line(p1,p2),line(pp1,pp2),t1);
          areIntersect(line(p2,p3),line(pp1,pp2),t2);

          areIntersect(line(p1,p2),line(pp1,pp4),t3);
          areIntersect(line(p1,p4),line(pp1,pp4),t4);

        }else
        {

          areIntersect(line(p1,p2),line(pp1,pp4),t1);
          areIntersect(line(p2,p3),line(pp1,pp4),t2);

          areIntersect(line(p1,p2),line(pp3,pp4),t3);
          areIntersect(line(p1,p4),line(pp3,pp4),t4);
        }

        
        ans=h*w-(fabs(cross(vec(p2,t1),vec(p2,t2)))+fabs(cross(vec(p1,t3),vec(p1,t4))));


    }else
    {
      

        point t1;
        point t2;
        point t3;
        point t4;

        areIntersect(line(p1,p2),line(pp1,pp2),t1);
        areIntersect(line(p3,p4),line(pp1,pp2),t2);
        areIntersect(line(p3,p4),line(pp3,pp4),t3);
        areIntersect(line(p1,p2),line(pp3,pp4),t4);


        ans=fabs(cross(vec(t4,t1),vec(t2,t1))/2)+fabs(cross(vec(t4,t3),vec(t2,t3))/2);





    }

    pd1(ans,10);nln;




    return 0;
}



