



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

const int N = 23;

int h, w;

bool read () {
	if (scanf("%d%d", &h, &w) != 2)
		return false;
	return true;
}

string res1[N], res2[N];

bool ok(string res[N], int x, int y){
	fore(dx, -1, 2) fore(dy, -1, 2) if (dx || dy){
		int nx = x + dx;
		int ny = y + dy;
		if (0 <= nx && nx < h && 0 <= ny && ny < w && res[nx][ny] == '1')
			return false;
	}
	return true;
}

void solve() {
	vector<pt> path;
	forn(i, w) path.pb(mp(0, i));
	fore(i, 1, h) path.pb(mp(i, w - 1));
	for (int i = w - 2; i >= 0; --i) path.pb(mp(h - 1, i));
	for (int i = h - 2; i > 0; --i) path.pb(mp(i, 0));
	forn(i, h){
		res1[i] = string(w, '0');
		res2[i] = string(w, '0');
	}
	int cnt1 = 0, cnt2 = 0;
	res1[0][0] = '1';
	fore(i, 1, sz(path)) if (ok(res1, path[i].x, path[i].y)){
		res1[path[i].x][path[i].y] = '1';
		++cnt1;
	}
	res2[0][1] = '1';
	fore(i, 2, sz(path)) if (ok(res2, path[i].x, path[i].y)){
		res2[path[i].x][path[i].y] = '1';
		++cnt2;
	}
	if (cnt1 < cnt2) swap(res1, res2);
	forn(i, h) puts(res1[i].c_str());
	
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