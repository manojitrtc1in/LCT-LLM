











using	namespace	    	 std;
typedef	long long    		  vt;
typedef unsigned long long   vt2;
typedef	pair<vt, vt>		     PVV;
typedef	pair<char, vt>	     PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt, vt>			 MVV;
typedef map<char, vt>	     MCV;
typedef map<string, vt>	     MSV;



const int MAXN = (1 << 18) + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



int vis[MAXN];
int main()
{
	int n, x;
	cin >> n >> x;
	fi(0, 1 << n)
	{
		if (!vis[i])
			vis[i ^ x] = 1;
	}
	int k = 0;
	vector<int> v;
	fi(1, 1 << n)
	{
		if (!vis[i])
		{
			v.push_back(i ^ k);
			k = i;
		}
	}
	cout << v.size() << endl;
	for (auto& it : v)
		cout << it << " ";
	return 0;
}
