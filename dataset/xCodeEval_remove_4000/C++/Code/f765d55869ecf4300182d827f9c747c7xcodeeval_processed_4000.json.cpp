









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
















namespace quick_IO {
	inline bool blank(char ch) {return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
  	ll id5=0,id0=10,cs=0;
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
	template<typename T>ll id3(T*x){return readm(x);};
	template<typename T>ll id3(T&x){return readm<T>(x);};
		
		
	template<typename T>void id4(typename Checker2<T>::Type c) {
		for(ll i=1;i<=y-1;i++)pc(' ');pc(c);
	}
	template <typename T> struct Checkers1;
	cl_pp(Checkers1,bool,int,short,long,long long,unsigned int,unsigned long,unsigned long long)
	template <typename T>inline void ycl(typename Checkers1<T>::Type c){x=0;}
	template <typename T>void ycl(T&c){long double ys=0.5;for(ll i=1;i<=x;i++)ys/=10;c+=ys;}
	template<typename T>void id4(typename Checker1<T>::Type c) {


		if(c<0)pc('-'),c=-c;
		ycl<T>(c);
		id1(ll(c),y-(x?x+1:0));c-=ll(c);if(!x)return;
		pc('.');for(ll i=1;i<=x;i++)c*=10,pc(int(c)^48),c-=char(c);
	}
	void id4(const char* c) {
		ll len=std::strlen(c);for(ll i=1;i<=y-len;i++)pc(' ');
		while(*c)pc(*c++); 
	}
	
	
	template<typename T>void id2(T*x){id4(x);id5=0,id0=10;};
	template<typename T>void id2(T x){id4<T>(x);id5=0,id0=10;};
}


















ll readll(void){ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());return x*w;}























ll id6((w,fr,toom,fa,c,lf,rt,up,down),bla[1222222]);
struct pt{
	ll x,y,ct,num;
}p[1222222];
ll find(ll u){
	return u^fa[u]?fa[u]=find(fa[u]):u;
}
ll cmp(ll u,ll v){
	return w[u]<w[v];
}
ll cmpx(pt u,pt v){
	return u.x!=v.x?u.x<v.x:u.y<v.y;
}
ll cmpnum(pt u,pt v){
	return u.num<v.num;
}
ll abs(ll u){
	return mx(u,-u);
}
ll dis(pt u,pt v){
	return mx(abs(u.x-v.x),abs(u.y-v.y));
}
ll mdis(pt u,pt v){
	return mn(abs(u.x-v.x),abs(u.y-v.y));
}
ll cmpy(pt u,pt v){
	return u.y!=v.y?u.y<v.y:u.x<v.x;
}
ll n,top=0,k,tnc;
ll a[5];
const ll inf=0x3f3f3f3f3f3f3f3f;
ll check(ll mid){
	rep(i,0,n)fa[i]=i;
	ll cnt=n;
	frh(i,c,1,top){
		if(w[i]>mid)break;
		if(find(fr[i])^find(toom[i])){
			fa[find(fr[i])]=find(toom[i]);
			cnt--;
		}
	}


	if(cnt==1)return 1;
	if(cnt==2){
		rep(i,1,n)
		rep(j,1,n)
		if(find(i)^find(j))
		if(mdis(p[i],p[j])==0)
		if(dis(p[i],p[j])<=2*mid)
		return 1;
	}
	if(cnt>4)return 0;
	rep(i,n+1,tnc){
		a[0]=inf;
		a[1]=lf[i]&&dis(p[i],p[lf[i]])<=mid?find(lf[i]):inf;
		a[2]=rt[i]&&dis(p[i],p[rt[i]])<=mid?find(rt[i]):inf;
		a[3]=up[i]&&dis(p[i],p[up[i]])<=mid?find(up[i]):inf;
		a[4]=down[i]&&dis(p[i],p[down[i]])<=mid?find(down[i]):inf;








		std::sort(a,a+5);
		ll su=std::unique(a,a+5)-a;
		if(su>=cnt+1)return 1;
	}
	return 0;
}
std::map<std::pair<ll,ll>,ll>ma;
int main(){
	

	ll ans=0;








	rill(n);
	rep(i,1,n)rill(p[i].x,p[i].y),p[i].num=i,ma[std::make_pair(p[i].x,p[i].y)]=1;
	tnc=n;
	rep(i,1,n)
	rep(j,1,n)
	if(!ma.count(std::make_pair(p[i].x,p[j].y))){
		ma[std::make_pair(p[i].x,p[j].y)]=1;
		p[++tnc].x=p[i].x,p[tnc].y=p[j].y,
		p[tnc].num=tnc,p[tnc].ct=1;
	}


	std::sort(p+1,p+tnc+1,cmpx);
	ll last=0;
	rep(i,1,tnc)
	if(p[i].ct==0){
		per(j,i-1,0)
		if(p[j].ct==1&&p[i].x==p[j].x)rt[p[j].num]=p[i].num;
		else break;
		rep(j,i+1,tnc)
		if(p[j].ct==1&&p[i].x==p[j].x)lf[p[j].num]=p[i].num;
		else break;
		if(p[i].x==p[last].x){
			w[++top]=p[i].y-p[last].y,fr[top]=p[i].num,toom[top]=p[last].num,c[top]=top;
		}
		last=i;
	}
	std::sort(p+1,p+tnc+1,cmpy);
	last=0;
	rep(i,1,tnc)
	if(p[i].ct==0){
		per(j,i-1,0)
		if(p[j].ct==1&&p[i].y==p[j].y)down[p[j].num]=p[i].num;
		else break;
		rep(j,i+1,tnc)
		if(p[j].ct==1&&p[i].y==p[j].y)up[p[j].num]=p[i].num;
		else break;
		if(p[i].y==p[last].y){
			w[++top]=p[i].x-p[last].x,fr[top]=p[i].num,toom[top]=p[last].num,c[top]=top;
		}
		last=i;
	}
	std::sort(c+1,c+top+1,cmp);
	std::sort(p+1,p+tnc+1,cmpnum);
	ll l=0,r=111111444555111444ll;
	ans=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	writeln(ans);
	return 0;
}