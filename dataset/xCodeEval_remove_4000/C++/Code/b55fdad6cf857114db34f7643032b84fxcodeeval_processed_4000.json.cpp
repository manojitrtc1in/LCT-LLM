









































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


i64 id9(i64 a,i64 b,i64 &x,i64 &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    i64 temp=id9(b,a%b,x,y);
    i64 t=x;
    x=y;
    y=t-a/b*y;
    return temp;
}

i64 id7(i64 a,i64 b)
{
    i64 x,y;
    id9(a,b,x,y);
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

i64 id8(i64 t)
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

    void print()
    {
        printf("%.4lf %.4lf\n",x,y);
    }
};

double id10(point a[],int n)
{
    double ans=0;
    int i;
    for(i=0;i<n;i++) ans+=a[i]*a[(i+1)%n];
    return ans;
}

int id1(point a[],int n)
{
    double s=id10(a,n);
    if(sgn(s)>=0) return 0;
    int L=0,R=n-1;
    while(L<R) swap(a[L++],a[R--]);
    return 1;
}

int id3(point p,point a,point b)
{
    if(sgn((p-a)*(p-b))) return 0;
    int x=sgn((p.x-a.x)*(p.x-b.x));
    int y=sgn((p.y-a.y)*(p.y-b.y));
    return x<=0&&y<=0;
}

int id2(point p,point a,point b)
{
    return sgn((p-a)*(b-a))>0;
}

int id4(point p,point a,point b)
{
    return sgn((p-a)*(b-a))==0;
}

int id5(point p,point a,point b)
{
    return sgn((b-a)*(p-a))>0;
}




int id11(point a[],int n,point p)
{
    a[n]=a[0];
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        if(id3(p,a[i],a[i+1])) return 0;
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


int id0(point a,point b,point p,point q,point &ans)
{
    if(id12(a,b,p,q))
    {
        if(!id4(p,a,b)) return 0;
        return 2;
    }

    double s1=(p-a)*(q-a);
    double s2=(q-b)*(p-b);
    ans=(a*s2+b*s1)/(s1+s2);
    return 1;

}



int id6(point a,point b,point p,point q,point &ans)
{
    if(id12(a,b,p,q))
    {
        if(!id4(p,a,b)) return 0;
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
    id0(a,b,p,q,ans);
    if(id3(ans,a,b)&&id3(ans,p,q)) return 1;
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

int matrixSize;
const int matrixMod=45989;

struct Matrix
{
    i64 a[122][122];

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
};



const int mod=19930726;
const i64 inf=(((i64)1)<<61)+5;
const double dinf=1000000000;
const int INF=1000000005;
const int N=100005;

struct node
{
    int L,R;
    i64 sum;
    int flag;
    i64 det,color;

    void add(i64 _det,i64 _color)
    {
        sum+=_det*(R-L+1);
        det+=_det;
        color=_color;
    }
};


node a[N<<2];



void pushDown(int t)
{
    if(!a[t].det||a[t].L==a[t].R) return;
    a[t<<1].add(a[t].det,a[t].color);
    a[t<<1|1].add(a[t].det,a[t].color);
    a[t].det=0;
}

void build(int t,int L,int R)
{
    a[t].L=L;
    a[t].R=R;
    a[t].sum=0;
    a[t].flag=0;
    a[t].det=0;
    if(L==R)
    {
        a[t].flag=1;
        a[t].color=L;
        return;
    }
    int M=(L+R)>>1;
    build(t<<1,L,M);
    build(t<<1|1,M+1,R);
}


void paint(int t,int L,int R,i64 x)
{
    if(a[t].L==L&&a[t].R==R&&a[t].flag)
    {
        a[t].det+=abs(x-a[t].color);
        a[t].sum+=abs(x-a[t].color)*(a[t].R-a[t].L+1);
        a[t].color=x;
        return;
    }
    pushDown(t);
    int M=(a[t].L+a[t].R)>>1;
    if(R<=M) paint(t<<1,L,R,x);
    else if(L>M) paint(t<<1|1,L,R,x);
    else
    {
        paint(t<<1,L,M,x);
        paint(t<<1|1,M+1,R,x);
    }
    if(a[t].L==L&&a[t].R==R) a[t].color=x,a[t].flag=1;
    else a[t].flag=0;
    if(a[t<<1].flag && a[t<<1|1].flag && a[t<<1].color==a[t<<1|1].color )
    {
        a[t].color=a[t<<1].color;
        a[t].flag=1;
    }
    a[t].sum=a[t<<1].sum+a[t<<1|1].sum;
}


int n,m;

i64 get(int t,int L,int R)
{
    if(a[t].L==L&&a[t].R==R) return a[t].sum;

    pushDown(t);

    int M=(a[t].L+a[t].R)>>1;
    i64 ans;
    if(R<=M) ans=get(t<<1,L,R);
    else if(L>M) ans=get(t<<1|1,L,R);
    else ans=get(t<<1,L,M)+get(t<<1|1,M+1,R);
    return ans;

}

int main()
{


    RD(n,m);
    build(1,1,n);
    while(m--)
    {
        int op;
        int L,R,x;
        RD(op);
        if(op==1)
        {
            RD(L,R,x);
            paint(1,L,R,x);
        }
        else
        {
            RD(L,R);
            i64 ans=get(1,L,R);
            cout<<ans<<endl;
        }
    }
}

