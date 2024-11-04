

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

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
vector<int> a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k){
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
	return true;
}

int cnt[N];

void solve() {
	memset(cnt, 0, sizeof(int) * n);
	forn(i, m) ++cnt[a[i][0]];
	int val = -1;
	forn(i, n) if (cnt[i] > (m + 1) / 2)
		val = i;
	int cnt2 = 0;
	forn(i, m) if (a[i][0] == val && sz(a[i]) > 1)
		++cnt2;
	if (val != -1 && (cnt[val] - cnt2) > (m + 1) / 2){
		puts("NO");
		return;
	}
	puts("YES");
	forn(i, m){
		if (a[i][0] == val && sz(a[i]) > 1 && cnt[val] > (m + 1) / 2){
			printf("%d ", a[i][1] + 1);
			--cnt[val];
		}
		else{
			printf("%d ", a[i][0] + 1);
		}
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