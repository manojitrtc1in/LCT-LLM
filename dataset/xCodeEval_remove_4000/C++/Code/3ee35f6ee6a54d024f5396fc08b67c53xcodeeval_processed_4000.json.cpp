










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



int cnt[int(1e2 + 99)];
int main()
{
	int n, m;
	sd(n); sd(m);
	fi(0, n)
	{
		int t;
		sd(t);
		int left = m-t, ans = i;
		fj(1, 101)
		{
			int cut = min(cnt[j], left / j);
			left -= cut * j, ans -= cut;
		}
		cnt[t]++;
		cout << ans << (i == n - 1 ? '\n' : ' ');
	}
}
