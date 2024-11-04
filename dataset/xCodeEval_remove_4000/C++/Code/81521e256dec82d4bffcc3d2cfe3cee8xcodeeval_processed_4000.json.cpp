



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

const int N = 1000 * 1000 + 13;

int n;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	return true;
}

int dp[N];
pt p[N];

void solve(){
	int cur0 = 0, cur1 = 0;
	pt mn0 = mp(0, -1), mn1 = mp(0, -1);
	forn(i, n){
		cur0 += s[i] == '0';
		cur1 += s[i] == '1';
		if (mn1.x + cur1 <= mn0.x + cur0 + 2){
			dp[i] = mn1.x + cur1;
			p[i] = mp(mn1.y, 1);
		}
		else{
			dp[i] = mn0.x + cur0 + 2;
			p[i] = mp(mn0.y, 0);
		}
		mn0 = min(mn0, mp(dp[i] - cur0, i));
		mn1 = min(mn1, mp(dp[i] - cur1, i));
	}
	printf("%d\n", dp[n - 1]);
	int cur = n - 1;
	while (cur >= 0){
		int nxt = p[cur].x;
		if (p[cur].y == 1){
			fore(i, nxt + 1, cur + 1) if (s[i] == '1')
				printf("+2^%d\n", n - i - 1);
		}
		else{
			printf("-2^%d\n", n - cur - 1);
			fore(i, nxt + 1, cur + 1) if (s[i] == '0')
				printf("-2^%d\n", n - i - 1);
			printf("+2^%d\n", n - nxt - 1);
		}
		cur = nxt;
	}
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