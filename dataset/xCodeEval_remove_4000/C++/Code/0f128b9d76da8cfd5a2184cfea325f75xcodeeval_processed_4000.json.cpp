



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

const int N = 200 + 7;
const int K = 500 + 7;

int n, m, k;
vector<int> l, r;
vector<int> a[N];
int w[N];

void get_num(vector<int> &a){
	int k;
	scanf("%d", &k);
	a.resize(k);
	forn(i, k)
		scanf("%d", &a[i]);
}

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	get_num(l);
	get_num(r);
	forn(i, n){
		get_num(a[i]);
		scanf("%d", &w[i]);
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

struct node{
	int nxt[20];
	int go[20];
	int sum;
	int dp;
	int link;
	int p, pch;
	node(){
		memset(nxt, -1, sizeof(nxt));
		memset(go, -1, sizeof(go));
		sum = 0;
		link = -1;
		p = pch = -1;
		dp = -1;
	}
	int& operator [](int x){
		return nxt[x];
	}
};

node trie[N];
int cnt;

void add(vector<int> &a, int w){
	int cur = 0;
	forn(i, sz(a)){
		int x = a[i];
		if (trie[cur][x] == -1){
			trie[cnt] = node();
			trie[cur][x] = cnt;
			trie[cnt].p = cur;
			trie[cnt].pch = x;
			++cnt;
		}
		cur = trie[cur][x];
	}
	trie[cur].sum += w;
}

int go(int v, int c);

int get_link(int v){
	if (trie[v].link == -1){
		if (v == 0 || trie[v].p == 0)
			trie[v].link = 0;
		else
			trie[v].link = go(get_link(trie[v].p), trie[v].pch);
	}
	return trie[v].link;
}

int go(int v, int c){
	if (trie[v].go[c] == -1) {
		if (trie[v][c] != -1)
			trie[v].go[c] = trie[v][c];
		else
			trie[v].go[c] = (v == 0 ? 0 : go(get_link(v), c));
	}
	return trie[v].go[c];
}

int id0(int v){
	if (trie[v].dp == -1){
		int nxt = get_link(v);
		trie[v].dp = trie[v].sum;
		if (v != nxt)
			trie[v].dp += id0(nxt);
	}
	return trie[v].dp;
}

int dp[N][N][K][2];

int calc(vector<int> &x){
	memset(dp, 0, sizeof(dp));
	forn(i, sz(x)){
		fore(j, 1, (i == 0) ? (x[i] + 1) : m){
			int nxt = go(0, j);
			int sum = id0(nxt);
			if (sum <= k)
				dp[i + 1][nxt][sum][(i != 0) || (j < x[i])] = add(dp[i + 1][nxt][sum][(i != 0) || (j < x[i])], 1);
		}
	}
	forn(i, sz(x)) forn(cur, cnt) forn(sum, k + 1) forn(fl, 2) if (dp[i][cur][sum][fl]){
		int lim = (fl ? m : (x[i] + 1));
		forn(d, lim){
			int nxt = go(cur, d);
			int nsum = sum + id0(nxt);
			if (nsum <= k){
				bool nfl = fl || (d < x[i]);
				dp[i + 1][nxt][nsum][nfl] = add(dp[i + 1][nxt][nsum][nfl], dp[i][cur][sum][fl]);
			}
		}
	}
	int ans = 0;
	forn(cur, cnt) forn(sum, k + 1) forn(fl, 2)
		ans = add(ans, dp[sz(x)][cur][sum][fl]);
	return ans;
}

void solve() {
	trie[0] = node();
	cnt = 1;
	forn(i, n) add(a[i], w[i]);
	assert(cnt <= N);
	
	--l.back();
	for (int i = sz(l) - 1; l[i] < 0; --i){
		l[i] = m - 1;
		--l[i - 1];
	}
	if (l[0] == 0){
		l.erase(l.begin());
	}
	
	

	

	
	printf("%d\n", add(calc(r), -calc(l)));
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