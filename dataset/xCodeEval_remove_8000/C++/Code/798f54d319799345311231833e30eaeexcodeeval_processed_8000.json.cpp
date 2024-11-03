



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

const int N = 100 * 1000 + 13;

int n, k;
int a[N];

bool read(){
	if(scanf("%d%d", &n, &k) != 2)
		return false;
	++n;
	static char buf[10];
	forn(i, n){
		scanf("%s", buf);
		a[i] = (buf[0] == '?' ? INF : atoi(buf));
	}
	return true;
}

void solve(){
	if (k == 0 && a[0] == 0){
		puts("Yes");
		return;
	}
	
	int cnt = 0;
	forn(i, n) if (a[i] == INF)
		++cnt;
	
	if (k == 0 && a[0] == INF){
		puts((n - cnt) & 1 ? "Yes" : "No");
		return;
	}
	
	if (k == 0){
		puts("No");
		return;
	}
	
	if (cnt > 0){
		puts(n & 1 ? "No" : "Yes");
		return;
	}
	
	bool dv = true;
	forn(i, n - 1){
		if (a[i] % k != 0){
			dv = false;
			break;
		}
		a[i + 1] += a[i] / k;
	}
	dv &= (a[n - 1] == 0);
	
	puts(dv ? "Yes" : "No");
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