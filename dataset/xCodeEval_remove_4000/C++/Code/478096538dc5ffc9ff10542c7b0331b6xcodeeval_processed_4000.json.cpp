



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

int m, n;
pt s, f;
pt a[N];

bool read () {
	if (scanf("%d%d", &m, &n) != 2)
		return false;
	scanf("%d%d", &s.x, &s.y);
	scanf("%d%d", &f.x, &f.y);
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	a[n++] = s;
	return true;
}

vector<pair<pt, int>> ox, oy;
li d[N];

void solve() {
	ox.clear();
	oy.clear();
	forn(i, n){
		ox.pb(mp(a[i], i));
		oy.pb(mp(mp(a[i].y, a[i].x), i));
	}
	sort(all(ox));
	sort(all(oy));
	forn(i, n) d[i] = INF64;
	d[n - 1] = 0;
	set<pair<li, int>> q;
	q.insert(mp(d[n - 1], n - 1));
	while (!q.empty()){
		int i = q.begin()->y;
		q.erase(q.begin());
		{
			int pos = lower_bound(all(ox), mp(a[i], i)) - ox.begin();
			if (pos > 0){
				int j = ox[pos - 1].y;
				if (d[j] > d[i] + abs(a[i].x - a[j].x)){
					if (!q.count(mp(d[j], j)))
						q.erase(mp(d[j], j));
					d[j] = d[i] + abs(a[i].x - a[j].x);
					q.insert(mp(d[j], j));
				}
			}
			if (pos + 1 < n){
				int j = ox[pos + 1].y;
				if (d[j] > d[i] + abs(a[i].x - a[j].x)){
					if (!q.count(mp(d[j], j)))
						q.erase(mp(d[j], j));
					d[j] = d[i] + abs(a[i].x - a[j].x);
					q.insert(mp(d[j], j));
				}
			}
		}
		{
			int pos = lower_bound(all(oy), mp(mp(a[i].y, a[i].x), i)) - oy.begin();
			if (pos > 0){
				int j = oy[pos - 1].y;
				if (d[j] > d[i] + abs(a[i].y - a[j].y)){
					if (!q.count(mp(d[j], j)))
						q.erase(mp(d[j], j));
					d[j] = d[i] + abs(a[i].y - a[j].y);
					q.insert(mp(d[j], j));
				}
			}
			if (pos + 1 < n){
				int j = oy[pos + 1].y;
				if (d[j] > d[i] + abs(a[i].y - a[j].y)){
					if (!q.count(mp(d[j], j)))
						q.erase(mp(d[j], j));
					d[j] = d[i] + abs(a[i].y - a[j].y);
					q.insert(mp(d[j], j));
				}
			}
		}
	}
	
	li ans = INF64;
	forn(i, n) ans = min(ans, d[i] + abs(f.x - a[i].x) + abs(f.y - a[i].y));
	printf("%lld\n", ans);
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