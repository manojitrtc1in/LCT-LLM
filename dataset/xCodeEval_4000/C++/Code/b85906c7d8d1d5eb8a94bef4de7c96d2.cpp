#pragma GCC optimize(3)
#pragma GCC optimize(2)


#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <map>
#define x first
#define y second
#define debug if(0)
#define Brute if(0)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const ll mod=998244353;


ll read(){
	bool minus=false;
	ll result=0;
	char ch;
	ch=getchar();
	while(true){
		if(ch=='-')break;
		if(ch>='0'&&ch<='9')break;
		ch=getchar();
	}
	if(ch == '-')minus=true;
    else result=ch-'0';
	while(true){
		ch=getchar();
		if(ch<'0'||ch>'9')break;
		result=result*10+(ch-'0');
	}
	if(minus)
		return -result;
	else
		return result;
}
inline ll add(ll x,ll y){
    return ((x+y)%mod+mod)%mod;
}
inline ll mul(ll x,ll y){
    return x*y%mod;
}
inline ll qpow(ll x,ll n){
    ll ret=1ll;
    while(n){
        if(n&1)ret=mul(ret,x);
        x=mul(x,x);
        n>>=1;
    }
    return ret;
}
ll gcd(ll n,ll m){
    return n==0?m:gcd(m%n,n);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}
int N,K,X;
ll cnt[15][15][15],dp[25][15][15][15];
void compute(int pos,int len,vector<int>&p,int inversions,int bad_pair,set<int>&vis){
    if(inversions>11||bad_pair>11)return;
    if(pos>len){
        if(p.front()!=1&&p.back()!=len)++cnt[len][inversions][bad_pair];
        return;
    }
    for(int d=1;d<=len;++d){
        if(vis.count(d))continue;
        int ninv=inversions;
        for(int j:p)if(j>d)++ninv;
        int nbad=bad_pair;
        if(!p.empty()&&p.back()>d)++nbad;
        p.push_back(d);
        vis.insert(d);
        compute(pos+1,len,p,ninv,nbad,vis);
        vis.erase(d);
        p.pop_back();
    }
}
void compute_dp(){
    dp[0][0][0][0]=1;
    

    

    for(int i=0;i<=22;++i){
        for(int j=0;j<=12;++j){
            for(int k=0;k<=12;++k){
                for(int x=0;x<=12;++x){
                    for(int a=2;a<=12;++a){
                        for(int b=1;b<=11;++b){
                            for(int c=1;c<=11;++c){
                                if(i+a<=23&&j+1<=12&&k+b<=12&&x+c<=12){
                                    dp[i+a][j+1][k+b][x+c]=add(
                                        dp[i+a][j+1][k+b][x+c],
                                        mul(dp[i][j][k][x],cnt[a][c][b])
                                    );
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
ll inv[20];
ll C(ll n, ll k){
    if(n<0||k<0||n<k)return 0;
    ll ans=1;
    for(ll x=n;x>=n-k+1;--x)ans=mul(ans,x);
    for(ll x=1;x<=k;++x)ans=mul(ans,inv[x]);
    return ans;
}
int main(){
    for(int i=0;i<20;++i)inv[i]=qpow(i,mod-2);
    int t=read();
    
    
    cnt[2][1][1] = 1;
    cnt[3][1][2] = 2;
    cnt[3][2][3] = 1;
    cnt[4][1][3] = 3;
    cnt[4][1][4] = 1;
    cnt[4][2][3] = 1;
    cnt[4][2][4] = 4;
    cnt[4][2][5] = 3;
    cnt[4][3][6] = 1;
    cnt[5][1][4] = 4;
    cnt[5][1][5] = 2;
    cnt[5][1][6] = 2;
    cnt[5][2][4] = 4;
    cnt[5][2][5] = 12;
    cnt[5][2][6] = 12;
    cnt[5][2][7] = 9;
    cnt[5][2][8] = 3;
    cnt[5][3][5] = 2;
    cnt[5][3][6] = 4;
    cnt[5][3][7] = 6;
    cnt[5][3][8] = 6;
    cnt[5][3][9] = 4;
    cnt[5][4][10] = 1;
    cnt[6][1][5] = 5;
    cnt[6][1][6] = 3;
    cnt[6][1][7] = 4;
    cnt[6][1][8] = 3;
    cnt[6][1][9] = 1;
    cnt[6][2][5] = 10;
    cnt[6][2][6] = 28;
    cnt[6][2][7] = 35;
    cnt[6][2][8] = 35;
    cnt[6][2][9] = 30;
    cnt[6][2][10] = 17;
    cnt[6][2][11] = 8;
    cnt[6][3][5] = 1;
    cnt[6][3][6] = 13;
    cnt[6][3][7] = 29;
    cnt[6][3][8] = 41;
    cnt[6][3][9] = 44;
    cnt[6][3][10] = 45;
    cnt[6][3][11] = 30;
    cnt[6][4][7] = 1;
    cnt[6][4][8] = 4;
    cnt[6][4][9] = 7;
    cnt[6][4][10] = 7;
    cnt[6][4][11] = 11;
    cnt[7][1][6] = 6;
    cnt[7][1][7] = 4;
    cnt[7][1][8] = 6;
    cnt[7][1][9] = 6;
    cnt[7][1][10] = 6;
    cnt[7][1][11] = 2;
    cnt[7][2][6] = 20;
    cnt[7][2][7] = 55;
    cnt[7][2][8] = 80;
    cnt[7][2][9] = 95;
    cnt[7][2][10] = 101;
    cnt[7][2][11] = 94;
    cnt[7][3][6] = 6;
    cnt[7][3][7] = 50;
    cnt[7][3][8] = 118;
    cnt[7][3][9] = 186;
    cnt[7][3][10] = 230;
    cnt[7][3][11] = 260;
    cnt[7][4][7] = 3;
    cnt[7][4][8] = 18;
    cnt[7][4][9] = 48;
    cnt[7][4][10] = 85;
    cnt[7][4][11] = 113;
    cnt[7][5][10] = 2;
    cnt[7][5][11] = 4;
    cnt[8][1][7] = 7;
    cnt[8][1][8] = 5;
    cnt[8][1][9] = 8;
    cnt[8][1][10] = 9;
    cnt[8][1][11] = 11;
    cnt[8][2][7] = 35;
    cnt[8][2][8] = 96;
    cnt[8][2][9] = 155;
    cnt[8][2][10] = 207;
    cnt[8][2][11] = 250;
    cnt[8][3][7] = 21;
    cnt[8][3][8] = 145;
    cnt[8][3][9] = 358;
    cnt[8][3][10] = 616;
    cnt[8][3][11] = 859;
    cnt[8][4][7] = 1;
    cnt[8][4][8] = 26;
    cnt[8][4][9] = 124;
    cnt[8][4][10] = 313;
    cnt[8][4][11] = 567;
    cnt[8][5][9] = 3;
    cnt[8][5][10] = 16;
    cnt[8][5][11] = 53;
    cnt[9][1][8] = 8;
    cnt[9][1][9] = 6;
    cnt[9][1][10] = 10;
    cnt[9][1][11] = 12;
    cnt[9][2][8] = 56;
    cnt[9][2][9] = 154;
    cnt[9][2][10] = 268;
    cnt[9][2][11] = 389;
    cnt[9][3][8] = 56;
    cnt[9][3][9] = 350;
    cnt[9][3][10] = 898;
    cnt[9][3][11] = 1654;
    cnt[9][4][8] = 8;
    cnt[9][4][9] = 126;
    cnt[9][4][10] = 552;
    cnt[9][4][11] = 1404;
    cnt[9][5][9] = 4;
    cnt[9][5][10] = 48;
    cnt[9][5][11] = 204;
    cnt[9][6][11] = 1;
    cnt[10][1][9] = 9;
    cnt[10][1][10] = 7;
    cnt[10][1][11] = 12;
    cnt[10][2][9] = 84;
    cnt[10][2][10] = 232;
    cnt[10][2][11] = 427;
    cnt[10][3][9] = 126;
    cnt[10][3][10] = 742;
    cnt[10][3][11] = 1967;
    cnt[10][4][9] = 36;
    cnt[10][4][10] = 448;
    cnt[10][4][11] = 1887;
    cnt[10][5][9] = 1;
    cnt[10][5][10] = 43;
    cnt[10][5][11] = 357;
    cnt[10][6][11] = 6;
    cnt[11][1][10] = 10;
    cnt[11][1][11] = 8;
    cnt[11][2][10] = 120;
    cnt[11][2][11] = 333;
    cnt[11][3][10] = 252;
    cnt[11][3][11] = 1428;
    cnt[11][4][10] = 120;
    cnt[11][4][11] = 1302;
    cnt[11][5][10] = 10;
    cnt[11][5][11] = 252;
    cnt[11][6][11] = 5;
    cnt[12][1][11] = 11;
    cnt[12][2][11] = 165;
    cnt[12][3][11] = 462;
    cnt[12][4][11] = 330;
    cnt[12][5][11] = 55;
    cnt[12][6][11] = 1;  
    compute_dp();
    while(t--){
        N=read();
        K=read();
        X=read();
        ll ans=0;
        for(int i=2;i<=22;++i){
            for(int j=1;j<=12;++j){
                ll val=dp[i][j][K][X];
                val=mul(val,C(N-i+j,j));
                ans=add(ans,val);
            }
        }
        printf("%lld\n",ans);
    }
}       
