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
         
         
#define rush() int _CC;for(scanf("%d",&_CC);_CC--;)
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
    if(x>1e-10) return 1;
    if(x<-1e-10) return -1;
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
        
        
const int SIZE=700;
const int MM=1000000000;
 
struct BigNum
{
    
    i64 a[SIZE];

    int len;

    BigNum()
    {
        clr(a,0);
    }

    BigNum(char *s,int n)
    {
        clr(a,0);
        int p=0;
        int i;
        for(i=n-1;i>=0;i-=9)
        {
            int j=max(0,i-8);
            a[p]=0;
            int k;
            for(k=j;k<=i;k++) a[p]=a[p]*10+s[k]-'0';
            p++;
        }
        adjust();
    }


    BigNum(i64 n)
    {
        clr(a,0);
        a[0]=n;
        adjust();
    }
           
    BigNum adjust()
    {
        int i;
        FOR0(i,SIZE)
        {
            if(a[i]>=MM)
            {
                a[i+1]+=a[i]/MM;
                a[i]%=MM;
            }
            else if(a[i]<0)
            {
                a[i+1]--;
                a[i]+=MM;
            }
        }
        for(i=SIZE-1;i>=0;i--) if(a[i]) break;
        len=i+1;
        if(len==0) len=1;
    }
       
    BigNum operator*(const BigNum &p)
    {
        BigNum c;
        int i,j;
        FOR0(i,len) for(j=0;j<p.len;j++)
        {
            c.a[i+j]+=a[i]*p.a[j];
        }
        c.adjust();
        return c;
    }
       
    BigNum operator/(const int x)
    {
        i64 tmp=0;
        BigNum c;
        memcpy(c.a,a,sizeof(a));
        int i;
        for(i=len-1;i>=0;i--)
        {
            i64 p=(tmp*MM+c.a[i])%x;
            c.a[i]=(tmp*MM+c.a[i])/x;
            tmp=p;
        }
        c.adjust();
        return c;
    }
       
    BigNum operator+(BigNum &p)
    {
        BigNum c;
        int i;
        int t=max(len,p.len);
        FOR0(i,t) c.a[i]=a[i]+p.a[i];
        c.adjust();
        return c;
    }
       
    BigNum operator-(const BigNum &p) const
    {
        BigNum c;
        int i;
        FOR0(i,len) c.a[i]=a[i]-p.a[i];
        c.adjust();
        return c;
    }
       
    int operator==(const BigNum &p) const
    {
        if(len!=p.len) return 0;
        int i;
        FOR0(i,SIZE) if(a[i]!=p.a[i]) return 0;
        return 1;
    }

    int operator<(const BigNum &p) const
    {
        if(len<p.len) return 1;
        if(len>p.len) return 0;
        int i;
        for(i=len-1;i>=0;i--) 
        {
            if(a[i]<p.a[i]) return 1;
            if(a[i]>p.a[i]) return 0;
        }
        return 0;
    }
    
    int operator>(const BigNum &p) const
    {
        if(len>p.len) return 1;
        if(len<p.len) return 0;
        int i;
        for(i=len-1;i>=0;i--) 
        {
            if(a[i]>p.a[i]) return 1;
            if(a[i]<p.a[i]) return 0;
        }
        return 0;
    }

       
    void output()
    {
        int i;
        printf("%d",(int)a[len-1]);
        for(i=len-2;i>=0;i--) printf("%09d",(int)a[i]);
        puts("");
    }
};  
    
      
const i64 inf=(((i64)1)<<61)+5;
const double dinf=1e20;
const int INF=1000000005;
const int N=300005;


vector<int> g[N];
int n;
int S[N];

int m,Q;
int a[N];

int f[N],Max;

int visit[N];
int K;

int bfs(int u)
{
    queue<int> Q;
    Q.push(u);
    int i;
    f[u]=0;
    Max=0;
    int ans=u;
    visit[u]=K;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        int i;
        FOR0(i,SZ(g[u])) 
        {
            int v=g[u][i];
            if(K==visit[v]) continue;
            visit[v]=K;
            f[v]=f[u]+1;
            if(Max<f[v]) Max=f[v],ans=v;

            Q.push(v);
        }
    }
    return ans;
}

int cal(int u)
{
    K++;
    int x=bfs(u);


    K++;
    int y=bfs(x);


    return Max;
}


int get(int x)
{
    if(S[x]!=x) S[x]=get(S[x]);
    return S[x];
}



int cal(int x,int y)
{
    if(x==0) return 1;


    int x1=(x+1)/2,x2=x/2;
    int y1=(y+1)/2,y2=y/2;

    return max(x1+y1+1,x);

}

int main()
{



    RD(n,m,Q);
    int i;
    FOR1(i,n) S[i]=i,a[i]=0;
    FOR1(i,m)
    {
        int x=getInt();
        int y=getInt();

        S[get(x)]=get(y);

        g[x].pb(y);
        g[y].pb(x);
    }

    FOR1(i,n) if(get(i)==i) a[i]=cal(i);

    while(Q--)
    {
        int op;
        RD(op);
        if(op==1)
        {
            int x=getInt();
            x=get(x);
            PR(a[x]);
        }
        else 
        {
            int x=getInt();
            int y=getInt();
            x=get(x);
            y=get(y);
            if(x==y) continue;
            S[x]=y;
            int xx=a[x],yy=a[y];

            if(xx<yy) swap(xx,yy);
            a[y]=cal(xx,yy);
        }
    }
}