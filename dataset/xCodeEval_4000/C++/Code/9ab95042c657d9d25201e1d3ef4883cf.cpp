

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

const int N = 250 * 1000 + 13;
const int M = 1000 * 1000 + 13;

int n;
li a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
	return true;
}

int primes[N];
int cnt;

void sieve(){
	static bool prime[M];
	memset(prime, 0, sizeof(prime));
	cnt = 0;
	fore(i, 2, M){
		if (prime[i]) continue;
		primes[cnt++] = i;
		for (li j = i * li(i); j < M; j += i)
			prime[j] = true;
	}
}

li ans;
map<li, li> used;

li check(li x){
	if (used.count(x))
		return used[x];
	li res = 0;
	forn(i, n){
		li val = a[i] % x;
		if (a[i] >= x)
			res += min(val, x - val);
		else
			res += x - val;
		if (res >= ans)
			break;
	}
	used[x] = res;
	return res;
}

bool get(int tt){
	static int cnt = 0;
	++cnt;
	if (cnt & 63) return true;
	return clock() - tt < 2300;
}

void solve(){
	sieve();
	int tt = clock();
	used.clear();
	ans = INF64;
	ans = min(ans, check(2));
	while (get(tt)){
		li x = a[rnd() % n];
		for (int k1 = -1; k1 <= 1; ++k1) if (x + k1 > 0){
			li g = x + k1;
			forn(i, cnt) if (g % primes[i] == 0){
				while (g % primes[i] == 0) g /= primes[i];
				ans = min(ans, check(primes[i]));
			}
			if (g > 1){
				ans = min(ans, check(g));
			}
		}
	}
	printf("%lld\n", ans);
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