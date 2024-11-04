













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


template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 n; vi p, cnt, ans, level;
vector<vi> Adj; vb vis;


void DFS(i64 z) {
	vis[z] = true;
	for (i64 i=0; i<Adj[z].size(); i++) {
		if (!vis[Adj[z][i]]) {
			level[Adj[z][i]] = level[z] + 1;
			DFS(Adj[z][i]);
		}
	}
}


void VarInput() {
	

	cin >> n; p.resize(n+1); cnt.resize(n+1, 0);
	Adj.resize(n+1, vi(0)); level.resize(n+1, 0);
	for (i64 i=1; i<=n; i++) {
		cin >> p[i];
		if (p[i] == 0) continue;
		Adj[i].pub(p[i]); Adj[p[i]].pub(i);
		cnt[i]++; cnt[p[i]]++;
		cnt[i] %= 2; cnt[p[i]] %= 2;
	}
}

void ProSolve() {
	set<pip> Set; vis.resize(n+1, false); DFS(1);
	for (i64 i=1; i<=n; i++) Set.insert(mp(cnt[i], mp(-level[i], i)));
	while (!Set.empty()) {
		i64 par = Set.begin()->first, q = Set.begin()->second.second;
		

		if (par == 1) {cout << "NO"; return;}
		Set.erase(Set.begin()); ans.pub(q);
		

		for (i64 i=0; i<Adj[q].size(); i++) {
			pip x = mp(cnt[Adj[q][i]], mp(-level[Adj[q][i]], Adj[q][i]));
			

			if (Set.find(x) == Set.end()) continue;
			Set.erase(Set.find(x)); x.fi++; x.fi %= 2;
			cnt[x.se.se]++; cnt[x.se.se] %= 2;
			

			Set.insert(x);
		}
	}
	cout << "YES\n";
	for (i64 i=0; i<ans.size(); i++) cout << ans[i] << endl;
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