
 

 
















 
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

const int maxn = 100005;
const LL inf = 0x3f3f3f3f3f3f3f3fLL;

int n, p;
int aa[maxn];
LL ans[maxn];
LL lstans = 0;




struct Tree {
	struct Node {
		LL mn, lzy;
	} no[maxn << 2];
	
	inline void push_up(int x) {
		no[x].mn = min(no[ls(x)].mn, no[rs(x)].mn);
	}
	
	inline void build_tree(int l, int r, int k) {
		if (l == r) {
			no[k].mn = aa[l];
			return;
		}
		int mid = (l + r) >> 1;
		build_tree(l, mid, ls(k));
		build_tree(mid + 1, r, rs(k));
		push_up(k);
	}
	
	inline void push_down(int x)  {
		if (no[x].lzy) {
			no[ls(x)].mn = max(no[x].lzy, no[ls(x)].mn);
			no[ls(x)].lzy = max(no[x].lzy, no[ls(x)].lzy);
			no[rs(x)].mn = max(no[x].lzy, no[rs(x)].mn);
			no[rs(x)].lzy = max(no[x].lzy, no[rs(x)].lzy);
			no[x].lzy = 0;
		}
	}
	
	inline void change(int l, int r, int k, int L, int R, LL x) {
		if (L <= l && r <= R) {
			no[k].mn = max(x, no[k].mn);
			no[k].lzy = max(x, no[k].lzy);
			return;
		}
		push_down(k);
		int mid = (l + r) >> 1;
		if (L <= mid) {
			change(l, mid, ls(k), L, R, x);
		}
		if (R > mid) {
			change(mid + 1, r, rs(k), L, R, x);
		}
		push_up(k);
	}
	
	inline int query(int l, int r, int k) {
		if (l == r) {
			ans[l] = max(lstans, no[k].mn) + p;


			no[k].mn = inf;
			lstans = ans[l];
			return l;
		}
		push_down(k);
		int mid = (l + r) >> 1, t;
		if (no[ls(k)].mn <= no[rs(k)].mn) {
			t = query(l, mid, ls(k));
		} else {
			t = query(mid + 1, r, rs(k));
		}
		push_up(k);
		return t;
	}
	
	inline void query() {
		int now = query(1, n, 1);
		change(1, n, 1, now, n, ans[now]);
	}
} tr;

int main() {
	read(n), read(p);
	for (int i = 1; i <= n; ++i) {
		read(aa[i]);
	}
	tr.build_tree(1, n, 1);
	for (int i = 1; i <= n; ++i) {
		tr.query();
	}
	for (int i = 1; i <= n; ++i) {
		id0(ans[i]);
	}
	return 0;
}