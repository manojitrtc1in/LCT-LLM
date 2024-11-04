

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

const int INF = int(1e9) + 10;
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

int n;
vector<pt> a[3];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, 3) a[i].clear();
	forn(i, n){
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		--c;
		a[c].pb(mp(x, y));
	}
	return true;
}

vector<int> ys[3];
int n3;

bool check1(int cnt){
	int y = ys[0][cnt - 1];
	int l = 0, r = 0;
	int cntl = 0, cntr = 0;
	forn(i, n3) if (a[2][i].y > y) ++cntr;
	while (l < n3 || r < n3){
		int x = min(l < n3 ? a[1][l].x : INF, r < n3 ? a[2][r].x : INF);
		while (l < n3 && a[1][l].x == x){
			cntl += a[1][l].y > y;
			++l;
		}
		while (r < n3 && a[2][r].x == x){
			cntr -= a[2][r].y > y;
			++r;
		}
		if (min(cntl, cntr) >= cnt){
			return true;
		}
	}
	return false;
}

bool check2(int cnt){
	int y = ys[0][cnt - 1];
	int l = 0, r = 0;
	int cntl = 0, cntr = 0;
	forn(i, n3) if (ys[2][i] > y) ++cntr;
	while (l < n3 || r < n3){
		int x = min(l < n3 ? ys[1][l] : INF, r < n3 ? ys[2][r] : INF);
		while (l < n3 && ys[1][l] == x){
			cntl += ys[1][l] > y;
			++l;
		}
		while (r < n3 && ys[2][r] == x){
			cntr -= ys[2][r] > y;
			++r;
		}
		if (min(cntl, cntr) >= cnt){
			return true;
		}
	}
	return false;
}

void solve() {
	n3 = n / 3;
	int ans = 0;
	forn(_, 4){
		forn(i, 3) sort(all(a[i]));
		forn(i, 3){
			ys[i].clear();
			for (auto it : a[i])
				ys[i].pb(it.y);
			sort(all(ys[i]));
		}
		forn(__, 3){
			forn(___, 2){
				int l = 1, r = n3;
				while (l <= r){
					int m = (l + r) / 2;
					if (check1(m)){
						ans = max(ans, m * 3);
						l = m + 1;
					}
					else{
						r = m - 1;
					}
				}
				l = 1, r = n3;
				while (l <= r){
					int m = (l + r) / 2;
					if (check2(m)){
						ans = max(ans, m * 3);
						l = m + 1;
					}
					else{
						r = m - 1;
					}
				}
				swap(a[1], a[2]);
				swap(ys[1], ys[2]);
			}
			rotate(a, a + 1, a + 3);
			rotate(ys, ys + 1, ys + 3);
		}
		forn(i, 3) for (auto &it : a[i]){
			it = mp(-it.y, it.x);
		}
	}
	printf("%d\n", ans);
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