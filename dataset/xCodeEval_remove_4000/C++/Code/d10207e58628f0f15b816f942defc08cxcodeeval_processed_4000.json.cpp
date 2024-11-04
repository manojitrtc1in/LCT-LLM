



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

const int N = 4000 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, 2 * n){
		ld x;
		scanf("%Lf", &x);
		a[i] = round(x * 1000);
		a[i] %= 1000;
	}
	return true;
}

int b[N];

void solve() {
	forn(i, 2 * n) b[i] = -(1000 - a[i]) % 1000 - a[i];
	int sum = accumulate(a, a + 2 * n, 0);
	int cnt1 = count(b, b + 2 * n, -1000);
	int cnt0 = count(b, b + 2 * n, 0);
	

	int ans = INF;
	if (cnt0 >= n){
		ans = min(ans, abs(sum));
		ans = min(ans, abs(sum - 1000 * cnt1));
	}
	if (cnt1 >= n){
		ans = min(ans, abs(sum - 1000 * n));
		ans = min(ans, abs(sum - 1000 * (n - cnt0)));
	}
	if (cnt1 >= min(n, sum / 1000) && cnt0 >= n - min(n, sum / 1000)){
		ans = min(ans, abs(sum - 1000 * min(n, sum / 1000)));
	}
	if (cnt1 >= min(n, (sum + 999) / 1000) && cnt0 >= n - min(n, (sum + 999) / 1000)){
		ans = min(ans, abs(sum - 1000 * min(n, (sum + 999) / 1000)));
	}
	printf("%.3Lf\n", ld(ans) / 1000);
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