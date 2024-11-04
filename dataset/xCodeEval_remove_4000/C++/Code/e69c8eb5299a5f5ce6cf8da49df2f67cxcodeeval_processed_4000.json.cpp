



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

struct man{
	int t, s, f, i;
	man(){}
};

int n, m;
man a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		scanf("%d%d%d", &a[i].t, &a[i].s, &a[i].f);
		--a[i].s, --a[i].f;
		a[i].i = i;
	}
	return true;
}

vector<int> wt[N], fn[N];

int f[N];

void upd(int x, int val){
	for (int i = x; i < N; i |= i + 1)
		f[i] += val;
}

int get(int x){
	int sum = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		sum += f[i];
	return sum;
}

li ans[N];

void solve() {
	sort(a, a + n, [](const man &a, const man &b){
		return a.t < b.t;
	});
	
	forn(i, m){
		wt[i].clear();
		fn[i].clear();
	}
	
	memset(f, 0, sizeof(f));
	
	int cur = 0;
	int tot = 0;
	
	li tim = 0;
	
	int fin = 0;
	int j = 0;
	while (true){
		while (j < n && a[j].t == tim){
			wt[a[j].s].pb(j);
			upd(a[j].s, 1);
			++tot;
			++j;
		}
		
		while (!wt[cur].empty()){
			int x = wt[cur].back();
			wt[cur].pop_back();
			fn[a[x].f].pb(x);
			upd(cur, -1);
			upd(a[x].f, 1);
		}
		
		while (!fn[cur].empty()){
			int x = fn[cur].back();
			fn[cur].pop_back();
			upd(cur, -1);
			ans[a[x].i] = tim;
			--tot;
			++fin;
		}
		
		if (fin == n)
			break;
		
		if (tot == 0){
			tim = a[j].t;
			continue;
		}
		
		int pdown = get(cur - 1);
		int pup = tot - pdown;
		int dx = (pup >= pdown ? 1 : -1);
		
		int l = 0, r = INF;
		if (dx == 1) r = min(r, m - 1 - cur);
		else r = min(r, cur);
		if (j < n) r = min(li(r), a[j].t - tim);
		
		int ncur = cur;
		while (l <= r){
			int m = (l + r) / 2;
			int cnt;
			if (dx == 1) cnt = get(cur + dx * m - 1) - pdown;
			else cnt = pdown - get(cur + dx * m);
			if (cnt == 0){
				ncur = cur + dx * m;
				l = m + 1;
			}
			else{
				r = m - 1;
			}
		}
		
		tim += abs(ncur - cur);
		cur = ncur;
	}
	
	forn(i, n) printf("%lld\n", ans[i]);
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