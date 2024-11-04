







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







string s; vi cc(10, 0); i64 n;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s; n = s.size();
}

void ProSolve() {
	cc[1]--; cc[6]--; cc[8]--; cc[9]--;
	for (i64 i=0; i<n; i++) cc[s[i]-'0']++;
	i64 modulo = 0;
	for (i64 i=1; i<10; i++) {
		for (i64 j=0; j<cc[i]; j++) {
			cout << i; modulo *= 10;
			modulo += i; modulo %= 7;
		}
	}
	modulo = (modulo * 10000) % 7;
	if (modulo == 0) cout << "1869";
	else if (modulo == 1) cout << "1896";
	else if (modulo == 2) cout << "8916";
	else if (modulo == 3) cout << "1698";
	else if (modulo == 4) cout << "6198";
	else if (modulo == 5) cout << "1689";
	else if (modulo == 6) cout << "6189";
	for (i64 i=0; i<cc[0]; i++) cout << "0";
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




