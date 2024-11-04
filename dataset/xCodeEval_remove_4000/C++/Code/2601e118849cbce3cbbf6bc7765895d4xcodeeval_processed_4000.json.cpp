



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
const int LOGN = 17;
const int SM = 87;
const int P = 450;

int n, m;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m)
		scanf("%d%d", &q[i].x, &q[i].y);
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		return a;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int lst[N];

void sieve(){
	iota(lst, lst + N, 0);
	fore(i, 2, N){
		if (lst[i] != i) continue;
		for (int j = i; j < N; j += i)
			lst[j] = min(lst[j], i);
	}
}

int num[N];
int pws[N][20];

struct node{
	node *l, *r;
	int val;
	node() : l(NULL), r(NULL), val(1) {}
	node(int x) : l(NULL), r(NULL), val(x) {}
};

typedef node* tnode;

vector<pt> f[N];

void upd(int x, int t, int val){
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		f[i].pb(mp(t, mul(f[i].back().y, val)));
}

int get(int x, int t){
	int res = 1;
	for (int i = x; i < N; i |= i + 1)
		res = mul(res, (--lower_bound(all(f[i]), mp(t, 2 * INF)))->y);
	return res;
}

vector<pair<int, pt>> st[N];

void solve() {
	sieve();
	int cnt = 0;
	fore(i, 2, N) if (lst[i] == i){
		num[i] = cnt;
		pws[cnt][0] = 1;
		fore(j, 1, 20) pws[cnt][j] = mul(pws[cnt][j - 1], i);
		++cnt;
	}
	
	forn(i, cnt) st[i].clear();
	forn(i, N) f[i] = vector<pt>(1, mp(-1, 1));
	forn(i, n){
		while (a[i] > 1){
			int x = lst[a[i]];
			int cnt = 0;
			while (a[i] % x == 0){
				++cnt;
				a[i] /= x;
			}
			x = num[x];
			while (!st[x].empty() && st[x].back().y.x < cnt){
				upd(st[x].back().x, i, binpow(st[x].back().y.y, MOD - 2));
				st[x].pop_back();
			}
			if (!st[x].empty()){
				upd(st[x].back().x, i, mul(binpow(st[x].back().y.y, MOD - 2), pws[x][st[x].back().y.x - cnt]));
				st[x].back().y.y = pws[x][st[x].back().y.x - cnt];
			}
			upd(i, i, pws[x][cnt]);
			st[x].pb(mp(i, mp(cnt, pws[x][cnt])));
		}
	}
	
	int ans = 0;
	forn(i, m){
		int l = (ans + q[i].x) % n;
		int r = (ans + q[i].y) % n;
		if (l > r) swap(l, r);
		ans = get(l, r);
		printf("%d\n", ans);
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