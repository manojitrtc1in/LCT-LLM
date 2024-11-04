













using namespace std;







typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41],M;
typedef pair<long,long>edge;
typedef pair<edge,long>weightedEdge;
typedef pair<long,edge>outPutEdge;
typedef vector<long>adjList;

long long id3(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=id3(mdlo%n);
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
vector<unsigned long> id1(unsigned long max){

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
long long id4(long long a,long long b){
    long long c=a/gcd(a,b);
    return b*c;
}
void id5(long long b,long long e,long long node){
    if(b==e)
    {
        maxvals[node]=h[b];
        minvals[node]=h[b];
         return;
    }
    long long mid=(b+e)/2;
    id5(b,mid,node*2);
    id5(mid+1,e,1+(node*2));
    maxvals[node]=max(maxvals[2*node],maxvals[1+(node*2)]);
    minvals[node]=min(minvals[2*node],minvals[(1+(2*node))]);
}
ll id2(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return -10000000000000;
    if(b>=qb&&e<=qe)
        return maxvals[node];
    ll m=(b+e)/2;
    ll f=id2(b,m,node*2,qb,qe),s=id2(m+1,e,1+(node*2),qb,qe);
    return max(f,s);
}
ll id6(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return 10000000000000;
    if(b>=qb&&e<=qe)
        return minvals[node];
    ll m=(b+e)/2;
    ll f=id6(b,m,node*2,qb,qe),s=id6(m+1,e,1+(node*2),qb,qe);
    return min(f,s);
}
multiset<long>villains;
long villainsPow[200005];
bool id0(long heroPower){
    if(villains.empty())
        return false;
    multiset<long>::iterator it=villains.find(-1*heroPower);
    if(it!=villains.end()){
        villains.erase(it);
        return true;
    }
    villains.insert(-1*heroPower);
    it=villains.find(-1*heroPower);
    it++;
    if(it!=villains.end()){
        villains.erase(it);
        villains.erase(0-heroPower);
        return true;
    }
        villains.erase(0-heroPower);
    return false;
}
int main(void){


 

    ll test_cases=1;

 

  

    cout << setprecision(15) << fixed;
    long burstPos=-1;
 

    long heroes[8];
    long N,M;
    cin>>N;
    cin>>heroes[0]>>heroes[1]>>heroes[2];
    long capable[3];
    capable[0]=capable[1]=0;
    sort(heroes,heroes+3);
    heroes[3]=heroes[0]+heroes[1];
    heroes[4]=heroes[0]+heroes[2];
    heroes[5]=heroes[2]+heroes[1];
    heroes[6]=heroes[0]+heroes[1]+heroes[2];
    capable[0]=capable[1]=capable[2]=0;
    for(long i=0;i<N;i++){
        cin>>villainsPow[i];
        villains.insert(villainsPow[i]*-1);
    }
    sort(villainsPow,villainsPow+N);

    if(villainsPow[N-1]>heroes[6]){
        cout<<-1<<endl;
        return 0;
    }
    long ans=0,endPos=N-1,startPos=0;
    while(endPos>-1&&villainsPow[endPos]>heroes[5]&&!villains.empty()){        
        villains.erase(-1*villainsPow[endPos]);
        endPos--;
        ans++;
    }
    while(endPos>=startPos&&villainsPow[endPos]>heroes[4]&&!villains.empty()){
        ans++;
        endPos--;
        id0(heroes[5]);
        id0(heroes[0]);
    }
    while(endPos>=startPos&&villainsPow[endPos]>max(heroes[3],heroes[2])){
        ans++;
        endPos--;
        id0(heroes[4]);
        id0(heroes[1]);
    }
    if(heroes[2]<heroes[3]){
        while(endPos>=startPos&&villainsPow[endPos]>heroes[2]&&!villains.empty()){
            ans++;
            endPos--;
            id0(heroes[3]);
            id0(heroes[2]);
        }
    }
    while(id0(heroes[0])){
        id0(heroes[1]);
        id0(heroes[2]);
        ans++;
    }
    while(!villains.empty()){
        id0(heroes[2]);
        id0(heroes[3]);
        ans++;
    }
    cout<<ans<<endl;
        return 0;
}
