
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <functional>
#include <map>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <random>

using namespace std;

typedef long long ll;
#define pii pair<ll, int>
#define mp make_pair

ll read() {
	int f = 1;
	ll res = 0;
	char ch;
	do {
		ch = getchar();
		if (ch == '-') f = -f;
	} while (ch < '0' || ch > '9');
	do {
		res = res * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	return f == 1 ? res : -res;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N = 500010;
const int mod = 998244353;
const ll INF = 1e18;
int n, m, q;
int A[N], B[N];
char str[N];

int head[N * 2], to[N * 2], nxt[N * 2], tot;
void addEdge(int u, int v) {
	tot++;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

template <class T>
T mmax(T a, T b) {
	return a < b ? b : a;
}

template <class T>
T mmin(T a, T b) {
	return a < b ? a : b;
}

int countOne(int set) {
	int res = 0;
	while (set) {
		res++;
		set &= set - 1;
	}
	return res;
}

bool contain(int set, int i) {
	return (set & (1 << i)) > 0;
}

ll myPow(ll a, int p) {
	if (p == 0) return 1;
	ll res = myPow(a, p / 2);
	res *= res;
	res %= mod;
	if (p % 2 == 1) {
		res *= a;
		res %= mod;
	}
	return res;
}

void addMode(int &a, ll b) {
	a = (a + b) % mod;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

template <class T>
void mySwap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

pii cnt[N];
pii query[N];
int ans[N];

bool cmp(int a, int b) {
	if (cnt[a] == cnt[b]) return a < b;
	return cnt[a] < cnt[b];
}

const int MAXN = 1000007;

struct SplayTree {

	int f[MAXN], cnt[MAXN], ch[MAXN][2], size[MAXN], key[MAXN], sz, rt;

	void clear(int x)
	{
		f[x] = cnt[x] = ch[x][0] = ch[x][1] = size[x] = key[x] = 0;
	}

	bool get(int x)
	{
		return ch[f[x]][1] == x;
	}

	void pushup(int x)
	{
		if (x)
		{
			size[x] = cnt[x];
			if (ch[x][0]) size[x] += size[ch[x][0]];
			if (ch[x][1]) size[x] += size[ch[x][1]];
		}
	}

	void rotate(int x)
	{
		int old = f[x], oldf = f[old], which = get(x);
		ch[old][which] = ch[x][which ^ 1]; f[ch[old][which]] = old;  

																	 

		ch[x][which ^ 1] = old; f[old] = x;
		

		f[x] = oldf;

		if (oldf) ch[oldf][ch[oldf][1] == old] = x;
		pushup(old); pushup(x);

	}

	void splay(int x)
	{
		for (int fa; fa = f[x]; rotate(x))
			if (f[fa])
				rotate((get(x) == get(fa)) ? fa : x);

		rt = x;
	}

	void insert(int x)

	{
		if (rt == 0)
		{
			sz++; key[sz] = x; rt = sz;
			cnt[sz] = size[sz] = 1;
			f[sz] = ch[sz][0] = ch[sz][1] = 0;
			return;
		}
		int now = rt, fa = 0;
		while (1)
		{
			if (x == key[now])

			{
				cnt[now]++; pushup(now); pushup(fa); splay(now); return;
			}
			fa = now; now = ch[now][key[now]<x];
			if (now == 0)
			{
				sz++;
				size[sz] = cnt[sz] = 1;
				ch[sz][0] = ch[sz][1] = 0;
				ch[fa][x>key[fa]] = sz;

				f[sz] = fa;
				key[sz] = x;
				pushup(fa); splay(sz); return;
			}
		}
	}

	int rnk(int x)

	{
		int now = rt, ans = 0;
		while (1)
		{
			if (x<key[now]) now = ch[now][0];
			else
			{
				ans += size[ch[now][0]];
				if (x == key[now])
				{

					splay(now); return ans + 1;
				}
				ans += cnt[now];
				now = ch[now][1];

			}
		}
	}

	int kth(int x)
	{

		int now = rt;
		int num = 0;
		while (1)
		{
			if (num > 1000) return -1;
			num++;
			if (ch[now][0] && x <= size[ch[now][0]])
				now = ch[now][0];
			else
			{
				int temp = size[ch[now][0]] + cnt[now];
				if (x <= temp)
					return key[now];
				x -= temp; now = ch[now][1];
			}
		}
	}

	int pre()

	{

		int now = ch[rt][0];
		while (ch[now][1]) now = ch[now][1];
		return now;
	}

	int next()
	{
		int now = ch[rt][1];
		while (ch[now][0]) now = ch[now][0];
		return now;
	}

	void del(int x)
	{
		rnk(x);
		if (cnt[rt]>1) { cnt[rt]--; pushup(rt); return; }

		if (!ch[rt][0] && !ch[rt][1]) { clear(rt); rt = 0; return; }
		if (!ch[rt][0]) {
			int oldrt = rt; rt = ch[rt][1]; f[rt] = 0; clear(oldrt); return;
		}
		else if (!ch[rt][1]) {
			int oldrt = rt; rt = ch[rt][0]; f[rt] = 0; clear(oldrt); return;
		}
		int oldrt = rt; int leftbig = pre();
		splay(leftbig);
		ch[rt][1] = ch[oldrt][1];
		f[ch[oldrt][1]] = rt;
		clear(oldrt);
		pushup(rt);
	}
};


struct fhqTreap {
#define ls c[rt][0]
#define rs c[rt][1]
	int c[N][2], sz[N], val[N], ra[N], cnt, RT;
	int rand() {
		static int seed = 233;
		return seed = (int)seed * 482711LL % 2147483647;
	}
	int ne(int v) { sz[++cnt] = 1; val[cnt] = v; ra[cnt] = rand(); return cnt; }
	void pu(int rt) { sz[rt] = sz[ls] + sz[rs] + 1; }
	void sl(int rt, int k, int &x, int &y) {
		if (!rt) { x = y = 0; return; }
		if (val[rt]>k)y = rt, sl(ls, k, x, ls);
		else x = rt, sl(rs, k, rs, y);
		pu(rt);
	}
	int mg(int x, int y) {
		if (!x || !y)return x + y;
		if (ra[x]<ra[y]) {
			c[x][1] = mg(c[x][1], y);
			pu(x);
			return x;
		}
		else {
			c[y][0] = mg(x, c[y][0]);
			pu(y);
			return y;
		}
	}
	void ins(int v) {
		int x, y;
		sl(RT, v, x, y);
		RT = mg(mg(x, ne(v)), y);
	}
	void del(int v) {
		int x, y, z;
		sl(RT, v, x, z);
		sl(x, v - 1, x, y);
		RT = mg(mg(x, mg(c[y][0], c[y][1])), z);
	}
	int kth(int rt, int k) {
		if (k <= sz[ls])return kth(ls, k);
		if (k == sz[ls] + 1)return rt;
		return kth(rs, k - sz[ls] - 1);
	}
	int frk(int v) {
		int x, y, t;
		sl(RT, v - 1, x, y);
		t = sz[x] + 1;
		RT = mg(x, y);
		return t;
	}
	int pre(int v) {
		int x, y, t;
		sl(RT, v - 1, x, y);
		t = val[kth(x, sz[x])];
		RT = mg(x, y);
		return t;
	}
	int nxt(int v) {
		int x, y, t;
		sl(RT, v, x, y);
		t = val[kth(y, 1)];
		RT = mg(x, y);
		return t;
	}
};


struct Treap {
	int tot, root;

	struct Treap_node {
		int rd, sz, ch[2], cnt, key;
	}t[N];

	Treap() {
		tot = root = 0;
		memset(t, 0, sizeof(t));
	}
	


	void push_up(int p) {
		t[p].sz = t[p].cnt;
		t[p].sz += t[t[p].ch[0]].sz;
		t[p].sz += t[t[p].ch[1]].sz;
	}
	


	void rotate(int &p, int dir) {
		

		int s = t[p].ch[dir ^ 0];
		t[p].ch[dir ^ 0] = t[s].ch[dir ^ 1];
		t[s].ch[dir ^ 1] = p;
		push_up(p);
		push_up(s);
		p = s;
	}
	


	void Insert(int &p, int key) {
		if (p == 0) {
			p = ++tot;
			t[p].sz = 1;
			t[p].cnt = 1;
			t[p].key = key;
			t[p].rd = rand();
			return;
		}
		++t[p].sz;
		if (t[p].key == key) {
			++t[p].cnt;
		}
		else {
			int dir = key > t[p].key;
			Insert(t[p].ch[dir], key);
			if (t[p].rd > t[t[p].ch[dir]].rd) {
				rotate(p, dir);
			}
		}
	}
	


	void Delete(int &p, int key) {
		if (p == 0) {
			return;
		}
		if (t[p].key == key) {
			if (t[p].cnt > 1) {
				--t[p].sz;
				--t[p].cnt;
			}
			else {
				if (t[p].ch[0] * t[p].ch[1] == 0) {
					

					p = t[p].ch[0] + t[p].ch[1];
				}
				else {
					if (t[p].ch[0] < t[p].ch[1]) {
						rotate(p, 0);
					}
					else {
						rotate(p, 1);
					}
					Delete(p, key);
				}
			}
		}
		else {
			--t[p].sz;
			Delete(t[p].ch[key > t[p].key], key);
		}
	}
	


	int pre(int key) {
		int p = root, ans = 0;
		while (p != 0) {
			if (t[p].key < key) {
				ans = t[p].key;
				p = t[p].ch[1];
			}
			else {
				p = t[p].ch[0];
			}
		}
		return ans;
	}
	


	int nxt(int key) {
		int p = root, ans = 0;
		while (p != 0) {
			if (t[p].key > key) {
				ans = t[p].key;
				p = t[p].ch[0];
			}
			else {
				p = t[p].ch[1];
			}
		}
		return ans;
	}
	


	int kth(int k) {
		int p = root;
		while (p != 0) {
			if (k <= t[t[p].ch[0]].sz) {
				p = t[p].ch[0];
			}
			else if (k > t[t[p].ch[0]].sz + t[p].cnt) {
				k -= t[t[p].ch[0]].sz + t[p].cnt;
				p = t[p].ch[1];
			}
			else {
				return t[p].key;
			}
		}
		return false;
	}
	


	int get_rnk(int key) {
		int p = root, ans = 0;
		while (p != 0) {
			if (key < t[p].key) {
				p = t[p].ch[0];
			}
			else if (key > t[p].key) {
				ans += t[p].cnt;
				ans += t[t[p].ch[0]].sz;
				p = t[p].ch[1];
			}
			else {
				return ans + t[t[p].ch[0]].sz + 1;
			}
		}
		return false;
	}
	

}treap;

int main() {



	
	n = read();
	m = read();
	q = read();
	for (int i = 1; i <= m; i++) cnt[i].second = i;
	for (int i = 1; i <= n; i++) {
		int a = read();
		cnt[a].first++;
	}
	sort(cnt + 1, cnt + m + 1);
	for (int i = 0; i < q; i++) {
		query[i].first = read();
		query[i].second = i;
	}
	sort(query, query + q);
	int k = 1;
	
	for (; k <= m; k++) {
		if (cnt[k].second) break;
		treap.Insert(treap.root, cnt[k].second);
	}
	ll pre = n;
	ll hold = 0;
	int start = 0;
	for (int i = 0; i < q; i++) {
		ll diff = query[i].first - pre;
		if (diff == 0) {
			ans[query[i].second] = ans[query[i - 1].second];
			continue;
		}
		pre = query[i].first;
		if (start != 0) {
			if (diff > treap.tot - start) {
				diff -= treap.tot - start;
				hold++;
			}
			else {
				int it = treap.kth(start + diff);
				ans[query[i].second] = it;
				start += diff;
				if (start == treap.tot) {
					start = 0;
					hold++;
				}
				continue;
			}
		}

		while (k <= m && 1LL * treap.tot * (cnt[k].first - hold) < diff) {
			diff -= 1LL * treap.tot * (cnt[k].first - hold);
			treap.Insert(treap.root, cnt[k].second);
			hold = cnt[k].first;
			k++;
		}

		if (diff > treap.tot) {
			hold += diff / treap.tot;
			diff = diff % treap.tot;
		}
		if (diff == 0) {
			diff = treap.tot;
			hold--;
		}
		start = diff;
		int it = treap.kth(start);
		ans[query[i].second] = it;
		if (start == treap.tot) {
			start = 0;
			hold++;
		}
	}

	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	
	

	return 0;
}