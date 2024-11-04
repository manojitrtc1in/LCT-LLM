








































typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
using namespace std;

int a[N],sum[N];
int cnt,ans;
int main(){
	Speedforce
    int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i%k]+=a[i];
	}
	int mn=(int)1e9,ans;

	for(int i=0;i<k;i++){
		if(mn>sum[i]){
			mn=sum[i];
			ans=i%k+1;
		}
	}
	printf("%d",ans);
	return 0;
}