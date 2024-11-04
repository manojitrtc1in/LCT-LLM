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
ll heights[5];
ll segTree[3];
long nums[5005];
long g[5005];


vector<long>primes;
vector<long>badPrimes;
long funcVal[1000006];
ll N;
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
string genMinString(ll val){
	long len=val/9,firstDigit=val%9;
	string s="";
	if(firstDigit>0){
		char ch='0'+firstDigit;
		s=ch+s;
	}
	for(long i=0;i<len;i++)
		s=s+"9";
	return s;

}
typedef vector<long>bigInteger;
long maxBuild;
bigInteger mult(bigInteger A,bigInteger B){
    long len1=A.size(),len2=B.size();
    bigInteger C;
    for(long i=0;i<len1;i++){
        long carry=0;
        for(long j=0;j<len2;j++){
            long pos=i+j;
            long val=carry+(A[i]*B[j]);
            carry=val/10;
            val=val%10;
            if(pos>=C.size()){
                C.push_back(val);
            }
            else{
                C[pos]+=val;
                carry=C[pos]/10;
                C[pos]=C[pos]%10;
            }
        }
        if(carry>0)
            C.push_back(carry);
    }
    return C;
}
bigInteger getVal(long power){
    bigInteger C;
    C.push_back(5);
    if(power==1)
        return C;
    bigInteger B=getVal(power/2);
    B=mult(B,B);
    if(power%2==1)
        B=mult(B,C);
    return B;
}
long getZeros(long fives){
    long ans=0;
    while(fives>0){
        ans+=fives;
        fives/=5;
    }
    return ans;
}
ll getPow(long zeros){
    long val=((zeros*4)/5)-1;
    while(getZeros(val)<zeros)
        val++;
    if(getZeros(val)==zeros)
        return val;
    return -1;
}
ll rowVal[5050],colVal[5050];
ll rowAlter[5050],colAlter[5050];
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,maxVal;
	

	vector<string>originalStrings;
	ll curNum;
	ll m,n,k;
	ll ans=0;


  for(long T=0;T<test_cases;T++){
	   cin>>n>>m>>k;
	   long rv,cv,av;
	   memset(rowVal,0,sizeof(rowVal));
	   memset(colVal,0,sizeof(colVal));
	   memset(rowAlter,-1,sizeof(rowAlter));
	   memset(colAlter,-1,sizeof(colAlter));
	   for(long i=0;i<k;i++){
        scanf("%ld",&av);
        scanf("%ld",&rv);
        rv--;
        scanf("%ld",&cv);
        if(av==1){
            rowVal[rv]=cv;
            rowAlter[rv]=i;
        }
        else{
            colVal[rv]=cv;
            colAlter[rv]=i;
        }
	   }
	   for(long i=0;i<n;i++){
        for(long j=0;j<m;j++){
            if(rowAlter[i]>colAlter[j])
                printf("%ld ",rowVal[i]);
            else
                printf("%ld ",colVal[j]);
        }
        cout<<endl;
	   }

        

   }
    return 0;
}

