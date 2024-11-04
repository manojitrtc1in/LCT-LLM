

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

const int N = 500 * 1000 + 13;

int n;
string s;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

li ans;
int vals[N];
li su[N];

void calc(int l, int r){
	if (l == r - 1){
		ans += (s[l] == '1');
		return;
	}
	int m = (l + r) / 2;
	calc(l, m);
	calc(m, r);
	int cur = 0, mx = 0;
	int posl = l - 1;
	for (int i = m - 1; i >= l; --i){
		if (s[i] == '1')
			++cur;
		else{
			cur = 0;
			posl = max(posl, i);
		}
		mx = max(mx, cur);
		vals[i] = mx;
	}
	su[l] = 0;
	fore(i, l, m) su[i + 1] = su[i] + vals[i];
	cur = 0, mx = 0;
	int posr = -1;
	int j = posl;
	for (int i = m; i < r; ++i){
		if (s[i] == '1')
			++cur;
		else{
			cur = 0;
			if (posr == -1)
				posr = i;
		}
		int tmp = posr == -1 ? i + 1 : posr;
		mx = max(mx, cur);
		while (j >= l && vals[j] <= max(mx, tmp - posl - 1)) --j;
		ans += su[j + 1];
		ans += li(posl - j) * max(mx, tmp - posl - 1);
		int ni = min(m - 1, max(posl, tmp - mx));
		ans += (m - posl - 1) * li(m - posl) / 2 - (m - ni) * li(m - ni - 1) / 2 + (tmp - m) * li(ni - posl);
		ans += li(m - ni - 1) * mx;
	}
}

void solve() {
	ans = 0;
	calc(0, n);
	printf("%lld\n", ans);
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