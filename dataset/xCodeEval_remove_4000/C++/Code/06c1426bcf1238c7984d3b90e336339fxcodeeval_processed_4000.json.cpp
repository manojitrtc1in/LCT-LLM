



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
const int LOGN = 17;
const int SM = 87;
const int P = 450;

int n, m;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m)
		scanf("%d%d", &q[i].x, &q[i].y);
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		return a;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int lst[N];

void sieve(){
	iota(lst, lst + N, 0);
	fore(i, 2, N){
		if (lst[i] != i) continue;
		for (int j = i; j < N; j += i)
			lst[j] = min(lst[j], i);
	}
}

int num[N];
char st[SM][N / 2][LOGN];
int pw[N];

void build(int pr){
	int x = num[pr];
	forn(i, n){
		st[x][i][0] = 0;
		while (a[i] % pr == 0){
			++st[x][i][0];
			a[i] /= pr;
		}
	}
	fore(j, 1, LOGN) forn(i, n){
		st[x][i][j] = st[x][i][j - 1];
		if (i + (1 << (j - 1)) < n)
			st[x][i][j] = max(st[x][i][j], st[x][i + (1 << (j - 1))][j - 1]);
	}
	pw[0] = pw[1] = 0;
	fore(i, 2, N) pw[i] = pw[i / 2] + 1;
}

int get(int x, int l, int r){
	int len = pw[r - l];
	return max(st[x][l][len], st[x][r - (1 << len)][len]);
}

int pws[SM][20];

struct node{
	node *l, *r;
	int val;
	node() : l(NULL), r(NULL), val(1) {}
	node(int x) : l(NULL), r(NULL), val(x) {}
};

typedef node* tnode;

tnode root[N];

tnode build(int l, int r){
	if (l == r - 1)
		return new node();
	int m = (l + r) / 2;
	tnode cur = new node();
	cur->l = build(l, m);
	cur->r = build(m, r);
	return cur;
}

tnode upd(tnode v, int l, int r, int pos, int val){
	if (l == r - 1)
		return new node(val);
	int m = (l + r) / 2;
	tnode cur = new node();
	if (pos < m){
		cur->l = upd(v->l, l, m, pos, val);
		cur->r = v->r;
	}
	else{
		cur->l = v->l;
		cur->r = upd(v->r, m, r, pos, val);
	}
	cur->val = mul(cur->l->val, cur->r->val);
	return cur;
}

int get(tnode v, int l, int r, int L, int R){
	if (L >= R)
		return 1;
	if (l == L && r == R)
		return v->val;
	int m = (l + r) / 2;
	return mul(get(v->l, l, m, L, min(m, R)), get(v->r, m, r, max(m, L), R));
}

int pos[N];

void solve() {
	sieve();
	int cnt = 0;
	fore(i, 2, N) if (lst[i] == i){
		num[i] = cnt;
		if (cnt < SM){
			pws[cnt][0] = 1;
			fore(j, 1, 20) pws[cnt][j] = mul(pws[cnt][j - 1], i);
		}
		++cnt;
	}
	fore(i, 2, P) if (lst[i] == i){
		build(i);
	}
	
	forn(i, cnt) pos[i] = -1;
	root[0] = build(0, n);
	forn(i, n){
		if (a[i] == 1)
			root[i + 1] = root[i];
		else{
			int x = num[a[i]];
			if (pos[x] != -1){
				root[i + 1] = upd(root[i], 0, n, pos[x], 1);
				root[i + 1] = upd(root[i + 1], 0, n, i, a[i]);
			}
			else{
				root[i + 1] = upd(root[i], 0, n, i, a[i]);
			}
			pos[x] = i;
		}
	}
	
	

	

	
	int ans = 0;
	forn(i, m){
		int l = (ans + q[i].x) % n;
		int r = (ans + q[i].y) % n;
		if (l > r) swap(l, r);
		ans = 1;
		forn(i, SM){
			int val = get(i, l, r + 1);
			ans = mul(ans, pws[i][val]);
		}
		ans = mul(ans, get(root[r + 1], 0, n, l, r + 1));
		printf("%d\n", ans);
	}
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