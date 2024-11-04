










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	int q;
	sd(q);
	while (q--)
	{
		int n, k, midi, a[MAXN];
		double midd;
		sd(n); sd(k);
		fi(0, n)
			sd(a[i]);
		sort(a, a + n);
		midi = (a[0] + a[n - 1]) / 2, midd = ((double)a[0] + (double)a[n - 1]) / 2;
		if (midd-(double)a[0] > (double)k)
		{
			cout << -1 << endl;
			continue;
		}
		cout << a[0]+k << endl;
	}
}
