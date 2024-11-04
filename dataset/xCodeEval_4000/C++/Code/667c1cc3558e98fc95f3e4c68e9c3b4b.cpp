#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include <iomanip>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<math.h>
#include <time.h>
using namespace std;


#define mdlo 1000000007
#define maxERR 0.000000002


#define maxBits 40
#define pi 3.1415926535897932384626433832795
#define INF 999999999999
#define lim 10000007
typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>numPos;
typedef vector<long>adjList;
typedef pair<long,long>edge;
vector<edge>criticalEdges;
adjList Graph[29];


ll segTree[700003];
long nums[5005];
long g[5005];

ll N,D;


vector<long>primes;
vector<long>badPrimes;
long funcVal[1];
long dfs_num[29],dfs_low[29],visited[29],parent[19],criticalNode[19];
set<string>dictionary;
set<string>::iterator it;
pair<set<string>::iterator,bool> ret;
typedef multiset<long> numset;
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
long long getmoduloInv(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=getmoduloInv(mdlo%n);
    mInv[n]=(m%mdlo);
    return mInv[n];
}
vector< long> get_primes(unsigned long maxN){

    char *sieve;
    sieve = new char[maxN/8+1];
    

    long m=(maxN/8)+1;
    for(long long i=0;i<m;i++)
        sieve[i]=255;
    for(unsigned long x = 2; x <= maxN; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            

            for(unsigned long j = 2*x; j <= maxN; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
    return primes;
}
ll getPow(ll b,ll p){
	if(b<2||p==1)
		return b;
	if(p==0)
		return 1;
	ll val=getPow(b,p/2);
	val*=val;
	val%=mdlo;
	if(p%2==1){
		val*=b;
		val%=mdlo;
	}
	return val;
}

ll dp[100010];
ll a[100005];
void buildSegTree(long node,long b,long e){
    if(b==e)
        segTree[node]=b;
    else{
        long mid=(b+e)/2;
        buildSegTree(node*2,b,mid);
        buildSegTree(1+node*2,mid+1,e);
        if(a[segTree[node*2]]>a[segTree[1+node*2]])
            segTree[node]=segTree[node*2];
        else
            segTree[node]=segTree[1+node*2];
    }
}
long long getMax(long node,long segBeg,long segEnd,long qBeg,long qEnd){
    if(node==39879){
        long aa=1;
        aa++;
    }
    if(segEnd<qBeg||segBeg>qEnd)
        return 0;
    if(segBeg>=qBeg&&segEnd<=qEnd)
        return segTree[node];
    long mid=(segBeg+segEnd)/2;
    long fh=getMax(node*2,segBeg,mid,qBeg,qEnd);
    long sh=getMax(1+node*2,mid+1,segEnd,qBeg,qEnd);
    if(a[sh]>a[fh])
        return sh;
    return fh;
}

long bff[1100];
long inq[1010];
long source;
long oneEndBig=0,oneEndSmall=0,twoendans,zeroendans;
typedef pair<long,long>ee;
typedef pair<long,ee>openAns;
vector<openAns>allopenANs;
long bigEntry,bigExit,smallEntry,smallExit;

long dfs(long node,long curLen){
    if(inq[node]==0){
        inq[node]=1;
        dfs(bff[node],curLen+1);
    }
    else if(node==source)
    {
        if(zeroendans<curLen)
            zeroendans=curLen;
    }
    else if(bff[bff[node]]==node){
        curLen-=2;
        openAns oA;
        oA.first=curLen;
        oA.second.first=bff[node];
        oA.second.first=node;
        allopenANs.push_back(oA);
    }
  

  return 0;
}
ll getWays(ll startingStaion){
    if(dp[startingStaion]==-1){
        if(a[startingStaion]==N)
            dp[startingStaion]=(N-startingStaion);
        else{
            ll nextstation=getMax(1,1,N-1,startingStaion+1,a[startingStaion]);
            dp[startingStaion]=(nextstation-startingStaion)+getWays(nextstation)+N-a[startingStaion];
        }
    }
    return dp[startingStaion];
}
set<ll>nodes;
int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal,m;
	

	

	cout << setprecision(15) << fixed;
    for(long T=0;T<test_cases;T++){
        cin>>N;
        memset(dp,-1,sizeof(dp));
        for(long i=1;i<N;i++)
            cin>>a[i];
        buildSegTree(1,1,N-1);
        ll ans=0;
        for(long i=N-1;i>0;i--)
            ans+=getWays(i);
        for(long i=0;i>0;i--){
            if((N-i)%40==0)
                cout<<endl;
            cout<<dp[i]<<" ";
        }
        cout<<ans<<endl;;
    }
    return 0;
}

