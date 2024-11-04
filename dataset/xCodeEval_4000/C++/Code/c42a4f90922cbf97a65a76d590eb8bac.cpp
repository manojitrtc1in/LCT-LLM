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
double dp[2][2];
long nextRight[2012];
long nextLeft[2012];
ll treepos[20];
ll H,N;
ll h[2],maxvals[6],minvals[2],curMax=-1,curMin=11111111111;
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
    

}
ll getMaxelement(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return 0;
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
ll le,ri;


double angle[1];
vector<ll>nvals;
vector<ll>mvals;
ll n,p;
string s;
bool isValidChar(long pos,char ch){
    if(pos==0)
        return true;
    if(pos==1){
        if(s[0]!=ch)
            return true;
        return false;
    }
    if(s[pos-1]!=ch&&s[pos-2]!=ch)
        return true;
    return false;
}
char nextChar(long pos){
    char lim='a'+p,sChar=s[pos];
    sChar++;
    for(char ch=s[pos]+1;ch<('a'+p);ch++){
        if(isValidChar(pos,ch))
            return ch;
    }
    return s[pos];
}
void buildNext(long startPos){
    for(long i=startPos;i<n;i++){
        if(s[i-1]!='a'&&(i==1||s[i-2]!='a'))
            s[i]='a';
        else if((i==1||s[i-2]!='b')&&s[i-1]!='b')
            s[i]='b';
        else
            s[i]='c';
    }
}
int main(void){


 

    ll test_cases=1;

 

  

  

    cout << setprecision(15) << fixed;
 

 memset(maxvals,0,sizeof(maxvals));
    ll k,extra,ans=0,cowbells[100005],curSize;

    cin>>n>>p;
    cin>>s;
    bool posible=false;
    if(p==1){
        cout<<"NO"<<endl;
        return 0;
    }
    if(p==2){
        if(s[0]=='b')
            cout<<"NO"<<endl;
        else if(n==2)
            cout<<"ba"<<endl;
        else
            cout<<"b"<<endl;
        return 0;
    }

    for(long i=n-1;i>-1;i--){
        char ch=nextChar(i);
        if(ch!=s[i]){
            s[i]=ch;
            buildNext(i+1);
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

