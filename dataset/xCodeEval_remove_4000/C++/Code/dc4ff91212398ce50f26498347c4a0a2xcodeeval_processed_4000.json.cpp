



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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 + 7;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

void solve() {
	while (true){
		bool p1 = false, p2 = false;
		forn(i, n){
			int t = (a[i].x + a[i].y) & 1;
			if (t) p1 = true;
			else p2 = true;
		}
		if (!p1 || !p2){
			forn(i, n){
				a[i] = mp(a[i].x + a[i].y, a[i].x - a[i].y);
				if (a[i].x & 1) ++a[i].x, ++a[i].y;
				a[i].x /= 2, a[i].y /= 2;
			}
		}
		else{
			break;
		}
	}
	vector<int> res;
	forn(i, n) if ((a[i].x + a[i].y) & 1)
		res.pb(i);
	printf("%d\n", sz(res));
	for (auto it : res)
		printf("%d ", it + 1);
	puts("");
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}