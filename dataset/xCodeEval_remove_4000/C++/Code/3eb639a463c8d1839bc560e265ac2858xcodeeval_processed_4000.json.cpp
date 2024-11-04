



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

int n;
pair<pt, pt> a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i].x.x);
		if (a[i].x.x == 1){
			scanf("%d%d", &a[i].x.y, &a[i].y.x);
		}
		else if (a[i].x.x == 2){
			scanf("%d", &a[i].x.y);
		}
		else if (a[i].x.x == 3){
			scanf("%d%d%d", &a[i].x.y, &a[i].y.x, &a[i].y.y);
		}
	}
	return true;
}

vector<int> vals;

struct node{
	int s;
	li sum, minsum;
	node(){};
	node(int s, int len) : s(s), sum(s * li(len)), minsum(s < 0 ? s * li(len) : 0) {};
};

node t[4 * N];

node merge(node a, node b){
	node c(0, 0);
	c.sum = a.sum + b.sum;
	c.minsum = min(a.minsum, a.sum + b.minsum);
	return c;
}

void build(int v, int l, int r){
	if (l == r - 1){
		if (l == 0)
			t[v] = node(0, INF + 1);
		else
			t[v] = node(0, 0);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, pt val){
	if (l == r - 1){
		t[v] = node(val.x, val.y);
		

		return;
	}
	int m = (l + r) / 2;
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int val[N];
int len[N];

ld ask(int v, int l, int r, int L, int R, li &x){
	

	if (L >= R)
		return 2 * INF;
	if (l == L && r == R){
		if (t[v].minsum + x > 0){
			x += t[v].sum;
			

			return 2 * INF;
		}
		

		while (l < r - 1){
			int m = (l + r) / 2;
			

			if (t[v * 2].minsum + x <= 0){
				r = m;
				v = v * 2;
			}
			else{
				x += t[v * 2].sum;
				l = m;
				v = v * 2 + 1;
			}
		}
		if (x == 0)
			return vals[l];
		

		assert(t[v].minsum + x <= 0);
		assert(t[v].s < 0);
		ld res = vals[l] + (x / ld(-t[v].s));
		x = 0;
		return res;
	}
	int m = (l + r) / 2;
	ld tmp = ask(v * 2, l, m, L, min(m, R), x);
	if (x == 0) return tmp;
	assert(x > 0);
	return ask(v * 2 + 1, m, r, max(m, L), R, x);
}

void solve() {
	vals.clear();
	forn(i, n) if (a[i].x.x == 1)
		vals.pb(a[i].x.y);
	vals.pb(0);
	vals.pb(INF + 1);
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	set<int> cur;
	build(1, 0, sz(vals));
	
	val[0] = 0;
	len[0] = INF + 1;
	
	cur.insert(0);
	cur.insert(sz(vals) - 1);
	
	forn(i, n){
		if (a[i].x.x == 1){
			int pos = lower_bound(all(vals), a[i].x.y) - vals.begin();
			auto pos2 = cur.lower_bound(pos);
			val[pos] = a[i].y.x; 
			--pos2;
			len[*pos2] = vals[pos] - vals[*pos2];
			upd(1, 0, sz(vals), *pos2, mp(val[*pos2], len[*pos2]));
			++pos2;
			len[pos] = vals[*pos2] - vals[pos];
			upd(1, 0, sz(vals), pos, mp(val[pos], len[pos]));
			cur.insert(pos);
		}
		else if (a[i].x.x == 2){
			int pos = lower_bound(all(vals), a[i].x.y) - vals.begin();
			auto pos2 = cur.lower_bound(pos);
			val[*pos2] = len[*pos2] = 0;
			upd(1, 0, sz(vals), *pos2, mp(val[*pos2], len[*pos2]));
			pos2 = cur.erase(pos2);
			int l = vals[*pos2];
			--pos2;
			l -= vals[*pos2];
			len[*pos2] = l;
			upd(1, 0, sz(vals), *pos2, mp(val[*pos2], len[*pos2]));
		}
		else{
			int l = lower_bound(all(vals), a[i].x.y) - vals.begin();
			auto lit = cur.lower_bound(l);
			int r = a[i].y.x;
			li x = a[i].y.y;
			if (x == 0){
				printf("%.15Lf\n", ld(a[i].x.y));
				continue;
			}
			

			ld res = ask(1, 0, sz(vals), *lit, sz(vals), x);
			if (x == 0 && res < r + EPS)
				printf("%.15Lf\n", res);
			else
				puts("-1");
			

		}
	}
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