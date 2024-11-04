



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

const int N = 300 * 1000 + 13;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[500 * 1000 + 13];
	forn(i, n){
		scanf("%s", buf);
		string tmp = buf;
		a[i] = mp(count(all(tmp), 'B'), count(all(tmp), 'N'));
	}
	return true;
}

pt fin;

bool check(int k){
	int lx = -INF, rx = INF;
	int ly = -INF, ry = INF;
	int ld = -INF, rd = INF;
	forn(i, n){
		lx = max(lx, a[i].x - k);
		rx = min(rx, a[i].x + k);
		ly = max(ly, a[i].y - k);
		ry = min(ry, a[i].y + k);
		ld = max(ld, a[i].x - a[i].y - k);
		rd = min(rd, a[i].x - a[i].y + k);
	}
	if (lx > rx || ly > ry || ld > rd) return false;
	int l = max(ld, lx - ry);
	int r = min(rd, rx - ly);
	if (l <= r){
		if (ly <= rx - l && rx - l <= ry && (rx > 0 || rx - l > 0))
			fin = mp(rx, rx - l);
		else if (lx <= ry + l && ry + l <= rx && (ry + l > 0 || ry > 0))
			fin = mp(ry + l, ry);
		else
			assert(false);
	}
	return l <= r;
}

void solve() {
	int l = 0, r = 1000 * 1000;
	int res = -1;
	while (l <= r){
		int m = (l + r) / 2;
		if (check(m)){
			res = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	printf("%d\n", res);
	puts((string(fin.x, 'B') + string(fin.y, 'N')).c_str());
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