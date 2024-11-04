


























#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")

#include<bits/stdc++.h>






#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>

using namespace std ;
namespace io
{
    const int N=1<<20;
    char buf[N],*t1=buf,*t2=buf;
    #ifdef cjy
    #define getc getchar
    #else
    #define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
    #endif
    inline int read()
    {
        static int an;an=0;
        static char ch;ch=getc();
        while(ch<48||ch>57)ch=getc();
        while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
        return an;
    }
}using io::read;
#define WorkingArea() int main(int argc, char **argv)
#define test() int t; cin >> t; while(t--)
#define ll long long
#define ull unsigned long long int
#define ld long double
#define lli long long int
#define lop(i,n) for(int i=0;i<n;i++)
#define rloop(i,n) for (int i = n-1; i >= 0; i--)
#define loop(x, n) for(ll x = 0; x < n; ++ x)
#define rep(x,n) for(ll x=1;x<=n;x++)
#define frange(i,l,r) for(int i=l;i<r;i++)
#define mp make_pair
#define pb push_back
#define I cin>>
#define O cout<<
#define W(x) while(x--)
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define s(x) scanf("%lld",&x)
#define p(x) printf("%lld\n",x)
#define sc(x) scanf("%s",x)
#define pc(x) printf("%s",x)
#define out2(x, y) cout<< (x) << " " << (y) << endl
#define out3(x, y, z) cout<< (x) << " " << (y) << " " << (z) << endl
#define F first
#define S second
#define sz size()
#define re return
#define inf 1e18
#define MAX 10000000
#define M 1000000007
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prec(x) fixed<<setprecision(15)<<x
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fix(a, k) (ll(a) % ll(k) + k) % k  

#define magic ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define XXX return 0;
#define stringToLower(s)  transform(all(s), s.begin(), ::tolower);
#define stringToUpper(s)  transform(all(s), s.begin(), ::toupper);
#define noOfDigits(n)  (1+floor(log10(n)))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, n) ((S) & (n - 1))   

#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define posOfFirstSetBit(n) (log2(n & -n) + 1);
#define ARR(a,n) ll a[n];for(ll i=0;i<n;scanf("%ld ",&a[i++]));
#define ARR2D(a,n,m) ll a[n][m];for(ll i=0;i<n;i++)for(ll j=0;i<m;scanf("%ld ",&a[i][j++]));
#define SHOW2D(a,n,m) ll a[n][m];for(ll i=0;i<n;i++){for(ll j=0;i<m;printf("%ld ",a[i][j++]));printf("\n")}
#define SHOW(a,n) printf("\n");for(ll i=0;i<n;printf("%ld ",a[i++]));
#define br cout<<"\n";
#define nl <<"\n";
#define RESET(a,b)    memset(a,b,sizeof(a))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define _abs(x, y) ((x>y)?(x-y):(y-x))
#define each(x,y) for(auto &(x): (y))
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define mii map<int,int>
#define mll map<ll,ll>
#define mic map<int,char>
#define mci map<char,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vop vector<pair<int,int>>
 
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
















bool PointInRectangle(ll x1, ll y1, ll x2,
    ll y2, ll x, ll y) {
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}


















string Letters = "0123456789ABCDEF";
int toInt(char c) { return Letters.find(c); }
ll FromAnyBaseToDecimal(string inp, int base) { ll res = 0;  lop(i,inp.sz) { res *= base; res += toInt(inp[i]); } return res; }
string FromDecimalToAnyBase(ll n, int base) { if (n == 0) return "0";  string ret = ""; while (n) { ret = Letters[n%base] + ret;  n /= base; } return ret; }































double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }
ll mult(ll a, ll b) { re(1LL * a * b) % M; }
ll SumOfOdd(ll l, ll r) { ll Rsm = (r + 1) / 2; Rsm *= Rsm; l--; ll Lsm = (l + 1) / 2; Lsm *= Lsm; return Rsm - Lsm; }
ll NoOfOdd(ll L, ll R) { ll n = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)n++; return n; }
ll NoOfEven(ll L, ll R) { re((R - L + 1) - NoOfOdd(L, R)); }









int extgcd(int a, int b, int &x, int &y) {
    int g = a;
    x = 1;
    y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
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
bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

bool is_perfect_cube(int n) {
    int root(round(cbrt(n)));
    return n == root * root * root;
}



void n_primes(){
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
    vi primedivisor;
    while(n%2==0)
    {
        primedivisor.pb(2);
        n>>=1;
    }
    for(int i=3; i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            primedivisor.pb(i);
        }
    }
    if(n>2)
        primedivisor.pb(2);

    if(primedivisor.sz>=k)
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