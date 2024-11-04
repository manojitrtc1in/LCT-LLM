



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

int n, m, s;
pt a[N];
pair<pt, int> b[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &s) != 3)
		return false;
	forn(i, m){
		scanf("%d", &a[i].x);
		a[i].y = i;
	}
	forn(i, n)
		scanf("%d", &b[i].x.x);
	forn(i, n){
		scanf("%d", &b[i].x.y);
		b[i].y = i;
	}
	return true;
}

int ans[N];

set<pt> lft, cur;

bool check(int k){
	lft.clear();
	cur.clear();
	forn(i, m) lft.insert(a[i]);
	li tot = 0;
	int j = 0;
	while (!lft.empty()){
		while (j < n && b[j].x.x >= lft.rbegin()->x){
			cur.insert(mp(b[j].x.y, b[j].y));
			++j;
		}
		if (cur.empty()){
			return false;
		}
		tot += cur.begin()->x;
		for (int t = 0; t < k && !lft.empty(); ++t){
			ans[lft.rbegin()->y] = cur.begin()->y;
			lft.erase(--lft.end());
		}
		cur.erase(cur.begin());
	}
	return tot <= s;
}

void solve() {
	sort(a, a + m, greater<pt>());
	sort(b, b + n, greater<pair<pt, int>>());
	int res = INF;
	int l = 1, r = m;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)){
			r = mid - 1;
			res = mid;
		}
		else{
			l = mid + 1;
		}
	}
	

	if (res == INF)
		puts("NO");
	else{
		puts("YES");
		check(res);
		forn(i, m)
			printf("%d ", ans[i] + 1);
		puts("");
	}
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