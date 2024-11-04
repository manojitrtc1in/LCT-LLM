

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

const int N = 1000 * 1000 + 13;
const int LOGN = 21;

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

bool used[N];
int ans[N];

void solve() {
	
	

	

	

	
	memset(used, 0, sizeof(used));
	for (int i = n; i >= 0; --i){
		for (int b = LOGN; b >= 0; --b){
			int num = (1 << b) - 1;
			if ((i ^ num) <= n && !used[i ^ num]){
				ans[i] = i ^ num;
				used[i ^ num] = true;
				break;
			}
		}
	}
	printf("%lld\n", n * li(n + 1));
	li sum = 0;
	forn(i, n + 1){
		printf("%d ", ans[i]);
		sum += i ^ ans[i];
	}
	puts("");
	assert(sum == n * li(n + 1));
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