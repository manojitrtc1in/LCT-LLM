

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

const int N = 100 * 1000 + 13;
const int AL = 52;

int n, m;
string s;
pt q[N];

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

inline int mul(int a, int b){
	if (a == 0 || b == 0) return 0;
	return a * li(b) % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int inv(int a){
	return binpow(a, MOD - 2);
}

int fact[N], rfact[N];
int cnt[AL];

int cnk(int n, int k){
	if (k < 0 || k > n) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int pr[AL + 1][N / 2], su[AL + 1][N / 2];
int ans[AL][AL];
int n2[N];
int ncnt[AL][N];

void solve() {
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = inv(fact[N - 1]);
	for (int i = N - 2; i >= 0; --i) rfact[i] = mul(rfact[i + 1], i + 1);
	
	memset(cnt, 0, sizeof(cnt));
	vector<char> xs(all(s));
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	
	forn(i, n){
		s[i] = lower_bound(all(xs), s[i]) - xs.begin();
		++cnt[s[i]];
	}
	
	int AL = sz(xs);
	forn(i, N) n2[i] = cnk(n / 2, i);
	forn(i, AL) forn(j, N - cnt[i]) ncnt[i][j] = cnk(j + cnt[i], cnt[i]);
	
	memset(ans, 0, sizeof(ans));
	forn(z, AL){
		int tot;
		
		memset(pr, 0, sizeof(pr));
		tot = 0;
		pr[0][0] = 1;
		forn(i, AL){
			forn(j, tot + 1) if (pr[i][j]){
				if (i != z && j + cnt[i] <= n / 2)
					pr[i + 1][j + cnt[i]] = add(pr[i + 1][j + cnt[i]], mul(ncnt[i][j], pr[i][j]));
				if (tot - j + cnt[i] <= n / 2)
					pr[i + 1][j] = add(pr[i + 1][j], mul(ncnt[i][tot - j], pr[i][j]));
			}
			tot += cnt[i];
		}
		
		memset(su, 0, sizeof(su));
		tot = 0;
		su[0][0] = 1;
		forn(i, AL){
			int ni = AL - i - 1;
			forn(j, tot + 1) if (su[i][j]){
				if (ni != z && j + cnt[ni] <= n / 2)
					su[i + 1][j + cnt[ni]] = add(su[i + 1][j + cnt[ni]], mul(ncnt[ni][j], su[i][j]));
				if (tot - j + cnt[ni] <= n / 2)
					su[i + 1][j] = add(su[i + 1][j], mul(ncnt[ni][tot - j], su[i][j]));
			}
			tot += cnt[ni];
		}
		
		
		
		ans[z][z] = pr[AL][n / 2];
		tot = 0;
		forn(i, AL){
			if (z != i) forn(j, min(n / 2, tot) + 1) if (tot - j + cnt[i] <= n / 2)
				ans[z][i] = add(ans[z][i], mul(mul(n2[j], n2[tot - j + cnt[i]]), mul(ncnt[i][tot - j], mul(pr[i][j], su[AL - i - 1][n / 2 - j]))));
			tot += cnt[i];
		}
	}
	
	forn(i, m) printf("%d\n", mul(2, ans[s[q[i].x]][s[q[i].y]]));
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