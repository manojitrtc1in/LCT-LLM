
using namespace std;


const int Block=333,Maxn=100000;
const int jt=1000000007,wsr=2066076461;
const int t1=19260817,t2=20200429;


int n,q;
int mii1[Block],mii2[Block];
int ls[Block],rs[Block];
int a[Maxn+5];
bool shit[Block];
int Blocks;

void init(){
	mii1[0]=mii2[0]=1;
	for(int i=1;i<Block;i++){
		mii1[i]=1ll*mii1[i-1]*t1%jt;
		mii2[i]=1ll*mii2[i-1]*t2%wsr;
	}
}

struct SingleBlock{
	int val[Block+5],hsh1[Block+5],hsh2[Block+5];
	int sz;
	void make(){
		hsh1[0]=hsh2[0]=0;
		for(int i=1;i<=sz;i++){
			hsh1[i]=(1ll*hsh1[i-1]*t1+val[i])%jt;
			hsh2[i]=(1ll*hsh2[i-1]*t2+val[i])%wsr;
		}
	}
	long long gethash(int r,int len){
		int res1=(hsh1[r]-1ll*hsh1[r-len]*mii1[len]%jt+jt)%jt;
		int res2=(hsh2[r]-1ll*hsh2[r-len]*mii2[len]%wsr+wsr)%wsr;
		return 1ll*res1*wsr+res2;
	}
}L[Block],R[Block];

int stk[355];

void remake(int bl,int Ls=-1,int Rs=-1){
	int siz=0;
	int l=ls[bl],r=rs[bl];
	shit[bl]=0;
	if(~Ls){
		l=Ls;
		r=Rs;
	}
	for(int i=l;i<=r;i++){
		if(a[i]<0&&siz&&stk[siz-1]==-a[i]){
			siz--;
		}else{
			stk[siz++]=a[i];
		}
	}
	for(int i=1;i<siz;i++){
		if(stk[i-1]>0&&stk[i]<0){
			shit[bl]=1;
			return;
		}
	}
	L[bl].sz=R[bl].sz=0;
	for(int i=siz-1;i>=0;i--){
		if(stk[i]<0){
			L[bl].val[++L[bl].sz]=-stk[i];
		}
	}
	for(int i=0;i<siz;i++){
		if(stk[i]>0){
			R[bl].val[++R[bl].sz]=stk[i];
		}
	}
	L[bl].make();
	R[bl].make();
}

void change(int to,int x){
	a[to]=x;
	remake(which(to));
}

pair<int,int> Stk[355];

bool isvalid(int l,int r){
	int lk=which(l),rk=which(r);
	if(lk==rk){
		int siz=0;
		for(int i=l;i<=r;i++){
			if(a[i]<0&&siz&&stk[siz-1]==-a[i]){
				siz--;
			}else{
				stk[siz++]=a[i];
			}
		}
		return !siz;
	}else{
		remake(Blocks+1,l,rs[lk]);
		remake(Blocks+2,ls[rk],r);
		int siz=0;
		bool can=1;
		auto Addblock=[&](int bl){
			if(shit[bl]){
				can=0;
			}
			if(!can){
				return;
			}
			int sz=L[bl].sz;
			while(siz&&can&&sz){
				int lens=min(Stk[siz].second,sz);
				if(R[Stk[siz].first].gethash(Stk[siz].second,lens)!=L[bl].gethash(sz,lens)){
					can=0;
				}
				Stk[siz].second-=lens;
				if(!Stk[siz].second){
					siz--;
				}
				sz-=lens;
			}
			if(sz){
				can=0;
			}
			if(R[bl].sz){
				Stk[++siz]=make_pair(bl,R[bl].sz);
			}
		};
		Addblock(Blocks+1);
		for(int i=lk+1;i<rk;i++){
			Addblock(i);
		}
		Addblock(Blocks+2);
		if(siz){
			can=0;
		}
		return can;
	}
}

int main(){
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	Blocks=which(n);
	for(int i=1;i<=Blocks;i++){
		ls[i]=(i-1)*Block+1;
		rs[i]=min(n,i*Block);
		remake(i);
	}
	scanf("%d",&q);
	while(q--){
		int lx,x,y;
		scanf("%d%d%d",&lx,&x,&y);
		if(lx==1){
			change(x,y);
		}else{
			puts(isvalid(x,y)?"Yes":"No");
		}
	}
	return 0;
}
