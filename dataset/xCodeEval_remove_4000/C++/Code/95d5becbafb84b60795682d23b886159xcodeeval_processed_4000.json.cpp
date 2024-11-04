










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



int ccc = 0;
int flag = 0;
void fo(vt2& x,vt2 k)
{
	string str;
	vt2 cnt = 0;
	vt2 bef = x;
	k--;
	while (cin >> str&&ccc--&&str[0]!='e')
	{
		if (str[0] == 'a')
		{
			if (x == 4294967295)
			{
				flag = 1;
				return;
			}
			++x;
		}
		else
		{
			vt2 temp;
			cin >> temp;
			fo(x, temp);
		}
		if (ccc == 0)
			break;
	}
	bef = x-bef;
	while (k--)
	{
		if ((unsigned long long)(4294967295 - x) < bef)
		{
			flag = 1;
			return;
		}
		x += bef;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	vt2 x = 0;
	cin >> ccc;
	fo(x, 1);
	if (x > 4294967295)
		flag = 1;
	if (!flag)
		cout << x << endl;
	else
		cout << "OVERFLOW!!!" << endl;
	return 0;
}
