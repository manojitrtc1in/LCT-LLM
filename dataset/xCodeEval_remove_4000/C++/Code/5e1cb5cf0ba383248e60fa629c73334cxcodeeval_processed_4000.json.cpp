



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

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

void solve() {
	static char buf[30];
	string bst = "";
	int score = -INF;
	forn(i, n){
		string s;
		scanf("%s", buf);
		s = buf;
		int x, y;
		int cur = 0;
		scanf("%d%d", &x, &y);
		cur = x * 100 - y * 50;
		forn(j, 5){
			scanf("%d", &x);
			cur += x;
		}
		if (cur > score){
			score = cur;
			bst = s;
		}
	}
	cerr << score << endl;
	puts(bst.c_str());
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