

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

const int N = 1000 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

void solve() {
	ld l = -INF, r = INF;
	int j = 0, cnt = 0;
	fore(i, 1, 1000001){
		if (j == n)
			break;
		if (a[j] == i){
			++cnt;
			++j;
		}
		l = max(l, 10 * (i + 1) / ld(cnt + 1));
		if (cnt != 0) r = min(r, 10 * (i + 1) / ld(cnt));
	}
	

	int ans = 0;
	int lst = -1;
	fore(i, a[n - 1] + 1, 3000001){
		ld L = 10 * (i + 1) / ld(n + 2);
		ld R = 10 * (i + 1) / ld(n + 1);
		if (max(L, l) < min(R, r)){
			++ans;
			lst = i;
		}
		l = max(l, 10 * (i + 1) / ld(n + 1));
		r = min(r, 10 * (i + 1) / ld(n));
		if (l > r) break;
	}
	puts(ans == 1 ? "unique" : "not unique");
	if (ans == 1) printf("%d\n", lst);
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