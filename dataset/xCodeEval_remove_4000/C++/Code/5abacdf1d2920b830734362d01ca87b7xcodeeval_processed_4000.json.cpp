
 



 
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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
 
const int N = 1000 + 7;
const int M = 100 * 1000 + 13;
const int P = 2000;
 
struct query{
	int t, x1, y1, x2, y2;
	li val;
};
 
int n, m;
query q[M];
 
bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d%d%d%d", &q[i].t, &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
		--q[i].x1, --q[i].y1, --q[i].x2, --q[i].y2;
		if (q[i].t == 2) scanf("%lld", &q[i].val);
	}
	return true;
}
 
li pr[N][N];
li sv[N][N];
li a[N][N];
 
void rebuild(){
	forn(i, n) forn(j, n){
		sv[i + 1][j] ^= sv[i][j];
		sv[i][j + 1] ^= sv[i][j];
		sv[i + 1][j + 1] ^= sv[i][j];
		a[i][j] ^= sv[i][j];
	}
	forn(i, n) forn(j, n){
		pr[i + 1][j + 1] = pr[i + 1][j] ^ pr[i][j + 1] ^ pr[i][j] ^ a[i][j];
	}
	memset(sv, 0, sizeof(sv));
}
 
void solve(){
	vector<int> qs;
	forn(i, m){
		if (i % P == 0){
			rebuild();
			qs.clear();
		}
		if (q[i].t == 2){
			sv[q[i].x1][q[i].y1] ^= q[i].val;
			sv[q[i].x2 + 1][q[i].y1] ^= q[i].val;
			sv[q[i].x1][q[i].y2 + 1] ^= q[i].val;
			sv[q[i].x2 + 1][q[i].y2 + 1] ^= q[i].val;
			qs.pb(i);
		}
		else{
			li tmp = pr[q[i].x2 + 1][q[i].y2 + 1] ^ pr[q[i].x2 + 1][q[i].y1] ^ pr[q[i].x1][q[i].y2 + 1] ^ pr[q[i].x1][q[i].y1];
			for (int j : qs){
				int sq = max(0, min(q[i].x2, q[j].x2) - max(q[i].x1, q[j].x1) + 1) * max(0, min(q[i].y2, q[j].y2) - max(q[i].y1, q[j].y1) + 1);
				if (sq & 1) tmp ^= q[j].val;
			}
			printf("%lld\n", tmp);
		}
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