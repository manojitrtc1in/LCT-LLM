









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









struct node
{
	 int inside;
	 int outside;
	 int con;
};
int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int n;
    cin>>n;
    vector<node>v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i].inside;
    	cin>>v[i].outside;
    	cin>>v[i].con;
    }
    vector<int>ans;
    int vis[n];
    memset(vis,0,sizeof(vis));

    for(int i=0;i<n;i++){
        if(vis[i]==1){
    		continue;
    	}
    	ans.pb(i+1);
        int x = v[i].inside;
        int y = 0;
        int p = 0;
        bool ok = false;
        int ind = n;
        for(int j=i+1;j<n;j++){
        	if(vis[j]==1){
        		continue;
            }
        	v[j].con-= max(0,x-p);
        	if(v[j].con<0){
        		ind = min(j+1,ind);
        		y = v[ind-1].outside;
        		vis[ind-1] = 1;
        	}
        	p++;
        }
        for(int j=ind;j<n;j++){
        	if(vis[j]){
        		continue;
        	}
        	v[j].con = v[j].con - y;
        	if(v[j].con<0){
        		vis[j]  = 1;
        		y+=v[j].outside;
        	}
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;


}



