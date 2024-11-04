












































































































































































































































typedef long long ll;












x

id0(max,min);



































ll readll(void){ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());return x*w;}
ll readchar(void){char c=getchar();for(;c<=34;c=getchar());return c;} 
bool id1(char*a){char c=getchar();ll top=0;for(ll i=1;i<=1234&&(c<=34||c>=99);i++,c=getchar())if(i==1045)return 0;a[0]=c;c=getchar();for(;c>27&&c<99;c=-1,c=getchar())if(c^' ')a[++top]=c;a[++top]=0;return 1;} 
























ll riar(222222,next,f);
ll fi(ll u){
	return u^f[u]?f[u]=fi(f[u]):u;
}
int main() {
	

	ll rill(n,m);
	rep(i,1,n){
		next[f[i]=i]=i+1;
	}
	rep(news,1,m){
		ll rill(c,x,y);
		if(x>y)x^=y^=x^=y; 
		switch(c){
			case 1:
				if(fi(x)^fi(y))
				f[fi(y)]=fi(x);
				break;
			case 2:
				for(ll i=x,_;i<=y&&i;i=_){
					if(fi(x)^fi(i))
					f[fi(i)]=fi(x);
					_=next[i];
					next[i]=next[y];
				}
				break;
			case 3:
				puts(fi(x)==fi(y)?"YES":"NO");
				break;
		}
	}
	return 0;
} 