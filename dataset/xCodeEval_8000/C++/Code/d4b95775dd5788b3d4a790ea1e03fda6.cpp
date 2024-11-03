
#include<cstdio>
#define ll long long
#define ls (i<<1)
#define rs (i<<1|1)
#define mid (l+r>>1)
using namespace std;
const int N=800010,mod=1000000007;
inline int read(){
	int x=0,c=getchar(),f=0;
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,tr[N],s[N<<2],a[N],b[N],c[N];
void add(int x,int k){
	for(;x<=n;x+=x&-x)tr[x]+=k;
}
int get(int x){
	int res=0;
	for(;x;x-=x&-x)res+=tr[x];
	return res;
}
void build(int i,int l,int r){
	if(l==r){s[i]=1;return;}
	build(ls,l,mid);
	build(rs,mid+1,r);
	s[i]=s[ls]+s[rs];
}
int find(int i,int l,int r,int k){
	s[i]--;if(l==r)return l;
	if(k<=s[ls])return find(ls,l,mid,k);
	else return find(rs,mid+1,r,k-s[ls]);
}
int main(){
	int i,k;n=read();build(1,1,n);
	for(i=1;i<=n;i++)add(i,1);
	for(i=1;i<=n;i++){
		a[i]=read()+1;
		c[i]+=get(a[i])-1;
		add(a[i],-1);
	}
	for(i=1;i<=n;i++)add(i,1);
	for(i=1;i<=n;i++){
		b[i]=read()+1;
		c[i]+=get(b[i])-1;
		add(b[i],-1);
	}
	for(i=n,k=1;i;k++,i--)
	c[i-1]+=c[i]/k,c[i]%=k;
	for(i=1;i<=n;i++){
		write(find(1,1,n,c[i]+1)-1);
		if(i<n)putchar(' ');else putchar('\n');
	}return 0;
}