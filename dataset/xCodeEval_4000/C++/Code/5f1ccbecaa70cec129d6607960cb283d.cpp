

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
const int K = 15;

int n;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	return true;
}

deque<pt> dp[N];
int sum[N];

deque<pt> merge(int c, deque<pt> a){
	if (a.empty()) return {mp(1, c)};
	if (a[0].y == c){
		++a[0].x;
		return a;
	}
	a.push_front(mp(1, c));
	if (sz(a) > K)
		a.pop_back();
	return a;
}

bool comp(const deque<pt> &a, const deque<pt> &b){
	forn(i, min(sz(a), sz(b))) if (a[i] != b[i]){
		if (a[i].y != b[i].y)
			return a[i].y < b[i].y;
		if (a[i] < b[i])
			return i == sz(b) - 1 || a[i + 1].y < b[i].y;
		else
			return i != sz(b) - 1 && b[i + 1].y > a[i].y;
	}
	if (sz(a) != sz(b))
		return sz(a) < sz(b);
	return false;
}

int p[N];

void solve() {
	dp[n] = {};
	for (int i = n - 1; i >= 0; --i){
		dp[i] = merge(s[i] - 'a', dp[i + 1]);
		sum[i] = sum[i + 1] + 1;
		p[i] = (sum[i] <= 2 ? i : p[i + 1]);
		if (i != n - 1 && s[i] == s[i + 1] && comp(dp[i + 2], dp[i])){
			dp[i] = dp[i + 2];
			p[i] = p[i + 2];
			sum[i] = sum[i + 2];
		}
	}
	forn(i, n){
		int val = (sum[i] > 10 ? 5 : sum[i]);
		string pr = "";
		for (auto it : dp[i]){
			int t = min(it.x, val - sz(pr));
			pr += string(t, it.y + 'a');
			if (sz(pr) == val) break;
		}
		if (sum[i] > 10){
			int j = p[i];
			pr += "...";
			for (auto it : dp[j])
				pr += string(it.x, it.y + 'a');
		}
		printf("%d %s\n", sum[i], pr.c_str());
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