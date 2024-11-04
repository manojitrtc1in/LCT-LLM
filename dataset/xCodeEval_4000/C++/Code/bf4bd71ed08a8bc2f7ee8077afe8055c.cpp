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






int32_t main()
{

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif

    fastio;
    int t;
    cin>>t;

    while(t--)
    { 
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
        int ans[n];
        int c = n;
        for(int i=0;i<n;i++){
        	ans[i] = c--;
        }
        vector<pair<int,int>>v;
        for(int i=0;i<n-1;i++){
           if(s[i]=='<'){
           	  int l  =i;
           	  int r = i+1;
           	  for(int j =i;j<n;j++){
           	  	 if(s[j]=='<'){
                    r = j+1;
           	  	 }
           	  	 else{
           	  	 	break;
           	  	 }
           	  }
           	  v.pb(mp(l,r));
           	  i = r - 1;
           }
        }
        for(auto x:v){
        	int l = x.first;
        	int r = x.second;
        	vector<int>p;
        	for(int i=l;i<=r;i++){
               p.pb(ans[i]);
        	}
        	reverse(all(p));
        	int ind = 0;
        	for(int i=l;i<=r;i++){
               ans[i] = p[ind++];
        	}
        }
        for(int i=0;i<n;i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
        c = 1;
        v.clear();
        for(int i=0;i<n;i++){
        	ans[i] = c++;
        }
        for(int i=0;i<n-1;i++){
        	if(s[i]=='>'){
        		int l = i;
        		int r = i+1;
        		for(int j=i;j<n;j++){
        			if(s[j]=='>'){
                       r = j+1;
        			}
        			else{
        				break;
        			}
        		}
        		v.pb(mp(l,r));
        		i = r-1;
        	}
        }
        for(auto x:v){
        	int l = x.first;
        	int r = x.second;
        	vector<int>p;
        	for(int i=l;i<=r;i++){
               p.pb(ans[i]);
        	}
        	reverse(all(p));
        	int ind = 0;
        	for(int i=l;i<=r;i++){
               ans[i] = p[ind++];
        	}
        }
        for(int i=0;i<n;i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
    }


  return 0;


}



