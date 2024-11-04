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
typedef pair<ll,ll>skill;
typedef pair<ll,ll>depth;
typedef vector<long>adj;
vector<long>primes;
set<long>candidates;


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
long vals[1000006],n;
ll a,b;
ll removalCost[1000006];

ll getCost(long g){
    memset(removalCost,0,sizeof(removalCost));
    bool removeMust=false;
    ll removeFirst=-1,remLast;
	ll cost=0;
    for(long i=0;i<n;i++){
		long dist=(vals[i]+1)%g;
        if(dist>2){
			removeMust=true;
            if(removeFirst==-1)
				removeFirst=i;
            remLast=i;
        }
        else if(dist!=1)
			cost+=b;
    }
    if(a>=b){       
        if(!removeMust)
            return cost;
    }
    if(removeFirst>-1){
        ll exCost=0,minExCost=0;
        for(long i=removeFirst-1;i>-1;i--){
            exCost+=a;
            if(vals[i]%g!=0)
                exCost-=b;
            if(exCost<minExCost){
                removeFirst=i;
				minExCost=exCost;
			}
        }
        exCost=0,minExCost=0;
        for(long i=remLast+1;i<n;i++){
            exCost+=a;
            if(vals[i]%g!=0)
                exCost-=b;
            if(exCost<minExCost){
                remLast=i;
				minExCost=exCost;
			}
        }
        ll totalCost=(remLast+1-removeFirst)*a;
        for(long i=0;i<removeFirst;i++){
            if(vals[i]%g!=0)
                totalCost+=b;
        }for(long i=remLast+1;i<n;i++){
            if(vals[i]%g!=0)
                totalCost+=b;
        }
        return totalCost;
    }
    if(vals[n-1]%g==0)
        removalCost[n-1]=-a;
    else
        removalCost[n-1]=b-a;
    ll maxremSave=max((ll)0,removalCost[n-1]);
    for(long i=n-2;i>-1;i--){
        if(vals[i]%g==0)
            removalCost[i]=-a;
        else
            removalCost[i]=b-a;
        if(removalCost[i+1]>0)
            removalCost[i]+=removalCost[i+1];
        if(removalCost[i]>maxremSave)
            maxremSave=removalCost[i];
    }
    ll totalCost=0;
    for(long i=0;i<n;i++){
        if(vals[i]%g!=0)
            totalCost+=b;
    }
    return totalCost-maxremSave;
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
void addCandidates(long num){
    long limit=sqrt((double)num)+1;
    for(long i=0;primes[i]<=limit;i++){
        if(num%primes[i]==0){
            candidates.insert(primes[i]);
            while(num%primes[i]==0)
                num/=primes[i];
            limit=sqrt((double)num)+1;
        }
    }
	if(num>1)
		candidates.insert(num);
}
int main(void){




    ll test_cases=1;

 

  

    cout << setprecision(15) << fixed;
	get_primes(32000);
    cin>>n>>a>>b;
    for(long i=0;i<n;i++){
        cin>>vals[i];
    }
    addCandidates(vals[0]);
    addCandidates(vals[0]+1);
    addCandidates(vals[0]-1);
    addCandidates(vals[n-1]);
    addCandidates(vals[n-1]+1);
    addCandidates(vals[n-1]-1);
    ll ans=n*a;
    set<long>::iterator it;
    it=candidates.begin();
    while(it!=candidates.end()){
        long g=*it;
        ll curAns=getCost(g);
        if(curAns<ans)
            ans=curAns;
        it++;
    }
    cout<<ans<<endl;
    return 0;
}

