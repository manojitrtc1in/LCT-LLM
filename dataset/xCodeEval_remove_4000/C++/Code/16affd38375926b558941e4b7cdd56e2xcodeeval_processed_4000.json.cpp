







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







i64 n, k; vector<pii> a;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> k; a.rsz(n);
	for (i64 i=0; i<n; i++) {cin >> a[i].fi; a[i].se = i+1;}
}

void ProSolve() {
	sort(a.begin(), a.end(), greater<pii>());
	i64 tmp = 0; vi res;
	for (i64 i=0; i<n; i++) {
		if (tmp + a[i].fi >= k) {
			cout << i+1 << endl;
			return;
		}
		tmp += a[i].fi; res.pub(a[i].se);
	}
	cout << n << endl;
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




