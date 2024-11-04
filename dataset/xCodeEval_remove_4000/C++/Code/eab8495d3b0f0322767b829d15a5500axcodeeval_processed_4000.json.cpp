









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
	    if (ch=='.') for (ch=gc();isdigit(ch);ch=gc()) tmp/=10.0,x+=tmp*(ch-'0');if (sign) x=-x;lastc=ch;return 1;
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



























ll f[14][1<<14],nt[1<<14];
struct x2{
	ll x,y;
}e[1333];
struct x3{
	ll x,y,z;
}lca[1333];
template<typename T>
int cmp(T x,T y){
	return x.x<y.x;
}


const ll mod=1e9+7,k=114599;
ll km[114514];
struct calc{
	calc(){
		km[0]=1;
		rep(i,1,114500)km[i]=km[i-1]*k%mod;
	}
};
const calc calcer;
inline add(ll x,ll y){
	ll c=x+y;
	return c>=mod?c-mod:c;
}
struct hash{
	ll kc[2555];
	hash(const char*f){
		ll lenf=strlen(f+1);
		kc[0]=0;
		rep(i,1,lenf)kc[i]=(kc[i-1]*k+f[i]-96)%mod;
	}
	ll operator()(ll l,ll r)const{
		if(l>r)return 0;
		return add(mod-kc[l-1]*km[r-l+1]%mod,kc[r]);
	}
};
ll len1,len2;
typedef char str[114514];
str s1,s2,s3,s4;


struct mint{
	ll x;
	operator ll()const{
		return x;
	}
	mint(ll y=0):x(y){x>=mod&&(x%=mod);}
	mint operator+(const mint&b)const{
		ll c=x+b.x;
		return c>=mod?c-mod:c;
	}
	mint&operator+=(const mint&b){x+=b.x,x>=mod&&(x-=mod);return*this;}
	mint operator++(int){ll lx=x;++x>=mod&&(x=0);return mint(lx);}
	mint operator--(int){ll lx=x;--x<0&&(x=mod-1);return mint(lx);}
	mint&operator++(){++x>=mod&&(x=0);return*this;}
}ans;
typedef mint ar[2555][2555];
ar f1,f2,f12,f21;
void work(){
	hash h1(s1),h2(s2),h3(s3),h4(s4);
	memset(f1,0,sizeof f1);
	memset(f2,0,sizeof f2);
	memset(f12,0,sizeof f12);
	memset(f21,0,sizeof f21);
	rep(i,0,len1){
		rep(j,0,min(len2/2,(ll)i))
		if(j!=1){
			if(h2(i-j+1,i)==h4(len2-j+1,len2)&&h1(i-j+1,i)==h3(j+1,2*j)){
				f21[i][j*2]++;


			}
			if(h1(i-j+1,i)==h4(len2-j+1,len2)&&h2(i-j+1,i)==h3(j+1,2*j)){
				f12[i][j*2]++;


			}
		}
		rep(j,1,len2){
			if(s1[i]==s3[j])f1[i][j]+=f1[i-1][j-1]+f21[i-1][j-1],f21[i][j]+=f2[i][j-1];
			if(s2[i]==s3[j])f2[i][j]+=f2[i-1][j-1]+f12[i-1][j-1],f12[i][j]+=f1[i][j-1];








		}
	}
	rep(i,0,len1)
	rep(j,0,min(len2/2-1,len1-i))
	if(j!=1){
		if(h2(i+1,i+j)==h4(1,j)&&h1(i+1,i+j)==h3(len2-2*j+1,len2-j)){
			ans+=f21[i][len2-j*2]+f1[i][len2-j*2];


		}
		if(h1(i+1,i+j)==h4(1,j)&&h2(i+1,i+j)==h3(len2-2*j+1,len2-j)){
			ans+=f12[i][len2-j*2]+f2[i][len2-j*2];


		}
	}
}
int main(){
	

	read(s1+1,s2+1,s3+1);
	len1=strlen(s1+1),len2=strlen(s3+1);
	rep(i,1,len2)s4[i]=s3[len2-i+1];
	work();
	rep(i,1,len1)if(i<len1-i+1)std::swap(s1[i],s1[len1-i+1]),std::swap(s2[i],s2[len1-i+1]);
	work();


	if(len2==2)rep(i,1,len1){
		if(s3[1]==s1[i]&&s3[2]==s2[i])ans--;
		if(s3[1]==s2[i]&&s3[2]==s1[i])ans--;
	}
	if(len2==1)rep(i,1,len1){
		if(s3[1]==s1[i])ans++;
		if(s3[1]==s2[i])ans++;
	}
	writeln((ll)ans);
	return 0;
}

