

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
const int AL = 26;

int n;
string s[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

string cur[AL];

bool issuf(const string &a, const string &b){
	forn(i, sz(a)) if (a[sz(a) - i - 1] != b[sz(b) - i - 1])
		return false;
	return true;
}

bool ispref(const string &a, const string &b){
	forn(i, sz(a)) if (a[i] != b[i])
		return false;
	return true;
}

void solve(){
	forn(i, n) forn(j, AL) if (count(all(s[i]), 'a' + j) > 1){
		puts("NO");
		return;
	}
	
	forn(i, AL) cur[i] = "";
	forn(i, n){
		set<string> nw;
		for (auto c : s[i]) if (cur[c - 'a'] != "")
			nw.insert(cur[c - 'a']);
		string tmp = s[i];
		for (auto it : nw){
			int p1, p2;
			forn(i, AL) if ((p1 = it.find(i + 'a')) != -1 && (p2 = tmp.find(i + 'a')) != -1){
				string l1 = it.substr(0, p1);
				string r1 = it.substr(p1);
				string l2 = tmp.substr(0, p2);
				string r2 = tmp.substr(p2);
				if (sz(l1) < sz(l2)) swap(l1, l2);
				if (sz(r1) < sz(r2)) swap(r1, r2);
				if (issuf(l2, l1) && ispref(r2, r1))
					tmp = l1 + r1;
				else{
					puts("NO");
					return;
				}
				forn(j, AL) if (count(all(tmp), 'a' + j) > 1){
					puts("NO");
					return;
				}
				break;
			}
		}
		for (auto c : tmp) cur[c - 'a'] = tmp;
	}
	
	set<string> res;
	forn(i, AL) res.insert(cur[i]);
	for (auto it : res) printf("%s", it.c_str());
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