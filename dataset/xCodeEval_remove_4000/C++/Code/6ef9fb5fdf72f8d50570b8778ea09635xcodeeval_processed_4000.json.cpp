



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

const int N = 20 * 1000 * 1000 + 13;

string s;
int n;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	return true;
}

vector<int> ord;

void gen(int n){
	if (n == 1){
		ord.pb(1);
		return;
	}
	gen(n / 2);
	gen((n + 1) / 2);
	ord.pb(n);
}

int get(int t, bool ans = false){
	ord.clear();
	gen(t);
	int l = 0;
	int pr = 0;
	for (int x : ord){
		if (x == 1){
			++pr;
			continue;
		}
		int cnt0 = 0, cnt1 = 0;
		int r = l;
		bool fl = false;
		while (r < n){
			if (s[r++] == '0'){
				++cnt0;
				if (cnt0 == x / 2 && cnt1 < (x + 1) / 2){
					fl = true;
					break;
				}
			}
			else{
				++cnt1;
				if (cnt1 == (x + 1) / 2 && cnt0 < x / 2){
					fl = true;
					break;
				}
			}
		}
		if (!fl) break;
		l = r;
		++pr;
	}
	if (!ans) return sz(ord) - pr;
	assert(l == n && pr == sz(ord));
	vector<vector<int>> res;
	l = 0;
	for (int x : ord){
		if (x == 1){
			res.pb({0});
			continue;
		}
		int cnt0 = 0, cnt1 = 0;
		int r = l;
		bool fl = false;
		vector<int> L(x / 2), R((x + 1) / 2);
		while (r < n){
			if (s[r++] == '0'){
				L[cnt0] = cnt0 + cnt1;
				++cnt0;
				if (cnt0 == x / 2 && cnt1 < (x + 1) / 2){
					fl = true;
					break;
				}
			}
			else{
				R[cnt1] = cnt0 + cnt1;
				++cnt1;
				if (cnt1 == (x + 1) / 2 && cnt0 < x / 2){
					fl = true;
					break;
				}
			}
		}
		while (cnt0 < x / 2) L[cnt0] = cnt0 + cnt1, ++cnt0;
		while (cnt1 < (x + 1) / 2) R[cnt1] = cnt0 + cnt1, ++cnt1;
		vector<int> nw;
		for (int x : res[sz(res) - 2]) nw.pb(L[x]);
		for (int x : res[sz(res) - 1]) nw.pb(R[x]);
		res.pop_back();
		res.pop_back();
		res.pb(nw);
		if (!fl) break;
		l = r;
	}
	printf("%d\n", t);
	for (int x : res[0])
		printf("%d ", x + 1);
	puts("");
	return true;
}

void solve() {
	int l = 1, r = n + 1;
	int res = -1;
	while (l <= r){
		int m = (l + r) / 2;
		if (get(m) == 0){
			res = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	get(res, true);
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