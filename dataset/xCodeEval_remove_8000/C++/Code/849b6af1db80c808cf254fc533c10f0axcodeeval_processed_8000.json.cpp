















using namespace std;






int main()
{
	int n;
	cin>>n;
	vector<pair<int,bool> > a[101];
	int b;
	for (int i = 0; i < 2*n; i++)
	{
		cin>>b;
		a[b].push_back(make_pair(i,false));
	}
	int c = 0;
	vector<int> t(2*n, -2);
	int e = 0;
	for (int i = 0; i < 100; i++)
	{
		if (a[i].size() >= 2)
		{
			c += 2;
			t[a[i][0].first] = 0;
			t[a[i][1].first] = 1;
			a[i][0].second = true;
			a[i][1].second = true;
		}
		else if (a[i].size() == 1)
		{
			c++;
			t[a[i][0].first] = e;
			e = (e+1)%2;
			a[i][0].second = true;
		}
	}
	int d;
	if (c%2 == 0)
	{
		c /=2;
		d = c;
	}
	else
	{
		c /=2;
		d = c;
		c++;
	}
	e = 1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j].second) continue;
			t[a[i][j].first] = e;
			a[i][j].second = true;
			e = (e+1)%2;
		}
	}
	
	cout<<c*d<<endl;
	cout<<t[0]+1;
	for (int i = 1; i < 2*n; i++)
	{
		cout<<" "<<t[i]+1;
	}
	cout<<endl;
}	