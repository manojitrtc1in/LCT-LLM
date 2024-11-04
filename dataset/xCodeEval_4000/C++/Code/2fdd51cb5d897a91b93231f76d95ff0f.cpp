

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

const int INF = int(1e9) + 1334734;
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;

int n, k;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	static char buf[20];
	forn(i, n){
		scanf("%s", buf);
		if (buf[0] == '?')
			a[i] = INF;
		else
			a[i] = atoi(buf);
	}
	return true;
}

bool calc(int x){
	vector<int> nums;
	for (int i = x; i < n; i += k)
		nums.pb(a[i]);
	
	int lst = -INF;
	vector<int> pos;
	forn(i, sz(nums)) if (nums[i] != INF){
		lst = nums[i];
		pos.pb(i);
	}
	
	nums.pb(INF);
	pos.pb(sz(nums) - 1);
	
	lst = -INF;
	int pi = -1;
	int lpos = 0;
	for (auto i : pos){
		if (nums[i] - lst < i - pi)
			return false;
		int st;
		if (nums[i] < 0)
			st = nums[i] - (i - pi - 1);
		else if (lst > 0)
			st = lst + 1;
		else
			st = max(lst + 1, min(-((i - pi - 1) / 2), nums[i] - (i - pi - 1)));
		for (; lpos < i; ++lpos, ++st)
			a[lpos * k + x] = st;
		lst = nums[i];
		pi = i;
		++lpos;
	}
	return true;
}

void solve() {
	forn(i, k) if (!calc(i)){
		puts("Incorrect sequence");
		return;
	}
	forn(i, n) printf("%d ", a[i]);
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