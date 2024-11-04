

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

const int N = 200 * 1000 + 13;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

pt p[N][5];
pt dp[N][5];

void paint(int l, int r, int clr, int nxt){
	while (l < r){
		fore(i, 2, 6){
			if ((r - l - i) >= 2 * (nxt - clr - 1) && (r - l - i) <= 5 * (nxt - clr - 1)){
				forn(_, i)
					a[l++] = clr;
				++clr;
				break;
			}
		}
	}
}

void solve() {
	int lst = -1;
	int pos = -1;
	forn(i, n){
		if (a[i] == -1) continue;
		if (a[i] < lst){
			puts("-1");
			return;
		}
		if (a[i] == lst){
			fore(j, pos + 1, i)
				a[j] = a[i];
		}
		else{
			lst = a[i];
		}
		pos = i;
	}
	
	forn(i, n){
		if (a[i] == -1) continue;
		int j = i;
		while (j + 1 < n && a[j + 1] == a[i])
			++j;
		if (j - i + 1 > 5){
			puts("-1");
			return;
		}
		i = j;
	}
	
	memset(dp, -1, sizeof(dp));
	vector<int> ok(1, 0);
	int prv = -1;
	pos = -1;
	int posi = -1;
	forn(i, n){
		if (a[i] == -1) continue;
		int j = i;
		while (j + 1 < n && a[j + 1] == a[j])
			++j;
		int dif = a[j] - prv - 1;
		int len = j - i + 1;
		
		vector<int> nw;
		forn(r, 5 - len + 1){
			if (j + r == n || (a[j + r] != a[i] && a[j + r] != -1))
				break;
			bool found = false;
			forn(l, 5 - len - r + 1){
				if (i - l < 0 || (a[i - l] != a[i] && a[i - l] != -1))
					break;
				if (len + l + r < 2)
					continue;
				for (auto it : ok){
					int dist = (i - l) - (pos + it) - 1;
					if (dist < 2 * dif || dist > 5 * dif)
						continue;
					found = true;
					dp[i][r] = mp(l, j);
					p[i][r] = mp(posi, it);
				}
			}
			if (found){
				nw.pb(r);
			}
		}
		
		if (nw.empty()){
			puts("-1");
			return;
		}
		ok = nw;
		
		posi = i;
		pos = j;
		prv = a[i];
		i = j;
	}
	
	int i = posi;
	int r = ok[0];
	if (r == 0 && sz(ok) == 1 && i != -1 && dp[i][r].y == i && dp[i][r].x == 0){
		puts("-1");
		return;
	}
	if (r == 0 && i != -1 && dp[i][r].x == 0 && dp[i][r].y == i){
		r = ok[1];
	}
	
	if (n - (i == -1 ? 0 : dp[i][ok[0]].y + r + 1) == 1){
		if (r == ok.back()){
			puts("-1");
			return;
		}
		assert(pos != -1);
		r = ok.back();
	}
	
	paint(pos + r + 1, n, pos == -1 ? 0 : a[pos] + 1, (pos == -1 ? -1 : a[pos]) + (n - (pos + r) + 1) / 2);
	
	while (i != -1){
		int l = dp[i][r].x;
		int j = dp[i][r].y;
		fore(k, i - l, i)
			a[k] = a[i];
		fore(k, j, j + r + 1)
			a[k] = a[j];
		int nxt = p[i][r].x;
		int nr = p[i][r].y;
		int npos = (nxt == -1 ? -1 : dp[nxt][nr].y);
		paint(npos + nr + 1, i - l, nxt == -1 ? 0 : a[nxt] + 1, a[i]);
		i = nxt;
		r = nr;
	}
	
	printf("%d\n", a[n - 1] + 1);
	forn(i, n)
		printf("%d ", a[i] + 1);
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