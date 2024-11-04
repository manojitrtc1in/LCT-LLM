

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

const int N = 11;

struct ball{
	int i;
	ld x, v, m;
	ball(){};
};

int n, t;
ball a[N];

bool read () {
	if (scanf("%d%d", &n, &t) != 2)
		return false;
	forn(i, n){
		a[i].i = i;
		scanf("%Lf%Lf%Lf", &a[i].x, &a[i].v, &a[i].m);
	}
	return true;
}

void solve() {
	ld cur = 0;
	while (t - cur > EPS){
		ld nxt = INF;
		vector<pt> chg;
		
		sort(a, a + n, [](ball a, ball b){
			if (fabsl(a.x - b.x) > EPS)
				return a.x < b.x;
			return a.v < b.v;
		});
		
		forn(j, n) forn(i, j){
			ld v1 = a[i].v;
			ld v2 = a[j].v;
			ld fv1 = fabsl(v1);
			ld fv2 = fabsl(v2);
			
			if (v1 < -EPS && v2 < -EPS){
				if (fv1 > fv2 - EPS) continue;
				ld tim = (a[j].x - a[i].x) / (fv2 - fv1);
				if (cur + tim < nxt - EPS)
					chg.clear();
				if (cur + tim < nxt + EPS){
					nxt = cur + tim;
					chg.pb(mp(i, j));
				}
			}
			else if (v1 < -EPS && v2 > EPS){
				continue;
			}
			else if (v1 > EPS && v2 < -EPS){
				ld tim = (a[j].x - a[i].x) / (fv1 + fv2);
				if (cur + tim < nxt - EPS)
					chg.clear();
				if (cur + tim < nxt + EPS){
					nxt = cur + tim;
					chg.pb(mp(i, j));
				}
			}
			else if (v1 > EPS && v2 > EPS){
				if (fv2 > fv1 - EPS) continue;
				ld tim = (a[j].x - a[i].x) / (fv1 - fv2);
				if (cur + tim < nxt - EPS)
					chg.clear();
				if (cur + tim < nxt + EPS){
					nxt = cur + tim;
					chg.pb(mp(i, j));
				}
			}
		}
		
		bool fl = true;
		if (nxt > t){
			nxt = t;
			fl = false;
		}
		
		forn(i, n)
			a[i].x += a[i].v * (nxt - cur);
		
		if (fl){
			for (auto bst : chg){
				ld v1 = a[bst.x].v, v2 = a[bst.y].v;
				ld m1 = a[bst.x].m, m2 = a[bst.y].m;
				a[bst.x].v = ((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2);
				a[bst.y].v = ((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2);
			}
		}
		
		
		
		cur = nxt;
		
		

	}
	
	

	
	vector<ld> ans(n);
	forn(i, n) ans[a[i].i] = a[i].x;
	
	forn(i, n)
		printf("%.15Lf\n", ans[i]);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(4);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef _DEBUG
	while(read()) {	
#else
	if(read()) {
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}