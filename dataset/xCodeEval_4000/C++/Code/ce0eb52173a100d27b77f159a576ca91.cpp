

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

const int N = 900 * 1000 + 13;
const int AL = 256;
const int LOGN = 20;

int n;
string t1, t2, t3;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	t1 = buf;
	scanf("%s", buf);
	t2 = buf;
	scanf("%s", buf);
	t3 = buf;
	return true;
}

pair<pt, int> p[N];
int c[N];
int lcp[N];

int st[LOGN][N];
int pw[N];

void init(){
	pw[0] = pw[1] = 0;
	fore(i, 2, N)
		pw[i] = pw[i / 2] + 1;
	forn(i, n)
		st[0][i] = lcp[i];
	fore(j, 1, LOGN){
		forn(i, n){
			st[j][i] = st[j - 1][i];
			if (i + (1 << (j - 1)) < n)
				st[j][i] = min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
		}
	}
}

int getMin(int l, int r){
	int len = pw[r - l];
	return min(st[len][l], st[len][r - (1 << len)]);
}

int add(int a, int b){
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int cnt[N][3];
int ans[N];

int get(int l, int r, int k){
	return cnt[r][k] - cnt[l][k];
}

int get(int l, int r){
	int res = 1;
	forn(i, 3) res = mul(res, get(l, r, i));
	return res;
}

pt getLower(int x){
	int l = 0, r = x - 1;
	while (l < r - 1){
		int m = (l + r) / 2;
		if (getMin(m, x) <= lcp[x])
			l = m;
		else
			r = m;
	}
	if (l >= x || getMin(l, x) > lcp[x])
		return mp(0, 0);
	else if (getMin(r, x) <= lcp[x])
		return mp(r + 1, lcp[r]);
	return mp(l + 1, lcp[l]);
}

pt getUpper(int x){
	int l = x + 1, r = n - 1;
	while (l < r - 1){
		int m = (l + r) / 2;
		if (getMin(x + 1, m + 1) < lcp[x])
			r = m;
		else
			l = m;
	}
	if (getMin(x + 1, l + 1) < lcp[x])
		return mp(l + 1, lcp[l]);
	return mp(r + 1, lcp[r]);
}

void build(){
	static int cnt[N];
	static int cn[N], p[N], pn[N];
	
	memset (cnt, 0, AL * sizeof(int));
	for (int i=0; i<n; ++i)
		++cnt[s[i]];
	for (int i=1; i<AL; ++i)
		cnt[i] += cnt[i-1];
	for (int i=0; i<n; ++i)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i=1; i<n; ++i) {
		if (s[p[i]] != s[p[i-1]])  ++classes;
		c[p[i]] = classes-1;
	}
		

	for (int h=0; (1<<h)<n; ++h) {
		for (int i=0; i<n; ++i) {
			pn[i] = p[i] - (1<<h);
			if (pn[i] < 0)  pn[i] += n;
		}
		memset (cnt, 0, classes * sizeof(int));
		for (int i=0; i<n; ++i)
			++cnt[c[pn[i]]];
		for (int i=1; i<classes; ++i)
			cnt[i] += cnt[i-1];
		for (int i=n-1; i>=0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		classes = 1;
		for (int i=1; i<n; ++i) {
			int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
			if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
				++classes;
			cn[p[i]] = classes-1;
		}
		memcpy (c, cn, n * sizeof(int));
	}
	
	forn(i, n)
		::p[i].y = p[i];
	
	int len = 0;
	forn(i, n){
		int pos = c[i];
		
		if (pos + 1 < n){
			for (int j = p[pos + 1]; s[i + len] == s[j + len]; ++len);
			lcp[pos] = len;
		}
		else{
			lcp[pos] = 0;
		}
		
		len = max(len - 1, 0);
	}
}

void solve(){
	s = t1 + string(1, 'z' + 1) + t2 + string(1, 'z' + 2) + t3 + string(1, 'z' + 3);
	n = sz(s);
	build();
	
	memset(cnt, 0, sizeof(cnt));
	forn(i, n){
		forn(j, 3) cnt[i + 1][j] += cnt[i][j];
		if (!isalpha(s[p[i].y])) continue;
		if (p[i].y < sz(t1))
			++cnt[i + 1][0];
		else if (p[i].y < sz(t1) + sz(t2) + 1)
			++cnt[i + 1][1];
		else
			++cnt[i + 1][2];
	}
	
	init();
	memset(ans, 0, sizeof(ans));
	forn(i, n - 1){
		pt l = getLower(i);
		pt r = getUpper(i);
		if (l.y == lcp[i])
			continue;
		ans[lcp[i]] = add(ans[lcp[i]], get(l.x, r.x));
		ans[max(l.y, r.y)] = add(ans[max(l.y, r.y)], -get(l.x, r.x));
	}
	
	for (int i = n - 1; i > 0; --i)
		ans[i - 1] = add(ans[i - 1], ans[i]);
	
	fore(i, 1, min({sz(t1), sz(t2), sz(t3)}) + 1)
		printf("%d ", ans[i]);
	puts("");
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