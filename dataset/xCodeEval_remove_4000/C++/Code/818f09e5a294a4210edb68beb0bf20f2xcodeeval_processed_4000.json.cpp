

















using namespace std;

































































































































template <class _T>inline void ina(_T a[],int n){int i; fr0(i,n)sc1(a[i]);}
template <class _T>inline void outa(_T a[],int n){int i; fr0(i,n-1)pr1(a[i]),SPS;if(i)pi1(i);NL;}



const double EPS = 1e-9;
const int SIZE=1e6;











template<class _T>inline _T pow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans*=a,ans%=m;a*=a;a%=m;b>>=1;}return ans;}
template<class _T>inline _T pow(_T a,_T b){_T ans=1;while(b){if(b&1)ans*=a;a*=a;b>>=1;}return ans;}
template<class _T>inline _T add(_T a,_T b,_T m){return a>=m-b?a-(m-b):a+b;}

template<class _T>inline _T multiply(_T a,_T b,_T m){_T ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=add(ans,a,m);b>>=1;a=add(a,a,m);}return ans;}

template<class _T>inline _T bigpow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans=multiply(ans,a,m);a=multiply(a,a,m);b>>=1;}return ans;}
template<class _T>inline _T id0(_T a,_T m){return m>2000000000LL?bigpow(a,m-2,m):pow(a,m-2,m);}



template<class _T> _T id3(_T a, _T b, _T &x,_T &y){if(!b){x=1,y=0;return a;}_T _g=id3(b,a%b,x,y);_T xt=x;x=y,y=xt-(a/b)*y;return _g;}
template<class _T>inline _T id1(_T a,_T m){_T x,y;id3(a,m,x,y);x%=m;if(x<0)x+=m;return x;} 

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
double id4(double d) { return d * PI / 180.0; }

double id2(double r) { return r * 180.0 / PI; }
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
  double rad = id4(theta);    

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



