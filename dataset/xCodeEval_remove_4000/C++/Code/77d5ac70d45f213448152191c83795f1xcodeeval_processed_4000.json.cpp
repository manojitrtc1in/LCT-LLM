




















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

typedef long long LL;

const int maxn = 205;

int n, K;
int a[maxn];
int f[maxn][maxn];
int g[maxn][maxn];

struct Edge {
	int to, nxt;
} e[maxn << 1];

int first[maxn];

inline void add_edge(int from, int to) {
	static int cnt = 0;
	e[++cnt].nxt = first[from];
	first[from] = cnt;
	e[cnt].to = to;
	e[++cnt].nxt = first[to];
	first[to] = cnt;
	e[cnt].to = from;
}

inline void dfs(int now, int fa) {
	f[now][0] = a[now];
	for (int i = first[now]; i; i = e[i].nxt) {
		int to = e[i].to;
		if (to != fa) {
			dfs(to, now);
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (j + k + 1 > K) {
						g[now][min(j, k + 1)] = max(g[now][min(j, k + 1)], f[now][j] + f[to][k]);






					}
				}
			}












			f[now][n] = max(f[now][n], g[now][n]);
			for (int j = n - 1; ~j; --j) {
				f[now][j] = max(max(f[now][j], g[now][j]), f[now][j + 1]); 
			}
		}
	}
}

int main() {
	read(n), read(K);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		read(u), read(v);
		add_edge(u, v);
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, f[1][i]);
	}
















	writeln(ans);
	return 0;
}