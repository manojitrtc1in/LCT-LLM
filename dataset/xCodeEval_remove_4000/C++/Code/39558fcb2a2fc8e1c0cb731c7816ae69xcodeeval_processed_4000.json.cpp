






using namespace std;




























const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;
typedef vector<pii> vp;




template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

















i64 n; vi dp, p; vd st;
vvi adj;


void countChildren(i64 z) {
	for (i64 i=0; i<adj[z].size(); i++) {
		countChildren(adj[z][i]);
	}
	if (z != 1) dp[p[z]] += dp[z];
}

void DFS(i64 z) {
	for (i64 i=0; i<adj[z].size(); i++) {
		st[adj[z][i]] = st[z] + 1 + (ld)(dp[z] - 1 - dp[adj[z][i]]) / 2 ;
		DFS(adj[z][i]);
	}
}


void VarInput() {
	

	cin >> n; p.resize(n+1, -1); adj.resize(n+1, vi(0));
	dp.resize(n+1, 1); st.resize(n+1, 1.0);
	for (i64 i=2; i<=n; i++) {
		cin >> p[i]; adj[p[i]].pub(i);
	}
}

void ProSolve() {
	

	countChildren(1);
	DFS(1);
	for (i64 i=1; i<=n; i++) dout(15, st[i]);
}


int main() {
	

	

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	

	ProSolve(); 

	return 0;
}




