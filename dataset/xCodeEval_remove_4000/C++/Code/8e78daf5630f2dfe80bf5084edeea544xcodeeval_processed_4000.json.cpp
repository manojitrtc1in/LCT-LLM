







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







i64 n, x; vi a, b;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> x; a.rsz(n); b.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i] >> b[i];
}

void ProSolve() {
	vector<vi> intercepts(7, vi(7));
	intercepts[1][2] = 4; intercepts[2][1] = 3;
	intercepts[1][3] = 2; intercepts[3][1] = 5;
	intercepts[1][4] = 5; intercepts[4][1] = 2;
	intercepts[1][5] = 3; intercepts[5][1] = 4;
	intercepts[2][3] = 6; intercepts[3][2] = 1;
	intercepts[2][4] = 1; intercepts[4][2] = 6;
	intercepts[2][6] = 3; intercepts[6][2] = 4;
	intercepts[3][5] = 6; intercepts[5][3] = 1;
	intercepts[3][6] = 2; intercepts[6][3] = 5;
	intercepts[4][5] = 1; intercepts[5][4] = 6;
	intercepts[4][6] = 5; intercepts[4][6] = 2;
	intercepts[5][6] = 3; intercepts[6][5] = 4;
	for (i64 i=1; i<n; i++) {
		if (intercepts[a[i]][b[i]] != x && intercepts[a[i]][b[i]] != 7-x) {
			cout << "NO"; return;
		}
	}
	cout << "YES";
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




