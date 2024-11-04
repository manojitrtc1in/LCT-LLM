







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







i64 n; vi a;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; a.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i];
		i64 tmp = abs(a[i]);
		for (i64 x=2; x<=sqrt(tmp); x++) {
			if (tmp % x != 0) continue;
			i64 cnt = 0;
			while (tmp % x == 0) {
				cnt++; tmp /= x; a[i] /= x;
			}
			if (cnt % 2 == 1) a[i] *= x;
		}
	}
}

void ProSolve() {
	vi ans(n+1, 0); vb perfectSquare(n, false), negPS(n, false);
	for (i64 i=0; i<n; i++) {
		if (a[i] < 0) {
			i64 tmp = sqrt(abs(a[i]));
			if (tmp * tmp == abs(a[i])) negPS[i] = true;
			continue;
		}
		i64 tmp = sqrt(a[i]); if (tmp * tmp == a[i]) perfectSquare[i] = true;
	}
	unordered_map<i64, i64> M; vi Map(n, 0), Map2(n, 0);
	for (i64 i=0; i<n; i++) {
		if (negPS[i] || perfectSquare[i]) continue;
		if (M.find(a[i]) == M.end()) {M[a[i]] = i; Map[i] = i;}
		else Map[i] = M[a[i]];
	}
	for (i64 x=1; x<=n; x++) {
		for (i64 z=0; z<n; z++) Map2[z] = 0;
		i64 id0 = 0, negps = 0, siz = 0, zero = 0;
		for (i64 j=0; j<x; j++) {
			if (a[j] == 0) {zero++; continue;}
			else if (perfectSquare[j]) {id0++; continue;}
			else if (negPS[j]) {negps++; continue;}
			Map2[Map[j]]++; if (Map2[Map[j]] == 1) siz++;
		}
		ans[siz+(id0 != 0)+(negps != 0)+(zero != 0 && id0 == 0 && negps == 0 && siz == 0)]++;
		

		

		for (i64 j=x; j<n; j++) {
			if (a[j-x] == 0) zero--;
			else if (perfectSquare[j-x]) id0--;
			else if (negPS[j-x]) negps--;
			else {Map2[Map[j-x]]--; if (Map2[Map[j-x]] == 0) siz--;}
			if (a[j] == 0) zero++;
			else if (perfectSquare[j]) id0++; 
			else if (negPS[j]) negps++; else {Map2[Map[j]]++; if (Map2[Map[j]] == 1) siz++;}
			ans[siz+(id0 != 0)+(negps != 0)+(zero != 0 && id0 == 0 && negps == 0 && siz == 0)]++;
			

			

		}
	}
	for (i64 i=1; i<=n; i++) cout << ans[i] << " ";
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




