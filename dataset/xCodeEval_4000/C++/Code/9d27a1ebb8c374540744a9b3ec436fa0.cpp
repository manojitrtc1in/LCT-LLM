
#define COPYRIGHT "© : JAYPAL MUDALIYAR \n"







#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define f(i,a,b) for(int i=a;i<b;i++)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define fd(i,a,b) for(int i=a-1;i>=b;i--)
#define fdll(i,a,b) for(long long i=a-1;i>=b;i--)
#define ll long long
#define ld long double
#define LLMAX LLONG_MAX
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long,long long>>
#define vstr vector<string>
#define all(k) k.begin(),k.end()
#define rall(k) k.rbegin(),k.rend()
#define stll set <long long,greater<long long>>
#define Mi map <int,int>
#define Mll map <long long,long long>
#define dbg(x) cout << "---> [" << (x) << "] "
#define dbg2(x,y) cout << "---> {[" << (x) << "],",cout << "[" << (y) << "]} "
#define kill(x) { cout << (x) << "\n"; return; }
#define here() cout << "UPTO HERE" << endl;
#define printvec(v) for(auto x : v)  { cout << x << " "; } cout << "\n";
#define print3(x,y,z) cout << (x) << " " << (y) << " " << (z) << "\n"; 
#define tup(i,v) get<i>(v)
#define mt make_tuple
#define MOD 1000000007
#define nl cout << "\n"
#define printPair(x) cout << x.F << " " << x.S << "\n";
#define speed ios :: sync_with_stdio(0); cin.tie(0); cout.tie(nullptr);
#define inout(input,output) freopen(input,"r",stdin); freopen(output,"w",stdout);

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

string decToBinary(ll );
int numofBits(ll x) { if(x==0) { return 0; } return floor(log2(x))+1;}
template <typename T>  ll lcm(T a,T b) {return (ll)(a/__gcd(a,b))*b;}
unsigned long long leastSetBitpos(ll n) {return log2(n & -n) + 1;}
template <typename T> T mostSignificantBit(T n) {n|=n>>1,n|=n>>2,n|=n>>4,n|=n>>8,n|=n>>16,++n;return (n>>1);}
template<typename T> T gcd(T a,T b) {if(a==0 || b==0) return (a>0?b:a); return __gcd(a,b);}
template <typename T> bool isprime(T n) {if(n<=1) return false; for(ll i=2;(i*i)<=n;i++) if(n%i==0) return false; return true;}
bool ispalin(string s) {ll j=s.size()-1,i=0; while(i<j) if(s[i++]!=s[j--]) return false; return true;}
template <typename T> T getmod(T x,T mod) {return ((x+mod)%mod);}

bool sortsec(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.S < b.S);}
bool spsort(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
    

    if(a.F != b.F) return (a.F > b.F); 
    return (a.S < b.S);
    

}

void getprime(int );

template<typename T>
using ord_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<class key,class value,class cmp=less<key>>
using ord_map=tree<key,value,cmp,rb_tree_tag,tree_order_statistics_node_update>;






ll binpw(ll x,ll n,ll mod) {
    ll ans=1;x=x%mod;
    if(!x) return 0LL;
    for (;n>0;n/=2LL,x=(x*x)%mod) if(n%2) ans=(ans*x)%mod;
    return ans;
}

template<typename T>
struct SparseTable {
    int n,lg;
    vector<int> logs;
    vector<vector<T>> sptable;
    

    

    SparseTable(const int maxn) {
        n=maxn;
        lg=log2(n+5);
        sptable=vector<vector<T>> (n+5,vector<T> (lg+5));
        logs=vector<int> (n+5);
        logs[0]=-1; 

        logs[1]=0;
        for(int i=2;i<=n;i++) logs[i]=logs[i/2]+1;
    }
    

    

    SparseTable(const int sz,const vector<T>& arr) {
        n=sz;
        lg=log2(n+5);
        sptable=vector<vector<T>> (n+5,vector<T> (lg+5));
        logs=vector<int> (n+5);
        logs[0]=-1; 

        logs[1]=0;
        for(int i=2;i<=n;i++) logs[i]=logs[i/2]+1;
        build(arr);
    }
    SparseTable(const int sz,const T arr[]) {
        n=sz;
        lg=log2(n+5);
        sptable=vector<vector<T>> (n+5,vector<T> (lg+5));
        logs=vector<int> (n+5);
        logs[0]=-1; 

        logs[1]=0;
        for(int i=2;i<=n;i++) logs[i]=logs[i/2]+1;
        build(arr);
    }
    T merge(const T& value1,const T& value2) {
        T ans;
        

        

        

        ans=__gcd(value1,value2);
        return ans;
    }
    

    void rebuild(const int sz,const vector<T>& arr) {
        n=sz;
        lg=log2(n+5);
        build(arr);
    }
    void rebuild(const int sz,const T arr[]) {
        n=sz;
        lg=log2(n+5);
        build(arr);
    }
    

    void build(const vector<T>& arr) {
        for(int j=0;j<=lg;j++) {
            int x=1<<j;
            for(int i=0;(i+x)<=n;i++) {
                if(j==0) sptable[i][j]=arr[i];
                else sptable[i][j]=merge(sptable[i][j-1],sptable[i+(x/2)][j-1]);
            }
        }
    }
    void build(const T arr[]) {
        for(int j=0;j<=lg;j++) {
            int x=1<<j;
            for(int i=0;(i+x)<=n;i++) {
                if(j==0) sptable[i][j]=arr[i];
                else sptable[i][j]=merge(sptable[i][j-1],sptable[i+(x/2)][j-1]);
            }
        }
    }
    

    

    T query(int l,int r) {
        

        

        

        

        T ans=0;
        for(int j=logs[r-l+1];j>-1;j--) {
            int x=1<<j;
            if((r-l+1)&x) {
                ans=merge(ans,sptable[l][j]);
                l+=x;
            }
        }
        return ans;
    }
    

    

    

    T Idempotent_query(int l,int r) {
        int j=logs[r-l+1],x=1<<j;
        T ans=merge(sptable[l][j],sptable[r-(x)+1][j]);
        return ans;
    }
    

    

};

SparseTable<ll> SP((int)2e5+5);

const long double PI = acos(-1);
const int max_bits=32; 

const int primel=1e6+50; 



bool *prime;




void AJM()
{
    int n;cin >> n;
    vll a(n);f(i,0,n) cin >> a[i];
    if(n==1) kill(1)
    if(n==2) {
        if(abs(a[0]-a[1])>1) kill(2)
        else kill(1)
    }
    vll df(n-1);
    f(i,1,n) df[i-1]=abs(a[i]-a[i-1]);
    SP.rebuild((int)df.size(),df);
    auto poss=[&](int val)->bool {
        int i=0,j=val-1;
        while(j<n) {
            ll g=SP.Idempotent_query(i,j-1);
            if(g!=1) return true;
            i++,j++;
        }
        return false;
    };
    int start=2,end=n;
    int ans=1;
    while(start<=end) {
        int mid=(start+end)/2;
        if(poss(mid)) ans=max(ans,mid),start=mid+1;
        else end=mid-1;
    }
    cout << ans << "\n";
    return;
}




bool GOOGLE = 0;
bool txtinp = 1;
bool TC = 1;









int main()
{
    if(txtinp) {
        #ifndef ONLINE_JUDGE
            inout("1input.txt","1output.txt");
        #endif
    }
    speed
    ll t=1;
    if(TC) cin >> t;
    

    ll tc=1;
    while(t--) {
        if(GOOGLE) cout << "Case #" << tc << ": "; 
        ++tc; 
        AJM();
    }
    return 0;
}

void getprime(int prm)
{
    int a=prm;
    prime=new bool[prm]{0};
    prime[0]=prime[1]=false;
    f(i,2,a) prime[i]=true;
    for(ll p=2;(p*p)<=a;p++)
    {
        if (prime[p] == true) 
        {
            for(ll i=(p*p);i<=a;i+=p)
                prime[i] = false;
        }
    }
}
string decToBinary(ll n) {bitset<max_bits> b(n);  return b.to_string();}
















