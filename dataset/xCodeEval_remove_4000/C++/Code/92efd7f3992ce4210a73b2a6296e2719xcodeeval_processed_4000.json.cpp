



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

const int N = 100 * 1000 + 13;

int n, a, b, c;
string s;

bool read () {
	if (scanf("%d%d%d%d", &n, &a, &b, &c) != 4)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

void solve() {
	vector<pt> lens;
	int fr = 0;
	forn(i, n){
		int j = i;
		while (j + 1 < n && s[j + 1] == s[i])
			++j;
		if (s[i] == '0'){
			if (i == 0 || j == n - 1)
				lens.pb(mp(1, j - i + 1));
			else
				lens.pb(mp(0, j - i + 1));
		}
		else{
			fr += j - i;
		}
		i = j;
	}
	sort(all(lens));
	int mva = 0;
	for (pt it : lens) mva += it.y - 1;
	int mvtr = 0;
	for (pt it : lens) if (it.x == 1) ++mvtr;
	li ans = 0;
	forn(z, 2){
		int curfr = fr;
		int sva = mva, svtr = mvtr, cura = 0;
		li res = 0;
		queue<int> cs;
		for (pt it : lens) if (it.x == 0) cs.push(it.y - 1);
		for (int i = z;; i ^= 1){
			if (i == 0){
				if (sva > 0){
					--sva;
					++cura;
					res += a;
				}
				else if (!cs.empty() && cura >= cs.front()){
					cura -= cs.front();
					cs.pop();
					res -= c;
					++curfr;
				}
				else if (svtr > 0){
					--svtr;
					res -= c;
				}
				else{
					break;
				}
			}
			else{
				if (curfr == 0){
					if (cs.empty() || cura < cs.front() + 1) break;
					cura -= cs.front() + 1;
					cs.pop();
					++sva;
					res = (res - a - c + b);
				}
				else{
					res += b;
					--curfr;
				}
			}
			ans = max(ans, res);
		}
	}
	printf("%lld\n", ans);
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