











using namespace std;



int main()
{
	string s;
	long long n;
	cin>>n;
	cin>>s;
	vector<int> a(s.size());
	vector<long long> sum(s.size(),0);
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = s[i]-'0';
		sum[i] = a[i];
		if (i) sum[i] += sum[i-1];
	}
	long long res = 0;
	vector<long long> mp(100000,0);
	vector<long long> ss;
	long long num = 0;
	for (int i = 0; i < sum.size(); i++)
	{
		num++;
		if (mp[sum[i]]) mp[sum[i]]++;
		else
		{
			mp[sum[i]] = 1;
			ss.push_back(sum[i]);
		}
		
		for (int j = 0; j < i; j++)
		{
			num++;
			if (mp[sum[i]-sum[j]]) mp[sum[i]-sum[j]]++;
			else
			{
				mp[sum[i]-sum[j]] = 1;
				ss.push_back(sum[i]-sum[j]);
			}
		}
	}
	
	for (int i = 0; i < ss.size(); i++)
	{
		
		if (ss[i] == 0) 
		{
			if (n == 0)
			{
				res += mp[ss[i]]*num;
			}
		}
		else if (n%ss[i] != 0) continue;
		else if (n/ss[i] > 90000) continue;
		else res += (long long)mp[n/ss[i]] * (long long)(mp[ss[i]]);
	}
	cout<<res<<endl;


}

