
using namespace std;
int T;
const int maxn=9;
int ans[51][51]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,9,1,2,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,1,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,2,2,9,9,9,9,9,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,2,2,9,9,9,1,2,2,2,2,2,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,2,9,9,9,9,2,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9,9,1,9,9,2,9,9,1,2,2,2,2,2,2,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,9,9,9,9,9,2,9,2,9,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,2,9,2,9,9,2,2,3,3,2,3,9,9,9,9,9,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9,9,1,9,9,9,9,9,2,9,2,9,2,3,2,9,9,2,9,9,9,2,3,3,3,3,2,9,9,2,3,3,3,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,1,9,9,9,9,1,2,2,2,1,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,2,2,9,9,2,3,9,2,9,9,2,2,3,3,3,9,9,9,9,2,9,9,2,2,3,3,3,2,3,3,2,3,3,3,3,2,9,9,2,3,3,3,9,9,9,9,1,9,9,9,9,2,2,9,9,2,3,9,2,9,9,2,2,9,3,3,9,9,9,2,2,3,3,2,3,3,3,9,3,9,9,2,3,9,9,9,2,9,9,3,3,9,9,9,1,2,2,1,9,9,9,9,2,2,9,1,2,2,2,2,2,2,2,2,3,3,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,2,2,9,2,2,3,9,1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,2,9,9,2,2,9,9,2,3,9,3,2,9,2,3,2,3,3,3,2,9,9,3,2,3,2,3,3,9,9,2,2,9,3,3,2,9,9,3,9,9,2,2,2,3,3,1,9,9,9,9,2,9,9,2,2,9,9,2,3,3,3,2,2,3,3,2,9,9,9,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,1,9,9,9,9,2,9,9,2,2,9,2,2,3,3,9,2,3,3,3,2,9,9,2,2,3,3,9,3,9,2,9,3,9,2,2,2,3,3,2,3,3,3,3,3,3,3,3,2,9,9,1,9,9,9,9,2,9,9,2,2,9,3,2,9,9,1,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,1,2,2,1,9,9,9,9,2,9,9,2,2,9,3,2,9,9,2,2,3,9,9,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,2,9,9,2,2,9,3,2,9,9,2,2,3,9,9,2,2,3,3,2,9,9,2,2,3,2,3,3,3,3,2,2,9,2,3,3,3,3,3,3,3,3,3,2,4,3,1,9,9,9,9,2,9,9,2,2,9,3,2,9,2,2,2,3,9,2,2,2,3,3,2,2,2,3,2,3,2,3,3,3,9,2,2,3,3,3,3,3,2,3,3,3,3,3,2,9,3,1,9,9,9,9,2,9,1,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,9,9,9,9,9,9,2,2,9,2,9,2,9,3,2,3,9,2,3,2,2,9,2,2,3,3,2,2,3,2,2,2,2,3,3,2,3,3,3,3,3,2,3,3,2,3,3,2,3,3,1,9,9,9,9,9,9,2,2,9,2,9,2,9,3,2,3,9,2,3,2,2,9,2,2,3,3,3,2,2,2,3,2,3,3,3,2,3,3,2,2,3,3,3,3,2,3,3,2,3,3,1,9,9,9,9,9,9,2,2,9,2,2,2,2,2,2,3,3,2,9,2,2,2,3,2,2,3,3,2,2,2,3,2,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,2,2,9,2,3,2,2,3,2,3,2,2,3,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,1,2,2,2,2,2,1,9,9,9,9,9,9,2,2,9,2,3,2,3,3,2,9,3,2,9,2,2,3,3,2,3,2,2,2,3,2,3,2,2,2,2,2,3,3,3,3,3,3,2,2,2,3,3,2,3,3,1,9,9,9,9,9,9,2,2,9,2,3,2,3,3,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,3,3,3,1,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,2,9,9,2,9,2,3,9,2,2,3,2,9,2,2,3,3,2,2,3,3,2,3,2,3,2,3,3,3,2,9,2,2,2,3,3,3,3,2,3,4,2,2,2,1,9,9,9,9,9,9,2,9,9,2,9,2,2,3,2,2,3,2,3,2,2,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,1,9,9,9,9,9,9,2,9,9,2,9,9,3,9,2,2,9,2,9,2,2,3,3,2,2,3,3,2,2,2,3,2,2,3,3,2,2,3,3,2,3,3,3,1,2,2,2,2,2,2,1,9,9,9,9,9,9,2,9,9,2,9,9,3,9,2,2,9,2,2,2,2,3,9,2,3,3,3,2,2,3,3,2,3,3,3,2,3,3,3,2,3,3,2,2,2,3,3,2,3,9,1,9,9,9,9,9,9,2,9,9,2,9,1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,2,2,3,3,2,3,3,3,2,3,3,3,2,2,2,3,2,2,3,3,2,9,9,1,9,9,9,9,9,9,2,9,9,2,9,2,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,1,9,9,9,9,9,9,2,9,9,2,9,2,3,9,2,2,9,2,3,2,2,9,3,2,3,3,2,2,3,3,9,2,2,3,3,2,3,3,3,2,3,3,3,2,2,3,2,2,3,3,1,9,9,9,9,9,9,2,9,9,2,9,2,3,9,2,2,3,2,3,2,2,2,3,2,3,3,2,2,3,3,2,2,3,3,3,2,3,3,3,2,3,3,3,2,2,2,3,2,3,3,1,9,9,9,9,9,9,2,9,9,2,9,2,3,9,2,2,3,2,2,2,2,3,3,2,3,2,2,2,3,3,2,2,3,3,3,2,3,3,4,2,2,3,3,2,2,3,3,2,3,3,1,9,9,9,9,9,9,2,9,1,2,2,2,2,2,2,2,2,2,3,2,2,3,3,2,3,2,2,2,3,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,2,9,2,2,9,2,9,9,2,2,9,2,3,2,2,3,3,2,3,3,2,2,3,2,3,2,3,3,2,2,3,3,2,2,3,2,2,2,2,3,3,2,2,2,1,9,9,9,9,9,9,2,9,2,2,9,2,9,9,2,2,9,2,3,2,2,3,2,2,2,3,2,2,3,2,3,2,3,3,2,2,3,3,3,1,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,2,9,2,2,9,2,2,3,2,2,3,2,3,3,2,3,3,2,3,3,2,3,2,2,3,2,3,2,3,2,3,3,3,2,2,2,3,2,2,2,3,2,3,3,1,9,9,9,9,9,9,2,9,2,2,9,2,3,3,2,2,9,2,3,3,2,3,3,2,3,3,2,3,2,2,3,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,2,9,2,2,9,2,3,9,2,2,9,2,3,3,2,3,3,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,2,9,2,2,9,2,3,9,2,2,2,2,3,3,2,3,3,2,3,3,2,2,3,2,3,2,2,3,3,2,3,2,3,2,3,2,2,2,2,3,3,2,3,2,1,9,9,9,9,9,9,2,9,2,2,9,2,9,9,2,2,2,2,3,3,2,3,3,2,3,3,2,2,3,2,4,2,2,3,3,2,2,3,3,2,3,2,3,2,2,3,3,2,3,3,1,9,9,9,9,9,9,2,9,2,2,9,2,9,1,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9,9,9,9,9,9,9,9,2,9,9,2,9,2,2,2,3,3,9,2,2,4,9,2,3,3,2,2,3,2,2,3,2,3,9,2,3,3,3,2,2,2,3,2,2,3,3,2,3,3,1,9,9,9,9,9,9,9,9,2,9,9,2,9,2,2,2,3,3,9,2,2,3,3,2,3,3,2,2,3,2,2,3,2,9,9,2,3,3,3,2,2,2,3,2,2,2,3,2,3,3},jl[51][51];

int main()
{
	cin>>T;
	
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		cout<<min(2,ans[a][b])<<endl;
	}
	return 0;
 }
 