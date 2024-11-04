



using namespace std;













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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 + 7;

int n, m;
string s, t;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%s", buf);
	t = buf;
	m = sz(t);
	return true;
}

string get(string s){
	int cnt = count(all(s), 'B') % 2;
	string nw = "";
	forn(i, sz(s)) if (s[i] != 'B') nw += s[i];
	s = nw;
	nw = "";
	forn(i, sz(s)){
		if (nw.empty() || nw.back() != s[i])
			nw += s[i];
		else
			nw.pop_back();
	}
	return nw + string(cnt, 'B');
}

void solve() {
	puts(get(s) == get(t) ? "YES" : "NO");
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}