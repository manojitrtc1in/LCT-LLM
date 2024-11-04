
 
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
typedef double ld;
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
 
const int K = 45;
 
typedef pair<ld, ld> point;
 
pt tmp[3];
point a[3];
 
bool read () {
	if (scanf("%d%d%d%d%d%d", &tmp[0].x, &tmp[0].y, &tmp[1].x, &tmp[1].y, &tmp[2].x, &tmp[2].y) != 6)
		return false;
	return true;
}
 
ld g2(const ld &x, const ld &y){
	ld res = 0;
	forn(i, 3) res += sqrt(sqr(x - a[i].x) + sqr(y - a[i].y));
	return res;
}
 
ld f2(ld x){
	ld l = -10000, r = 10000;
	forn(_, K){
		ld m1 = l + (r - l) * 0.45;
		ld m2 = r - (r - l) * 0.45;
		if (g2(x, m1) > g2(x, m2))
			l = m1;
		else
			r = m2;
	}
	return g2(x, (l + r) / 2);
}
 
ld calc2(){
	ld l = -10000, r = 10000;
	forn(_, K){
		ld m1 = l + (r - l) * 0.45;
		ld m2 = r - (r - l) * 0.45;
		if (f2(m1) > f2(m2))
			l = m1;
		else
			r = m2;
	}
	return f2((l + r) / 2);
}
 
ld g(ld x, ld y){
	ld res = 0;
	forn(i, 3){
		a[0] = tmp[i];
		a[1] = tmp[(i + 1) % 3];
		a[2] = {x, y};
		res = max(res, calc2());
	}
	return res;
}
 
ld f(ld x){
	ld l = -10000, r = 10000;
	forn(_, K){
		ld m1 = l + (r - l) * 0.45;
		ld m2 = r - (r - l) * 0.45;
		if (g(x, m1) > g(x, m2))
			l = m1;
		else
			r = m2;
	}
	return g(x, (l + r) / 2);
}
 
ld calc(){
	ld l = -10000, r = 10000;
	forn(_, K){
		ld m1 = l + (r - l) * 0.45;
		ld m2 = r - (r - l) * 0.45;
		if (f(m1) > f(m2))
			l = m1;
		else
			r = m2;
	}
	return f((l + r) / 2);
}
 
void solve() {
	printf("%.15lf\n", calc());
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