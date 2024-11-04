







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







i64 n, q, l, r; vi tree;
vector<vi> a, ans, mx;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; a.rsz(n); ans.rsz(n, vi(n, 0)); a[0].rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[0][i];
}

void ProSolve() {
	for (i64 i=1; i<n; i++) {
		a[i].rsz(a[i-1].size()-1);
		for (i64 j=0; j<a[i].size(); j++) a[i][j] = a[i-1][j] ^ a[i-1][j+1];
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=i; j<n; j++) {
			ans[i][j] = a[j-i][i];
		}
	}
	

	mx.rsz(n, vi(n, 0));
	vector<vi> id0(n, vi(n, 0));
	for (i64 j=n-1; j>=0; j--) {
		for (i64 i=j; i>=0; i--) {
			

			if (i < n-1) id0[j][i] = max(id0[j][i+1], ans[i][j]);
			else id0[j][i] = ans[i][j];
		}
	}
	

	

	for (i64 i=0; i<n; i++) {
		for (i64 j=i; j<n; j++) {
			if (i == j) mx[i][j] = id0[j][i];
			else mx[i][j] = max(id0[j][i], mx[i][j-1]);
		}
	}
	

	

	cin >> q; while (q--) {
		cin >> l >> r; l--; r--;
		cout << mx[l][r] << endl;
	}
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




