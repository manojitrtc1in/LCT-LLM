














using namespace std;














int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> minl(n,0);
	vector<int> minr(n,n-1);
	vector<int> maxl(n,0);
	vector<int> maxr(n,n-1);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; i++)
	{
		minl[i] = i;
		minr[i] = i;
		maxl[i] = i;
		maxr[i] = i;
		if (i)
		{
		minl[i] = a[minl[i]]<a[minl[i-1]] ? minl[i] : minl[i-1];
		maxl[i] = a[maxl[i]] > a[maxl[i-1]] ? maxl[i] : maxl[i-1];
		}
		if (i < n-1)
		{
		minr[i] = a[minr[i]]<a[minr[i+1]] ? minr[i] : minr[i+1];
		maxr[i] = a[maxr[i]] > a[maxr[i+1]] ? maxr[i] : maxr[i+1];
		}
	}
	bool yes = false;
	for (int i = 1; i < n-1; i++)
	{
		if (a[i] > a[minr[i+1]] && a[i] > a[minl[i-1]])
		{
			yes = true;
			cout<<3<<endl;
			cout<<minl[i-1]+1<<" "<<i+1<<" "<<minr[i+1]+1<<endl;
			break;
		}
	}
	if (!yes)
	{
	for (int i = 1; i < n-1; i++)
	{
		if (a[i] < a[maxr[i+1]] && a[i] < a[maxl[i-1]])
		{
			yes = true;
			cout<<3<<endl;
			cout<<maxl[i-1]+1<<" "<<i+1<<" "<<maxr[i+1]+1<<endl;
			break;
		}
	}
	if (!yes) cout<<0<<endl;
	}
}