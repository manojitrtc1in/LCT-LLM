














using namespace std;










typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<ll,ll>numCnt;
typedef vector<long>adjList;
typedef pair<long,long>edge;
vector<edge>criticalEdges;
adjList Graph[29];
typedef set<long>divisor;
ll heights[5];
ll segTree[3];
vector<long>apos;
vector<long>bpos;
divisor allDivisors[200005];
set<long>::iterator it;

ll N,D;


vector<long>primes;


long funcVal[1];
long dfs_num[29],dfs_low[29],visited[29],parent[19],criticalNode[19];
set<string>dictionary;


pair<set<string>::iterator,bool> ret;
typedef multiset<long> numset;
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
long long id1(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=id1(mdlo%n);
    mInv[n]=(m%mdlo);
    return mInv[n];
}
vector< long> id6(unsigned long maxN){

    char *sieve;
    sieve = new char[maxN/8+1];
    

    long m=(maxN/8)+1;
    set<long>::iterator it2;
    for(long long i=0;i<m;i++)
        sieve[i]=255;
    for(unsigned long x = 2; x <= maxN; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            

            allDivisors[x].insert(1);
            for(unsigned long j = 2*x; j <= maxN; j += x){
                if(sieve[j/8]&(0x01<<(j%8))){
                    sieve[j/8] &= ~(0x01 << (j % 8));
                    allDivisors[j].insert(x);
                }
            }
        }
        else{
            it=allDivisors[x].begin();
            long firstDiv=*it;
            divisor d=allDivisors[x/firstDiv];
            allDivisors[x].insert(x/firstDiv);
            it2=d.begin();
            while(it2!=d.end()){
                long num1=*it2;
                long num2=num1*firstDiv;
                allDivisors[x].insert(num1);
                allDivisors[x].insert(num2);
                it2++;
            }
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
void id0(long node,long b,long e){
    if(b==e)
        segTree[node]=b;
    else{
        long mid=(b+e)/2;
        id0(node*2,b,mid);
        id0(1+node*2,mid+1,e);
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

long bff[1];
long inq[1];
long source;
long id4=0,id7=0,id2,id3;
typedef pair<long,long>ee;
typedef pair<long,ee>openAns;
vector<openAns>id5;
long bigEntry,bigExit,smallEntry,smallExit;

long dfs(long node,long curLen){
    if(inq[node]==0){
        inq[node]=1;
        dfs(bff[node],curLen+1);
    }
    else if(node==source)
    {
        if(id3<curLen)
            id3=curLen;
    }
    else if(bff[bff[node]]==node){
        curLen-=2;
        openAns oA;
        oA.first=curLen;
        oA.second.first=bff[node];
        oA.second.first=node;
        id5.push_back(oA);
    }
  

  return 0;
}
long dp[1][5];
long wordLen;
string s1,s2,s3;
long perMutation[20];
ll a[20],b[20],n,k;
double getDist(ll ax, ll ay,ll bx, ll by){
    double dist=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
    return sqrt(dist);
}

int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal,m;
	

	

	cout << setprecision(15) << fixed;
    ll K;
    

    for(long T=0;T<test_cases;T++){
        string s;
        cin>>N>>K;
        cin>>s;
        ll ac=0,bc=0,ans=min(2*K,N),cnt=0;
        apos.push_back(-1);
        bpos.push_back(-1);
        for(ll i=0;i<N;i++){
            if(s[i]=='a'){
                ac++;
                apos.push_back(i);
            }
            else{
                bc++;
                bpos.push_back(i);
            }
            ans=max(ans,max((i-apos[max((ll)0,ac-K)]),(i-bpos[max((ll)0,bc-K)])));
        }
        cout<<ans<<endl;
    }
    return 0;
}

