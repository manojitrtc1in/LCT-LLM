































































using namespace std ;
namespace io
{
    const int N=1<<20;
    char buf[N],*t1=buf,*t2=buf;
    
    
    
    
    
    inline int read()
    {
        static int an;an=0;
        static char ch;ch=getc();
        while(ch<48||ch>57)ch=getc();
        while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
        return an;
    }
}using io::read;
















































































 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;

const double PI=3.141592653589793238462643383279502884197169399375105820974944;




vector<bool> chkprime (MAX,true);
unsigned primearray[5761459];

const int monthly[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };



ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b))*b; }
ll nCr(ll n, ll r) { if (n<r)return 0; if (r == 0)return 1; return n*nCr(n - 1, r - 1) / r; }





ll PowMod(ll bs, ll ex, ll Mod) { if (!ex)return 1; ll p = PowMod((bs*bs) % Mod, ex >> 1, Mod); re(ex & 1) ? (p*bs) % Mod : p; }
ll ModInverse(ll a) { return PowMod(a, M - 2, M); }
















bool id4(ll x1, ll y1, ll x2,
    ll y2, ll x, ll y) {
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}


















string Letters = "0123456789ABCDEF";
int toInt(char c) { return Letters.find(c); }
ll id1(string inp, int base) { ll res = 0;  lop(i,inp.sz) { res *= base; res += toInt(inp[i]); } return res; }
string id0(ll n, int base) { if (n == 0) return "0";  string ret = ""; while (n) { ret = Letters[n%base] + ret;  n /= base; } return ret; }































double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }
ll mult(ll a, ll b) { re(1LL * a * b) % M; }
ll id7(ll l, ll r) { ll Rsm = (r + 1) / 2; Rsm *= Rsm; l--; ll Lsm = (l + 1) / 2; Lsm *= Lsm; return Rsm - Lsm; }
ll id2(ll L, ll R) { ll n = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)n++; return n; }
ll id6(ll L, ll R) { re((R - L + 1) - id2(L, R)); }









int id8(int a, int b, int &x, int &y) {
    int g = a;
    x = 1;
    y = 0;
    if (b != 0) g = id8(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
bool isPalindrome(string str) { ll l = 0; ll h = str.sz - 1; while (h > l) { if (str[l++] != str[h--]) { return 0; } } return 1; }
bool primity(long long n)
{
    if(n<=1)
        return false;
    if(n<=3)
        return true;

    if(n%2==0 || n%3==0)
        return false;

    for(auto i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;

    return true;
}
int power_x(int x, unsigned y)
{
    if(y==0)
        return 1;
    if(!(y&1))
        return power_x(x,y>>1)*power_x(x,y>>1);
    return x*power_x(x,y>>1)*power_x(x,y>>1);
}
int sod(int n)
{
    int sum=0;
    while(n > 0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int order_x(long long x)
{
    int n=0;
    while(x)
    {
        n++;
        x/=10;
    }
    return n;
}
bool id10(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

bool id9(int n) {
    int root(round(cbrt(n)));
    return n == root * root * root;
}



void id5(){
    chkprime[0]=chkprime[1]=false;
    for(unsigned i=2;i*i<=MAX;i++){
        if(chkprime[i]){
            for(unsigned j=i;j*i<=MAX;j++) chkprime[i*j]=false;
        }
    }
    unsigned id = 1;
    primearray[0]=2;

    for(int i=3;i<=MAX;i+=2){
        if(chkprime[i]){
            primearray[id++]=i;
        }
    }
}
bool solve(ll n, ll k)
{
    vi id3;
    while(n%2==0)
    {
        id3.pb(2);
        n>>=1;
    }
    for(int i=3; i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            id3.pb(i);
        }
    }
    if(n>2)
        id3.pb(2);

    if(id3.sz>=k)
        return true;
    else
        return false;
}



string alp = "abcdefghijklmnopqrstuvwxyz";
WorkingArea()
{
    


    magic;


        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);


    




        int b,g;
        I b>>g;

        lop(i,min(b,g))
        {
            if(g>=b){
                O "GB";
            }
            else{
                O "BG";
            }
        }

        if(b<g){
            lop(i,g-b)
            O "G";
        }
        else if(g<b){
            lop(i,b-g){
                O "B";
            }
        }












    XXX
}