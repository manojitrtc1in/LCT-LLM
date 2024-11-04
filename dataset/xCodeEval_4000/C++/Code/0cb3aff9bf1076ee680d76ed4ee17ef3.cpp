

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
typedef pair<li, li> pt;
 
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
 
vector<li> a;
 
bool read () {
	a.resize(3);
	if (scanf("%lld%lld%lld", &a[0], &a[1], &a[2]) != 3)
		return false;
	return true;
}

li get0(vector<li> a){
	sort(all(a));
	return a[1] - a[0];
}

li get1(vector<li> a){
	sort(all(a));
	return a[2] - a[1];
}

li get2(vector<li> a){
	sort(all(a));
	return a[2] - a[0];
}

li get3(vector<li> a){
	sort(all(a));
	return 2 * a[2] - a[1] - a[0];
}

int mn(vector<li> a){
	return min_element(all(a)) - a.begin();
}

int mx(vector<li> a){
	return max_element(all(a)) - a.begin();
}

void solve() {
	puts("First");
	fflush(stdout);
	li y;
	printf("%lld\n", y = get3(a));
	fflush(stdout);
	int x;
	forn(i, 1000){
		scanf("%d", &x);
		--x;
		if (x == -1) return;
		li z;
		if (x == mn(a)){
			printf("%lld\n", z = get1(a));
			a[x] += y;
		}
		else if (x != mx(a)){
			printf("%lld\n", z = get2(a));
			a[x] += y;
		}
		else{
			a[x] += y;
			printf("%lld\n", z = get3(a));
		}
		fflush(stdout);
		y = z;
	}
}
 
int main() {
#ifdef _DEBUG




	
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
