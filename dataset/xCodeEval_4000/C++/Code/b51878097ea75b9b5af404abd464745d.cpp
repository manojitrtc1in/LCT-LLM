
#include<string>
#include<set>
#include<vector>
#include<array>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<deque>
#include<iomanip>
#include<sstream>
#include<stack>
#include<limits.h>
#include<bitset>
#include<list>
#include<queue>
#include<map>
#include<memory>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int LEN = 2000000;
#define endl '\n'

struct io_in {
	inline char gc() {
		static char buf[LEN], *s, *t, buf2[LEN];
		return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
	}
	inline io_in & operator >> (long long&x) {
		static char ch, sgn, *p;
		ch = gc(), sgn = 0;
		for (; !isdigit(ch); ch = gc()) { if (ch == -1)return *this; sgn |= ch == '-'; }
		for (x = 0; isdigit(ch); ch = gc())x = x * 10 + (ch^'0');
		sgn && (x = -x); return *this;
	}
	inline io_in & operator >> (int &x) {
		static char ch, sgn, *p;
		ch = gc(), sgn = 0;
		for (; !isdigit(ch); ch = gc()) { if (ch == -1)return *this; sgn |= ch == '-'; }
		for (x = 0; isdigit(ch); ch = gc())x = x * 10 + (ch^'0');
		sgn && (x = -x); return *this;
	}
	inline io_in & operator >> (char&x)
	{
		static char ch;
		for (; !isalpha(ch) && !isdigit(ch); ch = gc())
			if (ch == -1)return *this;
		for (; isalpha(ch) || isdigit(ch); ch = gc())
			x = ch;
		return *this;
	}
	inline io_in & operator >> (string &x)
	{
		static char ch, *p, buf2[LEN];
		for (; !isalpha(ch) && !isdigit(ch); ch = gc())
			if (ch == -1)return *this;
		p = buf2;
		for (; isalpha(ch) || isdigit(ch); ch = gc())
			*p = ch, p++;
		*p = '\0';
		x = buf2;
		return *this;
	}
} cin;
struct io_out
{
	char obuf[LEN], *oh = obuf;
	inline io_out & operator <<(string &c)
	{
		for (auto &p : c)
			this->operator<<(p);
		return *this;
	}
	inline io_out & operator <<(const char *c)
	{
		while (*c != '\0')
		{
			this->operator<<(*c);
			c++;
		}
		return *this;
	}
	inline io_out & operator <<(const char &c) {
		oh == obuf + LEN ? (fwrite(obuf, 1, LEN, stdout), oh = obuf) : 0;
		*oh++ = c;
		return *this;
	}
	inline io_out & operator <<(int x) {
		static int buf[60], cnt;
		if (x < 0)
			this->operator<<('-'), x = -x;
		if (x == 0)
			this->operator<<('0');
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
		while (cnt) this->operator<<((char)buf[cnt--]);
		return *this;
	}
	inline io_out & operator <<(long long x) {
		static int buf[60], cnt;
		if (x < 0)
			this->operator<<('-'), x = -x;
		if (x == 0)
		{
			this->operator<<('0');
			return *this;
		}
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
		while (cnt) this->operator<<((char)buf[cnt--]);
		return *this;
	}
	~io_out()
	{
		fwrite(obuf, 1, oh - obuf, stdout);
	}
}cout;
namespace trie01
{
	const int sigma = 20;
	long long base = 1;
	struct node
	{
		node *child[2];
		int times;
		int element;
		bool lazy;
		void clear()
		{
			lazy = times = element = 0;
		}
	};
	node *history[200000];
	node _pool[10000000];
	node *root, *cur = _pool, *null;
	node *new_()
	{
		cur->clear();
		cur->child[0] = cur->child[1] = null;
		return cur++;
	}
	void init()
	{
		null = new node();
		null->times = null->element = null->lazy = 0;
		null->child[0] = null->child[1] = null;
		cur = _pool;
		root = new_();
		history[0] = new_();
	}
	void insert(node *ver_s, int pos, int element, int add)
	{
		node *found = ver_s;
		bitset<sigma + 1> kkk = pos;
		found->times += add;
		for (int i = sigma; i >= 0; --i)
		{
			if (found->child[kkk[i]] == null)
			{
				found->child[kkk[i]] = new_();
				found = found->child[kkk[i]];
			}
			else
				found = found->child[kkk[i]];
			found->times += add;
		}
		found->element = element;
	}
	node *insert_new(int pos, int element, node *old, int add)
	{
		node *found = old, *_new = new_(), *_new2;
		bitset<sigma + 1> kkk = pos;
		_new2 = _new;
		for (int i = sigma; i >= 0; --i)
		{
			_new->times += add;
			_new->child[kkk[i]] = new_();
			if (found == null)
				_new = _new->child[kkk[i]];
			else
			{
				_new->times += found->times;
				_new->child[!kkk[i]] = found->child[!kkk[i]];
				_new = _new->child[kkk[i]];
				found = found->child[kkk[i]];
			}
		}
		_new->times += found->times;
		_new->times += add;
		_new->element = element;
		return _new2;
	}
	int rank(node *p, int pos)
	{
		bitset<sigma + 1> kkk = pos;
		int rk = 1;
		for (int i = sigma; i >= 0; --i)
		{
			if (kkk[i])
				rk += p->child[0]->times;
			p = p->child[kkk[i]];
		}
		return rk;
	}
	int find(node *p, int pos)
	{
		bitset<sigma + 1> kkk = pos;
		for (int i = sigma; i >= 0; --i)
			p = p->child[kkk[i]];
		return p->times;
	}
	int kth(node *p, int s)
	{
		bitset<sigma + 1> ans;
		for (int i = sigma; i >= 0; --i)
			if (p->child[0]->times < s)
			{
				s -= p->child[0]->times;
				ans[i] = 1;
				p = p->child[1];
			}
			else
				p = p->child[0], ans[i] = 0;
		return ans.to_ulong();
	}
	int rank(int L, int R, int pos)
	{
		node* PL = history[L - 1], *PR = history[R];
		bitset<sigma + 1> kkk = pos;
		int rk = 1;
		for (int i = sigma; i >= 0; --i)
		{
			if (kkk[i])
				rk += PR->child[0]->times - PL->child[0]->times;
			PL = PL->child[kkk[i]];
			PR = PR->child[kkk[i]];
		}
		return rk;
	}
	int prefix(node *p, int pos)
	{
		bitset<sigma + 1> kkk = pos;
		int rk = 0;
		for (int i = sigma; i >= 0; --i)
		{
			if (kkk[i])
				rk += p->child[0]->times;
			p = p->child[kkk[i]];
		}
		rk += p->times;
		return rk;
	}
	int querysum(node *p, int L, int R)
	{
		return prefix(p, R) - prefix(p, L - 1);
	}
	int kth(int L, int R, int s)
	{
		node* PL = history[L - 1], *PR = history[R];
		int rk;
		for (int i = sigma; i >= 0; --i)
		{
			rk = PR->child[0]->times - PL->child[0]->times;
			if (rk < s)
			{
				s -= rk;
				PL = PL->child[1];
				PR = PR->child[1];
			}
			else
			{
				PL = PL->child[0];
				PR = PR->child[0];
			}
		}
		return rk;
	}
	void merge(node *a, node *b)
	{
		b->times += a->times;
		for (int i = 0; i < 2; ++i)
		{
			if (a->child[i] != null && b->child[i] != null)
				merge(a->child[i], b->child[i]);
			else if (b->child[i] == null)
				b->child[i] = a->child[i];
		}
	}
	node *merge2(node *x, node *y) 

	{
		if (x == null) return y;
		if (y == null) return x;
		node *merge_version = new_();
		merge_version->times = y->times + x->times;
		merge_version->child[0] = merge2(x->child[0], y->child[0]);
		merge_version->child[1] = merge2(x->child[1], y->child[1]);
		return merge_version;
	}
	void merge_all(node *x, node *y) 

	{
		y->times += x->times;
		y->child[0] = merge2(x->child[0], y->child[0]);
		y->child[1] = merge2(x->child[1], y->child[1]);
	}
}
using namespace trie01;
using namespace std;
const int N = 200010;
struct EXSAM_node
{
	EXSAM_node *next[26], *pre;
	int rank;
	int step;
	int sign;
	int belong;
	int firstpos;
	node *cnt;
	void clear(int k)
	{
		cnt = new_();
		rank = 0;
		belong = 0;
		firstpos = 0;
		sign = k;
		pre = NULL;
		step = 0;
		memset(next, 0, sizeof(next));
	}

};
EXSAM_node EXSAM_Pool[N * 2];
EXSAM_node *EXpool[N * 2];
int d[N * 2];
string spool[N];
struct EXSAM
{
	EXSAM_node *root, *last;
	EXSAM_node  *cur;
	void init()
	{
		cur = EXSAM_Pool;
		root = last = cur++;
		root->clear(cur - EXSAM_Pool);
	}
	EXSAM_node *newnode()
	{
		cur->clear(cur - EXSAM_Pool + 1);
		return cur++;
	}
	void Insert(int w, int i, int j)

	{
		EXSAM_node *p = last;
		if (p->next[w] && p->next[w]->step == p->step + 1)
		{
			last = p->next[w];
			insert(last->cnt, j, j, 1);
			return;
		}
		EXSAM_node *np = newnode();
		np->step = p->step + 1;
		np->firstpos = j; 

		while (p && !p->next[w])
		{
			p->next[w] = np, p = p->pre;
		}
		if (p == 0)
			np->pre = root;
		else
		{
			EXSAM_node *q = p->next[w];
			if (p->step + 1 == q->step)
				np->pre = q;
			else
			{
				EXSAM_node *nq = newnode();
				nq->step = p->step + 1;
				memcpy(nq->next, q->next, sizeof(q->next));
				nq->pre = q->pre;
				nq->belong = q->belong;
				nq->firstpos = q->firstpos;
				q->pre = nq;
				np->pre = nq;
				while (p&&p->next[w] == q)
				{
					p->next[w] = nq, p = p->pre;
				}
			}
		}
		last = np;
		last->belong = i;
		insert(last->cnt, j, j, 1);
	}

	void topo()
	{
		int cnt = cur - EXSAM_Pool;
		int maxVal = 0;
		memset(d, 0, sizeof(d));
		for (int i = 1; i < cnt; i++)
		{
			maxVal = max(maxVal, EXSAM_Pool[i].step), d[EXSAM_Pool[i].step]++;
		}
		for (int i = 1; i <= maxVal; i++)
			d[i] += d[i - 1];
		for (int i = 1; i < cnt; i++)
			EXpool[d[EXSAM_Pool[i].step]--] = &EXSAM_Pool[i];
		EXpool[0] = root;
	}
}part;
EXSAM_node *trans[N * 2];
EXSAM_node *Last[N * 2];
void build(string &s, int i)
{
	for (int j = 0; j < s.size(); ++j)
	{
		part.Insert(s[j] - 'a', i, j + 1);
	}
	EXSAM_node *r = part.root;
	for (int j = 0; j < s.size(); ++j)
	{
		r = r->next[s[j] - 'a'];
		Last[j + 1] = r;
	}
	spool[i] = s;
	part.last = part.root;
}
vector<pair<int, int> > edge[N * 2];
void addedge(int u, int v, int w)
{
	edge[u].push_back({ w,v });
}
int dfslen;
void dfs(int a)
{
	trans[a]->rank = dfslen;
	for (auto &p : edge[a])
	{
		dfslen++;
		dfs(p.second);
	}
}
void EXST()
{
	EXSAM_node *p;
	p = part.root;
	trans[1] = p;
	p++;
	for (int i = 0; i < part.cur - EXSAM_Pool + 10; ++i)
		edge[i].clear();
	while (p != part.cur)
		addedge(p->pre->sign, p->sign, spool[p->belong][p->firstpos - p->pre->step - 1]), trans[p->sign] = p, p++;
	for (int i = 0; i < part.cur - EXSAM_Pool + 10; ++i)
		sort(edge[i].begin(), edge[i].end());
	dfslen = 0;
	dfs(1);
}
void EXST2()
{
	EXSAM_node *p;
	p = part.root;
	trans[1] = p;
	p++;
	for (int i = 0; i < part.cur - EXSAM_Pool + 10; ++i)
		edge[i].clear();
	while (p != part.cur)
		addedge(p->pre->sign, p->sign, spool[p->belong][p->firstpos - p->pre->step - 1]), trans[p->sign] = p, p++;
}
string trans2(EXSAM_node *p, int len)
{
	string p2;
	for (int i = p->firstpos - 1; i >= p->firstpos - len; --i)
		p2.append(1, spool[p->belong][i]);
	return p2;
}
const int maxn = 230000;
const int max2 = 20;
int father[max2][maxn];
void init(int n)
{
	memset(father, 0, sizeof(father));
	int Max = N * 2;
	for (int i = 0; i < Max; ++i)
		edge[i].clear();
}
void dfs2(int x)
{
	for (auto &s : edge[x])
	{
		if (father[0][x] != s.second)
		{
			father[0][s.second] = x;
			dfs2(s.second);
		}
	}
}
void  build(int root, int n)
{
	dfs2(root);
	for (int k = 0; k < max2; k++)  

		for (int i = 1; i <= n; i++)
			if (father[k][i])
				father[k + 1][i] = father[k][father[k][i]];
}
EXSAM_node *substring(int L, int R)
{
	int len = R - L + 1;
	int p = Last[R]->sign;
	for (int k = max2 - 1; k >= 0; k--)
	{
		if (father[k][p] == 0)
			continue;
		if (trans[father[k][p]]->step >= len)
			p = father[k][p];
	}
	return trans[p];
}
void single(string &s)
{
	int n = s.size();
	init();
	init(n);
	part.init();
	build(s, 1);
	EXST();
	int cnt = part.cur - EXSAM_Pool - 1;
	build(1, cnt + 100);
	part.topo();
	for (int i = cnt; i > 0; --i)
		merge_all(EXpool[i]->cnt, EXpool[i]->pre->cnt);
}
int ans;
#define  G(x,y) get<y>(x)
stack<tuple<EXSAM_node*, int, int> > st;
list<char> solve(int l, int r, string &s)
{
	list<char> ans;
	while (!st.empty())
		st.pop();
	EXSAM_node *p = part.root;
	for (int i = 0; i < s.size(); ++i)
	{
		int k = s[i] - 'a';
		for (int j = 25; j > k; --j)
			if (p->next[j] != NULL)
				st.push(make_tuple(p->next[j], i, j));
		if (p->next[k] != NULL)
			p = p->next[k];
		else
		{
			p = NULL;
			break;
		}
	}
	if (p)
		for (int i = 25; i >= 0; --i)
			if (p->next[i])
				st.push(make_tuple(p->next[i], s.size(), i));
	bool flag = false;
	while (!st.empty())
	{
		auto p = st.top();
		st.pop();
		if (l + G(p, 1) <= r && querysum(G(p, 0)->cnt, l + G(p, 1), r) != 0)
		{
			flag = true;
			for (int i = 0; i < G(p, 1); ++i)
				ans.push_back(s[i]);
			ans.push_back(char(G(p, 2) + 'a'));
		}
		if (flag) break;
	}
	if (flag)
		return ans;
	else
	{
		ans.clear();
		return ans;
	}
}
int main()
{
	string s, qs;
	cin >> s;
	part.init();
	single(s);
	int q, l, r;
	cin >> q;
	list<char> ans;
	while (q--)
	{
		cin >> l >> r >> s;
		ans = solve(l, r, s);
		if (ans.empty())
			cout << -1 << '\n';
		else
		{
			for (auto &p : ans)
				cout << p;
			cout << '\n';
		}
	}
	return 0;
}
