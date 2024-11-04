

using namespace std;

int x[10000];
int y[10000];

int main()
{
	IOS;
	int n,k,r=0;
	cin>>n;
	
	for ( int i=1 ; i<=n ; i++ ){
		cin>>x[i]>>y[i];
	}
	
	cin>>k;
	
	for ( int i=1 ; i<=n ; i++ ){
		if ( k <= y[i] && k >= x[i] ){
		r=i;
		break;}
	}
	
	cout<<n-r+1;
	
	return 0;
}
