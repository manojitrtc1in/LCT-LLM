

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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;

int n;
pair<int, pt> a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d%d%d", &a[i].y.x, &a[i].x, &a[i].y.y);
		--a[i].x, --a[i].y.x, --a[i].y.y;
	}
	return true;
}

int ps[4 * N];
pt t[4 * N];

void push(int v){
	if (v * 2 + 1 < 4 * N){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v].x += ps[v];
	ps[v] = 0;
}

void build(int v, int l, int r){
	ps[v] = 0;
	if (l == r - 1){
		t[v] = mp(0, -l);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

pt get(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return mp(0, -1);
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	pt res = max(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
	t[v] = max(t[v * 2], t[v * 2 + 1]);
	return res;
}

void solve(){
	vector<pair<int, pt>> qr;
	forn(i, n){
		qr.pb(mp(a[i].y.x, mp(0, i)));
		qr.pb(mp(a[i].x, mp(1, i)));
	}
	build(1, 0, N);
	sort(all(qr));
	pair<int, pt> ans = mp(0, mp(-1, -1));
	forn(i, sz(qr)){
		int x = qr[i].y.y;
		if (qr[i].y.x == 0){
			upd(1, 0, N, a[x].x, a[x].y.y + 1, 1);
		}
		else{
			pt tmp = get(1, 0, N, a[x].x, a[x].y.y + 1);
			ans = max(ans, mp(tmp.x, mp(qr[i].x, -tmp.y)));
			upd(1, 0, N, a[x].x, a[x].y.y + 1, -1);
		}
	}
	vector<int> res;
	forn(i, n) if (ans.y.x <= a[i].x && a[i].x <= ans.y.y && min(a[i].y.y, ans.y.y) - max(a[i].y.x, ans.y.x) == ans.y.y - ans.y.x)
		res.pb(i + 1);
	printf("%d\n", ans.x);
	for (auto it : res)
		printf("%d ", it);
	puts("");
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}