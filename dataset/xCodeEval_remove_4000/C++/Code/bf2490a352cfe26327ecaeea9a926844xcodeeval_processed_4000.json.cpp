



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

const int N = 6000 + 7;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

pt operator -(const pt &a, const pt &b){
	return mp(a.x - b.x, a.y - b.y);
}

li cross(const pt &a, const pt &b){
	return a.x * li(b.y) - a.y * li(b.x);
}

int get(const pt &a, const pt &b){
	int dx = abs(a.x - b.x);
	int dy = abs(a.y - b.y);
	return __gcd(dx, dy);
}

int cnt[4];
li C[N][4];
li fact[4];

void solve() {
	forn(i, n + 1){
		C[i][0] = 1;
		if (i < 4) C[i][i] = 1;
		fore(j, 1, min(i, 4))
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	fact[0] = 1;
	fore(i, 1, 4) fact[i] = fact[i - 1] * i;
	forn(i, n + 1) forn(j, 4){
		C[i][j] *= fact[j];
	}
	memset(cnt, 0, sizeof(cnt));
	forn(i, n){
		++cnt[(a[i].x / 2 % 2) * 2 + (a[i].y / 2 % 2)];
	}
	li ans = 0;
	forn(i, 4) forn(j, 4) forn(k, 4){
		int res = ((i ^ j) > 0) + ((i ^ k) > 0) + ((k ^ j) > 0);
		if (res % 2 == 0){
			li tot = 1;
			forn(z, 4){
				int cur = (i == z) + (j == z) + (k == z);
				tot *= C[cnt[z]][cur];
			}
			ans += tot;
		}
	}
	assert(ans % 6 == 0);
	printf("%lld\n", ans / 6);
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