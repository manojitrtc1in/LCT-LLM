


































using namespace std;




using namespace tr1;





using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}



template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int id0(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id0(int(a)); }
inline int id0(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id0(int(a)); }

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}


template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if(mod == -1) mod = MOD;
	a += b;
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
}
template <class t>
void output1(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template <class t>
void output2(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		output1(arr[i]);
}






void id3(long long num1, long long num2, long long &a, long long &b) {
	long long i, j;
 	if(!(num1 % num2)) {
		a = 1;
		b = -num1 / num2 + 1;
		return;
	}
	id3(num2, num1 % num2, i, j);
	a = j;
	b = i - j * (num1 / num2);
}



ll getfirst(ll be, ll en, ll mod, ll add) {
	ll rans;
	if(add == 0) return -1ll;
	if(add > mod / 2) {
		rans = getfirst(mod - en, mod - be, mod, mod - add);
		if(rans == -1ll) return -1ll;
		rans = mod - rans;
		return rans;
	}
	if((be - 1) / add != en / add) {
		ll k = (be - 1) / add + 1;
		rans = k * add;
		assert(rans >= be && rans <= en);
		return rans;
	}
	ll radd = add - mod % add;
	ll rbe = be % add, ren = en % add;
	rans = getfirst(rbe, ren, add, radd);
	if(rans == -1ll) return -1ll;
	rans += be - rbe;
	return rans;
}



ll getmin(ll be, ll mod, ll add, ll left) {
	if(left == 0) return be;
	pll radd = mpr(getfirst(mod - be, mod - 1, mod, add), 0);
	if(radd.first == -1ll) return be;
	ll ra, rb, gg = __gcd(mod, add), xia = add / gg, xib = mod / gg;
	id3(mod, add, ra, rb);
	if(rb < 0) {
		rb += xib;
		ra -= xia;
	}
	ra = ra * (radd.first / gg % xia) % xia;
	rb = rb * (radd.first / gg % xib) % xib;
	assert(rb * add + mod * ra == radd.first);
	radd.second = rb;
	if(radd.second > left) return be;
	radd.first = be - (mod - radd.first);
	left -= radd.second;

	ll rpadd = (radd.first / (be - radd.first));
	if(1.0 * rpadd * radd.second > left)
		return radd.first - (left / radd.second) * (be - radd.first);
	radd.first -= rpadd * (be - radd.first);
	left -= rpadd * radd.second;
	return getmin(radd.first, mod, add, left);
}

const int maxn = 201000;
struct edge {
	int to, nxt;
} e[maxn * 2];
int head[maxn], le;
inline void addedge(int a, int b) {
	e[le].to = b;
	e[le].nxt = head[a];
	head[a] = le++;
}

int n, nq;

int fa[maxn][22], deep[maxn];

inline void initfa() {
	for(int i = 1; i <= 20; i++) {
		for(int j = 0; j < n; j++) {
			if(fa[j][i - 1] == -1) fa[j][i] = -1;
			else fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
}
inline int getfa(int no, int l) {
	for(int i = 0; l; l >>= 1, i++)
		if(l & 1) no = fa[no][i];
	return no;
}
inline int id5(int a, int b) {
	if(deep[a] > deep[b]) swap(a, b);
	b = getfa(b, deep[b] - deep[a]);
	if(b == a) return a;
	for(int i = 20; i >= 0; i--)
		if(fa[a][i] != fa[b][i]){
			a = fa[a][i];
			b = fa[b][i];
		}
	return fa[a][0];
}
inline int getl(int a, int b) {
	int faa = id5(a, b);
	return deep[a] + deep[b] - deep[faa] * 2;
}

void dfs(int no) {
	for(int i = head[no]; i != -1; i = e[i].nxt) if(e[i].to != fa[no][0]) {
		fa[e[i].to][0] = no;
		deep[e[i].to] = deep[no] + 1;
		dfs(e[i].to);
	}
}
inline void swap(int &a, int &b, int c) {
	if(deep[c] > deep[b]) swap(b, c);
	if(deep[b] > deep[a]) swap(b, a);
}

inline ll id2(int mod1, int mod2, int p1, int p2) {
	if(p1 < p2) {
		swap(p1, p2);
		swap(mod1, mod2);
	}
	ll gg = __gcd(mod1, mod2);
	if((p2 - p1) % gg) return -1ll;
	ll xia = mod2 / gg, xib = mod1 / gg, ra, rb;
	id3(mod1, mod2, ra, rb);
	if(rb < 0) {
		rb += xib;
		ra -= xia;
	}
	ra = ra * ((p1 - p2) / gg);
	rb = rb * ((p1 - p2) / gg);
	ll k = min(-ra / xia, rb / xib);
	rb -= k * xib; ra += k * xia;
	assert(ra * mod1 + mod2 * rb == p1 - p2);
	return p2 + rb * mod2;
}
ll getp(int mod1, int mod2, int delta1, int delta2) {
	if(delta2 % 2) return -1ll;
	if(1ll * delta1 * delta2 <= 0) return 0;
	if(delta1 > delta2) swap(delta1, delta2);
	if(delta2 < 0) {
		delta1 += mod2, delta2 += mod2;
		ll ans = getp(mod1, mod2, delta1, delta2);
		if(ans == -1ll) return -1ll;
		return getp(mod1, mod2, delta1, delta2) - mod2;
	}
	if(delta2 >= mod2) {
		ll p = delta2 - delta2 % mod2;
		ll ans = getp(mod1, mod2, delta1 - p, delta2 - p);
		if(ans == -1ll) return -1ll;
		return ans + p;
	}

	ll num = getfirst(mod2 - delta2 % mod2, mod2 - delta1 % mod2, mod2, mod1 % mod2);
	if(num == -1ll) return -1ll;
	if((num - (mod2 - delta2)) % 2) return -1ll;

	return id2(mod1, mod2, mod2 - num + mod2 * (delta2 / mod2), 0);
}
void id1(ll l1, ll l2, ll range1, ll range2, ll st, ll &ans) {
	ll p = getp(l1 * 2, l2 * 2, range1, range2);
	if(p != -1ll) {
		ll rdelta = p % (l1 * 2);
		while(rdelta > range2) rdelta -= l1 * 2;
		while(rdelta < range1) rdelta += l1 * 2;
		ll add1 = st + (range2 - rdelta) / 2;
		ans = min((ull) ans, (ull) (p + add1));
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	int id4 = 256 << 20; 

	char *__p__ = (char*)malloc(id4) + id4;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	


	memset(head, -1, sizeof(head));
	le = 0;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		addedge(a, b);
		addedge(b, a);
	}
	fa[0][0] = -1;
	dfs(0);
	initfa();

	scanf("%d", &nq);
	for(int i1 = 0; i1 < nq; i1++) {
		int a, b, ra, rb, l1, l2, la, lb, rla, rlb;
		bool flag = 0;
		scanf("%d%d%d%d", &a, &b, &ra, &rb);












		a--; b--; ra--; rb--;
		int f1 = id5(a, b), f2 = id5(ra, rb);
		int f11 = id5(a, ra), f12 = id5(a, rb);
		int f21 = id5(b, ra), f22 = id5(b, rb);
		if(deep[f11] < deep[f1] && deep[f12] < deep[f1]) {
			puts("-1");
			continue;
		}
		if(deep[f21] < deep[f2] && deep[f11] < deep[f2]) {
			puts("-1");
			continue;
		}
		int be = f1, en = f1;
		swap(be, en, f11);
		swap(be, en, f12);
		swap(be, en, f21);
		swap(be, en, f22);
		if(getl(be, a) > getl(en, a)) swap(be, en);
		if(getl(be, ra) > getl(en, ra)) flag = 1;
		l1 = getl(a, b); l2 = getl(ra, rb);
		la = getl(be, a), lb = getl(en, b);
		if(flag) {
			rla = getl(en, ra);
			rlb = getl(be, rb);
		} else {
			rla = getl(be, ra);
			rlb = getl(en, rb);
		}
		ll ans = -1ll;
		if(!flag) {
			ans = min((ull) ans, (ull) id2(l1 * 2, l2 * 2, la, rla));
			ans = min((ull) ans, (ull) id2(l1 * 2, l2 * 2, lb + l1, rlb + l2));
			id1(l1, l2, l1 + lb - (l2 - rlb), l1 * 2 - la - rla, rla, ans);
			id1(l1, l2, la - (l2 * 2 - rla), l1 - lb - (l2 + rlb), l2 + rlb, ans);
		} else {
			ans = min((ull) ans, (ull) id2(l1 * 2, l2 * 2, la, rlb + l2));
			ans = min((ull) ans, (ull) id2(l1 * 2, l2 * 2, lb + l1, rla));
			id1(l1, l2, la - (l2 - rlb), l1 - lb - rla, rla, ans);
			id1(l1, l2, l1 + lb - (l2 * 2 - rla), l1 * 2 - la - (l2 + rlb), l2 + rlb, ans);
		}

		printf("%I64d\n", ans);
	}

    return 0;
}
