














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
vector<long>id12;
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
vector< long> id11(unsigned long maxN){

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
long id8=0,id13=0,id5,id7;
typedef pair<long,long>ee;
typedef pair<long,ee>openAns;
vector<openAns>id10;
long bigEntry,bigExit,smallEntry,smallExit;

long dfs(long node,long curLen){
    if(inq[node]==0){
        inq[node]=1;
        dfs(bff[node],curLen+1);
    }
    else if(node==source)
    {
        if(id7<curLen)
            id7=curLen;
    }
    else if(bff[bff[node]]==node){
        curLen-=2;
        openAns oA;
        oA.first=curLen;
        oA.second.first=bff[node];
        oA.second.first=node;
        id10.push_back(oA);
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
vector<long>id4;
long shirtpantcombo[110];
long shirtjacketcombo[110];
long jacketpantcombo[110];
long S,J,P,K;
double getDist(ll ax, ll ay,ll bx, ll by){
    double dist=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
    return sqrt(dist);
}
int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal,m;
    ll ax,ay,bx,by,rx,ry,xx,yy,aminpos=0,id9=0,id1=0,id6=0;
    double amin=1000000000000,amin2=1000000000000,bmin=1000000000000,id3=1000000000000;
    double minDist=0,cd,ad,bd,rd;
	

	

	cout << setprecision(15) << fixed;
	ll tta=0;
	string s;
	ll charcount[30];
	memset(charcount,0,sizeof(charcount));
    for(long T=0;T<test_cases;T++){
        cin>>ax>>ay>>bx>>by>>rx>>ry;
        cin>>N;
        for(long i=0;i<N;i++){
            scanf("%lld %lld",&xx,&yy);
            ad=getDist(ax,ay,xx,yy);
            bd=getDist(bx,by,xx,yy);
            cd=getDist(rx,ry,xx,yy);
            ad-=cd;
            bd-=cd;
            minDist+=2*cd;
            if(ad<amin){
                amin2=amin;
                amin=ad;
                id9=aminpos;
                aminpos=i;
            }
            else if(ad<amin2){
                amin2=ad;
                id9=i;
            }
            if(bd<bmin){
                id3=bmin;
                bmin=bd;
                id6=id1;
                id1=i;
            }
            else if(bd<id3){
                id3=bd;
                id6=i;
            }
        }
        if(N==1||amin>0||bmin>0){
            cout<<min(amin,bmin)+minDist;
        }
        else if(aminpos!=id1){
            cout<<minDist+amin+bmin;
        }
        else{
            cout<<minDist+min((min(amin2,(double)0)+bmin),(amin+min(id3,(double)0)));
        }

        

    }
    return 0;
}

