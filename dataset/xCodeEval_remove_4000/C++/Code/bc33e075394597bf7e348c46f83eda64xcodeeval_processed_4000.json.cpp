










using namespace std;





int main()
{
	int n, k;
	cin>>n>>k;
	vector<int> a(2*n+1,0);
	for (int i = 0; i < a.size(); i++)
	{
		cin>>a[i];
	}
	for (int i = 1; i <a.size(); i+=2)
	{
		if (a[i] > a[i-1]+1 && a[i] > a[i+1]+1)
		{
			a[i]--;
			k--;
		}
		if (!k) break;
	}
	cout<<a[0];
	for (int i = 1; i < a.size(); i++)
	{
		cout<<" "<<a[i];
	}
	cout<<endl;
}