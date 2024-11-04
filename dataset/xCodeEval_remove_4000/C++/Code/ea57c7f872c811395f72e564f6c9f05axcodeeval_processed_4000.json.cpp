










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	int n, m;
	sd(n); sd(m);
	fi(1, (n + 2) / 2)
	{
		fj(1, m + 1)
		{
			printf("%d %d\n", i, j);
			printf("%d %d\n", n + 1 - i, m + 1 - j);
		}
	}
	if (n % 2 == 1)
	{
		int j = 1, k = m;
		fi(1, m + 1)
			printf("%d %d\n", (n + 1) / 2, (i % 2 == 1 ? j++ : k--));
	}
	return 0;
}
