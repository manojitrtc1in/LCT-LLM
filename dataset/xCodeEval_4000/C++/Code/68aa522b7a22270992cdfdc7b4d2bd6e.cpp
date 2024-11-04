

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

const int N = 50 * 1000 + 13;
const int M = 12;

int w, n, m;
int a[N];
string s[N];

bool read () {
	if (scanf("%d%d%d", &w, &n, &m) != 3)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	static char buf[30];
	forn(i, m){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

int cnt[531443];

int bit(int mask, int x){
	forn(_, x) mask /= 3;
	return mask % 3;
}

const string al = "AOXaox";
vector<vector<vector<int>>> ops({{{0, 2}, {1, 0}}, {{0, 0}}, {{0, 0}, {1, 1}}, {{1, 1}}, {{0, 1}, {1, 2}}, {{0, 1}, {1, 0}}});

int pos[1 << M];
vector<int> pws;
int ans;
string cur;
int mask1, mask2;

void brute(int i){
	if (i == w){
		ans += cnt[mask1] * cnt[mask2];
		return;
	}
	for (auto &it : ops[cur[i]]){
		mask1 += pws[i] * it[0];
		mask2 += pws[i] * it[1];
		brute(i + 1);
		mask2 -= pws[i] * it[1];
		mask1 -= pws[i] * it[0];
	}
}

void solve() {
	forn(i, m) forn(j, w)
		s[i][j] = al.find(s[i][j]);
	pws.assign(1, 1);
	forn(_, w) pws.pb(pws.back() * 3);
	memset(cnt, 0, sizeof(cnt));
	forn(i, 1 << w){
		int cur = 0;
		forn(j, w)
			cur += pws[j] * ((i >> (w - j - 1)) & 1);
		pos[i] = cur;
	}
	forn(i, n) ++cnt[pos[a[i]]];
	int c;
	forn(i, w) forn(mask, pws.back()) if (cnt[mask] && (c = bit(mask, i)) != 2)
		cnt[mask + pws[i] * (2 - c)] += cnt[mask];
	forn(i, m){
		ans = 0;
		cur = s[i];
		brute(0);
		printf("%d\n", ans);
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