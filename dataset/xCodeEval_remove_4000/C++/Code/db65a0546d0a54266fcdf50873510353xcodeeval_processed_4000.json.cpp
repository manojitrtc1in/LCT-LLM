










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;







const int MAXN = 3e5 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	vt n, k;
	sl(n); sl(k);
	vt s[MAXN],a[MAXN];
	s[0] = 0;
	fi(1, n+1)
	{
		sl(a[i]);
		s[i] = s[i - 1] + a[i];
	}
	vt ans = s[n] * k;
	sort(s + 1, s + n);
	fi(1, k)
		ans -= s[i];
	cout << ans << endl;
}
