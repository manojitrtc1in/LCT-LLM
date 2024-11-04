



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
int a[N];

bool read () {
	if (scanf("%d%d", &m, &n) != 2)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

vector<int> pos[N];

void solve() {
	forn(i, m) pos[i].clear();
	forn(i, n) pos[a[i]].pb(i);
	
	li sum = 0;
	forn(i, n - 1)
		sum += abs(a[i] - a[i + 1]);
	
	li ans = INF64;
	forn(i, m){
		vector<int> cur;
		li tmp = sum;
		for (auto it : pos[i]){
			if (it > 0 && a[it - 1] != a[it]){
				cur.pb(a[it - 1]);
				tmp -= abs(a[it] - a[it - 1]);
			}
			if (it + 1 < n && a[it + 1] != a[it]){
				cur.pb(a[it + 1]);
				tmp -= abs(a[it] - a[it + 1]);
			}
		}
		if (cur.empty()){
			ans = min(ans, sum);
			continue;
		}
		sort(all(cur));
		int x = cur[sz(cur) / 2];
		for (auto it : pos[i]){
			if (it > 0 && a[it - 1] != a[it])
				tmp += abs(x - a[it - 1]);
			if (it + 1 < n && a[it + 1] != a[it])
				tmp += abs(x - a[it + 1]);
		}
		ans = min(ans, tmp);
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

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}