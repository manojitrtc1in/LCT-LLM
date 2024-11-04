

















using namespace std;




int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int> s;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		s.insert(make_pair(i,a[i]));
	}
	int m;
	cin>>m;
	while (m--)
	{
		int q;
		cin>>q;
		if (q == 1)
		{
			int p, x;
			cin>>p>>x;
			p--;
			map<int,int> ::iterator i;
			i = s.lower_bound(p);
			while (i != s.end())
			{
				(*i).second -= x;
				x = -(*i).second;
				if (x > 0)
				{
					map<int,int> ::iterator j = i;
					i++;
					s.erase(j);
				}
				else
					break;
			}
		}
		else
		{
			int k;
			cin>>k;
			k--;
			if (s.count(k)) cout<<a[k]-s[k]<<endl;
			else
				cout<<a[k]<<endl;
		}
	}


}