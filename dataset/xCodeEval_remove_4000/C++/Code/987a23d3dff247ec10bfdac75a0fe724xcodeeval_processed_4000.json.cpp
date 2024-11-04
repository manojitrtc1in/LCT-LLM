




typedef std::pair < long long, long long > hash_int;
const hash_int MOD = { 1001001011, 1000000007 }, BAS = { 37, 10007 }, id0 = { 784568360, 820925358 };

inline hash_int operator _ (const hash_int &a, const hash_int &b)\
{\
	return { a.first _ b.first, a.second _ b.second };\
}
oper(+);
oper(-);
oper(*);
oper(%);
int min_d[100001], primes[100001], phi[100001], prime;
hash_int Power[100001], iPower[100001];
int N, M, Q, head[100001], next[199999], to[199999], ch[199999], E;
std::string str[200001];
int J[17][100001], *fa = J[0], dep[100001], LOG, pos[100001];
hash_int hud[17][100001], hdu[17][100001];

int son[200001][26], chr[200001], fat[200001], suf[200001], n, end[200001];

std::vector < int > fail_edge[200001];
int fail_left[200001], fail_right[200001];

int sum[4000001], ls[4000001], rs[4000001], o, root[100001];

std::vector < std::pair < int, std::pair < int, int > > > query[100001];
int O[100001];

int L;
struct current
{
	int a[100002], rk[100001], sa[100001], hi[100001], KMP[17][100001], *kmp, LOG;
	std::vector < std::pair < std::pair < int, int >, int > > border[100001];
	hash_int H[100001];
	current()
	{
		kmp = KMP[0];
	}
	void init()
	{
		static int cnt[100001], A[100001], B[100001], tmp[100001];
		a[0] = a[L + 1] = -1;
		for (int i = 0; i < 26; i++)
			cnt[i] = 0;
		for (int i = 1; i <= L; i++)
			cnt[a[i]]++;
		for (int i = 1; i < 26; i++)
			cnt[i] += cnt[i - 1];
		for (int i = L; i; i--)
			sa[cnt[a[i]]--] = i;
		for (int i = 1; i <= L; i++)
			rk[sa[i]] = rk[sa[i - 1]] + (a[sa[i - 1]] != a[sa[i]]);
		for (int k = 1; rk[sa[L]] < L; k <<= 1)
		{
			for (int i = 0; i <= L; i++)
				cnt[i] = 0;
			for (int i = 1; i <= L; i++)
			{
				A[i] = rk[i];
				cnt[B[i] = i + k <= L ? rk[i + k] : 0]++;
			}
			for (int i = 1; i <= L; i++)
				cnt[i] += cnt[i - 1];
			for (int i = L; i; i--)
				tmp[cnt[B[i]]--] = i;
			for (int i = 0; i <= L; i++)
				cnt[i] = 0;
			for (int i = 1; i <= L; i++)
				cnt[A[i]]++;
			for (int i = 1; i <= L; i++)
				cnt[i] += cnt[i - 1];
			for (int i = L; i; i--)
				sa[cnt[A[tmp[i]]]--] = tmp[i];
			for (int i = 1; i <= L; i++)
				rk[sa[i]] = rk[sa[i - 1]] + (A[sa[i - 1]] != A[sa[i]] || B[sa[i - 1]] != B[sa[i]]);
		}
		for (int i = 1, v = 0; i <= L; i++)
		{
			if (rk[i] < L)
				while (a[i + v] == a[sa[rk[i] + 1] + v])
					v++;
			hi[rk[i]] = v ? v-- : 0;
		}
		border[0] = { { { 0, 0 }, 0 } };
		border[1] = { { { 0, 1 }, 1 } };
		for (int i = 2, ans = 0; i <= L; i++)
		{
			while (ans && a[ans + 1] != a[i])
				ans = kmp[ans];
			if (a[ans + 1] == a[i])
				ans++;
			kmp[i] = ans;
			border[i] = border[kmp[i]];
			if (border[i].back().second == 0 || border[i].back().second == i - kmp[i])
			{
				border[i].back().first.second = i;
				border[i].back().second = i - kmp[i];
			}
			else
				border[i].push_back({ { i, i }, 0 });
		}
		for (int i = 1; i <= L; i++)
			H[i] = (H[i - 1] + Power[i] * hash_int(a[i], a[i])) % MOD;
		while (1 << LOG <= L)
			LOG++;
		for (int i = 1; i <= LOG; i++)
			for (int j = 1; j <= L; j++)
				KMP[i][j] = KMP[i - 1][KMP[i - 1][j]];
	}
}
sA, sB;

void insert(const std::string &s, int id)
{
	int p = 0;
	for (char __ch : s)
	{
		int ch = __ch - 'a';
		if (!son[p][ch])
		{
			fat[son[p][ch] = ++n] = p;
			chr[n] = ch;
		}
		p = son[p][ch];
	}
	end[id] = p;
}
void build()
{
	static int q[200001];
	int H = -1, T = 0;
	q[0] = 0;
	while (H < T)
	{
		int u = q[++H];
		for (int ch = 0; ch < 26; ch++)
			if (son[u][ch])
				q[++T] = son[u][ch];
		if (u == 0)
			suf[u] = 0;
		else
		{
			suf[u] = fat[u] ? son[suf[fat[u]]][chr[u]] : 0;
			for (int ch = 0; ch < 26; ch++)
				if (!son[u][ch])
					son[u][ch] = son[suf[u]][ch];
		}
	}
}
void insert(int &root, int x, int w)
{
	int p = root, l = 0, r = n;
	sum[root = ++o] = sum[p] + w;
	while (l < r)
	{
		int m = l + r >> 1;
		if (x <= m)
			ls[o] = o + 1, rs[o] = rs[p], p = ls[p], r = m;
		else
			rs[o] = o + 1, ls[o] = ls[p], p = rs[p], l = m + 1;
		sum[++o] = sum[p] + w;
	}
}
int get_sum(int p, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return sum[p];
	int m = l + r >> 1;
	if (R <= m)
		return get_sum(ls[p], l, m, L, R);
	if (L > m)
		return get_sum(rs[p], m + 1, r, L, R);
	return get_sum(ls[p], l, m, L, R) + get_sum(rs[p], m + 1, r, L, R);
}
void BFS()
{
	static int q[100001];
	int H = 0, T = 1, u;
	q[1] = 1;
	pos[1] = 0;
	insert(root[1], fail_left[pos[1]], 1);
	while (H < T)
		for (int e = head[u = q[++H]]; e; e = next[e])
			if (to[e] != fa[u])
			{
				fa[q[++T] = to[e]] = u;
				pos[to[e]] = son[pos[u]][ch[e]];
				root[to[e]] = root[u];
				dep[to[e]] = dep[u] + 1;
				hud[0][to[e]] = hdu[0][to[e]] = { ch[e], ch[e] };
				insert(root[to[e]], fail_left[pos[to[e]]], 1);
			}
	while (2 << LOG < N)
		LOG++;
	for (int i = 1; i <= LOG; i++)
		for (int j = 1; j <= N; j++)
		{
			J[i][j] = J[i - 1][J[i - 1][j]];
			hud[i][j] = (hud[i - 1][j] * Power[1 << i - 1] + hud[i - 1][J[i - 1][j]]) % MOD;
			hdu[i][j] = (hdu[i - 1][j] + hdu[i - 1][J[i - 1][j]] * Power[1 << i - 1]) % MOD;
		}
}
void id1()
{
	static int q[200001];
	static std::vector < int >::iterator ue[200001];
	for (int i = 1; i <= n; i++)
		fail_edge[suf[i]].push_back(i);
	int D = 0, TIME = 0;
	q[0] = 0;
	ue[0] = fail_edge[0].begin();
	fail_left[0] = fail_right[0] = 0;
	while (~D)
		if (ue[D] == fail_edge[q[D]].end())
		{
			if (D)
				fail_right[q[D - 1]] = fail_right[q[D]];
			D--;
		}
		else
		{
			int To = *ue[D]++;
			fail_left[To] = fail_right[To] = ++TIME;
			q[++D] = To;
			ue[D] = fail_edge[To].begin();
		}
}
int LCA(int u, int v)
{
	for (int i = LOG; i >= 0; i--)
	{
		if (dep[u] - dep[v] >= 1 << i)
			u = J[i][u];
		if (dep[v] - dep[u] >= 1 << i)
			v = J[i][v];
	}
	if (u == v)
		return u;
	for (int i = LOG; i >= 0; i--)
		if (J[i][u] != J[i][v])
		{
			u = J[i][u];
			v = J[i][v];
		}
	return fa[u];
}
int jump(int u, int d)
{
	for (int i = 0; i <= LOG; i++)
		if (d >> i & 1)
			u = J[i][u];
	return u;
}
void init(int id)
{
	L = str[id].size();
	for (int i = 1; i <= L; i++)
	{
		sA.a[i] = str[id][i - 1] - 'a';
		sB.a[i] = str[id][L - i] - 'a';
	}
	sA.init();
	sB.init();
}
bool check(int u, int lca, current &sB, int mid)
{
	

	for (int i = LOG; i >= 0; i--)
		if (dep[u] - dep[lca] >= 1 << i && L - mid + 1 >= 1 << i)
		{
			int p = jump(u, dep[u] - dep[lca] - (1 << i));
			hash_int hash1 = hud[i][p], hash2 = (sB.H[mid + (1 << i) - 1] - sB.H[mid - 1] + MOD) * iPower[mid] % MOD;
			if (hash1 == hash2)
			{
				lca = p;
				mid += 1 << i;
			}
		}
	if (mid > L)
		return true;
	if (lca == u)
		return false;
	return sB.a[mid] <= hud[0][jump(u, dep[u] - dep[lca] - 1)].first;
}
int LCP(int u, int lca, current &sB, int mid)
{
	int ans = 0;
	for (int i = LOG; i >= 0; i--)
		if (dep[u] - dep[lca] >= 1 << i && L - mid + 1 >= 1 << i)
		{
			int p = jump(u, dep[u] - dep[lca] - (1 << i));
			hash_int hash1 = hud[i][p], hash2 = (sB.H[mid + (1 << i) - 1] - sB.H[mid - 1] + MOD) * iPower[mid] % MOD;
			if (hash1 == hash2)
			{
				lca = p;
				mid += 1 << i;
				ans += 1 << i;
			}
		}
	return ans;
}
int search(int u, int lca, current &sA, current &sB)
{
	

	

	int l = 0, r = L;
	while (l < r)
	{
		int m = l + r + 1 >> 1;
		if (check(u, lca, sB, sB.sa[m]))
			l = m;
		else
			r = m - 1;
	}
	if (l == 0)
		return 0;
	int cur = L - sB.sa[l] + 1, len = LCP(u, lca, sB, sB.sa[l]);
	if (cur <= len)
		return cur;
	for (int i = sA.LOG; i >= 0; i--)
		if (sA.KMP[i][cur] > len)
			cur = sA.KMP[i][cur];
	return sA.kmp[cur];
}
long long gcd(long long x, long long y)
{
	long long r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
inline long long divide(long long x, long long y)
{
	if (x >= 0)
		return x / y;
	return (x - y + 1) / y;
}
long long POWER(long long a, long long b, long long c)
{
	long long r = 1 % c;
	for (; b; b >>= 1)
	{
		if (b & 1)
			r = r * a % c;
		a = a * a % c;
	}
	return r;
}
inline long long merge(long long r1, long long r2, long long d1, long long d2)
{
	long long e2 = d1 * POWER(d1, phi[d2] - 1, d2) % (d1 * d2);
	long long e1 = d2 * POWER(d2, phi[d1] - 1, d1) % (d1 * d2);
	return (e1 * r1 + e2 * r2) % (d1 * d2);
}
inline long long common(long long l1, long long r1, long long d1, long long l2, long long r2, long long d2)
{
	if (d1 == 0 && d2 == 0)
		return l1 == l2;
	if (d1 == 0)
		return l2 <= l1 && l1 <= r2 && l1 % d2 == l2 % d2;
	if (d2 == 0)
		return l1 <= l2 && l2 <= r1 && l2 % d1 == l1 % d1;
	long long l = std::max(l1, l2), r = std::min(r1, r2);
	if (l > r)
		return 0;
	long long g = gcd(d1, d2);
	if (l1 % g != l2 % g)
		return 0;
	l1 /= g;
	r1 /= g;
	d1 /= g;
	l2 /= g;
	r2 /= g;
	d2 /= g;
	l /= g;
	r /= g;
	long long common_r = merge(l1 % d1, l2 % d2, d1, d2);
	return divide(r - common_r, d1 * d2) - divide(l - 1 - common_r, d1 * d2);
}
int answer(int u, int v, int id)
{
	int lca = LCA(u, v), O = 0;
	if (dep[u] - dep[lca] > L)
	{
		O += get_sum(root[u], 0, n, fail_left[end[M + id]], fail_right[end[M + id]]);
		O -= get_sum(root[jump(u, dep[u] - dep[lca] - L)], 0, n, fail_left[end[M + id]], fail_right[end[M + id]]);
	}
	if (dep[v] - dep[lca] > L)
	{
		O += get_sum(root[v], 0, n, fail_left[end[id]], fail_right[end[id]]);
		O -= get_sum(root[jump(v, dep[v] - dep[lca] - L)], 0, n, fail_left[end[id]], fail_right[end[id]]);
	}
	std::vector < std::pair < std::pair < int, int >, int > > Lpart = sA.border[search(u, lca, sA, sB)], Rpart = sB.border[search(v, lca, sB, sA)];
	for (auto &i : Rpart)
	{
		std::swap(i.first.first, i.first.second);
		i.first.first = L - i.first.first;
		i.first.second = L - i.first.second;
	}
	for (auto &i : Lpart)
		for (auto &j : Rpart)
			O += common(i.first.first, i.first.second, i.second, j.first.first, j.first.second, j.second);
	return O;
}
int main()
{
	phi[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		if (!min_d[i])
		{
			min_d[i] = primes[++prime] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= prime && primes[j] * i <= 100000 && primes[j] <= min_d[i]; j++)
		{
			min_d[primes[j] * i] = primes[j];
			phi[primes[j] * i] = phi[i] * (primes[j] - (primes[j] != min_d[i]));
		}
	}
	iPower[0] = Power[0] = { 1, 1 };
	for (int i = 1; i <= 100000; i++)
	{
		iPower[i] = iPower[i - 1] * id0 % MOD;
		Power[i] = Power[i - 1] * BAS % MOD;
	}
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1, u, v, c; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		do c = getchar(); while (c < 'a' || c > 'z');
		c -= 'a';
		next[++E] = head[u], to[E] = v, ch[E] = c, head[u] = E;
		next[++E] = head[v], to[E] = u, ch[E] = c, head[v] = E;
	}
	for (int i = 1; i <= M; i++)
	{
		std::cin >> str[i];
		str[M + i] = str[i];
		std::reverse(str[M + i].begin(), str[M + i].end());
	}
	for (int i = 1; i <= M + M; i++)
		insert(str[i], i);
	build();
	id1();
	BFS();
	for (int i = 1, u, v, id; i <= Q; i++)
	{
		scanf("%d%d%d", &u, &v, &id);
		query[id].push_back({ i, { u, v } });
	}
	for (int id = 1; id <= M; id++)
	{
		init(id);
		for (auto &q : query[id])
			O[q.first] = answer(q.second.first, q.second.second, id);
	}
	for (int i = 1; i <= Q; i++)
		printf("%d\n", O[i]);
	return 0;
}
