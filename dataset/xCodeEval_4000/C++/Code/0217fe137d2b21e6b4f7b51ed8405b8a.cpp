#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#ifndef MY_RANDOM_H
#define MY_RANDOM_H

	namespace zdw{

		

		namespace __random{

			const unsigned a=1664525;
			const unsigned c=1013904223;

			unsigned random_seed=2333,random_seed2=23333;
			unsigned Random(unsigned &x){return x=a*x+c;}
			unsigned Random(){return Random(random_seed);}
			unsigned Random2(){return Random(random_seed2);}

		};

		void set_rand_seed(const unsigned &x){__random::random_seed=x;}
		void set_rand_seed2(const unsigned &x){__random::random_seed2=x;}
		unsigned random(){return __random::Random();}
		

		

		unsigned long long random(const unsigned long long &l,const unsigned long long &r){return ((unsigned long long)__random::Random()<<32|(unsigned long long)__random::Random2())%(r-l+1)+l;}

	};

#endif


using namespace std;
typedef long long ll;
const int  maxn = 400010;
const int md1 = 1000000006;
const int mod = 1000000007;
const int N=63;
const int ha=1e9+7;
class powmod{
private:
	static const int z=15;

	static const int sz=1<<z;
	static const int L=sz-1;
	int P[sz],Q[sz],ha;
public:
	powmod():ha(1){}
	void init(int x,int mod){
		P[0]=Q[0]=1; ha=mod;
		for(int i=1;i<sz;++i)
			P[i]=(long long)P[i-1]*x%ha;
		Q[1]=(long long)P[L]*x%ha;
		for(int i=2;i<sz;++i)
			Q[i]=(long long)Q[i-1]*Q[1]%ha;
	}
	inline int query(const int &y){
		return (long long)P[y&L]*Q[y>>z]%ha;
	}
}A[N];



#ifndef MY_FASTIO_H

	#define MY_FASTIO_H

	namespace zdw{

		void readint(int &x){
			char s=getchar(),c=0;
			while(~s&&s<'0'||s>'9')c=s,s=getchar(); x=s-'0';
			while(~(s=getchar())&&s>='0'&&s<='9')x=(x<<3)+(x<<1)+s-'0';
			if(c=='-')x=-x;
		}

		void readll(ll &x){
			char s=getchar(),c=0;
			while(~s&&s<'0'||s>'9')c=s,s=getchar(); x=s-'0';
			while(~(s=getchar())&&s>='0'&&s<='9')x=(x<<3)+(x<<1)+s-'0';
			if(c=='-')x=-x;
		}

		void _readint(char *&s,int &x){
			char w=*s,c;
			while(w&&w<'0'||w>'9')w=*++s;
			if(!w){x=-1;return;} c=*(s-1); x=w-'0';
			while((w=*++s)&&w>='0'&&w<='9')x=(x<<3)+(x<<1)+w-'0';
			if(c=='-')x=-x;
		}

		void _readll(char *&s,ll &x){
			char w=*s,c;
			while(w&&w<'0'||w>'9')w=*++s;
			if(!w){x=-1;return;} c=*(s-1); x=w-'0';
			while((w=*++s)&&w>='0'&&w<='9')x=(x<<3)+(x<<1)+w-'0';
			if(c=='-')x=-x;
		}

		void readintmod(int &x,const int &ha){
			char s=getchar(),c=0;
			while(~s&&s<'0'||s>'9')c=s,s=getchar(); x=s-'0';
			while(~(s=getchar())&&s>='0'&&s<='9'){
				x=(x<<3)+(x<<1)+s-'0';
				if(x>2e8)x%=ha;
			}
			if(c=='-')x=-x;
		}

		void readllmod(ll &x,const ll &ha){
			char s=getchar(),c=0;
			while(~s&&s<'0'||s>'9')c=s,s=getchar(); x=s-'0';
			while(~(s=getchar())&&s>='0'&&s<='9'){
				x=(x<<3)+(x<<1)+s-'0';
				if(x>9e17)x%=ha;
			}if(x>=ha)x%=ha;
			if(c=='-')x=-x;
		}

		void _readintmod(char *&s,int &x,const int &ha){
			char w=*s,c;
			while(w&&w<'0'||w>'9')w=*++s;
			if(!w){x=-1;return;} c=*(s-1); x=w-'0';
			while((w=*++s)&&w>='0'&&w<='9'){
				x=(x<<3)+(x<<1)+w-'0';
				if(x>2e8)x%=ha;
			}
			if(c=='-')x=-x;
		}

		void _readllmod(char *&s,ll &x,const ll &ha){
			char w=*s,c;
			while(w&&w<'0'||w>'9')w=*++s;
			if(!w){x=-1;return;} c=*(s-1); x=w-'0';
			while((w=*++s)&&w>='0'&&w<='9'){
				x=(x<<3)+(x<<1)+w-'0';
				if(x>9e17)x%=ha;
			}if(x>=ha)x%=ha;
			if(c=='-')x=-x;
		}

	

		char __num_table[500001];

		void init_num_table(){
			for(int i=0;i<100000;++i){
				

				char *t=__num_table+i*5;
				t[0]=i/10000+'0';
				t[1]=(i/1000)%10+'0';
				t[2]=(i/100)%10+'0';
				t[3]=(i/10)%10+'0';
				t[4]=i%10+'0';
			}
		}

		void putint(int x){
			if(x<0)putchar('-'),x=-x;
			if(x<=9){putchar(x+'0');return;}
			char w[11],*p=w,*t; *p=0;
			int z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*p)putchar(*p--);
		}

		void putll(ll x){
			if(x<0)putchar('-'),x=-x;
			if(x<=9){putchar(x+'0');return;}
			char w[20],*p=w,*t; *p=0;
			ll z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*p)putchar(*p--);
		}

		void _putint(char *&s,int x){
			if(x<0)*s++='-',x=-x;
			if(x<=9){*s++=x+'0';return;}
			char w[11],*p=w,*t; *p=0;
			int z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*s++=*p--); --s;
		}

		void _putll(char *&s,ll x){
			if(x<0)*s++='-',x=-x;
			if(x<=9){*s++=x+'0';return;}
			char w[20],*p=w,*t; *p=0;
			ll z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*s++=*p--); --s;
		}

		class FastInput{
		public:
			static const int MXL=83886080;
			char *buf,*tt; int sz;

			FastInput(int SZ=MXL){buf=(char*)malloc((sz=SZ)+1);tt=buf+1;*buf=*tt=0;}
			~FastInput(){free(buf);}

			void file_init(FILE *F){
				buf[fread(buf+1,1,sz,F)]=0;
				tt=buf+1;
			}

			void readint(int &x){_readint(tt,x);}
			void readll(ll &x){_readll(tt,x);}
			void readintmod(int &x,const int &ha){_readintmod(tt,x,ha);}
			void readllmod(ll &x,const ll &ha){_readllmod(tt,x,ha);}
			char getchar(){return *tt?*tt++:-1;}
			void getchar(char &c){c=(*tt?*tt++:-1);}
			void getstr(char *s){
				char w;
				while((w=*tt)&&w=='\r'||w=='\n'||w==' ')++tt;
				while((w=*tt)&&w!='\r'&&w!='\n'&&w!=' ')*s++=w,++tt;
				*s=0;
			}
			void getline(char *s){
				char w;
				while((w=*tt)&&w!='\r'&&w!='\n')*s++=w,++tt;
				tt+=*tt=='\r'?1:0; tt+=*tt=='\n'?1:0; *s=0;
			}

		};

		class FastOutput{
		public:
			static const int MXL=31457280;
			char *buf,*tt; int sz;

			FastOutput(int SZ=MXL){buf=(char*)malloc(sz=SZ);tt=buf;}
			~FastOutput(){free(buf);}

			void flush(FILE *F){
				if(tt==buf)return;
				fwrite(buf,1,tt-buf,F);
				tt=buf;
			}

			void putint(const int &x){_putint(tt,x);}
			void putll(const ll &x){_putll(tt,x);}
			void putchar(const char &c){*tt++=c;}
			void putstr(char *s){while(*tt++=*s++);--tt;}

		};

	}

#endif

#define add_mod(a,b,mod) ((a+=(b))>=mod?a-=mod:a)
int id[310];

bool vis[310];
int pri[310];
int tot=0;
void init(){
	for(int i=2;i<=300;i++){
		if(!vis[i]){
			pri[++tot]=i;
			for(int j=i*i;j<=300;j+=i){
				vis[j]=1;
			}
		}
	}
}
int n,q;
int a[400010];

struct Fenwick{
	

	

	unsigned long long C[maxn];
	bitset<maxn>sign,sign2;
    inline int lowbit(const int &x){
        return x&(-x);
    }
    inline void add(const int &l,const int &r,const int &x){
        

        for(int i=l;i<maxn;i+=lowbit(i)){
			ll a=sign[i]?-(C[i]>>40):(C[i]>>40);
			ll b=sign2[i]?(C[i]&0xffffffffffLL):-(C[i]&0xffffffffffLL);
			a+=x; b+=x*l;
			sign[i]=a<0; sign2[i]=b>=0;
			C[i]=abs(a)<<40|abs(b);
        }
        for(int i=r+1;i<maxn;i+=lowbit(i)){
			ll a=sign[i]?-(C[i]>>40):(C[i]>>40);
			ll b=sign2[i]?(C[i]&0xffffffffffLL):-(C[i]&0xffffffffffLL);
			a-=x; b-=x*(r+1);
			sign[i]=a<0; sign2[i]=b>=0;
			C[i]=abs(a)<<40|abs(b);
        }


    }
    inline long long ask(const int &pos){
        int ret1=0;
        long long ret2=0;
        for(int i=pos,c;i>0;i-=lowbit(i)){
			

			

			ret1+=sign[i]?-(C[i]>>40):(C[i]>>40);
			ret2+=sign2[i]?-(C[i]&0xffffffffffLL):(C[i]&0xffffffffffLL);
			

        }
        return (ll)ret1*(pos+1)+ret2;
    }
    inline long long ask(const int &l,const int &r){
        return ask(r)-ask(l-1);
    }
}f[63];
vector<pair<int,int> > fp[310];
char s;

zdw::FastInput I(8e6);
zdw::FastOutput O(3e6);

int main(){

	I.file_init(stdin);
    zdw::init_num_table();
	init(); 

    for(int i=1;i<=tot;i++) A[i].init(pri[i],mod);

	for(int i=1;i<310;i++){
		for(int j=1;j<=tot;j++){
			if(i%pri[j]==0){
				int tmp=i;
				fp[i].push_back(make_pair(j,0));
				while(tmp%pri[j]==0){
					tmp/=pri[j];
					fp[i][fp[i].size()-1].second++;
				}
			}
		}
	}
	

	

	I.readint(n); I.readint(q);

	for(int i=1;i<=n;i++) 

		

		I.readint(a[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<fp[a[i]].size();j++){
			f[fp[a[i]][j].first].add(i,i,fp[a[i]][j].second);
		}
	}
	char s[20];
	int l,r,x;
	while(q--){
		

		

		I.getstr(s); I.readint(l); I.readint(r);
		if(*s=='M'){
			

			I.readint(x);
			for(int j=0;j<fp[x].size();j++){
				f[fp[x][j].first].add(l,r,fp[x][j].second);
			}

		}else{

			int ans=1;
			for(int j=1;j<=tot;j++){
				long long get=f[j].ask(l,r);
				if(get==0) continue;
				else{
					ans=(ll)ans*(pri[j]-1)%mod;
					if(get>1)ans=(ll)ans*A[j].query((get-1)%md1)%mod;
				}
			}
			

			O.putint(ans); O.putchar('\n');
		}
	}
	O.flush(stdout);
	return 0;
}
