



#include<bits/stdc++.h>
using namespace std;


#ifdef XiEn
	struct colored_cerr{
		template<typename T>
		colored_cerr& operator<<(T value){cerr<<"\e[1;31m"<<value<<"\e[0m";return *this;}
		colored_cerr& operator<<(ostream&(*func)(ostream&)){cerr<<func;return *this;}
	}cerr_temp;
	string stmp;
	template<typename... Targs>
	int fprintf_temp(FILE* stream,const char* format,Targs... Fargs){
		if(stream==stderr)stmp="\e[1;31m"+string(format)+"\e[0m";
		else stmp=string(format);
		return fprintf(stream,stmp.c_str(),Fargs...);
	}
	#define cerr cerr_temp
	#define fprintf fprintf_temp
	

#endif
using ll=long long;
using pr=array<ll,2>;

#define all(x) (x).begin(),(x).end()
#define rep(x,a,b) for(int x=(a);x<=(b);x++)
mt19937 rng(time(0)^((ll)new char));
mt19937_64 rng64(time(0)^((ll)new char));
#define rand() (int)(rng()>>1)


using intype=ll;
inline intype qread(){
	intype ret=0;char buf;bool neg=false;
	do{buf=getchar();if(buf=='-')neg=true;}while(!isdigit(buf));
	do{ret=ret*10+buf-'0';buf=getchar();  }while( isdigit(buf));
	return neg?-ret:ret;
}

struct PrintExecTime{
	~PrintExecTime(){fprintf(stderr,"\n[finished in %.0lf ms]\n",clock()*1000.0/CLOCKS_PER_SEC);}
}PrintExecTime_exec;

namespace Neix{
	template<int maxlen,bool get_mu=false,bool get_phi=false>
	struct sieve{
		bool vis[maxlen+5];int prms[maxlen+5],prmcnt;int *mu,*phi;
		void alloc(int*& pt){pt=new int[maxlen+5];memset(pt,0,sizeof(*pt));}
		sieve(){
			prmcnt=0;
			memset(vis,0,sizeof(vis));
			memset(prms,0,sizeof(prms));
			if(get_mu){alloc(mu);mu[1]=0;}    

			if(get_phi){alloc(phi);phi[1]=1;} 

			for(int i=2;i<=maxlen;i++){
				if(!vis[i]){
					prms[++prmcnt]=i;
					if(get_mu){mu[i]=-1;}
					if(get_phi){phi[i]=i-1;}
				}
				for(int j=1;j<=prmcnt&&i*prms[j]<=maxlen;j++){
					vis[i*prms[j]]=true;
					if(i%prms[j]==0){if(get_phi){phi[i*prms[j]]=phi[i]*prms[j];}break;}
					if(get_mu){mu[i*prms[j]]=-mu[i];}
					if(get_phi){phi[i*prms[j]]=phi[i]*phi[prms[j]];}
				}
			}
		}
	};
	template<typename valtype,int maxL>
	struct BIT{
		valtype seq[maxL+1];
		BIT(){memset(seq,0,sizeof(seq));}
		void modify(int pos,valtype val){while(pos<=maxL){seq[pos]=seq[pos]+val;pos+=pos&-pos;}}
		valtype query(int pos){valtype tmp=0;for(;pos>0;pos-=pos&-pos){tmp=seq[pos]+tmp;}return tmp;}
	};
	template<int maxL>
	struct dsu{
		int fa[maxL+1],successful_merge_times;
		dsu(){clear();}
		void clear(){memset(fa,-1,sizeof(fa));successful_merge_times=0;}
		int findfa(int pos){
			while(fa[pos]>0&&fa[fa[pos]]>0){fa[pos]=fa[fa[pos]];pos=fa[pos];}
			return fa[pos]<0?pos:fa[pos];
		}
		bool merge(int a,int b){
			int afa=findfa(a),bfa=findfa(b);
			if(afa!=bfa){
				successful_merge_times++;
				if(fa[afa]<fa[bfa]){fa[afa]+=fa[bfa];fa[bfa]=afa;
				}else{fa[bfa]+=fa[afa];fa[afa]=bfa;}return true;
			}
			return false;
		}
		bool same(int a,int b){return findfa(a)==findfa(b);}
		int mergenum(){return successful_merge_times;}
	};
	template<typename typ,size_t Vcnt,size_t Ecnt>
	struct MinCostMaxFlow{
	

	

		struct edge{
			int to,nxt;typ cap,cst;edge(){}
			edge(int nto,int nnxt,typ ncap,typ ncst){to=nto;nxt=nnxt;cap=ncap;cst=ncst;}
		}Es[Ecnt];int idx=1;
		int lst[Vcnt];
	
		int dis[Vcnt];
		bool inq[Vcnt];
		int cur[Vcnt];
		queue<int> qq;
	
		
		void clear(){memset( Es,0x00,sizeof( Es));idx=1;memset(lst,0x00,sizeof(lst));}
		void addE(int fr,int to,typ cap,typ cst){
			Es[++idx]=edge{to,lst[fr],cap, cst};lst[fr]=idx;
			Es[++idx]=edge{fr,lst[to],  0,-cst};lst[to]=idx;
		}
		bool spfa(int nS,int nT){
			memset(dis,0x3f,sizeof(dis));
			memset(inq,0x00,sizeof(inq));
			while(!qq.empty()){qq.pop();}
			qq.push(nS);dis[nS]=0;inq[nS]=true;
			while(!qq.empty()){
				int nw=qq.front();qq.pop();inq[nw]=false;
				for(int i=lst[nw];i;i=Es[i].nxt){
					int to=Es[i].to;
					if(Es[i].cap>0&&dis[to]>dis[nw]+Es[i].cst){
						dis[to]=dis[nw]+Es[i].cst;
						if(!inq[to]){qq.push(to);inq[to]=true;}
					}
				}
			}
			return dis[nT]!=0x3f3f3f3f;
		}
		typ dfs(int nw,typ flow,int nT){
			if(nw==nT){return flow;}inq[nw]=1;typ cntf=0;
			for(int& i=cur[nw];i;i=Es[i].nxt){
				int to=Es[i].to;
				if(Es[i].cap>0&&dis[to]==dis[nw]+Es[i].cst&&!inq[to]){
					typ tmp=dfs(to,min(flow-cntf,Es[i].cap),nT);
					cntf+=tmp;Es[i].cap-=tmp;Es[i^1].cap+=tmp;
					if(cntf==flow){break;}
				}
			}
			inq[nw]=0;return cntf;
		}
	
		array<typ,2> dinic(int nS,int nT){
			array<typ,2> ret{0,0};
			while(spfa(nS,nT)){
				memcpy(cur,lst,sizeof(cur));typ flow=dfs(nS,10000000,nT);
				ret[0]+=flow;ret[1]+=flow*dis[nT];
			}
			return ret;
		}
	};
	
	template<typename typ,size_t Vcnt,size_t Ecnt>
	struct MaxFlow{
	

	

		struct edge{
			int to,nxt;typ cap;edge(){}
			edge(int nto,int nnxt,typ ncap){to=nto;nxt=nnxt;cap=ncap;}
		}Es[Ecnt];int idx=1;
		int lst[Vcnt];
	
		int dis[Vcnt];
		int cur[Vcnt];
		queue<int> qq;
	
		
		void clear(){memset( Es,0x00,sizeof( Es));idx=1;memset(lst,0x00,sizeof(lst));}
		void addE(int fr,int to,typ cap){
			Es[++idx]=edge{to,lst[fr],cap};lst[fr]=idx;
			Es[++idx]=edge{fr,lst[to],  0};lst[to]=idx;
		}
		bool bfs(int nS,int nT){
			memset(dis,0x00,sizeof(dis));
			while(!qq.empty()){qq.pop();}
			qq.push(nS);dis[nS]=1;
			while(!qq.empty()){
				int nw=qq.front();qq.pop();
				for(int i=lst[nw];i;i=Es[i].nxt){
					int to=Es[i].to;
					if(!dis[to]&&Es[i].cap>0){
						dis[to]=dis[nw]+1;if(to==nT){return true;}qq.push(to);
					}
				}
			}
			return dis[nT];
		}
		typ dfs(int nw,typ flow,int nT){
			if(nw==nT){return flow;}typ cntf=0;
			for(int& i=cur[nw];i;i=Es[i].nxt){
				int to=Es[i].to;
				if(Es[i].cap>0&&dis[to]==dis[nw]+1){
					typ tmp=dfs(to,min(flow-cntf,Es[i].cap),nT);
					cntf+=tmp;Es[i].cap-=tmp;Es[i^1].cap+=tmp;
					if(cntf==flow){break;}
				}
			}
			return cntf;
		}
	
		typ dinic(int nS,int nT){
			typ ret=0;
			while(bfs(nS,nT)){
				memcpy(cur,lst,sizeof(cur));
				typ flow=dfs(nS,10000000,nT);ret+=flow;
			}
			return ret;
		}
	};

	using poly=vector<ll>;
	namespace polynomial{
		const ll mod=998244353;
	
		ll inv(ll b,ll pw=mod-2){
			static ll mem[1000000];
			if(b<=1000000&&pw==mod-2&&mem[b]){return mem[b];}ll rt=1;
			for(;pw>0;pw>>=1){if(pw&1){(rt*=b)%=mod;}(b*=b)%=mod;}
			if(b<=1000000&&pw==mod-2){mem[b]=rt;}
			return rt;
		}
		int upto2pow(ll val){
			return __lg(val*2-1);
		}
	
	
		const ll G=3,invG=inv(G);
	
	
		poly make_poly(function<ll(int)> func,int n){poly f(n);for(int i=0;i<n;i++)f[i]=func(i);return f;}
	
	
		poly& iCut(poly& f,int n){f.resize(n);return f;}
		poly Cut(poly f,int n){return iCut(f,n);}
	
	
		poly& iNTT(poly& f,bool sgn){
			static vector<int> rev{0};
			int n=1<<upto2pow(f.size());
			f.resize(n);rev.resize(n);rev[0]=0;
			for(int i=0;i<n;i++){
				rev[i]=(rev[i>>1]>>1)|(i&1)*(n>>1);
				if(i<rev[i]){swap(f[i],f[rev[i]]);}
			}
			for(int tmp=1;tmp<n;tmp<<=1){
				ll w1=inv(sgn?invG:G,(mod-1)/(tmp<<1));
				for(int l=0;l<n;l+=tmp<<1){
					ll w=1;
					for(int pos=0;pos<tmp;pos++){
						ll x=f[l+pos],y=f[l+pos+tmp]*w%mod;
						f[l+pos]=(x+y)%mod;f[l+pos+tmp]=(x-y+mod)%mod;
						(w*=w1)%=mod;
					}
				}
			}
			if(sgn){
				ll invl=inv(n);
				for(auto& it:f){(it*=invl)%=mod;}
			}
			return f;
		}poly NTT(poly f,bool sgn){return iNTT(f,sgn);}
	
	
		poly& iMul(poly& f,poly g){ 

			int n=f.size()+g.size()-1;
			f.resize(n);g.resize(n);
			iNTT(f,0);iNTT(g,0);
			for(int i=0;i<(int)f.size();i++){(f[i]*=g[i])%=mod;}
			iNTT(f,1);

			return f;
		}poly Mul(poly f,poly g){return iMul(f,forward<poly>(g));}
	
	
		poly& iInv(poly& f){
			int tlen=f.size(),len=1<<upto2pow(tlen);
			poly g{inv(f[0])};f.resize(len);
			for(int tmp=2;tmp<=len;tmp<<=1){
				poly tf(tmp<<1,0);for(int i=0;i<tmp;i++)tf[i]=f[i];
				g.resize(tmp<<1);iNTT(tf,0);iNTT(g,0);
				for(int i=0;i<tmp<<1;i++)(g[i]=g[i]*(mod+2-tf[i]*g[i]%mod))%=mod;
				iNTT(g,1);g.resize(tmp);
			}
			g.resize(tlen);swap(g,f);
			return f;
		}poly Inv(poly f){return iInv(f);}
	
	
		poly& iDer(poly& f){ 

			for(int i=1;i<(int)f.size();i++){f[i-1]=f[i]*i%mod;}
			f.pop_back();return f;
		}poly Der(poly f){return iDer(f);}
	
	
		poly& iInt(poly& f){ 

			f.emplace_back(0);
			for(int i=f.size();i>=1;i--){f[i]=f[i-1]*inv(i)%mod;}
			f[0]=0;return f;
		}poly Int(poly f){return iInt(f);}
	
	
		poly& iLn(poly& f){
			static poly ivf;ivf=Inv(f);
			return iCut(iInt(iMul(iDer(f),ivf)),f.size());
		

		}poly Ln(poly f){return iLn(f);}
	
	
		poly& iExp(poly& f){
			int tlen=f.size(),len=1<<upto2pow(tlen);
			poly g{1};f.resize(len);
			for(int tmp=2;tmp<=len;tmp<<=1){
				g.resize(tmp);
				poly tf(tmp<<1,0),lng=Ln(g);
				for(int i=0;i<tmp;i++)tf[i]=f[i];
				g.resize(tmp<<1);lng.resize(tmp<<1);
				iNTT(tf,0);iNTT(g,0);iNTT(lng,0);
				for(int i=0;i<tmp<<1;i++)(g[i]=g[i]*(mod+1-lng[i]+tf[i]))%=mod;
				iNTT(g,1);g.resize(tmp);
			}
			g.resize(tlen);swap(g,f);
			return f;
		}poly Exp(poly f){return iExp(f);}
	}

}


vector<int> Es[100005];
ll deg[100005];
pr val[100005];
bool vis[100005];
pr tot;

set<pr> tp,mp;
void dfs(int nw,pr fr){
	val[nw]=pr{tot[0]-deg[nw]*fr[0],tot[1]-deg[nw]*fr[1]};
	vis[nw]=1;
	for(auto it:Es[nw]){
		if(!vis[it]){
			dfs(it,pr{(deg[nw]-1)*fr[0]+val[nw][0],
				   (deg[nw]-1)*fr[1]+val[nw][1]});
		}
	}
}
struct de1ete{de1ete(){
	int n=qread();
	rep(i,1,n){
		Es[i].clear();
		deg[i]=0;
		val[i]=pr{0,0};
		vis[i]=false;
	}
	rep(i,2,n){
		int fr=qread(),to=qread();
		Es[fr].emplace_back(to);deg[fr]++;
		Es[to].emplace_back(fr);deg[to]++;
	}
	int nlf=-1,nb=-1;
	rep(i,1,n){if(deg[i]==1){nlf=i;break;}}
	nb=Es[nlf][0];


	val[nb]=pr{0,1};
	vis[nb]=1;
	for(auto it:Es[nb]){
		if(deg[it]==1){
			val[it]=pr{1,0};
			vis[it]=1;
		}
	}
	tot=pr{deg[nb],1};
	dfs(nb,pr{1,0});
	tp.clear();
	rep(i,1,n){
	

		if(!val[i][0]||!val[i][1])continue;
		ll tmp=__gcd(llabs(val[i][0]),llabs(val[i][1]));
		tp.insert(pr{val[i][0]/tmp,val[i][1]/tmp});
		mp.insert(val[i]);
	}
	for(int i=1;;i++){
		pr rd=pr{1,-deg[nb]};
	

	

	

	

	

	

	

		for(int i=1;i<=n;i++){
			printf("%lld ",rd[0]*val[i][0]+rd[1]*val[i][1]);
		}
		puts("");
		return;
		JILE:;
	}


}};



int run=[](int exec_times)->int{
	delete[](new de1ete[exec_times]);
	return 0;


}(qread());

int main(){}
string Neri=R"(||  300ch*98ch -> 2100px*1176px  ||  Software: ASCgen  ||  Read Caelum Sky & See This Adorable Neri !  ||  Author: ALRadeck  ||
7vvvvLvvvL7rirrrrrrrrrrvri:i::i7YLvEPPKPKPXdEDZPXgEbbRBBMPPPSd1. iii...r:. ..:ii:ii. ::i:  Ru :r..EDQv .ir:. 1b5PQ:  uRqI525IgK. :Pq5PPX25UIU52IUIU5USdd:.vDP:  JP .BKIS  q5u15Y 7X1uujKu7LjsJvYv7vUuu7vvYvLvLv7KBMgEZSSKPqqXSLrrLvYvsi::i:iii:i:::::i:i:::i:i:::::::::::::::i:i:i:::::::i:::i:::::::i:::::i
LvvvvvLvLvYvvrrirr7rrr7i::::i:rL7vRZPXPqPKKKgdgqPgggRBgrivsqDPggi i:i:..ri:...iii:i:.:rii  Pv ii: KBi .iii: .KbSEi... vgP5jYPE. ..qddJYSX252I2I2525UIKq  .LgY rBZbi :5IK2.121uUSKU2jUJ1J1r:.:iYj2uJjUUJ7LvYvYvLrUZgQMEDPPKPPdbgX7rvvvvjj1u5L::v7vsjJ1u1uU11u112U212uUu1u1u1jU11u1u1u1j11U1U11uUu1uUuUj1u1uUu
vvvv7L7Lvv7LLs7rirrrr7i:::::::::..DMPPqPqPXPZDZdKQQBQr   .  :rXBQ .iiii..rrr:..iiii: .iii. K..ii: vs ..i:i: .bXgJ .... :EE2SS: 7: qgi  .P5252I25U5UIUdv iBPKD  SdXPr uI25P21uUj2U2uUu1JjKQ5vr. r12UUu2UJ7YvLvLvvrrivdgEgPKqPKPPDbYrrrvvLvYLL.rDSuP5sLYLYLLvYvLvLvLLYvLvYvYvLvYvLvLvYLYvYLYvYvYvLvYvYvYvLvLvL
LvLvvvLvvvvvLvYLvirrrrrii:i:ri:::.iQDKPKPqqKgEgERi.Sg2  .ii.   :BP :i:r:.::.....iii:.:iii....iii:.. ..:iii: :EEd. ....:..SMEd .r:.gr   7EII252IUI2IU5Sg. vb2d5.vP5ISqUUuU1UjUu1jUuUuUuUY2gBBQQv 7JJu2U5svvLvLvLvL7rvEDZZbXPKPKPKZZP1Lrrrv7LYYvPgZPgirsYvLvvvYvYvYvYvLvLvYvLvLvLvYvvvLvLvLvYvYvLvYvLvLvvvLvYv
vvvvvL7L7vvv7vvLYLrrrrr77777r777:: 7MbKPKPSqEDgQX   iQg: .:ri:. .X:.iri:.....:...rii.:ii....:i:i:.....:i:r: :Rg: r.....i. 7Rg .r:.s... EXIUI252I2I2525KR: PXIPEP25I2J1jUuUu1u1j1jUu1jU1ILrPgEgB::XLvvjJY7LvYvLvYv7JBRgZgbdPPKKXqKbdgZP2j7r7vvLrr:iXL 7sLvLvLvLvLvYvLvLvLvLvLvLvLvYvLvLvLvYLYvLvYvLvLvLvYvLvY
vvv7vvv7v7L7LvvvLvLrrrrrrrrrrr77vr::gbPKPXKbDZQZ.:i. .qr .:iiii.  :.r:....:::::..ii..ii.:r..i:ii:.....iiii. JBY :r:....:r:  . .i:...r rDS2I255SSKSqKPqdbQgbXKXXS5ISIIJuJ1j1j1J1uUuUj1jULrKRbvqQi:qIus7v7vvYvLvLvL7vDBRQRQqqbPqPqqXKXPdDZDPL7YvLvYvJr r1vLvLvYvLvYvLvYvYvLvYvLvLvYvYvLvLvjL77L7LvYvLvYvLvLvLv
vv7v7vvvvL7vvL7vvLvsrrrrrrrrrrrrr7r:PgqPXPEgEZDL :ir:. ..:ii:iii.......:::::.::..::.:r..r:.iiiii..:..:iiii..PR  ir......ir:. .:ri..i:.SZSKqdEEdEPPS5U2U2u2SqPEPZdEPqXSI2J1Jju1J1uuj1UjrrrBQKrEgq.IUI2U7v7vvLvYvLvL777v7LviUBQQggEZPPKqKPPQS7vYvLvLsv:vYYvYvLvLvLvLvLvLvYvLvLvLvLvYvLvLvJi:rrrrr7vJsYvYvLvLvL
v7v7L7v7v7v7v7vvLvLvsvrirrrr7rrrrrr:vgdKqDMEDbQ:  i:ii:...r:i:iir:....:::::::::.....r:.ir.:ii:i:.i:..:i:r...::..ii.......:ri:.:i:.iii:gQDqSY7::....        .....i7UXEZdKXIS2S2II2JuJ1u1vuQQXJbdRsiIvJY7YJvvvYvLvYvv7777r7rruPPRQMZgDDqKKPgXrLvLvLvLL1LYvYvYvLvLvLvYvLvLvYvLvLvLvLvLvLvYs::BBBQPu7:7jJvLvLvYv
vv7vvvvLvv7vvv7L7L7L7sv7rrrrrrrrrrr:igPPKZZgZgRBu :i:ii. .ii:ii:...:::.:iiiiiiii:..ii.:r:.:i:ii..r:..:ii:....:..ii....:r..:ri..iiii.:..:...........:.:::.:......    .isPbZqEdEPPKX1Uj1juJPMQRg1:rvU1v7LIU2vvvLvLvLvLvvvvvL7riirXEDDZEgbPEd77vLvYvLvYvYvLvLvLvLvLvLvYvYvLvYvYvYvLvLvLvLvsLriiYbMBQr iuJvLvLvY
L7L7vvL7Lvv7vvvvv7vvv7LvYvrirrrrrrr:iDZPqXPKdEgQB:.:i:i:..iir:. ..::::iiiii:i:iir:.i:.iii.::ii: :ri...ii........r:.::.iii...r:..i::::..  .:.:.::iiriiiiiiiiiiiiii:::..  .rPsii1SPddXSUIuJvj2dgMJ1U112su12YvvLvLvLvLvYv1jv7vvs7riXddDgDgKUr7vLvYvLvLvYvLvLvYvLvLvYvYvLvLvYvLYsLYvYvYvLvLvYJv.  .rBQ. rJsvLvYv
vvvvvvvL7Lvv7L7vvv7v7vvLvYvrrrrrrrrr SQZPPKKIqZQB:.i:i:r:.:r.. ..::::rii:i:i:i:ii:.i:.ii:..i:i:.iii: .ii.....ii:i. :i..iir:..........:.:.:.......::iiiii:iiiiiiiiiiiiii:.... . ...1gdZqK21sYvJJuju11jJJ2UL7vvYvLvLvLvLv11Y7vjUL7rPPZMgQji7vLvYvLvLvYvYvYvLvLvLvLvLvLvLvLvLLL7uusvYvLvLvLvYYJ7i  LBu .rsYvLvL
L7v7L7v7vvLvL7vvvvvvL7vvvvYrrr7rrr77. bBMbdqqXgQB.::::ii:.:....::.:ii:i:::::i:iir:....ii: :iii:.iii..:ri:....iii: .ir:.:i.....::::i:iiiiiii:i::..  .::iiiiiiiiiii:i:i:iiii:.iii.  ..:7XZZI1J1juju1gUuv11UvvvYvLvLvLvLvL7j2u7vL2u7rYJgQBIrvLvLvLvLvLvLvLvYvLvLvYvLvYvLvLvLvu: .:7JvLvYvLvLvYYuU7. SB:.vjvYvYv
vv7Lvvvvvv7LvLvv7vvvvvvv7LvLirrrrrrv:  vPggEXDMBL.:i:i:r:....::::iii:iiiiii::iiiii:. .iri.:i:i:.:ii: :ir..::.:ii:.iiir.....::iiiiiiiiiiiiiiiiri:7Zv. ...:iiiiiiiii:i:i:i:i.:ii:.:rri:  .vdbIuUu1s1DqJUuU1L7LvLvLvYvLvLvL7Y1U777JUsrrLXUs7YvLvLvLvLvYvYvLvLvLvLvLvLvLvYvLvYLLrr:7YLvLvLvYvYvYvYJ1:.qd.1YYvLvY
Yvv7LvLvL7Lvvvv7v7L7LvvvLvvL7irrrr77:   ::.XBQBE.:::iii:....::::ii::riiirr7ri:i:i:rri .ir.:ii:i.iiii..ri..7i..ri:.r::...::irriiiiiiiiii:i:i:i::r:vBBu...:..:iiiiiii:i:iii:::i:.ij7vr7v:   vbP1UuUJUJ1j1j2LvvYvLvLvYvLvLvL7vJIsv7Y127rr77LvLvLvLvLvLvYvLvLvLvLvLvYvYvLvLvLvYYujuLLvYvLvLvLvLvLvYJu:..:LjvLvYv
vL7vvvvvvL7vvv7L7L7vvv7v7vvsvrrrrrrv:...:..QBBI .i:iii...:.::::i:::riiii:iirii:i:i:ii: .:..iiii.iiir..ri.:....:r:.....:irriiiiiiiiiiiiiiiiiii: dRr.vBBv  .::..:::::i:i:iii.:::.v77i:7sJ1v:  7dXUu1juJUj11J7YvLvLvLvYvLvYvL7vv21L7vs2us7LvLvYvYvLvYvLvLvLvYvLvLvYvLvLvYvLvLvYvYvYvYvLvLvLvYvLvYvYYuL:.7jYvLvL
L7v7vvvvvvvvvvvvvvLvv7L7v7vvY77rrr77: .:i::.... .:iii...:::.:ii::iv7riiirrriiii:i:i:ii:......::.iiir:.i..   :.::....ir7riiiiiiiiiiiiiiiiiiiii.iDMgg7:KBgY..::..:i:i:i:i:iii:i..77ri7Yvv7sjji..jPIj1u1j1uUjvvLvv7LvYvYvYvLvLvv7J21v77J1UYLvLvLvLvLvLvLvLvLvLvLvLvLvLvLvLvYvYvLvLvYvLvLvLvLvYvLvYvLLU7.:UvLvLv
7v7vvvvv7v7vvv7v7vvv7v7vvL7LJr:Lr7rv. .iii::  ii:ii:...:::.:ii::r7iir7rr:irririi:i:i:iir:..:......:i:.     .i....iirrriiiiiriiiiiiii:iiiiirr 7BMPPPRP.7BBBi.::::.iiiii:i:i:i:..v7rrY777v7LvJJi :XquUj1uU1j7v7vLsvLvLvLvLvYvLvL7LYIJY7vLJvYvLvYvLvLvYLsLYvYvLvYvYvLvLvLvLvLvYvLvLvLvLvLvYvLvLvYvLvYJr..7uvYvY
v7vvvvLvLvLvv7L7vvL7L7vvv7vvU: :s777. .ii:ii. iiii: .:::::iii:ir7rii:irrrri:7ri:i:i:i:iii:irri:...:.      .::..:iiririririiiiiiiiiiirrrr777.rQggRZEqRS iBQR.:::::.::iii:i:.:i..rvr7vsvirv7v7LYJ:.ub1Uj1j2j7vYu51v7YvYvYvLvLvYvvvv7JYvvLvLvLvLvLvYvLYJ7rvsvLvLvYvYvYvLvYvLvYvYvLvYvYvLvLvLvLvYvYvLvs7i:vYLvYv
vvvLvLvv7Lvv7v7vvv7v7Lvvvv7L1:  .vvv...r:i:i:iri.. .:::::iii::r7:ijMu:irir7rir:i:i:i:::::i::::::iv:     .i::.::::iiriiiiiiiiii:ii77777r777.7BJ 7jqgMdQv rBB7.ii:.:..:iiiii.:i:.:Lri7SBsirv7vvvvjr rZ11j111Y1u21sLLvLvLvLvLvLvLvYvL7LvYvLvLvLvLvLvYLJ.:1::77vvLvLvLvYvYvYvYvLvLvLvLvYvLvLvLvLvLvYvLvJsuLLvYvL
L7L7vvvvvvvvLvvvLvv7L7L7L7vv2..i..Li...ii:iii::...::::::iii:ir7i7dQRdiiirr7v7:::::::iirr7iii77rii      :i.::::iiriiiiiriiiiiiirr777r7r7r77:i5..::.:JQEB..BBg:.iii:::.:iiii:.i::.7v::sBBKri77v7v7Jv iE11uUuuu1uU1SLvvLvLvLvLvYvLvLvLvYvYvLvYvYvLvLvJv .BR1LvvvrvsjLLvYvLvLvYvLvLvLvLvLvYvLvLvYvLvYvYvLLLvYvLv
vvvvvv7vvL7vvLvv7LvvvvvL7vvYu. ri ...:.:iiii.....:::.:ii:i:ir7ivEgPZXir7r777:ir7iiir7v7v71Us:        .ri::iiiiiriiiririiiiirr777r7r7rrrrr77r:iivr7i.7MM2:QgBD::iir::...iiii:::.:.ri::PBBR1ir7v7v7YL iD11j1j1uUuIJvvLvLvLvLvLvLvLvYvLvLvLvLvLvYvYvLvuv.:BBBdL2d:.iYjsLYvLvLvLvYvLvLvLvLvYvYvLvLvLvLvLvLvLvLvL
L7LvL7vvv7vvvvvvv7vvLvLvvvLJ1 .ir...:i..ii:...:::::.:iiii::rvriKgPPdPirr77r:i77777v777vuui            :::rririiiiiriiiiiiir77rrr7rrr7rrr7rrr777r7rv.:gZEugQBg.::iiii:...iiiiii:.::i:.iBQQBPir7v7v7JL iDU1uuJUu2svvLvLvLvLvLvL7LvYvYvLvLvLvLvLvYvLvYvuJ..jUriZBQs: :YuLYvLvLvYvLvYvLvLvYvLvLvYvLvYvLvLvLvYvLv
vvvLvv7vvvvLvv7L7L7vvvvv7vv1i .ii: .:r::ri .:i:::::::i:i:irvrriPEbqg2ir77r:i77r7r7r77uJi       v.      :rririiiiiriiiir7r777rrr7rrrrrrr7r7r7rrrrr77.iQDXPBZIri:::iiiii:..iiiiii:.::i:.7BRMQDri7v7v7sL rg1U1UuI1v7YvYvLvLvYvvv1svvLvYvYvLvLvYvYvLvLvLvJLi..:rLBBBBd: iUYYvLvLvYvLvLvLvYvYvLvLvYvYvLvLvLvLvYvL
L7v7vvvvvvvvLvLvv7Lvvvv7v7sU. :ii. .iiii: .:i:::::::iii::r7r7riuQdDgLirrri777r7rrr7Y1:      i2BB5      :viiiiiiiriiiir7r7r7r7rrr7rrr7rrr7rrr7rrr77r vBQ.DQ7.i7vri:i:iii:..:ii:ii:.::i:.JBMgQQrirvvv7YY rg1uj22s7LvLvLvLvYvvs5jYvLvYvLvLvLvLvYvLvLvLvYvYJusJv7r1dBBBj .usLvLvYvLvYvYvLvYvLvYvLvLvLvLvLvLvLvYv
vv7vvLvvvL7Lvv7L7v7v7vvvvLYY .iii: :ir:. :i::::::::rii::r7r7rrii1ggPir7ii7r7r7r7rvu7     iKBQQEB1      Lriiiiiirii:ir7r7rrr7rrr7rrrrr7rrr7rrr7r7r7r.uQr :rirr7r77r:::iiri:.:iiiii:.:ii:.JBgDMB1irv7v7sv sD7vYJ7LvYvLvLvL7v1Ss77LvYvYvLvYvLvYvLvYvLvYvLvYLYvYv7i:.gBBD..jYYvLvYvYvLvLvLvLvL7LvYvYvYvLvLvYvLvL
v7LvvvLvLvLvv7L7LvsLLvv7Lv2i :r:i:.:7: .ii:::::::.iii::r7rrr7r7iir7irrii7r7r7r77jY.   .UBBMPPKZB:     :vriiiiiiiirrr7rrr7r7r7r7rrr7r7r7rrr7rrrrrrr7i:..:rrrr7r7r77vi::i:ii:.:iiiii:.:ii:.vBggDBPiiv7v7J7 U5rv7LvLvLvYvL7v25v771YLvYvYvLvYvYvLvLvLvYvYvLvLvYvLvsL7:i7BQ .2LLvYvYvYvLvLvYvLv2uJLLvLvYvLvLvYvLv
vvvv7vvvvL7v7v7vvs7vJLvLvsU. iiii:.::..ri:::::::.:ii::r7rrr7rrrririrrii7r7r7rvL1r   .PBQbPKqXPBu      vriiiiirirr777rrrrr7rrrrr7rrrrr7rrrrrrr7rrrrr7r777r7r7rrr7r7rv7i:i:iii:.:iiiii..:i:.JBgDZBg7:77v7ui Pj7LvLvYvYvv7Y2277sIJYvLvLvLvYvLvLvLvLvYvLvYvLvYvYvYvLYL: :BR.ruvYvYvLvLvLvLvJL7br 7JYvLvLvLvLvLvL
v7vvL7Lvv7v7Lvv7sY..JjY7YUr :ii:i:....ir::::::::::i::i7rrrrrrr7rrr7rii7rrr7rvvr    2BRdXqSqSqDR      r7iiii:r77r7r7r7r7r7r7r7rrr7r7rrr7r7r777r777r7rr77rrr7r7rrr7r7rvr:ir:i:i:.:iiiii:.:i: JBMDEQQUiirv71.:PvvYvLvLvv7J5U77J5LvvYvLvLvLvLvLvYvLvYvYvLvLvLvLvYvLvLLuJ..QY.uLvLvLvYvYvLvJs.:R5:rJ7LvYvLvLvYvLv
vvvvvv7LvLvvvL7vLu. .vuLuL  .r:iii...ri::::::::::i::i7r7r7r7r7r7r7rir7r7r77v7:   rBBPqXKXKSPEB:     iLiiii:rr7r7r7r7r7r7r7rrrrr7r7r7r7r777rrrrirr7r7rrrrr7r7rrr7rrr7r7:rvi:i:i:.:iiiii:..i: 7BQDEMBMJirvvj sjvvYvLvv7J5177uIvvvLvLvLvLvLvLvLvLvLvYvLvYvYvLvLvYvLvYvJji...JLYvYvYvLvYvYu: qBM7r:7YLvLvLvLvLvY
LvLvvvv7LvvvvvvvL2i  .YUI. ...rii...i::::::::::.iiii7r7r7r7rrrrr7iir7r7r7777.   EBZqqXKXqSPdBr     .Yiiiirrr7r7r7r7rrr7r7r7r7r7rrrrr7r7rr:::iii:ir7r7r7r7rrrrr7r7r7r77:iL:rii:i:::iiiii::.i: iBQgEDQBqri7Ji.gvLvLvL7JIurvjU7vvYvYvLvLvYvYvLvLvLvYvYvLvLvLvLvYvYvLvLvYJsi7sLvLvLvYvLvLYY UBb..:sYLvYLLLssjJjs
vvvLvv7LvL7vvL7v72r ...P7 .r:..i..:i::::::::::.:ii:r77rrrrr7r7r7iir7r7rv77r.  .BRPXKSKSKXqEBi     .Yiii7r7r7rrrrr7r7r7r7r7r7r7rrr7r7rrr7rrr7rrrrirr7r7r7r7r7rrr7r7r7r7ii7ii7:i:i:.:iii:ii::ii .BQgUSQB2rrvJ 7R7vvLvLJj7vuU7vvYvLvYvLvLvYvYvLvLvLvLvLvLvLvYvLvLvLvLvYvJv7JsvYvYvLvYvYLjr:UY..v1LYvssuJL7rii:i
L7v7L7L7v7Lvv7vvLJv .: r: :ir:. ..i::::::::::::ii:r77rrr7rrr7r7ii77r777rir   .BgPXqXKXqXPMBi     .Liir7r7r7r7r7r7r7r7r77rrrrrr7r7r7r7r7rriiiiirr7rv7v7777r7r7r7rrr7r7riir:rri:i:i:.:iii:iii:i: .BBM2jgBUrrur qDrvvYvv7vLs7vvYvLvYvLvYvYvLvLvLvLvLvYvLvLvYvLvLvLvYJJvYY7.LLYvLvLvLvYL7rsJi.7uJvYvusr.....::::
vLvv7vvv7LvvvL7vvjY .r....iii:...:::::::::::::.i:r77rrr7rrr7r7ir77r77r:ir.  .BDqXKXKXqXbBZ      .Lirr777r7r7r7rrr7rrr7ii::iii777rrr77r::i77v7v7v7rrrirr77777r7r7rrr7r7:rri:i:i:iii:.:iii:iii::i .BBQKvqB5rvj  BS7LvLvLvvvvvLvLvLvYvYvLvLvLvYvLvLvLvYvLvLvLvLvYvsv::Yss7rYYvYvLvYvsvrrj7LYussvYLsi..rIgdQQQRQ
L7vvvvv7v7v7v7vvLsj .r:...ir:..::::::::::::::.:i:i7r7r7rrrr7r:r77r77i:i7   .BDqSKXKSKKEBu      .Yi7vv77r777r7rrrrr7r7i::iirrri777r7ri:i7Lri::.:...::::i:iir77r777r7r7r:rr:r:i:iiiii:..iii:i:i:::  BBQgU2QI7Y  .DUvYvYvYvLvYvYvLvLvLvYvLvYvLvLvYvLvLvYvsLLvYvYvYJiiU.rJsYYvLvLvLvs7r7U7vvYvYvLvYiiUQBMi1ZEbZP
vv7v7v7v7vvL7vvLvuv .r:.:..:..:::i::.:::::::.:ii:r77r7r7rrrr:7r77vri:i7:   BgPKKSKSqXgBv      .Li77riirri7r777r7rrr7ri:i::.:iii777rr:r7vr:..         ..::::iiriir7777r:7i:7r:iii:iir:..iii:iii:i: .BBgQDUQdj.   gsvLvLvLvYvYvLvYvLvLvYvLvYvYvLvLvYvLvYvYvvvLvYvu:YBg.isYvYvLvYLsrr12rvvYvYvYvsrSQQMQdUQq.PEv
v7LvLvvvvvvvLvJuj2v .ii.i:..::::i:r:::::::::::i::r7r7rrrrrri7r777i::iri   SBPKKXKXqXQQ.      .vr77r:  :irir77r7r7r7rvi:i. .  .iir77i:7L7i ..:rj1U7i.    ...:iii:::r7vr77iiv:iiiii:iir:..iiiii:i::i  BBdb7rgBU . igvvLvLvLvLvLvLvYvLvssuuuLYvLvLvLvLvLvLvYvLvYvYLL.iBg LYLvLvsv7:ruurvvYvYvvvs7:qB5j7iii.7ZdK
vv7vvvvLvv7Lvuv.rP: .ri..:::.:ii:r7iii::::::.::::irrrrrrrrr7r7r7:::ir7   rBEqqSqSKqQR       .vr7r7ir.  ..ii:rrr7r7r77r:i..ri.. :i7vr:vri..L5J5QBQBBBBE7:   ..::iii:ir777:7r::i:iii:i:r:..iii:iii.:: .BB55L:XB: . g5vvLvLvYvLvLvLvLvs7ii:r1LLvLvLvLvLvYvLvYLLvLvYLu:r5.7LvLvYvr:jbIrvvv7Lvr7sJ:iB7 7U75qggbPP
Lvv7L7v7vvLLuj: :r ..ir..::.:7v777v7r::::::.::::rvr:rrrrrr7r7r7i::iiv   .QgKXXKXqKBQ        v77r77rir.... .::iri777r7r:i:.riri: .:7riri: :Ks7YBgDZgDQBBBBU.  ...:ii::i7ri7r:iii:i:i:i:r:..iiiiiii.::  BQP2j:jP .  BYLvLvLvYvLvLvYvLLY:.:.i1vYvLvYvYvYvLvYvLvYvYvYvU: :bsvvYr:rgR27L777PsivsvYr7vqEBBgSQRMbbP
vv7Lvv7L7LYY17....:..i.:::.:7vr7777r::::::.:::7PDMP7:rr7r7r7r7ri:iiv.  .BMXKXKXqPBP        rvvr7r7iiir......:::rir77rvii:.:riirr. .riii: iIYrsQgdZdZEDZMQBBj  ....:ri::i7v:i:iii:ii:ii:r:.::ii:iii.::  BQDjI7v  : .qvLvLvLvLvLvYvYvYY2i:.:JYvLvYvsvriiirrr7vvLvLvLYYi7DQrLi:5BPrrvrrdBJrvsvsvJvvJ12MBu.r:rXL
Lvvvv7vvLYu.:i.i.:7...:::.i77r7r777:i::::..:rUMZdgBB7i7r7rrr7rii::rr   QRKKXqKqDBJ        iLvr7r7riiiir.......::riir7r7ii..iii:r7. .irr: :IY77BgDEZdZEZEDZQBBv  .:..iii:iiiiiii:ii::ii::r..::ii:iii:.:  bBBPZS  :i .ULLvYvLvYvLvLvLvYLIi r1vYvYvYvirJUKSbU7irrvvLvYvsrPB7.rQBviJ7iYgQviYJsuvvLL777Mg..7uIqdP
vv7v7LvvvUr ...irr:..:::.i77r7r7r7ii:::::..7ggbDM5KBvir7rrr7rii::i7.  PBqqXqXbBR:        vsvr7r7r7riiiir:......::iiirrr7ii.:ri .:7:. :rr. sUvr1BgZEZdZdZdZEgQBQr  .:.:ii:i:iii:iii:i:i:.ir...:iiiiii:::  XBBgQb  iILuYvLvLvLvLvYvLvYvLji.JsYvYvLLrYBQjYqPMgq1vr7vvvLrqBX.jBZiLUUIPgqI2uYvLiivsvvrPQ.YQgDbbbS
Lvvvvvv7Y1.....ri...::..rv7r7rrrvr:i:::...LZDqDDB7.7ir7r7r77r:i:irr  iBPqSqqgBS         7L7r7r7r7r7ii:iiri......::iiirririi.:r: .:7:. .rr :SJvrUBgDdDEZEZdZEDDBBZ:  :..irii:i:i:i:i::ii::ir..:::r:iiri::. 7EgdBBR: :q1svYvLvYvYvLvLvLvsLJYYvYvLvYi7DD7QBP1QQQRb77vYvi1U.ZBsiSQQb21ZBg7ri:.rLJLYv7BrrBPPPPbMU
vv7vvLvvuv :...:..:::.:777r7r7r7ri:i:::. vQDXdZMQB5ir7r7r77i:iiiiv.  PRKXqdBQ.        :L77r7irr7r77rii:iiri:......:iir:iiiii.:r. .i7i. .ri iIu7rsQQgEDdEdZdZEZEgBBX. ...:i:iii:i:i::i:::.:i:..:::i:i:i:::.  JQ::MBZ  j1LvLvYvLvLvYvLvYvsLLvYvYvYLvrivXuPQY5QgQQqrvrs2::Bgi7QQg2sbBPY:ii..vL7YuJuLR:.bgqPPP2D
L7v7v7vv2: ::....::..:v77r7r7r77i:ii:::.:DMKPDQBQu7irr7r7ri::ii:rr  .BEqPMBr         r7r7rLrr:r777777rr:::i::......::iiii:iii.:r. .i7r: .ii .YIvrrPQQEDEZEZEZdZEDgBBL  ..:::iiiiii::i.i::.ii:.::::i::::::::  X:  rv:  5YYvLvvvLvYvLvLvLvLvLvLvYvLvY7vr7ug2rQgDQP7:7ZrsBSvdBPJSRD1:rLr:..v72Zr .i... igPdP.:d
vv7vvLvYU: ii...:::.:L77r7rrr7rr:iii.:..YQPKZBg7i7irr7r7riiv7r:i7.  7BERBM.        :v7rvriii:ir7r7r7rv7rii:::i......::iiiiiiii.:7. .i7i:..ir  i5j7iJdBQMZZEZEZEDdZZQBg: .::::iiii::r::i::::i::.::::::::::::i  . .:.i. vJ7Lvv7LvY7LvLvLvLvLvLvLvLvYvLvLr7Er7QEgMviL5JqBXPRgZDEIrri5Ir..7QMBg..15. SE1bEPdi7RU
JYJYsLYY5. ir..:::.iL77r7r7rrr7i::i::.iiSgPPBPi::r7r7rrrir7r7i:ir   vBBb:         77ii7r7i....:.:.:irr777ri:i:i:.....::irriiii: :r: .:7i:..ii. .LIU7rsPDQQQZDdZdZEZEgBBj  ::::ii::r::i:::::::::.::::::::::::i   ii:i. rQs7LsjvL777v7v7LvvvYvLvLvLvLvvvvr:7BggggPr.1DQDgggDgduLPRQr....rr12:7QBb .gBgEPggMQ1i
r7r77771J..i...::.ivr7r7rrr7rvr::iii.:ivgPPBZ:::.r77r7r7r7r7rv:7.    7.         :Yri:rr7r7:.           ..:iirriri:.. .::iiiiiii: .7r. .ri:..ii:. :71uLr7v5bQQMEDEZdZdgMBq  ::::i:ri:i:::::::::::.::::::::::::i.:i::ri  BQr7vsJLYUJ77r77vvLvLvLvvvL7v77rr2BgMZZqv:KQQggggEZZddMDXr:iY2dZq.:qBddR7 2QPbZU7svir
:......::.....:..iLrrrrr7r7r77i:::ri.:iKMKESi::::i7rrr7r7r7r77i7.             .r7ii:r77rr7Lr:.  5BBPv:        ..:ii:. .::::i::ii. .r7:..::..r:ii:  .:vUus7rvPgQggEDdDdDgBZ  .::.ii::::i:::::::::..::::::::::ii.   ::r  vBLirvvYqBQPbPIJ7rr77v7vrrirr77IgBDggSv7sQQMggDgZdIvisqqKXZRMMgRqEQSXEPMM:.PgEi::ii:.
jJLJYLrri....::.:vr7r7r7r7r777:i::7r.irDdgJ.r:::.:r7r7r7r7r77ri7             r7rii:ir7rrr77L7i:.  YBQBBBRK7i..     :::.::::::iii::..:7r:.. .ii:ii:..  .:rsusrrsgQRZZEZdDDBg. .:::::::r:i:::::::::.::::::::::i   ..:::  .BBUri77vL52uuKZMDPuLrriJKXXPXbMRDgEI7UgQDgggbKL7i:::::7DbdPbPE5j7irEgZdQBgZMDSrr7i.i
svsLJYuuqr..::.ivr7r7r7r7r7r7i:::iv7::vgddgir:::rrrr7r7rrrrrvi7.         ..iv7i:i:iir77r77vrvYvi:    7MBBQBBBdX:.     ..i::.:::::::...irr:::i:i:ii:::..   :rUJ7r2ZQgZEZdDDBQ. .::::ii:i::::::::::..::::::::i  .ri:::i.  QRQM5rriiiLvv7772PQBBEbEggQZggMZDEK5ZbPPdXurrrJJvirLXDMEgZEEMv:.iPBSr:irYUJrrirr7rv7
vYvYvLLUJ..::::v77rrr7r7rrr7ri:i:777::JRPgqr.::uQB1rr7i:.rrrri.        ::rr7vr:::::ir7r7iri7irvLri::    .IBBBBI   iY      .i..:ii::::. :irii:i:i:ii:::::... .rJ27r1RQRZZdDZBB. .:::::i::::::::::::.:::::::i.  i::::i:.  IBbDRMq2YYiii7vvri:iIBMdKbEMDDEbSXPMgdbDqU1KX57rLPQBRgPPLvuUs2ERMBDr:iiiiiirr77v7vvv
JvYvLvsUi .:::v77r7r7rrrrr77r:i:i7vi::Jgdgv::i5BgLr:iri...iiri        iiii777riii:rrir7:r::i:.:rv7riri:     ivq2uvDBBB1:    . :::::::::..:riiii:iiiiii::i::.. .:j1v75DBggEZZBB. .::::::::::::::::::.::::::i  i::.  ..  :2XBggDMQQRMqK2LriUPXEZDPbPbEPKddMRQggdbX2JY777qMQqIsvri::rX5PddK2Lri77v7v7vv777ii::.
7YLYvYjL..::.777r7rrr7r7rrr7::::r77i:i7gPgs::XBgr....:iJjbZgdRR7:    :::.:::irr7777vr77ir777ii:ii77v7rrrii.      .  .YuXY     ::::::::::...iii:i:i:i:ii:ii.:::.. :rsv7IMQgEDDBQ. ..::::::::::::::::..::::::i:i:       .2QILKgQRKPQBBBBgZPggMDgZgQQgMgRDE52vv7rir7YJ22Iv7iii7rJIPPK52v777r7r7rrrri::.......:i
riYYYvUi .:.777rrr7rrr7rrrr:..:iv7v:.:LMZZI::XQEi::rjqQQBQQRBQPXD7.:v7Yvrv17r7ri7r7vL77r7r7rv7r:ir7r777i7rrri::....        :..i::::::::::...iii:i:i:i:iiiii:i::::.  iJYrIMBDZZBQ. ..:::::::::::::::...:::::::.  :EJ B.MPi5MqjLXq2vJuPZQQBQBQBQBBZJ2JLri:::i:ir7rL77rrrvrrrri7ISLvrriiii::...... ....:i7YJj11
iiissJJ:.:.i77rrr7r7r7rri:rvsui77Li..iiSMZg7.qQE::2QZQMgEgDQBM:.:7vXbDQQgBQQdZb7:rri:::vv7r77v7rrrr7r77v77riirii::.::r    :i:::::::::::::::. :riii:i:iii:ii::i:::::. .r17vSQRgZBZ  ..:::::::::::::::.:::::.    IgE5 B52UrrYEBZ5vjq5Jr77v7vJIssY7::..:iirr77v777v7YLJjs777ssuvrii::.........:::i77vsjJUJjYsLs
vriisjj..:iv7rrr7r7r7rrivJQQDPLiri.:i:::gRgg7:ZRv:RdPdgZgDBgs.:vPggMgbMgQggDRDZg2i7.....rvvrirv77riiri7777777:iiri:..   :ii:::::::::::i:::::. .iriiii::::::::::::::::. .sJrvbQRgBJ ..:::::::::::::::..:::.    DQS1b L25vv11vPDDKYr777iiiriiii:i:::ii77vvYYJsjs1JuJ1Jv:irrii:........::rrvvsJ1jUj1sJYYLYvLvLv
sYrirju..:ivr7r7r7r7rr:2QBd7i:::i:.:::::rYZRgJ7EZvIdPgEgZBE:.iERZPKDEPDgZgDgDMgZMYi:.:...:vYi::777iriiiiirr7ii:::: ...:::..:.:.::::::::::i:i:: .:rii:i:iii:i:::::::::::. rUviuMBRBi .:::::::::::::::.::. .  .  7ZKbr  BjrU7rr::iirr77vvv77rrr7rvvJsjsuJuJ1j1JJvv7ri:........:iirrYLjJ1u1JuYJLYLLvLvLvLvYvLvL
sLsrirJ...i77r7rrrrr7ivRDP:ii.::i::.::i:i:rERgPPDEPdEPDZMQr.:PMqqSqdgZgZQQBQQRRdMbr::::::.:rJ7:.i777vri:::::7rrvLrYs2U1Jsri:i:::::i:::i:i:ii:::..:rii:::i:i:i:i:::::::::. :YUrrXBBB. .:::::::::::::.:.  .  :BK   IQ7  Us77vvvvLLsYJLsLvr77vLssJJUuUJ1sJv7ri::......:::iir7vLJJuJusjYYLsvYvYvLvLvLvYvLvLvLvLv
iiirr7r..:ivr7r7r7r7i:5gbgU7::.:::.::ii:.i:rggiuDbKqEEPDQS.:jQPqKDggZgQjiu1ZgddEQU::.:::::...rL7ivvLriirir7YJY7r:.      .i7vLYi::i:i:iiiii:i::.:..:iii:i:i:i:i:::::::::::: .vIvijBB5 .::::::::::::::.       Pgdi  Dr  JuLLvYvLvLLYLYvYLjs1j1j1jJv7ri::.....:::irrvvuJuj1juJJLJLYvLvLvLvYvYvLvYvLvLvLvLvLvYvL
77rirrr.:::7rr7r7r7r.:gZgdv77.::::::::::i:i.:7::DPqPdPgZQP:.5QbKPgggBQBI.:::irRgs.:.:.:.:.:ir7sLJ77rririii.                  .::::::iiririiii.:::...i:i::::::::::::.:::::::...1u7vMQ..:::::::::ii:.  .   X  iZIPg    .qYYvYLYvsvsLjJuu1Jsv7ii::.....::ii77Ysuj1jusJYsvsLLLLvYvLvYvLvLvYvL7LvLvYvLvLvLvYvLvYv
sjYL7Lj..::vrrr7r7r:.rgMPrii...::i::.:iriv2bL::iEEXPZEPDZMb7:UbPXgQBvdsXQQZUYsYi ::....::irJjLri:..          :i:  ..   5qL.    . ....::iiriri:::::...::i:::::::::::i:::::::::..7UuUu .:::::iii:.   ..   dQ2  EUuPK   Y5svsYuJ1Jjss77ii:......::ir77YsuuuJJsJvLvYvLvYvLvYvLvLvLvvvv7LvL7v7YvLvLvLvYvLvLvLvLvL
YvYvJsXi.::77i7r7ri::igRvi:.:...i::.:ir:5RMDMPi.dZqqZEgdPXM5:ibPPRRJ..:RBL:iiiiiri:ir7Jsvr:         :    .JPbQBQM.   :QQSgBRs           ..:::::::::...::::i:::i:::::::::::::::. :7r:.:iiii:..   .      SPJg. IKJXP   25J1Js7rii::....:::ii7Yss1juJjYsYYvLvYvLvLvLvLvLvLvLvLvY7v7Ls11J7vLU1YvYvLvLvLvLvLvLvYv
LYvvvJ1i.::7rirvr:ri:iqBri.:::..:i::i7:SMEPPPQK.vQPqPDZgPKES:dZqEBi.iiPQR::rrrrr77r7v7.      ...:v5BQ  .UdSUXdqPgBrrgBZdLJbgBB5r            ...:::::...:::::::::::::::::::::::::.::::i..     .     .:LIIY2g7 iP1KX  :rrr::...::ii77JYjj1juJjYsvsvYvYLYLsvYLYvLvLLYvYvYvLvLvLvvvU1UYv7s1IsLvLvYvLvLvLvLvYvLvL
JvLvYJY...:r7r77:r7:::Ugii..:::..::.riLRdPPqPPQY.IMPKPgZgKdq:YZKgQi:r:PMBv.irrrri.r:... iYU 1BBBBQRB7 .BBLY1ZXK5qMBBBKqqUYPXPPQBI   jPdXEdL    ...::::::::::::iiiiiii:i:i:i::::....             .  rBgPXqdg7 .D1gi  v:::rrvLYJ1jUJjYsYsLsYYYsYJsjJuj1j1jUj1j1JusjsJLsvsLYLYvLjUjL7vYUUJvv7YvYvYvYvYvYvLvLvLv
svvLvIi.:.:v777::7:::iigri:..:::..::iiqgPPqPKPbg:.UREPPDDZqdIs2PdBY:ii:KQBs:::.sB2rii: iBBBB:IRdPPDS ..RM5rJPKIbBB  QQIKKKKKXKKDQ  Qd512ugBBX:       . .                               .:Yu.  PBQB:  XdEKbE7  EZX  .1jJ1JuJjLsvsvsYJYujUUI2I11sY7ririii::i:iirr77JjUU52I1Us12UvvvLv1Lv7LvLvLvYvLvYvLvYvLvLvL
svLvs1:.:..7vvi.7i::i:isQri..::::..:::PEPKPqPKPZZi.7EgEqPPPqEbPXPRg:isJ7ZQBgP1JKBQBEb17. .XBQ:JZPPK.sBJ.BMurPPQQY .  BBIXPPKqXPBE .gKJusY1dPRBg                   .ir:.   ..  .:iivsUUXKPSZg  BgdEg7  qKbPZr :BZ   U2LYvYvYLYLJJUU51u7r:.                               .:7YU121ussvLvLvLvLvLvLvLvLvLvLvYvYv
LLvYJu.:::.r7r.ri::i:::ijBP7.:::::..:rqgPPqPKPKPZgv:.7XMPPKPqPqPXPdu:r1PZbZBBBQQdbEQQQQQIi.LMBiYdSYBBBQP2BB5qBD  1BK .BBIISDdZBB   .E2JuYsqPKPQB.        LXqS5SY2BBBQBP  7dPP  Qdb55uIIXKq5P  gESPqD: .PPdE7 .I   rSsJvvLss1UIu7:.       .isSZMBBBBBQBBBBBBBBBBBBQgPjr..       :rjUIuuYsLYvYvYvLvYvLvLvLvYvL
svYL5i.:::.:r.:riri:i:::.vBJ7.:::::..ruDbKPqPKPKPbMPj:.7ZZEPPKdPPKPZZs::ii71qPdKXSqKdZggBBQEdgMKEQBBPjUPr71:.  .BBBI   QBKI5PE5     ib1JJvSPKKPBJ uBbi   2BX52IUPbPKqBs rdS5Xs vdUPU2KbqdXKJ  BKK5bdK  uEbg.     :dL22JjIIur.     :JgQBBBBBBBBBBBBBQBBBBBBBQBBBBBBBQBQBQBQBRXi.     :v22UYsvLvLvYvYvLvLvLvLv
LLv1s .:::.:i.iirr:i:i:::.::rr.::::. :LQZPqPqPqPKPbZDgu:iJqdZqUqdbKbZgIr:rrrruSZdbKqXqKPKPPb5DDMP7.   rK1 .i7vSBBQU7Ji         v  KY sPusJJbKSEB  QDDBBr  iEuuJJ2PXKPB  E1Kd5M7 sX2EqKSqquD. JRKSqKDg  uBD.     :gKI2ESY.    iKBBBBBBBBBBBBBBBQBBBBBBBBBBBBBQBBBQBBBBBBBBBBBQBBBBg7.    rU21LsvYvLvLvLvYvLvY
YvYIi :::::.::ir7:i:i:i:i::::::::::.. i5RbbqPqPqPqSqgZgEKvviJPEjjqDbbbDXL:irvvUqgMQMgDMDZdPqXdgMq  7gMZXPgBQBBBBZvrvjU5jYriiL1gY .Mg. UK1JY5KPB. dDSSSZQb  rPJJLIqKXBi Ku2PXqPB: uI2PSqq5K7 iQbqPEMQB  .7  .   iRKqb5:   :dBBBBBBQBBBBBBBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQv    75uJvYvLvYvLvLvYv
LYuu .::::::.iivi::i:i:i:i:i::.:::::. .r:ugdqPKPPbUrrPMgZgD2ii2MbusXbDEdqui:...::i71qMQBBBQQMgZgDDBQ51dQBBBBRP5vi7vYYjJuU55K2KI  P5KP  dIuLXQB. LQXXSXSbBY  PUYjKPqBi UUjPKKXKPB  S1KdP55J 7BBQBgq2Y.    L:   ZMqZ1   iQBBBBBBBBQBBBBBBBBBBBBBBBBBQBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBL   iU2YsvLvLvYvLvL
JLI:.:::::::.:rr::i:i:iii:i:ii:::::7Jii7:75XPqPKPPEP7.7SDDgMg57iLPd5uL5gRggPqI1i.   ...:rrjSgQQRQBBQBQBgP2uri:irYYju1sYv7iiiii  PD55M: iMSqBP  :BPbPggggBB. ZIJ2ddBi 2UjPqPKPKbQE 7qPbPPP iB5i.      .UKrJ  .EDPX   IBBBBBBBBBBBBQBBBQBBBQBBBBBBBBBBBBBBBBBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBQ.  rSJsvYvLvLvYv
YU7 .:::::::::ii:i:i:i:iiiiiiri::::i7jLPEJvIPPSPqPPEDj:.:7Y2qRQZsir1qq7ruPDQMQRMPP1v7vrrr:.ir1PgEKIXuuri:ii7vYLjv7i:..     ..   15ISP7  uqs:  .BQQDKr.:: i  SdPQQg..PqPQQQRRMQRBQ .Pvr::       irUiXU7u    LDEbr  5BBBQBBBdKBb:Bq77uQB7QBgYBBBBRBBqBBjBD7v1BQB1UQBuK55BQ7BBBUv7qSBQ77BBBBBBBQB  .IjsvLvLvLvY
jU..::::::::ri::iiririiiiii:i::........ :2L1bPPqPKPqbZgq2Jjr::rr7iir2ZqZXrvjKPgMBQBBBBZKEQBgL:irriiiiir77ri:.....:ii7rLJSPdqDu                 .        :     :r. rRXS1r:.            ..:irLdZQQ5Bir    iKgPKd: .QBQBBBBBBQri:RY:QBIiZ:BB.vBBBBivr Us.B :YQBBii gr.2uLB7:BBQ iuQZi:rQBBBBBBBBBBU  2jsvYvLvLv
I7 ::::::::irrrrii:i:::::.............r7gBMK2XKPPPKPqbqEEDEDbP21sUv7ii.uKgqriii77Ju1UUriirr77sLL77ri::.....::vsISPEDbEKKSqKdZBQDjv2K5S5S7: .     .r2bQBBBBBRP1r:.        :ivLv772ssQZQDDDMggEQgr     iuRRqUIP7 :BBBBBBBBBBQP BB.7BB:7Y:M7 BBBBBi 1B  Bg vrPQ  I 1RIZI.g LZ5J jrMBiiBBBBBBBQBQBBBZ  5YYvLvYvL
P:.:::i:ii.::..        .:..:vi..:rUMBBBBBQBBdSSUXSPqPqPqbqPqPPEEZE5vririii7vsJri7:::ii77v7v7rii:::::irYJ2SPPdKK5SSP .P5UUj1J11XqEDZDMgRRBBBQMZEqBBBRRDggRRBBBBBBBBPU2qMgQRRMRgQQQggbqbEZgdqqu.   .sEQMZKKjUIq  BBBBQBQBBBQBsgBBQ7r7YBBrs2UBBBBBKrBBUEBQrY2Q57BBPQQJvudBivLPdrJXQBvBBBBBBBBBBBBBBB7 rUvLvLvYv
s.::...         .....ijY:iXdvr7XMMZgQgDbRgBBgPPP2X5SII5XSKISIS2gZ..7r7r7rrrrirr777rrii:ri:....     iSggMDgggZgddPMi  EK5U21U1Uu1uUjuj215ISKEgQQBQQQRbq1vi:.                                   :PQBBQDZPP521PL 7BBBQBBBBBQBBBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB .IsvYvYvL
  .     ....::::::i:i::.:ir.:IDqbPPXqqdEEDDQBMEdgMBBBZPSXXPEQQBBBE iv777v77rr::.....ru:                     .:r7j5 r: gggEDEdPqSSUI12u2USXPPP51r:         .:r7JIdZQBBQBBBQBQBBBBBQQZd51v7i:.        :iuXqPPZU sBBQBBBBBBBQBQQBBgEDgBBBQPBQBQPgBgBBBBDXbQBQBBBggMBBRQBBBdgZBBBRPBBZgQBBBBBBBBBBBBBB  SLLvYLYY
.....::::i:iii:i::::::::.. idKSDRQQQgQgZPqI5BBBQQBiiQBBBBBBBBBBBRr..7Lri.....:i71XJ5KPg                            UB  ...:rvj2qbEdZPEbKJi.      :7IgBBBBBBBBBBBBBBBBBQBBBQBBBBBBBQBBBBBBBBBBBBBZI7:      .7I  BBBQBBBBBBBB.vBBqi sQv..LMU: 7dD.BBB..rXBBBBv.1uLBE BrrZr JRs .7RPUj.:BBBBBBBBBBBBs rUYvYLJUu
i:i:iii:i:::::::::::.::.:::XKXQRL.::.:vPQgRPIBBQBBZ  gBBBBBBBBBBg:r.....rvISDgRDDZPu21PqSUYY25KXbPqKqKq1IjsXb2UJYv rBB           .::r.    .iSQBBBBBBBBBBBBBBBBBQBBBBBBBBBQBBBBBBBQBBBBBBBBBBBBBBBBBQBBBQIi     .BBBBBQBBBBg BBBBY7BBB.QBBBi7BB:iBQM JsgBBBB2JbX.Bi:5 KBL7BBB.MBBBuI2EBBBBQBBBBBBQ  UjLLv22: 
:::::::::::::::::::.:P::57SPqBI         ..rBBKBBBBQBi PBQBBBBBBBQ7::.vPRggZEqPKPXPPKsU1SXPPdPqSq5KSqXqXPUXUKUII55M  BBQu    i. ..     iPBBBBBBBBBBQBBBBBBBBBBBBBBBBBQBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBBE: PBBBBBBBBBY v:I1 rQBq:QBBB.gBB :7r2.riSBQBBE7UU:d.QBiBj iQBb.BBBQiBBQBBBQBBBQBBP  u1vYYIi  L
::::::::::i:iii:i::.Pj.qjLdPBL  .......     BBEBBQBBBr XBBBBBBBBBQ::JBgqqXPKqSKSKXqq2JUu21UU21U1212J5jsuvsYLLJULUZ: BBBBB2  :v.   7gBBBBBBBQBBBBBBBQBQBQBQBQBBBQBBBBBBBBBBBBBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQBBBRBQBBBBBBBBBBBBBQBBBQBBBBBBBBBZRBBQBBBBMBBBBBBBBBBgBBBBBQBBBBBQ.  UULLJ1  iBB
:::iii:i::::::...:.iE.rdiSqgP. .::::::::..   MBEBBQBBB: UBBBBBBBBB5.:KZdKqXKXqXKXKXP5ju2u1uUuUu112uvuJL27YvsLs1YYIX 7BBBBBBZ.  vBBBBBBBBBBBBBBBBQBBBQBBBBBBBBBBBBBQBBBBBBBBBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBBBBBQBBBBBBBBBQBBBBBQBBBQBBBBBBBQBBBBB:  r2uYYj7  dBRg
:::::.... ......::::i.d7r5PR7 ..i:::::::::.   BSPQBBBBK  7QQBBBQBBBq: iqDbPXqXPPPKKKPJju21UuUuUuUU171ss1vsYLsYsYXJ.  BBBBQBBBBBQBBBBBBBBBBBBBBBBBBBQBBBBBBBBBBBBBQBBBBBBBBBBBBBBBQBBBBBBBBBBBBBBBBBBBBBQBQBBBBBBBBBBBQBBBQBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQBQBQBBBBBBBQBBBBBBBBBBBU   :2uJLsY: uBBPZg
.. ..............i::.iZ:sqPQ: .::::::::::::7  vQSdQBQBB  iiYBBBBBBBBBIi.iuPZEEPSIPXKq5s1uU1Uu11U1IuvYuvUvuLYJuuJ:..: .BBBBBBBBBBXi.7QJsKvDBBBBBPr:i7giBgiBBgiuEv:::ZBBbQBvBBiB25BigBB7rB17:i1BBBBvQB.qErr75Bq7BBrbBBBBBBBBBBBBBBBBBBQBBBBBBBBBBBQBBBBBBBBBQBBBBBQBBBBBBBBBBBBBBBQBBBBBj.   r22YYvJ7.rBQgqZMP
......::::i::i:...i:.:d:ubdgi .::::::::::.:RP  QdPqQBBY  .i7:sBBBBBBBBBBIri7s7:.vPqXPKI11uU121Uu11IvLsLsvsJY1uYr.:i   .BBQBBBBBBBU.QP.12rPBBBBBB:.BB. 1 PBii.:B:.RBQBBrii viiB.i2 BB.r.KB:iBBBBBBb:.EM.RBB.DrPBP QBBBBBBBBB  LMQBBBQBBBQBBBBBBBQBBBQBBBQBBBQBBBBBBBBBBBQBBBBBBBBBQU.    iu5uJLLvji.XBRqqMgX1
ii::........ :::...:::r:JPPMY  ::::::::::..dB. SdDBBB7  sr ud:.jQBBBQBBBQKrr:i7KPqXKXqq1jUuUuUu11UUY7jvuv15Ss..:   iYY  BBBBBBBBM.iBQUPE.iBBBBB1 BB:.B:7S  Y Pd BBQBQBr SB .Bq BU:M  I JB.gBQBBBBB.bBq MM7.B.Y2 rBQBBBQBBBBM     .iKQBBBBBBBBBBBBBBBBBQBQBBBBBBBQBBBBBBBBBBBdv:     .7uIujLYvLLui.gBg5XQZIuS
i:::i::.:....:::... .::.rPPZg  .:::::::::..PBr 7EQBB.  iBg  KDvi::::i::.::irJXDPPqKSPXuj1uU1UuUu11ILvLsUuIIi:   iL1sJj  BBBBBBBB1L5QBKujbQBBBQB1DQB7BBXBjgBBPBKdBQBBBBgJBBDQBdXBBMDIBBQQB5BBBBBQBDPBBBd7YuBBbvdPQBBBBBBBBQBQB  L:       .:vIZRBBBBBBBBBBBBBBBBBQBBQDKsr.       .ivU2IJJYYvLvLvU:.RBZ5qQdI2S5
:::::::iiiirii:..::. ..:.SPdQ1  .i::::::...RQ  PgBB.  rBEQP. bZSjuUuvLvjjSKddbKKXqSPIuSXjU121U12uUIj71jI5r   .v1Yv777s .BBQBBBBBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBBBQBQBBBBBBBBBBBBBB  PII2UL7:.                                .:ivj222uussLYvLvYvYv2: BBgIqRZ2US5X
::::::::i::.....i::::.. .iZDDQ7  .:::::::.7Bs iQBX   uBEPiD:  dgSSPXdZDEZbbqPKKXqXPUUqXJ1u1uUuUuU15jLJK7   :JJL77r7rvL  BBBBBBBBBBBBBQBBBBgBBBKBBS2jBBBQbBBMBBBqBdD2uQBBBBDEKuBQPu5QBBBBBBX2dBBQSJ5BBqdZQBBQBQBBBQBQBQBBBBBQB  IJYYYjJU1I2I11JL7rii::::::.:::iir77sjUUI2211JJLsLYvYvYvYvLvYv1i XBgIXRg51S5X5
:::i:i::.....:...i::::..  .KQQQ1   .:::::.LU  gB:  rgQqqEJ.YL. :bd5X2S5qKX5XSqKqKPu5P2s1uU1U1Uu2u22jjS.  7ju77r777r77si iBBBBBBBBBBBBBBBB. Bb  BL r5QBg: uB  B7:Qs rIBQBBQY iKQ:rZP:dBBBB.iQX.g:vZq:EX1r bQBBBBBBBBBBBQBBBBB. 72LLvYvLvLvYLJLJJuJ1uU1U1UuU11jUjususJYJLYvsvLvLvYvLvLvLvYvLvJs YBRXURMXUS5SIX
:::::.....::::.  .i::::::.  :DBQgr.  .:::::  ..  :PQDXqXPDu.XQi .s2252S2XI1YISKKXuXP1s1jUu2uUuU121ju7  72Lv77r7r7r7r77j. iBBBBBBBBBBBBBBLiY r:.B.rJ5B1 r7:q.Di.gBZ.QBBBBBBQ BB5 BBB dBBBQ Qg.J1.BBR BP2PMBBBBBBBBBBBBBBBBBB. :5LLvLvv7vsULLvYvLLLvYLYLsLsLYvsLLvYvLvYvLvLvLvYvLvLvYvYvLvLvY1..BQbjgMP155SISS
.... .:::::::::.  .i::::::.. .r1dBBB1  . :::.ii1EQZPXKSKSPDK.7B7  LUuI1Ij1u1jus1s5IjJUu21U1U121II2Li.rIvr7r777r7rr77r77u:  MBBBBBBBBBBBBigQ:BPYB:i75R.YgX2YvBPrBQjrBBBBBBBIiBBBir7:1BBBBg.ii5BBii7.KBJ1BBBBBQBBBBBBBBBBBBP  iSYsvLvv7122vv7LvvvYvYvLvLvYvYvYvLvYvLvLvLvLvLvLvLvYvLvLvYvLvsJv PBgJPMDuSIS5S5S
::::::::::::::::. ..i::::::::.    .ii.....5DPMQgEKPXKSKXqXPdK.7QL  71j5UI1UuU1UuUu1uUuUU21UYJj5IUriiIY. 77v77r7ivLYrrr77J7   PBBBBBBBBBBBQBBBBBBBBBBBBBBBBBQBBBBBBBBBBBQBQBBBBBQBBBBBQBBBBBQBBBBBBBQBBBBBBBBBBBBBBBBBBBX   J2LsvL7vY52s7suY7LYYvYvYvLvYvYvLvYvLvLvLvLvLvYvLvYvLvYvYvLvYvLLI :BQIUgMIIIX5S5SS
:::::::::::::::i. ..:i::::::::::::...::::.JQPPXqXqXKXqXKSqq2:v.vBZ: :Yju15U221u5uu12jUssJ2YusJ1srivU: .LL1srrrru1vr7r7r7rv77   rBBQBBBBBBBBBBBBBBBQBQBBBBBBBQBBBQBBBQBBBBBBBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBQBBBBBBBQi   L2uLYvL7LuXs7vI1Yvj1svLvLvYvYvYvYvYvLvLvLvLvYvLvLvYvLvYvYvLvYvLvIi MBdjPQb22S5S5XIP
::::::::::::::::i....::::::::::::::::::::.IDPSKXKSKXKXqSKXqdI...JBQL  rYuYUsJYssjYss1JuLJYJsU1YrvJv  i2suY7iir5Jri7r777rrruED2:   7RBBBBBBBQBBBBBQBQBBBBBQBBBBBBBBBBBBBBBBBBBBBQBQBBBQBBBBBBBQBBBBBBBBBQBBBBBBBQBd:   :s5JsvYvv7sI5v7uIsvL2JL7LvLvYvYvLvYvLvLvYvYvLvYvYvLvLvLvYvLvLvLvYvJI .BRXjggKuqP55X5Sq
:::::::::::::::::: ...::::::::::::::::::..5ZSKXKXKSKXKSKSKSPEd:..JQQ1 .i7IJJYLvsYsYusjssJ1u1Yv7ur. .j2sJsviiLqUirrr7r7r7ijX51XPdU.   .LQBBBBBBBBQBQBBBBBBBBBBBBBBBQBBBBBBBQBBBQBBBBBBBBBBBQBBBBBQBQBBBBBBBBBBdi    :YSUJYYvLvv71I17vu277vuLv7LvLvLvvvLvLvLvYvvvYvLvLvLvLvLvLvLvLvLvLvLvLuv uBMjKgg25Eq2S5SIP
::::::::::::::::::: . .:::::::::::::::::..XdK5XSXSXSKSK5XSXXPdD:  uMB2:i :U12Js7YvvvYLjujvvrrvI:  7IuLYYLii1KSYirrjiririiiiiuU2Uqgr       :ugBBBBQBBBBBBBBBBBBBBBBBQBBBBBBBQBQBQBBBBBBBBBBBBBBBBBBBBBBBBb7.    .r2P2JvYvvvLvvvIUY7v7Y7v7L7vvv7vvvvL7vvLvLvLvLvvvvvLvLvLvL7L7LvLvv7LvvvvvI: bBPuEMb1XZU5ISI5q
::::::::::::::::::i: . .::::::::::::::::..UgPbqPPbPPqPqPqbPPqdDB5. 1bu:.. .iivsJYJYsLYvJ7rrsU7  :KXUYusvr75PSSirvPPY7uXSUI15552S2dP.:i::.        :7UPQQBBBBBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQRP17:      .ruqPPuUssssYsLsLsv1uL7YLsLsvsYsLJYJYJLJLsLsLsLJYsLsYJLsYsLsLJLsLsYsYsLsLsLYLuI. BQqSQMPUddXXKKq5d
)";