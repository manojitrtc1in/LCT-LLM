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
typedef pair<edge,long>weightedEdge;
typedef pair<long,edge>outPutEdge;
typedef vector<long>adjList;

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
weightedEdge edges[100005];
outPutEdge finaledges[100005];
long nextNode[100005];
long h[1],maxvals[1],minvals[1];
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

int main(void){


 

    ll test_cases=1;

 

  

    cout << setprecision(15) << fixed;
    long burstPos=-1;
 


    long N,M;
    cin>>N>>M;
    long w,s;
    for(long i=0;i<M;i++){
        cin>>w>>s;
        edges[i].first.first=w;
        edges[i].first.second=-s;
        edges[i].second=i;
        nextNode[i]=i+2;
    }

    sort(edges,edges+M);
    bool posible=true;
    long maxInvalidEdge=0,totalInvalidEdge=0,validEdge=0,invalidEdgeStart=1,saturatedNode=0;
    for(long i=0;i<M;i++){
        if(edges[i].first.second==0){
            totalInvalidEdge++;
            if(totalInvalidEdge>maxInvalidEdge){
                cout<<-1<<endl;
                return 0;
            }
            while(nextNode[invalidEdgeStart]>validEdge+1){
                invalidEdgeStart++;
            }
            finaledges[i].first=edges[i].second;
            finaledges[i].second.first=invalidEdgeStart;
            finaledges[i].second.second=nextNode[invalidEdgeStart];
            nextNode[invalidEdgeStart]++;
            while(nextNode[saturatedNode]>N)
                saturatedNode++;
        }
        else{
            maxInvalidEdge+=validEdge;
            validEdge++;
            finaledges[i].first=edges[i].second;
            finaledges[i].second.first=validEdge;
            finaledges[i].second.second=validEdge+1;
            invalidEdgeStart=saturatedNode+1;

        }
    }
    sort(finaledges,finaledges+M);
    for(long i=0;i<M;i++){
        cout<<finaledges[i].second.first<<" "<<finaledges[i].second.second<<endl;
    }
  

      return 0;
}

