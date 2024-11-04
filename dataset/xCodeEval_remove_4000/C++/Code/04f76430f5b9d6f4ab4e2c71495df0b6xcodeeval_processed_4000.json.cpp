










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;









const int MAXN = 2e5 + 99, INF = 0x3f3f3f3f;
const int MAXR = 1e5 + 99, MAXC = 1e5 + 99;
vt HASHprime = 13331;



int a[MAXN], b[MAXN], order[MAXN];
int main()
{
	int n, ans = 0;
	sd(n);
	fi(1, n + 1)
		sd(a[i]);
	fi(1, n + 1)
	{
		sd(b[i]);
		order[b[i]] = i;
	}
	if (order[1])
	{
		int i, j;
		for (i = 2; order[i] == order[1] + i - 1; i++)
			;
		if (order[i - 1] == n)
		{
			for (j = i; j <= n && order[j] <= j - i; j++)
				;
			if (j > n)
			{
				printf("%d", n - i + 1);
				return 0;
			}
		}
	}
	fi(1, n + 1)
		ans = max(ans, order[i] - i + 1 + n);
	printf("%d\n", ans);
	return 0;
}
