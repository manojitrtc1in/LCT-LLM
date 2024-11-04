










using namespace std;
typedef double vt;
typedef unsigned long long vt2;
typedef pair<vt,vt> PVV;
typedef pair<char,vt> PCV;
typedef pair<string,vt> PSV;
typedef map<vt,vt> MVV;
typedef map<char,vt> MCV;
typedef map<string,vt> MSV;





const int MAXN = 2e6 + 99, INF = 0x3f3f3f3f;
vt2 HASHprime = 13331;



__int64 C(__int64 n, __int64 m)
{
	__int64 i, c = 1;
	i = m;
	while (i != 0)
	{
		c *= n;
		n--;
		i--;
	}
	while (m != 0)
	{
		c /= m; 
		m--;
	}
	return c;
}
int main()
{	
	int n;
	cin >> n;
	MVV m1, m2;
	map<pair<vt, vt>, int> m3;
	__int64 ans = 0;
	fi(0, n)
	{
		vt a, b;
		scanf("%lf%lf", &a, &b);
		m3[PVV(a, b)]++;
		m1[a]++, m2[b]++;
	} 
	m1.size();
	MVV::iterator it;
	map < pair<vt, vt>, int>::iterator it2;
	for (it = m1.begin(); it != m1.end(); it++)
		if (it->second > 1)
			ans += C(it->second, 2);
	for (it = m2.begin(); it != m2.end(); it++)
		if (it->second > 1)
			ans += C(it->second, 2);
	for (it2 = m3.begin(); it2 != m3.end(); it2++)
		if (it2->second > 1)
			ans -= C(it2->second,2);
	cout<<ans<<endl;
	return 0;
}

