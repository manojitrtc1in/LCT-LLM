






























































































































































































using namespace std;
int h[maxn],k[maxn],l[maxn],r[maxn];
void solve(){
	int n;
	cin>>n;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(l));
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++){
		l[i]=k[i]-h[i]+1;
		r[i]=k[i];
	}
	
	for(int i=1;i<=n;i++){
		if(l[i]<=r[i-1]){
			int j=i;
			int p=lower_bound(r+1,r+1+i,l[i])-r;
			

			for(int j=p;j<=i;j++){
				l[j]=min(l[p],l[i]);
				r[j]=r[i];
			}
		}
	}
	













	long long ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]==l[i-1]&&r[i]==r[i-1])continue;
		int num=r[i]-l[i]+1;
		ans+=1ll*(num+1)*num/2;
		if(l[i]-r[i-1]>1&&l[i-1]!=0){
			;

		}
	}
	cout<<ans<<endl;
}

int main(){
	

	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}