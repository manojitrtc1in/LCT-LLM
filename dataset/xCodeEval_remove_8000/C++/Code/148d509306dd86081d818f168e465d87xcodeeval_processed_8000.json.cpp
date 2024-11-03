





















 










using namespace std;
const int N=1e6+5;
int l[N],r[N],c[N],a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int mx=0,pos;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
			pos=i;
		}
	}
	b[n+1]=mx;
	for(int i=1;i<=n;i++){
		b[i]=a[pos++];
		if(pos>n)
			pos=1;
	}
	for(int i=2;i<=n;i++){
		l[i]=i-1;
		while(l[i]>1&&b[i]>=b[l[i]])
			l[i]=l[l[i]];
	}
	for(int i=n;i>=1;i--){
		r[i]=i+1;
		while(r[i]<=n&&b[i]>b[r[i]])
			r[i]=r[r[i]];
		if(r[i]<=n&&b[i]==b[r[i]]){
			c[i]=c[r[i]]+1;
			r[i]=r[r[i]];
		}
	}
	long long ans=0;
	for(int i=2;i<=n;i++){
		ans+=c[i];
		ans+=2;
		if(l[i]==1&&r[i]==n+1)
			ans--;
	}
	cout<<ans<<"\n";
}

