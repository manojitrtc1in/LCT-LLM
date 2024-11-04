
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<deque>
#include<iomanip>
#include<sstream>
#include<stack>
#include<iostream>
#include<limits>
#include<bitset>
#include<list>
#include<queue>
#include<memory>
#include<functional>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<deque>
#include<iomanip>
#include<sstream>
#include<stack>
#include<iostream>
#include<limits>
#include<bitset>
#include<list>
#include<queue>
#include<memory>
#include<functional>
#include<cstdio>
#include<tuple>
using namespace std;
#define  G(x,y) get<y>(x)
#include<string>
#include<vector>
#include<regex>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<iomanip>
#include<sstream>
#include<stack>
#include<iostream>
#include<limits>
#include<bitset>
#include<list>
#include<queue>
#include<array>
#include<memory>
#include<functional>
#include<unordered_map>
using namespace std;


namespace tree1 

{
	const int inf = 100000100;
	const int L_ = 1;
	const int R_ = 0x7fffffff - 1;
	const int N2 = 8000000;
	struct node
	{
		node *L, *R;
		int l, r, val;
		void clear()
		{
			L = R = NULL;
			l = r = val = 0;
		}
	};
	node pool[N2], *cur, *null;
	void clear()
	{
		cur = pool;
		null = cur++;
		null->l = null->r = null->val = 0, null->L = null, null->R = null;
		cur->clear();
	}
	node *new_node(int L, int R, int val)
	{
		cur->l = L, cur->r = R, cur->val = val;
		cur->L = null, cur->R = null;
		return cur++;
	}
	void pl(node *a)
	{
		if ((a->L != null) || (a->l == a->r))
			return;
		int mid = (a->l + a->r) / 2;
		a->L = new_node(a->l, mid, 0);
	}
	void pr(node *a)
	{
		if ((a->R != null) || (a->l == a->r))
			return;
		int mid = (a->l + a->r) / 2;
		a->R = new_node(mid + 1, a->r, 0);
	}

	node* insert(node *old_version, int k)

	{
		int l = old_version->l, r = old_version->r;
		node * new_version = new_node(l, r, old_version->val + 1);
		if (l != r)
		{
			int mid = (l + r) / 2;
			if (k >= mid + 1)
			{
				pr(old_version);
				new_version->R = insert(old_version->R, k);
				new_version->L = old_version->L;
			}
			else
			{
				pl(old_version);
				new_version->L = insert(old_version->L, k);
				new_version->R = old_version->R;
			}
		}
		return new_version;
	}
	void insert_cur(node *cur_version, int k)

	{
		int l = cur_version->l, r = cur_version->r;
		int mid = (l + r) / 2;
		cur_version->val++;
		if (l != r)
		{
			if (k >= mid + 1)
				pr(cur_version), insert_cur(cur_version->R, k);
			else
				pl(cur_version), insert_cur(cur_version->L, k);
		}
	}
	void insert_cur_n(node *cur_version, int k, int data)

	{
		int l = cur_version->l, r = cur_version->r;
		int mid = (l + r) / 2;
		cur_version->val += data;
		if (l != r)
		{
			if (k >= mid + 1)
				pr(cur_version), insert_cur_n(cur_version->R, k, data);
			else
				pl(cur_version), insert_cur_n(cur_version->L, k, data);
		}
	}
	node* insert_n(node *old_version, int k, int data)

	{
		int l = old_version->l, r = old_version->r;
		node * new_version = new_node(l, r, old_version->val + data);
		if (l != r)
		{
			int mid = (l + r) / 2;
			if (k >= mid + 1)
			{
				pr(old_version);
				new_version->R = insert_n(old_version->R, k, data);
				new_version->L = old_version->L;
			}
			else
			{
				pl(old_version),
					new_version->L = insert_n(old_version->L, k, data);
				new_version->R = old_version->R;
			}
		}
		return new_version;
	}
	node *merge(node *x, node *y) 

	{
		if (x == null) return y;
		if (y == null) return x;
		node *merge_version = new_node(x->l, x->r, y->val + x->val);
		merge_version->L = merge(x->L, y->L);
		merge_version->R = merge(x->R, y->R);
		return merge_version;
	}
	void update(node *x) 

	{
		if (x->l == x->r) return;
		x->val = 0;
		x->val += x->L->val;
		x->val += x->R->val;
	}
	void merge_all(node *x, node *y) 

	{
		y->val += x->val;
		y->L = merge(x->L, y->L);
		y->R = merge(x->R, y->R);
	}
	int query_sum(node *x, int L, int R) 

	{
		if (x == null) return 0;
		int sum = 0;
		int mid = (x->l + x->r) / 2;
		if (x->l == L && x->r == R)
			return x->val;
		else
		{
			if (L <= mid && R > mid)
				return query_sum(x->L, L, mid) + query_sum(x->R, mid + 1, R);
			else if (R <= mid)
				return query_sum(x->L, L, R);
			else if (L >= mid + 1)
				return query_sum(x->R, L, R);
		}
	}
	void merge(int L, int R, node *x, node *y) 

	{
		if (x == null) return;
		int mid = (x->l + x->r) / 2;
		if (x->l == L && x->r == R)
		{
			y->val += x->val;
			y->L = merge(x->L, y->L);
			y->R = merge(x->R, y->R);
			

		}
		else
		{
			pl(y), pr(y);
			if (L <= mid && R > mid)
				merge(L, mid, x->L, y->L), merge(mid + 1, R, x->R, y->R);
			else if (R <= mid)
				merge(L, R, x->L, y->L);
			else if (L >= mid + 1)
				merge(L, R, x->R, y->R);
		}
		update(x);
	}
	int query_rank(node *p, int L, int R, int k)
	{
		int l = L_, r = R_;
		int all_rank = 1;
		while (l != r)
		{
			int rk = 0;
			rk += p->L->val;
			int mid = (l + r) / 2;
			if (k <= mid)
			{
				r = mid;
				p = p->L;
			}
			else
			{
				all_rank += rk;
				l = mid + 1;
				p = p->R;
			}
		}
		return all_rank;
	}
	struct node2
	{
		node2 *L, *R;
		int l, r, val;
		node *tree2;
		vector<pair<int, int> > *lazy;
	};
	void pl(node2 *a)
	{
		if ((a->L != NULL) || (a->l == a->r))
			return;
		int mid = (a->l + a->r) / 2;
		a->L = new node2();
		a->L->l = a->l, a->L->r = mid, a->L->val = 0;
	}
	void pr(node2 *a)
	{
		if ((a->R != NULL) || (a->l == a->r))
			return;
		int mid = (a->l + a->r) / 2;
		a->R = new node2();
		a->R->l = mid + 1, a->R->r = a->r, a->R->val = 0;
	}
	void build(int *p, node2 *x)
	{
		x->lazy = new vector<pair<int, int>>();
		x->tree2 = new_node(L_, R_, 0);
		pl(x), pr(x);
		if (x->l == x->r)
		{
			x->val = p[x->l];
			return;
		}
		else
			build(p, x->L), build(p, x->R);
		


	}
	int se1;
	node * segment[50];
	void pd(node2 *p)
	{
		for (auto &s : *(p->lazy))
			insert_cur_n(p->tree2, s.first, s.second);
		(*p->lazy).clear();
	}
	void split(node2 *p, int l, int r)
	{
		if (p->l == l && p->r == r)
		{
			pd(p);
			segment[se1++] = (p->tree2);
			return;
		}
		int mid = (p->l + p->r) / 2;
		if (l <= mid && r > mid)
			split(p->L, l, mid), split(p->R, mid + 1, r);
		else if (r <= mid)
			split(p->L, l, r);
		else if (l >= mid + 1)
			split(p->R, l, r);
	}
	node *history[100010];
	int query_kth(node2 *p, int L, int R, int k)
	{
		se1 = 0;
		node *lh = history[L - 1], *rh = history[R];
		split(p, L, R);
		int l = L_, r = R_;
		while (l != r)
		{
			int rk = 0;
			rk += rh->L->val;
			rk -= lh->L->val;
			int mid = (l + r) / 2;
			for (int i = 0; i < se1; ++i)
				rk += segment[i]->L->val;
			if (rk >= k)
			{
				r = mid;
				rh = rh->L;
				lh = lh->L;
				for (int i = 0; i < se1; ++i)
					segment[i] = segment[i]->L;
			}
			else
			{
				l = mid + 1;
				k -= rk;
				rh = rh->R;
				lh = lh->R;
				for (int i = 0; i < se1; ++i)
					segment[i] = segment[i]->R;
			}
		}
		return l;
	}
	int query_rank(node2 *p, int L, int R, int k)
	{
		se1 = 0;
		node *lh = history[L - 1], *rh = history[R];
		split(p, L, R);
		int l = L_, r = R_;
		int all_rank = 1;
		while (l != r)
		{
			int rk = 0;
			rk += rh->L->val;
			rk -= lh->L->val;
			int mid = (l + r) / 2;
			for (int i = 0; i < se1; ++i)
				rk += segment[i]->L->val;
			if (k <= mid)
			{
				r = mid;
				rh = rh->L;
				lh = lh->L;
				for (int i = 0; i < se1; ++i)
					segment[i] = segment[i]->L;
			}
			else
			{
				all_rank += rk;
				l = mid + 1;
				rh = rh->R;
				lh = lh->R;
				for (int i = 0; i < se1; ++i)
					segment[i] = segment[i]->R;
			}
		}
		return all_rank;
	}
	void split2(node2 *p, int l, int pre, int k)
	{
		if (p->l != p->r)
		{
			int mid = (p->l + p->r) / 2;
			if (l <= mid)
				split2(p->L, l, pre, k);
			else
				split2(p->R, l, pre, k);
		}
		

		

		p->lazy->push_back({ pre, -1 });
		p->lazy->push_back({ k, 1 });
	}
}
using namespace tree1;

#define For(n) for(int i=0;i<n;++i)
using namespace std;
const int N = 200010;
struct EXSAM_node
{

	EXSAM_node  *next[26], *pre;
	node *segment;
	int step;
	bool vis;
	int pos;
	void clear(int p, int k)
	{
		segment = new_node(1, k + 5, 0);
		pos = p;
		vis = 0;
		pre = NULL;
		step = 0;
		memset(next, 0, sizeof(next));
		

	}
};
EXSAM_node EXSAM_Pool[N * 2];
EXSAM_node *EXpool[N * 2];
long d[N * 2];
struct EXSAM
{
	EXSAM_node *root, *last;
	EXSAM_node  *cur;
	void init(int k)
	{
		cur = EXSAM_Pool;  

		root = last = cur++;
		root->clear(1, k);
	}
	void Insert(int w, int i, int k)

	{
		EXSAM_node *p = last;
		if (p->next[w] && p->next[w]->step == p->step + 1)
		{
			last = p->next[w];
			insert_cur_n(last->segment, i, 1);
			return;
		}
		EXSAM_node *np = cur++;
		np->clear(cur - EXSAM_Pool - 1, k);
		np->step = p->step + 1;
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
				EXSAM_node *nq = cur++;
				nq->clear(cur - EXSAM_Pool - 1, k);
				nq->step = p->step + 1;
				memcpy(nq->next, q->next, sizeof(q->next));
				nq->pre = q->pre;
				

				q->pre = nq;
				np->pre = nq;
				while (p&&p->next[w] == q)
				{
					p->next[w] = nq, p = p->pre;
				}
			}
		}
		last = np;
		insert_cur_n(last->segment, i, 1);
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
EXSAM_node *last[N];
string s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	clear();
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	part.init(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		part.last = part.root;
		for (auto &p : s[i])
			part.Insert(p - 'a', i, n + 2);
	}
	part.topo();
	int cnt = part.cur - EXSAM_Pool;
	for (int i = cnt - 1; i > 0; --i)
		merge_all(EXpool[i]->segment, EXpool[i]->pre->segment);
	int l, r, k;
	for (int i = 1; i <= n; ++i)
	{
		EXSAM_node *f = part.root;
		for (auto &p : s[i])
			f = f->next[p - 'a'];
		last[i] = f;
	}
	while (q--)
	{
		cin >> l >> r >> k;
		cout << query_sum(last[k]->segment, l, r) << '\n';
	}
	return 0;
}




