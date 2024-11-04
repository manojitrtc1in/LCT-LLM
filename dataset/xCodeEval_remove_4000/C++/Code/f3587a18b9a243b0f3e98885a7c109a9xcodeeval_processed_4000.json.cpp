



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

int n;
pair<li, li> a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld%lld", &a[i].x, &a[i].y);
	return true;
}

bool lose(li l, li r){
	for (li i = r;; i /= 4){
		if (i / 2 % 2 == 1 || l > i / 4){
			if (l > i / 2)
				return true;
			return l % 2 != i / 2 % 2;
		}
	}
}

bool win(li l, li r){
	for (li i = r;; i /= 4){
		if (i % 2 == 1)
			return !(l % 2);
		if (l > i / 4){
			if (l > i / 2)
				return l % 2 != i % 2;
			return true;
		}
	}
}

void solve() {
	int w = 0, l = 1;
	forn(i, n){
		int nw = 0, nl = 0;
		li x = a[i].x, y = a[i].y;
		if (l){
			nw |= win(x, y);
			nl |= lose(x, y);
		}
		if (w){
			nw |= !win(x, y);
			nl |= !lose(x, y);
		}
		w = nw, l = nl;
	}
	printf("%d %d\n", w, l);
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