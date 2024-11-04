

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

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

bool wl[22][360][4];
bool used[22][360];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
	static char buf[10];
	memset(wl, 0, sizeof(wl));
	forn(_, n){
		int x, l, r;
		scanf("%s", buf);
		if (buf[0] == 'C'){
			scanf("%d%d%d", &x, &l, &r);
			while (l != r){
				wl[x - 1][l][1] = true;
				wl[x][l][3] = true;
				l = (l + 1) % 360;
			}
		}
		else{
			scanf("%d%d%d", &l, &r, &x);
			fore(i, l, r){
				wl[i][(x + 359) % 360][0] = true;
				wl[i][x][2] = true;
			}
		}
	}
	memset(used, 0, sizeof(used));
	used[0][0] = true;
	queue<pt> q;
	q.push({0, 0});
	while (!q.empty()){
		int r = q.front().x;
		int a = q.front().y;
		q.pop();
		if (r == 21){
			puts("YES");
			return;
		}
		forn(i, 4) if (!wl[r][a][i]){
			int nr = r + dx[i];
			int na = (a + dy[i] + 360) % 360;
			if (nr < 0 || used[nr][na]) continue;
			used[nr][na] = true;
			q.push({nr, na});
		}
	}
	puts("NO");
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