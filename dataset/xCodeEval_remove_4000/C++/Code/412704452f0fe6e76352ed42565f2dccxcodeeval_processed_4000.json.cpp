



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
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 500 + 7;
const int M = 1000 * 1000 + 13;
const int LOGN = 20;

int n, m;
int a[M];

bool read () {
	if (scanf("%d%d", &m, &n) != 2)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return  a * li(b) % MOD;
}

int mn[N][N];
bool sg[N];
pt pos[N];
int dp[N][N];
vector<int> poss[N];
int sv[N];

int calc(int l, int r){
	if (l > r)
		return 1;
	
	int xl = a[l], xr = a[r];
	if (dp[xl][xr] != -1)
		return dp[xl][xr];
	if (xl == xr && sg[xl])
		return dp[xl][xr] = 1;
	
	int num = mn[xl][xr];
	int suml = calc(l, pos[num].x - 1), sumr = calc(pos[num].y + 1, r);
	
	int nl = l;
	while (nl < pos[num].x){
		suml = add(suml, mul(calc(l, pos[a[nl]].y), calc(pos[a[nl]].y + 1, pos[num].x - 1)));
		nl = pos[a[nl]].y + 1;
	}
	
	int nr = r;
	while (nr > pos[num].y){
		sumr = add(sumr, mul(calc(pos[num].y + 1, pos[a[nr]].x - 1), calc(pos[a[nr]].x, r)));
		nr = pos[a[nr]].x - 1;
	}
	
	if (sv[num] == -1){
		sv[num] = 1;
		forn(i, sz(poss[num]) - 1){
			int l = poss[num][i] + 1;
			int r = poss[num][i + 1] - 1;
			if (l < r) sv[num] = mul(sv[num], calc(l, r));
		}
	}
	
	dp[xl][xr] = mul(sv[num], mul(suml, sumr));
	return dp[xl][xr];
}

int st[LOGN][M];
int pw[M];

void init(){
	pw[0] = pw[1] = 0;
	fore(i, 2, M)
		pw[i] = pw[i / 2] + 1;
	forn(i, n)
		st[0][i] = a[i];
	fore(j, 1, LOGN){
		forn(i, n){
			st[j][i] = st[j - 1][i];
			if (i + (1 << (j - 1)) < n)
				st[j][i] = min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
		}
	}
}

int get(int l, int r){
	++r;
	int len = pw[r - l];
	return min(st[len][l], st[len][r - (1 << len)]);
}

void solve(){
	forn(i, n) pos[a[i]].y = i;
	for (int i = n - 1; i >= 0; --i) pos[a[i]].x = i;
	
	init();
	forn(l, m) forn(r, m){
		mn[l][r] = min(l, r);
		if (pos[l].x >= pos[r].y) continue;
		mn[l][r] = get(pos[l].x, pos[r].y);
	}
	
	forn(i, m) if (mn[i][i] < i){
		puts("0");
		return;
	}
	
	forn(i, m){
		sg[i] = true;
		forn(k, m) if (k != i && pos[k].x >= pos[i].x && pos[k].y <= pos[i].y)
			sg[i] = false;
	}
	
	forn(i, m) poss[i].clear();
	forn(i, n) poss[a[i]].pb(i);
	memset(sv, -1, sizeof(sv));
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", calc(0, n - 1));
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