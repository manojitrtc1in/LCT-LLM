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
ll heights[5];
ll segTree[3];
long nums[5005];
long g[5005];

ll as,cs,rs;
ll am,cm,rm;
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
void buildSegTree(long node,long b,long e){
    if(b==e)
        segTree[node]=b;
    else{
        long mid=(b+e)/2;
        buildSegTree(node*2,b,mid);
        buildSegTree(1+node*2,mid+1,e);
        if(heights[segTree[node*2]]<=heights[segTree[1+node*2]])
            segTree[node]=segTree[node*2];
        else
            segTree[node]=segTree[1+node*2];
    }
}
long long getMin(long node,long segBeg,long segEnd,long qBeg,long qEnd){
    if(segEnd<qBeg||segBeg>qEnd)
        return N+1;
    if(segBeg>=qBeg&&segEnd<=qEnd)
        return segTree[node];
    long mid=(segBeg+segEnd)/2;
    long fh=getMin(node*2,segBeg,mid,qBeg,qEnd);
    long sh=getMin(1+node*2,mid+1,segEnd,qBeg,qEnd);
    if(heights[sh]<heights[fh])
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
long dp[10010][5];
long wordLen;
string s1,s2,s3;
long perMutation[20];
ll a[20],b[20],n,k;
typedef pair<long,long>party;
party parties[30];
vector<long>shirtsseq;
vector<long>pantseq;
vector<long>jacketseq;
long shirtpantcombo[110];
long shirtjacketcombo[110];
long jacketpantcombo[110];
long S,J,P,K;
double getDist(ll ax, ll ay,ll bx, ll by){
    double dist=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
    return sqrt(dist);
}
typedef pair<long,long>ancestor;
typedef pair<long,long>nodewpos;
typedef pair<nodewpos,ancestor>node;
set<node>nodes;
long numbers[100005];
int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal,m;
    ll ax,ay,bx,by,rx,ry,xx,yy,aminpos=0,aminpos2=0,bminpos=0,bminpos2=0;
    double amin=1000000000000,amin2=1000000000000,bmin=1000000000000,bmin2=1000000000000;
    double minDist=0,cd,ad,bd,rd;
	

	

	cout << setprecision(15) << fixed;
    for(long T=0;T<test_cases;T++){
        cin>>N;
        ll numb,cumsum=0;
        vector<long>pars;
        pair<set<node>::iterator,bool> ret;
        set<node>::iterator it;
        for(long i=0;i<N;i++){
            scanf("%lld",&numb);
            numbers[i]=numb;
            node nd;
            nodewpos nwp;
            nwp.first=numb;
            nwp.second=i;
            nd.first=nwp;
            ancestor an;
            an.first=-1;
            an.second=-1;
            nd.second=an;
            ret=nodes.insert(nd);
            if(i>0){
                it=ret.first;
                if(it==nodes.begin()){
                    it++;
                    node np=*it;
                    np.second.first=np.first.second;
                    nodes.erase(it);
                    nodes.erase(nd);
                    an.first=-1;
                    an.second=np.first.second;
                    nd.second=an;
                    nodes.insert(nd);
                    nodes.insert(np);
                    pars.push_back(np.first.second);
                }
                else{
                    it++;
                    if(it==nodes.end()){
                        it=ret.first;
                        it--;
                        node np=*it;
                        nodes.erase(it);
                        nodes.erase(nd);
                        np.second.second=np.first.second;
                        an.first=np.first.second;
                        nd.second=an;
                        nodes.insert(nd);
                        nodes.insert(np);
                        pars.push_back(np.first.second);
                    }
                    else{
                        node nextNode=*it;
                        it--;
                        it--;
                        node prevNode=*it;
                        nodes.erase(nd);
                        nodes.erase(nextNode);
                        nodes.erase(prevNode);
                        ll commonancestor=numbers[nextNode.second.first];
                        if(numb>commonancestor){
                            an.first=nextNode.second.first;
                            nextNode.second.first=nextNode.first.second;
                            an.second=nextNode.first.second;
                            pars.push_back(nextNode.first.second);
                        }
                        else{
                            an.first=prevNode.first.second;
                            an.second=nextNode.second.first;
                            prevNode.second.second=prevNode.first.second;
                            pars.push_back(prevNode.first.second);
                        }
                        nodes.insert(nextNode);
                        nodes.insert(nd);
                        nodes.insert(prevNode);
                    }
                }
            }





        }
        for(long i=0;i<pars.size();i++)
            cout<<numbers[pars[i]]<<" ";
    }
    return 0;
}

