


















































































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







const ll mod=1000000007;
ll cl_ri([3333],a,f[3333],c);
ll cmp(cl_hst((ll,x,y))){
	return a[x]<a[y];
}
int main() {
	

	ll rill(n);
	rep(i,1,n)rill(a[i])-i,c[i]=i;
	std::sort(c,c+n+1,cmp);
	memset(f,0x3f,sizeof(f));
	rep(i,0,n)
	f[0][i]=0;
	rep(i,1,n){
		ll cl_ri(=0x3f3f3f3f3f3f3f3f,minn);
		rep(j,1,n)f[i][j]=(minn=cl_min(minn,f[i-1][j]))+abs(a[i]-a[c[j]]);
		

		

	}
	ll cl_ri(=0x3f3f3f3f3f3f3f3f,minn);
	rep(i,1,n)minn=cl_min(minn,f[n][i]);
	printf("%lld\n",minn);
	return 0;
} 