










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;






const int MAXN = 6e5 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



vt n, mp[MAXN];
vt mod= 998244353;
int main()
{
	sl(n);
	vt ans = n;
	fi(0, n-1)
	{
		vt v, u;
		scanf("%lld%lld", &v, &u);
		ans = ans * (++mp[u]) % mod * (++mp[v]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
