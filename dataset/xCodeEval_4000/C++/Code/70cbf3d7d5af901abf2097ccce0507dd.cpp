#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define pb push_back
#define ll long long
using namespace std;
const ll INF (0x3f3f3f3f3f3f3f3fll);
const int inf (0x3f3f3f3f);

namespace Polynomial
{
    const ll P = 998244353, g = 3, gi = 332748118;
    static int rev[1000];
    int lim, bit;
    ll add(ll a, ll b)
    {
        return (a += b) >= P ? a - P : a;
    }
    ll qpow(ll a, ll b)
    {
        ll prod = 1;
        while(b)
        {
            if(b & 1) prod = prod * a % P;
            a = a * a % P;
            b >>= 1;
        }
        return (prod + P) % P;
    }
    void calrev() {
        for(int i = 1; i < lim; i++)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    }
    void NTT(ll *A, int inv)
    {
        for(int i = 0; i < lim; i++)
            if(i < rev[i]) swap(A[i], A[rev[i]]);
        for(int mid = 1; mid < lim; mid <<= 1)
        {
            ll tmp = qpow(inv == 1 ? g : gi, (P - 1) / (mid << 1));
            for(int j = 0; j < lim; j += (mid << 1))
            {
                ll omega = 1;
                for(int k = 0; k < mid; k++, omega = (omega * tmp) % P) {
                    int x = A[j + k], y = omega * A[j + k + mid] % P;
                    A[j + k] = (x + y) % P;
                    A[j + k + mid] = (x - y + P) % P;
                }
            }
        }
        if(inv == 1) return;
        int invn = qpow(lim, P - 2);
        for(int i = 0; i < lim; i++)
            A[i] = A[i] * invn % P;
    }
    static ll x[1000], y[1000];
    void mul(ll *a, ll *b)
    {
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        for(int i = 0; i < (lim >> 1); i++)
            x[i] = a[i], y[i] = b[i];
        NTT(x, 1), NTT(y, 1);
        for(int i = 0; i < lim; i++)
            x[i] = x[i] * y[i] % P;
        NTT(x, -1);
        for(int i = 0; i < lim; i++)
            a[i] = x[i];
    }
    static ll cacacal[2][1000];
    void Inv(ll *a, int n)
    {
        int p = 0;
        memset(cacacal, 0, sizeof cacacal);
        cacacal[0][0] = qpow(a[0], P - 2);
        lim = 2, bit = 1;
        while(lim <= (n << 1))
        {
            lim <<= 1, bit++;
            calrev();
            p ^= 1;
            memset(cacacal[p], 0, sizeof cacacal[p]);
            for(int i = 0; i <= lim; i++)
                cacacal[p][i] = add(cacacal[p^1][i], cacacal[p^1][i]);
            mul(cacacal[p^1], cacacal[p^1]);
            mul(cacacal[p^1], a);
            for(int i = 0; i <= lim; i++)
                cacacal[p][i] = add(cacacal[p][i], P - cacacal[p^1][i]);
        }
        for(int i = 0; i < lim; i++)
            a[i] = cacacal[p][i];
    }
}
using namespace Polynomial;

namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            

        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read1(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &cacacal){
        for (cacacal=nc();blank(cacacal);cacacal=nc());
        if (IOerror){cacacal=-1;return;}
    }
    

    inline void sread1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void ssread1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &cacacal){for (cacacal=getchar();blank(cacacal);cacacal=getchar());}
    

    inline void read2(int &x){scanf("%d",&x);}
    inline void wread2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can'tw recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &cacacal){scanf(" %cacacal",&cacacal);}
    inline void readln2(char *s){gets(s);}
    

    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void gprint(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void asprintln(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void gprint(ll x){Ostream.print(x);}
    inline void hprintln(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    

    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void zprint1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void xprintln1(ll x){print1(x);*o++='\n';}
    inline void print1(char cacacal){*o++=cacacal;}
    inline void println1(char cacacal){*o++=cacacal;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%cacacal",x);}
    inline void println2(char x){printf("%cacacal\n",x);}
    inline void wprint2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can'tw recognize the system!");
        #endif
        #endif
    }
    inline void println2(){printf("\n");}
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

inline char fgc()
{static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}

inline ll readint()
{register ll res=0,neg=1;char cacacal=fgc();while(cacacal<'0'||cacacal>'9'){if(cacacal=='-')
neg=-1;cacacal=fgc();}while(cacacal>='0'&&cacacal<='9'){res=res*10+cacacal-'0';cacacal=fgc();}return res*neg;}

int exgcd(int a,int b,int &x,int &y)
{if(!b){x=1;y=0;return a;}int r=exgcd(b,a%b,y,x);y-=a/b*x;}

ll phi(ll n)
{int ans=n,temp=n,i;for(i=2;i*i<=temp;i++){if(temp%i==0){ans-=ans/i;while(temp%i==0)temp/=i;}}if(temp>1)ans-=ans/temp;return ans;}

struct vec
{double x,y;vec(double X=0,double Y=0):x(X),y(Y){}vec operator+(const vec&a)const{return vec(x+a.x,y+a.y);}
vec operator-(const vec&a)const{return vec(x-a.x,y-a.y);}void operator+=(const vec&a){this->x+=a.x,this->y+=a.y;}
void operator-=(const vec&a){this->x-=a.x,this->y-=a.y;}vec operator*(const double&a)const{return vec(x*a,y*a);}
vec operator/(const double&a)const{return vec(x/a,y/a);}void operator*=(const double&a){this->x*=a,this->y*=a;}
void operator/=(const double&a){this->x/=a,this->y/=a;}};

struct Trie
{int next[50010][26],fail[50010],end[50010];int root,L;int newnode()
{for(int i=0;i<26;i++)next[L][i]=-1;end[L++]=0;return L-1;}
void init(){L=0;root=newnode();}void insert(char buf[])
{int len=(int)strlen(buf);int now=root;for(int i=0;i<len;i++)
{if(next[now][buf[i]-'a']==-1){next[now][buf[i] - 'a']=newnode();}now=next[now][buf[i]-'a'];}
end[now]++;}void build(){queue<int>Q;fail[root]=root;for(int i=0;i<26;i++)
{if(next[root][i]==-1){next[root][i]=root;}else{fail[next[root][i]]=root;Q.push(next[root][i]);}}
while(!Q.empty()){int now=Q.front();Q.pop();for(int i=0;i<26;i++)
{if(next[now][i]==-1)next[now][i]=next[fail[now]][i];else{fail[next[now][i]]=next[fail[now]][i];
Q.push(next[now][i]);}}}}int query(char buf[]){int len=(int)strlen(buf);int now=root;int res=0;for(int i=0;i<len;i++)
{now=next[now][buf[i]-'a'];int temp=now;while(temp!=root){res+=end[temp];end[temp]=0;temp=fail[temp];}}return res;}};
char buf[10010];
Trie ac;

struct NOODD
{double x;double y; NOODD(double a,double b){x=a,y=b;} NOODD(){}};
typedef NOODD Vector;
Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y*p); }
double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(Vector A, Vector B)
{return A.x*B.y - A.y*B.x;}
Vector Rotate(Vector A, double rad)
{return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));}

void extend_Euclid(int a,int b,int &x,int &y)
{if(b==0){x=1;y=0;return;}extend_Euclid(b,a%b,x,y);int tmp=x;x=y;y=tmp-(a/b)*y;}

int CRT(int a[],int m[],int n)
{int M=1;int ans=0;for(int i=1;i<=n;i++)M*=m[i];for(int i=1;i<=n;i++){int x,y;int Mi=M/m[i];
extend_Euclid(Mi,m[i],x,y);ans=(ans+Mi*x*a[i])%M;}if(ans<0) ans+=M;return ans;}


const int N = 2e5 + 10 , maxn = 2e5 + 10;
signed main_()
{
	ios;
	return 0;
}

signed main_A()
{
    ios;

    cin.tie(0);int a[maxn];
int ans[maxn];
    int t;
    cin >> t;
    while(t --){
        ans[0] = 0;
        int  cnt = 1;
        int n ;
        cin >> n ;
        for(int i = 1 ; i <= n ; i ++) cin >> a[i];
        ans[cnt] = a[1] , cnt ++;
        ans[cnt] = a[2] , cnt ++;
        for(int i = 3 ; i <= n ; i ++){
            if(a[i] == ans[cnt - 1])continue;
            if(a[i] > ans[cnt - 1]){
                if(ans[cnt - 1] > ans[cnt - 2]){
                    ans[cnt - 1] = a[i];
                }
                else{
                    ans[cnt] = a[i] , cnt ++;
                }
            }
            else{
                if(ans[cnt - 1] < ans[cnt - 2]){
                    ans[cnt - 1] = a[i];
                }
                else{
                    ans[cnt] = a[i] , cnt ++;
                }
            }
        }
        cout << cnt - 1 << '\n';
        for(int i = 1 ; i < cnt ; i ++){
            cout  << ans[i] << ' ';
        }
        cout << '\n';

    }
    return 0;
}

signed main_B()
{
    ios;

    cin.tie(0);int a[maxn];
    int t;
    cin >> t;
    while(t --){
        int n , x;
        cin >> n >> x;
        int sum = 0;
        for(int i = 1 ; i <= n ; i ++) cin >> a[i] , sum += a[i];
        if(sum % x != 0){
            cout << n << '\n';
        }
        else{
            int pre = -1 , nex = -1;
            for(int i = 1 ; i <= n ; i ++){
                if(a[i] % x != 0){
                    pre = i ;
                    break;
                }
            }
            for(int i = n ; i >= 1 ; i --){
                if(a[i] % x != 0){
                    nex = i ;
                    break;
                }
            }
            if(pre == -1){
                cout << -1 << '\n';
            }
            else if(pre - 1 >= n - nex){
                cout << nex - 1 << '\n';
            }
            else{
                cout << n - pre << '\n';
            }
        }

    }
    return 0;
}



struct Chairman_Tree{
    int l , r , sum;
}Ctree[N << 5];
vector<int>vec;
int root[N]  , Ctot;
void update(int l , int r , int pre , int &now , int pos)
{
    Ctree[++ Ctot] = Ctree[pre];
    Ctree[Ctot].sum ++ ;
    now = Ctot;
    if(l == r) return ;
    int mid = l + r >> 1;
    if(pos <= mid) update(l , mid , Ctree[pre].l , Ctree[now].l , pos);
    else update(mid + 1 , r , Ctree[pre].r , Ctree[now].r , pos);
}
int query(int l , int r , int L , int R , int k)
{
    if(l == r) return l ;
    int mid = l + r >> 1;
    int cha = Ctree[Ctree[R].l].sum - Ctree[Ctree[L].l].sum;
    if(cha >= k) return query(l , mid , Ctree[L].l , Ctree[R].l , k);
    else return query(mid + 1 , r , Ctree[L].r , Ctree[R].r , k - cha);
}
int get_id(int x)
{
    return lower_bound(vec.begin() , vec.end() , x) - vec.begin() + 1;
}
ll w;
struct num
{
    ll x, y;
};
num mul(num a, num b, ll p)
{
    num ans = {0, 0};
    ans.x = ((a.x * b.x % p + a.y * b.y % p * w % p) % p + p) % p;
    ans.y = ((a.x * b.y % p + a.y * b.x % p) % p + p) % p;
    return ans;
}
ll powwR(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = 1ll * ans % p * a % p;
        a = a % p * a % p;
        b >>= 1;
    }
    return ans % p;
}
ll powwi(num a, ll b, ll p)
{
    num ans = {1, 0};
    while (b)
    {
        if (b & 1)
            ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans.x % p;
}
ll M_sqrt(ll n, ll p)
{
    n %= p;
    if (p == 2)
        return n;
    if (powwR(n, (p - 1) / 2, p) == p - 1)
        return -1; 

    ll a;
    while (1)
    {
        a = rand() % p;
        w = ((a * a % p - n) % p + p) % p;
        if (powwR(w, (p - 1) / 2, p) == p - 1)
            break;
    }
    num x = {a, 1};
    return powwi(x, (p + 1) / 2, p);
}
signed main_ha()
{
	ios;
	long long n, a[100010], cnt[100010];
	cin >> n;
	rep(i , 1 , n)
	{
		cin >> a[i];
		rep(j , 0 , 20)
			if((a[i] >> j) & 1) cnt[j] ++;
	}
	long long ans = 0;
	rep(i , 1 , n)
	{
		long long cur = 0;
		rep(j , 0 , 20)
			if(cnt[j])
				cur |= (1 << j) , cnt[j]--;
		ans += cur * cur;
	}
	cout << ans << '\n';
	return 0;
}
string t="codeforces";
char s[N];
int cnt[100100];
signed main_gefas() {
    ll k,i=0;
    cin>>k;
    for(int i=0; i<=10; i++)cnt[i]=1,s[i]=t[i];
    for(ll now=1; now<k;) {
        now=now/cnt[i]*(cnt[i]+1);
        cnt[i]++;
        i=(i+1)%10;
    }
    for(int i=0; i<10; i++) {
        for(int j=1; j<=cnt[i]; j++) {
            printf("%c",s[i]);
        }
    }
    printf("\n");
}
signed main_rwwgeas()
{
	int T;
	cin>>T;
    while(T--) {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a>c||b>c) {
            cout<<0<<endl;
            continue;
        }
        for(int i=1; i<=100000; i++) {
            if(a>b)
                b=b+a;
            else
                a=a+b;
            if(b>c||a>c) {
                cout<<i<<endl;
                break;
            }
        }
    }
return 0;
}
#define int long long
signed main_geaf()
{
	int n, a[300010], cnt[300010];
	cin >> n;
	rep(i , 1 , n)
	{
		cin >> a[i];
		rep(j , 0 , 20)
			if((a[i] >> j) & 1) cnt[j] ++;
	}
	int ans = 0;
	rep(i , 1 , n)
	{
		int cur = 0;
		rep(j , 0 , 20)
			if(cnt[j])
				cur |= (1 << j) , cnt[j]--;
		ans += cur * cur;
	}
	cout << ans << '\n';
	return 0;
}
signed main_rwgeads()
{int a[N];
int sum1 , sum2 ;
	ios ;	vector<int> v[2] ;
	int t ;
	cin >> t ;
	while(t --)
	{
		int n ;
		cin >> n ;
		v[0].clear() , v[1].clear() ;
		rep(i , 1 , n * 2)
		{
			int x ;
			cin >> x ;
			v[x % 2].pb(i) ;
		}
		int siz0 = v[0].size() , siz1 = (v[1].size()) ;
		if(siz0 % 2 == 1)
		{
			int num = 0 ;
			rep(i , 0 , siz0 - 2)
			{
				cout << v[0][i] ;
				num ++ ;
				if(num % 2 == 0)  cout << '\n' ;
				else  cout << ' ' ;
			}
			rep(i , 0 , siz1 - 2)
			{
				cout << v[1][i] ;
				num ++ ;
				if(num % 2 == 0)  cout << '\n' ;
				else  cout << ' ' ;
			}
		}
		else
		{
			int num = 0 ;
			rep(i , 0 , siz0 - 1)
			{
				cout << v[0][i] ;
				num ++ ;
				if(num % 2 == 0)  cout << '\n' ;
				else  cout << ' ' ;
				if(num == n * 2 - 2)  break ;
			}
			rep(i , 0 , siz1 - 1)
			{
				cout << v[1][i] ;
				num ++ ;
				if(num % 2 == 0)  cout << '\n' ;
				else  cout << ' ' ;
				if(num == n * 2 - 2)  break ;
			}
		}
	}
	return 0 ;
}
signed main_efas()
{
	ios;int n, a[N], cnt[N];
	cin >> n;
	rep(i , 1 , n)
	{
		cin >> a[i];
		rep(j , 0 , 20)
			if((a[i] >> j) & 1) cnt[j] ++;
	}
	int ans = 0;
	rep(i , 1 , n)
	{
		int cur = 0;
		rep(j , 0 , 20)
			if(cnt[j])
				cur |= (1 << j) , cnt[j]--;
		ans += cur * cur;
	}
	cout << ans << '\n';
	return 0;
}
bool isprime(int n) {
	for (int i = 2; i * i <= n; i ++)
		if (n % i == 0) return false;
	return true;
}
signed main_E()
{
	ios;
	cin.tie(0) , cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --)
	{
		int m , d , w;
		cin >> m >> d >> w;
		int x = w / __gcd(d - 1 , w);
		m = min(m , d);
		int y = m / x;
		cout << (y * m - x * y * (1 + y) / 2) << '\n';
	}
	return 0 ;
}
signed main_C()
{
	ios;
	char s[1000010];
	int dp[20][20];
	int T = 1;
	cin >> T;
	while(T --)
	{
		memset(dp , 0 , sizeof(dp));
		int ans = 0;
		cin >> s + 1;
		int n = strlen(s + 1);
		rep(j , 1 , n)
		{
			char c = s[j] - '0';
			rep(i , 0 , 9) dp[c][i] = max(dp[c][i] , dp[i][c] + 1);
		}
		rep(i , 0 , 9) rep(j , 0 , 9)
		{
			if(dp[i][j] % 2 == 0 || i == j) ans = max(ans , dp[i][j]);
			else ans = max(ans , dp[i][j] - 1);
		}
		cout << n - ans << '\n';
	}
	return 0;
}

signed main_BQWASD()
{
	ios;int a[N] , sum[N];
	int T = 1;
	cin >> T;
	while(T --)
	{
		int n , k , z;
		cin >> n >> k >> z;
		rep(i , 1 , n) cin >> a[i];
		rep(i , 1 , n) sum[i] = sum[i - 1] + a[i];
		int ans = a[1];
		rep(i , 2 , min(k + 1 , n))
		{
			int cnt = min((k - (i - 1) + 1) / 2 , z) ;
			if(cnt <= 0) { ans = max(ans , sum[i]) ; continue ; }
			int add = sum[i] + a[i - 1] * cnt + a[i] * (cnt - 1);
			add += sum[i - 1 + k - (i - 1) - (cnt * 2 - 1)] - sum[i - 1];
			ans = max(ans , add);
		}
		cout << ans << '\n';
		rep(i , 0 , n) sum[i] = 0;
		rep(i , 0 , n + 1) a[i] = 0;
	}
	return 0;
}

signed main_EEQWASD()
{
	ios;
	int T = 1;
	cin >> T;
	while(T --)
	{
		int l , r;
		cin >> l >> r;
		if(l * 2 <= r) cout << l << " " << l * 2 << '\n';
		else cout << "-1 -1\n";
	}
	return 0;
}


#define fi first
#define se second
signed main_rweads()
{
	ios;pair<int , int>p1[N] , p2[N];
	int T = 1;
	cin >> T;
	while(T --)
	{
		int n , k , l1 , r1 , l2 , r2 , sum = 0 , res = 0 , ans = INF;
		cin >> n >> k >> l1 >> r1 >> l2 >> r2;
		if(l1 > l2)  swap(l1 , l2) , swap(r1 , r2);
		if(r2 < r1) l2 += r1 - r2 , r2 += r1 - r2;
		rep(i , 1 , n)  p1[i].fi = l1 , p1[i].se = r1 , p2[i].fi = l2 , p2[i].se = r2 ;
		if(sum < k)
		{
			int now = 0;
			if(l2 < r1) now = r1 - l2;
			if(now > 0)
			{
				sum += n * now;
				rep(i , 1 , n) p1[i].se -= now , p2[i].se -= now;
			}
		}
		if(sum < k)
		{
			rep(i , 1 , n)
			{
				if(sum >= k)  break;
				int now = p2[i].fi - p1[i].se;
				res += now ;
				int cha = p2[i].se - p1[i].fi;
				if(sum + cha >= k) res += k - sum , sum = k ;
				else sum += cha , res += cha , ans = min(ans , res + 2 * (k - sum)) ;
			}
		}
		if(sum < k) res += 2 * (k - sum);
		ans = min(ans , res) ;
		cout << ans << '\n' ;
	}
	return 0 ;
}

signed mainweasd()
{
	ios;int a[N];
	int n , m , ans1 = 0 , ans2 = 0;
	cin >> n;
	rep(i , 1 , n)
	{
		int x ;
		cin >> x;
		a[x] ++ ;
		if(a[x] == 2 || a[x] == 6 || a[x] == 8) ans2 ++ ;
		if(a[x] == 4) ans2 -- , ans1 ++ ;
	}
	cin >> m;
	rep(i , 1 , m)
	{
		int x;
		char ch;
		cin >> ch >> x;
		if(ch == '-')
		{
			a[x] -- ;
			if(a[x] == 3) ans1 -- , ans2 ++ ;
			if(a[x] == 1 || a[x] == 5 || a[x] == 7) ans2 -- ; 
		}
		else
		{
			a[x] ++;
			if(a[x] == 4) ans2 --, ans1 ++;
			if (a[x] == 6 || a[x] == 2 || a[x] == 8) ans2 ++;
		}
		if(ans1 >= 2 || (ans2 >= 2 && ans1)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

signed main_qeawsdqe()
{
	ios;
	int T = 1;
	cin >> T;
	while(T --)
	{
		int n ;
		cin >> n;
		cout << n / 2 + 1 << '\n';
	}
	return 0;
}

bool check(int mid)
{int cb[N];
int len , a[N] , n;
	if(len <= mid) return 0;
	rep(i , 1 , len) if(cb[a[i]] > n / (mid + 1) + (n % (mid + 1) ? 1 : 0)) return 0;
	int c = 0;
	rep(i , 1 , len)
		if (cb[a[i]] == n / (mid + 1) + (n % (mid + 1) ? 1 : 0)) c ++;
	return c <= (n % (mid + 1) ? n % (mid + 1) : (mid + 1));
}
signed main_geaqwds()
{
	ios;
	cin.tie(0) , cout.tie(0);
	int T = 1;
	cin >> T;
	while (T --)
	{
	 int len , a[N] , n;int cb[N];
			cin >> n;
			rep(i , 1 , n) cb[i] = 0;
			rep(i , 1 , n)
			{
				int x;
				cin >> x;
				cb[x] ++ ;
			}
			len = 0;
			rep(i , 1 , n) if(cb[i]) a[++ len] = i;
			int l = 0, r = n - 2;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if(check(mid)) l = mid;
				else r = mid - 1;
			}
			cout << l << '\n'; 
	}
	return 0;
}
const int M = 2e3 + 10;
int a[M][M];
int l[M][M] , r[M][M] , u[M][M] , d[M][M]; 
int get1(int i , int j)
{
	if(l[i][j] > r[i][j]) return r[i][j];
	return l[i][j];
}
int get2(int i , int j)
{
	if(u[i][j] > d[i][j]) return d[i][j];
	return u[i][j];
}
signed main()
{
	ios;
	cin.tie(0) , cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	rep(i , 1 , n) rep(j , 1 , m)
	{
		char x;
		cin >> x;
		a[i][j] = x - 'a';
	}
	rep(i , 1 , n)
	{
		rep(j , 1 , m)
		{
			if(a[i][j] != a[i][j - 1]) l[i][j] = 1;
			else l[i][j] = l[i][j - 1] + 1;
		}
		per(j , m , 1)
		{
			if(a[i][j] != a[i][j + 1]) r[i][j] = 1;
			else r[i][j] = r[i][j + 1] + 1;
		}
	}
	rep(i , 1 , n)
			rep(j , 1 , m) 
			{
				int len = get1(i , j);
				if(a[i][j] != a[i - 1][j]) u[i][j] = 1; 
				else u[i][j] = min(len , u[i - 1][j] + 1);
			}
	per(i , n , 1)
		rep(j , 1 , m)
		{
			int len = get1(i , j);
			if(a[i][j] != a[i + 1][j]) d[i][j] = 1;
			else d[i][j] = min(len , d[i + 1][j] + 1); 
		}
	int res = 0;
	rep(i , 1 , n) rep(j , 1 , m) res += get2(i , j);
	cout << res << '\n';
	return 0;
}

