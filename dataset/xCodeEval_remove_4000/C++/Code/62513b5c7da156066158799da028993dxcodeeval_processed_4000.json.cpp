

















using namespace std;




int main()
{
	int n, k;
	cin>>n;
	vector<pair<long long,int> > d(n);
	for (int i = 0; i < n; i++)
	{
		cin>>d[i].first;
		d[i].second = i+1;
	}
	sort(d.begin(), d.end());
	vector<long long> dif(n-1);
	vector<long long> asc(n-1);
	vector<long long> dsc(n-1);
	long long mn = d[0].first;
	for (int i = 0; i < n; i++)
	{
		d[i].first -= mn;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (i < n-1) dif[i] = d[i+1].first-d[i].first;
		asc[i] = ((long long)i)*dif[i];
		if (i) asc[i] += asc[i-1];
	}
	for (int i = n-2; i >= 0; i--)
	{
		dsc[i] = (n-2-i)*dif[i];
		if (i < n-2) dsc[i] += dsc[i+1];
	}
	cin>>k;
	int mnk = k;
	long long sm = 0;
	vector<long long> ml(k-1);
	for (int i = 1; i <= (k-1); i++)
	{
		ml[i-1] = i*(k-i);
	}
	
	for (int i = 0; i < (k-1); i++)
	{
		sm += ml[i]*(dif[i]);
	}
	long long msm = sm;
	for (int i = k-1; i < n-1; i++)
	{
		sm += asc[i];
		if (i >= k)
			sm -= asc[i-k];
		sm -= (i-k+1)*(d[i+1].first-d[i-k+1].first);
		sm -= dsc[i-k+1];
		if (i+1 < n-1) sm +=dsc[i+1];
		sm+= (n-2-i)*(d[i+1].first-d[i-k+1].first);
		if (sm< msm)
		{
			msm = sm;
			mnk = i+2;
		}
	}
	for (int i = mnk-k; i < mnk; i++)
	{
		cout<<d[i].second;
		if (i+1 < mnk) cout<<" ";
	}
	cout<<endl;


}