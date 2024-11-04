







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







i64 n, a, b; vi x, id0, vx, vy;
map<i64, i64> Map1; map<pip, i64> Map2;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> a >> b; x.rsz(n); id0.rsz(n); vx.rsz(n); vy.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> x[i] >> vx[i] >> vy[i];
		id0[i] = a * vx[i] - vy[i];
		Map1[id0[i]]++; Map2[mp(id0[i], mp(vx[i], vy[i]))]++;
	}
}

void ProSolve() {
	i64 ans = 0;
	for (i64 i=0; i<n; i++) {
		ans += Map1[id0[i]];
		ans -= Map2[mp(id0[i], mp(vx[i], vy[i]))];
	}
	cout << ans;
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




