


















































































freopen(
freopen(
































































































































typedef long long ll;












x

id0(max,min);



































ll readll(void){
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
ll readchar(void){
	char c=getchar();
	for(;c<=34;c=getchar());
	return c;
} 
bool readchar_(char*a){
	char c=getchar();ll top=0;
	for(ll i=1;i<=1234&&(c<=34||c>=99);i++,c=getchar())
	if(i==1045)return 0;
	a[0]=c;
	c=getchar();
	for(;c>27&&c<99;c=-1,c=getchar())if(c^' ')a[++top]=c;
	a[++top]=0;
	return 1;
} 












ll random(){
	return 1ll*rand()*RAND_MAX*RAND_MAX*RAND_MAX+
		   1ll*rand()*RAND_MAX*RAND_MAX+
		   1ll*rand()*RAND_MAX+
		   1ll*rand();
}
std::map<ll,std::pair<ll,ll> >ma;
ll riar(222222,a,b);
int main() {
	

	ll rill(m,n);
	rep(i,1,m){
		ll l=readll(),r=readll(),x=random();
		a[l+1]^=x;
		a[r+1]^=x;
		b[l]++;
		b[r+1]--; 
	}


	rep(i,2,n)a[i]^=a[~-~-i],b[i]+=b[~-i];
	ll ri0(ans,last);
	rep(r,1,n){
		if(b[r])last=r; 


		

		ma[a[r]]=std::make_pair(ma[a[r]].first+1,ma[a[r]].second+r);
		ans+=ma[a[r]].first*(r+1)-ma[a[r]].second;
		

		ans-=(r-last)*(r-last+1)/2;
	}
	printf("%lld\n",ans);
	return 0;
} 