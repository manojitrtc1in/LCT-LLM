



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
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

void solve() {
	queue<pt> q;
	set<int> cur;
	forn(i, n) cur.insert(i);
	forn(i, n) if (__gcd(a[i], a[(i + 1) % n]) == 1)
		q.push(mp(i, (i + 1) % n));
	vector<int> ans;
	while (!q.empty()){
		int i = q.front().x;
		int j = q.front().y;
		q.pop();
		if (!cur.count(i) || !cur.count(j)) continue;
		ans.pb(j + 1);
		cur.erase(j);
		if (cur.empty()) break;
		auto it = cur.lower_bound(j);
		if (it == cur.end()) it = cur.begin();
		if (__gcd(a[i], a[*it]) == 1)
			q.push(mp(i, *it));
	}
	printf("%d ", sz(ans));
	for (auto it : ans) printf("%d ", it);
	puts("");
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