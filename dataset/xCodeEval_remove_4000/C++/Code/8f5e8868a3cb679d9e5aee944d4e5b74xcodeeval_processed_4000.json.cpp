






using namespace std;




























const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;
typedef vector<pii> vp;




template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

















i64 n, ans = 0; vi a;
vi cc(5001, 0), sum(5001, 0);





void VarInput() {
	

	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
	for (i64 i=0; i<n; i++) {
		for (i64 j=i+1; j<n; j++) {
			cc[abs(a[i]-a[j])]++;
		}
	}
	sum[0] = cc[0]; for (i64 i=1; i<5001; i++) sum[i] = sum[i-1] + cc[i];
}

void ProSolve() {
	

	for (i64 i=0; i<5001; i++) {
		if (cc[i] == 0) continue;
		for (i64 j=0; j<5001; j++) {
			if (cc[j] == 0) continue;
			if (i + j > 5000) continue;
			

			ans += cc[i] * cc[j] * (sum[5000] - sum[i+j]);
			

		}
	}
	dout(15, (ld)ans/sum[5000]/sum[5000]/sum[5000]);
}


int main() {
	

	

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	

	ProSolve(); 

	return 0;
}




