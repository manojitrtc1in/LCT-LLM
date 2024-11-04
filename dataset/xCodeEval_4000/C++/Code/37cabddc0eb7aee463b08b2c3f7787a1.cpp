

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

const int N = 2000 + 7;

int n, s;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &s) != 2)
		return false;
	--s;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int dp[N];
pt p[N];
vector<int> pos[N];

void solve() {
	vector<int> xs(a, a + n);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	forn(i, n) a[i] = lower_bound(all(xs), a[i]) - xs.begin();
	forn(i, n) pos[i].clear();
	forn(i, n) pos[a[i]].pb(i);
	forn(i, n) dp[i] = INF;
	
	if (sz(pos[0]) == 1){
		int nval = min(abs(s - pos[0][0]), n - abs(s - pos[0][0]));
		if (dp[pos[0][0]] > nval){
			dp[pos[0][0]] = nval;
			p[pos[0][0]] = mp(s, 0);
		}
	}
	else{
		forn(i, sz(pos[0])){
			int ni = (i + 1) % sz(pos[0]);
			int nval = min(abs(s - pos[0][i]), n - abs(s - pos[0][i])) + (n - (pos[0][ni] - pos[0][i] + n) % n);
			if (dp[pos[0][ni]] > nval){
				dp[pos[0][ni]] = nval;
				p[pos[0][ni]] = mp(s, -1);
			}
		}
		forn(i, sz(pos[0])){
			int pi = (i - 1 + sz(pos[0])) % sz(pos[0]);
			int nval = min(abs(s - pos[0][i]), n - abs(s - pos[0][i])) + (n - (pos[0][i] - pos[0][pi] + n) % n);
			if (dp[pos[0][pi]] > nval){
				dp[pos[0][pi]] = nval;
				p[pos[0][pi]] = mp(s, 1);
			}
		}
	}
	
	fore(x, 1, n){
		if (sz(pos[x]) == 1){
			for (auto s : pos[x - 1]){
				int nval = dp[s] + min(abs(s - pos[x][0]), n - abs(s - pos[x][0]));
				if (dp[pos[x][0]] > nval){
					dp[pos[x][0]] = nval;
					p[pos[x][0]] = mp(s, 0);
				}
			}
		}
		else{
			for (auto s : pos[x - 1]){
				forn(i, sz(pos[x])){
					int ni = (i + 1) % sz(pos[x]);
					int nval = dp[s] + min(abs(s - pos[x][i]), n - abs(s - pos[x][i])) + (n - (pos[x][ni] - pos[x][i] + n) % n);
					if (dp[pos[x][ni]] > nval){
						dp[pos[x][ni]] = nval;
						p[pos[x][ni]] = mp(s, -1);
					}
				}
				forn(i, sz(pos[x])){
					int pi = (i - 1 + sz(pos[x])) % sz(pos[x]);
					int nval = dp[s] + min(abs(s - pos[x][i]), n - abs(s - pos[x][i])) + (n - (pos[x][i] - pos[x][pi] + n) % n);
					if (dp[pos[x][pi]] > nval){
						dp[pos[x][pi]] = nval;
						p[pos[x][pi]] = mp(s, 1);
					}
				}
			}
		}
	}
	
	int ans = INF;
	int bst = -1;
	for (auto x : pos[sz(xs) - 1]) if (dp[x] < ans){
		ans = dp[x];
		bst = x;
	}
	
	vector<int> res;
	for (int x = sz(xs) - 1; x >= 0; --x){
		int dir = p[bst].y;
		int dest = p[bst].x;
		if (dir == -1){
			auto it = find(all(pos[x]), bst);
			rotate(pos[x].begin(), it, pos[x].end());
			forn(i, sz(pos[x]) - 1)
				res.pb(-((pos[x][i + 1] - pos[x][i] + n) % n));
			bst = pos[x].back();
		}
		else if (dir == 1){
			auto it = find(all(pos[x]), bst);
			if (it + 1 == pos[x].end()) it = pos[x].begin();
			else it = it + 1;
			rotate(pos[x].begin(), it, pos[x].end());
			for (int i = sz(pos[x]) - 1; i > 0; --i)
				res.pb((pos[x][i] - pos[x][i - 1] + n) % n);
			bst = pos[x][0];
		}
		if ((bst - dest + n) % n < (dest - bst + n) % n){
			res.pb((bst - dest + n) % n);
		}
		else{
			res.pb(-((dest - bst + n) % n));
		}
		bst = dest;
	}
	
	printf("%d\n", ans);
	reverse(all(res));
	for (auto it : res){
		if (it >= 0) printf("+");
		printf("%d\n", it);
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}