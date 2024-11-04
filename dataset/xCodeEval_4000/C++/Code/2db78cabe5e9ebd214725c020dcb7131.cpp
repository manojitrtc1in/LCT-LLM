

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

const int N = 200 * 1000 + 13;

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

int f[4][N];

void upd(int f[N], int x, int val){
	for (int i = x; i <= n; i |= i + 1)
		f[i] += val;
}

int get(int f[N], int x){
	assert(x <= n);
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i];
	return res;
}

void solve() {
	li ans = n * li(n + 1) / 2;
	
	vector<int> sums(3);
	sums[0] = 1;
	int sum = 0;
	vector<int> xs(1, 0);
	forn(i, n){
		sum += (s[i] == '+' ? 1 : -1);
		int mod = (sum % 3 + 3) % 3;
		ans -= sums[(mod + 1) % 3] + sums[(mod + 2) % 3];
		xs.pb(sum);
		++sums[mod];
	}
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	
	forn(t, 3){
		forn(i, n + 1) f[0][i] = 0;
		int sum = 0;
		if (t == 0) upd(f[0], lower_bound(all(xs), 0) - xs.begin(), 1);
		forn(i, n){
			sum += (s[i] == '+' ? 1 : -1);
			if ((sum % 3 + 3) % 3 != t) continue;
			int x = lower_bound(all(xs), sum) - xs.begin();
			ans -= get(f[0], x - 1);
			upd(f[0], x, 1);
		}
	}
	
	forn(t, 3){
		forn(i, 4) forn(j, n + 1) f[i][j] = 0;
		int sum = 0, mx = 0, lst = 0;
		vector<int> xs;
		
		if (t == 0) xs.pb(0);
		forn(i, n){
			if (s[i] == '+'){
				++sum;
				if ((sum % 3 + 3) % 3 == t) xs.pb(sum + 3 * mx);
			}
			else if (lst == 0){
				++mx;
				--sum;
				lst = 1;
				if ((sum % 3 + 3) % 3 == t) xs.pb(sum + 3 * mx);
			}
			else{
				--sum;
				lst = 0;
				if ((sum % 3 + 3) % 3 == t) xs.pb(sum + 3 * mx);
			}
			if ((sum % 3 + 3) % 3 == t){
				xs.pb(sum + 3 * mx);
				xs.pb(sum + 3 * (mx - 1));
			}
		}
		sort(all(xs));
		xs.resize(unique(all(xs)) - xs.begin());
		
		vector<vector<int>> sv(4);
		if (t == 0) upd(f[0], lower_bound(all(xs), 0) - xs.begin(), 1);
		forn(i, n){
			if (s[i] == '+'){
				++sum;
				if ((sum % 3 + 3) % 3 == t){
					upd(f[0], lower_bound(all(xs), sum + 3 * mx) - xs.begin(), 1);
				}
				for (int x : sv[2]){
					upd(f[2], lower_bound(all(xs), x) - xs.begin(), -1);
					upd(f[0], lower_bound(all(xs), x) - xs.begin(), 1);
				}
				for (int x : sv[3]){
					upd(f[3], lower_bound(all(xs), x) - xs.begin(), -1);
					upd(f[1], lower_bound(all(xs), x) - xs.begin(), 1);
				}
				sv[2].clear();
				sv[3].clear();
			}
			else if (lst == 0){
				++mx;
				--sum;
				lst = 1;
				swap(f[2], f[3]);
				swap(sv[2], sv[3]);
				if ((sum % 3 + 3) % 3 == t){
					upd(f[0], lower_bound(all(xs), sum + 3 * mx) - xs.begin(), 1);
				}
			}
			else{
				--sum;
				lst = 0;
				swap(f[2], f[3]);
				swap(sv[2], sv[3]);
				if ((sum % 3 + 3) % 3 == t){
					upd(f[2], lower_bound(all(xs), sum + 3 * mx) - xs.begin(), 1);
					sv[2].pb(sum + 3 * mx);
				}
			}
			if ((sum % 3 + 3) % 3 == t){
				ans -= get(f[0], n) - get(f[0], lower_bound(all(xs), sum + 3 * mx) - xs.begin());
				ans -= get(f[1], n) - get(f[1], lower_bound(all(xs), sum + 3 * (mx - 1)) - xs.begin());
				ans -= get(f[2], n) - get(f[2], lower_bound(all(xs), sum + 3 * mx) - xs.begin());
				ans -= get(f[3], n) - get(f[3], lower_bound(all(xs), sum + 3 * (mx - 1)) - xs.begin());
			}
		}
	}
	
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