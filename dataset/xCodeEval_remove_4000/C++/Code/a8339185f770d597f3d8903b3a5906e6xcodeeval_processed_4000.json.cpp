
















using namespace std;










namespace XTREME_IOS {
	const int SZ = 1 << 20;
	char ib[SZ], ob[SZ], *li, *ri, *lo = ob, *ro = ob + SZ;
}
inline int gc() {
	using namespace XTREME_IOS;
	if (li == ri) ri = (li = ib) + fread(ib, 1, SZ, stdin);
	return *li++;
}
inline void fl() {
	using namespace XTREME_IOS;
	fwrite(ob, 1, lo - ob, stdout), lo = ob, fflush(stdout);
}
inline void pc(int ch) {
	using namespace XTREME_IOS;
	if (lo == ro) fl();
	*lo++ = ch;
}


template <typename T>
inline typename enable_if<is_signed<T>::value && is_integral<T>::value>::type read(T &x) {
	int c = gc(), tag = 0;
	x = 0;
	for (; !isdigit(c); c = gc())
		tag |= (c == '-');
	for (; isdigit(c); c = gc())
		x = (x * 10) + (c ^ 48);
	if (tag)
		x = -x;
}
template <typename T>
inline typename enable_if<is_unsigned<T>::value>::type read(T &x) {
	int c = gc();
	x = 0;
	for (; !isdigit(c); c = gc());
	for (; isdigit(c); c = gc())
		x = (x * 10) + (c ^ 48);
}
inline void read(char &x) {
	int c = gc();
	for (; isspace(c); c = gc());
	x = c;
}
inline void read(char *s) {
	int c = gc();
	for (; isspace(c); c = gc());
	for (; !isspace(c); c = gc()) *s++ = c;
	*s++ = '\0';
}
inline void read(string &s) {
	int c = gc();
	s = "";
	for (; isspace(c); c = gc());
	for (; !isspace(c); c = gc()) s += c;
}
template <typename T>
inline typename enable_if<!is_integral<T>::value>::type read(T &x) {
	string s;
	stringstream ss;
	read(s);
	ss.str(s);
	ss >> x;
}
template <typename Head, typename... Tail>
inline void read(Head &x, Tail&... y) {
	read(x);
	read(y...);
}
template <typename OutputIt, typename = typename enable_if<is_same<
		output_iterator_tag,
		 typename iterator_traits<OutputIt>::iterator_category>::value ||
		(is_base_of<forward_iterator_tag, typename
		 iterator_traits<OutputIt>::iterator_category>::value &&
		 !is_const<OutputIt>::value)>::type>
void read(OutputIt l, OutputIt r) {
	for (; l != r; ++l)
		read(*l);
}

template <typename T>
inline typename enable_if<is_unsigned<T>::value>::type write(T x) {
	if (x >= 10) write(x / 10);
	pc((x % 10) ^ 48);
}
template <typename T>
inline typename enable_if<is_signed<T>::value && is_integral<T>::value>::type write(T x) {
	if (x < 0) pc('-'), x = -x;
	write(typename make_unsigned<T>::type (x));
}
inline void write(char c) {
	pc(c);
}
inline void write(const char *s) {
	for (; *s; pc(*s++));
}
inline void write(const string &s) {
	for (auto c: s) pc(c);
}
template <typename T>
inline typename enable_if<is_floating_point<T>::value>::type write(T x) {
	stringstream ss;
	ss << fixed << setprecision(12) << x;
	write(ss.str());
}
template <typename T>
inline typename enable_if<!is_arithmetic<T>::value>::type write(const T &x) {
	stringstream ss;
	ss << x;
	write(ss.str());
}

inline void wts() { }
inline void wtb() { pc('\n'); }
inline void wte() { exit(0); }
template <typename Head, typename... Tail>
inline void wts(const Head &x, const Tail&... y) {
	write(x), pc(' '), wts(y...);
}
template <typename Head, typename... Tail>
inline void wtb(const Head &x, const Tail&... y) {
	write(x), pc(' '), wtb(y...);
}
template <typename Head, typename... Tail>
inline void wte(const Head &x, const Tail&... y) {
	write(x), pc(' '), wte(y...);
}
template <typename It, typename = typename enable_if<is_base_of<input_iterator_tag,
	typename iterator_traits<It>::iterator_category>::value>::type>
void write(const pair<It, It> &range) {
	for (It l = range.fi; l != range.se; ++l)
		write(*l), pc(' ');
}

template <class T>
struct is_pair { static const int value = 0; };
template <class A, class B>
struct is_pair<pair<A, B>> { static const int value = 1; };

template <class T>
inline void debug_out(const T &x) {
	write(x);
}
inline void debug_out(const string &s) {
	pc('"'), write(s), pc('"');
}
inline void debug_out(const char *s) {
	pc('"'), write(s), pc('"');
}
template <typename It, typename = typename enable_if<is_base_of<input_iterator_tag,
	typename iterator_traits<It>::iterator_category>::value>::type>
void debug_out(const pair<It, It> &range) {
	pc('{');
	bool fst = 1;
	for (It l = range.fi; l != range.se; ++l) {
		if (fst)
			fst = 0;
		else
			pc(','), pc(' ');
		write(*l);
    }
	pc('}');
}
template <typename... args>
inline void debug_out(const vector<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const list<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const deque<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const set<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const multiset<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const map<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const multimap<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const unordered_set<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const unordered_multiset<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const unordered_map<args...> &v) { debug_out(mp(BE(v))); }
template <typename... args>
inline void debug_out(const unordered_multimap<args...> &v) { debug_out(mp(BE(v))); }
template <typename Head, typename... Tail>
inline void debug_out(const Head &x, const Tail&... y) {
	debug_out(x), pc(' ');
	debug_out(y...);
}





int id1 = []() {

	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	atexit([](){ system("grep VmPeak /proc/$PPID/status > /dev/tty"); });

	atexit(fl);
	return 0;
}();

using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using db = double;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using l3 = __int128_t;
using u3 = __uint128_t;

const double finf = 1e121, eps = 1e-10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

template <typename A, typename B>
auto mymax(const A &x, const B &y) -> decltype(x > y ? x : y) { return x > y ? x : y; }
template <typename A, typename B>
auto mymin(const A &x, const B &y) -> decltype(x < y ? x : y) { return x < y ? x : y; }
template <typename A, typename B>
inline int id2(A &x, const B &y) { return x > y ? (x = y, 1) : 0; }
template <typename A, typename B>
inline int id0(A &x, const B &y) { return x < y ? (x = y, 1) : 0; }

const int N = 200100, K = 26, B = 1000;
const ul M = 1085420197799615903;
int n, m, q;
vector<pii> son[N];
string str;
int nxt[N][K], fail[N], len[N], pos[N], cnt = 1;
int split(int p, int c) {
	int q = nxt[p][c];
	if (len[q] == len[p] + 1) return q;
	int nq = ++cnt; len[nq] = len[p] + 1, fail[nq] = fail[q], fail[q] = nq;
	pos[nq] = pos[q];
	for (int i = 0; i < K; i++) nxt[nq][i] = nxt[q][i];
	for (; nxt[p][c] == q; p = fail[p]) nxt[p][c] = nq;
	return nq;
}
int append(int p, int c) {
	if (nxt[p][c]) return split(p, c);
	int np = ++cnt; len[np] = len[p] + 1;
	for (; p && !nxt[p][c]; p = fail[p]) nxt[p][c] = np;
	fail[np] = p ? split(p, c) : 1;
	return np;
}
int sz[N], ch[N], dep[N], fa[N], dfn[N], top[N], idfn[N], tot;
void dfs1(int x, int f) {
	sz[x] = 1, ch[x] = 0, dep[x] = dep[f] + 1, fa[x] = f;
	for (auto pr: son[x]) {
		dfs1(pr.fi, x), sz[x] += sz[pr.fi];
		if (sz[ch[x]] < sz[pr.fi]) ch[x] = pr.fi;
	}
}
void dfs2(int x, int t) {
	dfn[x] = ++tot, top[x] = t, idfn[tot] = x;
	if (ch[x]) dfs2(ch[x], t), pos[x] = pos[ch[x]];
	for (auto pr: son[x]) if (pr.fi != ch[x]) dfs2(pr.fi, pr.fi);
}
u3 pw[N], hs[N];
ul gethash(int l, int r) {
	return (hs[r] - (u3)hs[l - 1] * pw[r - l + 1] % M + M) % M;
}

namespace tree {
	vector<pii> e[N];
	int sz[N], ch[N], dep[N], fa[N], dfn[N], top[N], tot, col[N];
	int str[N];
	ul ha[N];
	void dfs1(int x, int f) {
		sz[x] = 1, ch[x] = 0, dep[x] = dep[f] + 1, fa[x] = f;
		for (auto pr: e[x]) if (pr.fi != f) {
			col[pr.fi] = pr.se;
			dfs1(pr.fi, x), sz[x] += sz[pr.fi];
			if (sz[ch[x]] < sz[pr.fi]) ch[x] = pr.fi;
		}
	}
	void dfs2(int x, int t) {
		dfn[x] = ++tot, top[x] = t, str[tot] = col[x];
		if (ch[x]) dfs2(ch[x], t);
		for (auto pr: e[x]) if (pr.fi != ch[x] && pr.fi != fa[x]) dfs2(pr.fi, pr.fi);
	}
	void init() {
		dfs1(1, 0), dfs2(1, 1);
		FOR (i, 1, n) str[2 * n + 1 - i] = str[i];
		FOR (i, 1, n * 2) ha[i] = ((u3)ha[i - 1] * B + str[i]) % M;
	}
	ul treehash(int l, int r) {
		return (ha[r] - (u3)ha[l - 1] * pw[r - l + 1] % M + M) % M;
	}
	vector<pii> query(int u, int v) {
		vector<pii> up, dn, res;
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]])
				up.eb(mp(dfn[top[u]], dfn[u])), u = fa[top[u]];
			else
				dn.eb(mp(dfn[top[v]], dfn[v])), v = fa[top[v]];
		}
		if (dep[u] < dep[v])
			dn.eb(mp(dfn[u] + 1, dfn[v]));
		else if (dep[u] > dep[v])
			up.eb(mp(dfn[v] + 1, dfn[u]));
		reverse(BE(dn));
		for (auto pr: up) res.eb(mp(n * 2 + 1 - pr.se, n * 2 + 1 - pr.fi));
		for (auto pr: dn) res.eb(pr);
		return res;
	}
}
using tree::treehash;
int l[N], r[N];

pii jump(pii pr, pii seg) {
	int ptr = pr.fi, dis = pr.se;
	if (!ptr) return pr;
	int x = seg.fi, y = seg.se;
	while (x <= y) {
		if (dis) {
			int len = min(y - x + 1, dis);
			int tl = r[ptr] - dis + 1;
			if (treehash(x, x + len - 1) != gethash(tl, tl + len - 1))
				return mp(0, 0);
			dis -= len, x += len;
		}
		if (x > y) break;
		for (int i = (1 << 18); i; i >>= 1) {
			int tp = dfn[ptr] + i;
			if (tp > cnt) continue;
			tp = idfn[tp];
			if (top[tp] != top[ptr]) continue;
			int tl = r[ptr] + 1, tr = r[tp];
			if (y - x < tr - tl) continue;
			if (treehash(x, x + tr - tl) != gethash(tl, tr)) continue;
			ptr = tp, x += tr - tl + 1;
		}
		if (x > y) break;
		int ch = treehash(x, x), find = 0;
		for (auto pr: son[ptr]) if (pr.se == ch) {
			find = 1;
			ptr = pr.fi, dis = r[ptr] - l[ptr] + 1;
			break;
		}
		if (!find) return mp(0, 0);
	}
	return mp(ptr, dis);
}

vector<int> ind[N];
int ans[N];
struct Qry {
	int x, y, k, id;
	bool operator < (const Qry &q) const {
		return x < q.x;
	}
} qry[N];

inline int lowbit(int x) { return x & (-x); }
int bit[N];
inline void modify(int x, int k) {
	for (; x <= cnt; x += lowbit(x)) bit[x] += k;
}
inline int query(int x, int k = 0) {
	for (; x; x ^= lowbit(x)) k += bit[x];
	return k;
}
string ts[N];

int main() {
	pw[0] = 1;
	FOR (i, 1, N - 1) pw[i] = (u3)pw[i - 1] * B % M;
	read(n, m, q);
	FOR (i, 2, n) {
		int u, v; char c[4];
		read(u, v, c);
		tree::e[u].eb(mp(v, *c)), tree::e[v].eb(mp(u, *c));
	}
	tree::init();
	str += "+";
	FOR (i, 1, m) {
		string &s = ts[i];
		read(s);
		int l = str.size(), r = l + s.size() - 1, p = 1;
		str += s;
		FOR (j, l, r)
			pos[p = append(p, str[j] - 'a')] = j;
	}
	FOR (i, 1, m) {
		int p = 1;
		FOR (j, 0, ts[i].size() - 1)
			ind[i].eb(p = nxt[p][ts[i][j] - 'a']);
	}
	FOR (i, 2, cnt) son[fail[i]].eb(mp(i, str[pos[i] - len[fail[i]]]));
	reverse((char *)str.c_str() + 1, (char *)str.c_str() + str.size());
	FOR (i, 1, str.size() - 1) hs[i] = ((u3)hs[i - 1] * B + str[i]) % M;
	dfs1(1, 0), dfs2(1, 1);
	FOR (i, 1, cnt) {
		pos[i] = str.size() - pos[i];
		l[i] = pos[i] + len[fail[i]], r[i] = pos[i] + len[i] - 1;
	}

	int num = 0;
	FOR (i, 1, q) {
		int u, v, l, r;
		read(v, u, l, r);
		auto pr = mp(1, 0);
		for (auto seg: tree::query(u, v)) pr = jump(pr, seg);
		if (pr.fi) {
			qry[++num] = Qry{r, pr.fi, 1, i};
			if (l > 1) qry[++num] = Qry{l - 1, pr.fi, -1, i};
		}
	}
	sort(qry + 1, qry + num + 1);
	for (int i = 1, j = 1; i <= m; i++) {
		for (int x: ind[i])
			modify(dfn[x], 1);
		for (; j <= num && qry[j].x <= i; j++) {
			int x = qry[j].y;
			ans[qry[j].id] += qry[j].k *
				(query(dfn[x] + sz[x] - 1) - query(dfn[x] - 1));
		}
	}
	FOR (i, 1, q) wtb(ans[i]);
}
