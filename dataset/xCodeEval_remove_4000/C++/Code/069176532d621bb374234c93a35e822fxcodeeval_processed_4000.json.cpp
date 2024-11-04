









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
    int n,d,k;
    cin>>n>>d>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    sort(all(arr));
    vector<int>small;
    vector<int>big;
    for(int i=0;i<n;i++){
    	if(arr[i]>k){
    		big.pb(arr[i]);
    	}
    	else{
    		small.pb(arr[i]);
    	}
    }
    sort(big.rbegin(),big.rend());
    sort(small.rbegin(),small.rend());
    for(int i=1;i<(int)big.size();i++){
    	big[i]+=big[i-1];
    }
    for(int i=1;i<(int)small.size();i++){
    	small[i]+=small[i-1];
    }
    int ans = 0;
    if((int)big.size()==0){
    	ans = small[n-1];
    	cout<<ans<<endl;
    	return 0;
    }
    for(int i=1;i<=(int)big.size();i++){
       int res =0 ;
       int day = (i-1)*(d+1) + 1;
       res+=big[i-1];
       int ss = n - (day);
       debug(i,ss,res);
       if(ss==0){
       	ans = max(ans,res);
       }
       if(ss>0 && small.size()==0){
       	ans = max(ans,res);
       }
       if(ss<=0||small.size()==0){

       	 continue;
       }
       ans = max(ans,res);
       res+=small[min((int)small.size() -1 , ss - 1 )];
        debug(res,i);
       ans = max(ans,res);
    }

    cout<<ans<<endl;

    


  return 0;


}



