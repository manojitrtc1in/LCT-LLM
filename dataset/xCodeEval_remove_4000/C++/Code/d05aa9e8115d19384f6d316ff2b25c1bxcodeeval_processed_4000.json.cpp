






































































typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T id1(T a,T b,T&x,T&y){if(b!=0){T ans=id1(b,a%b,y,x);y-=a/b*x;return ans;}else return y=0,x=1,a;}
template<typename T>T power(T base,T index,T mod)
{
    T ans=1%mod;
    while(index)
    {
        if(index&1)ans=ans*base%mod;
        base=base*base%mod,index>>=1;
    }
    return ans;
}
namespace ConstMod
{
    template<const ullt p>
    class id0
    {
        private:
            ullt v;
            inline ullt chg(ullt w){return(w<p)?w:w-p;}
            inline id0 _chg(ullt w){id0 ans;ans.v=(w<p)?w:w-p;return ans;}
        public:
            id0():v(0){}
            id0(ullt v):v(v%p){}
            bol empty(){return!v;}
            inline ullt val(){return v;}
            friend bol operator<(id0 a,id0 b){return a.v<b.v;}
            friend bol operator>(id0 a,id0 b){return a.v>b.v;}
            friend bol operator<=(id0 a,id0 b){return a.v<=b.v;}
            friend bol operator>=(id0 a,id0 b){return a.v>=b.v;}
            friend bol operator==(id0 a,id0 b){return a.v==b.v;}
            friend bol operator!=(id0 a,id0 b){return a.v!=b.v;}
            inline friend id0 operator+(id0 a,id0 b){return a._chg(a.v+b.v);}
            inline friend id0 operator-(id0 a,id0 b){return a._chg(a.v+a.chg(p-b.v));}
            inline friend id0 operator*(id0 a,id0 b){return a.v*b.v;}
            friend id0 operator/(id0 a,id0 b){return b._power(p-2)*a.v;}
            friend id0 operator^(id0 a,ullt b){return a._power(b);}
            inline id0 operator-(){return _chg(p-v);}
            id0 sqrt()
            {
                if(power(v,(p-1)>>1,p)!=1)return 0;
                id0 b=1;do b++;while(b._power((p-1)>>1)==1);
                ullt t=p-1,s=0,k=1;while(!(t&1))s++,t>>=1;
                id0 x=_power((t+1)>>1),e=_power(t);
                while(k<s)
                {
                    if(e._power(1llu<<(s-k-1))!=1)x*=b._power((1llu<<(k-1))*t);
                    e=_power(p-2)*x*x,k++;
                }
                return _min(x,-x),x;
            }
            id0 inv(){return _power(p-2);}
            id0 _power(ullt index){id0 ans(1),w(v);while(index){if(index&1)ans*=w;w*=w,index>>=1;}return ans;}
            voi read(){v=0;chr c;do c=getchar();while(c>'9'||c<'0');do v=(c-'0'+v*10)%p,c=getchar();while(c>='0'&&c<='9');v%=p;}
            voi print()
            {
                static chr C[20];uint tp=0;
                ullt w=v;do C[tp++]=w%10+'0',w/=10;while(w);
                while(tp--)putchar(C[tp]);
            }
            voi println(){print(),putchar('\n');}
            id0 operator++(int){id0 ans=*this;return v=chg(v+1),ans;}
        public:
            inline ullt&operator()(){return v;}
            inline id0&operator+=(id0 b){return*this=_chg(v+b.v);}
            inline id0&operator-=(id0 b){return*this=_chg(v+chg(p-b.v));}
            inline id0&operator*=(id0 b){return*this=v*b.v;}
            id0&operator^=(ullt b){return*this=_power(b);}
            id0&operator/=(id0 b){return*this=b._power(p-2)*v;}
            id0&operator++(){return v=chg(v+1),*this;}
    };
}
const ullt Mod=998244353;
typedef ConstMod::id0<Mod>modint;
modint A[100005],B[100005];
modint CNT[13][12][12],User[12][27][12][12];
uint V[13],QAQ[13];
int main() 

{

    freopen("QAQ.in","r",stdin);

	A[0]=1;for(uint i=1;i<=100000;i++)A[i]=A[i-1]*i;
	B[100000]=A[100000].inv();for(uint i=100000;i;i--)B[i-1]=B[i]*i;
	

	

	

    

	

	

    

    

    

    

    

    

    

    

    

	

	

    

    

    

    

	

	

	

	

    

	

    

    

    CNT[2][1][1]=1;
    CNT[3][2][1]=2;
    CNT[3][3][2]=1;
    CNT[4][3][1]=3;CNT[4][3][2]=1;
    CNT[4][4][1]=1;CNT[4][4][2]=4;
    CNT[4][5][2]=3;
    CNT[4][6][3]=1;
    CNT[5][4][1]=4;CNT[5][4][2]=4;
    CNT[5][5][1]=2;CNT[5][5][2]=12;CNT[5][5][3]=2;
    CNT[5][6][1]=2;CNT[5][6][2]=12;CNT[5][6][3]=4;
    CNT[5][7][2]=9;CNT[5][7][3]=6;
    CNT[5][8][2]=3;CNT[5][8][3]=6;
    CNT[5][9][3]=4;
    CNT[5][10][4]=1;
    CNT[6][5][1]=5;CNT[6][5][2]=10;CNT[6][5][3]=1;
    CNT[6][6][1]=3;CNT[6][6][2]=28;CNT[6][6][3]=13;
    CNT[6][7][1]=4;CNT[6][7][2]=35;CNT[6][7][3]=29;CNT[6][7][4]=1;
    CNT[6][8][1]=3;CNT[6][8][2]=35;CNT[6][8][3]=41;CNT[6][8][4]=4;
    CNT[6][9][1]=1;CNT[6][9][2]=30;CNT[6][9][3]=44;CNT[6][9][4]=7;
    CNT[6][10][2]=17;CNT[6][10][3]=45;CNT[6][10][4]=7;
    CNT[6][11][2]=8;CNT[6][11][3]=30;CNT[6][11][4]=11;
    CNT[7][6][1]=6;CNT[7][6][2]=20;CNT[7][6][3]=6;
    CNT[7][7][1]=4;CNT[7][7][2]=55;CNT[7][7][3]=50;CNT[7][7][4]=3;
    CNT[7][8][1]=6;CNT[7][8][2]=80;CNT[7][8][3]=118;CNT[7][8][4]=18;
    CNT[7][9][1]=6;CNT[7][9][2]=95;CNT[7][9][3]=186;CNT[7][9][4]=48;
    CNT[7][10][1]=6;CNT[7][10][2]=101;CNT[7][10][3]=230;CNT[7][10][4]=85;CNT[7][10][5]=2;
    CNT[7][11][1]=2;CNT[7][11][2]=94;CNT[7][11][3]=260;CNT[7][11][4]=113;CNT[7][11][5]=4;
    CNT[8][7][1]=7;CNT[8][7][2]=35;CNT[8][7][3]=21;CNT[8][7][4]=1;
    CNT[8][8][1]=5;CNT[8][8][2]=96;CNT[8][8][3]=145;CNT[8][8][4]=26;
    CNT[8][9][1]=8;CNT[8][9][2]=155;CNT[8][9][3]=358;CNT[8][9][4]=124;CNT[8][9][5]=3;
    CNT[8][10][1]=9;CNT[8][10][2]=207;CNT[8][10][3]=616;CNT[8][10][4]=313;CNT[8][10][5]=16;
    CNT[8][11][1]=11;CNT[8][11][2]=250;CNT[8][11][3]=859;CNT[8][11][4]=567;CNT[8][11][5]=53;
    CNT[9][8][1]=8;CNT[9][8][2]=56;CNT[9][8][3]=56;CNT[9][8][4]=8;
    CNT[9][9][1]=6;CNT[9][9][2]=154;CNT[9][9][3]=350;CNT[9][9][4]=126;CNT[9][9][5]=4;
    CNT[9][10][1]=10;CNT[9][10][2]=268;CNT[9][10][3]=898;CNT[9][10][4]=552;CNT[9][10][5]=48;
    CNT[9][11][1]=12;CNT[9][11][2]=389;CNT[9][11][3]=1654;CNT[9][11][4]=1404;CNT[9][11][5]=204;CNT[9][11][6]=1;
    CNT[10][9][1]=9;CNT[10][9][2]=84;CNT[10][9][3]=126;CNT[10][9][4]=36;CNT[10][9][5]=1;
    CNT[10][10][1]=7;CNT[10][10][2]=232;CNT[10][10][3]=742;CNT[10][10][4]=448;CNT[10][10][5]=43;
    CNT[10][11][1]=12;CNT[10][11][2]=427;CNT[10][11][3]=1967;CNT[10][11][4]=1887;CNT[10][11][5]=357;CNT[10][11][6]=6;
    CNT[11][10][1]=10;CNT[11][10][2]=120;CNT[11][10][3]=252;CNT[11][10][4]=120;CNT[11][10][5]=10;
    CNT[11][11][1]=8;CNT[11][11][2]=333;CNT[11][11][3]=1428;CNT[11][11][4]=1302;CNT[11][11][5]=252;CNT[11][11][6]=5;
    CNT[12][11][1]=11;CNT[12][11][2]=165;CNT[12][11][3]=462;CNT[12][11][4]=330;CNT[12][11][5]=55;CNT[12][11][6]=1;
    

    

    

	User[0][0][0][0]=1;
	for(uint p=1;p<=11;p++)for(uint i=1;i<=12;i++)for(uint j=1;j<=11;j++)for(uint k=1;k<=11;k++)
        for(uint q=24;q>=i;q--)for(uint u=11;u>=j;u--)for(uint v=11;v>=k;v--)
            User[p][q][u][v]+=User[p-1][q-i][u-j][v-k]*CNT[i][j][k];
    uint t;scanf("%u",&t);
    while(t--)
    {
    	uint n,k,t;
    	scanf("%u%u%u",&n,&k,&t);
    	auto binom=[&](uint n,uint k)->modint
    	{
    		if(n<k||n>Mod||k>Mod)return 0;
    		modint ans=B[k];
    		for(uint i=n-k+1;i<=n;i++)ans*=i;
    		return ans;
    	};
    	modint ans;
    	for(uint i=1;i<=22&&i<=n;i++)for(uint j=1;j<=11;j++)ans+=binom(n-i+j,j)*User[j][i][k][t];
	    ans.println();
    }
    return 0; 
}

