



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

int n, k;

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	return true;
}

li ask(int x){
	printf("? %d\n", x + 1);
	fflush(stdout);
	li res;
	scanf("%lld", &res);
	return res;
}

void solve() {
	int l = -1, r = -1;
	int cnt = 0;
	while (l == -1 && r == -1){
		int x = rnd() % n;
		li res = ask(x);
		++cnt;
		if (res < k)
			l = x;
		if (res > k)
			r = x;
	}
	int res = -1;
	if (l == -1)
		l = r - cnt;
	else
		r = l + cnt;
	if (l < 0)
		l += n, r += n;
	while (l <= r){
		int m = (l + r) / 2;
		if (ask(m % n) <= k){
			res = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	printf("! %d\n", res % n + 1);
	fflush(stdout);
}

int main() {





	
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