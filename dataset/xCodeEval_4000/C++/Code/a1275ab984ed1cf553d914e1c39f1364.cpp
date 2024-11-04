



#include <bits/stdc++.h>
using namespace std;

#define gc              getchar_unlocked
#define gc              getchar
#define pc              putchar_unlocked
#define pc              putchar

#define pb              push_back
#define ForA(n)         for (ll i=0; i<n; i++)
#define ForA2(n)        for (ll j=0; j<n; j++)
#define ForA3(n)        for (ll k=0; k<n; k++)
#define ForN(n)         for (ll i=1; i<=n; i++)
#define ForN2(n)        for (ll j=1; j<=n; j++)
#define ForN3(n)        for (ll k=1; k<=n; k++)
#define SortA(n,x)      sort(n,n+x);
#define SortS(s)        sort(s.begin(), s.end());
#define SortRS(s)       sort(s.rbegin(), s.rend());
#define Search(s)       s.begin(), s.end()
#define SortSG(n)       sort(n.begin(), n.end(), greater<int>());
#define Cin(a)          cin>>a;
#define GCin(a)         getline(cin,a);
#define Sz(a)           a.size()
#define Cin2(a,b)       cin>>a>>b;
#define Cin3(a,b,c)     cin>>a>>b>>c;
#define Cin4(a,b,c,d)   cin>>a>>b>>c>>d;
#define scan2(a,b)      scan(a);scan(b);
#define scan3(a,b,c)    scan(a);scan(b),scan(c);
#define scan4(a,b,c,d)  scan(a);scan(b),scan(c),scan(d)
#define Unique(n)       sort(Search(n)),n.erase(unique(Search(n)),n.end())
#define PI              3.1415926535897932384626433832795l
#define Ignore          cin.ignore();
#define Cout(n)         cout<<n<<endl;
#define mem(n,i)        memset(n,i,sizeof n);
#define deci(n)         cout<<fixed<<setprecision(n);
#define square(n)       (n*n)
#define cube(n)         (n*n*n)
#define F               first
#define S               second
#define bug()           cerr<<"*****<>*****\n";
#define bug2(a,b)       cout<<#a<<"-> "<<a<<" | "<<#b<<"-> "<<b<<endl;
#define bug3(a,b,c)     cout<<#a<<"-> "<<a<<" | "<<#b<<"-> "<<b<<" | "<<#c<<"-> "<<c<<"\n";
#define bug4(a,b,c,d)   cout<<#a<<"-> "<<a<<" | "<<#b<<"-> "<<b<<" | "<<#c<<"-> "<<c<<" | "<<#d<<"-> "<<d<<"\n";
#define bug5(a,b,c,d,e) cout<<#a<<"-> "<<a<<" | "<<#b<<"-> "<<b<<" | "<<#c<<"-> "<<c<<" | "<<#d<<"-> "<<d<<" | "<<#e<<"-> "<<e<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef unsigned long long ull;
typedef long double ldb;
typedef long long ll;
typedef stringstream SS;
typedef vector<string> VS;
typedef vector<ll> VI;
typedef vector<char> VC;
typedef map<string, string> MSS;
typedef map <ll,string> MIS;
typedef map <char,ll> MCI;
typedef map <string,ll> MSI;
typedef map <ll,ll> MII;
typedef pair<int, int> pii;
map <ll, ll> fib;

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = { 0, 1, 0,-1};

const int dx8[] = {-1, 0, 1, 0, -1,-1, 1, 1};
const int dy8[] = { 0, 1, 0,-1, -1, 1,-1, 1};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1,  -1, 2 , -2, 2,-2, 1,-1};

template <typename T> inline T ItoS(T n){SS a; a<<n;return a.str();}
template <typename T> inline T TrailingZeros(T  n){ll cnt = 0;for(ll i=5; n/i>=1; i*=5) cnt += n/i;return cnt;}
template <typename T> inline T StoI(T s){ll sum=0;for(ll i=0; i<Sz(s); i++){s[i]-='0';sum=sum*10+s[i];}return sum;}
template <typename T> inline T binary_decimal(T n){ll decimal=0, i=0, rem;while (n!=0){rem = n%10;n/=10;decimal += rem*pow(2,i);++i;}return decimal;}
template <typename T> inline T LCM(T a,T b){return (a*b)/GCD(a,b);}
template <typename T> inline T maxi(T x, T y) { if(x>y) return x; else return y;}
template <typename T> inline T maxi(T x, T y,T z) { return maxi(maxi(x,y),z);}
template <typename T> inline T mini(T x, T y) { if(x<y) return x; else return y;}
template <typename T> inline T mini(T x, T y,T z) { return mini(mini(x,y),z);}
template <typename T> inline T GCD(T a,T b)   {ll t;while(a){t = a;a = b%a;b = t;}return b;}
template <typename T> inline T Pow(T base,T exp){ll result = 1;while (exp){if(exp&1)result*=base;exp>>=1;base*=base;}return result;}
template <typename T> inline T Mulmod(T a, T b, T c){ull x = 0,y = a%c;while(b>0){if(b&1) x = (x+y)%c;y = (y<<1)%c;b >>= 1;}return x;}
template <typename T> inline T Pow(T base,T exp,T mod){ull x = 1, y = base;while(exp>0){if(exp&1) x = Mulmod(x,y,mod);y = Mulmod(y,y,mod);exp >>= 1;}return x;}
template <typename T> inline T modulo(T a,T b,T c){ull x = 1 , y = a%c ;while( b>0 ){if(b%2) x = Mulmod(x,y,c) ;y=Mulmod(y,y,c);b/=2;}return x%c ;}
template <typename T> inline T BigMod(T a, T b, T m){if(!b)return 1;ll x=BigMod(a, b/2, m);x=(x*x)%m;if(b%2)x=(x*a)%m;return x;}
template <typename T> inline T EGCD(T a,T b,T &x,T &y){if(a == 0) {x = 0;y = 1;return b;}T x1, y1;T d = EGCD(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
template <typename T> inline T NumOfDivisor(T n){ ll cnt=0; int square_root = (int) sqrt(n) + 1; for (int i = 1; i < square_root; i++) { if (n%i == 0&&i*i!=n) cnt+=2; if (n%i == 0&&i*i==n) cnt++;} return cnt;}
template <typename T> string to_string(T const& value) { stringstream sstr; sstr << value; return sstr.str();}
template <class T1,class T2,class T3,class T4> int lcs( T1 X,T2 Y,T3 m,T4 n ){int L[m+1][n+1];int i, j;for (i=0; i<=m; i++){for (j=0; j<=n; j++){if (i == 0 || j == 0)L[i][j] = 0;else if (X[i-1] == Y[j-1])L[i][j] = L[i-1][j-1] + 1;else L[i][j] = max(L[i-1][j], L[i][j-1]);}}return L[m][n];}
template<class T>inline ll Fibonacci(T n){if(n == 0) return 0;if(n == 1 or n == 2) return fib[n] = 1;if(fib[n]) return fib[n];ll k = (n+1) >> 1;if(n&1){fib[n] = Fibonacci(k)*Fibonacci(k) + Fibonacci(k-1)*Fibonacci(k-1);}else fib[n] = ((Fibonacci(k-1)) << 1) + Fibonacci(k)*Fibonacci(k);return fib[n];}
template<class T, class T2>inline ll Fibonacci(T n, T2 M){if(n == 0) return 0;if(n == 1 or n == 2) return fib[n] = 1;if(fib[n]) return fib[n];ll k = (n+1) >> 1;if(n&1){fib[n] = (Fibonacci(k,M) * Fibonacci(k,M) + Fibonacci(k-1,M) * Fibonacci(k-1,M)) % M;}else fib[n] = (((Fibonacci(k-1,M)) << 1) + Fibonacci(k,M)*Fibonacci(k,M)) % M;return fib[n];}















template <typename T> inline T scan(T &n) { n=0; bool negative=0; char c=gc(); while(c<'0'||c>'9') {if(c=='-') negative=1; c=gc();} while(c>='0'&&c<='9'){n=n*10+c-48;c=gc();} if(negative) n=~(n-1);}
template <typename T> void print(T n){if(n<0){pc('-');n=-n;}if(!n){pc('0');pc('\n');return;}char buff[12];int len=0;while(n) buff[len++]=n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);pc('\n');}
template <typename T> void print(T a, T b){print(a);print(b);}
template <typename T> void print(T a, T b, T c){print(a);print(b);print(c);}
template <typename T> void Print(T n){if(n<0){pc('-');n=-n;}if(!n){pc('0');return;}char buff[12];int len=0;while(n) buff[len++]=n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);}
template <class T1,class T2> void Print(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template <class T1,class T2,class T3> void Print(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template <class T1,class T2,class T3,class T4> void Print(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}













int main(){

    #ifdef FariD
        

        

    #endif 


    int n;


    scan(n);

    MII(mp);

    int arr[n+5];

    for(int i=1; i<=n; i++) scan(arr[i]);

    sort(arr+1,arr+n+1);

    if(n == 1) {cout << -1 << endl; return 0;}

    int diff = arr[2]-arr[1];

    int tmp = 0;

    bool flg = 0;
    int pos=0;
    int cnt = 0;

    for(int i=2; i<=n; i++){

        mp[arr[i]-arr[i-1]]++;

        if(diff != arr[i]-arr[i-1]){

            tmp = arr[i]-arr[i-1];
            pos = i-1;
            flg = 1;
        }
    }


    if(!flg and diff == 0) {cout << 1 << endl << arr[1] << endl; return 0;}
    if(diff == 0 or (tmp == 0 and flg ) ) {cout  << 0 << endl; return 0;}
    if(mp[diff]+mp[tmp] != n-1 or (mp[tmp]>1 and mp[diff]>1) ) {cout << 0 << endl; return 0;}


    if(mp[tmp] > mp[diff]) {
        swap(diff, tmp);
        pos = 1;
    }
    else if(mp[tmp] == mp[diff]) swap(tmp, diff);
    

    if(flg and tmp > diff and diff*2 == tmp) {
        int val = 0;
        for(int i=1; i<n; i++){
            if(arr[i]+diff != arr[i+1] and (i+2 >= n or arr[i+2]-arr[i+1] == diff) ){
                val = arr[i]+diff;
                i++;
                i++;
                while(arr[i]-arr[i-1] == diff and i<=n) i++;
                if(i > n) cout << 1 << endl << val << endl;
                else Cout(0)

                return 0;
            }
            else if(arr[i]+diff != arr[i+1]) break;
        }
        return cout << 0 << endl, 0;
    }
    else if(flg and tmp < diff and diff == tmp*2 ) {
        

        int val;
        for(int i=1; i<n; i++){

            if(arr[i]+tmp != arr[i+1] and (i+2 >= n or arr[i+2]-arr[i+1] == tmp)) {
                val = arr[i]+tmp;
                i++;
                i++;
                while(arr[i]-arr[i-1] == tmp and i<=n) i++;
                if(i > n) cout << 1 << endl << val << endl;
                else Cout(0)

                return 0;
            }
            else if(arr[i]+tmp != arr[i+1]) break;
        }
        return cout << 0 << endl, 0;
    }
    else if(flg) {cout << 0 << endl;return 0;}

    if(diff&1){
        cout << 2 << endl;
        cout << arr[1]-diff << " " << arr[n]+diff << endl;
        return 0;
    }
    else {
        if(n == 2){
            cout << 3 << endl;
            cout << arr[1]-diff << " " << (diff >> 1)+arr[1] << " " << arr[n]+diff << endl;
        }
        else {
            cout << 2 << endl;
            cout << arr[1]-diff << " " << arr[n]+diff << endl;
        }
        return 0;
    }



    return 0;
}
