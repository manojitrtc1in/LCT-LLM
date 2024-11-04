

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

const int N = 1000 * 1000 + 13;
const int AL = 26;

int n;
string s;
int m;
int t[N];

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%d", &m);
	forn(i, m){
		scanf("%s", buf);
		string tmp = buf;
		int x = 0;
		forn(j, sz(tmp))
			x |= (1 << (tmp[j] - 'a'));
		t[i] = x;
	}
	return true;
}

int nxt[N][AL];
int cnt[N], mx[N];
unordered_map<int, int> masks;

void solve() {
	forn(i, AL) nxt[n][i] = n;
	for (int i = n - 1; i >= 0; --i){
		forn(j, AL)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	
	masks.clear();
	masks.rehash(32748313);
	forn(i, m) if (!masks.count(t[i])){
		int k = sz(masks);
		masks[t[i]] = k;
	}
	
	memset(cnt, 0, sizeof(cnt));
	memset(mx, -1, sizeof(mx));
	
	forn(i, n){
		int lst = i;
		int cur = (1 << (s[lst] - 'a'));
		while (true){
			int mn = n;
			forn(j, AL) if (!((cur >> j) & 1))
				mn = min(mn, nxt[lst][j]);
			if (masks.count(cur)){
				int x = masks[cur];
				if (mx[x] != mn - 1){
					mx[x] = mn - 1;
					++cnt[x];
				}
			}
			if (mn == n)
				break;
			lst = mn;
			cur |= (1 << (s[lst] - 'a'));
		}
	}
	
	forn(i, m)
		printf("%d\n", cnt[masks[t[i]]]);
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