



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

const int N = 1000 * 1000 + 13;
const int LOGN = 21;

int n, k;
pt a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n){
		scanf("%d", &a[i].x);
		a[i].x *= 100;
	}
	forn(i, n){
		scanf("%d", &a[i].y);
	}
	return true;
}

int stmin[LOGN][N], stmax[LOGN][N];
int pw[N];

void init(){
	pw[0] = pw[1] = 0;
	fore(i, 2, N) pw[i] = pw[i / 2] + 1;
	forn(i, n){
		stmin[0][i] = a[i].y;
		stmax[0][i] = a[i].x;
	}
	fore(j, 1, LOGN){
		forn(i, n){
			stmin[j][i] = stmin[j - 1][i];
			stmax[j][i] = stmax[j - 1][i];
			if (i + (1 << (j - 1)) < n){
				stmin[j][i] = min(stmin[j][i], stmin[j - 1][i + (1 << (j - 1))]);
				stmax[j][i] = max(stmax[j][i], stmax[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
}

int getMin(int l, int r){
	++r;
	int len = pw[r - l];
	return min(stmin[len][l], stmin[len][r - (1 << len)]);
}

int getMax(int l, int r){
	++r;
	int len = pw[r - l];
	return max(stmax[len][l], stmax[len][r - (1 << len)]);
}

int val[N];

void solve() {
	init();
	forn(i, n){
		int l = i, r = n - 1;
		while (l < r - 1){
			int m = (l + r) / 2;
			if (getMax(i, m) < getMin(i, m))
				l = m;
			else
				r = m;
		}
		if (getMax(i, r) < getMin(i, r)) l = r;
		val[i] = min(getMax(i, l), getMin(i, l));
		if (l + 1 < n){
			++l;
			val[i] = max(val[i], min(getMax(i, l), getMin(i, l)));
		}
	}
	
	sort(val, val + n);
	
	ld ans = 0;
	
	ld p = k / ld(n);
	forn(i, n){
		ans += val[i] * p;
		p *= (n - k - i);
		p /= (n - i - 1);
	}
	
	printf("%.15Lf\n", ans);
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