





















 





















using namespace std;
typedef long long ll;
int a[1000005],b[1000005];
int ls[1000005],rs[1000005],c[1000005];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int pos,mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
			pos=i;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=a[pos++];
		if(pos>n)
			pos=1;
	}
	b[n+1]=mx;
	for(int i=2;i<=n;i++){
		ls[i]=i-1;
		while(ls[i]>1&&b[i]>=b[ls[i]])
			ls[i]=ls[ls[i]];
	}
	for(int i=n;i>=1;i--){
		rs[i]=i+1;
		while(rs[i]<=n&&b[i]>b[rs[i]])
			rs[i]=rs[rs[i]];
		if(rs[i]<=n&&b[i]==b[rs[i]]){
			c[i]=c[rs[i]]+1;
			rs[i]=rs[rs[i]];
		}
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		ans+=2;
		ans+=c[i];
		if(ls[i]==1&&rs[i]==n+1)
			ans--;
	}
	cout<<ans<<"\n";
}
