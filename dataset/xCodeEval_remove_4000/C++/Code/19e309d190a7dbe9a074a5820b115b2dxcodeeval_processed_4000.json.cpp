










using   namespace            std;
typedef long long             vt;
typedef unsigned long long   vt2;







const long long MAXN = 1e6 + 9, INF = 1e18, MAXP = 1e4;
vt HASHprime = 1333331;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, a[MAXN], cnt[MAXN], q;
	cin >> q;
	while (q--)
	{
		cnt[0] = 0;
		cin >> n >> k;
		fi(1, n + 1)
		{
			cin >> a[i];
			cnt[i] = a[i] % 2 == 0 ? cnt[i - 1] : cnt[i - 1] + 1;
		}
		if ((cnt[n] - k + 1) % 2 == 0 && cnt[n] > k && k != 1 || cnt[n] < k || k == 1 && cnt[n] % 2 == 0)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			int cntans = 0;
			fi(2, n + 1)
			{
				if (cntans == k - 1)
					break;
				if (cnt[i] - cnt[i - 1] == 1 && cnt[i - 1] != 0)
				{
					cout << i - 1 << ' ';
					cntans++;
				}
			}
			cout << n << endl;
		}
	}
	return 0;
}

