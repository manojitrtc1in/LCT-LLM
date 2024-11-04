











using   namespace            std;
typedef long long             vt;
typedef unsigned long long   vt2;






const long long MAXN = 1e6 + 9, INF = 1e18, MAXP = 1e4;
vt HASHprime = 1333331;


int main()
{
	vt a[3];
	vt q;
	cin >> q;
	while (q--)
	{
		fi(0, 3)
			cin >> a[i];
		cout << (a[0] + a[1] + a[2]) / 2 << endl;
	}
}
