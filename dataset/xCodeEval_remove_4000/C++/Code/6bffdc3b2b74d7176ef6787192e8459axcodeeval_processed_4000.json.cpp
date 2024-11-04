




















using namespace std;

typedef long long LL;

inline char gc() {
	static const LL L = 233333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt) {
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) {
			return EOF;
		}
	}
	return *sss++;
}






inline char readalpha() {
	char dd;
	for (; !isalpha(c); dd);
	return c;
}

inline char readchar() {
	char dd;
	for (; c == ' '; dd);
	return c;
}

template <class T>
inline bool read(T& x) {
	bool flg = false;
	char dd;
	x = 0;
	for (; !isdigit(c); dd) {
		if (c == '-') {
			flg = true;
		} else if(c == EOF) {
			return false;
		}
	}
	for (; isdigit(c); dd) {
		x = (x << 1) + (x << 3) + (c ^ 48);
	}
	if (flg) {
		x = -x;
	}
	return true;
}


template <class T>
inline void write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x | 48);
		return;
	}
	write(x / 10);
	putchar((x % 10) | 48);
}

template <class T>
inline void id0(T x) {
	write(x);
	putchar(' ');
}

template <class T>
inline void writeln(T x) {
	write(x);
	puts("");
}

const int maxn = 300005;
const int inf = 0x3f3f3f3f;

int n;
int aa[maxn];
int bb[maxn];

struct Tree {
	int no[maxn << 2];
	int k;

	inline void build_tree() {
		for (k = 1; k < n; k <<= 1);
		for (int i = k + 1; i <= k + n; ++i) {
			no[i] = aa[i - k];
		}
		for (int i = k + n; i <= (k << 1 | 1); ++i) {
			no[i] = inf;
		}
		for (int i = k; i; --i) {
			no[i] = min(no[i << 1], no[i << 1 | 1]);
		}
	}

	inline void del(int x) {
		for (no[x += k] = inf, x >>= 1; x; x >>= 1) {
			no[x] = min(no[x << 1], no[x << 1 | 1]);
		}
	}

	inline int query(int l, int r) {
		int ans = inf;
		for (l += k - 1, r += k + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if (~l & 1) {
				ans = min(ans, no[l ^ 1]);
			}
			if (r & 1) {
				ans = min(ans, no[r ^ 1]);
			}
		}
		return ans;
	}
} tr;

struct LB {
	int id, nxt;
} lb[maxn];

int first[maxn];

inline void add_node(int x, int id) {
	static int cnt = 0;
	lb[++cnt].nxt = first[x];
	first[x] = cnt;
	lb[cnt].id = id;
}

inline void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		first[i] = 0;
		read(aa[i]);
	}
	for (int i = 1; i <= n; ++i) {
		read(bb[i]);
	}
	for (int i = n; i; --i) {
		add_node(aa[i], i);
	}
	tr.build_tree();
	for (int i = 1; i <= n; ++i) {
		if (!first[bb[i]]) {
			puts("NO");
			return;
		}
		if (tr.query(1, lb[first[bb[i]]].id) < bb[i]) {
			puts("NO");
			return;
		}
		tr.del(lb[first[bb[i]]].id);
		first[bb[i]] = lb[first[bb[i]]].nxt;
	}
	puts("YES");
}

int main() {
	int T;
	read(T);
	while (T--) {
		solve();
	}
	return 0;
}