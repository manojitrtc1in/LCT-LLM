

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;





int n,p[N],pp[N],q[N];
struct SegTree{
	int a[N<<2],tg[N<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	inline void push_up(int p){a[p]=max(a[lc(p)],a[rc(p)]);}
	inline void f(int p,int k){a[p]+=k;tg[p]+=k;}
	inline void push_down(int p){f(lc(p),tg[p]);f(rc(p),tg[p]);tg[p]=0;}
	inline void update(int p,int l,int r,int L,int R,int k){
		if(L>R) return;
		if(L<=l&&r<=R){f(p,k);return;}
		int mid=l+r>>1;
		push_down(p);
		if(L<=mid) update(lc(p),l,mid,L,R,k);
		if(mid<R) update(rc(p),mid+1,r,L,R,k);
		push_up(p);
	}
	inline int query(int p,int l,int r,int L,int R){ 
		if(L<=l&&r<=R) return a[p];
		int mid=l+r>>1,res=0;
		push_down(p);
		if(L<=mid) res=max(res,query(lc(p),l,mid,L,R));
		if(mid<R) res=max(res,query(rc(p),mid+1,r,L,R));
		return res;
	}
}tr;
int main(){
	scanf("%d",&n);
	int ans=n+1;
	for(int i=1;i<=n;++i){
		scanf("%d",p+i);
		pp[p[i]]=i;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",q+i);
		tr.update(1,1,n,1,q[i-1],-1);
		while(tr.query(1,1,n,1,n)<=0){
			--ans;
			tr.update(1,1,n,1,pp[ans],1);
		}
		printf("%d ",ans);
	}
	return 0;
}
