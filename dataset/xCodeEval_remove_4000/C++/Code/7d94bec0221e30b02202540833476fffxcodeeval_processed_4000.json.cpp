










using namespace std;




long long gcd(long long x,long long b)
{
	if (b==0) return x;
	return gcd(b, x%b);
}
long long lcm(long long x, long long b)
{
	long long g = gcd(x,b);
	if (g == 0) return 0;
	return x*(b / g);
}

vector<long long> a;
vector<bool> tk;
vector<vector<int> > t;
long long dfs1(int i)
{
	if (i!= 0 && t[i].size() == 1) return 1;
	tk[i] = true;
	long long rs = 0;
	long long id0 = 1;
	for (int j = 0; j < t[i].size(); j++)
	{
		if (tk[t[i][j]]) continue;
		id0= lcm(id0, dfs1(t[i][j]));
	}
	rs = id0 * ((long long)t[i].size()-1ll);
	if (0 == i)
	{
		rs = id0 * ((long long)t[i].size());
	}
	tk[i] = false;
	return rs;
}
long long dfs2(int i, long long val)
{
	long long mn = 10000000000ll;
	if (i!=0&& t[i].size() == 1)
	{
		if (val == 0) return 0;
		return a[i] / val;
	}
	tk[i] = true;
	long long dis;
	if (0==i) dis = val / (t[i].size());
	else dis = val / (t[i].size()-1);
	
	for (int j = 0; j < t[i].size(); j++)
	{
		if (tk[t[i][j]]) continue;
		mn = min(mn, dfs2(t[i][j], dis));
	}
	return mn;
}

int main()
{
	int n;
	cin>>n;
	t = vector<vector<int> > (n);
	a = vector<long long> (n);
	tk = vector<bool> (n);
	long long sm = 0;
	for (int i = 0; i < n; i++) {
	cin>>a[i];
	sm += a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int x,y;
		cin>>x>>y;
		t[x-1].push_back(y-1);
		t[y-1].push_back(x-1);
	}
	long long val = dfs1(0);
	
	long long ans = dfs2(0,val);
	cout<<(sm - (val * ans))<<endl;
}