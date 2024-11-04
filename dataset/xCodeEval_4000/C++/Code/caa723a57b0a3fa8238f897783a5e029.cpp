

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

const int N = 300 * 1000 + 13;

int n, w;
int a[N], b[N];

bool read () {
	if (scanf("%d%d", &n, &w) != 2)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i], &b[i]);
	return true;
}

int ans[N];
set<pt> add, p0;
set<pt, greater<pt>> rem, p2;

void addi(int i){
	++ans[i];
	if (ans[i] == 1){
		p0.erase(mp(b[i], i));
		add.erase(mp(a[i], i));
		add.insert(mp(b[i] - a[i], i));
		rem.insert(mp(a[i], i));
	}
	else{
		p2.insert(mp(b[i], i));
		add.erase(mp(b[i] - a[i], i));
		rem.erase(mp(a[i], i));
		rem.insert(mp(b[i] - a[i], i));
	}
}

void remi(int i){
	--ans[i];
	if (ans[i] == 1){
		p2.erase(mp(b[i], i));
		rem.erase(mp(b[i] - a[i], i));
		add.insert(mp(b[i] - a[i], i));
		rem.insert(mp(a[i], i));
	}
	else{
		p0.insert(mp(b[i], i));
		rem.erase(mp(a[i], i));
		add.erase(mp(b[i] - a[i], i));
		add.insert(mp(a[i], i));
	}
}

bool ok(pt &it, pt &jt){
	if (add.empty() || rem.empty())
		return false;
	if (add.begin()->y != rem.begin()->y){
		if (add.begin()->x >= rem.begin()->x)
			return false;
		it = *add.begin();
		jt = *rem.begin();
		return true;
	}
	int mn1 = 0, mn2 = 0;
	if (sz(add) > 1) mn1 = (++add.begin())->x - rem.begin()->x;
	if (sz(rem) > 1) mn2 = add.begin()->x - (++rem.begin())->x;
	if (min(mn1, mn2) >= 0)
		return false;
	if (mn1 < mn2){
		it = *(++add.begin());
		jt = *rem.begin();
	}
	else{
		it = *add.begin();
		jt = *(++rem.begin());
	}
	return true;
}

li solve() {
	add.clear();
	rem.clear();
	p0.clear();
	p2.clear();
	forn(i, n){
		ans[i] = 0;
		add.insert(mp(a[i], i));
		p0.insert(mp(b[i], i));
	}
	li tot = 0;
	forn(_, w){
		int i = add.begin()->y;
		tot += add.begin()->x;
		add.erase(add.begin());
		addi(i);
	}
	pt it, jt;
	while (true){
		bool chg = false;
		while (ok(it, jt)){
			tot += it.x - jt.x;
			addi(it.y);
			remi(jt.y);
			chg = true;
		}
		while (!p0.empty() && !p2.empty() && p0.begin()->x < p2.begin()->x){
			tot += p0.begin()->x - p2.begin()->x;
			int i = p0.begin()->y;
			int j = p2.begin()->y;
			addi(i); addi(i);
			remi(j); remi(j);
			chg = true;
		}
		while (!p2.empty() && sz(add) > 1 && add.begin()->x + (++add.begin())->x < p2.begin()->x){
			tot += add.begin()->x + (++add.begin())->x - p2.begin()->x;
			int i = add.begin()->y;
			int j = (++add.begin())->y;
			int k = p2.begin()->y;
			addi(i);
			addi(j);
			remi(k); remi(k);
			chg = true;
		}
		while (!p0.empty() && sz(rem) > 1 && p0.begin()->x < rem.begin()->x + (++rem.begin())->x){
			tot += p0.begin()->x - rem.begin()->x - (++rem.begin())->x;
			int i = rem.begin()->y;
			int j = (++rem.begin())->y;
			int k = p0.begin()->y;
			remi(i);
			remi(j);
			addi(k); addi(k);
			chg = true;
		}
		if (!chg) break;
	}
	

	

	

	return tot;
}

li res;

void brute(int x, int cnt, li pr){
	if (pr >= res)
		return;
	if (x == n){
		if (cnt == w)
			res = pr;
		return;
	}
	brute(x + 1, cnt, pr);
	if (cnt + 1 <= w)
		brute(x + 1, cnt + 1, pr + a[x]);
	if (cnt + 2 <= w)
		brute(x + 1, cnt + 2, pr + b[x]);
}

li naive(){
	res = INF64;
	brute(0, 0, 0);
	return res;
}

bool gen(){
	n = rnd() % 4 + 1;
	w = rnd() % (2 * n) + 1;
	forn(i, n){
		a[i] = rnd() % 5 + 1;
		b[i] = a[i] + rnd() % 5 + 1;
	}
	return true;
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
		li ans1 = solve();
		
		printf("%lld\n", ans1);
		forn(i, n)
			printf("%d", ans[i]);
		puts("");
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}