



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

const int N = 5000 + 7;

int n, k;
int a[N];
int m;
int q[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m)
		scanf("%d", &q[i]);
	return true;
}

void solve() {
	sort(a, a + n);
	forn(z, m){
		int ans = INF;
		forn(i, n) fore(j, 1, k + 1){
			int lft = q[z] - a[i] * j;
			if (lft == 0)
				ans = min(ans, j);
			else if (lft < 0)
				break;
			fore(nj, 1, k - j + 1){
				if (lft % nj != 0)
					continue;
				int val = lft / nj;
				if (binary_search(a, a + n, val))
					ans = min(ans, j + nj);
			}
		}
		printf("%d\n", ans == INF ? -1 : ans);
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