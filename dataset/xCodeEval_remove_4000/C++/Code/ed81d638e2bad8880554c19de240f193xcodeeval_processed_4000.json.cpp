





























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





int N, M;
vector<string>s(1000);
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

void dfs(int x, int y, int d, int sum, vt<vt<vt<vt<bool>>>>& vis){
    vis[x][y][d][sum]=true;
    

    for(int i=0; i<4; ++i){
        int x1=dx[i]+x, y1=dy[i]+y, sum1=(d==i)?sum:sum+1;
        if(x1<0||y1<0||x1>=N||y1>=M||s[x1][y1]=='*'||sum1>2||vis[x1][y1][i][sum1])continue;
        dfs(x1, y1, i, sum1, vis);
    }

}
void a(vector<int>& f){
    f[0]=1;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    

    vt<vt<vt<vt<bool>>>>vis(N, vt<vt<vt<bool>>>(M, vt<vt<bool>>(4, vt<bool>(3))));

    int sx, sy, tx, ty;

    for(int i=0; i<N; ++i){
        cin >> s[i];
        for(int j=0; j<M; ++j){
            if(s[i][j]=='S') sx=i, sy=j;
            if(s[i][j]=='T')tx=i, ty=j;
        }
    }
    for(int i=0; i<4; ++i)
        dfs(sx, sy, i, 0, vis);

    bool ok=false;
    for(int i=0; i<4; ++i)
        for(int j=0; j<=2; ++j)
            if(vis[tx][ty][i][j])ok=true;

    if(ok) cout << "YES" << ends;
    else cout << "NO" << ends;
}

