






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

















i64 a, b, c, d;





void VarInput() {
	

	cin >> a >> b >> c >> d;
}

void ProSolve() {
	

	ld p = (ld)a / b, q = (ld)(1 - (ld)c / d) * (1 - (ld)a / b);
	

	cout << fixed << setprecision(15) << p / (1 - q);
}


int main() {
	

	

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	

	ProSolve(); 

	return 0;
}




