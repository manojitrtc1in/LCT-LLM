













using namespace std;







typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41],M;
typedef pair<long,long>edge;
typedef pair<edge,long>weightedEdge;
typedef pair<long,edge>outPutEdge;
typedef vector<long>adjList;

long long id2(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=id2(mdlo%n);
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
vector<unsigned long> id0(unsigned long max){

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
long long id3(long long a,long long b){
    long long c=a/gcd(a,b);
    return b*c;
}
void id4(long long b,long long e,long long node){
    if(b==e)
    {
        maxvals[node]=h[b];
        minvals[node]=h[b];
         return;
    }
    long long mid=(b+e)/2;
    id4(b,mid,node*2);
    id4(mid+1,e,1+(node*2));
    maxvals[node]=max(maxvals[2*node],maxvals[1+(node*2)]);
    minvals[node]=min(minvals[2*node],minvals[(1+(2*node))]);
}
ll id1(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return -10000000000000;
    if(b>=qb&&e<=qe)
        return maxvals[node];
    ll m=(b+e)/2;
    ll f=id1(b,m,node*2,qb,qe),s=id1(m+1,e,1+(node*2),qb,qe);
    return max(f,s);
}
ll id5(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return 10000000000000;
    if(b>=qb&&e<=qe)
        return minvals[node];
    ll m=(b+e)/2;
    ll f=id5(b,m,node*2,qb,qe),s=id5(m+1,e,1+(node*2),qb,qe);
    return min(f,s);
}
long count1[200005];
int main(void){


 

    ll test_cases=1;

 

  

    cout << setprecision(15) << fixed;
    long burstPos=-1;
 

    long heroes[8];
    long N,M;
    string a,b;
    cin>>a>>b;
    memset(count1,0,sizeof(count1));
    count1[0]=(b[0]-'0');
    for(long i=1;i<b.size();i++){
        if(b[i]=='1')
            count1[i]=count1[i-1]+1;
        else
            count1[i]=count1[i-1];
    }
    ll comp=1+b.size()-a.size();
    ll ans=count1[comp-1];
    if(a[0]=='1')
        ans=comp-ans;
    for(ll j=1;j<a.size();j++){
        ll ones=count1[comp+j-1]-count1[j-1];
        ll mismatch;
        if(a[j]=='1')
            mismatch=comp-ones;
        else
            mismatch=ones;
        ans+=mismatch;
    }
    cout<<ans<<endl;
        return 0;
}
