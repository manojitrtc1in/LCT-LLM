

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

const int N = 1000 * 1000 + 13;

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	++n;
	return true;
}

int p[N];
int res[N];
multiset<int, greater<int>> ch[N];

bool recalc(int v){
	

	int nw;
	if (sz(ch[v]) == 1 || v == 0)
		nw = *ch[v].begin();
	else
		nw = max(*ch[v].begin(), *(++ch[v].begin()) + 1);
	if (nw == res[v])
		return false;
	if (v != 0)
		ch[p[v]].erase(ch[p[v]].find(res[v]));
	res[v] = nw;
	if (v != 0)
		ch[p[v]].insert(res[v]);
	return true;
}

void solve() {
	p[0] = -1;
	res[0] = 1;
	fore(i, 1, n){
		scanf("%d", &p[i]);
		--p[i];
		int v = i;
		res[v] = 1;
		ch[p[v]].insert(res[v]);
		while (p[v] != -1 && recalc(p[v])){
			

			v = p[v];
		}
		printf("%d ", res[0]);
	}
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