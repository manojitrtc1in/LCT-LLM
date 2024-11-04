



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

const int N = 100 * 1000 + 13;

int n, m;
pair<int, pt> a[N];
li q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d%d", &a[i].x, &a[i].y.x);
		if (a[i].x == 2) scanf("%d", &a[i].y.y);
	}
	scanf("%d", &m);
	forn(i, m){
		scanf("%lld", &q[i]);
	}
	return true;
}

void solve() {
	vector<int> pr;
	vector<li> lens;
	lens.pb(0);
	forn(i, n){
		if (a[i].x == 1){
			if (sz(pr) < N)
				pr.pb(a[i].y.x);
			lens.pb(lens.back() + 1);
		}
		else{
			forn(t, a[i].y.y) for (int j = 0; j < a[i].y.x && sz(pr) < N; ++j)
				pr.pb(pr[j]);
			lens.pb(lens.back() + a[i].y.x * a[i].y.y);
		}
	}
	forn(i, m){
		auto it = lower_bound(all(lens), q[i]);
		assert(it != lens.end() && it != lens.begin());
		int x = it - lens.begin() - 1;
		if (a[x].x == 1) printf("%d ", a[x].y.x);
		else printf("%d ", pr[(q[i] - lens[x] - 1) % a[x].y.x]);
	}
	puts("");
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