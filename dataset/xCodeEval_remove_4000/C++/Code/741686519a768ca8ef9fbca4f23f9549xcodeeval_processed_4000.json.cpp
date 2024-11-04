


 
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
 
const int N = 400 * 1000 + 13;
const int M = 15 * 1000 * 1000 + 13;
 
struct query{
	int t, l, r, x;
	query(){}
};
 
int n, m;
int a[N];
query q[N];
 
bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	static char buf[20];
	forn(i, m){
		scanf("%s%d%d", buf, &q[i].l, &q[i].r);
		--q[i].l;
		q[i].t = (buf[0] == 'M' ? 1 : 2);
		if (q[i].t == 1)
			scanf("%d", &q[i].x);
	}
	return true;
}
 
int pos[300];

vector<int> get(int x){
	vector<int> res;
	for (int i = 2; i * i <= x; ++i) if (x % i == 0){
		res.pb(pos[i]);
		while (x % i == 0)
			x /= i;
	}
	if (x > 1){
		res.pb(pos[x]);
	}
	return res;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}
 
int mul(int a, int b){
	return a * li(b) % MOD;
}
 
inline int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int t[4 * N];
int ps[4 * N];
li tmask[4 * N];
li psmask[4 * N];

void push(int v, int l, int r){
	if (l != r - 1){
		ps[v * 2] = mul(ps[v * 2], ps[v]);
		ps[v * 2 + 1] = mul(ps[v * 2 + 1], ps[v]);
	}
	t[v] = mul(t[v], binpow(ps[v], r - l));
	ps[v] = 1;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v, l, r);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] = val;
		push(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = mul(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int l, int r, int L, int R){
	push(v, l, r);
	if (L >= R)
		return 1;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	int res = 1;
	res = mul(res, get(v * 2, l, m, L, min(m, R)));
	res = mul(res, get(v * 2 + 1, m, r, max(m, L), R));
	t[v] = mul(t[v * 2], t[v * 2 + 1]);
	return res;
}

void pushm(int v){
	if (v * 2 + 1 < 4 * N){
		psmask[v * 2] |= psmask[v];
		psmask[v * 2 + 1] |= psmask[v];
	}
	tmask[v] |= psmask[v];
	psmask[v] = 0;
}

void updm(int v, int l, int r, int L, int R, li val){
	pushm(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		psmask[v] = val;
		pushm(v);
		return;
	}
	int m = (l + r) / 2;
	updm(v * 2, l, m, L, min(m, R), val);
	updm(v * 2 + 1, m, r, max(m, L), R, val);
	tmask[v] = tmask[v * 2] | tmask[v * 2 + 1];
}

li getm(int v, int l, int r, int L, int R){
	pushm(v);
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return tmask[v];
	int m = (l + r) / 2;
	li res = 0;
	res |= getm(v * 2, l, m, L, min(m, R));
	res |= getm(v * 2 + 1, m, r, max(m, L), R);
	tmask[v] = tmask[v * 2] | tmask[v * 2 + 1];
	return res;
}

int inv[62];
 
void solve() {
	vector<int> prm;
	fore(i, 2, 300){
		bool ok = true;
		for (int j = 2; j * j <= i; ++j) if (i % j == 0){
			ok = false;
			break;
		}
		if (ok){
			pos[i] = sz(prm);
			inv[pos[i]] = mul(i - 1, binpow(i, MOD - 2));
			prm.pb(i);
		}
	}
	
	forn(i, 4 * n) t[i] = ps[i] = 1;
	memset(tmask, 0, sizeof(tmask));
	memset(psmask, 0, sizeof(psmask));
	
	forn(i, n){
		upd(1, 0, n, i, i + 1, a[i]);
		li mask = 0;
		auto x = get(a[i]);
		for (auto it : x)
			mask |= (1ll << it);
		updm(1, 0, n, i, i + 1, mask);
	}
	
	forn(i, m){
		if (q[i].t == 1){
			upd(1, 0, n, q[i].l, q[i].r, q[i].x);
			li mask = 0;
			auto x = get(q[i].x);
			for (auto it : x)
				mask |= (1ll << it);
			updm(1, 0, n, q[i].l, q[i].r, mask);
		}
		else{
			int res = get(1, 0, n, q[i].l, q[i].r);
			li mask = getm(1, 0, n, q[i].l, q[i].r);
			forn(i, 62) if ((mask >> i) & 1)
				res = mul(res, inv[i]);
			printf("%d\n", res);
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