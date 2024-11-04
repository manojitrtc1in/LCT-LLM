

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

int n, m;
pair<pt, int> a[N];
pt b[N];

bool read () {
	if (scanf("%d", &m) != 1)
		return false;
	forn(i, m)
		scanf("%d%d", &b[i].x, &b[i].y);
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d%d", &a[i].x.x, &a[i].x.y, &a[i].y);
	return true;
}

void solve() {
	vector<pt> qs;
	forn(i, m) qs.pb(mp(b[i].y, i));
	forn(i, n) qs.pb(mp(a[i].x.y, i + m));
	sort(all(qs));
	vector<int> ans(m, -1);
	set<pt> cur;
	for (auto it : qs){
		if (it.y < m)
			cur.insert(mp(b[it.y].x, it.y));
		else{
			int i = it.y - m;
			while (a[i].y > 0 && !cur.empty()){
				auto jt = cur.lower_bound(mp(a[i].x.x, -INF));
				if (jt == cur.end()) break;
				--a[i].y;
				ans[jt->y] = i + 1;
				cur.erase(jt);
			}
		}
	}
	if (!cur.empty()){
		puts("NO");
		return;
	}
	puts("YES");
	forn(i, m)
		printf("%d ", ans[i]);
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