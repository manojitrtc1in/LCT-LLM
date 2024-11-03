














using namespace std;














unsigned long long f(unsigned long long k, unsigned long long x)
{
	if (k > (18446744073709551615 )/x) return 18446744073709551615;
	

	return k*x + (x*(x-1))/2;
}
unsigned long long n;
long long bs(long long k, long long l, unsigned long long h)
{

	if (l > h) return -1;
	long long mid = (l+h)/2;
	
	unsigned long long mm = f(k,mid);
	if (mm == n) return mid;
	if (mm > n) return bs(k,l,mid-1);
	if (mm < n) return bs(k,mid+1,h);
}

int main()
{
	cin>>n;
	unsigned long long k = 1;
	unsigned long long kk = 0;
	vector<unsigned long long> res;
	while (kk <= n)
	{
		
		long long r = bs(kk,0,10000000000ll);
		

		if (r!= -1 && r%2==1) res.push_back(k*r);
		kk+=k;
		k*=2;
	}
	sort(res.begin(),res.end());
	if (res.empty())
	{
		cout<<-1<<endl;
	}
	else
	{
		for (int i = 0; i < res.size(); i++)
		{
			if (i && res[i] == res[i-1]) continue;
			cout<<res[i]<<endl;
		}
	}


}