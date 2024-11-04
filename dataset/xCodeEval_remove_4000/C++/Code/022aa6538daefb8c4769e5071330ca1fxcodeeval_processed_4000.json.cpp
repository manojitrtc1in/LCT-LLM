









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








string s;
int n,k;
const int mxn = 1e6+5;
int dp[mxn][2];
int solve(int ind,int face){
	if(ind>=n){
		return 0;
	}
    int res = inf;
	int cost = 0;
    for(int i=ind+1;i<min(n,(ind+k));i++){
           if(s[i]=='1'){
           	 cost++;
           }
    }
    if(ind+k<n){
        if((int)(s[ind+k]-'0')==0){
           	 cost++;
        }
    }
    res = min(res,cost + solve(ind+k,1));
    debug(ind,face,res);
    return res;
}
int pre[mxn];
int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int t;
    cin>>t;

    for(int i1=1;i1<=t;i1++)
    {
    	cin>>n>>k;
    	cin>>s;
    	int c = 0;
        for(int i=0;i<n;i++){
           c+= s[i]-'0';
        }
        int ans = inf;
     	for(int i=0;i<k;i++){
          int d = 0;
          int co = 0;
          for(int j=i;j<n;j+=k){
             if(s[j]-'0')d++;
             else{
             	d = max(d-1,0);
             }
             co =  max(co,d);
          }
          ans= min(ans,c-co);
    	}

    	cout<<ans<<endl;
    }


  return 0;


}



