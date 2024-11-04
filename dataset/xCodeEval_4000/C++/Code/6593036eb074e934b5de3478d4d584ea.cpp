

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

const int N = 1000 + 7;

struct castle{
	int x1, y1, x2, y2;
	castle(){};
};

ostream& operator << (ostream& out, const castle &a) {
	return out << "(" << a.x1 << ", " << a.y1 << ", " << a.x2 << ", " << a.y2 << ")";
}

int n;
castle a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	return true;
}

bool comp1(const castle &a, const castle &b){
	return a.x1 < b.x1;
}

bool comp2(const castle &a, const castle &b){
	return a.y1 < b.y1;
}

bool solve(vector<castle> a){
	if (sz(a) == 1)
		return true;
	vector<castle> tmp;
	int mx;
	bool fl;
	
	sort(all(a), comp1);
	tmp = vector<castle>(1, a[0]);
	mx = a[0].x2;
	fl = true;
	fore(i, 1, sz(a)){
		if (a[i].x1 >= mx){
			fl &= solve(tmp);
			if (!fl) break;
			tmp.clear();
			mx = 0;
		}
		tmp.pb(a[i]);
		mx = max(mx, a[i].x2);
	}
	if (sz(tmp) == sz(a)) fl = false;
	if (fl) fl &= solve(tmp);
	if (fl) return true;
	
	sort(all(a), comp2);
	tmp = vector<castle>(1, a[0]);
	mx = a[0].y2;
	fl = true;
	fore(i, 1, sz(a)){
		if (a[i].y1 >= mx){
			fl &= solve(tmp);
			if (!fl) break;
			tmp.clear();
			mx = 0;
		}
		tmp.pb(a[i]);
		mx = max(mx, a[i].y2);
	}
	if (sz(tmp) == sz(a)) fl = false;
	if (fl) fl &= solve(tmp);
	
	return fl;
}

void solve() {
	puts(solve(vector<castle>(a, a + n)) ? "YES" : "NO");
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