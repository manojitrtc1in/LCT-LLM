







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







i64 n, k; vs verd;





void VarInput() {
	

	cin >> n >> k; verd.rsz(n-k+1);
	for (i64 i=0; i<n-k+1; i++) cin >> verd[i];
}

void ProSolve() {
	vs ans(n, "Akiaa");
	for (i64 j=1; j<n; j++) {
		ans[j] = ans[j-1];
		if (ans[j][4] == 'z') {
			ans[j][3]++; ans[j][4] = 'a';
		}
		else ans[j][4]++;
	}
	for (i64 i=0; i<n-k+1; i++) {
		if (verd[i] == "NO") continue;
		for (i64 j=i+1; j<i+k; j++) {
			ans[j] = ans[j-1];
			if (ans[j][4] == 'z') {
				ans[j][3]++; ans[j][4] = 'a';
			}
			else ans[j][4]++;
		}
	}
	vector<vb> match(n, vb(n, true));
	for (i64 i=0; i<n-k+1; i++) {
		if (verd[i] == "NO") continue;
		for (i64 x=i; x<i+k; x++) {
			for (i64 y=x+1; y<i+k; y++) {
				match[x][y] = false;
			}
		}
	}
	for (i64 i=0; i<n-k+1; i++) {
		if (verd[i] == "YES") continue;
		bool matched = false;
		for (i64 x=i; x<i+k; x++) {
			for (i64 y=x+1; y<i+k; y++) {
				if (!match[x][y]) continue;
				ans[y] = ans[x]; matched = true; break;
			}
			if (matched) break;
		}
	}
	for (i64 i=0; i<n; i++) cout << ans[i] << " ";
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




