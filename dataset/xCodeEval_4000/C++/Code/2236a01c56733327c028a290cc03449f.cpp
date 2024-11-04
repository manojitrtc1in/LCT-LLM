

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

const int N = 2000 + 7;

int n, m;
string s[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

pair<pt, pt> nxt[N][N];
pair<pt, pt> mx1, mx2;
bool used[N][N];
pair<pt, pt> val;

pair<pt, pt> getnxt(short x, short y){
	assert(0 <= x && x < n && 0 <= y && y < m);
	if (used[x][y])
		return nxt[x][y];
	used[x][y] = true;
	
	if (s[x][y] == '#')
		return nxt[x][y] = mp(mp(x, y), mp(-1, 0));
	else if (s[x][y] == '^'){
		val = getnxt(x - 1, y);
		if (val.y.y == 0) val.y.x = 0;
	}
	else if (s[x][y] == '>'){
		val = getnxt(x, y + 1);
		if (val.y.y == 0) val.y.x = 1;
	}
	else if (s[x][y] == 'v'){
		val = getnxt(x + 1, y);
		if (val.y.y == 0) val.y.x = 2;
	}
	else{
		val = getnxt(x, y - 1);
		if (val.y.y == 0) val.y.x = 3;
	}
	
	if (val.y.y != -1)
		++val.y.y;
	return nxt[x][y] = val;
}

void solve() {
	memset(nxt, -1, sizeof(nxt));
	memset(used, 0, sizeof(used));
	
	vector<pt> ord;
	forn(i, n) forn(j, m) ord.pb(mp(i, j));
	shuffle(all(ord), rnd);
	
	mx1 = mx2 = mp(mp(-1, -1), mp(-1, 0));
	for (auto cell : ord){
		auto it = getnxt(cell.x, cell.y);
		if (it.y.y == -1){
			puts("-1");
			return;
		}
		if (it.y.y > mx1.y.y){
			mx2 = mx1;
			mx1 = it;
		}
		else if (it.y.y > mx2.y.y && it != mx1){
			mx2 = it;
		}
	}
	
	printf("%d\n", mx1.y.y + mx2.y.y);
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