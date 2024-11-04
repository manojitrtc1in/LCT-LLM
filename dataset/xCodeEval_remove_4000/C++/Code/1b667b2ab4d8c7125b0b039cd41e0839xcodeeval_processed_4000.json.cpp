



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

const int N = 100 * 1000 + 13;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

void solve() {
	map<int, int> cnt;
	map<pt, int> cnt2;
	li ans = 0;
	forn(i, n){
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
		if (a[i].x == a[i].y){
			ans += cnt[a[i].x];
			ans -= cnt2[a[i]];
		}
		else{
			ans += cnt[a[i].x];
			ans += cnt[a[i].y];
			ans -= cnt2[mp(a[i].x, a[i].x)];
			ans -= cnt2[mp(a[i].y, a[i].y)];
			ans -= cnt2[a[i]];
		}
		++cnt[a[i].x];
		++cnt[a[i].y];
		++cnt2[a[i]];
	}
	printf("%lld\n", ans);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}