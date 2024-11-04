










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	int n, a[MAXN],last=INF,ln;
	sd(n);
	fi(0, n)
	{
		sd(a[i]);
		if (a[i] >= 0)
			a[i] = -a[i] - 1;
		last = min(last, a[i]);
		if (last == a[i])
			ln = i;
	}
	if (n % 2 == 1)
		a[ln] = -a[ln] - 1;
	fi(0, n)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
