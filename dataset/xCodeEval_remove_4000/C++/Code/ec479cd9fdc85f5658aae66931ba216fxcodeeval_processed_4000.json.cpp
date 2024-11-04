



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
	sort(a, a + n);
	int lst = 0;
	forn(i, n){
		int j = i;
		while (j + 1 < n && a[j + 1] == a[i])
			++j;
		int cnt = j - i + 1;
		

		if (i == 0){
			lst = cnt;
		}
		else if (a[i] != a[i - 1] + 1){
			puts("NO");
			return;
		}
		else if (cnt < lst || lst == 0){
			puts("NO");
			return;
		}
		else{
			lst = cnt - lst;
		}
		i = j;
	}
	puts(lst == 0 ? "YES" : "NO");
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