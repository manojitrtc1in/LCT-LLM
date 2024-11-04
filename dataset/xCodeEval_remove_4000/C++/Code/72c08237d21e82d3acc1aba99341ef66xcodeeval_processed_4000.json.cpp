



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

li n, k, d1, d2;

bool read () {
	if (scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2) != 4)
		return false;
	return true;
}

pt vars[] = {{1, 2}, {1, -2}, {-1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int cb[] = {1, -1, 1, 1, -1, -1};
int ba[] = {1, 1, -1, -1, 1, -1};

void solve(){
	forn(i, 6){
		li c = k - vars[i].x * d1 - vars[i].y * d2;
		if (c % 3 != 0)
			continue;
		c /= 3;
		li b = c + cb[i] * d2;
		li a = b + ba[i] * d1;
		li p = n / 3;
		if (a < 0 || b < 0 || c < 0 || n % 3 != 0 || a > p || b > p || c > p)
			continue;
		puts("yes");
		return;
	}
	puts("no");
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
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}