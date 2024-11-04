










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
vt HASHprime = 1333331;



int vis1[MAXN], vis2[MAXN];
int main()
{
	int n;
	sd(n);
	while (n--)
	{
		string a, b;
		cin >> a >> b;
		int lena = a.size(), lenb = b.size();
		if (lena >lenb)
		{
			cout << "NO" << endl;
			continue;
		}
		int j = 0, i = 0, flag = 1;
		while (1)
		{
			if (a[i] != b[j])
			{
				flag = 0;
				break;
			}
			int s1 = 1, s2 = 1;
			while (a[i] == a[i + s1])
				s1++;
			while (b[j] == b[j + s2])
				s2++;
			if (s2 < s1)
			{
				flag = 0;
				break;
			}
			if (i + s1 < lena && j + s2 < lenb)
				i += s1, j += s2;
			else
			{
				i += s1 - 1, j += s2 - 1;
				break;
			}
		}
		if (flag&&i==lena-1&&j==lenb-1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
