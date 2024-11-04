






using int64=long long;
using uchar=unsigned char;

constexpr int id13(262144);
constexpr int p(998244353);
constexpr int hfp(p>>1);
constexpr int proot(3);

namespace IOManager{
	constexpr int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;

	struct IOManager{
		inline char gc()
			{return(ibuf==tbuf)&&(tbuf=(ibuf=buf)+fread(buf,1,FILESZ,stdin),ibuf==tbuf)?EOF:*ibuf++;}

		template<class _Tp>
			inline operator _Tp(){
				_Tp s=0u;char c=gc();
				for(;c<48;c=gc());
				for(;c>47;c=gc())
					s=(_Tp)(s*10u+c-48u);
				return s;
			}
	};
}IOManager::IOManager io;

inline int rd(){
	static int _;
	return scanf("%d",&_),_;
}

namespace my_template{

	template<class _Tp>
		inline void swap(_Tp&x,_Tp&y)
			{_Tp z=x;x=y;y=z;}

	template<class _Tp>
		inline int fpow(_Tp v,int n){
			int pw=1;
			for(;n;n>>=1,v=(int64)v*v%p)
				if(n&1)pw=(int64)pw*v%p;
			return pw;
		}

	template<class _Tpx,class _Tpy>
		inline void inc(_Tpx&x,const _Tpy&y)
			{(p-y<=x)?(x+=y-p):(x+=y);}
	template<class _Tpx,class _Tpy>
		inline void dec(_Tpx&x,const _Tpy&y)
			{x-=y;(x<0)&&(x+=p);}

	template<class _Tpx,class _Tpy>
		inline _Tpx pls(const _Tpx&x,const _Tpy&y)
			{return(x<p-y)?(x+y):(x-p+y);}
	template<class _Tpx,class _Tpy>
		inline _Tpx sub(const _Tpx&x,const _Tpy&y)
			{return(x<y)?(x-y+p):(x-y);}

	template<class _Tp>
		inline _Tp gcd(const _Tp&x,const _Tp&y)
			{return y?gcd(y,x%y):x;}
	template<class _Tp>
		inline _Tp lcm(const _Tp&x,const _Tp&y)
			{return x/gcd(x,y)*y;}
	template<class _Tp,class _Tpx>
		inline void id5(const _Tp&x,const _Tp&y,_Tpx&a,_Tpx&b){
			if(y)id5(y,x%y,b,a),b-=x/y*a;
			else a=1,b=0;
		}

	inline int inv(const int&v,const int&mp){
		int x,y;
		id5(v,mp,x,y);
		return x<0?x+mp:x;
	}

	template<class _Tp>
		inline int div2(const _Tp&v)
			{return(v&1)?(v+p)>>1:(v>>1);}

	template<class _Tpx,class _Tpy>
		inline _Tpx Min(const _Tpx&x,const _Tpy&y)
			{return x<y?x:y;}
	template<class _Tpx,class _Tpy>
		inline _Tpx Max(const _Tpx&x,const _Tpy&y)
			{return x>y?x:y;}

	template<class _Tpx,class _Tpy>
		inline void chkMin(_Tpx&x,const _Tpy&y)
			{(x>y)&&(x=y);}
	template<class _Tpx,class _Tpy>
		inline void chkMax(_Tpx&x,const _Tpy&y)
			{(x<y)&&(x=y);}

	template<class _Tpx,class _Tpy>
		inline bool id6(_Tpx&x,const _Tpy&y)
			{return(x>y)&&(x=y,1);}
	template<class _Tpx,class _Tpy>
		inline bool id10(_Tpx&x,const _Tpy&y)
			{return(x<y)&&(x=y,1);}
}

namespace Hashmap{
	using namespace my_template;

	template<class key_tp,class val_tp>
		struct link_t{
			key_tp key;
			val_tp val;
			link_t<key_tp,val_tp>*las;

			link_t():key(key_tp(0)),val(val_tp(0)),las(nullptr){}

			inline link_t* init(const key_tp&_key,const val_tp&_val,link_t<key_tp,val_tp>*const&ls)
				{return key=_key,val=_val,las=ls,this;}
		};

	template<class key_tp,class val_tp>
		struct hashmap{
			static constexpr int hashp=100007;

			using link=link_t<key_tp,val_tp>;

			link lnk_pool[hashp*10];
			link *lnk[hashp],*id12;

			hashmap():id12(lnk_pool-1){}

			inline val_tp&operator[](const key_tp&key){
				const val_tp hash_key=key%hashp;
				for(link*o=lnk[hash_key];o;o=o->las)
					if(o->key==key)
						return o->val;
				lnk[hash_key]=(++id12)->init(key,0,lnk[hash_key]);
				return lnk[hash_key]->val;
			}

			inline bool count(const key_tp&key){
				const val_tp hash_key=key%hashp;
				for(link*o=lnk[hash_key];o;o=o->las)
					if(o->key==key)
						return true;
				return false;
			}

			inline void clear(){
				id12=lnk_pool-1;
				memset(lnk,0,sizeof lnk);
			}
		};
}

namespace poly{

	using namespace my_template;
	using namespace Hashmap;

	using poly_t=int[id13];
	using poly=int*const;

	inline int id8(const int&n){
		int pw2=1;
		for(;pw2<n;pw2+=pw2);
		return pw2;
	}

	int wn[id13],
		iwn[id13],
		inv[id13+1];
	constexpr int rt_blk(31596);
	constexpr int id14(393213064);
	Hashmap::hashmap<int,int>lg;

	inline void polyinit(){
		const int ob=fpow(proot,(p-1)/id13);
		const int iob=fpow(ob,p-2);
		wn[0]=iwn[0]=inv[0]=inv[1]=1;
		for(int i=1,v=1,iv=1;i!=id13;++i){
			v=(int64)v*ob%p;wn[i]=v;
			iv=(int64)iv*iob%p;iwn[i]=iv;
		}
		

		


		

		

		

	}

	inline int root(const int&v,const int&k){
		if(k==1||v<2)
			return v;
		for(int t=0,pw=v;t<p;t+=rt_blk,pw=(int64)pw*id14%p)
			if(lg.count(pw))
				return fpow(proot,(int64)(t+lg[pw])*my_template::inv(k,p-1)%(p-1));
		return-1;
	}

	void DFT(poly&A,const int&deg){
		for(int i=0,j=0;i!=deg;++i){
			if(i<j)swap(A[i],A[j]);
			for(int k=deg>>1;(j^=k)<k;k>>=1);
		}
		int*const td=A+deg;
		for(int l=1,tp=id13>>1;l<deg;l+=l,tp>>=1)
			for(int*i=A,z;i<td;i+=l+l)
				for(int j=0,*w=wn;j!=l;++j,w+=tp)
					z=(int64)i[j+l]**w%p,
					i[j+l]=sub(i[j],z),
					inc(i[j],z);
	}
	void IDFT(poly&A,const int&deg){
		for(int i=0,j=0;i!=deg;++i){
			if(i<j)swap(A[i],A[j]);
			for(int k=deg>>1;(j^=k)<k;k>>=1);
		}
		int*const td=A+deg;
		for(int l=1,tp=id13>>1;l<deg;l+=l,tp>>=1)
			for(int*i=A,z;i<td;i+=l+l)
				for(int j=0,*w=iwn;j!=l;++j,w+=tp)
					z=(int64)i[j+l]**w%p,
					i[j+l]=sub(i[j],z),
					inc(i[j],z);

		const int invdeg=fpow(deg,p-2);
		for(int i=0;i!=deg;++i)
			A[i]=(int64)A[i]*invdeg%p;
	}

	inline void cp(const int*const&sl,const int*const&sr,int*const&dl,int*const&dr){
		std::copy(sl,sr,dl);
		if(sr-sl<dr-dl)
			std::fill(dl+(sr-sl),dr,0);
	}

	void polyder(const poly&f,poly&df,const int&n){
		for(int i=1;i!=n;++i)
			df[i-1]=(int64)f[i]*i%p;
		df[n-1]=0;
	}

	void polyint(const poly&f,poly&intf,const int&n){
		for(int i=n-1;i;--i)
			intf[i]=(int64)f[i-1]*inv[i]%p;
		intf[0]=0;
	}

	void polyinv(const poly&h,poly&f,const int&n){
		static poly_t inv_t;
		std::fill(f,f+n+n,0);
		f[0]=fpow(h[0],p-2);
		for(int t=1;(1<<t)<=n;++t){
			const int deg1=1<<t,deg2=deg1<<1;
			cp(h,h+deg1,inv_t,inv_t+deg2);

			DFT(f,deg2);DFT(inv_t,deg2);
			for(int i=0;i!=deg2;++i)
				f[i]=(int64)f[i]*sub(2ll,(int64)inv_t[i]*f[i]%p)%p;
			IDFT(f,deg2);

			std::fill(f+deg1,f+deg2,0);
		}
	}

	void polyln(const poly&h,poly&f,const int&n){
		static poly_t ln_t;
		assert(h[0]==1);
		const int n2=n<<1;

		polyder(h,f,n);
		std::fill(f+n,f+n2,0);
		polyinv(h,ln_t,n);

		DFT(f,n2);DFT(ln_t,n2);
		for(int i=0;i!=n2;++i)
			f[i]=(int64)f[i]*ln_t[i]%p;
		IDFT(f,n2);

		polyint(f,f,n);
		std::fill(f+n,f+n2,0);
	}

	void polyexp(const poly&h,poly&f,const int&n){
		static poly_t exp_t;
		assert(h[0]==0);
		std::fill(f,f+n+n,0);
		f[0]=1;
		for(int t=1;(1<<t)<=n;++t){
			const int deg1=1<<t,deg2=deg1<<1;

			polyln(f,exp_t,deg1);
			exp_t[0]=sub(h[0]+1,exp_t[0]);
			for(int i=1;i!=deg1;++i)
				exp_t[i]=sub(h[i],exp_t[i]);
			std::fill(exp_t+deg1,exp_t+deg2,0);

			DFT(f,deg2);DFT(exp_t,deg2);
			for(int i=0;i!=deg2;++i)
				f[i]=(int64)f[i]*exp_t[i]%p;
			IDFT(f,deg2);

			std::fill(f+deg1,f+deg2,0);
		}
	}

	void polydiv(const poly&f,const int&n,const poly&g,const int&m,poly&Q,poly&R){
		static poly_t div_t;

		const int res=n-m+1;
		const int deg1=id8(res+res);

		std::reverse_copy(g,g+m,Q);
		if(m<deg1)
			std::fill(Q+m,Q+deg1,0);
		polyinv(Q,div_t,res);

		std::reverse_copy(f+m-1,f+n,Q);
		std::fill(Q+res,Q+deg1,0);

		DFT(Q,deg1);DFT(div_t,deg1);
		for(int i=0;i!=deg1;++i)
			Q[i]=(int64)Q[i]*div_t[i]%p;
		IDFT(Q,deg1);

		std::reverse(Q,Q+res);
		std::fill(Q+res,Q+deg1,0);

		const int deg2=id8(n);

		cp(Q,Q+res,R,R+deg2);
		cp(g,g+m,div_t,div_t+deg2);

		DFT(R,deg2);DFT(div_t,deg2);
		for(int i=0;i!=deg2;++i)
			R[i]=(int64)R[i]*div_t[i]%p;
		IDFT(R,deg2);

		for(int i=0;i!=m;++i)
			R[i]=sub(f[i],R[i]);
		std::fill(R+m-1,R+deg2,0);
	}

	void id2(const poly&f,const int&n,const poly&g,const int&m,poly&R){
		static poly_t mod_t;

		const int res=n-m+1;
		const int deg1=id8(res+res);

		std::reverse_copy(g,g+m,R);
		if(m<deg1)
			std::fill(R+m,R+deg1,0);
		polyinv(R,mod_t,res);

		std::reverse_copy(f+m-1,f+n,R);
		std::fill(R+res,R+deg1,0);

		DFT(R,deg1);DFT(mod_t,deg1);
		for(int i=0;i!=deg1;++i)
			R[i]=(int64)R[i]*mod_t[i]%p;
		IDFT(R,deg1);

		std::reverse(R,R+res);
		std::fill(R+res,R+deg1,0);

		const int deg2=id8(n);

		cp(g,g+m,mod_t,mod_t+deg2);

		DFT(R,deg2);DFT(mod_t,deg2);
		for(int i=0;i!=deg2;++i)
			R[i]=(int64)R[i]*mod_t[i]%p;
		IDFT(R,deg2);

		for(int i=0;i!=m;++i)
			R[i]=sub(f[i],R[i]);
		std::fill(R+m-1,R+deg2,0);
	}

	void id3(const poly&h,poly&f,const int&n){
		static poly_t sqrt_t,inv_t;
		std::fill(f,f+n+n,0);
		f[0]=root(h[0],2);
		for(int t=1;(1<<t)<=n;++t){
			const int deg1=1<<t,deg2=deg1<<1;

			polyinv(f,sqrt_t,deg1);

			DFT(f,deg1);
			for(int i=0;i!=deg1;++i)
				f[i]=(int64)f[i]*f[i]%p;
			IDFT(f,deg1);
			for(int i=0;i!=deg1;++i)
				inc(f[i],h[i]);

			DFT(f,deg2);DFT(sqrt_t,deg2);
			for(int i=0;i!=deg2;++i)
				f[i]=(int64)f[i]*sqrt_t[i]%p;
			IDFT(f,deg2);
			for(int i=0;i!=deg1;++i)
				f[i]=div2(f[i]);

			std::fill(f+deg1,f+deg2,0);
		}
	}

	void id9(const poly&h,poly&f,const int&n){
		static constexpr int inv3(332748118);
		static poly_t id1,id7;
		if(n==1)
			return(void)(f[0]=root(h[0],3));
		id9(h,f,(n+1)>>1);

		const int deg=id8(n+n+3);

		cp(f,f+((n+1)>>1),id1,id1+deg);

		DFT(id1,deg);
		for(int i=0;i!=deg;++i)
			id1[i]=(int64)id1[i]*id1[i]%p;
		IDFT(id1,deg);

		polyinv(id1,id7,n);

		cp(h,h+n,id1,id1+deg);

		DFT(id1,deg);DFT(id7,deg);
		for(int i=0;i!=deg;++i)
			id1[i]=(int64)id1[i]*id7[i]%p;
		IDFT(id1,deg);

		for(int i=(n+1)>>1;i!=n;++i)
			f[i]=(int64)(f[i]+f[i]+id1[i])*inv3%p;
	}

	void id4(const poly&h,poly&f,const int&k,const int&n){
		static poly_t pow_t;
		if(h[0]==1){
			polyln(h,pow_t,n);
			for(int i=0;i!=n;++i)
				pow_t[i]=(int64)pow_t[i]*k%p;
			polyexp(pow_t,f,n);
		}else{
			int lw=0;
			for(;!h[lw];++lw);

			if(n<=lw*k)
				return std::fill(f,f+n,0);

			const int low=lw,id11=fpow(h[low],p-2);

			for(int i=0;i!=n-low;++i)
				pow_t[i]=(int64)h[i+low]*id11%p;
			std::fill(pow_t+n-low,pow_t+n,0);

			polyln(pow_t,f,n);
			for(int i=0;i!=n;++i)
				f[i]=(int64)f[i]*k%p;
			polyexp(f,pow_t,n);

			const int pwlow=low*k,id0=fpow(h[low],k);
			for(int i=0;i!=n-pwlow;++i)
				f[i+pwlow]=(int64)pow_t[i]*id0%p;
			std::fill(f,f+pwlow,0);
		}
	}

	void polyroot(const poly&h,poly&f,const int&k,const int&n){
		static poly_t root_t;
		const int invk(fpow(k,p-2));
		if(h[0]==1){
			polyln(h,root_t,n);
			for(int i=0;i!=n;++i)
				root_t[i]=(int64)root_t[i]*invk%p;
			polyexp(root_t,f,n);
		}else{
			int lw=0;
			for(;!h[lw];++lw);

			assert(lw%k==0);

			const int low=lw,id11=fpow(h[low],p-2);

			for(int i=0;i!=n-low;++i)
				root_t[i]=(int64)h[i+low]*id11%p;
			std::fill(root_t+n-low,root_t+n,0);

			polyln(root_t,f,n);
			for(int i=0;i!=n;++i)
				f[i]=(int64)f[i]*invk%p;
			polyexp(f,root_t,n);

			const int pwlow=low/k,id0=root(h[low],k);
			for(int i=0;i!=n-pwlow;++i)
				f[i+pwlow]=(int64)root_t[i]*id0%p;
			std::fill(f,f+pwlow,0);
		}
	}
}

using namespace poly;

poly_t C,rt;

int main(){
	polyinit();

	int n=io;const int m((int)io+1),deg=id8(m);

	C[0]=1;
	for(int i;n;--n)
		if((i=io)<m)
			C[i]=998244349;

	id3(C,rt,deg);
	inc(rt[0],1);
	polyinv(rt,C,deg);

	for(int i=1;i!=m;++i)
		printf("%d\n",C[i]<=hfp?C[i]+C[i]:(C[i]+C[i]-p));

	return 0;
}
