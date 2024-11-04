

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

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	
	return true;
}

int masks[N];
li res[N];

void solve(){
	int i = 0;
	forn(mask, 1 << 13) if (__builtin_popcount(mask) == 6){
		masks[i++] = mask;
		if (i == n) break;
	}
	forn(i, n){
		res[i] = 0;
	}
	forn(j, 13){
		int cnt = 0;
		forn(i, n) if ((masks[i] >> j) & 1)
			++cnt;
		if (cnt == 0)
			continue;
		printf("? %d", cnt);
		forn(i, n) if ((masks[i] >> j) & 1)
			printf(" %d", i + 1);
		puts("");
		fflush(stdout);
		li x;
		scanf("%lld", &x);
		forn(i, n) if (!((masks[i] >> j) & 1))
			res[i] |= x;
	}
	printf("!");
	forn(i, n) printf(" %lld", res[i]);
	puts("");
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