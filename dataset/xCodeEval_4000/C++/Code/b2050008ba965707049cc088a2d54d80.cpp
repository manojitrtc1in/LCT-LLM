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
map<string,long>cityId;
typedef vector<long>adjList;
typedef pair<long,long>edge;
vector<edge>criticalEdges;
adjList Graph[29];
ll heights[5];
ll segTree[3];
long nums[5005];
long g[5005];

ll S[1000006];
ll M[1000006];

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
ll minDIst[20],maxDist1[20];

long getUnevenPos(string s1,string s2){
    for(long i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]&&s1[i]!='?'&&s2[i]!='?')
            return i;
    }
    return -1;
}
pair<string,string> equalizestrings(long startPos,long endPos,string s1,string s2){
    for(long i=startPos;i<=endPos;i++){
        if(s1[i]=='?'){
            if(s2[i]=='?'){
                s2[i]='0';
            }
            s1[i]=s2[i];
        }
        else
            s2[i]=s1[i];
    }
    pair<string,string>s;
    s.first=s1;
    s.second=s2;
    return s;
}
string maximizeString(long startPos,long endPos,string s){
    for(long i=startPos;i<=endPos;i++){
        if(s[i]=='?')
            s[i]='9';
    }
    return s;
}
string minimizeString(long startPos,long endPos,string s){
    for(long i=startPos;i<=endPos;i++){
        if(s[i]=='?')
            s[i]='0';
    }
    return s;
}
bool upPossible(long pos,string s1,string s2){
    if(s1[pos]!='?'){
        if(s2[pos]!='?'||s1[pos]=='0')
            return false;
        return true;
    }
    if(s2[pos]=='9')
        return false;
    return true;
}
pair<string,string>  upPrevPos(long pos,string s1,string s2){
    pos--;
    while(pos>=0&&!upPossible(pos,s1,s2))
        pos--;
    if(pos>=0){
        if(s2[pos]=='?'){
            if(s1[pos]=='?'){
                s1[pos]='1';
                s2[pos]='0';
            }
            else
                s2[pos]=s1[pos]-1;
        }
        s1[pos]=s2[pos]+1;
    }
    pair<string,string>s;
    s.first=s1;
    s.second=s2;
    return s;
}
ll diff(string s1,string s2){
    ll dff=0;
    for(long i=0;i<s1.size();i++){
        ll d=s1[i]-s2[i];
        dff=(dff*10)+d;
    }
    return abs(dff);
}
void convert(){
    long unEvenPos=getUnevenPos(s1,s2);
    long swapCount=0;
    ll mindiff=9999999999999999999;
    pair<string,string>ss;
    if(unEvenPos==-1)
        ss=equalizestrings(0,s1.size()-1,s1,s2);
    else{

        ss=equalizestrings(0,unEvenPos-1,s1,s2);
        if(s1[unEvenPos]>s2[unEvenPos]){
            ss.second=maximizeString(unEvenPos+1,s1.size()-1,ss.second);
            ss.first=minimizeString(unEvenPos+1,s1.size()-1,ss.first);
            mindiff=diff(ss.first,ss.second);
            pair<string,string> ss2;
            ss2=upPrevPos(unEvenPos,s2,s1);
            unEvenPos=getUnevenPos(ss2.first,ss2.second);
            ss2=equalizestrings(0,unEvenPos-1,ss2.first,ss2.second);
            ss2.second=maximizeString(unEvenPos+1,s1.size()-1,ss2.second);
            ss2.first=minimizeString(unEvenPos+1,s1.size()-1,ss2.first);
            if(mindiff>diff(ss2.first,ss2.second)||(mindiff==diff(ss2.first,ss2.second)&&(ss2.second<ss.first||(ss2.second==ss.first&&ss2.first<ss.second)))){
                ss.first=ss2.second;
                ss.second=ss2.first;
            }
        }
        else{
            ss.first=maximizeString(unEvenPos+1,s1.size()-1,ss.first);
            ss.second=minimizeString(unEvenPos+1,s1.size()-1,ss.second);
            mindiff=diff(ss.first,ss.second);
            pair<string,string> ss2;
            ss2=upPrevPos(unEvenPos,s1,s2);
            unEvenPos=getUnevenPos(ss2.first,ss2.second);
            ss2=equalizestrings(0,unEvenPos-1,ss2.first,ss2.second);
            ss2.second=maximizeString(unEvenPos+1,s1.size()-1,ss2.second);
            ss2.first=minimizeString(unEvenPos+1,s1.size()-1,ss2.first);
            if(mindiff>diff(ss2.first,ss2.second)||(mindiff==diff(ss2.first,ss2.second)&&(ss2.first<ss.first||(ss2.first==ss.first&&ss2.second<ss.second)))){
                ss=ss2;
            }
        }
    }
    cout<<ss.first<<" "<<ss.second<<endl;
}
ll a[100005],b[100005],n,k;
long isFeasible(ll cookis){
    ll remain=k;
    for(long i=0;i<n;i++){
      ll req=a[i]*cookis;
      if(req>b[i]){
        remain+=(b[i]-req);
        if(remain<0)
            return 0;
      }
    }
    return 1;
}
int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal;
	

	

	cout << setprecision(15) << fixed;
    for(long T=0;T<test_cases;T++){

        cin>>n>>k;
        for(long i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(long i=0;i<n;i++){
            scanf("%lld",&b[i]);
        }
        ll maxcookies=b[0]+k,minCookies=0,mid;
        while(maxcookies>minCookies+1){
            mid=(maxcookies+minCookies)/2;
            if(isFeasible(mid))
                minCookies=mid;
            else
                maxcookies=mid-1;
        }
        while(isFeasible(minCookies+1))
            minCookies++;
        cout<<minCookies<<endl;
        

      



        

        

    }
    return 0;
}

