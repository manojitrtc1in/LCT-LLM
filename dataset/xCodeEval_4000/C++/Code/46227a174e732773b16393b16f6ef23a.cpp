

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

const int N = 100 * 1000 + 13;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int pr[N];

void solve() {
	forn(i, n) pr[i + 1] = pr[i] + (a[i] == 1);
	vector<pt> ans;
	fore(t, 1, n + 1){
		int cnt1 = 0, cnt2 = 0;
		int lst = 0;
		for (int i = 0; i < n;){
			int l = i, r = n - 1;
			int res = INF;
			while (l <= r){
				int m = (l + r) / 2;
				if (pr[m + 1] - pr[i] >= t || (m - i + 1) - (pr[m + 1] - pr[i]) >= t){
					res = m;
					r = m - 1;
				}
				else{
					l = m + 1;
				}
			}
			if (res == INF){
				cnt1 = cnt2 = -INF;
				break;
			}
			int s1 = pr[res + 1] - pr[i];
			int s2 = (res - i + 1) - s1;
			assert(s1 != s2);
			if (s1 == t){
				++cnt1;
				lst = cnt1;
			}
			else{
				assert(s2 == t);
				++cnt2;
				lst = cnt2;
			}
			i = res + 1;
		}
		if (cnt1 != cnt2 && lst == max(cnt1, cnt2)){
			ans.pb(mp(max(cnt1, cnt2), t));
		}
	}
	sort(all(ans));
	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d\n", it.x, it.y);
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