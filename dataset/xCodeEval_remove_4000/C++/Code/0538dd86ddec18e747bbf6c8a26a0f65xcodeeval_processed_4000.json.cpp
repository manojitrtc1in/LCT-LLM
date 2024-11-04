

using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;







using namespace std;


struct Node{
	int l,r;
	mutable ll v;
	Node(int L,int R=-1,ll V=0){l=L;r=R;v=V;}
	inline bool operator <(const Node &n)const{return l<n.l;}
};
typedef set<Node>::iterator IT;
set<Node> cdr;
ll sd;
IT split(int pos){
	IT it=cdr.lower_bound(Node(pos));
	if(it!=cdr.end()&&it->l==pos) return it;
	--it;
	int L=it->l,R=it->r;
	ll V=it->v;
	cdr.erase(it);
	cdr.insert(Node(L,pos-1,V));
	return cdr.insert(Node(pos,R,V)).first;
}
void add(int l,int r,ll val){
	IT itr=split(r+1),itl=split(l);
	for(;itl!=itr;itl++){
		itl->v+=val;
	}
}
inline void assign_val(int l,int r,ll v){
	IT itr=split(r+1),itl=split(l);
	cdr.erase(itl,itr);
	cdr.insert(Node(l,r,v)); 
}
ll kth(int l,int r,int x){
	vector<pair<ll,int> > vp;
	IT itr=split(r+1),itl=split(l);
	for(;itl!=itr;itl++){
		vp.push_back(pair<ll,int>(itl->v,itl->r-itl->l+1));
	}
	sort(vp.begin(),vp.end());
	for(vector<pair<ll,int> >::iterator it=vp.begin();it!=vp.end();++it){
		x-=it->S;
		if(x<=0) return it->F;
	}
}
inline ll rd(){
	ll rt=sd;
	sd=(sd*7+13)%mod;
	return rt;
}
ll mi(ll a, ll b, ll p){
    ll res=1;
    ll ans=a%p;
    while(b){
        if(b&1) res=res*ans%p;
        ans=ans*ans%p;
        b>>=1;
    }
    return res;
}
ll addm(int l,int r,ll x,ll y){
	ll ans=0;
	IT itr=split(r+1),itl=split(l);
	for(;itl!=itr;itl++){
		ans=(ans+mi(itl->v,x,y)*(itl->r-itl->l+1))%y;
	}
	return ans;
}
int main(){
	int n,m,vmax,val,op,y,l,r;
	scanf("%d%d%lld%d",&n,&m,&sd,&vmax);
	for(int i=1;i<=n;i++){
		val=rd()%vmax+1;
		

		cdr.insert(Node(i,i,val));
	}
	cdr.insert(Node(n+1,n+1,0));
	for(int i=1;i<=m;i++){
		op=rd()%4+1;
		l=rd()%n+1;
		r=rd()%n+1;
		if(l>r) swap(l,r);
		if(op==1){
			val=rd()%vmax+1;
			add(l,r,val);
		}else if(op==2){
			val=rd()%vmax+1;
			assign_val(l,r,val);
		}else if(op==3){
			val=rd()%(r-l+1)+1;
			printf("%lld\n",kth(l,r,val));
		}else if(op==4){
			val=rd()%vmax+1;
			y=rd()%vmax+1;
			printf("%lld\n",addm(l,r,val,y));
		}else assert(0);
	}
    return 0;
}