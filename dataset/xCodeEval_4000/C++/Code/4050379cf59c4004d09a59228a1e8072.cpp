

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

int n;
li a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
	return true;
}

bool used[N];

void solve(){
	memset(used, 0, sizeof(used));
	vector<li> ans;
	for (int i = 59; i >= 0; --i){
		vector<int> nw;
		forn(j, n) if (!used[j] && ((a[j] >> i) & 1))
			nw.pb(j);
		vector<int> pos;
		forn(j, sz(ans)) if ((ans[j] >> i) & 1)
			pos.pb(j);
		pos.pb(sz(ans));
		if (sz(nw) > sz(pos)){
			puts("No");
			return;
		}
		vector<li> fin;
		for (int j = 0, k = 0; j < sz(ans) || k < sz(nw);){
			if (k < sz(nw) && sz(fin) - k == pos[k]){
				fin.pb(a[nw[k]]);
				used[nw[k]] = true;
				++k;
			}
			else{
				fin.pb(ans[j]);
				++j;
			}
		}
		ans = fin;
	}
	
	puts("Yes");
	for (auto it : ans)
		printf("%lld ", it);
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