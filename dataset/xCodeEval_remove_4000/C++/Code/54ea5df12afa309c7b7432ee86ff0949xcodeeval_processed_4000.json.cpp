





using namespace std;
const int N=200100,mod=1e8;
inline int read(){
    int x=0,c=getchar(),f=0;
    for(;c>'9'||c<'0';f=c=='-',c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
    x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
void write(ll x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
vector<pair<int,int> >ask[N];
int a[N],s[N],q[N],t,ans[N];
double fuck(int j,int k){
	double g=s[k]-s[j]+j*a[j]-k*a[k];
	g/=0.0+a[k]-a[j];
	return g;
}
int main(){
	int m,x,y,k,i,n=read();
	for(i=1;i<=n;i++)
	a[i]=read(),s[i]=s[i-1]+a[i];m=read();
	for(i=1;i<=m;i++){
		x=read();y=read();
		ask[y].push_back(make_pair(x,i));
	}
	for(i=1;i<=n;i++){
		while(t&&a[q[t]]>=a[i])t--;
		while(t>1&&fuck(q[t-1],i)<=fuck(q[t],i))t--;
		q[++t]=i;
		for(x=ask[i].size()-1;x>=0;x--){
			y=ask[i][x].first;
			k=ask[i][x].second;
			int l,r;r=t;
			l=lower_bound(q,q+t+1,i-y+1)-q;
			l--;while(l<r-1)
			if(fuck(q[(l+r>>1)],q[(l+r>>1)+1])>=y-i)
			l=l+r>>1;
			else r=l+r>>1;
			l=q[r];
			ans[k]=s[i]-s[l]+(y-i+l)*a[l];
		}
	}
	for(i=1;i<=m;i++)write(ans[i]),putchar('\n');
    return 0;
}