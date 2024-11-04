

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

const int N = 200 * 1000 + 13;
const int P = 450;

struct query{
	int x1, y1, x2, y2, i;
	int l, r;
};

int h, w, n, m;
pt a[N];
query q[N];

bool read () {
	if (scanf("%d%d%d%d", &h, &w, &n, &m) != 4)
		return false;
	forn(i, n){
		scanf("%d%d", &a[i].x, &a[i].y);
		--a[i].x, --a[i].y;
	}
	forn(i, m){
		scanf("%d%d%d%d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
		--q[i].x1, --q[i].y1, --q[i].x2, --q[i].y2;
		q[i].i = i;
	}
	return true;
}

int cnt[N];
int bl[N];
bool ans[N];

void add(int x){
	bl[x / P] += cnt[x] == 0;
	++cnt[x];
}

void rem(int x){
	bl[x / P] -= cnt[x] == 1;
	--cnt[x];
}

int ask(int l, int r){
	int tot = 0;
	for (int i = l; i <= r;){
		if (i % P == 0 && i + P <= r + 1){
			tot += bl[i / P];
			i += P;
		}
		else{
			tot += cnt[i] > 0;
			++i;
		}
	}
	return tot;
}

void solve() {
	forn(i, m) ans[i] = false;
	forn(_, 2){
		sort(a, a + n);
		forn(i, m){
			q[i].l = lower_bound(a, a + n, mp(q[i].x1, -1)) - a;
			q[i].r = lower_bound(a, a + n, mp(q[i].x2, INF)) - a - 1;
		}
		
		sort(q, q + m, [](const query &a, const query &b){
			if (a.l / P != b.l / P)
				return a.l < b.l;
			if ((a.l / P) & 1)
				return a.r < b.r;
			return a.r > b.r;
		});
		
		int L = 0, R = -1;
		memset(cnt, 0, sizeof(cnt));
		memset(bl, 0, sizeof(bl));
		forn(i, m){
			int l = q[i].l, r = q[i].r;
			if (l > r){
				ans[q[i].i] = false;
				continue;
			}
			while (L > l) --L, add(a[L].y);
			while (R < r) ++R, add(a[R].y);
			while (L < l) rem(a[L].y), ++L;
			while (R > r) rem(a[R].y), --R;
			ans[q[i].i] |= ask(q[i].y1, q[i].y2) == q[i].y2 - q[i].y1 + 1;
		}
		forn(i, n) swap(a[i].x, a[i].y);
		forn(i, m) swap(q[i].x1, q[i].y1), swap(q[i].x2, q[i].y2);
	}
	forn(i, m){
		puts(ans[i] ? "YES" : "NO");
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