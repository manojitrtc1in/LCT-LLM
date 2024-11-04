



typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=1e5;
int n,m,a,chot[maxn+3],dem[maxn+3];

int main()
{
	IOS;
	cin>>n>>m;
	int j=n;
	for (int i=1;i<=m;i++) {
		cin>>a;
		if (dem[a]==0) n--;dem[a]++;
		if (n==0) {
			chot[i]=1;
			for (int p=1;p<=j;p++) dem[p]--,n+=dem[p]==0?1:0;
		}
	}
	for (int i=1;i<=m;i++) cout<<chot[i];
}

