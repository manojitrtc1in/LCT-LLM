

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

const int N = 100 + 7;

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

int ans[N][N];

int get(int n){
	int x = sqrt(n);
	while (x * x < n) ++x;
	if (x * x - n == 2) ++x;
	return x;
}

void draw(int x, int y, int n, bool fl){
	int k = get(n);
	int lft = k * k - n;
	forn(i, k) forn(j, k)
		ans[x + (fl ? i : -i)][y + (fl ? j : -j)] ^= 1;
	if (lft > 0)
		draw(x + (fl ? k - 1 : -k + 1), y + (fl ? k - 1 : -k + 1), lft, fl ^ 1);
}

void solve() {
	if (n == 2){
		puts("-1");
		return;
	}
	memset(ans, 0, sizeof(ans));
	draw(0, 0, n, true);
	int x = get(n);
	printf("%d\n", x);
	for (int i = x - 1; i >= 0; --i){
		forn(j, x) printf("%c", ans[i][j] ? 'o' : '.');
		puts("");
	}
	int cnt = 0;
	forn(i, x) forn(j, x){
		cnt += ans[i][j];
		assert(ans[i][j] == ans[j][i]);
	}
	assert(cnt == n);
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

	while (read()){
	

	

		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}