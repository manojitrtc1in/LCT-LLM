








using namespace std;

inline char gc() {
	static const int L = 233333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt) {
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) {
			return EOF;
		}
	}
	return *sss++;
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

const int maxn = 100005;
const int inf = 0x3f3f3f3f;

int n, q, tim;
char s[maxn];
int from[maxn];
int nxt[maxn][2];
int jl[maxn * 11][10];
vector<int> dfn[maxn];

inline void rm(int x) {
	nxt[nxt[x][0]][1] = nxt[x][1];
	nxt[nxt[x][1]][0] = nxt[x][0];
}

inline int ask(int x, int t) {
	vector<int>::iterator it = lower_bound(dfn[x].begin(), dfn[x].end(), t);
	if (it == dfn[x].end()) {
		return inf;
	} else {
		return *it;
	}
}

inline bool run() {
	int fx = 1;
	for (int now = nxt[0][1]; ; now = nxt[now][fx]) {
		tim++;


		dfn[now].push_back(tim);
		if (now == n + 1) {
			return false;
		} else if (!now) {
			return true;
		}
		if (dfn[now].size() == 1u) {
			from[now] = nxt[now][0];
		}
		for (int i = 0; i < 10; ++i) {
			jl[tim][i] = jl[tim - 1][i];
		}
		if (s[now] == '<' || s[now] == '>') {
			fx = (s[now] == '>');
			if (s[nxt[now][fx]] == '<' || s[nxt[now][fx]] == '>' || !nxt[now][fx]) {
				rm(now);
			}
		} else {
			if (s[now] == '0') {
				rm(now);
			}
			jl[tim][s[now] - '0']++;
			s[now]--;
		}








	}
}

int main() {




	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 0; i <= n; ++i) {
		nxt[i + 1][0] = i;
		nxt[i][1] = i + 1;
	}
	while (run());
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ll = *dfn[l].begin();
		int rr = min(ask(from[l], ll), ask(r + 1, ll));


		ll--, rr--;
		for (int i = 0; i < 10; ++i) {
			id0(jl[rr][i] - jl[ll][i]);
		}
		puts("");
	}




	return 0;
}