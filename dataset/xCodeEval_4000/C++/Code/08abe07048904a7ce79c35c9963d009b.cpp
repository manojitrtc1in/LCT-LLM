

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

const int N = 2000 + 7;

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

bool ok[N];

bool ask(vector<int> pos, int k){
	vector<int> tmp;
	for (auto x : pos) if (!ok[x])
		tmp.pb(x);
	

	

	int dt = 0;
	printf("%d", sz(tmp));
	for (auto x : tmp){
		ok[x] = true;
		++dt;
		printf(" %d", x + 1);
	}
	puts("");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	--x;
	for (int i = x; i < x + sz(tmp); ++i){
		dt -= ok[i % n];
		ok[i % n] = false;
	}


	return dt > 0;
}

void solve(){
	memset(ok, 0, sizeof(ok));
	int k = 1;
	fore(i, 1, n + 1) if (n - (n + i - 1) / i - (i - 1) > n - (n + k - 1) / k - (k - 1))
		k = i;
	vector<int> pos;
	forn(i, n - 1) if (i % k != k - 1)
		pos.pb(i);
	while (ask(pos, k));
	puts("0");
	fflush(stdout);
}

int main() {
#ifdef _DEBUG




	
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