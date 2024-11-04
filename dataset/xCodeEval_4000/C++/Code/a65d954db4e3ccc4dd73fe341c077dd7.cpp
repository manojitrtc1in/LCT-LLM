

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include<cstdio>
using namespace std;
const int N = 800010;
const int INF = 1 << 30;

int n, tim;

long long num[N];
int siz[N], top[N], son[N];
int dep[N], tid[N], Rank[N], fa[N];
int head[N], to[2 * N], Next[2 * N], w[2 * N], edge;
int flag = 0;
struct Edge
{
	int u, v;
	long long c;
};
Edge tmp[2 * N];

void Init()
{
	memset(head, -1, sizeof(head));
	memset(son, -1, sizeof(son));
	tim = 0;
	edge = 0;
}

void addedge(int u, int v, int c)
{
	to[edge] = v, w[edge] = c, Next[edge] = head[u], head[u] = edge++;
	to[edge] = u, w[edge] = c, Next[edge] = head[v], head[v] = edge++;
}



void dfs1(int u, int father, int d)
{
	dep[u] = d;
	fa[u] = father;
	siz[u] = 1;
	for (int i = head[u]; ~i; i = Next[i])
	{
		int v = to[i];
		if (v != father)
		{
			dfs1(v, u, d + 1);
			siz[u] += siz[v];
			if (son[u] == -1 || siz[v]>siz[son[u]])
				son[u] = v;
		}
	}
}

void dfs2(int u, int tp)
{
	top[u] = tp;
	tid[u] = ++tim;
	Rank[tid[u]] = u;
	if (son[u] == -1) return;
	dfs2(son[u], tp);
	for (int i = head[u]; ~i; i = Next[i])
	{
		int v = to[i];
		if (v != son[u] && v != fa[u])
			dfs2(v, v);
	}
}



#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const long long kkk = 1e18 + 28;
long long MAX[4 * N];

void PushUP(int rt)
{
	if (MAX[rt << 1] == 0)
		MAX[rt] = 1;
	if (MAX[rt << 1 | 1] == 0)
		MAX[rt << 1 | 1] = 1;
	double ppp1 = MAX[rt << 1];
	double ppp2 = MAX[rt << 1 | 1];
	if (log(ppp1) + log(ppp2) > log(kkk * 1.0))
		MAX[rt] = kkk + 5;
	else
		MAX[rt] = MAX[rt << 1] * MAX[rt << 1 | 1];
}

void Build(int l, int r, int rt)
{
	if (l == r)
	{
		MAX[rt] = num[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUP(rt);
}

void Update(int l, int r, int rt, int p, long long val)
{
	if (l == r)
	{
		MAX[rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid)
		Update(lson, p, val);
	else
		Update(rson, p, val);
	PushUP(rt);
}

long long Query(int l, int r, int rt, int L, int R)
{
	if (L <= l&&R >= r)
		return MAX[rt];
	int mid = (l + r) >> 1;
	long long ans = 1;
	if (L <= mid)
	{
		long long kkkk = Query(lson, L, R);
		if (kkkk == -1)
			flag = 1;
		if (log(ans*1.0) + log(kkkk*1.0) > log(kkk*1.0))
			ans = kkk + 203;
		else
			ans *= kkkk;
	}
	if (R>mid)
	{
		long long kkkk = Query(rson, L, R);
		if (kkkk == -1)
			flag = 1;
		if (log(ans*1.0) + log(kkkk*1.0) > log(kkk*1.0))
			ans = kkk + 203;
		else
			ans *= kkkk;
	}
	return ans;
}

void Change(int x, long long val)
{
	if (dep[tmp[x].u]>dep[tmp[x].v])
		Update(2, n, 1, tid[tmp[x].u], val);
	else
		Update(2, n, 1, tid[tmp[x].v], val);
}

long long query(int x, int y)
{
	long long ans = 1;
	while (top[x] != top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x, y);
		long long kkkk = Query(2, n, 1, tid[top[x]], tid[x]);
		if (log(ans*1.0) + log(kkkk*1.0) > log(kkk*1.0))
			ans = kkk + 203;
		else
			ans *= kkkk;
		x = fa[top[x]];
	}
	if (dep[x]>dep[y]) swap(x, y);
	if (x != y)
	{
		long long kkkk = Query(2, n, 1, tid[x] + 1, tid[y]);
		if (log(ans*1.0) + log(kkkk*1.0) > log(kkk*1.0))
			ans = kkk + 203;
		else
			ans *= kkkk;
	}
	return ans;
}
int MM;
int main()
{
	char oper[15];
	int a, b;
	long long c;
	Init();
	scanf("%d%d", &n, &MM);
	for (int i = 1; i<n; i++)
	{
		scanf("%d%d%I64d", &a, &b, &c);
		tmp[i].u = a; tmp[i].v = b; tmp[i].c = c;
		addedge(a, b, c);
	}
	dfs1(1, 1, 1);
	dfs2(1, 1);
	

	for (int i = 1; i<n; i++)
	{
		if (dep[tmp[i].u]>dep[tmp[i].v])
			num[tid[tmp[i].u]] = tmp[i].c;
		else
			num[tid[tmp[i].v]] = tmp[i].c;
	}
	Build(2, n, 1);
	while (MM--)
	{
		scanf("%s", oper);
		if (oper[0] == '1')
		{
			long long ppp;
			scanf("%d%d", &a, &b);
			scanf("%I64d", &ppp);
			flag = 0;
			long long dddd = query(a, b);
			printf("%I64d\n", ppp / dddd);
		}
		else
		{
			long long ppp;
			scanf("%d%I64d", &a, &ppp);
			Change(a, ppp);
		}
	}
	return 0;
}