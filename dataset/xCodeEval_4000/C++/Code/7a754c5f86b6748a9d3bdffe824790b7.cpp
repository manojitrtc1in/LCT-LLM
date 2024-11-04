

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

const int N = 200 * 1000 + 13;

int n, t;
string s;

bool read () {
	if (scanf("%d%d", &n, &t) != 2)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

void solve() {
	vector<int> pos;
	int st = s.find('.') + 1;
	fore(i, st, n) if (s[i] >= '5')
		pos.pb(i);
	
	if (pos.empty()){
		puts(s.c_str());
		return;
	}
	
	pos.resize(1);
	
	forn(_, t){
		if (pos.empty()) break;
		int i = pos.back();
		while (sz(s) > i + 1)
			s.pop_back();
		++s[i - 1];
		pos.pop_back();
		if (s[i - 1] == '5')
			pos.pb(i - 1);
		s.pop_back();
	}
	
	while (s.back() == '9' + 1){
		s.pop_back();
		++s.back();
	}
	
	if (s.back() == '.' + 1){
		s.pop_back();
		if (s.empty())
			s = '0';
		++s.back();
		for (int i = sz(s) - 1; i >= 0 && s[i] == '9' + 1; --i){
			s[i] = '0';
			if (i == 0)
				s = '1' + s;
			else
				++s[i - 1];
		}
	}
	
	puts(s.c_str());
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