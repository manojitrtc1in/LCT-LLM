

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")

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

const int N = 1000 + 7;
const int M = 10 * 1000 + 13;

struct query{
	int x1, y1, x2, y2, h, w;
};

int n, m, k;
int a[N][N];
query q[M];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	forn(i, n) forn(j, m)
		scanf("%d", &a[i + 1][j + 1]);
	forn(i, k)
		scanf("%d%d%d%d%d%d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2, &q[i].h, &q[i].w);
	return true;
}

pt nxt[N][N][4];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int ans[N][N];

void solve() {
	forn(i, n + 2) forn(j, m + 2) forn(k, 4)
		nxt[i][j][k] = mp(i + dx[k], j + dy[k]);
	forn(i, k){
		int x1 = q[i].x1, y1 = q[i].y1;
		int x2 = q[i].x2, y2 = q[i].y2;
		int h = q[i].h, w = q[i].w;
		pt p1 = mp(0, 0), p2 = mp(0, 0);
		forn(_, x1) p1 = nxt[p1.x][p1.y][2];
		forn(_, y1) p1 = nxt[p1.x][p1.y][1];
		forn(_, x2) p2 = nxt[p2.x][p2.y][2];
		forn(_, y2) p2 = nxt[p2.x][p2.y][1];
		forn(j, w){
			swap(nxt[nxt[p1.x][p1.y][0].x][nxt[p1.x][p1.y][0].y][2], nxt[nxt[p2.x][p2.y][0].x][nxt[p2.x][p2.y][0].y][2]);
			swap(nxt[p1.x][p1.y][0], nxt[p2.x][p2.y][0]);
			if (j < w - 1){
				p1 = nxt[p1.x][p1.y][1];
				p2 = nxt[p2.x][p2.y][1];
			}
		}
		forn(j, h){
			swap(nxt[nxt[p1.x][p1.y][1].x][nxt[p1.x][p1.y][1].y][3], nxt[nxt[p2.x][p2.y][1].x][nxt[p2.x][p2.y][1].y][3]);
			swap(nxt[p1.x][p1.y][1], nxt[p2.x][p2.y][1]);
			if (j < h - 1){
				p1 = nxt[p1.x][p1.y][2];
				p2 = nxt[p2.x][p2.y][2];
			}
		}
		forn(j, w){
			swap(nxt[nxt[p1.x][p1.y][2].x][nxt[p1.x][p1.y][2].y][0], nxt[nxt[p2.x][p2.y][2].x][nxt[p2.x][p2.y][2].y][0]);
			swap(nxt[p1.x][p1.y][2], nxt[p2.x][p2.y][2]);
			if (j < w - 1){
				p1 = nxt[p1.x][p1.y][3];
				p2 = nxt[p2.x][p2.y][3];
			}
		}
		forn(j, h){
			swap(nxt[nxt[p1.x][p1.y][3].x][nxt[p1.x][p1.y][3].y][1], nxt[nxt[p2.x][p2.y][3].x][nxt[p2.x][p2.y][3].y][1]);
			swap(nxt[p1.x][p1.y][3], nxt[p2.x][p2.y][3]);
			if (j < h - 1){
				p1 = nxt[p1.x][p1.y][0];
				p2 = nxt[p2.x][p2.y][0];
			}
		}
	}
	int fl = 1;
	pt cur = mp(0, 0);
	int x = 0, y = 0;
	forn(i, n + 2){
		forn(j, m + 2){
			

			if (0 < x && x <= n && 0 < y && y <= m)
				ans[x - 1][y - 1] = a[cur.x][cur.y];
			if (j < m + 1){
				cur = nxt[cur.x][cur.y][fl];
				y += dy[fl];
			}
		}
		cur = nxt[cur.x][cur.y][2];
		++x;
		fl ^= 2;
	}
	forn(i, n){
		forn(j, m)
			printf("%d ", ans[i][j]);
		puts("");
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