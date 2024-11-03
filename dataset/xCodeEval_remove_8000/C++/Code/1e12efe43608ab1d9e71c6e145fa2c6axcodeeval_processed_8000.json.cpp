
using namespace std;
int n,m,a[100005],qjh[100005],ans;
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i],qjh[i]=qjh[i-1]+a[i];
	m/=2;
	for(int i=1;i<n;i++)
		if(qjh[i]==qjh[n]-qjh[i])
			ans++;
	cout << ans << endl;
	return 0;
}


