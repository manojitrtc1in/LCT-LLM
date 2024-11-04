

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

int a[4];

bool read () {
	if (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) != 4)
		return false;
	return true;
}

int sign(ld x){
	return (x < 0 ? -1 : 1);
}

bool check(ld x){
	vector<vector<ld>> vals;
	forn(i, 4){
		vals.pb({a[i] - x, a[i] + x});
		if (a[i] - x < 0 && a[i] + x > 0)
			vals.back().pb(0);
	}
	bool pos = false, neg = false;
	for (auto a : vals[0]) for (auto d : vals[3])
		for (auto b : vals[1]) for (auto c : vals[2]){
			int s = sign(a * d - b * c);
			pos |= s == 1;
			neg |= s == -1;
		}
	return pos && neg;
}

void solve() {
	ld l = 0, r = ld(3) * INF;
	forn(_, 100){
		ld m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	printf("%.15Lf\n", (l + r) / 2);
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