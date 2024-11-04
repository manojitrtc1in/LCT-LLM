


















































































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






ll f[4233][220];
struct point{
	ll x,y;
}p[4111];
const ll mod=1000000007;
bool cmp(cl_hst((point,x,y))){
	return x.x^y.x?x.x<y.x:x.y<y.y;
}
ll pow(cl_hst((ll,x,b))){
	ll ans=1;
	while(b){
		(b&1)&&((ans*=x)%=mod);
		(x*=x)%=mod;
		b>>=1;
	}
	return ans;
}
ll cl_ri([2111111],jc,ny);
ll C(cl_hst((ll,n,m))) {


	return jc[m]*ny[n]%mod*ny[m-n]%mod;
}
ll dis(cl_hst((ll,x1,x2,y1,y2))){
	return C(x2-x1,x2+y2-x1-y1);
}
ll d(cl_hst((ll,x,y))){
	return dis(p[x].x,p[y].x,p[x].y,p[y].y);
}
ll tj(cl_hst((ll,x,y))){
	return p[x].x<=p[y].x&&p[x].y<=p[y].y;
}














int main() {
	

	ll rill(n,m,k,s),cl_ri(=n+m,nm);
	jc[0]=1;
	rep(i,1,nm)jc[i]=jc[~-i]*i%mod;

	ny[nm]=pow(jc[nm],mod-2);
	for(ll i=nm-1;i>=0;i--)ny[i]=ny[-~i]*-~i%mod;

	rep(i,1,k)rill(p[i].x,p[i].y);
	p[0].x=1,p[0].y=1;
	p[k+1].x=n,p[k+1].y=m;
	std::sort(p+1,p+k+1,cmp);
	ll cl_ri(=log(s+0.0)/log(2.0)+5,z);
	f[0][0]=1;
	rep(i,1,k+1){
		rep(j,1,z)rep(_i,0,i-1)if(tj(_i,i))(((f[i][j]+=(f[_i][j-1]-f[_i][j])*d(_i,i))%=mod)+=mod)%=mod;
		f[i][0]=f[i][1];
	}












	ll ri0(ans),cl_ri(=pow(C(n-1,n-1+m-1),mod-2),faz);
	rep(i,1,z,i++,s=(s+1)/2)(((ans+=s*(f[k+1][i]-f[k+1][i+1]))%=mod)+=mod)%=mod;

	printf("%lld\n",(ans*faz%mod+mod)%mod);




 	return 0;
} 