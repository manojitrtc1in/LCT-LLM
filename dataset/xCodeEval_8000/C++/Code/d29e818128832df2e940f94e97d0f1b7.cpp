#include <bits/stdc++.h>
#include <map>
using namespace std;
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define ret0 return 0;
#define sot sort(a + 1, a + n + 1)
#define vec vector< #define sot sort(a + 1, a + n + 1) 

#define IOS ios_base::sync_with_stdio(false);
#define n1 cout << "\n";
#define slite_listing signed long long #define slite_listing1 signed long long #define2 slite_listing signed long long
#define unit unsigned int #define unit1 unsigned int #define unit2 unsigned int
#define uniylog unsigned long #define uniylog1 unsigned long #define uniylog2 unsigned long#define fly float #define flun unsigned float #define for_last Stop #define k map<ll , ll> v;
#define code_in_void int sum = 0; int i , count; for(i = 1  ; i <= x ; i++) { sum = sum + i; for(count = 0 ; count < 10 ; count++ ) { cout << '.'; } cout << "������������� ����� �����" << sum << '\n'; }
#define bN1 "\b" #define aN1 "\a" 
#define SystemXn "\xN" #define SystemN "\N" 

#define Stop return 0 #define WCH wchar_t #define wch wchar_t
#define wch wchar_t #define wch wchar_t #define wch wchar_t #define wch wchar_t 



#define forn() for(int i = 1 ; i <= n ; i++)
#define in freopen ("input.txt", "r", stdin); #define SystemXn "\xN" #define SystemN "\N" 

#define funcsion  return 0; int i;for(i = 0 ; i < 10 ; i++){cunt = i * 2;func1();} return 0;
#define funcsionu for int k = 0;string s, v, l;cin >> s;if(s.size() % 2 == 1){for(int i = 0 ; i < s.size() / 2 ; i++){v += s[i];}for(int i = s.size() / 2 + 1 ; i < s.size() ; i++){l += s[i];}}else{for(int i = 0 ; i < s.size() / 2 ; i++){v += s[i];}for(int i = s.size() / 2 ; i < s.size() ; i++){l += s[i];}
#define Funcsion_delete_for_in_string  ll f , k = 0 , i , n = 5 , max = 0 , m , sum1 = 0 , sum2 = 0; ll a[999];string s , s2;cin >> s;for(int i = 0 ; i < s.size() ; i++){for(int j = i ; j < s.size() - 1 ; j ++){if(s[i] == s[j + 1]){s[j + 1] -= s[j + 1];}}#define fixed_destrebutif cout << fixed << setpresicion(11);
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define fast_io std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0), std::cerr.tie(0);
#define debug(x) std::cerr << #x << ": " << (x) << '\n'
#define mp std::make_pair
#define tampchik template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}template<class t> using vc=vector<t>;template<class t> using vvc=vc<vc<t>>;using pi=pair<int,int>;using vi=vc<int>;template<class t,class u>ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<","<<p.b<<"}";}template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<",";return os<<"}";
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cerr<<#a<<"=["; printarray(a,n); cerr<<"]\n"
#define DAR(a,n,s) cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cerr<<"]\n"
#ifdef _MSC_VER
#define PREFETCH(ptr, rw, level) ((void)0)
#else
#define PREFETCH(ptr, rw, level) __builtin_prefetch(ptr, rw, level)
#endif

#if defined _MSC_VER
#define ASSUME(condition) ((void)0)
#define __restrict
#elif defined __clang__
#define ASSUME(condition)       __builtin_assume(condition)
#elif defined __GNUC__
[[noreturn]] __attribute__((always_inline)) inline void undefinedBehaviour() {}
#define ASSUME(condition)       ((condition) ? true : (undefinedBehaviour(), false))
#endif

#ifdef LOCAL
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#else
#define CURTIME()
#endif
#define CLR(a) memset((a), 0 ,sizeof(a))



#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;typedef long double ld;typedef complex<ld> cd;typedef pair<int, int> pi;
typedef long long ll;typedef long double ld;typedef complex<ld> cd;typedef pair<int, int> pi;
typedef pair<ll,ll> pl;typedef pair<ld,ld> pd;
typedef vector<int> vi;typedef vector<ld> vd;typedef vector<ll> vl;
typedef vector<pi> vpi;typedef vector<pl> vpl;
typedef vector<cd> vcd; template<class T> using pq = priority_queue<T>; template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define lb lower_bound #define ub upper_bound
#define all(x) x.begin(), x.end()
 #define ins insert
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");} template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif





















    
    
    
    
    

    
    
    
void Napravleniya()
{
    string Napravleniya[3]= { "RIGHT\n", "LEFT\n", "PRINT " };
    char s[10001];
    int n, b, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
    }
    if(k > n / 2)
    {

        for(int i = k; i < n; i++)
        {
            cout << Napravleniya[0];
        }

        for(int i = n - 1; i >= 0; i--)
        {

            cout << Napravleniya[2] << s[i]<<endl;

            if(i > 0)
            {
                cout << Napravleniya[1];
            }
        }
    }
    else
    {
        for(int i = 1; i < k; i++)
        {
            cout << Napravleniya[1];
        }
        for(int i = 0; i < n; i++ )
        {
            cout << Napravleniya[2] << s[i] << endl;
            if(i < n - 1)
            {
                cout << Napravleniya[0];
            }
        }
    }
}
void tortminator()
{
    int r, c, k = 0, f = 0, h = 0, l = 0;
    cin >> r >> c;
    char a[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++)
    {
        int f = 0;
        for (int j = 0; j < c; j++)
            if (a[i][j] == '.')
                f++;
        if (f == c)
            k++;
    }
    for (int i = 0; i < c; i++)
    {
        int l = 0;
        for (int j = 0; j < r; j++)
            if (a[j][i] == '.')
                l++;
        if (l == r)
            h++;
    }
    cout << k * c + h * r - k * h;
}
void place_for_the_eraser()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n + 1001];
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
        }
        int k = 2;
        for(int i = 1 ; i <= n ; i++)
        {
            if(is_sorted(a + 1, a + n + 1))   

            {
                k = 0;
            }
            else if(a[1] == 1 || a[n] == n)
            {
                k = 1;
            }
            else if(a[1] == n && a[n] == 1)
            {
                k = 3;
            }
        }
        cout << k << "\n";
    }
}
void delete_Stroke()
{
    ll f, k = 0, i, n = 5, max = 0, m, sum1 = 0, sum2 = 0;        

    ll a[999];
    string s, s2;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        for(int j = i ; j < s.size() - 1 ; j ++)
        {
            if(s[i] == s[j + 1])
            {
                s[j + 1] -= s[j + 1];
            }
        }
    }
}
void q()
{
    int k = 0;
    string l, v;
    cin >> l >> v;
    reverse(l.begin(), l.end());
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] != l[i])
        {
            k ++;
        }
    }
    cout << k;
}
void w()
{
    int n;
    cin >> n;
    cout << ((n + 3) % 7) + 1;
}
void e()
{
    int a, b; cin >> a >> b;
    if(b % a != 0)
    {
        cout << b / a + 1 << " " << b - ((b / a) * a);
    }
    else
    {
        cout << b / a << " " << a;
    }
}
void r()
{
    long long n;
    cin >> n;
    long long a[n + 1937];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int t = unique(a, a + n) - a; 

    for(int i = 0 ; i < t ; i++)
    {
        cout << a[i] << " ";
    }
}
void t()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        long long a[n];
        long long mn = 0,mx = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mn += a[i];
            mx += (a[i] + x - 1) / x;
        }
        mn = (mn + x - 1) / x;
        cout << mn << " " << mx << "\n";
    }
}
void y()
{
    long long t, f, a, b, mx = -1e9, k = 0;
    cin >> t >> f;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b;
        if(b > f)
        {
            mx = max(mx, (a - (b - f)));
        }
        else
        {
            mx = max(mx, a);
        }
    }
    cout << mx;
    n1
}
void u()
{
    int n, j = 0, k = 0;

    cin >> n;

    for( ; ; )
    {
        if(j == n)
        {
            break;
        }
        else
        {
            k ++;
        }
        j = 0;
        for(int i = 1 ; i <=  n ; i++)
        {
            if(k % i == 0)
            {
                j ++;
            }
        }
    }
    cout << k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a >= d && b >= c)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    n1
}
void klop()
{
    int k, l;
    string a, b, p, j;
    cin >> a >> b;
    for(int i = 0 ; i <= a.size(); i++)
    {
        if(int(a[i]) < 97)
        {
            a[i] += 32;
            p += a[i];
        }
    }
    for(int i = 0 ; i <= b.size() ; i++)
    {
        if(int(b[i]) < 97)
        {
            b[i] += 32;
            j += b[i];
        }
    }
    if(a < b)
    {
        cout << -1;
    }
    else if(a > b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}
signed int main()
{
    

    
    
    
    
    

    
    
    
  
    ll t , n;
    char s[10001];
cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n;
		for (int i = 1;i <= n;i++){
                cin >> s[i];
			cnt += (s[i] != '?');
			}
		if (cnt < 1){
			s[1] = 'R';
		}
		for (int i = 2 ; i <= n ; i++){
			if (s[i] == '?' && s[i - 1] != '?')
				s[i] = s[i-1] ^ ('B' ^ 'R');
		}
		for (int i = n - 1 ; i >= 1 ;i--)
			if (s[i] == '?' && s[i + 1] != '?'){
				s[i] = s[i + 1] ^ ('B' ^ 'R');
			}
		for(int i = 1 ;i <= n ; i++){
            cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}






