









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








int arr[1000003];
int n,k;
int dp[1024][1024];
int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    cin>>n>>k;
    int s = 0;
    bool ok=false;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    if(n>k){
    	int s =0 ;
        map<int,int>p;
        for(int i=0;i<n;i++){
            s+=arr[i];

            p[s%k]++;
        }
        bool ok=false;
        for(auto x:p){
        	if(x.second>1){
        		ok=true;
        		break;
        	}
        }
        if(ok){
        	cout<<"YES\n";
        }
        else{
        	cout<<"NO\n";
        }
    }
    else{
    	  for(int i=0;i<n;i++){
    	  	arr[i] = arr[i]%k;
    	  }
    	  for(int i=0;i<=n;i++){
    	  	for(int j=0;j<=k;j++){
    	  		dp[i][j] =0 ;
    	  	}
    	  }
    	  for(int i=0;i<=n;i++){
    	  	   dp[i][0] = 1;
    	  }	                                                          	
    	  for(int i=1;i<=n;i++){
    	  	for(int j=0;j<=k;j++){   	  		
    	  			
    	  			dp[i][j] = (dp[ i-1 ][ (j+arr[i-1])%k ]) || (dp[i-1][j]);
    	  			debug(dp[i][j]);
    	  	}
    	  }

    	  if(dp[n][k]){
    	  	cout<<"YES\n";
    	  	
    	  }
    	  else{
    	  	cout<<"NO\n";
    	  }
    }
  return 0;
    }






