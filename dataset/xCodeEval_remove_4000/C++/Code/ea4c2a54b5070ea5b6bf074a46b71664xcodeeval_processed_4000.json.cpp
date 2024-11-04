
using namespace std;


const int Maxm=(1<<22)+5,Maxn=(1<<17);
const int ch=19260817,wsr=2066076461;



mt19937 jtrand;
int mii[Maxn];
int n;
int a[Maxn];

struct Segtree{
	struct Node{
		int val,fix,sz;
		int lhs,rhs;
		Node *l,*r;
		void pushup(){
			sz=Sz(l)+1+Sz(r);
			lhs=((1ll*Lhs(l)*ch+val)%wsr*mii[Sz(r)]+Lhs(r))%wsr;
			rhs=((1ll*Rhs(r)*ch+val)%wsr*mii[Sz(l)]+Rhs(l))%wsr;
		}
	}nds[Maxm];
	typedef Node *node;
	int Nds;
	node newnode(int val){
		node nd=&nds[Nds++];
		nd->val=nd->lhs=nd->rhs=val;
		nd->fix=jtrand();
		nd->sz=1;
		nd->l=nd->r=0;
		return nd;
	}
	node dream(node real){
		node nd=&nds[Nds++];
		*nd=*real;
		return nd;
	}
	void split(node now,int val,node &a,node &b){
		if(!now){
			a=b=0;
			return;
		}
		if(Sz(now->l)<val){
			a=dream(now);
			split(now->r,val-Sz(now->l)-1,a->r,b);
			a->pushup();
		}else{
			b=dream(now);
			split(now->l,val,a,b->l);
			b->pushup();
		}
	}
	node merge(node a,node b){
		if(!a||!b){
			return a?a:b;
		}
		node dr;
		if(a->fix<b->fix){
			dr=dream(a);
			dr->r=merge(dr->r,b);
		}else{
			dr=dream(b);
			dr->l=merge(a,dr->l);
		}
		dr->pushup();
		return dr;
	}
	struct Segnode{
		bool can;
		node foo,dgn;
		Segnode(){
			can=1;
			foo=dgn=0;
		}
	}dt[Maxn<<1];
	Segnode newsegn(int val){
		Segnode nd;
		if(val<0){
			nd.foo=newnode(-val);
		}else{
			nd.dgn=newnode(val);
		}
		return nd;
	}
	Segnode merge(Segnode a,Segnode b){
		Segnode res;
		if(!a.can||!b.can){
			res.can=0;
		}else{
			if(Sz(a.dgn)>=Sz(b.foo)){
				node l,r;
				split(a.dgn,Sz(a.dgn)-Sz(b.foo),l,r);
				if(Lhs(r)!=Rhs(b.foo)){
					res.can=0;
				}else{
					res.foo=a.foo;
					res.dgn=merge(l,b.dgn);
				}
			}else{
				node l,r;
				split(b.foo,Sz(a.dgn),l,r);
				if(Rhs(l)!=Lhs(a.dgn)){
					res.can=0;
				}else{
					res.dgn=b.dgn;
					res.foo=merge(a.foo,r);
				}
			}
		}
		return res;
	}
	void initial(){
		Nds=0;
		for(int i=1;i<=n;i++){
			dt[i+Maxn]=newsegn(a[i]);
		}
		for(int i=Maxn-1;i;i--){
			dt[i]=merge(dt[i<<1],dt[i<<1|1]);
		}
	}
	void change(int to,int x){
		to+=Maxn;
		dt[to]=newsegn(x);
		to>>=1;
		while(to){
			dt[to]=merge(dt[to<<1],dt[to<<1|1]);
			to>>=1;
		}
	}
	Segnode query(int l,int r){
		Segnode lp,rp;
		l+=Maxn;
		r+=Maxn;
		while(l<r){
			if(l&1){
				lp=merge(lp,dt[l++]);
			}
			if(r&1){
				rp=merge(dt[--r],rp);
			}
			l>>=1;
			r>>=1;
		}
		return merge(lp,rp);
	}
}seg;

int main(){
	jtrand.seed(114514^time(0)^1919810);
	mii[0]=1;
	for(int i=1;i<Maxn;i++){
		mii[i]=1ll*mii[i-1]*ch%wsr;
	}
	int q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	seg.initial();
	scanf("%d",&q);
	while(q--){
		int lx,x,y;
		scanf("%d%d%d",&lx,&x,&y);
		if(lx==1){
			a[x]=y;
			seg.change(x,y);
		}else{
			auto res=seg.query(x,y+1);
			if(res.can&&!Sz(res.dgn)&&!Sz(res.foo)){
				puts("Yes");
			}else{
				puts("No");
			}
		}
		if(seg.Nds+2333>=Maxm){
			

			

			seg.initial();
		}
	}
	return 0;
}
