



#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


#define ok order_of_key
#define fbo find_by_order 
#define ll long long 
#define ld long double
#define ull unsigned long long
#define vc vector
#define vll vector<ll> 
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define sz(x) (ll)x.size()


#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define fill(a,b) memset(a, b, sizeof(a))
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";

#define rep(i,j,n) for(ll i=j;i<n;i++)
#define Rep(i,j,n) for(ll i=n-1;i>=j;i--)
const ld pi  = 3.141592653589793238462;




const ll inf = 1e18;



#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(bool t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

ll mul(ll a , ll b , ll m){ ll res = (a%m*b%m)%m; if(res<0) {res+=m;} return res;}
ll ceil(ll a,ll b){ if(a%b==0) {return a/b;} else {return a/b +1;} }
ll power(ll a,ll b) { ll res=1; while(b>0) { if(b&1) { res=res*a; b--; } else { a=a*a; b/=2; } } return res; }
ll mod_power(ll a , ll b , ll m){ ll res = 1; while (b > 0) { if (b & 1) {res = mul(res,a,m);} a = mul(a , a , m); b >>= 1;} return res%m; }
ll isprime(ll n) { ll flag=1; for ( ll i = 2; i <= sqrt(n); i++) { if (n % i == 0) { flag = 0; break; } } if (n <= 1) { flag = 0; } return flag; }
ll sumofdigits(ll a) { ll S=0; while(a>0) { ll t=a%10; S+=t; a/=10; } return S; }
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll highestpower(ll n) { ll temp=1; for(ll i=1;1;i++) { temp=1<<i; if(temp>n) { return temp; } } } 

ll isperfectsquare(ll x) { ll y=sqrt(x); return y*y==x; }
ll stoint(string s) { stringstream geek(s); ll x = 0; geek >> x; return x; }
ll fact(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) { res = res * i; } return res; }
ll nCr(ll n, ll r) { return fact(n) / (fact(r) * fact(n - r)); }
ll countDigit(ll n) { ll count = 0; while (n != 0) { n = n / 10; ++count; } return count; }
ll ispalindrom(string s) { ll t=0; ll l=sz(s); rep(i,0,l) { if(s[i]!=s[l-i-1]) t=1; } if(t) { return 0; } return 1; }
ll reversdigits(ll num) { ll rev_num = 0; while (num > 0) { rev_num = rev_num * 10 + num % 10; num = num / 10; } return rev_num; }
void pop_front(vector<ll> &v) { if (v.size() > 0) { v.erase(v.begin()); } }

















        












 
































































































































































































 


















 


















































































































































































































































































    
























































































































































































































































ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}












ll d(ll n)
{
    return n*(n-1)/2;
}



ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

void solve()
{
    ll count=0,res=0,cnt=0,count0=0,count1=0,flag=0,flag1=0,zero=0,odd=0,even=0,sum=0,ans=0,ans2=0,ans1=0,pos=0,neg=0;
    
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n)cin>>a[i];

    ll i=0,j=0,k=1;
      while(j<n)
      {
        while(i<n && k>a[j]){
          i++;
          k--;
        }

        ans+=(j-i+1);
        j++;
        k++;
      }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    


    

    

    

    

    

    

    

    


    


    

    

    

    


    cout<<ans<<endl;



} 
    

    


    

    


    

    

    

    

 
    

    

    

    












 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    ll t=1;
    cin>>t;

    

    

    while(t--)
    {
        solve();
    }

    

    return 0;
}



