









using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int id0(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
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










int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int t;
    cin>>t;

    while(t--)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	vector<int>v[n*(n+2)];
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
              v[arr[i]*n + arr[j]].pb(i);
    		}
    	}
    	int ans = 0;
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			auto &it = v[(arr[i]*n) +arr[j]];
    			if(it.size()==0){
    				continue;
    			}
    			else{
    				auto tem = upper_bound(all(it),j);
    				if(tem!=it.end())ans+= it.end()-tem;
    			}
    		}
    	}
    	cout<<ans<<endl;
    	

    }


  return 0;


}



