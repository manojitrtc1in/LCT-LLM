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
#define INF 999999999999999999
#define lim 10000007
typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>mymap;
ll nums[1];
ll minSegTree[1];
ll maxSegTree[1];
ll H,R;


typedef pair<ll,ll>cake;
set<cake>cakes;
set<cake>::iterator it;
vector<long>primes;
ll N,S;
set<string>dictionary;


pair<set<cake>::iterator,bool> ret;

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
    if(b==e){
        minSegTree[node]=nums[b];
		maxSegTree[node]=nums[b];
	}
    else{
        long mid=(b+e)/2;
        buildSegTree(node*2,b,mid);
        buildSegTree(1+node*2,mid+1,e);
		minSegTree[node]=min(minSegTree[node*2],minSegTree[1+(2*node)]);
		maxSegTree[node]=max(maxSegTree[node*2],maxSegTree[1+(2*node)]);
    }
}
long long getMin(long node,long segBeg,long segEnd,long qBeg,long qEnd){
    if(segEnd<qBeg||segBeg>qEnd)
        return 10000000000;
    if(segBeg>=qBeg&&segEnd<=qEnd)
        return minSegTree[node];
    long mid=(segBeg+segEnd)/2;
    long fh=getMin(node*2,segBeg,mid,qBeg,qEnd);
    long sh=getMin(1+node*2,mid+1,segEnd,qBeg,qEnd);
    if(sh<fh)
        return sh;
    return fh;
}

long long getMax(long node,long segBeg,long segEnd,long qBeg,long qEnd){
    if(segEnd<qBeg||segBeg>qEnd)
        return -10000000000;
    if(segBeg>=qBeg&&segEnd<=qEnd)
        return maxSegTree[node];
    long mid=(segBeg+segEnd)/2;
    long fh=getMax(node*2,segBeg,mid,qBeg,qEnd);
    long sh=getMax(1+node*2,mid+1,segEnd,qBeg,qEnd);
    if(sh>fh)
        return sh;
    return fh;
}
ll getMaxDis(ll startPoint, ll endPoint){
	ll maxVal=getMax(1,1,N,startPoint,endPoint);
	ll minVal=getMin(1,1,N,startPoint,endPoint);
	return (maxVal-minVal);
}
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,ans=0,maxVal,L;
	

	cout << setprecision(15) << fixed;
   for(long T=0;T<test_cases;T++){
	   cin>>N;
	   for(long i=0;i<N;i++){
		   cin>>R>>H;
		   ll V=R*R*H;
		   cake c,cc;
		   c.first=V;
		   c.second=V;
		   ret=cakes.insert(c);
		   it=ret.first;
		   if(it!=cakes.begin()){
			   it--;
			   cc=*it;
			   cc.first=V;
			   cc.second+=V;
			   if(cc.second>ans)
				   ans=cc.second;
			   cakes.erase(c);
			   ret=cakes.insert(cc);
			   it=ret.first;
			   it++;
			   c=*it;
			   if(c.first==cc.first){
				   cakes.erase(cc);
			   }
			   else{
				   while(it!=cakes.end()){
					   c=*it;
					   if(c.second>cc.second)
						   break;
					   else{
						   cakes.erase(c);
						   it=cakes.find(cc);
						   it++;
					   }
				   }
			  }
		   }
		   else if(V>ans)
			   ans=V;
	   }
	   double tv=ans;
	   cout<<tv*pi<<endl;
   }
    return 0;
}
