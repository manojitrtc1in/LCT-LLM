

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

int n, m;
pt a[N];

bool read () {
	if (scanf("%d%d", &m, &n) != 2)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

struct line{
	li A, B, C;
	line(const pt &a, const pt &b){
		A = a.y - b.y;
		B = b.x - a.x;
		C = -A * a.x - B * a.y;
		if (A < 0) A = -A, B = -B, C = -C;
		else if (A == 0 && B < 0) B = -B, C = -C;
		else if (A == 0 && B == 0 && C < 0) C = -C;
		li g = __gcd(abs(A), __gcd(abs(B), abs(C)));
		if (g != 0) A /= g, B /= g, C /= g;
	}
};

bool operator <(const line &a, const line &b){
	if (a.A != b.A)
		return a.A < b.A;
	if (a.B != b.B)
		return a.B < b.B;
	return a.C < b.C;
}

map<line, int> cur;
int ans[N];

void solve() {
	fill(ans, ans + m, 1);
	forn(i, n){
		cur.clear();
		forn(j, n) if (i != j)
			++cur[line(a[i], a[j])];
		for (auto it : cur) if (it.x.A != 0 && -it.x.C % it.x.A == 0){
			li x = -it.x.C / it.x.A;
			if (1 <= x && x <= m)
				ans[x - 1] = max(ans[x - 1], it.y + 1);
		}
	}
	li sum = 0;
	forn(i, m) sum += ans[i];
	printf("%lld\n", sum);
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