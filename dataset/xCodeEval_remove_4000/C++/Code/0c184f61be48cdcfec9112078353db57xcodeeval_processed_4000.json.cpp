
using namespace std;
const int N=1e6+7,p=998244353; bool id1=0;
int n,k,q,kt,qt,pf,s1,s2,l1,a1,a2,lt[N],rt[N],w[N],gt[N],inv[N],pos[N],c1[N],c2[N],f1[N],f2[N],f3[N],f4[N],f5[N],f6[N],g1[N],g2[N],g3[N],g4[N];
inline int read(){
	int num=0; char t='+',g=getchar(); while(g<48||57<g) t=g,g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
	if(t=='-') return -num; return num;
}
inline pair<int,int>getl(int t,int l){
	if(l==0) return make_pair(0,0);
	
	if(f2[t]==l){
		if(g3[t<<1|1]>=l) return getl(t<<1|1,l);
		return make_pair(f4[t],f6[t]);
	}
	if(g3[t<<1|1]>=l) return getl(t<<1|1,l);
	
	pair<int,int>g=getl(t<<1,l-f2[t<<1|1]+f1[t<<1|1]);
	g.first=(g.first-f3[t<<1|1]+p)%p,g.second=(g.second-f5[t<<1|1]+p)%p;
	if(g.first==-1||g.second==-1||f4[t<<1|1]==-1||f6[t<<1|1]==-1){
		g.first=g.second=-1; return g;
	}
	g.first=(1ll*g.first*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]+f4[t<<1|1])%p;


	g.second=(1ll*g.second*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]+f6[t<<1|1])%p;
	
	return g;
}
inline pair<int,int>getr(int t,int l){
	if(l==0) return make_pair(0,0);
	if(f1[t]==l){
		if(g2[t<<1]<=-l) return getr(t<<1,l);
		return make_pair(f3[t],f5[t]);
	}
	if(g2[t<<1]<=-l) return getr(t<<1,l);
	
	pair<int,int>g=getr(t<<1|1,l-f1[t<<1]+f2[t<<1]);
	if(g.first==-1||g.second==-1||f3[t<<1]==-1||f5[t<<1]==-1){
		g.first=g.second=-1; return g;
	}
	g.first=(1ll*(g.first-f4[t<<1]+p)*gt[f1[t<<1]]%p*inv[f2[t<<1]])%p;
	g.second=(1ll*(g.second-f6[t<<1]+p)*gt[f1[t<<1]]%p*inv[f2[t<<1]])%p;
	g.first=(g.first+1ll*f3[t<<1]+p)%p;
	g.second=(1ll*g.second+1ll*f5[t<<1]+p)%p;
	return g;
}
inline void build(int l,int r,int t){
	lt[t]=l,rt[t]=r;
	if(l==r){
		if(w[l]<0) f1[t]=1,f3[t]=c1[-w[l]],f5[t]=c2[-w[l]],g1[t]=g2[t]=g3[t]=g4[t]=-1;
		else f2[t]=1,f4[t]=c1[w[l]],f6[t]=c2[w[l]],g1[t]=g2[t]=g3[t]=g4[t]=1; pos[l]=t;
		return;
	}
	int d=(l+r)>>1; build(l,d,t<<1),build(d+1,r,t<<1|1);
	g1[t]=g1[t<<1]+g1[t<<1|1];
	g2[t]=min(g2[t<<1],g2[t<<1|1]+g1[t<<1]);
	g3[t]=max(g3[t<<1|1],g3[t<<1]+g1[t<<1|1]);
	f1[t]=f1[t<<1],f2[t]=f2[t<<1|1]; int z=min(f2[t<<1],f1[t<<1|1]),q=max(f2[t<<1],f1[t<<1|1]);
	f1[t]=f1[t]-z+f1[t<<1|1],f2[t]=f2[t]-z+f2[t<<1];
	if(f3[t<<1]==-1||f3[t<<1|1]==-1){
		f3[t]=f4[t]=f5[t]=f6[t]=-1; return;
	}
	if(l==10&&r==18) id1=1;
	if(f2[t<<1]<=f1[t<<1|1]){
		pair<int,int>c=getr(t<<1|1,f2[t<<1]);
		if(c.first!=f4[t<<1]||c.second!=f6[t<<1]||f4[t<<1]==-1) f3[t]=f4[t]=f5[t]=f6[t]=-1;
		else{
			f3[t]=(f3[t<<1]+1ll*f3[t<<1|1]*gt[f1[t<<1]]%p*inv[f2[t<<1]]-1ll*f4[t<<1]*gt[f1[t<<1]]%p*inv[f2[t<<1]])%p; if(f3[t]<0) f3[t]+=p;
			f4[t]=f4[t<<1|1];
			f5[t]=(f5[t<<1]+1ll*f5[t<<1|1]*gt[f1[t<<1]]%p*inv[f2[t<<1]]-1ll*f6[t<<1]*gt[f1[t<<1]]%p*inv[f2[t<<1]])%p; if(f5[t]<0) f5[t]+=p;
			f6[t]=f6[t<<1|1];
		}


	}
	else{
		pair<int,int>c=getl(t<<1,z);


		if(c.first!=f3[t<<1|1]||c.second!=f5[t<<1|1]||f3[t<<1|1]==-1) f3[t]=f4[t]=f5[t]=f6[t]=-1;
		else{
			f3[t]=f3[t<<1];
			f4[t]=(1ll*f4[t<<1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]-1ll*f3[t<<1|1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]+f4[t<<1|1])%p; if(f4[t]<0) f4[t]+=p;
			f5[t]=f5[t<<1];
			f6[t]=(1ll*f6[t<<1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]-1ll*f5[t<<1|1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]+f6[t<<1|1])%p; if(f6[t]<0) f6[t]+=p;
		}
		
	}
	id1=0;
	




	
}
inline void update(int t){
	t=t>>1;
	while(t>0){
		f3[t]=f4[t]=f5[t]=f6[t]=0;
		f1[t]=f1[t<<1],f2[t]=f2[t<<1|1]; int z=min(f2[t<<1],f1[t<<1|1]),q=max(f2[t<<1],f1[t<<1|1]);
		f1[t]=f1[t]-z+f1[t<<1|1],f2[t]=f2[t]-z+f2[t<<1];
		g1[t]=g1[t<<1]+g1[t<<1|1];
		g2[t]=min(g2[t<<1],g2[t<<1|1]+g1[t<<1]);
		g3[t]=max(g3[t<<1|1],g3[t<<1]+g1[t<<1|1]);
		if(f3[t<<1]==-1||f3[t<<1|1]==-1){
			f3[t]=f4[t]=f5[t]=f6[t]=-1,t=t>>1; continue;
		}
		if(f2[t<<1]<=f1[t<<1|1]){
			pair<int,int>c=getr(t<<1|1,f2[t<<1]);
			if(c.first!=f4[t<<1]||c.second!=f6[t<<1]||f4[t<<1]==-1) f3[t]=f4[t]=f5[t]=f6[t]=-1;
			else{
				f3[t]=(f3[t<<1]+1ll*f3[t<<1|1]*gt[f1[t<<1]]%p*inv[f2[t<<1]]-1ll*f4[t<<1]*gt[f1[t<<1]]%p*inv[f2[t<<1]])%p; if(f3[t]<0) f3[t]+=p;
				f4[t]=f4[t<<1|1];
				f5[t]=(f5[t<<1]+1ll*f5[t<<1|1]*gt[f1[t<<1]]%p*inv[f2[t<<1]]-1ll*f6[t<<1]*gt[f1[t<<1]]%p*inv[f2[t<<1]])%p; if(f5[t]<0) f5[t]+=p;
				f6[t]=f6[t<<1|1];
			}
		}
		else{
			pair<int,int>c=getl(t<<1,z);
			if(c.first!=f3[t<<1|1]||c.second!=f5[t<<1|1]||f3[t<<1|1]==-1) f3[t]=f4[t]=f5[t]=f6[t]=-1;
			else{
				f3[t]=f3[t<<1];
				f4[t]=(1ll*f4[t<<1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]-1ll*f3[t<<1|1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]+f4[t<<1|1])%p; if(f4[t]<0) f4[t]+=p;
				f5[t]=f5[t<<1];
				f6[t]=(1ll*f6[t<<1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]-1ll*f5[t<<1|1]*inv[f1[t<<1|1]]%p*gt[f2[t<<1|1]]+f6[t<<1|1])%p; if(f6[t]<0) f6[t]+=p;
			}
	

		}
		
		t=t>>1;
	}
}
inline void id0(int l,int r,int t,int ql,int qr){
	if(kt==0) return;


	if(l==ql&&r==qr){
		if(lt[t]==0||rt[t]==0) return; int d=(l+r)>>1;
		if(g3[t<<1|1]>=kt){
			id0(d+1,r,t<<1|1,d+1,r); return;
		}
		if(lt[t]==rt[t]||g3[t]<kt){
			kt=kt+f1[t]-f2[t],pf=l; return;
		}
		if(kt<=g3[t<<1|1]) id0(d+1,r,t<<1|1,d+1,r);
		else{
			kt=kt+f1[t<<1|1]-f2[t<<1|1];
			id0(l,d,t<<1,l,d);
		}
	}
	int d=(l+r)>>1;
	if(d+1<=qr) id0(d+1,r,t<<1|1,max(d+1,ql),qr);
	if(ql<=d) id0(l,d,t<<1,ql,min(d,qr));
}
inline void solve(int l,int r,int t,int ql,int qr){
	if(l==ql&&r==qr){
		a1=(1ll*a1*inv[f1[t]]%p*gt[f2[t]]-1ll*f3[t]*inv[f1[t]]%p*gt[f2[t]]+f4[t])%p;
		a2=(1ll*a2*inv[f1[t]]%p*gt[f2[t]]-1ll*f5[t]*inv[f1[t]]%p*gt[f2[t]]+f6[t])%p;
		if(a1<0) a1+=p; if(a2<0) a2+=p;


		return;
	}
	int d=(l+r)>>1;
	if(ql<=d) solve(l,d,t<<1,ql,min(d,qr));
	if(d+1<=qr) solve(d+1,r,t<<1|1,max(d+1,ql),qr);
	
}
inline void search(int l,int r,int t,int ql,int qr){
	if(s1==-1||s2==-1) return;
	if(l==ql&&r==qr){


		if(l1<f1[t]){
			s1=-1,s2=-1; return;
		}
		if(f3[t]==-1){
			s1=-1,s2=-1; return;
		}
		
		if(f1[t]>0){
			kt=f1[t],qt=kt,pf=ql-1;
			id0(1,n,1,1,ql-1);
			a1=0,a2=0,solve(1,n,1,pf,ql-1);
			
			if(a1!=f3[t]||a2!=f5[t]){
				s1=-1,s2=-1; return;
			}
		}
		int ak=1ll*inv[f1[t]]*gt[f2[t]]%p;


		s1=(1ll*s1*ak-1ll*f3[t]*ak+f4[t])%p;
		s2=(1ll*s2*ak-1ll*f5[t]*ak+f6[t])%p,l1=l1-f1[t]+f2[t];
		if(s1<0) s1+=p; if(s2<0) s2+=p;
		return;
	}
	int d=(l+r)>>1;
	if(ql<=d) search(l,d,t<<1,ql,min(d,qr));
	if(d+1<=qr) search(d+1,r,t<<1|1,max(d+1,ql),qr);
}
int main(){


	srand(19260817); n=read(),k=read(),gt[0]=1,inv[0]=1,inv[1]=729486258; int op,l,r;
	for(int i=2;i<=n;i++) inv[i]=1ll*inv[i-1]*inv[1]%p; 
	for(int i=1;i<=n;i++) w[i]=read(),gt[i]=gt[i-1]*26ll%p;
	for(int i=1;i<=k;i++) c1[i]=c1[i-1]+rand()%3+1,c2[i]=c2[i-1]+rand()%7+1;
	build(1,n,1),q=read(); int zt=0;
	while(q--){
		op=read(),l=read(),r=read();
		if(op==1){
			w[l]=r; int t=pos[l];
			if(w[l]<0) f1[t]=1,f3[t]=c1[-w[l]],f5[t]=c2[-w[l]],f2[t]=f4[t]=f6[t]=0,g1[t]=g2[t]=g3[t]=-1;
			else f2[t]=1,f4[t]=c1[w[l]],f6[t]=c2[w[l]],f1[t]=f3[t]=f5[t]=0,g1[t]=g2[t]=g3[t]=1; update(t);
		}
		else{
			s1=0,s2=0,l1=0;
			search(1,n,1,l,r);


			if(s1==0&&s2==0) puts("Yes"); else puts("No");
		}zt++;
	}
}







