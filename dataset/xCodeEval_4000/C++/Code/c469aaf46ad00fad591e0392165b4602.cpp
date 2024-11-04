

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

const int N = 1000 + 7;
const int M = 100 * 1000 + 13;

int n, m, k;
string s[N];
pair<pt, pt> q[M];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	forn(i, k){
		scanf("%d%d%d%d", &q[i].x.x, &q[i].x.y, &q[i].y.x, &q[i].y.y);
		--q[i].x.x, --q[i].x.y;
	}
	return true;
}

int pr[N][N];

int calc(int cnt){
	return (cnt >> 1) + ((cnt & 1) ? ((__builtin_popcount(cnt >> 1) & 1) ^ 1) : 0);
}

li get(int x, int y, bool fl){
	li cur = 0;
	if (x >= n && y >= m){
		int cntx = x / n;
		int cnty = y / m;
		int onex = calc(cntx);
		int oney = calc(cnty);
		cur += (onex * li(oney) + (cntx - onex) * li(cnty - oney)) * li(pr[n][m]);
		cur += (onex * li(cnty - oney) + (cntx - onex) * li(oney)) * li(n * m - pr[n][m]);
		bool fly = oney == calc(cnty + 1);
		bool flx = onex == calc(cntx + 1);
		cur += get(x, y % m, fly);
		cur += get(x % n, y, flx);
		cur -= get(x % n, y % m, flx ^ fly);
	}
	else if (x < n && y >= m){
		int cnty = y / m;
		int oney = calc(cnty);
		cur += oney * li(pr[x][m]);
		cur += (cnty - oney) * li(x * m - pr[x][m]);
		cur += get(x, y % m, oney == calc(cnty + 1));
	}
	else if (x >= n && y < m){
		int cntx = x / n;
		int onex = calc(cntx);
		cur += onex * li(pr[n][y]);
		cur += (cntx - onex) * li(n * y - pr[n][y]);
		cur += get(x % n, y, onex == calc(cntx + 1));
	}
	else{
		cur += pr[x][y];
	}
	if (fl) cur = x * li(y) - cur;
	return cur;
}

void solve(){
	forn(i, n) forn(j, m)
		pr[i + 1][j + 1] = pr[i][j + 1] + pr[i + 1][j] - pr[i][j] + (s[i][j] - '0');
	forn(i, k)
		printf("%lld\n", get(q[i].y.x, q[i].y.y, 0) - get(q[i].x.x, q[i].y.y, 0) - get(q[i].y.x, q[i].x.y, 0) + get(q[i].x.x, q[i].x.y, 0));
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