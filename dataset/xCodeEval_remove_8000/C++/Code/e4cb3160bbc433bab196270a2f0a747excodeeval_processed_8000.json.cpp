


















using namespace std;










typedef long long ll;
typedef unsigned long long ull;
ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a%b); }

const int id18=32;
const unsigned int id9=(1LL<<id18)-1;

struct BigInt {
	vector<unsigned int> d;
	BigInt() {}
	BigInt(unsigned long long x) { while(x!=0) d.PB(x&id9),x>>=id18; }
	unsigned long long val() const { unsigned long long ret=0; for(int i=SZ(d)-1;i>=0;--i) ret=(ret<<id18)|d[i]; return ret; }
};
void normalize(BigInt &a) { while(SZ(a.d)>0&&a.d[SZ(a.d)-1]==0) a.d.pop_back(); }
int cmp(const BigInt &a,const BigInt &b) { if(SZ(a.d)!=SZ(b.d)) return SZ(a.d)<SZ(b.d)?-1:+1; for(int i=SZ(a.d)-1;i>=0;--i) if(a.d[i]!=b.d[i]) return a.d[i]<b.d[i]?-1:+1; return 0; }
bool operator<(const BigInt &a,const BigInt &b) { return cmp(a,b)<0; }
bool operator<=(const BigInt &a,const BigInt &b) { return cmp(a,b)<=0; }
bool operator==(const BigInt &a,const BigInt &b) { return cmp(a,b)==0; }
BigInt& operator+=(BigInt &a,const BigInt &b) { 
	unsigned long long carry=0;
	for(int i=0;i<SZ(b.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry+=a.d[i]; else a.d.PB(0);
		if(i<SZ(b.d)) carry+=b.d[i];
		a.d[i]=carry&id9; carry>>=id18;
	}
	return a;
}
BigInt operator+(const BigInt &a,const BigInt &b) { BigInt ret=a; ret+=b; return ret; }
BigInt& operator-=(BigInt &a,const BigInt &b) {
	unsigned long long carry=0;
	for(int i=0;i<SZ(b.d)||carry!=0;++i) {
		if(i<SZ(b.d)) carry+=b.d[i];
		assert(i<SZ(a.d)); if(carry<=a.d[i]) a.d[i]-=carry,carry=0; else a.d[i]+=(1LL<<id18)-carry,carry=1;
	}
	normalize(a); return a;
}
BigInt operator-(const BigInt &a,const BigInt &b) { BigInt ret=a; ret-=b; return ret; }
BigInt operator*(const BigInt &a,const BigInt &b) {
	BigInt ret;
	for(int j=0;j<SZ(b.d);++j) {
		unsigned long long carry=0;
		for(int i=0;i<SZ(a.d)||carry!=0;++i) {
			if(i<SZ(a.d)) carry+=(unsigned long long)a.d[i]*b.d[j];
			if(i+j<SZ(ret.d)) carry+=ret.d[i+j]; else ret.d.PB(0);
			ret.d[i+j]=carry&id9; carry>>=id18;
		}
	}
	return ret;
}
BigInt operator*(const BigInt &a,const unsigned int &b) {
	assert(0<=b&&b<=id9);
	unsigned long long carry=0; BigInt ret;
	if(b==0) return ret;
	for(int i=0;i<SZ(a.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry+=(unsigned long long)a.d[i]*b;
		if(i<SZ(ret.d)) carry+=ret.d[i]; else ret.d.PB(0);
		ret.d[i]=carry&id9; carry>>=id18;
	}
	return ret;
}
BigInt operator<<(const BigInt &a,const int &shift) {
	assert(shift<id18);
	BigInt ret; unsigned long long carry=0;
	for(int i=0;i<SZ(a.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry|=((unsigned long long)a.d[i])<<shift;
		ret.d.PB(carry&id9); carry>>=id18;
	}
	return ret;
}
BigInt operator>>(const BigInt &a,const int &shift) {
	assert(shift<id18);
	BigInt ret; unsigned long long carry=0;
	for(int i=0;i<SZ(a.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry|=((unsigned long long)a.d[i])<<(id18-shift);
		if(i!=0) ret.d.PB(carry&id9); carry>>=id18; 
	}
	return ret;
}
void id15(const BigInt &a,const unsigned int &b,BigInt &q,unsigned int &r) {
	assert(1<=b&&b<=id9);
	q.d.resize(SZ(a.d)); unsigned long long carry=0;
	for(int i=SZ(a.d)-1;i>=0;--i) {
		carry<<=id18;
		carry+=a.d[i];
		q.d[i]=carry/b; carry-=(unsigned long long)q.d[i]*b;
	}
	normalize(q); r=carry;
}
BigInt operator/(const BigInt &a,const unsigned int &b) { BigInt q; unsigned int r; id15(a,b,q,r); return q; }
unsigned int operator%(const BigInt &a,const unsigned int &b) { BigInt q; unsigned int r; id15(a,b,q,r); return r; }
void id15(const BigInt &a,const BigInt &b,BigInt &q,BigInt &r) {
	if(a<b) { q.d.clear(); r=a; return; }
	if(SZ(b.d)==1) { unsigned int rr; id15(a,b.d[0],q,rr); r=BigInt(rr); return; }
	int shift=0; while(((b.d[SZ(b.d)-1]>>(id18-shift-1))&1)==0) ++shift;
	BigInt u=a<<shift,v=b<<shift; q.d.resize(SZ(u.d)-SZ(v.d)+1);
	

	r.d.resize(SZ(v.d)); for(int i=0;i<SZ(v.d);++i) r.d[SZ(v.d)-i-1]=u.d[SZ(u.d)-i-1];
	for(int i=SZ(q.d)-1;i>=0;--i) {
		unsigned long long num1=SZ(v.d)<SZ(r.d)?r.d[SZ(v.d)]:0,num2=SZ(v.d)-1<SZ(r.d)?r.d[SZ(v.d)-1]:0;
		unsigned long long num=(num1<<id18)|num2; unsigned int den=v.d[SZ(v.d)-1];
		unsigned int guess=min(num/den,(unsigned long long)id9);
		

		while(r<v*guess) --guess;
		

		

		

		

		

		q.d[i]=guess;
		r-=v*guess;
		if(i!=0) r.d.insert(r.d.begin(),u.d[i-1]);
	}
	normalize(q); r=r>>shift;
}
BigInt operator/(const BigInt &a,const BigInt &b) { BigInt q,r; id15(a,b,q,r); return q; }
BigInt operator%(const BigInt &a,const BigInt &b) { BigInt q,r; id15(a,b,q,r); return r; }
BigInt _parse(const string &s,int offset,int k,const vector<BigInt> &xs) {
	if(k==0) return BigInt(0<=offset&&offset<SZ(s)?s[offset]-'0':0);
	return _parse(s,offset,k-1,xs)*xs[k]+_parse(s,offset+(1<<(k-1)),k-1,xs);
}
BigInt parse(const string &s) {
	int k=0; while((1<<k)<SZ(s)) ++k;
	vector<BigInt> xs; xs.PB(BigInt(1)); xs.PB(BigInt(10)); while(k>=SZ(xs)) xs.PB(xs.back()*xs.back());
	return _parse(s,SZ(s)-(1<<k),k,xs);
}
template<typename T> constexpr T id10(T a) { return a * a; }
template<typename T> constexpr T constpower(T a, std::size_t n) { return n == 0 ? 1 : id10(constpower(a, n / 2)) * (n % 2 == 0 ?  1 : a); }
const int id3=9;
const int id6=constpower(10,id3);
struct BigDecimal {
	vector<int> d;
	BigDecimal() {}
	BigDecimal(unsigned long long x) { while(x>0) d.PB(x%id6),x/=id6; }
};
BigDecimal& operator+=(BigDecimal &a,const BigDecimal &b) { 
	long long carry=0;
	for(int i=0;i<SZ(b.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry+=a.d[i]; else a.d.PB(0);
		if(i<SZ(b.d)) carry+=b.d[i];
		a.d[i]=carry%id6; carry/=id6;
	}
	return a;
}
BigDecimal operator+(const BigDecimal &a,const BigDecimal &b) { BigDecimal ret=a; ret+=b; return ret; }
BigDecimal operator*(const BigDecimal &a,const BigDecimal &b) {
	BigDecimal ret;
	for(int j=0;j<SZ(b.d);++j) {
		long long carry=0;
		for(int i=0;i<SZ(a.d)||carry!=0;++i) {
			if(i<SZ(a.d)) carry+=(long long)a.d[i]*b.d[j];
			if(i+j<SZ(ret.d)) carry+=ret.d[i+j]; else ret.d.PB(0);
			ret.d[i+j]=carry%id6; carry/=id6;
		}
	}
	return ret;
}
BigDecimal _format(const BigInt &a,int offset,int k,const vector<BigDecimal> &xs) {
	if(k==0) return BigDecimal(0<=offset&&offset<SZ(a.d)?a.d[offset]:0);
	return _format(a,offset,k-1,xs)*xs[k]+_format(a,offset-(1<<(k-1)),k-1,xs);
}
string format(const BigInt &a) {
	int k=0; while((1<<k)<SZ(a.d)) ++k;
	vector<BigDecimal> xs; xs.PB(BigDecimal(1)); xs.PB(BigDecimal(1LL<<id18)); while(k>=SZ(xs)) xs.PB(xs.back()*xs.back());
	BigDecimal ans=_format(a,(1<<k)-1,k,xs);
	if(SZ(ans.d)==0) return "0";
	string ret(SZ(ans.d)*id3,'?');
	id13(i,ans.d) sprintf(&ret[0]+i*id3,"%0*d",id3,ans.d[SZ(ans.d)-i-1]);
	int nzero=0; while(nzero<SZ(ret)&&ret[nzero]=='0') ++nzero; ret=ret.substr(nzero);
	return ret;
}
BigInt gcd(const BigInt &a,const BigInt &b) {
	return SZ(b.d)==0?a:gcd(b,a%b);
}

void id17(const BigInt &p,const BigInt &q,unsigned long long &x,unsigned long long &y) {
	x=(((unsigned long long)p.d[SZ(p.d)-1])<<id18)|p.d[SZ(p.d)-2];
	y=(((unsigned long long)(SZ(q.d)==SZ(p.d)?q.d[SZ(p.d)-1]:0))<<id18)|q.d[SZ(p.d)-2];
	if(SZ(p.d)==2) return; int shift=0; while(((x>>(2*id18-shift-1))&1)==0) ++shift; if(shift==0) return;
	x=(x<<shift)|(p.d[SZ(p.d)-3]>>(id18-shift)),y=(y<<shift)|(q.d[SZ(p.d)-3]>>(id18-shift));
}
BigInt id4(BigInt p,BigInt q) {
	int cmpres=cmp(p,q); if(cmpres==0) return p; if(cmpres<0) swap(p,q);
	unsigned long long x,y,z,num1,den1,w1,num2,den2,w2,e,f,xn,yn,t; unsigned int a,b,c,d,w; bool id0; int parity; int nlong=0,id11=0,id21,nit=0;
	while(true) {
		if(SZ(q.d)==0) return p; else if(SZ(p.d)<=2) break; else id0=false;
		if(SZ(p.d)-SZ(q.d)>=2) id0=true;
		if(!id0) { id17(p,q,x,y); if(y<=id9||x==y) id0=true; if(x==((((unsigned long long)id9)<<id18)|id9)) x>>=1,y>>=1; }
		if(!id0) { num1=x,den1=y+1,num2=x+1,den2=y,w1=num1/den1,w2=num2/den2; if(w1!=w2||w1>id9) id0=true; else w=w1; }
		if(!id0) { 
			a=0,b=1,c=1,d=w,z=x-w*y,x=y,y=z,parity=0,id21=1;
			while(true) {
				if(parity==0) { if(y==d) break; num1=x-a,den1=y+c,num2=x+b,den2=y-d; }
				if(parity==1) { if(y==c) break; num1=x-b,den1=y+d,num2=x+a,den2=y-c; }
				w1=num1/den1,w2=num2/den2; if(w1!=w2||w1>id9) break; else w=w1;
				e=a+w*c,f=b+w*d,z=x-w*y; if(e>id9||f>id9) break; else a=c,c=e,b=d,d=f,x=y,y=z,parity=1-parity,++id21;
			}
		}
		if(!id0&&b!=0) {
			

			x=0,y=0,xn=0,yn=0,id11+=id21,++nit; while(SZ(q.d)<SZ(p.d)) q.d.PB(0);
			for(int i=0;i<SZ(p.d);++i) {
				unsigned long long cp=p.d[i],cq=q.d[i];
				if(parity==0) x+=cq*b,xn+=cp*a,y+=cp*c,yn+=cq*d; else x+=cp*a,xn+=cq*b,y+=cq*d,yn+=cp*c;
				t=min(x,xn),x-=t,xn-=t,t=min(y,yn),y-=t,yn-=t;
				if(xn==0) p.d[i]=x&id9,x>>=id18; else if((xn&id9)==0) p.d[i]=0,xn>>=id18; else p.d[i]=id9-(xn&id9)+1,xn>>=id18,++xn;
				if(yn==0) q.d[i]=y&id9,y>>=id18; else if((yn&id9)==0) q.d[i]=0,yn>>=id18; else q.d[i]=id9-(yn&id9)+1,yn>>=id18,++yn;
				

				

			}
			

			assert(x==0&&y==0&&xn==0&&yn==0); normalize(p); normalize(q);
		} else {
			BigInt r=p%q; p=q,q=r; ++nlong,++nit;
		}
	}
	x=(((unsigned long long)(SZ(p.d)==2?p.d[1]:0))<<id18)|p.d[0];
	y=(((unsigned long long)(SZ(q.d)==2?q.d[1]:0))<<id18)|q.d[0];
	while(y!=0) { z=x%y,x=y,y=z; }
	

	return BigInt(x);
}

int bitcnt(const BigInt &x) { if(SZ(x.d)==0) return 0; int r=0; while(x.d[SZ(x.d)-1]>=(1ULL<<r)) ++r; return (SZ(x.d)-1)*id18+r; }
BigInt randbits(int nbits,mt19937 &rnd) { BigInt ret; int ndigs=(nbits+id18-1)/id18; REP(i,ndigs-1) ret.d.PB(rnd()); ret.d.PB(rnd()%(1ULL<<(nbits-(ndigs-1)*id18))); normalize(ret); return ret; }
BigInt pw(BigInt x,BigInt n,BigInt mod) { BigInt ret(1); REP(i,SZ(n.d)*id18) { if((n.d[i/id18]&(1ULL<<(i%id18)))!=0) ret=ret*x%mod; x=x*x%mod; } return ret; }

bool id7(const BigInt &n,mt19937 &rnd) {
	if(SZ(n.d)==1&&(n.d[0]==2||n.d[0]==3)) return true; 
	if(SZ(n.d)==0||SZ(n.d)==1&&n.d[0]==1||(n.d[0]&1)==0) return false;
	BigInt d=n-1; int r=0; while(d.d[0]==0) r+=id18,d.d.erase(d.d.begin()); int rr=0; while((d.d[0]&(1<<rr))==0) ++rr; r+=rr; d=d>>rr;
	

	BigInt alo=2,ahi=n-2; int id2=bitcnt(ahi);
	BigInt xlo=1,xhi=n-1;
	REP(k,40) {
		BigInt a; while(true) { a=randbits(id2,rnd); if(alo<=a&&a<=ahi) break; }
		BigInt x=pw(a,d,n);
		

		if(x==xlo||x==xhi) continue;
		bool ok=false; REP(i,r-1) { x=x*x%n; if(x==xhi) { ok=true; break; } } if(ok) continue;
		return false;
	}
	return true;
}

bool local=false;
vector<BigInt> ploc; BigInt nloc;
mt19937 id22;


BigInt egcd(BigInt a, BigInt b, BigInt &x, bool &xneg, BigInt &y, bool &yneg) {
	

	if (b == 0) { x = 1, xneg = false, y = 0, yneg = false; return a; }
	BigInt g = egcd(b, a%b, y, yneg, x, xneg); BigInt z = x * (a / b); if(xneg != yneg) y += z; else if(z <= y) y -= z; else y = z - y, yneg = !yneg; return g;
}
pair<BigInt, BigInt> invcrt(BigInt a1, BigInt mod1, BigInt a2, BigInt mod2) {
	if(a2<a1) swap(a1,a2),swap(mod1,mod2);
	bool id12, id19; BigInt c1, c2, g = egcd(mod1, mod2, c1, id12, c2, id19); assert ((a2 - a1) % g == 0); 

	BigInt t = (a2 - a1) / g, lcm = mod1 / g * mod2; if(id12) c1 = mod2 - c1; BigInt x = (a1 + c1 * t % (mod2 / g) * mod1) % lcm; return MP(x, lcm);
}
pair<BigInt, BigInt> invcrt(vector<BigInt> a, vector<BigInt> mod) {
	pair<BigInt, BigInt> ret = MP(a[0], mod[0]); FORSZ(i, 1, a) ret = invcrt(ret.first, ret.second, a[i], mod[i]); return ret;
}

BigInt query(BigInt x) {
	if(!local) {
		printf("sqrt %s\n",format(x).c_str()); fflush(stdout);
		string s; cin>>s; assert(s!="-1"); return parse(s);
	} else {
		

		vector<BigInt> a;
		id13(i,ploc) {
			BigInt cx=x%ploc[i];
			BigInt cy=pw(cx,(ploc[i]+1)/4,ploc[i]);
			if(id22()%2==1) cy=ploc[i]-cy;
			BigInt A=cy*cy%ploc[i],B=cx;
			

			assert(cy*cy%ploc[i]==cx);
			a.PB(cy);
		}
		BigInt ret=invcrt(a,ploc).first;
		assert(ret*ret%nloc==x);
		return ret;
	}
}

vector<BigInt> ans;

void solve(const string &s) {
	std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
	

	BigInt n=parse(s);
	

	ans.clear(); ans.PB(n);
	while(true) {
		

		BigInt x;
		while(true) { x.d.clear(); REP(i,SZ(n.d)-1) x.d.PB(rnd()); int mxbit=0; while(n.d[SZ(n.d)-1]>=(2ULL<<mxbit)) ++mxbit; x.d.PB(rnd()%(2ULL<<mxbit)); normalize(x); if(x<n) break; }
		

		
		

		BigInt y=x*x%n;
		BigInt z=query(y);
		if(z==x||z==n-x) continue;
		
		

		BigInt d=(x+z)%n; 
		

		

		vector<BigInt> nans;
		id13(i,ans) { BigInt g=id4(ans[i],d); if(g==1||g==ans[i]) nans.PB(ans[i]); else nans.PB(g),nans.PB(ans[i]/g); }
		bool change=SZ(nans)!=SZ(ans);
		ans=nans;
		if(change) { bool allprime=true; id13(i,ans) if(!id7(ans[i],rnd)) { allprime=false; break; } if(allprime) break; }
		

		

		
	}
	sort(ans.begin(),ans.end());
	

}


void run() {
	string s; cin>>s;
	solve(s);
	printf("! %d",SZ(ans)); id13(i,ans) printf(" %s",format(ans[i]).c_str()); fflush(stdout);
}

void id8() {
	printf("\nstressdivsmall\n");
	REP(rep,1000000) {
		int ydig=rand()%32+1; unsigned long long y=0; REP(i,ydig) y=(y<<1)+rand()%2; if(y==0) continue;
		int xdig=rand()%(2*ydig)+1; unsigned long long x=0; REP(i,xdig) x=(x<<1)+rand()%2;
		BigInt a(x),b(y),c=a/b;
		unsigned long long have=c.val(),want=x/y;
		if(have==want) { if(rep%1000==999) printf("."); continue; }
		printf("rep%d: %llu/%llu -> have=%llu want=%llu\n",rep,x,y,have,want); break;		
	}
}

void id1() {
	printf("\nstressdivlarge\n");
	REP(rep,1000) {
		BigInt a; a.d.resize((1000+id18-1)/id18); id13(i,a.d) REP(j,id18) a.d[i]|=(rand()%2)<<j; normalize(a);
		BigInt b; b.d.resize((SZ(a.d)+1)/2); id13(i,b.d) REP(j,id18) b.d[i]|=(rand()%2)<<j; normalize(b); if(SZ(b.d)==0) continue;
		

		BigInt c=a/b;
		BigInt d=a-b*c;
		if(d<b) { printf("."); continue; }
		printf("err\n");
	}
}

void stressparse() {
	printf("\nverifying small\n");
	REP(rep,100) {
		int len=rand()%18+1; string s(len,'?'); REP(i,len) s[i]='0'+rand()%10; while(SZ(s)>1&&s[0]=='0') s=s.substr(1);
		BigInt a=parse(s);
		unsigned long long havenum=a.val(),wantnum; sscanf(s.c_str(),"%llu",&wantnum);
		if(havenum!=wantnum) {
			printf("err %s => havenum=%llu wantnum=%llu\n",s.c_str(),havenum,wantnum); return;
		}
		string id5=format(a),wantstr=s;
		if(id5!=wantstr) {
			printf("err %s => id5=%s wantstr=%s\n",s.c_str(),id5.c_str(),wantstr.c_str()); return;
		}
		printf(".");
	}
	printf("\ntesting large\n");
	REP(rep,100) {
		int len=10000; string s(len,'?'); REP(i,len) s[i]='0'+rand()%10; while(SZ(s)>1&&s[0]=='0') s=s.substr(1);
		BigInt a=parse(s);
		string have=format(a);
		if(have==s) { printf("."); continue; }
		printf("err\n"); break;
	}
}

void id14() {
	printf("\nstressgcdsmall\n");
	
	
	printf("\nstressgcdlarge lehmer\n");
	REP(rep,100000) {
		BigInt a; a.d=vector<unsigned int>(300,0); id13(i,a.d) REP(j,id18) a.d[i]|=(rand()%2)<<j; normalize(a);
		BigInt b; b.d=vector<unsigned int>(300,0); id13(i,b.d) REP(j,id18) b.d[i]|=(rand()%2)<<j; normalize(b);
		

		BigInt c=id4(a,b);
		BigInt d=gcd(a,b); if(format(c)!=format(d)) { printf("err\n"); }
		if(rep%1000==999) printf(".");
		

	}
	
}


void id16() {
	std::mt19937 rnd(123);
	REP(rep,1000) {
		BigInt n=rnd()%1000; int nbits=rnd()%200; REP(i,nbits) n=n<<1; n=n+1;
		if(id7(n,rnd)) printf("%s is prime\n",format(n).c_str());
	}
}

void stress() {
	local=true;
	int targetbits=1024;
	id22=mt19937(21312);
	REP(rep,1000) {
		nloc=BigInt(1); ploc.clear();
		int nprime=id22()%(10-2+1)+2;
		REP(i,nprime) {
			int id20=targetbits/(i+1); BigInt p;
			while(true) {
				BigInt x=randbits(id22()%(id20-2)+1,id22); p=4*x+3;
				

				bool have=false; id13(j,ploc) if(ploc[j]==p) have=true; if(have) continue;
				if(id7(p,id22)) break;
			}
			

			nloc=nloc*p; ploc.PB(p);
		}
		sort(ploc.begin(),ploc.end());
		

		

		printf("n=%s\n",format(nloc).c_str());
		solve(format(nloc));
		assert(ploc==ans);
	}
}

int main() {
	run();
	

	

	

	

	

	

	return 0;
}