



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

int n, q;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &q) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int lst[N], fst[N];
int mx[N], tot[N];

int p[N], rk[N];

int getp(int a){
	return (a == p[a] ? a : p[a] = getp(p[a]));
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	mx[a] = max(mx[a], mx[b]);
	tot[a] += tot[b];
	p[b] = a;
}

void solve() {
	forn(i, n) lst[a[i]] = i;
	for (int i = n - 1; i >= 0; --i) fst[a[i]] = i;
	
	memset(tot, 0, sizeof(tot));
	forn(i, n) ++tot[a[i]];
	forn(i, N) mx[i] = tot[i];
	
	forn(i, N) p[i] = i, rk[i] = 1;
	
	vector<pt> qr;
	forn(i, N) if (tot[i] > 0){
		qr.pb(mp(fst[i], i));
		qr.pb(mp(lst[i] + 1, i));
	}
	sort(all(qr));
	
	int j = 0;
	set<int> cur;
	forn(i, n){
		while (j < sz(qr) && qr[j].x == i){
			int x = qr[j].y;
			if (cur.count(x)) cur.erase(x);
			else cur.insert(x);
			++j;
		}
		if (sz(cur) > 1){
			auto it = cur.begin();
			if (*it == a[i])
				++it;
			unite(a[i], *it);
		}
	}
	
	set<int> pp;
	forn(i, n) pp.insert(getp(a[i]));
	
	int ans = 0;
	for (auto it : pp)
		ans += tot[it] - mx[it];
	
	printf("%d\n", ans);
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