#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define down(i,l,r) for (int i=l;i>=r;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define maxn 200500
#define inf (int)1e9
#define ll unsigned long long
#define eps 1e-9
#define mm 4294967296LL
#define low(x) x&(-x)
#define pb push_back
#define mp make_pair
#define PII pair<int,int>
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
