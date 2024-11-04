










using   namespace            std;
typedef long long             vt;
typedef unsigned long long   vt2;






const long long MAXN = 1e6 + 9, INF = 1e18, MAXP = 1e4;
vt HASHprime = 1333331;


int main()
{
	sync_off;
	int n, k, a[MAXN], cnt[MAXN], q;
	scanf("%d", &q);

	while (q--)
	{
		

		

		cnt[0] = 0;
		scanf("%d%d", &n, &k);

		fi(1, n + 1)
		{
			scanf("%d", &a[i]);

			cnt[i] = a[i] % 2 == 0 ? cnt[i - 1] : cnt[i - 1] + 1;
		}
		if ((cnt[n] - k + 1) % 2 == 0 && cnt[n] > k && k != 1 || cnt[n] < k || k == 1 && cnt[n] % 2 == 0)
			printf("NO\n");

		else
		{
			printf("YES\n");

			int cntans = 0;
			fi(2, n + 1)
			{
				if (cntans == k - 1)
					break;
				if (cnt[i] - cnt[i - 1] == 1 && cnt[i - 1] != 0)
				{
					printf("%d ", i - 1);

					cntans++;
				}
			}
			printf("%d\n", n);

		}
	}
	return 0;
}

