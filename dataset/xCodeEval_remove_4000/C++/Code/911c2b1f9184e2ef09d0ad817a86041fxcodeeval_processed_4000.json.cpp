










using   namespace            std;
typedef    long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 3e3 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
vt HASHprime = 1333331;



int main()
{
	vt k, n, a, b,q;
	scanf("%lld", &q);
	while (q--)
	{
		scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
		vt minv = k - 1 - n * b, base = a - b;
		vt ans = minv /( a - b);
		if ((k - 1) / b < n)
		{
			cout << -1 << endl;
			continue;
		}
		cout << min(n, ans) << endl;
	}
	return 0;
}
