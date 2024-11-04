

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

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

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

int t[4 * N];
int ps[4 * N];

void push(int v){
	if (v * 2 + 1 < 4 * N){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

int d[N];

void build(int v, int l, int r){
	ps[v] = 0;
	if (l == r - 1){
		t[v] = d[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void add(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	add(v * 2, l, m, L, min(m, R), val);
	add(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, int val){
	push(v);
	if (l == r - 1){
		t[v] = val;
		return;
	}
	int m = (l + r) / 2;
	if (pos < m){
		upd(v * 2, l, m, pos, val);
		push(v * 2 + 1);
	}
	else{
		upd(v * 2 + 1, m, r, pos, val);
		push(v * 2);
	}
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void add(int l, int r, int val){
	if (l > r){
		add(l, n, val);
		add(0, r, val);
	}
	else{
		add(1, 0, n, l, r, val);
	}
}

int get(){
	push(1);
	return t[1];
}

int get(int v, int l, int r, int pos){
	push(v);
	if (l == r - 1)
		return t[v];
	int m = (l + r) / 2;
	int res;
	if (pos < m){
		res = get(v * 2, l, m, pos);
		push(v * 2 + 1);
	}
	else{
		res = get(v * 2 + 1, m, r, pos);
		push(v * 2);
	}
	t[v] = max(t[v * 2], t[v * 2 + 1]);
	return res;
}

int nl[N], nr[N];

void solve() {
	vector<pt> ord;
	forn(i, n) ord.pb(mp(a[i], i));
	sort(all(ord));
	
	set<int> cur;
	forn(i, n){
		int x = ord[i].y;
		if (cur.empty()){
			d[x] = 1;
			nl[x] = nr[x] = -1;
			cur.insert(x);
			continue;
		}
		auto r = cur.lower_bound(x);
		auto l = r;
		if (r == cur.end()) r = cur.begin();
		if (l == cur.begin()) l = cur.end();
		--l;
		if (*l < x && *r > x)
			d[x] = (a[*l] > a[*r] ? d[*l] : d[*r]) + 1;
		else if (*l < x)
			d[x] = d[*l] + 1;
		else
			d[x] = d[*r] + 1;
		nl[x] = *l;
		nr[x] = *r;
		cur.insert(x);
	}
	
	build(1, 0, n);
	pt ans = mp(get(), 0);
	forn(i, n - 1){
		if (nl[i] == -1) continue;
		add(i, nr[i], -1);
		upd(1, 0, n, i, get(1, 0, n, nl[i]));
		add(nl[i] + 1, i + 1, 1);
		

		ans = min(ans, mp(get(), i + 1));
	}
	printf("%d %d\n", ans.x, ans.y);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	if(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}