

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

int n, k;
string s;

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

set<int> pos[2];

void solve() {
	bool fl = false;
	forn(y, 2){
		forn(i, 2) pos[i].clear();
		forn(i, n) pos[s[i] - '0'].insert(i);
		
		forn(i, n){
			if (s[i] - '0' != y){
				pos[!y].erase(i);
				pos[y].insert(i);
			}
			
			if (i >= k && s[i - k] - '0' != y){
				pos[y].erase(i - k);
				pos[!y].insert(i - k);
			}
			
			if (i < k - 1) continue;
		
			if (pos[0].empty() || pos[1].empty()){
				puts("tokitsukaze");
				return;
			}
			
			bool cur = true;
			forn(z, 2)
				cur &= (*pos[z].rbegin() - *pos[z].begin() + 1 > k);
			fl |= cur;
		}
	}
	
	puts(fl ? "once again" : "quailty");
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