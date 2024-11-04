 
  
   
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>
         
         
#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-7
     
     
#define pii pair<int,int>
#define FFF freopen("test","r",stdin)
#define all(a) a.begin(),a.end()
         
#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)
         
         
#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n)  while(scanf("%d",&n)!=-1)
using namespace std;
         
         
void RD(int &x){scanf("%d",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}
         
         
void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(u32 x) {printf("%u\n",x);}
void PR(u64 x) {cout<<x<<endl;}
void PR(double x) {printf("%.4lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}
void PR(i64 x) {cout<<x<<endl;}
         
void upMin(int &x,int y) {if(x>y) x=y;}
void upMin(i64 &x,i64 y) {if(x>y) x=y;}
void upMin(double &x,double y) {if(x>y) x=y;}
void upMax(int &x,int y) {if(x<y) x=y;}
void upMax(i64 &x,i64 y) {if(x<y) x=y;}
void upMax(double &x,double y) {if(x<y) x=y;}
         
         
         
         
         
int sgn(double x)
{
    if(x>1e-8) return 1;
    if(x<-1e-8) return -1;
    return 0;
}
         
i64 Gcd(i64 x,i64 y)
{
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(y==0) return x;
    return Gcd(y,x%y);
}
         
i64 Lcm(i64 x,i64 y)
{
    return x/Gcd(x,y)*y;
}
         
i64 eular(i64 n)
{
    i64 ans=n,i;
    for(i=2;i*i<=n;i++) if(n%i==0)
    {
        ans-=ans/i;
        while(n%i==0) n/=i;
    }
    if(n>1) ans-=ans/n;
    return ans;
}
         
         
i64 exGcd(i64 a,i64 b,i64 &x,i64 &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    i64 temp=exGcd(b,a%b,x,y);
    i64 t=x;
    x=y;
    y=t-a/b*y;
    return temp;
}
         
i64 gcdReverse(i64 a,i64 b)
{
    i64 x,y;
    i64 g=exGcd(a,b,x,y);
    if(g!=1) return 0;
    x%=b;
    if(x<0) x+=b;
    return x;
}
         
i64 myPow(i64 a,i64 b)
{
    i64 ans=1;
    while(b)
    {
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
         
i64 myPow(i64 a,i64 b,i64 mod)
{
    a%=mod;
    i64 ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
         
         
i64 getInt()
{
    i64 x=0,flag=1;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        flag=-1,c=getchar();
        while(!isdigit(c)) c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*flag;
}
         
i64 getSqrt(i64 t)
{
    i64 p=sqrt(1.0*t);
    while(p*p>t) p--;
    while((p+1)<=t/(p+1)) p++;
    return p;
}
         
         
         
         
struct point
{
    double x,y;
         
    point(){}
    point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
         
    void get()
    {
        scanf("%lf%lf",&x,&y);
    }
         
    point operator+(point a)
    {
        return point(x+a.x,y+a.y);
    }
         
    point operator-(point a)
    {
        return point(x-a.x,y-a.y);
    }
         
    point operator*(double t)
    {
        return point(x*t,y*t);
    }
         
    double operator*(point a)
    {
        return x*a.y-y*a.x;
    }
         
         
    double operator^(point a)
    {
        return x*a.x+y*a.y;
    }
         
    double Len()
    {
        return sqrt(x*x+y*y);
    }
         
    point adjustTo(double L)
    {
        L/=Len();
        return point(x*L,y*L);
    }
         
    point operator/(double t)
    {
        return point(x/t,y/t);
    }
         
         
    double rotateAngle(point a)
    {
        point p=*this;
        return atan2(p*a,p^a);
    }
         
    int operator==(point a)
    {
        return sgn(x-a.x)==0&&sgn(y-a.y)==0;
    }


    point zhuanNi(double ang)
    {
        return point(x*cos(ang)-y*sin(ang),x*sin(ang)+y*cos(ang));
    }

    point zhuanShun(double ang)
    {
        return point(x*cos(ang)+y*sin(ang),-x*sin(ang)+y*cos(ang));
    }
         
    void print()
    {
        printf("%.4lf %.4lf\n",x,y);
    }
};
         
double calPloyArea(point a[],int n)
{
    double ans=0;
    int i;
    for(i=0;i<n;i++) ans+=a[i]*a[(i+1)%n];
    return ans;
}
         
int changeToClockwise(point a[],int n)
{
    double s=calPloyArea(a,n);
    if(sgn(s)>=0) return 0;
    int L=0,R=n-1;
    while(L<R) swap(a[L++],a[R--]);
    return 1;
}
         
int pointOnSeg(point p,point a,point b)
{
    if(sgn((p-a)*(p-b))) return 0;
    int x=sgn((p.x-a.x)*(p.x-b.x));
    int y=sgn((p.y-a.y)*(p.y-b.y));
    return x<=0&&y<=0;
}
         
int pointOnRightOfLine(point p,point a,point b)
{
    return sgn((p-a)*(b-a))>0;
}
         
int pointOnLine(point p,point a,point b)
{
    return sgn((p-a)*(b-a))==0;
}
         
int pointOnLeftOfLine(point p,point a,point b)
{
    return sgn((b-a)*(p-a))>0;
}
         
         
         

int getRelationOfPointAndPloy(point a[],int n,point p)
{
    a[n]=a[0];
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        if(pointOnSeg(p,a[i],a[i+1])) return 0;
        point aa=a[i]-p;
        point bb=a[i+1]-p;
        sum+=aa.rotateAngle(bb);
    }
         
         
    if(fabs(sum-2*PI)<1e-2) return -1;
    return 1;
}
         
         
int isParal(point a,point b,point p,point q)
{
    double aa=(b.x-a.x)*(p.y-q.y);
    double bb=(b.y-a.y)*(p.x-q.x);
    return sgn(aa-bb)==0;
}
         

int lineCrossLine(point a,point b,point p,point q,point &ans)
{
    if(isParal(a,b,p,q))
    {
        if(!pointOnLine(p,a,b)) return 0;
        return 2;
    }
         
    double s1=(p-a)*(q-a);
    double s2=(q-b)*(p-b);
    ans=(a*s2+b*s1)/(s1+s2);
    return 1;
         
}
         

         
int segCrossSeg(point a,point b,point p,point q,point &ans)
{
    if(isParal(a,b,p,q))
    {
        if(!pointOnLine(p,a,b)) return 0;
        if(sgn(a.x-b.x)==0)
        {
            if(p.y>q.y) swap(p,q);
            if(a.y>b.y) swap(a,b);
            if(sgn(q.y-a.y)==-1||sgn(b.y-p.y)==-1) return 0;
            if(q==a||p==b)
            {
                if(q==a) ans=q;
                if(p==b) ans=p;
                return 1;
            }
            return 2;
        }
        if(p.x>q.x) swap(p,q);
        if(a.x>b.x) swap(a,b);
        if(sgn(q.x-a.x)==-1||sgn(b.x-p.x)==-1) return 0;
        if(q==a||p==b)
        {
            if(q==a) ans=q;
            if(p==b) ans=p;
            return 1;
        }
        return 2;
    }
    lineCrossLine(a,b,p,q,ans);
    if(pointOnSeg(ans,a,b)&&pointOnSeg(ans,p,q)) return 1;
    return 0;
}
        
        
const i64 MM=1000000000000LL;
        
struct BigInteger
{
    i64 a[105];
    int cnt;
        
    BigInteger()
    {
        cnt=1;
        a[1]=0;
    }
        
    BigInteger(i64 x)
    {
        if(x==0)
        {
            cnt=1;
            a[1]=0;
            return;
        }
        cnt=1;
        a[1]=x;
    }
        
    BigInteger operator*(int x)
    {
        BigInteger p=*this;
        int i;
        FOR1(i,p.cnt) p.a[i]*=x;
        int t=0;
        FOR1(i,p.cnt)
        {
            p.a[i]+=t;
            t=p.a[i]/MM;
            p.a[i]%=MM;
        }
        if(t==0) return p;
        while(t) p.a[++p.cnt]=t%MM,t/=MM;
        return p;
    }
       
       
    int zero()
    {
        return cnt==1&&a[1]==0;
    }
        
    BigInteger operator+(BigInteger a)
    {
        BigInteger p,q;
        if(a.cnt>cnt) p=a,q=*this;
        else p=*this,q=a;
        
        int i;
        for(i=1;i<=q.cnt;i++) p.a[i]+=q.a[i];
        int re=0;
        for(i=1;i<=p.cnt;i++)
        {
            p.a[i]+=re;
            re=p.a[i]/MM;
            p.a[i]%=MM;
        }
        if(re)
        {
            p.a[++p.cnt]=re;
        }
        return p;
    }
       
        
};
      
struct fraction
{
    i64 a,b;
      
    fraction() 
    {
        a=0;
        b=1;
    }
    fraction(i64 x)
    {
        a=x; b=1;
    }
      
    fraction(i64 x,i64 y)
    {
        a=x; b=y;
        deal();
    }
      
    void deal()
    {
        if(b<0) b=-b,a=-a;
        i64 k=Gcd(a,b);
        if(k<0) k=-k;
        a/=k; b/=k;
    }
      
    fraction operator+(fraction p)
    {
        fraction ans;
        ans.b=Lcm(b,p.b);
        ans.a=ans.b/b*a+ans.b/p.b*p.a;
        ans.deal();
        return ans;
    }
      
    fraction operator-(fraction p)
    {
        fraction ans;
        ans.b=Lcm(b,p.b);
        ans.a=ans.b/b*a-ans.b/p.b*p.a;
        ans.deal();
        return ans;
    }
      
    fraction operator*(fraction p)
    {
        fraction ans;
        ans.a=a*p.a;
        ans.b=b*p.b;
        ans.deal();
        return ans;
    }
      
    fraction operator/(fraction p)
    {
        fraction ans;
        ans.a=a*p.b;
        ans.b=b*p.a;
        ans.deal();
        return ans;
    }
      
    int operator==(fraction p)
    {
        return a*p.b==b*p.a;
    }
      
    int operator!=(fraction p)
    {
        if((*this)==p) return 0;
        return 1;
    }
      
    int isZero()
    {
        return a==0;
    }
      
};
      
const int matrixSize=3;
int matrixMod;
      
struct Matrix
{
    i64 a[3][3];
      
    void init(int t=0)
    {
        int i,j;
        FOR0(i,matrixSize) FOR0(j,matrixSize) a[i][j]=0; 
        if(t)
        {
            FOR0(i,matrixSize) a[i][i]=1;
        }
    }
      
    Matrix operator*(Matrix p)
    {
        Matrix ans;
        ans.init();
        int i,j,k;
        int x=matrixSize;
        FOR0(k,x) FOR0(i,x) FOR0(j,x)
        {
            ans.a[i][j]+=a[i][k]*p.a[k][j]%matrixMod;
            ans.a[i][j]%=matrixMod;
        }
        return ans;
    }
      
    Matrix pow(i64 t)
    {
        Matrix p=*this,ans;
        ans.init(1);
        while(t)
        {
            if(t&1) ans=ans*p;
            p=p*p;
            t>>=1;
        }
        return ans;
    }
 
 
    void print()
    {
        int i,j;
        FOR0(i,matrixSize)
        {
            FOR0(j,matrixSize) cout<<a[i][j]<<' ';
            puts("");
        }
    }
};
      
    
const int mod=1000000007;
      
const i64 inf=(((i64)1)<<61)+5;
const double dinf=1000000000;
const int INF=2000000005;
const int N=1111111;


int n,m;

int cross(pii a,pii b,pii p)
{
    b.first-=a.first;
    b.second-=a.second;

    p.first-=a.first;
    p.second-=a.second;

    int x=b.first*p.second-b.second*p.first;
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}

int ok(pii a,pii b,pii c,pii d)
{
    if(a==b||a==c||a==d||b==c||b==d||c==d) return 0;
    return 1;
    if(cross(a,b,c)==cross(a,b,d)) return 0;
    if(cross(c,d,a)==cross(c,d,b)) return 0;
    return 1;
}


double dis(pii a,pii b)
{
    a.first-=b.first;
    a.second-=b.second;

    return sqrt(1.0*a.first*a.first+1.0*a.second*a.second);
}

int main()
{
    while(scanf("%d%d",&n,&m)!=-1)
    {
        if(n==0) PR(0,1),PR(0,m),PR(0,0),PR(0,m-1);
        else if(m==0) PR(1,0),PR(n,0),PR(0,0),PR(n-1,0);
        else
        {
            vector<pii > a;
            a.pb(MP(0,0)); a.pb(MP(0,1)); a.pb(MP(1,0));
            a.pb(MP(n,0)); a.pb(MP(n-1,0)); a.pb(MP(n,1));
            a.pb(MP(0,m)); a.pb(MP(0,m-1)); a.pb(MP(1,m));
            a.pb(MP(n,m)); a.pb(MP(n-1,m)); a.pb(MP(n,m-1));

            pii p,q,r,w;
            int i,j,k,t;
            double Max=0;
            FOR0(i,12) FOR0(j,12)  FOR0(k,12)  FOR0(t,12)
            {
                if(ok(a[i],a[j],a[k],a[t]))
                {
                    double tmp=dis(a[i],a[j])+dis(a[j],a[k])+dis(a[k],a[t]);
                    if(tmp>Max) 
                    {
                        Max=tmp;
                        p=a[i];
                        q=a[j];
                        r=a[k];
                        w=a[t];
                    }
                }
            }
            PR(p.first,p.second);
            PR(q.first,q.second);
            PR(r.first,r.second);
            PR(w.first,w.second);
        }
    }
}


