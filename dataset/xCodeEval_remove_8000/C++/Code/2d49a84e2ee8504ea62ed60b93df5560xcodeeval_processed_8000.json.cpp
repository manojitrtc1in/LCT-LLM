




using namespace std;
const int N = 500005;
const int M = 2000005;

int prime[100000] = {};


int st[4 * M] = {};

__int64 dpsum[M] = {};

int n, x, y, mx=0;
__int64 ans = 0x3f3f3f3f3f3f3f3f;
int upb;



int sieve[NN + 1];
void initprime()
{
	for (int i = 2; i <= NN; i++) sieve[i] = 1;
	for (int i = 2; i <= NN / 2; i++) sieve[i * 2] = 0;
	int p = 2;
	while (p * p <= NN)
	{
		p = p + 1;
		while (sieve[p] == 0)
			p++;
		int t = p * p;
		int s = 2 * p;
		while (t <= NN)
		{
			sieve[t] = 0;
			t = t + s;
		}
	}
	for (int i = 2,j=0; i <= NN; i++)
		if (sieve[i] != 0) prime[j++]=i;
	return;
}

void build(int u, int l, int r, int tar)
{
	st[u] += 1;
	if (r - l == 1)
	{
		dpsum[tar] += tar;
		mx = max(mx, tar);
		return;
	}
	int mid = (l + r) / 2;
	if (tar > mid)build(u * 2 + 2, mid, r, tar);
	else build(u * 2 + 1, l, mid, tar);
}

int que(int u, int l, int r, int L, int R)
{
	if (L == l&&R == r)return st[u];
	int res = 0;
	int mid = (l + r) / 2;
	if (L < mid)res += que(u * 2 + 1, l, mid, L, min(R, mid));
	if (R > mid)res += que(u * 2 + 2, mid, r, max(mid, L), R);
	return res;
}

void solve(int p)
{
	__int64 curans = 0;
	for (int i =p; ; i+=p)
	{
		int cl = max(i - p, i - upb - 1);
		curans += (1LL*(1LL*que(0, 0, M, cl, i)*i - (dpsum[i] - dpsum[cl]))*y);
		if(cl>i-p)curans += (1LL*que(0, 0, M, i - p, cl)*x);
		if (i >= mx)break;
	}
	ans = min(ans, curans);
	return;
}

int main()
{
	cin >> n >> x >> y;
	initprime();
	int temp;
	upb = x / y;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		build(0, 0, M, temp);
	}
	for (int i = 1; i < M; i++)dpsum[i] += dpsum[i - 1];
	for (int i = 0; prime[i]; i++)
	{
		solve(prime[i]);
	}
	printf("%lld\n", ans);
	return 0;
}