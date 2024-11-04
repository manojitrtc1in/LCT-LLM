











using	namespace	    	 std;
typedef	long long    		  vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>		     PVV;
typedef	pair<char,vt>	     PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>			 MVV;
typedef map<char,vt>	     MCV;
typedef map<string,vt>	     MSV;





const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



int main()
{
	ios::sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	char a[MAXN];
	char b[MAXN];
	cin >> a;
	b[0] = '1';
	fi(1, x + 1)
		b[i] = '0';
	b[x - y] = '1';
	fi(x - y + 1, x + 1)
		b[i] = '0';
	b[x + 1] = '\0';
	int ans = 0;
	for (int i = n - 1, j = x; j != 0; i--, j--)
		if (b[j] != a[i])
			ans++;
	cout << ans << endl;
	return 0;
}
