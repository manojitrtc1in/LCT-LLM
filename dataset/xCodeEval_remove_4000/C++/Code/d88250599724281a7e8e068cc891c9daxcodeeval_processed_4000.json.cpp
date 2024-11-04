










using	namespace	    	 std;
typedef	 __int64			  vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>		     PVV;
typedef	pair<char,vt>	     PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>			 MVV;
typedef map<char,vt>	     MCV;
typedef map<string,vt>	     MSV;





const int MAXN = 2e5 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



bool judge(const vector<vt>& k) 
{
	vt id0 = k.front() * k.back();
	int len = k.size();
	fi(0,len)
		if (k[i] * k[len - i - 1] != id0)
			return false;
	set<vt> s;
	for (vt i = 2; i * i <= id0; ++i) 
		if (id0 % i == 0) 
		{
			s.insert(i);
			s.insert(id0 / i);
		}
	return s.size() == len;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) 
	{
		int n;
		cin >> n;
		vector<vt> k(n);
		fi(0,n)
			cin >> k[i];
		sort(k.begin(), k.end());
		if (judge(k))
			cout << k[0] * k.back() << endl;
		else 
			cout << -1 << endl;
	}
	return 0;
}
