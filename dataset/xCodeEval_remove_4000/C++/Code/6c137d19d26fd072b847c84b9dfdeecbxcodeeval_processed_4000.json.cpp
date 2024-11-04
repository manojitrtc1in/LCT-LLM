





































using namespace std;
const int Maxk=2;
const int Maxn=100005; 
const int mod=1e9+7;
const int Maxt=300005;
struct node{
	int x,y;
	long long a[Maxk][Maxk];
	node(){
		for (int i=0;i<Maxk;i++){
			for (int j=0;j<Maxk;j++){
				a[i][j]=0LL;
			} 
		}
	}
	void _(int p,int q){
		x=p,y=q;
	}
}I,ar[Maxn],r,Tree[Maxt],tag[Maxt],ini,mqy[33];
void _debug(node x){
	printf("DEBUG:------------------\n");
	printf("size: %d %d\n",x.x,x.y);
	for (int i=0;i<x.x;i++){
		for (int j=0;j<x.y;j++){
			printf("%d ",x.a[i][j]);
		} 
		printf("\n");
	}
	printf("------------------------\n");
}
int L,R,value;
inline node mul(node &A,node &B){
	node c;
	c._(A.x,B.y);
	for (int i=0;i<A.x;i++){
		for (int j=0;j<B.y;j++){
			for (int k=0;k<A.y;k++){
				c.a[i][j]+=(A.a[i][k]*B.a[k][j]);
			
			}
			c.a[i][j]%=mod;
		}
	}
	return c;
}
inline void MOD(long long &x){
	if (x>mod) x-=mod;
}
inline void add(node &A,node &B){
	for (int i=0;i<A.x;i++){
		for (int j=0;j<A.y;j++){
			A.a[i][j]+=B.a[i][j];
			MOD(A.a[i][j]);
		} 
	}
}
inline node add2(node A,node &B){
	for (int i=0;i<A.x;i++){
		for (int j=0;j<A.y;j++){
			A.a[i][j]+=B.a[i][j];
			MOD(A.a[i][j]);
		} 
	}
	return A;
}
inline node quickpow(node x,int p){
	if (p==1) return x;
	if (!p) return I;
	node ans;
	ans=I;
	for (int i=0;i<32;i++){
		if(p&1) ans=mul(ans,mqy[i]);
		p>>=1;
	}
	return ans;
}
inline void build(int l,int r,int p){
	if (l==r) {
		Tree[p]=ar[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	Tree[p]=add2(Tree[p*2],Tree[p*2+1]);
	return;
}
inline void modify(int lo,int hi,int p){
	if (lo>=L && hi<=R){
		node buff=quickpow(r,value);
		tag[p]=mul(buff,tag[p]);
		return;
	}
	int m=(lo+hi)>>1;
	if (L<=m){
		modify(lo,m,p*2);
	}
	if (R>m){
		modify(m+1,hi,p*2+1);
	}
	node lft=mul(tag[p*2],Tree[p*2]),rgt=mul(tag[p*2+1],Tree[p*2+1]);
	add(lft,rgt);
	Tree[p]=lft;
}
inline node query(int lo,int hi,int p){
	if (lo>=L && hi<=R){
		return mul(tag[p],Tree[p]);
	}
	int m=(lo+hi)>>1;
	node ret;
	ret._(2,1);
	if (L<=m){
		node buff=query(lo,m,p*2);
		add(ret,buff);
	}
	if (R>m){
		node buff=query(m+1,hi,p*2+1);
		add(ret,buff);
	}
	return mul(tag[p],ret);
}
int main(){
	I.a[0][0]=1;
	I.a[1][1]=1;
	I._(2,2);
	r.a[0][0]=1;
	r.a[0][1]=1;
	r.a[1][0]=1;
	ini.a[0][0]=1;
	ini.a[1][0]=1;
	ini._(2,1);
	r._(2,2);
	for (int i=0;i<Maxt;i++){
		tag[i]=I;
	}
	mqy[0]=r;
	for (int i=1;i<32;i++) mqy[i]=mul(mqy[i-1],mqy[i-1]);
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		int w;
		scanf("%d",&w);
		ar[i]=quickpow(r,w-1);
		ar[i]=mul(ar[i],ini);
	}

	build(1,n,1);
	while (m--){
		int ty;
		scanf("%d",&ty);
		if (ty==1){
			scanf("%d %d %d",&L,&R,&value);
			modify(1,n,1);
		} 
		else{
			scanf("%d %d",&L,&R);
			node ans=query(1,n,1);
			printf("%I64d\n",ans.a[1][0]);
		}
	}
} 

