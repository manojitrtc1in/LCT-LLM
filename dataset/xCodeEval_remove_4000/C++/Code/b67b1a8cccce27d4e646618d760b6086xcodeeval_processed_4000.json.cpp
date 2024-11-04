










using   namespace            std;
typedef    long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
vt HASHprime = 1333331;



int main()
{
	int m, n, stu, cnt = 0;
	cin >> m >> n;
	map<int, int> k;
	fi(0, m)
	{
		cin >> stu;
		k[stu]++;
		if (!(k[stu] % 2))
			cnt++;
	}
	if (cnt == (m + 1) / 2)
		cout << m << endl;
	else
		cout << (m + 1) / 2 + cnt << endl;
}
