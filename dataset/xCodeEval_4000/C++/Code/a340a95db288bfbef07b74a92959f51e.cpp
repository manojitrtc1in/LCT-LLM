#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define For(i_,l_,r_) for(int i_=(l_);i_<=(r_);i_++)
#define Rep(i_,l_,r_) for(int i_=(l_);i_>=(r_);i_--)
using namespace std;
#define Mi Mint
#define CMi const Mi
#define Ci const int
#define Cl const ll
#define Cul const ull
#define Cc const char
#define _c_ getchar()
const int M=998244353;
inline int Add(Ci x){return x>=M?x-M:x;}
inline int Add(Ci x,Ci p){return x>=p?x-p:x;}
#define CFr const Fr
template<typename T=ll>struct Fr{
	T x,y;
	Fr(){x=0,y=1;}
	Fr(const T a_,const T b_){int g=__gcd(a_,b_);x=a_/g,y=b_/g;if(y<0)x=-x,y=-y;}
	Fr(CFr&x_){(*this)=x_;}
	inline operator bool(){return x;}
	inline Fr operator~()const{if(x<0)return{-y,-x};return{y,x};}
	inline Fr operator-()const{return{-x,y};}
	inline Fr operator+(CFr&U)const{return Fr(x*U.y+y*U.x,y*U.y);}
	inline Fr operator+=(CFr&U){return(*this)=(*this)+U;}
	inline Fr operator+(Cl&U)const{return{x+y*U,y};}
	inline Fr operator+=(Cl&U){return(*this)=(*this)+U;}
	inline friend Fr operator+(Cl&U,CFr&V){return V+U;}
	inline Fr operator-(CFr&U)const{return Fr(x*U.y-y*U.x,y*U.y);}
	inline Fr operator-=(CFr&U){return(*this)=(*this)-U;}
	inline Fr operator-(Cl&U)const{return{x-y*U,y};}
	inline Fr operator-=(Cl&U){return(*this)=(*this)-U;}
	inline friend Fr operator-(Cl&U,CFr&V){return -V+U;}
	inline Fr operator*(CFr&U)const{return Fr(x*U.x,y*U.y);}
	inline Fr operator*=(CFr&U){return(*this)=(*this)*U;}
	inline Fr operator*(Cl&U)const{return Fr(x*U,y);}
	inline Fr operator*=(Cl&U){return(*this)=(*this)*U;}
	inline friend Fr operator*(Cl&U,CFr&V){return V*U;}
	inline Fr operator/(CFr&U)const{return Fr(x*U.y,y*U.x);}
	inline Fr operator/=(CFr&U){return(*this)=(*this)/U;}
	inline Fr operator/(Cl&U)const{return Fr(x,y*U);}
	inline Fr operator/=(Cl&U){return(*this)=(*this)/U;}
	inline friend Fr operator/(Cl&U,CFr&V){return ~V*U;}
	inline bool operator==(CFr&U)const{return x==U.x&&y==U.y;}
	inline bool operator==(Cl&U)const{return(*this)==Fr(U,1);}
	inline friend bool operator==(Cl&U,CFr&V){return V==U;}
	inline bool operator!=(CFr&U)const{return x!=U.x||y!=U.y;}
	inline bool operator!=(Cl&U)const{return(*this)!=Fr(U,1);}
	inline friend bool operator!=(Cl&U,CFr&V){return V!=U;}
	inline bool operator<(CFr&U)const{return x*U.y<y*U.x;}
	inline bool operator<(Cl&U)const{return(*this)<Fr(U,1);}
	inline friend bool operator<(Cl&U,CFr&V){return V>=U;}
	inline bool operator<=(CFr&U)const{return x*U.y<=y*U.x;}
	inline bool operator<=(Cl&U)const{return(*this)<=Fr(U,1);}
	inline friend bool operator<=(Cl&U,CFr&V){return V>U;}
	inline bool operator>(CFr&U)const{return x*U.y>y*U.x;}
	inline bool operator>(Cl&U)const{return(*this)>Fr(U,1);}
	inline friend bool operator>(Cl&U,CFr&V){return V<=U;}
	inline bool operator>=(CFr&U)const{return x*U.y>=y*U.x;}
	inline bool operator>=(Cl&U)const{return(*this)>=Fr(U,1);}
	inline friend bool operator>=(Cl&U,CFr&V){return V<U;}
	inline double real(){return 1.0*x/y;}
};
template<typename T=ll>inline void writefr(CFr<T>&X,Cc&C=-1,Cc&Q='/'){write(X.x,Q,X.y,C);}
template<Ci Mod=M>struct Mint{
    #define MI Mint<Mod>
    #define tmpMOD template<Ci MOD>
    #define Cm CMi<MOD>
    int x;
    inline bool q(){return!!x;}
    Mint(Cl x_=0){x=x_;}
    tmpMOD Mint(Cm x_){x=x_.x;}
    inline void init_with_mod(Cl x_){x=x_%Mod;}
    inline void init_with_add(Cl x_){x=Add(x_,Mod);}
    inline void init_with_neg(Cl x_){x=Add(x_+Mod,Mod);}
    inline void init_with_both(Cl x_){x=Add(x_%Mod+Mod,Mod);}
    

tmpMOD inline MI   operator+ (Cm&U)const{return MI(Add(x+U.x));}
       inline MI   operator+ (Cl&U)const{return MI(Add(x+U));}
tmpMOD inline void operator+=(Cm&U){(*this)=(*this)+U;}
       inline void operator+=(Cl&U){(*this)=(*this)+U;}
inline friend MI   operator+ (Cl&U,CMi<Mod>V){return MI(U)+V;}
tmpMOD inline MI   operator- (Cm&U)const{return MI(Add(x+M-U.x));}
       inline MI   operator- (Cl&U)const{return MI(Add(x+M-U));}
tmpMOD inline void operator-=(Cm&U){(*this)=(*this)-U;}
       inline void operator-=(Cl&U){(*this)=(*this)-U;}
inline friend MI   operator- (Cl&U,CMi<Mod>V){return MI(U)-V;}
tmpMOD inline MI   operator* (Cm&U)const{return MI(1ll*x*U.x%M);}
       inline MI   operator* (Cl&U)const{return MI(1ll*x*U%M);}
tmpMOD inline void operator*=(Cm&U){(*this)=(*this)*U;}
       inline void operator*=(Cl&U){(*this)=(*this)*U;}
inline friend MI   operator* (Cl&U,CMi<Mod>V){return MI(U)*V;}
       inline MI   operator-()const{return Add(M-x);}
    inline MI power(ll G){
        if(!x)return 0;
        MI u=(*this),ans(1);for(;G;G>>=1,u*=u)if(G&1)ans*=u;
        return ans;
    }
    inline Mi inv(){return (this)->power(Mod-2);}
tmpMOD inline MI   operator/ (Mi<MOD>&U)const{return MI(1ll*x*U.inv().x%M);}
       inline MI   operator/ (ll U)const{return (*this)/MI(U);}
tmpMOD inline void operator/=(Cm&U){(*this)=(*this)/U;}
       inline void operator/=(Cl&U){(*this)=(*this)/U;}
inline friend MI   operator/ (Cl&U,CMi<Mod>V){return MI(U)/V;}
       inline MI   operator++(){return x=(x==Mod-1?0:x+1);}
       inline MI   operator--(){return x=(x==0?Mod-1:x-1);}
tmpMOD inline bool operator==(Cm&U)const{return x==U.x;}
tmpMOD inline bool operator!=(Cm&U)const{return x!=U.x;}
       inline bool operator==(Cl&U)const{return x==U;}
       inline bool operator!=(Cl&U)const{return x!=U;}
inline friend MI   operator==(Cl&U,CMi<Mod>V){return MI(U)==V;}
inline friend MI   operator!=(Cl&U,CMi<Mod>V){return MI(U)!=V;}
       inline MI   operator<<(Cl&U)const{return(((ll)x)<<U)%M;}
       inline MI   operator<<=(Cl&U){(*this)=(*this)<<U;}
    #undef tmpMOD
    #undef MI
};
template<Ci Mod=M>inline istream&operator>>(istream&G,CMi<Mod>&x){return G>>x.x;}
template<Ci Mod=M>inline ostream&operator<<(ostream&G,CMi<Mod>x){return G<<x.x;}
const int inS=1<<18,ouS=1<<18;int _p,_l=-1;
char _b[ouS],_d[55],_c[inS],*_u=_c,*_v=_c;
template<typename T=int>inline T read(){
    char ch=_c_;T X=0;bool fl=0;while(ch<48||ch>57)fl|=(ch==45),ch=_c_;
    while(ch>47&&ch<58)X=X*10+(ch^48),ch=_c_;if(fl)return-X;return X;
}
inline char Gec(){char ch=_c_;while(ch<33)ch=_c_;return ch;}
inline int Ges(char*K){
    int L=0;char ch=_c_;while(ch<33)ch=_c_;
    while(ch>32)*K++=ch,ch=_c_,++L;*K++=0;return L;
}
template<typename T>inline void read(T B,const T E){for(;B!=E;B++)*B=read();}
inline void flush(){fwrite(_b,1,_l+1,stdout);_l=-1;}
inline void _pc(Cc&C){if(C!=-1)_b[++_l]=C;}
inline void _chf(){if(_l>(ouS>>1))flush();}
inline void puc(Cc&C){_b[++_l]=C;}
inline void pus(Cc*K,Cc&C=10){while(*K)_b[++_l]=*K++;_pc(C);_chf();}
inline void write(Cc&C){_b[++_l]=C;}
inline void write(Cc*K){while(*K)_b[++_l]=*K++;_chf();}
template<typename T>inline void write(T X,Cc&C=-1){
    if(X<0)_b[++_l]=45,X=-X;do{_d[++_p]=(X%10)|48;}while(X/=10);
    do{_b[++_l]=_d[_p];}while(--_p);_pc(C);_chf();
}
template<Ci Mod=M>inline void write(CMi<Mod>&X,Cc&C=-1){write(X.x,C);}
template<typename T,typename...A>void write(const T&X,const A&...a){write(X);write(a...);}
template<typename T>inline void writel(T B,const T E,Cc&c=' ',Cc&e='\n'){
    for(;B!=E;)write(*B),_pc(++B!=E?c:e);
}
#define Writel(x) template<typename T>inline void writel(const x<T>&g,Cc&c=' ',Cc&e='\n'){writel(g.begin(),g.end(),c,e);}
Writel(initializer_list);Writel(vector);Writel(set);Writel(multiset);
template<typename T,typename Func>inline ll Q_element(T B,const T E,Func F,ll init=0){
	ll ans=init;for(;B!=E;B++)ans=F(ans,*B);return ans;
}
template<typename T>inline ll max_(const T B,const T E,ll init=0){return Q_element(B,E,[](Cl x,Cl y){return max(x,y);},init);}
template<typename T>inline ll min_(const T B,const T E,ll init=INF){return Q_element(B,E,[](Cl x,Cl y){return min(x,y);},init);}
template<typename T>inline ll sum_(const T B,const T E,ll init=0){return Q_element(B,E,[](Cl x,Cl y){return x+y;},init);}
int Failed=-1,*failed=&Failed;
template<typename T>inline T maxp_(T B,const T E){


	if(B==E)return failed;
	T P=B++;for(;B!=E;B++)if((*B)>(*P))P=B;return P;
}
template<typename T>inline T minp_(T B,const T E){


	if(B==E)return failed;
	T P=B++;for(;B!=E;B++)if((*B)<(*P))P=B;return P;
}
inline vector<int>::iterator maxp_(vector<int>::iterator B,const vector<int>::iterator E){
	if(B==E)return B;
	vector<int>::iterator P=B++;for(;B!=E;B++)if((*B)>(*P))P=B;return P;
}
inline vector<int>::iterator minp_(vector<int>::iterator B,const vector<int>::iterator E){
	if(B==E)return B;
	vector<int>::iterator P=B++;for(;B!=E;B++)if((*B)<(*P))P=B;return P;
}
int n,m,T,L,X,Y;ll res=INFLL;
struct N{
	int a,b,c,d;
}p[32645];
int dis[256][32645];
inline int Dis(Ci u,Ci v,Ci w,Ci x){
	return abs(u-w)+abs(v-x);
}
int C[70];
inline ll val(){
	int U=sum_(C,C+66);ll ans=0;
	for(int i=0;i<66;i++)ans+=1ll*(C[i]-U)*(C[i]-U);
	return ans;
}
inline void init(){




	for(int i=1;i<=16;i++)
		for(int j=1;j<=16;j++)
			for(int k=1;k<=16;k++)
				for(int l=1;l<=16;l++){
					if(i==k&&j==l)continue;
					if(i>k||(i==k&&j>l))continue;
					p[++L]={i,j,k,l};
				}
	for(int i=1;i<=16;i++)
		for(int j=1;j<=16;j++){


			for(int I=1;I<=L;I++){
				dis[(i-1)*16+j-1][I]=Dis(p[I].a,p[I].b,i,j)+Dis(p[I].c,p[I].d,i,j);


			}


		}
}
int g[32645];
int Qt=100,Qn=3,Qm=3,Ax1=1,Ay1=1,Ax2=2,Ay2=1;
inline void Getnm(){
	cin>>n>>m;










}
inline void GetT(){
	cin>>T;




}
inline int SCAN(Ci X,Ci Y){
	cout<<"SCAN "<<X<<" "<<Y<<endl;
	int x;cin>>x;return x;




}
inline int DIG(Ci X,Ci Y){
	cout<<"DIG "<<X<<" "<<Y<<endl;
	int x;cin>>x;return x;




}
int GGGG;
inline void ypa(){
	++GGGG;
	Getnm();
	int QL=0;


	for(int i=1;i<=L;i++)
		if(max(p[i].a,p[i].c)<=n&&max(p[i].b,p[i].d)<=m)g[++QL]=i;


	int Ct=0;
	while(1){
		res=INFLL;if(++Ct>=6)cout<<GGGG<<'\n',assert(0);
		if(Ct==1){
			X=Y=1;
		}
		else
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int D=(i-1)*16+j-1;
				memset(C,0,sizeof C);
				for(int I=1;I<=QL;I++)C[dis[D][g[I]]]++;
				if(val()<res)res=val(),X=i,Y=j;
			}
		int x=SCAN(X,Y);int ql=0;
		int D=(X-1)*16+Y-1;
		for(int I=1;I<=QL;I++)
			if(dis[D][g[I]]==x)g[++ql]=g[I];
		QL=ql;
		if(ql==2){
			if(p[g[1]].a==p[g[2]].a&&p[g[1]].b==p[g[2]].b){
				if(DIG(p[g[1]].c,p[g[1]].d))DIG(p[g[1]].a,p[g[1]].b);
				else{
					DIG(p[g[2]].a,p[g[2]].b);
					DIG(p[g[2]].c,p[g[2]].d);
				}
			}
			else{
				if(DIG(p[g[1]].a,p[g[1]].b))DIG(p[g[1]].c,p[g[1]].d);
				else{
					DIG(p[g[2]].a,p[g[2]].b);
					DIG(p[g[2]].c,p[g[2]].d);
				}
			}
			break;
		}
		if(ql==1){
			DIG(p[g[1]].a,p[g[1]].b);
			DIG(p[g[1]].c,p[g[1]].d);
			break;
		}
	}
}
signed main(){init();for(GetT();T;T--)ypa();flush();return 0;}