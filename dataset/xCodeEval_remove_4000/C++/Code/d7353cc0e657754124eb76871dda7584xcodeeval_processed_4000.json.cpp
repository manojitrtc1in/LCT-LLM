







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







i64 n; vi p; vs f, s;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; p.rsz(n); f.rsz(n); s = f;
	for (i64 i=0; i<n; i++) cin >> f[i] >> s[i];
	for (i64 i=0; i<n; i++) {cin >> p[i]; p[i]--;}
}

void ProSolve() {
	if (n == 1) {cout << "YES"; return;}
	vi id0(n, 0); vs ff = f, ss = s;
	for (i64 i=0; i<n; i++) {ff[i] = f[p[i]]; ss[i] = s[p[i]];}
	f = ff; s = ss;
	if ((f[0] < f[1] && s[0] < s[1]) || (f[0] < s[1] && s[0] < f[1])) id0[1] = 0;
	else if (f[0] < f[1] || s[0] < f[1]) id0[1] = 1;
	else if (f[0] < s[1] || s[0] < s[1]) id0[1] = 2;
	else {cout << "NO"; return;}
	for (i64 i=1; i<n; i++) {
		if (id0[i-1] == 1) {
			if (f[i-1] > s[i] && f[i-1] > f[i]) {
				cout << "NO"; return;
			}
			else if (f[i-1] < f[i] && f[i-1] < s[i]) id0[i] = 0;
			else if (f[i-1] < f[i]) id0[i] = 1; else id0[i] = 2;
		}
		else if (id0[i-1] == 2) {
			if (s[i-1] > s[i] && s[i-1] > f[i]) {
				cout << "NO"; return;
			}
			else if (s[i-1] < f[i] && s[i-1] < s[i]) id0[i] = 0;
			else if (s[i-1] < f[i]) id0[i] = 1; else id0[i] = 2;
		}
		else {
			if ((f[i-1] < f[i] && s[i-1] < s[i]) || (f[i-1] < s[i] && s[i-1] < f[i])) id0[i] = 0;
			else if (f[i-1] < f[i] || s[i-1] < f[i]) id0[i] = 1;
			else if (f[i-1] < s[i] || s[i-1] < s[i]) id0[i] = 2;
			else {cout << "NO"; return;}
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




