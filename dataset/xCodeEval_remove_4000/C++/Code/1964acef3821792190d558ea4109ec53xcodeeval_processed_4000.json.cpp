



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

struct query{
	int i;
	li l, r;
	int ans;
};

int h, m;
query q[N];

bool read () {
	if (scanf("%d%d", &h, &m) != 2)
		return false;
	forn(i, m)
		scanf("%d%lld%lld%d", &q[i].i, &q[i].l, &q[i].r, &q[i].ans);
	return true;
}

struct node{
	node *l, *r;
	li val;
	node() : l(NULL), r(NULL), val(0) {}
};

void upd(node* &v, li l, li r, li L, li R, int val){
	if (L >= R)
		return;
	if (!v) v = new node();
	if (l == L && r == R){
		v->val += val;
		return;
	}
	li m = (l + r) / 2;
	upd(v->l, l, m, L, min(m, R), val);
	upd(v->r, m, r, max(m, L), R, val);
}

pair<li, li> trav(node *v, li l, li r, li cur){
	if (!v) return mp(-INF64, 0);
	cur += v->val;
	if (l == r - 1)
		return mp(cur, 1);
	li m = (l + r) / 2;
	auto resl = trav(v->l, l, m, cur);
	auto resr = trav(v->r, m, r, cur);
	if (resl.x != resr.x)
		return max(resl, resr);
	if (resl.x != -INF64)
		return mp(resl.x, resl.y + resr.y);
	return mp(cur, r - l);
}

pair<li, li> trav2(node *v, li l, li r, li cur, li mx){
	if (!v) return mp(-INF64, 0);
	cur += v->val;
	if (l == r - 1){
		if (cur == mx)
			printf("%lld\n", (1ll << (h - 1)) + l);
		return mp(cur, 1);
	}
	li m = (l + r) / 2;
	auto resl = trav2(v->l, l, m, cur, mx);
	auto resr = trav2(v->r, m, r, cur, mx);
	if (resl.x != resr.x)
		return max(resl, resr);
	if (resl.x != -INF64)
		return mp(resl.x, resl.y + resr.y);
	return mp(cur, r - l);
}

void solve() {
	node *t = new node();
	
	li l = 1ll << (h - 1);
	forn(i, m){
		li L = q[i].l, R = q[i].r;
		forn(_, h - q[i].i)
			L *= 2, R = R * 2 + 1;
		if (q[i].ans == 1)
			upd(t, 0, l, L - l, R - l + 1, 1);
		else{
			upd(t, 0, l, 0, L - l, 1);
			upd(t, 0, l, R - l + 1, l, 1);
		}
	}
	
	auto res = trav(t, 0, l, 0);
	if (res.x != m){
		puts("Game cheated!");
		return;
	}
	
	if (res.y != 1){
		puts("Data not sufficient!");
		return;
	}
	
	trav2(t, 0, l, 0, res.x);
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