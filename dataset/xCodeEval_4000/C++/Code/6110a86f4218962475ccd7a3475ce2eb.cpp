

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

int n, m, k;
li h;
pair<li, int> a[N];

bool read () {
	if (scanf("%lld%d%d%d", &h, &n, &m, &k) != 4)
		return false;
	forn(i, n)
		scanf("%lld%d", &a[i].x, &a[i].y);
	return true;
}

bool used[N];
li mn[N];
set<pt, greater<pt>> cur;

void add(li x){
	queue<int> q;
	forn(i, k) q.push(i);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		if (mn[v] + x < mn[(v + x) % k]){
			mn[(v + x) % k] = mn[v] + x;
			q.push((v + x) % k);
		}
	}
}

void recalc(){
	cur.clear();
	forn(i, n) if (!used[i] && mn[a[i].x % k] <= a[i].x)
		cur.insert(mp(a[i].y, -i));
}

void solve() {
	forn(i, k)
		mn[i] = h + 1;
	mn[1] = 1;
	memset(used, 0, sizeof(used));
	recalc();
	forn(i, m){
		int t;
		scanf("%d", &t);
		if (t == 1){
			li x;
			scanf("%lld", &x);
			add(x);
			recalc();
		}
		else if (t == 2){
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			if (mn[a[x].x % k] <= a[x].x)
				cur.erase(mp(a[x].y, -x));
			a[x].y -= y;
			if (mn[a[x].x % k] <= a[x].x)
				cur.insert(mp(a[x].y, -x));
		}
		else if (!cur.empty()){
			printf("%d\n", cur.begin()->x);
			used[-cur.begin()->y] = true;
			cur.erase(cur.begin());
		}
		else{
			puts("0");
		}
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