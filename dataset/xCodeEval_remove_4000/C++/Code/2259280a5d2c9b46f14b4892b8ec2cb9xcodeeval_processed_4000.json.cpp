














using namespace std;










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

ll as,cs,rs;
ll am,cm,rm;
ll N,D;


vector<long>primes;
vector<long>id8;
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
vector< long> id7(unsigned long maxN){

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

long bff[1100];
long inq[1010];
long source;
long id5=0,id9=0,id3,id4;
typedef pair<long,long>ee;
typedef pair<long,ee>openAns;
vector<openAns>id6;
long bigEntry,bigExit,smallEntry,smallExit;

long dfs(long node,long curLen){
    if(inq[node]==0){
        inq[node]=1;
        dfs(bff[node],curLen+1);
    }
    else if(node==source)
    {
        if(id4<curLen)
            id4=curLen;
    }
    else if(bff[bff[node]]==node){
        curLen-=2;
        openAns oA;
        oA.first=curLen;
        oA.second.first=bff[node];
        oA.second.first=node;
        id6.push_back(oA);
    }
  

  return 0;
}
long dp[10010][5];
long wordLen;
string s1,s2,s3;
long perMutation[20];
ll a[20],b[20],n,k;
typedef pair<long,long>party;
party parties[30];
vector<long>shirtsseq;
vector<long>pantseq;
vector<long>id2;
long shirtpantcombo[110];
long shirtjacketcombo[110];
long jacketpantcombo[110];
long S,J,P,K;
int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal,m;
	

	

	cout << setprecision(15) << fixed;
	ll tta=0;
	string s;
	ll charcount[30];
	memset(charcount,0,sizeof(charcount));
    for(long T=0;T<test_cases;T++){
        cin>>N;
        cin>>s;
        ll ans=0;
        if(s.size()>26){
            cout<<-1;
            return 0;
        }
        for(long i=0;i<s.size();i++){
            if(charcount[s[i]-'a']==0)
                charcount[s[i]-'a']=1;
            else
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
