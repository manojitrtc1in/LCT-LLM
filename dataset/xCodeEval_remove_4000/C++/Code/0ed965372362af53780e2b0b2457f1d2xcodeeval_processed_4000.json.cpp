





























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





int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    

    vt<vt<vt<vt<int>>>>vis(N, vt<vt<vt<int>>>(M, vt<vt<int>>(4, vt<int>(3))));
    string s[N];
    int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};


    int sx, sy, tx, ty;

    for(int i=0; i<N; ++i){
        cin >> s[i];
        for(int j=0; j<M; ++j){
            if(s[i][j]=='S') sx=i, sy=j;
            if(s[i][j]=='T')tx=i, ty=j;
        }
    }
    function<void(int, int, int, int)>dfs=[&](int x, int y, int d, int sum){
        vis[x][y][d][sum]=1;
        

        for(int i=0; i<4; ++i){
            int x1=dx[i]+x, y1=dy[i]+y, sum1=(d==i)?sum:sum+1;
            if(x1<0||y1<0||x1>=N||y1>=M||s[x1][y1]=='*'||sum1>2||vis[x1][y1][i][sum1])continue;
            dfs(x1, y1, i, sum1);
        }
    };

    for(int i=0; i<4; ++i)
        dfs(sx, sy, i, 0);

    bool ok=false;
    for(int i=0; i<4; ++i)
        for(int j=0; j<=2; ++j)
            if(vis[tx][ty][i][j])ok=true;

    if(ok) cout << "YES" << ends;
    else cout << "NO" << ends;
}

