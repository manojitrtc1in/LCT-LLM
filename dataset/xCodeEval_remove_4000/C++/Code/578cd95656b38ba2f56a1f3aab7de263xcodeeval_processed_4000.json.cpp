







using namespace std;










const long long MOD = 1000000007LL, INF = 2e9, LINF = 4e18;
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







i64 n, k; vi a; vector<pii> nonOne;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> k; a.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i]; if (a[i] == 1) continue;
		nonOne.pub(mp(a[i], i));
	}
}

void ProSolve() {
	i64 N = nonOne.size();
	i64 ans = 0;
	for (i64 i=0; i<N; i++) {
		i64 p = 1, s = 0;
		for (i64 j=i; j<=min(N-1, i+64); j++) {
			if (LINF / p < nonOne[j].fi) break;
			p *= nonOne[j].fi; s += nonOne[j].fi;
			if (j > i) s += (nonOne[j].se - nonOne[j-1].se - 1);
			if (p % k != 0) continue;
			i64 leftOne = 0, rightOne = 0;
			if (i > 0) leftOne = (nonOne[i].se - nonOne[i-1].se - 1);
			else if (nonOne[i].se > 0) leftOne = nonOne[i].se;
			if (j < N-1) rightOne = (nonOne[j+1].se - nonOne[j].se - 1);
			else if (nonOne[j].se < n-1) rightOne = (n-1 - nonOne[j].se);
			i64 id0 = p / k, required = id0 - s;
			if (s > id0 || (s + leftOne + rightOne) < id0) continue;
			

			ans += (required + 1);
			ans -= max(0LL, required - leftOne - 1 + 1); ans -= max(0LL, required - rightOne - 1 + 1);
			ans += max(0LL, required - leftOne - 1 - rightOne - 1 + 1);
			

		}
	}
	if (k == 1) ans += (n - N);
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



