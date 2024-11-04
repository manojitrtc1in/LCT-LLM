



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

const int N = 15;
const int M = 500 * 1000 + 25;
const int LOGN = 19;

int n, m;
int a[N];
vector<int> b[N];
map<string, int> wds;

int get_word(const string &s){
	if (!wds.count(s)){
		int k = sz(wds);
		wds[s] = k;
	}
	return wds[s];
}

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	wds.clear();
	static char buf[20];
	forn(i, n){
		scanf("%s", buf);
		a[i] = get_word(buf);
	}
	scanf("%d", &m);
	forn(i, m){
		int k;
		scanf("%d", &k);
		b[i].resize(k);
		forn(j, k){
			scanf("%s", buf);
			b[i][j] = get_word(buf);
		}
	}
	return true;
}

int dp[1 << N][N * N];
vector<int> pos[N];
int fst[N][M];

void solve() {	
	int tot = n * (n - 1) / 2;
	int ans = -INF;
	int pos = -1;
	forn(i, m){
		forn(j, n) fst[j][sz(b[i])] = sz(b[i]);
		for (int j = sz(b[i]) - 1; j >= 0; --j){
			forn(k, n)
				fst[k][j] = fst[k][j + 1];
			if (b[i][j] < n)
				fst[b[i][j]][j] = j;
		}
		forn(mask, 1 << n) forn(inv, tot + 1)
			dp[mask][inv] = INF;
		dp[0][0] = -1;
		forn(mask, 1 << n){
			int ncnt = __builtin_popcount(mask);
			forn(inv, tot + 1) if (dp[mask][inv] < sz(b[i])){
				int cnt = ncnt;
				forn(j, n){
					if (!((mask >> j) & 1)){
						int nxt = fst[j][dp[mask][inv] + 1];
						if (nxt < sz(b[i]))
							dp[mask | (1 << j)][inv + cnt] = min(dp[mask | (1 << j)][inv + cnt], nxt);
					}
					else{
						--cnt;
					}
				}
			}
		}
		int res = -1;
		forn(inv, tot + 1) if (dp[(1 << n) - 1][inv] < sz(b[i])){
			res = inv;
			break;
		}
		if (res != -1 && tot - res + 1 > ans){
			ans = tot - res + 1;
			pos = i + 1;
		}
	}
	
	if (pos == -1)
		puts("Brand new problem!");
	else
		printf("%d\n[:%s:]\n", pos, string(ans, '|').c_str());
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