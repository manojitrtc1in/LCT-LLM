

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

const int N = 70;

int x, k, n, q;
int c[N];
pt a[N];

bool read () {
	if (scanf("%d%d%d%d", &x, &k, &n, &q) != 4)
		return false;
	forn(i, k)
		scanf("%d", &c[i]);
	forn(i, q){
		scanf("%d%d", &a[i].x, &a[i].y);
		--a[i].x;
	}
	return true;
}

typedef array<array<li, N>, N> mat;

int cnt;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, cnt) forn(j, cnt) c[i][j] = INF64;
	forn(i, cnt) forn(j, cnt) forn(k, cnt) c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
	return c;
}

mat binpow(mat a, int b){
	mat res;
	forn(i, cnt) forn(j, cnt) res[i][j] = i == j ? 0 : INF64;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int num[1 << 8];

mat get(int pos, int &mx){
	mx = n - x - pos;
	vector<int> pr(k, 0);
	forn(i, q) if (pos < a[i].x){
		if (a[i].x <= pos + k){
			pr[a[i].x - pos - 1] = a[i].y;
			mx = 1;
		}
		else{
			mx = min(mx, a[i].x - (pos + k));
		}
	}
	mat res;
	forn(i, cnt) forn(j, cnt) res[i][j] = INF64;
	forn(mask, 1 << k) if (__builtin_popcount(mask) == x){
		if (mask & 1){
			fore(i, 1, k + 1) if (!((mask >> i) & 1))
				res[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
		}
		else{
			res[num[mask]][num[mask >> 1]] = 0;
		}
	}
	return res;
}

void solve(){
	cnt = 0;
	forn(mask, 1 << k) if (__builtin_popcount(mask) == x)
		num[mask] = cnt++;
	
	mat cur;
	forn(i, cnt) forn(j, cnt) cur[i][j] = i == j ? 0 : INF64;
	sort(a, a + q);
	for (int i = 0; i < n - x;){
		int mx;
		mat tmp = get(i, mx);
		i += mx;
		cur = cur * binpow(tmp, mx);
	}
	
	printf("%lld\n", cur[0][0]);
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