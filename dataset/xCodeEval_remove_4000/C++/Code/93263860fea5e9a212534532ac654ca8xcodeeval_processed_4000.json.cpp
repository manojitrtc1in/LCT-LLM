


using namespace std;






typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;


struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;









inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}









const int mod=998244353;
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}


const int proot=3;

const int id21=18;
const int id14=1<<id21;
const int FFTmx=id14+233;

const int FFTbit=15;




const int id3=FFTmx;
ll inv[id3],fac[id3],ifac[id3];




void comb_init()
{
	fac[0]=1;
	for(int i=1;i<id3;i++)fac[i]=fac[i-1]*i%mod;
	ifac[id3-1]=qpow(fac[id3-1],mod-2);
	for(int i=id3-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	inv[1]=1;
	for(int i=2;i<id3;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}
int id0(int x)
{
	while(x!=(x&(-x)))x+=x&(-x);
	return x;
}



int fsz,w_pre[FFTmx];
void FFTinit(int sz)
{
	fsz=id0(sz);
	assert(fsz<=id14);
}
typedef unsigned long long ull;
void FFT(int a[],int coef)
{
	static ull f_a[FFTmx];
	static int w[FFTmx];
	for(int i=0,j=0;i<fsz;i++)
	{
		f_a[j]=a[i]<0?a[i]+mod:a[i];
		for(int l=fsz>>1;(j^=l)<l;l>>=1);
	}
	const ull md2=1ull*mod*mod;
	for(int l=1;l<fsz;l<<=1)
	{
		int l2=l<<1,u=id14/l2;
		if(coef==1)for(int j=0,j2=0;j<l;j++,j2+=u)w[j]=w_pre[j2];
		else for(int j=0,j2=id14;j<l;j++,j2-=u)w[j]=w_pre[j2];
		for(int i=0;i<fsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				ull tmp=f_a[i+j+l]%mod*w[j];
				f_a[i+j+l]=f_a[i+j]+md2-tmp;
				f_a[i+j]+=tmp;
			}
		}
		if(l==(1<<16))for(int j=0;j<fsz;j++)f_a[j]%=mod;
	}
	for(int i=0;i<fsz;i++)a[i]=f_a[i]%mod;
	if(coef==-1)
	{
		int inv=qpow(fsz,mod-2);
		for(int i=0;i<fsz;i++)a[i]=1ll*a[i]*inv%mod;
	}
}
void id18()
{
	w_pre[0]=1;
	int ww=qpow(proot,(mod-1)/id14);
	for(int i=1;i<=id14;i++)w_pre[i]=1ll*w_pre[i-1]*ww%mod;
}


void id19(int a[],int an,int b[],int bn,int c[],int cn=-1)
{
	static int mul_a[FFTmx],mul_b[FFTmx];
	if(cn==-1)cn=an+bn;
	an=min(an,cn);bn=min(bn,cn);
	if(1ll*an*bn<=4096)
	{
		for(int i=0;i<an+bn;i++)mul_a[i]=0;
		for(int i=0;i<an;i++)
			for(int j=0;j<bn;j++)
				mul_a[i+j]=(mul_a[i+j]+1ll*a[i]*b[j])%mod;
		for(int i=0;i<cn;i++)c[i]=mul_a[i];
		return;
	}
	FFTinit(an+bn);
	for(int i=0;i<fsz;i++)mul_a[i]=i<an?a[i]:0;
	for(int i=0;i<fsz;i++)mul_b[i]=i<bn?b[i]:0;
	FFT(mul_a,1);
	FFT(mul_b,1);
	for(int i=0;i<fsz;i++)mul_a[i]=1ll*mul_a[i]*mul_b[i]%mod;
	FFT(mul_a,-1);
	for(int i=0;i<cn;i++)c[i]=mul_a[i];
}





const double pi=acos(-1);
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point conj()const{return point(x,-y);}
};
int fsz;
point w_pre[FFTmx];
void id18()
{
	for(int i=0;i<=id14;i++)w_pre[i]=point(cos(2.0/id14*i*pi),sin(2.0/id14*i*pi));
}
void FFTinit(int n)
{
	fsz=id0(n);
	assert(fsz<=id14);
}
void FFT(point a[],int coef)
{
	static point w[FFTmx];
	for(int i=0,j=0;i<fsz;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int l=fsz>>1;(j^=l)<l;l>>=1);
	}
	for(int l=1;l<fsz;l<<=1)
	{
		int l2=l<<1,u=id14/l2;
		if(coef==1)for(int j=0,j2=0;j<l;j++,j2+=u)w[j]=w_pre[j2];
		else for(int j=0,j2=id14;j<l;j++,j2-=u)w[j]=w_pre[j2];
		for(int i=0;i<fsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+l+j]*w[j];
				a[i+l+j]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<fsz;i++)a[i]=a[i]*(1.0/fsz);
	}
}


void id19(int a[],int an,int b[],int bn,int c[],int cn=-1)
{
	static point tl[FFTmx],tr[FFTmx],ta[FFTmx],tb[FFTmx];
	if(cn==-1)cn=an+bn;
	an=min(an,cn);bn=min(bn,cn);
	FFTinit(an+bn);
	int msk=(1<<FFTbit)-1;
	for(int i=0;i<fsz;i++)
	{
		ta[i]=i<an?point((a[i]>=0?a[i]:a[i]+mod)&msk,(a[i]>=0?a[i]:a[i]+mod)>>FFTbit):0;
		tb[i]=i<bn?point((b[i]>=0?b[i]:b[i]+mod)&msk,(b[i]>=0?b[i]:b[i]+mod)>>FFTbit):0;
	}
	FFT(ta,1);ta[fsz]=ta[0];
	FFT(tb,1);tb[fsz]=tb[0];
	for(int i=0;i<fsz;i++)
	{
		point a0=(ta[i]+ta[fsz-i].conj())*point(+0.5,0),a1=(ta[i]-ta[fsz-i].conj())*point(0,-0.5);
		point b0=(tb[i]+tb[fsz-i].conj())*point(+0.5,0),b1=(tb[i]-tb[fsz-i].conj())*point(0,-0.5);
		tl[i]=a0*b0+a0*b1*point(0,1);
		tr[i]=a1*b0+a1*b1*point(0,1);
	}
	FFT(tl,-1);
	FFT(tr,-1);
	for(int i=0;i<fsz;i++)
	{
		c[i]=(ll(tl[i].x+0.5)+
		    ((ll(tr[i].y+0.5)%mod)<<(FFTbit+FFTbit))+
	       (((ll(tl[i].y+0.5)+ll(tr[i].x+0.5))%mod)<<FFTbit))%mod;
	}
}






void dotmul(int a[],int an,int b[],int bn,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=1ll*(i<an?a[i]:0)*(i<bn?b[i]:0)%mod;
}
void dotmul(int a[],int b[],int c[],int sz){dotmul(a,sz,b,sz,c,sz);}

void polyadd(int a[],int an,int b[],int bn,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=((i<an?a[i]:0)+(i<bn?b[i]:0))%mod;
}
void polyadd(int a[],int b[],int c[],int sz){polyadd(a,sz,b,sz,c,sz);}

void id1(int a[],int an,int b[],int bn,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=((i<an?a[i]:0)-(i<bn?b[i]:0)+mod)%mod;
}
void id1(int a[],int b[],int c[],int sz){id1(a,sz,b,sz,c,sz);}

void id16(int a[],int an,int b[],int bn)
{
	for(int i=0;i<bn;i++)b[i]=(mod-(i<an?a[i]:0))%mod;
}
void id16(int a[],int n,int b[]){id16(a,n,b,n);}
void id16(int a[],int n){id16(a,n,a,n);}

void id10(int a[],int n){for(int i=0;i<n;i++)a[i]=0;}
void id10(int a[],int l,int r){for(int i=l;i<r;i++)a[i]=0;}

void polyset(int a[],int an,int b[],int bn){for(int i=0;i<bn;i++)b[i]=i<an?a[i]:0;}

void id17(int a[],int an,int b,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=1ll*(i<an?a[i]:0)*b%mod;
}
void id17(int a[],int b,int c[],int n){id17(a,n,b,c,n);}
void id17(int a[],int b,int n){id17(a,n,b,a,n);}

void id11(int a[],int an,int b[],int bn)
{
	for(int i=0;i<bn;i++)b[i]=1ll*(i+1<an?a[i+1]:0)*(i+1)%mod;
}
void id11(int a[],int n,int b[]){id11(a,n,b,n);}
void id11(int a[],int n){id11(a,n,a,n);}

void polyitg(int a[],int an,int b[],int bn)
{
	for(int i=bn-1;i>0;i--)b[i]=1ll*(i-1<an?a[i-1]:0)*inv[i]%mod;
	b[0]=0;
}
void polyitg(int a[],int n,int b[]){polyitg(a,n,b,n);}
void polyitg(int a[],int n){polyitg(a,n,a,n);}





void id15(int a[],int an,int k,int b[],int bn=-1)
{
	if(bn==-1)bn=(an-1)*k+1;
	static int pow_ans[FFTmx],pow_x[FFTmx];
	copy(a,a+an,pow_x);
	pow_ans[0]=1;
	int ansn=1;
	while(k>0)
	{
		if(k&1)
		{
			id19(pow_ans,ansn,pow_x,an,pow_ans);
			ansn=min(ansn+an,bn);
		}
		id19(pow_x,an,pow_x,an,pow_x);
		an=min(an+an,bn);
		k>>=1;
	}
	for(int i=0;i<bn;i++)b[i]=i<ansn?pow_ans[i]:0;
}



void id12(int a[],int n,int b[])
{
	static int inv_a[FFTmx],inv_b[FFTmx];
	assert(a!=b);
	if(n==1)
	{
		assert(a[0]!=0);
		b[0]=qpow(a[0],mod-2);
		return;
	}
	int nn=n>>1;
	id12(a,nn,b);

	FFTinit(n+n);
	polyset(b,nn,inv_a,fsz);
	FFT(inv_a,1);
	polyset(a,n,inv_b,fsz);
	FFT(inv_b,1);
	for(int i=0;i<fsz;i++)inv_a[i]=1ll*(2ll-1ll*inv_a[i]*inv_b[i]%mod+mod)*inv_a[i]%mod;
	FFT(inv_a,-1);
	polyset(inv_a,fsz,b,n);

	id19(b,nn,a,n,inv_a,n);
	id16(inv_a,n);
	inv_a[0]=(inv_a[0]+2)%mod;
	id19(b,nn,inv_a,n,b,n);

}




void polyinv(int a[],int an,int b[],int bn)
{
	static int inv_ta[FFTmx],inv_tb[FFTmx];
	int sz=id0(bn);
	polyset(a,an,inv_ta,sz);
	id12(inv_ta,sz,inv_tb);
	polyset(inv_tb,sz,b,bn);
}
void polyinv(int a[],int n,int b[]){polyinv(a,n,b,n);}
void polyinv(int a[],int n){polyinv(a,n,a,n);}







int polydiv(int a[],int an,int b[],int bn,int c[])
{
	static int div_a[FFTmx],div_b[FFTmx];
	int cn=an-bn+1;
	if(cn<=0)return 0;
	for(int i=0;i<bn;i++)div_b[i]=b[bn-i-1];
	polyinv(div_b,bn,div_a,cn);
	for(int i=0;i<an;i++)div_b[i]=a[an-i-1];
	id19(div_b,cn,div_a,cn,c,cn);
	for(int i=0;i<cn-i;i++)swap(c[i],c[cn-i-1]);
	return cn;
}







int id4(int a[],int an,int b[],int bn,int c[])
{
	static int mod_a[FFTmx];
	assert(bn>0);
	int rn=bn-1;
	int cn=polydiv(a,an,b,bn,mod_a);
	id19(mod_a,cn,b,bn,mod_a,rn);
	id1(a,mod_a,c,rn);
	return rn;
}







void polyln(int a[],int an,int b[],int bn)
{
	static int ln_a[FFTmx],ln_b[FFTmx];
	assert((a[0]%mod+mod)%mod==1);
	id11(a,an,ln_a,bn);
	polyinv(a,an,ln_b,bn);
	id19(ln_a,bn,ln_b,bn,b,bn);
	polyitg(b,bn);
}
void polyln(int a[],int n,int b[]){polyln(a,n,b,n);}
void polyln(int a[],int n){polyln(a,n,a,n);}



void id23(int a[],int n,int b[])
{
	static int ex_a[FFTmx];
	assert(a!=b);
	if(n==1)
	{
		assert(a[0]==0);
		b[0]=1;
		return;
	}
	int nn=n>>1;
	id23(a,nn,b);
	polyln(b,nn,ex_a,n);
	id16(ex_a,n);
	polyadd(ex_a,a,ex_a,n);
	ex_a[0]=(ex_a[0]+1)%mod;
	id19(ex_a,n,b,nn,b,n);
}




void polyexp(int a[],int an,int b[],int bn)
{
	static int exp_ta[FFTmx],exp_tb[FFTmx];
	int sz=id0(bn);
	polyset(a,an,exp_ta,sz);
	id23(exp_ta,sz,exp_tb);
	polyset(exp_tb,sz,b,bn);
}
void polyexp(int a[],int n,int b[]){polyexp(a,n,b,n);}
void polyexp(int a[],int n){polyexp(a,n,a,n);}







void id9(int a[],int n,ll K,int c[],int cn)
{
	if(K==0)
	{
		for(int i=0;i<cn;i++)c[i]=0;c[0]=1;
		return;
	}
	n=min(n,cn);
	int t=0;
	while(t<n&&a[t]%mod==0)t++;
	if(1.0*t*K>10*cn||1ll*t*K>=cn)
	{
		for(int i=0;i<cn;i++)c[i]=0;
		return;
	}
	static int pow_a[FFTmx];
	polyset(a+t,n-t,pow_a,cn-t);
	int sz=cn-t;
	ll coef=pow_a[0];
	id17(pow_a,sz,qpow(coef,mod-2),pow_a,sz);
	polyln(pow_a,sz);
	id17(pow_a,sz,K%mod,pow_a,sz);
	polyexp(pow_a,sz);
	id17(pow_a,sz,qpow(coef,K),pow_a,sz);
	ll cnt0=t*K;
	id10(c,cnt0);
	polyset(pow_a,sz,c+cnt0,cn-cnt0);
}



void id13(int a[],int n,int b[])
{
	static int sqrt_a[FFTmx];
	assert(a!=b);
	if(n==1)
	{
		assert((a[0]%mod+mod)%mod==1);
		b[0]=1;
		return;
	}
	int nn=n>>1;
	id13(a,nn,b);
	polyinv(b,nn,sqrt_a,n);
	id19(sqrt_a,n,a,n,sqrt_a,n);
	polyadd(b,nn,sqrt_a,n,sqrt_a,n);
	id17(sqrt_a,n,qpow(2,mod-2),b,n);
}




void id7(int a[],int an,int b[],int bn)
{
	static int sqrt_ta[FFTmx],sqrt_tb[FFTmx];
	int sz=id0(bn);
	polyset(a,an,sqrt_ta,sz);
	id13(sqrt_ta,sz,sqrt_tb);
	polyset(sqrt_tb,sz,b,bn);
}
void id7(int a[],int n,int b[]){id7(a,n,b,n);}
void id7(int a[],int n){id7(a,n,a,n);}



int ev_tab[id21][FFTmx<<1];
int ev_ans[id21][FFTmx<<1];
void id2(int lv,int a[],int l,int r)
{
	assert(lv<id21);
	if(l==r)
	{
		ev_tab[lv][l*2]=mod-a[l]%mod;
		ev_tab[lv][l*2+1]=1;
		return;
	}
	int m=l+r>>1;
	id2(lv+1,a,l,m);
	id2(lv+1,a,m+1,r);
	id19(ev_tab[lv+1]+l*2,m-l+2,ev_tab[lv+1]+(m+1)*2,r-(m+1)+2,ev_tab[lv]+l*2,r-l+2);
}
void id5(int lv,int a[],int an,int l,int r,int ans[])
{
	assert(lv<id21);
	int sz=id4(a,an,ev_tab[lv]+l*2,r-l+2,ev_ans[lv]+l);
	if(l==r)
	{
		ans[l]=ev_ans[lv][l];
		return;
	}
	int m=l+r>>1;
	id5(lv+1,ev_ans[lv]+l,sz,l,m,ans);
	id5(lv+1,ev_ans[lv]+l,sz,m+1,r,ans);
}


void id22(int a[],int n,int b[],int m,int c[])
{
	id2(0,b,0,m-1);
	id5(0,a,n,0,m-1,c);
}



int it_f[FFTmx],it_c[FFTmx];
int it_ta[FFTmx],it_tb[FFTmx];
void id8(int lv,int c[],int l,int r,int a[])
{
	if(l==r)
	{
		a[l]=1ll*qpow(it_c[l],mod-2)*c[l]%mod;
		return;
	}
	int m=l+r>>1;
	id8(lv+1,c,l,m,a);
	id8(lv+1,c,m+1,r,a);
	id19(a+l,m+1-l,ev_tab[lv+1]+(m+1)*2,r-(m+1)+2,it_ta,r-l+1);
	id19(a+m+1,r-m,ev_tab[lv+1]+l*2,m-l+2,it_tb,r-l+1);
	polyadd(it_ta,it_tb,a+l,r-l+1);
}


void id20(int b[],int n,int c[],int a[])
{
	id2(0,b,0,n-1);
	id11(ev_tab[0],n+1,it_f);
	id5(0,it_f,n,0,n-1,it_c);
	id8(0,c,0,n-1,a);
}

vector<int> con[100111];
ll ANS;
int n,K;
int SZ[100111],SZ_pre[100111];
int getsz(int x,int to){return SZ_pre[to]==x?SZ[to]:n-SZ[x];}
void dfs_sz(int x,int pre=-1)
{
	SZ[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		SZ_pre[u]=x;
		dfs_sz(u,x);
		SZ[x]+=SZ[u];
	}
}
int cur_lv,cur_rt;
int dlv[100111];
int sz[100111],an,arr[100111];
void pdfs(int x,int pre=-1)
{
	dlv[x]=cur_lv+1;
	sz[x]=1;
	arr[an++]=x;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||dlv[u]<cur_lv)continue;
		pdfs(u,x);
		sz[x]+=sz[u];
	}
}
int findrt(int x)
{
	an=0;
	pdfs(x);
	int ret=x;
	for(int i=0;i<an;i++)if(sz[arr[i]]*2>=sz[x]&&sz[arr[i]]<sz[ret])ret=arr[i];
	return ret;
}
ll ans[100111],sans[100111];

void id6(int lv,int a[],int l,int r)
{
	assert(lv<id21);
	if(l==r)
	{
		ev_tab[lv][l*2]=1;
		ev_tab[lv][l*2+1]=a[l];
		return;
	}
	int m=l+r>>1;
	id6(lv+1,a,l,m);
	id6(lv+1,a,m+1,r);
	id19(ev_tab[lv+1]+l*2,m-l+2,ev_tab[lv+1]+(m+1)*2,r-(m+1)+2,ev_tab[lv]+l*2,r-l+2);
}
int A[FFTmx],nA[FFTmx];
void mult(int sz,int c)
{
	for(int i=0;i<=sz;i++)nA[i]=0;
	for(int i=0;i<=sz;i++)
	{
		nA[i]=(nA[i]+A[i])%mod;
		nA[i+1]=(nA[i+1]+1ll*A[i]*c)%mod;
	}
	for(int i=0;i<=sz;i++)A[i]=nA[i];
}
void divi(int sz,int c)

{
	for(int i=0;i<=sz;i++)nA[i]=0;
	ll inv=qpow(c,mod-2);
	for(int i=sz;i>0;i--)
	{
		ll k=A[i]*inv%mod;
		nA[i-1]=k;
		A[i-1]=(A[i-1]-k+mod)%mod;
	}
	for(int i=0;i<=sz;i++)A[i]=nA[i];
}
ll calc_arr(int a[],int sz)
{
	ll ret=0;
	for(int i=0;i<=min(K,sz);i++)
	{
		ll coef=1ll*fac[K]*ifac[K-i]%mod;
		ret=(ret+coef*a[i])%mod;
	}
	return ret;
}
ll calc(vector<int> &v)
{
	ll ret=0;
	int sz=v.size();
	if(sz==0)return 1;
	static int calc_a[FFTmx];
	for(int i=0;i<sz;i++)calc_a[i]=v[i];
	id6(0,calc_a,0,sz-1);
	ret=calc_arr(ev_tab[0],min(sz,K));

	return ret;
}
ll dfs(int x,int pre)
{
	ll ret=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||dlv[u]<cur_lv)continue;
		ret=(ret+dfs(u,x))%mod;
	}
	static vector<int> v;
	v.clear();
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		v.PB(getsz(x,u));
	}
	ans[x]=calc(v);
	return (ret+ans[x])%mod;
}
map<int,int> mp;
void clear_ans()
{
	mp.clear();
}
int get_ans(int sz,int x)
{
	if(mp.find(x)!=mp.end())return mp[x];
	int &ret=mp[x];
	divi(sz,x);
	ret=calc_arr(A,sz);
	mult(sz,x);
	return ret;
}
void solve(int _x,int lv)
{
	cur_lv=lv;
	int rt=findrt(_x);
	dlv[rt]=lv;
	




	
	ll SUM=0;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]<lv)continue;
		sans[u]=dfs(u,rt);
		SUM=(SUM+sans[u])%mod;
	}


	
	vector<int> v;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];


		v.PB(getsz(rt,u));
	}
	calc(v);
	int vsz=v.size();




	for(int i=0;i<=vsz;i++)A[i]=ev_tab[0][i];




	
	clear_ans();
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]<lv)continue;
		ll cur_ans=get_ans(vsz,getsz(rt,u));


		ANS=(ANS+sans[u]*((SUM-sans[u])*qpow(2,mod-2)%mod+mod+cur_ans)%mod)%mod;
	}


	
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]<lv)continue;
		solve(u,lv+1);
	}
}
int main()
{
	id18();
	comb_init();
	getii(n,K);
	if(K==1)
	{
		cout<<(1ll*n*(n-1)/2)%mod<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs_sz(1);
	solve(1,0);
	cout<<ANS<<endl;
	return 0;
}
