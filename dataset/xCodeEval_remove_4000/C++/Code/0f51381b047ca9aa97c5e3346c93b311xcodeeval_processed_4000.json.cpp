



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

const int N = 200 * 1000 + 13;

int n;
string s[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[10];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

void solve() {
	li S = 1;
	int w = 1, h = 1;
	forn(i, n){
		if (sz(s[i]) == 4){
			S += w + h + 1;
			++w;
			++h;
		}
		else if (s[i] == "UR" || s[i] == "DL"){
			S += w;
			++h;
		}
		else{
			S += h;
			++w;
		}
	}
	printf("%lld\n", S);
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