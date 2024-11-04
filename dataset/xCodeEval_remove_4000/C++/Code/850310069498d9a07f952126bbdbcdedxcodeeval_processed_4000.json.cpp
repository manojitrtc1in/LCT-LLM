 
  
   











         
         













     
     



         






         
         


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
         
         
i64 id7(i64 a,i64 b,i64 &x,i64 &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    i64 temp=id7(b,a%b,x,y);
    i64 t=x;
    x=y;
    y=t-a/b*y;
    return temp;
}
         
i64 id11(i64 a,i64 b)
{
    i64 x,y;
    i64 g=id7(a,b,x,y);
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
         
i64 id2(i64 t)
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
         
double id3(point a[],int n)
{
    double ans=0;
    int i;
    for(i=0;i<n;i++) ans+=a[i]*a[(i+1)%n];
    return ans;
}
         
int id5(point a[],int n)
{
    double s=id3(a,n);
    if(sgn(s)>=0) return 0;
    int L=0,R=n-1;
    while(L<R) swap(a[L++],a[R--]);
    return 1;
}
         
int id10(point p,point a,point b)
{
    if(sgn((p-a)*(p-b))) return 0;
    int x=sgn((p.x-a.x)*(p.x-b.x));
    int y=sgn((p.y-a.y)*(p.y-b.y));
    return x<=0&&y<=0;
}
         
int id9(point p,point a,point b)
{
    return sgn((p-a)*(b-a))>0;
}
         
int id6(point p,point a,point b)
{
    return sgn((p-a)*(b-a))==0;
}
         
int id0(point p,point a,point b)
{
    return sgn((b-a)*(p-a))>0;
}
         
         
         

int id8(point a[],int n,point p)
{
    a[n]=a[0];
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        if(id10(p,a[i],a[i+1])) return 0;
        point aa=a[i]-p;
        point bb=a[i+1]-p;
        sum+=aa.rotateAngle(bb);
    }
         
         
    if(fabs(sum-2*PI)<1e-2) return -1;
    return 1;
}
         
         
int id12(point a,point b,point p,point q)
{
    double aa=(b.x-a.x)*(p.y-q.y);
    double bb=(b.y-a.y)*(p.x-q.x);
    return sgn(aa-bb)==0;
}
         

int id4(point a,point b,point p,point q,point &ans)
{
    if(id12(a,b,p,q))
    {
        if(!id6(p,a,b)) return 0;
        return 2;
    }
         
    double s1=(p-a)*(q-a);
    double s2=(q-b)*(p-b);
    ans=(a*s2+b*s1)/(s1+s2);
    return 1;
         
}
         

         
int id1(point a,point b,point p,point q,point &ans)
{
    if(id12(a,b,p,q))
    {
        if(!id6(p,a,b)) return 0;
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
    id4(a,b,p,q,ans);
    if(id10(ans,a,b)&&id10(ans,p,q)) return 1;
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

int r[N],sa[N],wa[N],wb[N],wd[N],rank[N],h[N];


int cmp(int *r,int a,int b,int len)
{
    return r[a]==r[b]&&r[a+len]==r[b+len];
}


void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    FOR0(i,m) wd[i]=0;
    FOR0(i,n) wd[x[i]=r[i]]++;
    FOR1(i,m-1) wd[i]+=wd[i-1];
    FORL0(i,n-1) sa[--wd[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p)
    {
        p=0;
        FOR(i,n-j,n-1) y[p++]=i;
        FOR0(i,n) if(sa[i]>=j) y[p++]=sa[i]-j;
        FOR0(i,m) wd[i]=0;
        FOR0(i,n) wd[x[i]]++;
        FOR1(i,m-1) wd[i]+=wd[i-1];
        FORL0(i,n-1) sa[--wd[x[y[i]]]]=y[i];
        t=x;x=y;y=t;p=1;x[sa[0]]=0;
        FOR1(i,n-1) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}


void calHeight(int *r,int *sa,int n)
{
    int i,j,k=0;
    FOR1(i,n) rank[sa[i]]=i;
    FOR0(i,n)
    {
        if(k) k--;
        j=sa[rank[i]-1];
        while(i+k<n&&j+k<n&&r[i+k]==r[j+k]) k++;
        h[rank[i]]=k;
    }
}

char s[N];
int mp[N];

int n;

int ans[N];


struct node
{
    int h,i;
};


int cmp1(node a,node b)
{
    if(a.h!=b.h) return a.h>b.h;
    return a.i<b.i;
}


node a[N];

int S[N];

int x[N][4];

int get(int x)
{
    if(S[x]!=x) S[x]=get(S[x]);
    return S[x];
}

set<int> ss;

i64 cur;

i64 f(int t)
{
    return (i64)x[t][1]*x[t][2]%mod*x[t][3]%mod;
}

void unite(int xx,int yy)
{
    xx=get(xx);
    yy=get(yy);

    if(xx==yy) return;

    int i;
    cur-=f(yy);
    cur-=f(xx);

    FOR1(i,3) x[xx][i]+=x[yy][i];
    cur+=f(xx);
    cur%=mod;
    if(cur<0) cur+=mod;
    S[yy]=xx;
}


int main()
{



    n=INF;
    int i,k=0;
    int tt=27;
    FOR1(i,3)
    {
        RD(s);
        int j;
        for(j=0;s[j];j++)
        {
            r[k++]=s[j]-'a'+1;
            mp[k-1]=i;
        }
        n=min(n,j);
        if(i<3) r[k++]=tt++,mp[k-1]=0;
    }
    r[k]=0;
    da(r,sa,k+1,35);
    calHeight(r,sa,k);
    FOR1(i,k)
    {
        a[i].h=h[i];
        a[i].i=i;
    }
    sort(a+1,a+k+1,cmp1);
    FOR1(i,k) 
    {
        int t=mp[sa[i]];
        x[i][t]=1;
        S[i]=i;
    }

    cur=0;
    for(i=1;i<=k;)
    {
        if(a[i].h==0) break;
        int j;
        for(j=i;j<=k;j++) 
        {
            if(a[j].h!=a[i].h) break;
            unite(a[j].i,a[j].i-1);
        }
        int L=a[i].h;
        ans[L]=cur;
        i=j;
    }

    FOR1(i,n) 
    {
        if(i>1) putchar(' ');
        printf("%d",ans[i]);
    }
    puts("");
}