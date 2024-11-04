












using   namespace            std;
typedef __int64              ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


int npos[MAXN], tpos[MAXN], opos[MAXN], zpos[MAXN];
int pn, pt, po, pz;
char teg[MAXN];
int pre[MAXN];
const int MAXM = (5e5 + 9);
ll srcArray[MAXM];
ll rigval[22];
ll sumval(int a[])
{
	ll sum = 0;
	for (int i = 0; i < 22; i++)
		sum += a[i] * rigval[i];
	return sum;
}
bool id1(int l, int r, int x, int y)
{
	if (l > y || r < x)
		return false;
	return true;
}
bool id4(int l, int r, int x, int y)
{
	if (r <= y && l >= x)
		return true;
	return false;
}
void dive(ll val, int a[])
{

	for (int i = 0; i < 22 && val != 0; i++)
	{
		a[i] = val & 1;
		val >>= 1;
	}
}
struct treenode
{
	int pid, len, pl, pr;
	int sum[22], lazy[23];
	int lson()
	{
		return pid << 1;
	}
	int rson()
	{
		return pid << 1 | 1;
	}
	void reset(int p, int l, int r)
	{
		pid = p;
		len = r - l + 1;
		pl = l, pr = r;
		dive(srcArray[l], sum);
		lazy[22] = 0;
	}
	void updateByValue(int val[])
	{
		lazy[22] = 1;
		for (int i = 0; i < 22; i++)
		{
			if (val[i] == 1)
			{
				lazy[i] = val[i]^lazy[i];
				sum[i] = len - sum[i];
			}
		}
	}
	void giveLazyToSon()
	{
		if (lazy[22])
		{
			nodes[lson()].updateByValue(lazy);
			nodes[rson()].updateByValue(lazy);
			for (int i = 0; i < 23; i++)
				lazy[i] = 0;
		}
	}
	void mergeQuery(int p)
	{
		for (int i = 0; i < 22; i++)
			sum[i] += nodes[p].sum[i];
	}
	void updateFromSon()
	{
		for (int i = 0; i < 22; i++)
			sum[i] = nodes[lson()].sum[i];
		mergeQuery(rson());
	}
}nodes[MAXM];
void id2(int p, int l, int r)
{
	nodes[p].reset(p, l, r);
	if (l < r)
	{
		int mid = (l + r) >> 1;
		id2(p << 1, l, mid);
		id2(((p << 1) | 1), mid + 1, r);
		nodes[p].updateFromSon();
	}
}
void id3(int p, int l, int r, int x, int y, ll val)
{
	if (!id1(l, r, x, y))
	{
		return;
	}
	if (id4(l, r, x, y))
	{
		int temp[23];
		for (int i = 0; i < 22; i++)
			temp[i] = 0;
		dive(val, temp);
		nodes[p].updateByValue(temp);
		return;
	}
	nodes[p].giveLazyToSon();
	int mid = (l + r) >> 1;
	id3(p << 1, l, mid, x, y, val);
	id3(p << 1 | 1, mid + 1, r, x, y, val);
	nodes[p].updateFromSon();
}
void id0(int p, int l, int r, int x, int y, treenode& ans)
{
	if (!id1(l, r, x, y))
	{
		return;
	}
	if (id4(l, r, x, y))
	{
		ans.mergeQuery(p);
		return;
	}
	nodes[p].giveLazyToSon();
	int mid = (l + r) >> 1;
	id0(p << 1, l, mid, x, y, ans);
	id0(p << 1 | 1, mid + 1, r, x, y, ans);
	nodes[p].updateFromSon();
}
int main()
{
	rigval[0] = 1;
	for (int i = 1; i < 22; i++)
		rigval[i] = 2 << (i - 1);
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &srcArray[i + 1]);
	id2(1, 1, n);
	scanf("%d", &m);
	for (; m--;)
	{
		int chose;
		scanf("%d", &chose);
		if (chose == 1)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			treenode ans;
			for (int i = 0; i < 22; i++)
				ans.sum[i] = 0;
			id0(1, 1, n, l, r, ans);
			printf("%lld\n", sumval(ans.sum));
		}
		else
		{
			int l, r;
			ll v;
			scanf("%d%d%lld", &l, &r, &v);
			id3(1, 1, n, l, r, v);
		}
	}
}
