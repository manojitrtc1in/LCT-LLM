


#include<bits/stdc++.h>
using namespace std;

#define google(tc) cout<<"Case #"<<tc++<<": ";
#define FILE freopen("input.txt","r",stdin); freopen("output.txt","w", stdout);
#define GetSetBolt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define ll long long int  
#define LD long double

#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#endif



#define max3(a,b,c) max(a,max(b,c)) 
#define min3(a,b,c) min(a,min(b,c)) 
#define FF first 
#define SS second 
#define PB push_back 
#define PF push_front 
#define PPB pop_back  
#define PPF pop_front  
#define Endl endl

#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define in2(arr,n,m) for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cin>>arr[i][j];}
#define dis(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
#define dis2(arr,n,m) for(int ii=0;ii<n;ii++){for(int j=0;j<m;j++)cout<<arr[ii][j]<<" ";cout<<endl;} 
#define tc int t=0;cin>>t; while(t--) 

#define For(n) for(ll i=0;i<n;i++)
#define For0(x,z) for(ll x=0;x<z;x++)
#define Forx(x,z) for(x;x<z;x++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

#define toLower(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define toUpperr(s) transform(s.begin(),s.end(),s.begin(),::toupper)

#define sortAD(arr,n) sort(arr,arr+n, greater<int>());
#define sortVD(v) sort(v.begin(), v.end(), greater<int>());
#define sortA(arr) sort(arr,arr+n);
#define sortV(v) sort(v.begin(),v.end());

#define mem0(X) memset((X), 0, sizeof((X)))
#define memx(X,x)  memset((X), x, sizeof((X)))
#define setbits(X)  __builtin_popcountll(X)
#define precise(X)  cout<<fixed << setprecision(X);
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define timer(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))







typedef pair<int, int> PII; 
typedef pair<ll, ll> PLL;
typedef pair<double,double> PDD;
typedef pair<string, string> PSS; 
typedef pair<string, ll> PSL; 
typedef long double lld;

typedef vector<int> VI;  
typedef vector<ll> VL;  
typedef vector<double> VD;
typedef vector<string> VS; 
typedef vector<VI> VVI;  
typedef vector<VL> VVL; 
typedef vector<VS> VVS; 
typedef vector<PII> VPII; 
typedef vector<PLL> VPLL; 
typedef vector<PSS> VPSS; 
typedef vector<PSL> VPSL; 

typedef map<int,int> MII; 
typedef map<ll,ll> MLL;   
typedef map<char,ll> MCL;  
typedef map<char,int> MCI; 
typedef map<char,ll> MCL;   
typedef map<string,string> MSS;  
typedef map<string,int> MSI;  
typedef map<string,ll> MSL; 

typedef unordered_map<int,int> UMII; 
typedef unordered_map<ll,ll> UMLL;   
typedef unordered_map<char,ll> UMCL;  
typedef unordered_map<char,int> UMCI; 
typedef unordered_map<char,ll> UMCL;   
typedef unordered_map<string,string> UMSS;  
typedef unordered_map<string,int> UMSI;  
typedef unordered_map<string,ll> UMSL; 
typedef unsigned long long ull;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
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

ll lcm(ll a, ll b) 
{ return (a * (b / __gcd(a, b))); }

string intToString(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}
 
ll stringToInt(string a)
{
    char x[100];
    ll res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

string to_binary(ll n)
{
    int bin[100];
     int i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    string s="";
    for(int j=i-1;j>=0;j--)
        s+=to_string(bin[j]);
    return s;
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errorf.txt" , "w" , stderr) ;
    #endif
    
     tc
     {
        

        ll n;
        cin >> n;
        ll arr[n];
        for(int i=0;i<n;i++)
        
        {
            cin >> arr[i];
        }
        int res = arr[0];
        for(int i=0;i<n;i++)
        {
            res|= arr[i];
        }
        cout << res << "\n";

      }
    return 0;
}

