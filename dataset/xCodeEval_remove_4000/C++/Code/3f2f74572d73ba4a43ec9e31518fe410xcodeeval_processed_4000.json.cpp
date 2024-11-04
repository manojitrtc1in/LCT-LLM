






















using namespace std;











typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 200200;
const int MAGIC = 111;
const int id3 = 1804;
const int MARG = 47;


const int LEN = 22;

int A[MAX];
int A1[MAX];

int getInd(int x)
{
	x = A1[x];
	x /= MAGIC;
	return x;
}

vector<pair<int, int> > g[MAX];
vector<int> G[MAX];

int n;
bool U[MAX];
int C[MAX];
vector<int> V;

int P[MAX];
LL DUP[MAX];
vector<LL> TOCUR[MAX];
vector<LL> TOPAR[MAX];
vector<int> SZ[MAX];
int IN[MAX];
int DD[MAX];
int H[MAX];
vector<pair<int, pair<LL, LL> > > DC[MAX];

int UP[MAX][LEN];
LL DIST[MAX];
int tin[MAX];
int tout[MAX];
int timer = 0;
int ST[MAX];

template<typename T>
void add(vector<T>& v, int x, T val)
{
	for (; x < id3; x = x | (x + 1))
	{
		v[x] += val;
	}
}

template<typename T>
T get(vector<T>& v, int x)
{
	T res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
	{
		res += v[x];
	}

	return res;
}

template<typename T>
LL get(vector<T>& v, int L, int R)
{
	T res = get(v, R);
	if (L != 0) res -= get(v, L - 1);
	return res;
}

bool isUpper(int x, int y)
{
	if (tin[x] <= tin[y] && tout[x] >= tout[y]) return true;
	return false;
}

int lca(int x, int y)
{
	if (isUpper(x, y)) return x;
	if (isUpper(y, x)) return y;

	RFOR(i, ST[x], 0)
	{
		if (!isUpper(UP[x][i], y)) x = UP[x][i];
	}

	return UP[x][0];
}

LL getDist(int x, int y)
{
	int c = lca(x, y);
	LL res = DIST[x] + DIST[y] - 2 * DIST[c];
	return res;
}

void dfs1(int x, int p)
{
	C[x] = 1;
	V.PB(x);
	FOR(i, 0, SZ(g[x]))
	{
		int to = g[x][i].first;
		if (U[to]) continue;
		if (to == p) continue;
		dfs1(to, x);
		C[x] += C[to];
	}
}

void dfs2(int x, int p, LL dist, vector<LL>& a)
{
	int ind = getInd(x);
	a[ind] += dist;

	FOR(i, 0, SZ(g[x]))
	{
		int to = g[x][i].first;
		int c = g[x][i].second;
		if (to == p) continue;
		if (U[to]) continue;

		dfs2(to, x, dist + c, a);
	}
}

void id7(int x, int p, vector<int>& a)
{
	int ind = getInd(x);
	a[ind] ++;
	FOR(i, 0, SZ(g[x]))
	{
		int to = g[x][i].first;
		if (to == p) continue;
		if (U[to]) continue;
		id7(to, x, a);
	}
}

int id5(int x, int par, int dst)
{
	

	LL d1 = dst;
	int xx = x;
	V.clear();
	dfs1(x, -1);

	

	

	

	

	


	int sz = C[x];
	int p = -1;
	while (true)
	{
		bool f = false;
		FOR(i, 0, SZ(g[x]))
		{
			int to = g[x][i].first;
			

			if (to == p || U[to]) continue;
			if (C[to] * 2 >= sz)
			{
				d1 += g[x][i].second;
				p = x;
				x = to;
				f = true;
				break;
			}
		}

		if (!f) break;
	}

	


	if (par != -1) H[x] = H[par] + 1;
	IN[x] = xx;
	DD[x] = dst;
	P[x] = par;
	DUP[x] = d1;
	if (par == -1) DUP[x] = 0;

	if (sz > MARG)
	{
		TOCUR[x] = vector<LL>(id3);
		SZ[x] = vector<int>(id3);
		TOPAR[x] = vector<LL>(id3);

		dfs2(x, -1, 0, TOCUR[x]);
		id7(x, -1, SZ[x]);
		if (par != -1)
		{
		

			dfs2(xx, par, dst, TOPAR[x]);
		}
	}
	else
	{
		DC[x] = vector<pair<int, pair<LL, LL> > >(sz);
		FOR(i, 0, SZ(V))
		{
			int v = V[i];
			DC[x][i].first = v;
			DC[x][i].second.first = getDist(v, x);
			DC[x][i].second.second = getDist(v, par);
		}
	}

	U[x] = true;
	
	FOR(i, 0, SZ(g[x]))
	{
		int to = g[x][i].first;
		int c = g[x][i].second;
		if (U[to]) continue;
		

		int cen = id5(to, x, c);

		G[x].PB(cen);
	}

	return x;
}

int id0()
{
	int root = id5(0, -1, 0);

	return root;
}

void dfs3(int x, int p, LL d)
{
	tin[x] = timer++;
	DIST[x] = d;

	UP[x][0] = p;
	ST[x] = -1;
	FOR(i, 1, LEN)
	{
		UP[x][i] = UP[UP[x][i - 1]][i - 1];
		if (UP[x][i] == UP[x][i - 1] && ST[x] == -1) ST[x] = i;
	}

	if (ST[x] == -1) ST[x] = LEN;

	FOR(i, 0, SZ(g[x]))
	{
		int to = g[x][i].first;
		int c = g[x][i].second;
		if (to == p) continue;
		dfs3(to, x, d + c);
	}

	tout[x] = timer++;
}

void id6()
{
	dfs3(0, 0, 0);
}

int L, R;
LL dst;
int h;

LL dfs4(int x, int p)
{
	

	LL res = 0;
	int ind = A1[x];
	if (ind >= L && ind < R) res = dst;
	FOR(i, 0, SZ(g[x]))
	{
		int to = g[x][i].first;
		int c = g[x][i].second;
		if (to == p || H[to] < h) continue;
		dst += c;
		res += dfs4(to, x);
		dst -= c;
	}
	


	return res;
}

int id4(int x, int p)
{
	

	int res = 0;
	int ind = A1[x];
	if (ind >= L && ind < R) res++;
	FOR(i, 0, SZ(G[x]))
	{
		int to = G[x][i];
		if (to == p) continue;
		res += id4(to, x);
	}

	return res;
}

LL id1(int x, int LP, int RP)
{
	LL res = 0;
	if (SZ(TOCUR[x]) != 0)
	{
		res += get(TOCUR[x], LP, RP - 1);
		
	}
	else
	{
		

		L = LP * MAGIC;
		R = RP * MAGIC;

		vector<pair<int, pair<LL, LL> > > & v = DC[x];
		FOR(i, 0, SZ(v))
		{
			int ind = A1[v[i].first];
			if (ind >= L && ind < R) res += v[i].second.first;
		}
		

		

		

	}

	


	return res;
}

LL id2(int x, int LP, int RP)
{
	LL res = 0;
	if (SZ(TOPAR[x]) != 0)
	{
		
		res += get(TOPAR[x], LP, RP - 1);
	}
	else
	{
	

	

		L = LP * MAGIC;
		R = RP * MAGIC;

		vector<pair<int, pair<LL, LL> > > & v = DC[x];
		FOR(i, 0, SZ(v))
		{
			int ind = A1[v[i].first];
			if (ind >= L && ind < R) res += v[i].second.second;
		}

		

		

		

	}

	return res;
}

LL getSZ(int x, int LP, int RP)
{
	int res = 0;
	if (SZ(SZ[x]) != 0)
	{
		
		res += get(SZ[x], LP, RP - 1);
	}
	else
	{
		L = LP * MAGIC;
		R = RP * MAGIC;

		vector<pair<int, pair<LL, LL> > > & v = DC[x];
		FOR(i, 0, SZ(v))
		{
			int ind = A1[v[i].first];
			if (ind >= L && ind < R) res ++;
		}

		

	}

	return res;
}

LL getAns(int x, int LP, int RP)
{
	LL res = 0;
	int sz = 0;
	int v = x;
	int cnt = (RP - LP) * MAGIC;
	while (x != -1)
	{
	

		LL toCur = id1(x, LP, RP);
		int cs = getSZ(x, LP, RP);
		LL dst;
		if (cs == 0) dst = 0;
		else dst = getDist(x, v);

	

		toCur += (cs - sz) * dst;
	


		res += toCur;
		if (cs == cnt) break;
		sz = cs;
		int p = P[x];
		if (p == -1) break;;

		LL toPar;
		if (cs == 0) toPar = 0;
		else toPar = id2(x, LP, RP);
		


		

		res -= toPar;

		x = p;
	}



	return res;
}

void add(int x, int d)
{
	int v = x;
	int ind = getInd(v);
	while (x != -1)
	{
		if (SZ(SZ[x]) != 0)
		{
			

			add(TOCUR[x], ind, d * getDist(v, x));
			

			add(SZ[x], ind, d);

			if (P[x] != -1)
			{
				

				add(TOPAR[x], ind, d * getDist(v, P[x]));
			}
		}

		x = P[x];
	}
}

int mrand()
{
	int res = abs(rand() ^ (rand() << 16));
	return res;
}

int main()
{
	

	

	


	int time = clock();

	int m;
	scanf("%d%d", &n, &m);
	

	

	

	FOR(i, 0, n)
	{
		scanf("%d", &A[i]);
		

		

		A[i]--;
		A1[A[i]] = i;
	}
	


	FOR(i, 0, n-1)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		

		

		


		

		x--;
		y--;
		g[x].PB(MP(y, c));
		g[y].PB(MP(x, c));
	}

	id6();
	int root = id0();

	FOR(i, 0, n)
	{
		if (SZ(SZ[i]) == 0) continue;
		RFOR(j, id3, 0)
		{
			LL v = TOCUR[i][j];
			TOCUR[i][j] = 0;
			add(TOCUR[i], j, v);

			v = TOPAR[i][j];
			TOPAR[i][j] = 0;
			add(TOPAR[i], j, v);

			int vv = SZ[i][j];
			SZ[i][j] = 0;
			add(SZ[i], j, vv);
		}
	}



	if (n > 10000)
	{
	

	}

	int ans = 0;
	FOR(i, 0, m)
	{
		

		int t;
		scanf("%d", &t);
		

		

		if (t == 1)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a ^= ans;
			b ^= ans;
			c ^= ans;

			int L = a;
			int R = b;
			int v = c;


			

			

			

			

		


		


		

			L--;
			R--;
			R++;
			v--;

			

			int LP, RP;
			LP = L / MAGIC * MAGIC;
			while (LP < L) LP += MAGIC;

			RP = R / MAGIC * MAGIC;

			LL res = 0;
			if (LP >= RP)
			{
				FOR(i, L, R)
				{
					res += getDist(v, A[i]);
				}
			}
			else
			{

			


				FOR(i, L, LP)
				{
					res += getDist(v, A[i]);
				}

				FOR(i, RP, R)
				{
					res += getDist(v, A[i]);
				}
			

			

				LL r = getAns(v, LP / MAGIC, RP / MAGIC);
			

				res += r;
			}

			

			printf("%I64d\n", res);

			ans = res % (1 << 30);
		}
		else
		{
			int a;
			scanf("%d", &a);
			int x = a ^ ans;
			x--;

			int LP = x / MAGIC * MAGIC;
			int RP = (x + 1) / MAGIC * MAGIC;

			if (LP == RP)
			{
				swap(A[x], A[x + 1]);
				A1[A[x]] = x;
				A1[A[x + 1]] = x + 1;
			}
			else
			{
				add(A[x], -1);
				add(A[x + 1], -1);

				swap(A[x], A[x + 1]);
				A1[A[x]] = x;
				A1[A[x + 1]] = x + 1;

				add(A[x], 1);
				add(A[x + 1], 1);
			}
		}

	}

	


	return 0;
}