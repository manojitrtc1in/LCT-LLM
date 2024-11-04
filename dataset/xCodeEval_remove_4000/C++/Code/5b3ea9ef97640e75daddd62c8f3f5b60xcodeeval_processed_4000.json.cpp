



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

const int N = 200 * 1000 + 13;

int n, x;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &x) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

void solve() {
	vector<pt> sv;
	forn(i, n){
		int cnt = 0;
		while (a[i] % x == 0){
			++cnt;
			a[i] /= x;
		}
		sv.pb(mp(a[i], cnt));
	}
	sort(all(sv));
	int ans = 0;
	forn(i, n){
		int j = i - 1;
		multiset<int> cur;
		while (j + 1 < n && sv[j + 1].x == sv[i].x){
			++j;
			cur.insert(sv[j].y);
		}
		while (!cur.empty()){
			int x = *cur.begin();
			cur.erase(cur.begin());
			if (cur.find(x + 1) != cur.end())
				cur.erase(cur.find(x + 1));
			else
				++ans;
		}
		i = j;
	}
	printf("%d\n", ans);
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