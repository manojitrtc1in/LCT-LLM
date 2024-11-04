







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
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));


template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 n, m; vector<vi> a;
vb rexist, id0;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; a.rsz(n, vi(m));
	rexist.rsz(n, false); id0.rsz(m, false);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> a[i][j]; if (!a[i][j]) continue;
			rexist[i] = true; id0[j] = true;
		}
	}
}

void ProSolve() {
	i64 ans = 4;
	if (rexist[0] || rexist[n-1] || id0[0] || id0[m-1]) {
		cout << "2"; return;
	}
	cout << ans;
}


int main() {
			
			

			

			
	VarInput();
			
			auto TIME1 = chrono::steady_clock::now();
			
	ProSolve();
			
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.\n";
			
	return 0;
}




