












using namespace std;
ll read(){
    ll x=0,f=1; char ch=getchar();
    while (!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}


int gg=0;
int n;
ll ans[100500];
int main(){
 

	n=read();
	for (ll i=1;i<=n;i++) if (i==1) puts("2"); else printf("%lld\n",1LL*(1LL*i*(i+1)*(i+1)-(i-1)));
	
    return 0;
}
