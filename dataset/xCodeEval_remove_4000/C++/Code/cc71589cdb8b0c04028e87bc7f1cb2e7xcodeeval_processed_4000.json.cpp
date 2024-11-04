



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

const int N = 1000 + 7;

int n;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	s = s.substr(4);
	n = sz(s);
	return true;
}

li lim[] = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
string pr1[] = {"", "198", "19", "2", "", "", "", "", "", ""};
string pr2[] = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

string solve() {
	li x = atoll(s.c_str());
	if (x >= lim[n])
		return pr1[n] + s;
	else
		return pr2[n] + s;
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

		puts(solve().c_str());
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}