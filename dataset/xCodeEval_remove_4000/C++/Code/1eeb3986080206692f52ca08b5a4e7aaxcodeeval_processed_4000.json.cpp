



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

const li INF = int(2e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

int n, m;

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	return true;
}

bool check(int x){
	li lft = m * li(x);
	li cnt = 0;
	vector<li> pr(1, 1);
	for (int i = 0; i <= x; ++i){
		li C;
		if (i < sz(pr) || x - i < sz(pr))
			C = pr[min(i, x - i)];
		else
			C = INF;
		li t = min(C, (i == 0 ? INF : lft / i));
		lft -= t * i;
		if (cnt + t >= n)
			return true;
		if (t == 0)
			return false;
		cnt += t;
		if (i < sz(pr) && C * li(x - i) / (i + 1) <= INF)
			pr.pb(C * (x - i) / (i + 1));
	}
	return false;
}

void solve() {
	int l = 0, r = n - 1;
	int res = -1;
	while (l <= r){
		int m = (l + r) / 2;
		if (check(m)){
			r = m - 1;
			res = m;
		}
		else{
			l = m + 1;
		}
	}
	printf("%d\n", res);
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