










using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


int main()
{
	char x[MAXN], y[MAXN];
	int t;
	for (scanf("%d", &t); t--;)
	{
		memset(x, '\0', sizeof(x));
		memset(y, '\0', sizeof(y));

		scanf("%s%s", &x, &y);

		int lenx = strlen(x), leny = strlen(y), lastx = 0, lasty = 0;

		for (int i = leny - 1; i >= 0; i--)
			if (y[i] == '1')
			{
				lasty = i;
				break;
			}
		int delat = lenx - leny, ans = 0;
		for (int i = delat + lasty; i >= 0; i--)
		{
			if (x[i] == '1')
				break;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
