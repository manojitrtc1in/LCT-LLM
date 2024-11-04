





























using namespace std;












const long long MOD=1e9+7;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}


const int mxN=100;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<pair<int, int>> adj[N];
    vt<vt<vt<int>>> dp(N, vt<vt<int>>(N, vt<int>(27, -1)));
    for(int i=0; i<M; ++i){
        int X, Y; char C; cin >> X >> Y >> C, --X, --Y;
        adj[X].pb({Y, C-'a'});
    }
    function<int(int, int, int)>dfs=[&](int i, int j, int e){
        

        if(dp[i][j][e]!=-1)return dp[i][j][e];
        dp[i][j][e]=0;
        for(auto u:adj[i])
            if(u.se>=e)dp[i][j][e]|=(!dfs(j, u.fi, u.se));
        return dp[i][j][e];
    };

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(dfs(i, j, 0))cout << "A";
            else cout << "B";
        }
        cout << ends;
    }

}
