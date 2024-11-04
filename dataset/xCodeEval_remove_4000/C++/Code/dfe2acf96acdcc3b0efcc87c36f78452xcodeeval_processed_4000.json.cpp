



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
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

void solve() {
	int mx = max_element(a, a + n) - a;
	int mn = min_element(a, a + n) - a;
	if (a[mn] == a[mx] || n == 2){
		puts("-1");
		return;
	}
	
	bool fl = false;
	if (mn > mx){
		fl = true;
		reverse(a, a + n);
		mn = n - mn - 1;
		mx = n - mx - 1;
	}
	
	forn(i, mn) if (a[i] != a[mx]){
		if (!fl) printf("%d %d\n", mn + 1, mx + 1);
		else printf("%d %d\n", n - mn, n - mx);
		return;
	}
	fore(i, mx + 1, n) if (a[i] != a[mn]){
		if (!fl) printf("%d %d\n", mn + 1, mx + 1);
		else printf("%d %d\n", n - mn, n - mx);
		return;
	}
	fore(i, mn + 1, mx - 1) if (a[i] < a[i + 1]){
		if (!fl) printf("%d %d\n", mn + 1, mx + 1);
		else printf("%d %d\n", n - mn, n - mx);
		return;
	}
	
	int l = mn;
	int r = n - mx - 1;
	int m = n - l - r - 2;
	

	
	if (n == 3){
		puts("-1");
		return;
	}
	
	if (l >= 2){
		if (!fl) printf("%d %d\n", 2, mn + 1);
		else printf("%d %d\n", n - 1, n - mn);
		return;
	}
	if (r >= 2){
		if (!fl) printf("%d %d\n", n - 1, mx + 1);
		else printf("%d %d\n", 2, n - mx);
		return;
	}
	
	bool allmn = true;
	bool allmx = true;
	int nmn = -1, nmx = -1;
	fore(i, mn + 1, mx){
		allmn &= a[i] == a[mn];
		allmx &= a[i] == a[mx];
		if (a[i] != a[mn]) nmn = i;
		if (a[i] != a[mx]) nmx = i;
	}
	
	if (l >= 1 && m >= 1){
		if (allmn){
			if (!fl) printf("%d %d\n", 1, mn + 1);
			else printf("%d %d\n", n, n - mn);
		}
		else{
			if (!fl) printf("%d %d\n", mn + 1, nmn + 1);
			else printf("%d %d\n", n - mn, n - nmn);
		}
		return;
	}
	if (r >= 1 && m >= 1){
		if (allmx){
			if (!fl) printf("%d %d\n", n, mx + 1);
			else printf("%d %d\n", 1, n - mx);
		}
		else{
			if (!fl) printf("%d %d\n", mx + 1, nmx + 1);
			else printf("%d %d\n", n - mx, n - nmx);
		}
		return;
	}
	
	if (l >= 1 && r >= 1){
		if (!fl) printf("%d %d\n", 1, mn + 1);
		else printf("%d %d\n", n, n - mn);
		return;
	}
	
	assert(l == 0 && r == 0 && m >= 2);
	if (!allmn){
		if (!fl) printf("%d %d\n", mn + 1, nmn + 1);
		else printf("%d %d\n", n - mn, n - nmn);
		return;
	}
	if (!fl) printf("%d %d\n", mx + 1, nmx + 1);
	else printf("%d %d\n", n - mx, n - nmx);
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