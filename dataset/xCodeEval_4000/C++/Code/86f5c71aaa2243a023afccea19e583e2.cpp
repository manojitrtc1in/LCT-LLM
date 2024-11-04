

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

const int N = 1000 + 7;

int n;
string s;
int k;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%d", &k);
	return true;
}

int cnt[26];

bool check(int i){
	int req = 0;
	forn(j, 26)
		req += (cnt[j] + i - 1) / i;
	return req <= k;
}

void solve() {
	memset(cnt, 0, sizeof(cnt));
	forn(i, n) ++cnt[s[i] - 'a'];
	
	int ans = -1;
	int l = 1, r = n * n;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	
	if (ans == -1){
		puts("-1");
		return;
	}
	
	printf("%d\n", ans);
	string res = "";
	forn(j, 26) forn(_, (cnt[j] + ans - 1) / ans)
		res += ('a' + j);
	res += string(k - sz(res), 'a');
	puts(res.c_str());
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