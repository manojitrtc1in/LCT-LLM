









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










const int N = 3e5+7;
int n,m,k;
int arrival[2][N], departure[2][N];
vector<pair<int, int> > g[N];
void dijkstra(int source, int destination,int f)
{
	for(int i=1;i<=n;i++)
	{
		arrival[f][i]=inf;
		departure[f][i]=inf;
	}
	arrival[f][source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		departure[f][x.second]=arrival[f][x.second];
		for(auto it:g[x.second])
		{
			if(arrival[f][it.first] > departure[f][x.second] + it.second)
			{
				s.erase({arrival[f][it.first], it.first});
				arrival[f][it.first]=departure[f][x.second] + it.second;
				s.insert({arrival[f][it.first], it.first});
			}
		}
	}
}

int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    
    cin>>n>>m>>k;
    vector<int>arr(k);
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       g[a].pb(mp(b,1));
       g[b].pb(mp(a,1));
    }

    dijkstra(1,n,0);
    dijkstra(n,1,1);
    vector<pair<int,int>>v;
    for(int i=0;i<k;i++){
    	v.pb(mp(arrival[0][arr[i]]-arrival[1][arr[i]],(arr[i])));
    }
    sort(all(v));
    debug(v);
    int best  =0 ;
    int maxi = -inf;
    for(auto x:v){
    	int node = x.second;
    	best = max(best,maxi+arrival[1][node]);
    	maxi = max(maxi,arrival[0][node]);
    }
    cout<<min(arrival[0][n],best+1);
    return 0;
}



