

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

const int N = 10 * 1000 + 13;
const int LOGN = 30;

int n;
int a[N], b[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	return true;
}

pt bas1[LOGN], bas2[LOGN];
bool used[LOGN];

bool add(int a[N], int x, int pos, pt bas[LOGN], vector<pt> &moves){
	for (int i = LOGN - 1; i >= 0; --i) if ((x >> i) & 1){
		if (bas[i].x == -1){
			bas[i] = mp(x, pos);
			return true;
		}
		moves.pb(mp(pos, bas[i].y));
		a[pos] ^= a[bas[i].y];
		x ^= bas[i].x;
	}
	return false;
}

vector<int> addpos(int x, pt bas[LOGN]){
	vector<int> res;
	for (int i = LOGN - 1; i >= 0; --i) if ((x >> i) & 1){
		if (bas[i].x == -1)
			return {};
		res.pb(i);
		x ^= bas[i].x;
	}
	return res;
}

void getbas(int a[N], pt bas[LOGN], vector<pt> &moves){
	forn(i, LOGN) bas[i] = mp(-1, -1);
	forn(i, n) add(a, a[i], i, bas, moves);
}

int mt[LOGN];

void solve() {
	vector<pt> p1, p2;
	getbas(a, bas1, p1);
	getbas(b, bas2, p2);
	reverse(all(p2));
	
	

	

	
	vector<pt> p3;
	memset(used, 0, sizeof(used));
	forn(i, LOGN) if (bas2[i].x != -1){
		auto tmp = addpos(bas2[i].x, bas1);
		if (tmp.empty()){
			puts("-1");
			return;
		}
		bool made = false;
		for (int j : tmp) if (!used[j]){
			made = true;
			used[j] = true;
			for (int k : tmp) if (k != j)
				p3.pb(mp(bas1[j].y, bas1[k].y));
			a[bas1[j].y] = b[bas2[i].y];
			bas1[j].x = bas2[i].x;
			mt[j] = i;
			break;
		}
		assert(made);
	}
	
	

	

	
	forn(i, LOGN) if (used[i]){
		int j = mt[i];
		if (bas1[i].y != bas2[j].y){
			p3.pb(mp(bas1[i].y, bas2[j].y));
			p3.pb(mp(bas2[j].y, bas1[i].y));
			p3.pb(mp(bas1[i].y, bas2[j].y));
			swap(a[bas1[i].y], a[bas2[j].y]);
			forn(k, LOGN) if (bas1[k].y == bas2[j].y)
				bas1[k].y = bas1[i].y;
			bas1[i].y = bas2[j].y;
		}
	}
	
	forn(i, n) if (a[i] != b[i]){
		p3.pb(mp(i, i));
		a[i] = 0;
		int x = b[i];
		for (int j = LOGN - 1; j >= 0; --j) if ((x >> j) & 1){
			p3.pb(mp(i, bas1[j].y));
			a[i] ^= a[bas1[j].y];
			x ^= bas1[j].x;
		}
	}
	
	

	
	vector<pt> tot;
	for (auto it : p1) tot.pb(it);
	for (auto it : p3) tot.pb(it);
	for (auto it : p2) tot.pb(it);
	
	printf("%d\n", sz(tot));
	for (auto it : tot)
		printf("%d %d\n", it.x + 1, it.y + 1);
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