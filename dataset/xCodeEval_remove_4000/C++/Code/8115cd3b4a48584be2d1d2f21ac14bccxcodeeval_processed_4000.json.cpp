










using namespace std;












inline int _lg(Cl x){return !x?-1:63-__builtin_clzll(x);}


inline int _cnt(Cl x){return __builtin_popcountll(x);}
const int M=1000000007;
inline int Add(Ci x){return x>=M?x-M:x;}
inline int Add(Ci x,Ci p){return x>=p?x-p:x;}

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

Writel(initializer_list);Writel(vector);Writel(set);Writel(multiset);
template<typename T,typename Func>inline ll Q_element(T B,const T E,Func F,ll init=0){
	ll ans=init;for(;B!=E;B++)ans=F(ans,*B);return ans;
}
template<typename T>inline ll max_(const T B,const T E,ll init=0){return Q_element(B,E,[](Cl x,Cl y){return max(x,y);},init);}
template<typename T>inline ll min_(const T B,const T E,ll init=INF){return Q_element(B,E,[](Cl x,Cl y){return min(x,y);},init);}
template<typename T>inline ll sum_(const T B,const T E,ll init=0){return Q_element(B,E,[](Cl x,Cl y){return x+y;},init);}
int Failed=-1,*failed=&Failed;
template<typename T>inline T id0(T B,const T E){


	if(B==E)return failed;
	T P=B++;for(;B!=E;B++)if((*B)>(*P))P=B;return P;
}
template<typename T>inline T id2(T B,const T E){


	if(B==E)return failed;
	T P=B++;for(;B!=E;B++)if((*B)<(*P))P=B;return P;
}
inline vector<int>::iterator id0(vector<int>::iterator B,const vector<int>::iterator E){
	if(B==E)return B;
	vector<int>::iterator P=B++;for(;B!=E;B++)if((*B)>(*P))P=B;return P;
}
inline vector<int>::iterator id2(vector<int>::iterator B,const vector<int>::iterator E){
	if(B==E)return B;
	vector<int>::iterator P=B++;for(;B!=E;B++)if((*B)<(*P))P=B;return P;
}
inline void init(){




}
int n,s[405],L,x,y;
int ans[400005],S;
inline int U(Ci x){return Add(x+1,n);}
inline int D(Ci x){return Add(x+n-1,n);}
inline void Work(Ci u){ans[++S]=u;}
inline void Opr(Ci u,Ci v){
	int x=u;L=0;
	while(x!=v)x=U(x),s[++L]=x;
	s[0]=u;
	Rep(i,L-1,0)Work(s[i]);
	For(i,1,L-1)Work(s[i]);
	Rep(i,L-2,0)Work(s[i]);
	For(i,1,L-2)Work(s[i]);
}
inline void Swap(Ci u,Ci v){
	Opr(u,v);
	Opr(v,u);
	Opr(u,v);
}
inline void id3(){
	L=0;
	For(i,x,n-1)s[L++]=i;
	For(i,0,y)s[L++]=i;
	--L;
	Rep(i,L-1,0)Work(s[i]);
	For(i,0,L/2){
		For(j,i+1,L-i-1)Work(s[j]);
		Rep(j,L-i-2,i)Work(s[j]);
	}
}
inline void id1(){
	L=0;
	For(i,0,n-1)s[L++]=i;
	--L;
	Rep(i,L-1,0)Work(s[i]);
	For(i,0,y){
		For(j,i+1,L-i-1)Work(s[j]);
		Rep(j,L-i-2,i)Work(s[j]);
		if(i==y)For(j,i+1,L-i-2)Work(s[j]);
	}
}
int tmp;
inline void Solver0(){
	L=0;
	For(i,y,x)s[L++]=i;
	--L;
	Rep(i,L-1,0)Work(s[i]);
	For(i,0,L/2){
		For(j,i+1,L-i-1)Work(s[j]);
		Rep(j,L-i-2,i)Work(s[j]);
		if(i==L/2)tmp=s[i];
	}
}
inline void Solver1(){
	L=0;
	For(i,tmp+1,n-1)s[L++]=i;
	For(i,0,tmp-(n&1))s[L++]=i;
	--L;
	Rep(i,L-1,0)Work(s[i]);
	For(I,tmp+1,x){
		int i=I-tmp-1;
		For(j,i+1,L-i-1)Work(s[j]);
		Rep(j,L-i-2,i)Work(s[j]);
		if(I==x)For(j,i+1,L-i-2)Work(s[j]);
	}
}
inline void ypa(){
	n=read();x=n-1;
	if(n<=3){
		For(i,0,(n>>1)-1)
			if(n-1-i-i<=i+i+1)Swap(i,n-i-1);
			else Swap(n-i-1,i);
		write(S,'\n');
		writel(ans+1,ans+1+S);
		return;
	}
	For(i,0,(n>>1)-1)
		if(n-1-i-i<=i+i+1){x=n-i-1,y=i;break;}
	x++,y--;
	id3();id1();id3();
	x--,y++;
	Solver0();Solver1();Solver0();
	write(S,'\n');
	writel(ans+1,ans+1+S);
}
signed main(){init();for(int T=1;T;T--)ypa();flush();return system("pause"),0;}