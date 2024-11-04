
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

#define ll long long int
#define ull unsigned long long int


#define linf (LLONG_MAX/10LL)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define fl(c,i,n) for(i=c;i<n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define pb push_back
#define pp pop_back()
#define aov(a) a.begin(),a.end()
#define mpr make_pair
#define PI (2.0*acos(0.0)) 

#define xx first
#define yy second
#define mxv(a) *max_element(aov(a))
#define mnv(a) *min_element(aov(a))
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define pii pair< int , int >
#define pll pair< ll , ll >
#define pcs(a) printf("Case %d: ", a)
#define nl puts("")
#define dbg(x) cout<<#x<<" : "<<x<<endl

template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   

template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}

int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int toLlint(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}




















#define M 50025
#define MD 100000007LL
#define MX 2000012LL

const double eps=1e-8;
const double pi=acos(-1.0);
const double inf=1e20;
const int maxp=100005;
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
inline double sqr(double x){return x*x;}












































struct point
{
    double x,y;
    point()             {                                    }
    point(double _x,double _y){    x = _x; y = _y;           }
    void input()        {   int a,b;scanf("%d%d",&a,&b);x=a*1.0,y=b*1.0;           }

    void output()       {   printf("%.2f %.2f\n",x,y);       }
    bool operator==(point a)const{
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }
    bool operator<(point a)const{
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }
    point operator-(point a)const{
		return point(x-a.x, y-a.y);
	}
    double len()        {   return hypot(x, y);              }
    double len2()       {   return x * x + y * y;            }
    double distance(point p){return hypot(x - p.x, y - p.y); }
    point add(point p)  {   return point(x + p.x, y + p.y);  }
    point sub(point p)  {   return point(x - p.x, y - p.y);  }
    point mul(double b) {   return point(x * b, y * b);      }
    point div(double b) {   return point(x / b, y / b);      }
    double dot(point p) {   return x*p.x+y*p.y;              }
    double det(point p) {   return x*p.y-y*p.x;              }
    double rad(point a,point b){
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r){
        double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft()     {   return point(-y,x);              }
    point rotright()    {   return point(y,-x);              }
    point rotate(point p,double angle){
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};

































































struct line
{
    point a,b;
    line()              {                                    }
    line(point _a,point _b){ a=_a; b=_b;                     }
    bool operator==(line v){ return (a==v.a)&&(b==v.b);      }
    line(point p,double angle){
        a=p;
        if (dblcmp(angle-pi/2)==0){
            b=a.add(point(0,1));
        }else{
            b=a.add(point(1,tan(angle)));
        }
    }
    

    line(double _a,double _b,double _c){
        if (dblcmp(_a)==0){
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }else if (dblcmp(_b)==0){
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }else{
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input()        {   a.input(); b.input();            }
    void adjust()       {   if(b<a)swap(a,b);                }
    double length()     {   return a.distance(b);            }
    double angle(){
        double k=atan2(b.y-a.y,b.x-a.x);
        if (dblcmp(k)<0)k+=pi;
        if (dblcmp(k-pi)==0)k-=pi;
        return k;
    }
    int relation(point p){
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p){
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v){
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    int segcrossseg(line v){
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
			d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
			d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
			d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int segcrossseg_inside(line v){
		if(v.pointonseg(a) || v.pointonseg(b) || pointonseg(v.a) || pointonseg(v.b)) return 0;
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 1;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
			d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
			d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
			d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int linecrossseg(line v){

        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    int linecrossline(line v){
        if ((*this).parallel(v)){
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v){
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p){
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p){
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0){
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p){
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p){
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
};


int n;
double p[2][1005];
double ds[3];
double qs[1005][1005];

bool chk(double md)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		j=(i+1)%n;
		

		{
			if(i==j||(i+2)%n==j)continue;
			
			

			

			

			

			
			

			

			

			

			
			

			

			
			double h=line(point(p[0][i],p[1][i]),point(p[0][(i+2)%n],p[1][(i+2)%n])).dispointtoline( point(p[0][j],p[1][j]) );
			if(h-md-md<=0.0)return 0;
		}
	}
	return 1;
}
#define dst(u,v,x,y) sqrt((x*1.0-u*1.0)*(x*1.0-u*1.0)+(y*1.0-v*1.0)*(y*1.0-v*1.0))
int main()
{
	int t,i,j,k;
	
	sc(n);
	f(i,n)
	{
		sc2(j,k);
		p[0][i]=j;
		p[1][i]=k;
	}
	
	double lo,hi,md;
	
	lo=0.0;
	hi=LLONG_MAX;
	
	f(i,n)
	{
		fl(i+1,j,n)
		{
			qs[i][j]=qs[j][i]=dst(p[0][i],p[1][i],p[0][j],p[1][j]);
			hi=min(hi, qs[i][j] );
		}
	}
	hi/=2.0;
	
	t=500;
	while(t--)
	{
		md=(lo+hi)/2.0;
		if(chk(md))lo=md;
		else hi=md;
	}
	printf("%.10lf\n",(lo+hi)*0.5);
	
	
	return 0;
}



