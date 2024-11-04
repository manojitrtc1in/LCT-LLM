#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define inf 10000000000000
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}




void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



vector<int> printDivisors(int n)
{
    vector<int>v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.pb(i);
            else
                v.pb(i),v.pb(n/i);
        }
    }
    return v;
}

int cnt[15000002];
int pr[15000002];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int32_t main()
{

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif

    fastio;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    int g = arr[0];
    for(int i=1;i<n;i++){
    	g=gcd(g,arr[i]);
    }
    
    for(int i=0;i<n;i++){
    	arr[i]/=g;
    	cnt[arr[i]]++;
    }
    int ans  = 1e9;
    for(int i=2;i<15000001;i++){
    	if(!pr[i]){
    		int c = 0;
    		for(int j=i;j<15000001;j+=i){
    			c+=cnt[j];
    			pr[j] = 1;
    		}
    		ans = min(ans,n-c);
    	}
    }
    if(ans==n)cout<<-1<<endl;
    else  cout<<ans<<endl;
   
    





  return 0;


}



