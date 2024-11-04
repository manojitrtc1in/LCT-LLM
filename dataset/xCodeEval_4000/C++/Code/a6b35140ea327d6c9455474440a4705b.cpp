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
#define maxERR 0.00000002


#define maxBits 40
#define pi 3.1415926535897932384626433832795
#define INF 999999999999
#define lim 10000007
typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>mymap;
ll heights[5005];
ll prevPos[5005];
ll prevHigher[5005];
ll nextHigher[5005];
ll nextBase[5005];
ll prevBase[5005];
ll segTree[30000];


vector<long>primes;
ll N;
set<string>dictionary;
set<string>::iterator it;
pair<set<string>::iterator,bool> ret;

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
vector< long> get_primes(unsigned long max){

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
ll getStrokes(ll prev,ll sPos,ll ePos){
	ll ans=1+ePos-sPos;
	if(true){
		ll baseVal=0,basepos;
		if(prev==0){
			basepos=prevBase[sPos]-1;
			baseVal=heights[basepos];
		}
		else if(prev==1){
			basepos=nextBase[ePos]+1;
			baseVal=heights[basepos];
		}		
		if(prev<0)
			prev++;
	

		ll minHeightPos=getMin(1,1,N,sPos,ePos);
		ll alternateValue=heights[minHeightPos]-baseVal;
		alternateValue+=(min(nextHigher[sPos],ePos)-sPos);
		alternateValue+=(ePos-max(sPos,prevHigher[ePos]));
		if(alternateValue<ans){
			if(prevPos[ePos]<=sPos)
				ans=alternateValue;
			else{
				if(minHeightPos>sPos)
					alternateValue+=getStrokes(1,min(nextHigher[sPos],ePos),minHeightPos-1);
				if(minHeightPos<ePos)
					alternateValue+=getStrokes(0,minHeightPos+1,max(sPos,prevHigher[ePos]));
				if(alternateValue<ans)
					ans=alternateValue;
			}
		}
		
	}
	return ans;
}
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,ans,maxVal;
	

   for(long T=0;T<test_cases;T++){
	   cin>>N>>heights[1];
	   prevPos[1]=1;
	   prevBase[1]=1;
	   prevHigher[1]=1;

	   for(long i=2;i<=N;i++){
		   cin>>heights[i];
		   if(heights[i]==heights[i-1])
			   prevPos[i]=prevPos[i-1];
		   else
			   prevPos[i]=i;
		   if(heights[i]>heights[i-1])
			   prevHigher[i]=prevHigher[i-1];
		   else
			   prevHigher[i]=i;
		   if(heights[i]<heights[i-1])
			   prevBase[i]=prevBase[i-1];
		   else
			   prevBase[i]=i;
	   }
	   nextBase[N]=N;
	   nextHigher[N]=N;
	   for(long i=N-1;i>0;i--){
		   if(heights[i]>heights[i+1])
			   nextHigher[i]=nextHigher[i+1];
		   else
			   nextHigher[i]=i;
		   if(heights[i]<heights[i+1])
			   nextBase[i]=nextBase[i+1];
		   else
			   nextBase[i]=i;
	   }
	   heights[N+1]=(1<<30);
	   buildSegTree(1,1,N);
	   cout<<getStrokes(-1,1,N)<<endl;
   }
    return 0;
}
