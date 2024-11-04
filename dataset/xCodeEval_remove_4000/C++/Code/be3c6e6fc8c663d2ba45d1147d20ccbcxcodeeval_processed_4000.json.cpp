


 
using namespace std;
 









 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}
 
template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}
 
mt19937 rnd(time(NULL));
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
 
const int N = 300 * 1000 + 13;
const int P = 450;
 
int n, m;
int a[N];
pt q[N];
 
bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x;
	}
	return true;
}
 
vector<li> pr[N];
li ans[N];
 
void solve() {
	fore(dx, 1, P){
		forn(i, dx) pr[i] = vector<li>(1, 0);
		forn(i, n) pr[i % dx].pb(pr[i % dx].back() + a[i]);
		forn(i, m) if (q[i].y == dx) ans[i] = pr[q[i].x % dx].back() - pr[q[i].x % dx][q[i].x / dx];
	}
	forn(i, m){
		if (q[i].y >= P){
			li sum = 0;
			for (int j = q[i].x; j < n; j += q[i].y)
				sum += a[j];
			ans[i] = sum;
		}
		printf("%lld\n", ans[i]);
	}
}
 
int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;
 
	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();

 
	}
}
