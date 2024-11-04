










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;









const int MAXN = 6e6 + 99, INF = 0x3f3f3f3f;
const int MAXR = 1e5 + 99, MAXC = 1e5 + 99;
vt HASHprime = 13331;



int main()
{
	int t;
	sd(t);
	while (t--)
	{
		int n, k;
		vt a[MAXN];
		sd(n); sd(k);
		fi(0, n)
			sl(a[i]);
		vt maxv = 1e13, ans;
		for (int i = 0; i + k < n; i++) 
		{
			if (maxv > a[i + k] - a[i]) 
			{
				maxv = a[i + k] - a[i];
				ans = (a[i + k] + a[i]) / 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
