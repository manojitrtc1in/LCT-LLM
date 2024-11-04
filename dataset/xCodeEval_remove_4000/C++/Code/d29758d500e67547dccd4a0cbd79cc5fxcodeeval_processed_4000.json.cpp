



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

const int N = 200 * 1000 + 13;
const int M = 123;
const int MAGIC = 30;

int n, k;
vector<int> a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n){
		a[i].resize(k);
		forn(j, k){
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
	return true;
}

vector<int> perm[M];
map<vector<int>, int> rperm;

vector<int> operator *(const vector<int> &a, const vector<int> &b){
	vector<int> c(k);
	forn(i, k) c[i] = a[b[i]];
	return c;
}

int g[M][M];
int nxt[M];

int p[M], rk[M];

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

inline bool unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return false;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
	return true;
}

void solve(){
	rperm.clear();
	int cnt = 0;
	vector<int> pr(k);
	
	iota(all(pr), 0);
	do{
		perm[cnt] = pr;
		rperm[pr] = cnt;
		++cnt;
	} while (next_permutation(all(pr)));
	
	forn(v, cnt) forn(w, cnt){
		int u = rperm[perm[v] * perm[w]];
		g[v][w] = u;
	}
	
	forn(i, cnt)
		nxt[i] = n;
	vector<int> ord(cnt);
	iota(all(ord), 0);
	
	li ans = 0;
	for (int i = n - 1; i >= 0; --i){
		int x = rperm[a[i]];
		ord.erase(find(all(ord), x));
		nxt[x] = i;
		ord.insert(ord.begin(), x);
		
		forn(j, cnt) p[j] = j, rk[j] = 1;
		int lst = i;
		for (int j : ord){
			int t = nxt[j];
			if (t == n || rk[getp(0)] == cnt) break;
			ans += rk[getp(0)] * (t - lst);
			lst = t;
			int tmp = 0;
			for (int l = 0; l < cnt && rk[getp(0)] < cnt; ++l){
				tmp += !unite(l, g[l][j]);
				if (tmp == MAGIC && l + 1 - tmp == 0) break;
			}
		}
		ans += rk[getp(0)] * (n - lst);
	}
	
	printf("%lld\n", ans);
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