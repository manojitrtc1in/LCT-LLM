

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

const int N = 2000 + 7;

struct point{
	int x, y, i;
	point(){};
	point(int x, int y, int i) : x(x), y(y), i(i) {};
};

ostream& operator << (ostream& out, const point &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

bool operator <(const point &a, const point &b){
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

int n;
point a[N];
string s;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].i = i + 1;
	}
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

point operator -(point a, point b){
	return point(a.x - b.x, a.y - b.y, -1);
}

point operator +(point a, point b){
	return point(a.x + b.x, a.y + b.y, -1);
}

bool operator ==(point a, point b){
	return (a.x == b.x && a.y == b.y);
}

li sdist(point a, point b){
	return sqr(li(a.x - b.x)) + sqr(li(a.y - b.y));
}

li dot(point a, point b){
	return a.x * li(b.x) + a.y * li(b.y);
}

li cross(point a, point b){
	return a.x * li(b.y) - a.y * li(b.x);
}

vector<point> build(){
	if (n <= 1) 
		return vector<point>(a, a + n);
	
	vector<point> up, dw;
	up.pb(a[0]);
	dw.pb(a[0]);
	
	fore(i, 1, n){
		

		if (i == n - 1 || cross(a[n - 1] - a[0], a[i] - a[0]) >= 0){
			while (sz(up) > 1 && cross(a[i] - up[sz(up) - 2], up.back() - up[sz(up) - 2]) < 0)
				up.pop_back();
			up.pb(a[i]);
		}
		if (i == n - 1 || cross(a[n - 1] - a[0], a[i] - a[0]) < 0){
			while (sz(dw) > 1 && cross(a[i] - dw[sz(dw) - 2], dw.back() - dw[sz(dw) - 2]) > 0)
				dw.pop_back();
			dw.pb(a[i]);
		}
	}
	
	vector<point> res = up;
	for (int i = sz(dw) - 2; i >= 1; --i)
		res.pb(dw[i]);
	
	return res;
}

vector<point> chs[N];

void solve() {
	sort(a, a + n);
	vector<point> ans;
	
	auto ch = build();
	ans.pb(ch[0]);
	if (s[0] == 'L')
		ans.pb(ch.back());
	else
		ans.pb(ch[1]);
	
	forn(i, sz(s)){
		int x = find(a, a + n, ans[sz(ans) - 2]) - a;
		fore(j, x + 1, n) a[j - 1] = a[j];
		--n;
		auto ch = build();
		int pos = find(all(ch), ans.back()) - ch.begin();
		if (s[i + 1] == 'L')
			ans.pb(ch[(pos - 1 + sz(ch)) % sz(ch)]);
		else
			ans.pb(ch[(pos + 1) % sz(ch)]);
	}
	
	for (auto it : ans)
		printf("%d ", it.i);
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