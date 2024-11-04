







using namespace std;










const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
vi HashMod = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};


template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 n, ans = 0; vi List; vector<vi> adj; vi init, goal;


void DFS(i64 z, i64 last, i64 evenCnt, i64 oddCnt, i64 rank) {
	

	

	if (rank % 2 == 0 && evenCnt) init[z] = (1 - init[z]);
	if (rank % 2 == 1 && oddCnt) init[z] = (1 - init[z]);
	if (init[z] != goal[z]) {
		init[z] = goal[z]; ans++; List.pub(z+1);
		

		if (rank % 2 == 0) evenCnt++; else oddCnt++;
		evenCnt %= 2; oddCnt %= 2;
	}
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z, evenCnt, oddCnt, rank+1);
	}
}


void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; adj.rsz(n); init.rsz(n); goal.rsz(n);
	for (i64 i=1; i<n; i++) {
		i64 u, v; cin >> u >> v; u--; v--;
		adj[u].pub(v); adj[v].pub(u);
	}
	for (i64 i=0; i<n; i++) cin >> init[i];
	for (i64 i=0; i<n; i++) cin >> goal[i];
}

void ProSolve() {
	DFS(0, -1, 0, 0, 0); cout << ans << endl;
	sort(List.begin(), List.end());
	for (i64 i=0; i<ans; i++) cout << List[i] << endl;
}


int main() {
			
			

			

			
	VarInput();
			
			auto TIME1 = chrono::steady_clock::now();
			
	ProSolve();
			
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			
	return 0;
}




