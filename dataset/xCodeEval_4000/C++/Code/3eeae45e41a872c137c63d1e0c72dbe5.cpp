

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

const int N = 100 * 1000 + 13;

int n;
string a[N];
int m;
pair<int, string> q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		a[i + 1] = buf;
	}
	a[0] = "blue";
	a[n + 1] = "lock";
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%s", &q[i].x, buf);
		q[i].y = buf;
	}
	return true;
}

int t[4 * N];
int ps[4 * N];

void push(int v, int l, int r){
	if (ps[v] == -1)
		return;
	if (l != r - 1){
		ps[v * 2] = ps[v];
		ps[v * 2 + 1] = ps[v];
	}
	t[v] = ps[v] * (r - l);
	ps[v] = -1;
}

void build(int v, int l, int r){
	ps[v] = -1;
	if (l == r - 1){
		t[v] = a[l] != "unlock" && a[l] != "lock";
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = t[v * 2] + t[v * 2 + 1];
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
	t[v] = t[v * 2] + t[v * 2 + 1];
}

int get(int v, int l, int r){
	push(v, l, r);
	if (t[v] == 0)
		return -1;
	if (l == r - 1)
		return l;
	int m = (l + r) / 2;
	int res = get(v * 2 + 1, m, r);
	if (res != -1)
		push(v * 2, l, m);
	else
		res = get(v * 2, l, m);
	t[v] = t[v * 2] + t[v * 2 + 1];
	return res;
}

set<pt> pos;

void solve() {
	n += 2;
	build(1, 0, n);
	pos.clear();
	pos.insert(mp(n - 1, 0));
	for (int i = n - 2; i >= 0; --i){
		if (a[i] == "unlock"){
			pos.insert(mp(i, 1));
		}
		else if (a[i] == "lock"){
			upd(1, 0, n, i + 1, pos.begin()->x, 0);
			pos.insert(mp(i, 0));
		}
	}
	pos.insert(mp(-1, 1));
	puts(a[get(1, 0, n)].c_str());
	forn(z, m){
		int i = q[z].x;
		string ol = a[i];
		string nw = q[z].y;
		if (ol == "lock" || ol == "unlock"){
			if (nw == "lock" || nw == "unlock"){
				upd(1, 0, n, i + 1, pos.lower_bound(mp(i, INF))->x, nw == "unlock");
				pos.erase(mp(i, ol == "unlock"));
				pos.insert(mp(i, nw == "unlock"));
			}
			else{
				auto it = pos.lower_bound(mp(i, -1));
				it = pos.erase(it);
				int r = it->x;
				--it;
				upd(1, 0, n, it->x + 1, r, it->y);
			}
		}
		else{
			if (nw == "lock" || nw == "unlock"){
				upd(1, 0, n, i, i + 1, 0);
				auto it = pos.lower_bound(mp(i, INF));
				upd(1, 0, n, i + 1, it->x, nw == "unlock");
				--it;
				upd(1, 0, n, it->x + 1, i, it->y);
				pos.insert(mp(i, nw == "unlock"));
			}
		}
		a[i] = nw;
		puts(a[get(1, 0, n)].c_str());
	}
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

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}