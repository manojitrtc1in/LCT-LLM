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
using namespace std;
#define mdlo 1000000007
#define maxERR 0.00000064


#define maxBits 40
#define pi 3.1415926535897932384626433832795
#define INF 999999999999
typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41],M;
typedef pair<long,long>edge;
typedef vector<long>adjList;
long levels[15];
long nextPoint[15];
long firstDigit[15];
bool inTree[1];
bool visited[1];
struct treeInfo{
    long depth;
    long longestPath;
    long startPointOflongestpath;
    long deepestNode;
    bool included;
};
adjList tree[16];
adjList rails[410];
adjList buses[410];
vector<long>startPoints;


adjList graph[15];
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
ll par[45];
ll getAncestor(ll val){
    if(par[val]!=val)
        par[val]=getAncestor(par[val]);
    return par[val];
}
bool unify(ll a,ll b){
    ll para=getAncestor(a),parb=getAncestor(b);
    if(para==parb)
        return false;
    if(para<parb)
        par[parb]=para;
    else
        par[para]=parb;
    return true;
}
vector<unsigned long> primes;
vector<unsigned long> get_primes(unsigned long max){

    char *sieve;
    sieve = new char[max/8+1];
    

    long m=(max/8)+1;
    for(long long i=0;i<m;i++)
        sieve[i]=255;
    for(unsigned long x = 2; x <= max; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            

            for(unsigned long j = 2*x; j <= max; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
    return primes;
}
long dp[600000];
long nextRight[2012];
long nextLeft[2012];
ll treepos[20];
long L,S,N;
ll h[100005],maxvals[600000],minvals[600000],curMax=-1,curMin=11111111111;
ll lPoint[2],rPoint[2];
long railMatrix[410][410];
bool isPrime(long N){
    if(N==1)
    return false;
    if(N<4)
        return true;
    for(long i=2;i*i<N;i++){
        if(N%i==0)
            return false;
    }
    return true;
}
ll gcd(ll a,ll b){
    ll c;
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
    if(a==0)
        return b;
    c=b%a;
    while(c>0){
        b=a;
        a=c;
        c=b%a;
    }
    return a;
}
long long getLcm(long long a,long long b){
    long long c=a/gcd(a,b);
    return b*c;
}
void buildSegmentTree(long long b,long long e,long long node){
    if(b==e)
    {
        maxvals[node]=h[b];
        minvals[node]=h[b];
         return;
    }
    long long mid=(b+e)/2;
    buildSegmentTree(b,mid,node*2);
    buildSegmentTree(mid+1,e,1+(node*2));
    maxvals[node]=max(maxvals[2*node],maxvals[1+(node*2)]);
    minvals[node]=min(minvals[2*node],minvals[(1+(2*node))]);
}
ll getMaxelement(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return -10000000000000;
    if(b>=qb&&e<=qe)
        return maxvals[node];
    ll m=(b+e)/2;
    ll f=getMaxelement(b,m,node*2,qb,qe),s=getMaxelement(m+1,e,1+(node*2),qb,qe);
    return max(f,s);
}
ll getMinelement(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return 10000000000000;
    if(b>=qb&&e<=qe)
        return minvals[node];
    ll m=(b+e)/2;
    ll f=getMinelement(b,m,node*2,qb,qe),s=getMinelement(m+1,e,1+(node*2),qb,qe);
    return min(f,s);
}

long getDiff(long startPoint,long endPoint){
    return getMaxelement(0,N-1,1,startPoint,endPoint)-getMinelement(0,N-1,1,startPoint,endPoint);
}
long getStrips(long pos){
    if(dp[pos]==0){
        dp[pos]=-1;
        if(pos+L>N)
            return dp[pos];
        if(pos+L==N){
            if(getDiff(pos,N-1)<=S)
                dp[pos]=1;
            return dp[pos];
        }
        if(getDiff(pos,N-1)<=S){
            dp[pos]=1;
            return dp[pos];
        }
        long endPos=pos+L-1;
      

        while(getDiff(pos,endPos)<=S){
            if(getStrips(endPos+1)>0&&(dp[pos]==-1||dp[pos]>dp[endPos+1]+1))
                dp[pos]=dp[endPos+1]+1;
            endPos++;
        }
    }
    return dp[pos];
}

double angle[1];
ll n,p;
string s;
bool grid[505][505];
vector<long>idlePos;
long x,y;
bool isvalid(long x0,long y0){
    if(x0<1||y0<1||x0>x||y0>>y)
        return false;
    return true;
}
int main(void){


 

    ll test_cases=1;

 

  

  

    cout << setprecision(15) << fixed;
    long burstPos=-1;
 

    memset(grid,false,sizeof(grid));
    long x0,y0;
    cin>>x>>y>>x0>>y0;
    cin>>s;
    grid[x0][y0]=true;
    idlePos.push_back(-1);
    for(long i=0;i+1<s.length();i++){
        if(s[i]=='U'){
            if(x0>1)
                x0--;
            else
                idlePos.push_back(i+1);
        }
        else if(s[i]=='D'){
            if(x0<x)
                x0++;
            else
                idlePos.push_back(i+1);
        }
        else if(s[i]=='L'){
            if(y0>1)
                y0--;
            else
                idlePos.push_back(i+1);
        }
        else if(y0<y)
            y0++;
        else
            idlePos.push_back(i+1);
        if(grid[x0][y0]&&(idlePos.size()==0||idlePos[idlePos.size()-1]!=i+1))
            idlePos.push_back(i+1);
        grid[x0][y0]=true;
    }
    for(long i=1;i<idlePos.size();i++){

        for(long j=idlePos[i-1]+1;j<idlePos[i];j++)
            cout<<1<<" ";
        cout<<"0 ";
    }
    for(long j=idlePos[idlePos.size()-1]+1;j<s.length();j++){
        cout<<"1 ";
    }
    cout<<x*y+idlePos.size()-s.length()-1;

    

    return 0;
}

