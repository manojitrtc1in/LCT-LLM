










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;









const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
const int MAXR = 1e5 + 99, MAXC = 1e5 + 99;
vt HASHprime = 13331;



int main()
{
	int n;
	cin >> n;
	int m = (n + 2) / 2;
	cout << m << endl;
	for (int i = m-1; i>-1; i--)
		cout << "1 " << m - i << endl;
	if (n > m)
	{
		int t = 2;
		for (int i = n - m; i != 0; i--)
			cout << t++ << " " << m<<endl;
	}
	return 0;
}
