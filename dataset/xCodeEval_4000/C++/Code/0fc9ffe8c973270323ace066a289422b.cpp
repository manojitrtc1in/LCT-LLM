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
string getNextGreater(string current,ll change){
	long len=current.size();
	string nxt=current;
	if(change>0){
		for(long i=len-1;i>-1;i--){
			ll rem='9'-current[i];
			if(rem<change){
				nxt[i]+=rem;
				change-=rem;
			}
			else{
				nxt[i]+=change;
				return nxt;
			}
		}
		while(change>9){
			change-=9;
			nxt="9"+nxt;
		}
		char ch='0'+change;
		nxt=ch+nxt;
		return nxt;
	}
}

string getNextLess(string current,ll val){
	long total=0;
	long pos;
	for(long i=0;i<current.size();i++){
		total+=(current[i]-'0');
		if(total>=val){
			current[i]-=(total+1-val);
			pos=i-1;
			break;
		}
	}
	while(pos>-1&&current[pos]=='9')
		pos--;
	if(pos>-1){
		current[pos]++;
		for(long i=pos+1;i<current.size();i++)
			current[i]='0';
	}
	else{
		for(long i=0;i<current.size();i++)
			current[i]='0';
		current="1"+current;
	}
	for(long i=0;i<current.size();i++)
		val-=(current[i]-'0');
	if(val>0)
		return getNextGreater(current,val);
	return current;

}
string getNextEqual(string current,long val){
	long len=current.size(),pos;
	pos=len-1;
	while(pos>-1&&current[pos]=='9'){
		current[pos]='0';
		pos--;
	}
	if(pos>-1)
		current[pos]++;
	else
		current="1"+current;
	long total=0;
	for(long i=0;i<len;i++)
		total+=(current[i]-'0');
	if(total>val)
		return getNextLess(current,val);
	return getNextGreater(current,val-total);
}
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,ans,maxVal;
	

	vector<string>originalStrings;
	ll curNum;
	long b[400];
   for(long T=0;T<test_cases;T++){
	   cin>>N>>b[0];
	   originalStrings.push_back(genMinString(b[0]));
	   for(long i=1;i<N;i++){
		   cin>>b[i];
		   if(b[i]>b[i-1])
			   originalStrings.push_back(getNextGreater(originalStrings[i-1],b[i]-b[i-1]));
		   else if(b[i]<b[i-1])
			   originalStrings.push_back(getNextLess(originalStrings[i-1],b[i]));
		   else
			   originalStrings.push_back(getNextEqual(originalStrings[i-1],b[i]));
	   }
	   for(long i=0;i<N;i++)
		   cout<<originalStrings[i]<<endl;
   }
    return 0;
}
