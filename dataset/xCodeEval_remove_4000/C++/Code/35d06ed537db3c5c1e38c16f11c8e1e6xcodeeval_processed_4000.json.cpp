



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

const int N = 200 * 1000 + 13;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

li d[N];

void solve() {
	memset(d, 0, sizeof(d));
	fore(i, 1, n){
		int lst = 1;
		for (int k = 1; k * k <= i; ++k){
			int v = (i - 1) / k;
			d[k] += (a[i] < a[v]);
			d[k + 1] -= (a[i] < a[v]);
			lst = k;
		}
		for (int v = 0;; ++v){
			int l = (i - 1) / (v + 1) + 1;
			int r = (v == 0 ? n : (i - 1) / v + 1);
			bool fl = false;
			if (l <= lst)
				fl = true, l = lst + 1;
			if (l >= r) break;
			d[l] += (a[i] < a[v]);
			d[r] -= (a[i] < a[v]);
			if (fl) break;
		}
	}
	forn(i, n) d[i + 1] += d[i];
	
	fore(i, 1, n)
		printf("%lld ", d[i]);
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