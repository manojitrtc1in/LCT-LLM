










using   namespace            std;
typedef    long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
vt HASHprime = 1333331;



vt dp[MAXN][2];
int main()
{
	vt n, a[MAXN], b[MAXN];
	cin >> n;
	fi(1, n + 1)
		cin >> a[i];
	fi(1, n + 1)
		cin >> b[i];
	dp[1][0] = a[1], dp[1][1] = b[1];
	fi(1, n + 1)
	{
		dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][1]);
	}
	cout << max(dp[n][1], dp[n][0])<<endl;
	return 0;
}
