









x,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
0)

 _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,\
_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,\
_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,\
_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,\
_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,\
_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,\
_60,_61,_62,_63,_64,_65,_66,_67,_68,_69,\
_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,\
_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,\
_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,\
_100,x...) _100





































typedef long long ll;
typedef long double ld;
typedef unsigned long long ull; 
















namespace quick_IO {
	inline bool blank(char ch) {return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
  	ll id6=0,id0=6,cs=0;
  	inline char gc() {return getchar();}
  	inline void pc(char c) {cs?fprintf(stderr,"%c",c):putchar(c);}
	template <typename T> struct Checker1;
	cl_pp(Checker1,bool,int,short,long,long long,unsigned int,unsigned long,unsigned short,unsigned long long,double,long double,float)
	template <typename T> struct Checker2;
	cl_pp(Checker2,char)
	char lastc=-2;
	template <typename T>inline ll readm(typename Checker1<T>::Type&x) {
	    register double tmp=1;register bool sign=0; x=0;register char ch=lastc==-2?gc():lastc;
	    for (;!isdigit(ch);ch=gc()) if(ch=='-') sign=1;else if(ch==EOF) return 0;for (;isdigit(ch);ch=gc()) x=x*10+(ch-'0');
	    if (ch=='.') for (ch=gc();isdigit(ch);ch=gc()) tmp/=10.0,x+=tmp*(ch-'0');if (sign) x=-x;
	    lastc=ch;return 1;
	}
	template <typename T>inline ll readm(typename Checker2<T>::Type&c) {
		for(c=lastc==-2?gc():lastc;blank(c);c=gc());if(c==EOF)return 0;
		lastc=-2;return 1;
	}
  	inline ll readm(char *s)
	{
    	register char ch=lastc==-2?gc():lastc;for (;blank(ch)&&~ch;ch=gc())if(ch==EOF)return 0;
		for (;~ch&&!blank(ch);ch=gc()) *s++=ch;*s=0;lastc=-2;return 1;
  	}
	void id1(ll c,ll x) {
		if(c<0)pc('-'),c=-c,x--;
		if(c<10)return ({for(ll i=1;i<=x-1;i++)pc(' ');pc(c^48);void(0);});
		id1(c/10,x-1);pc((c%10)^48);
	}
	void id5(ull c,ll x) {
		if(c<10)return ({for(ll i=1;i<=x-1;i++)pc(' ');pc(c^48);void(0);});
		id5(c/10,x-1);pc((c%10)^48);
	}
	template<typename T>ll id3(T*x){return readm(x);};
	template<typename T>ll id3(T&x){return readm<T>(x);};
		
		
	template<typename T>void id4(typename Checker2<T>::Type c) {
		for(ll i=1;i<=y-1;i++)pc(' ');pc(c);
	}
	template <typename T> struct Checkers1;
	template <typename T> struct Checkers2;
	cl_pp(Checkers1,bool,int,short,long,long long)
	cl_pp(Checkers2,unsigned int,unsigned long,unsigned long long)
	template <typename T>inline void ycl(typename Checkers1<T>::Type&c){if(c<0)pc('-'),c=-c;x=0;}
	template <typename T>inline void ycl(typename Checkers2<T>::Type&c){x=0;}
	template <typename T>void ycl(T&c){if(c<0)putchar('-'),c=-c;long double ys=0.5;for(ll i=1;i<=x;i++)ys/=10;c+=ys;}
	template <typename T>void ycl2(T&c){id5(ull(c),y-(x?x+1:0));}
	template <typename T>void ycl2(typename Checkers2<T>::Type c){id5(ull(c),y-(x?x+1:0));}
	template<typename T>void id4(typename Checker1<T>::Type c) {
		ycl<T>(c);
		ycl2<T>(c);
		c-=ll(c);if(!x)return;
		pc('.');for(ll i=1;i<=x;i++)c*=10,pc(int(c)^48),c-=char(c);
	}
	void id4(const char* c) {
		ll len=std::strlen(c);for(ll i=1;i<=y-len;i++)pc(' ');
		while(*c)pc(*c++); 
	}
	
	
	template<typename T>void id2(T*x){id4(x);id6=0,id0=6;};
	template<typename T>void id2(T x){id4<T>(x);id6=0,id0=6;};
	template<typename T>inline const T&max(const T&a,const T&b){return a>b?a:b;}
	template<typename T>inline T&max(T&a,T&b){return a>b?a:b;}
	template<typename T>inline const T&min(const T&a,const T&b){return a<b?a:b;}
	template<typename T>inline T&min(T&a,T&b){return a<b?a:b;}
}


















ll readll(void){ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());return x*w;}

























const ll mod=1e9+7;
inline void add(ll&x,ll y){
	x+=y;
	x>=mod&&(x-=mod);
}
inline void md(ll&x){
	static ll mod2=mod*mod;
	if(x>mod2)x-=mod2;
}
struct jz{
	ll val[103][103],len;
	int is_vec;
	jz(register ll n):len(n),is_vec(1){
		memset(val,0,sizeof val);
	}
	jz(const jz&b):len(b.len),is_vec(b.is_vec){
		memcpy(val,b.val,sizeof b.val);
	}
	jz&operator=(const jz&b){
		len=b.len;
		memcpy(val,b.val,sizeof b.val);
		return*this;
	}
	const ll*operator[](register ll b)const{
		return val[b];
	}
	ll*operator[](register ll b){
		b^1&&(is_vec=0);
		return val[b];
	}
	jz operator*(const jz&b)const{
		jz res(len);
		res.is_vec=is_vec;
		if(is_vec){
			rep(k,1,len)
			rep(j,1,len){
				md(res[1][j]+=val[1][k]*b[k][j]);
			}
			rep(i,1,len)res[1][i]%=mod;
			return res;
		}
		rep(k,1,len)
			rep(i,1,len)
			rep(j,1,len){
				md(res[i][j]+=val[i][k]*b[k][j]);
			}
		rep(i,1,len)
		rep(j,1,len){
			res[i][j]%=mod;
		}
		return res;
	}
};
jz mul_pow(jz ans,jz x,ll b){
	while(b){
		(b&1)&&(ans=ans*x,0);
		x=x*x;


		b>>=1;
	}
	return ans;
}
int main(){
	

	ll rill(n,x);
	static jz f(102),g(102);
	rep(i,1,n){
		ll rill(s);
		f[1+s-1][1]++;
	}
	rep(i,1,100)f[i][i+1]=1;
	f[1][102]=1;
	f[102][102]=1;
	g[1][1]=1;


	writeln(mul_pow(g,f,x+1)[1][102]);
	return 0;
}