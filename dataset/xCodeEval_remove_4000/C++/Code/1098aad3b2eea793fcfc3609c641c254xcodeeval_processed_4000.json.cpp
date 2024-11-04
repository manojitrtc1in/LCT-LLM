














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

ll S[1000006];
ll M[1000006];

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
bool isvalid(long pos,long prev){
    if(dp[pos][prev]==0)
        return false;
    if(dp[pos][prev]==1)
        return true;
    ll remaining=wordLen-(pos);
    if(remaining==0)
        return true;
    if(remaining==1||remaining<0)
        return false;
    if(prev==2){
        if(remaining%5==0||remaining%5==3||isvalid(pos+3,3)||remaining==3){
        dp[pos][prev]=1;
        return true;
        }
        if(s1[pos]!=s1[pos-2]||s1[pos+1]!=s1[pos-1]){
            return isvalid(pos+2,2);
        }
        return false;
    }
    if(prev==3){
        if(isvalid(pos+2,2)){
            dp[pos][prev]=1;
            return true;
        }
        for(long i=0;i<3;i++)
        {
            if(s1[pos+i]!=s1[pos+i-3]){
                if(isvalid(pos+3,3)){
                    dp[pos][prev]=1;
                    return true;
                }
                else{
                    dp[pos][prev]=0;
                    return false;
                }
            }
        }
        return false;
    }

}
long perMutation[20];


long id1(string s){
    if(s.length()<7){
        cout<<0<<endl;
        return 0;
    }
    wordLen=s.size();

    for(long i=5;i+1<s.length();i++){
        if(i==1005){
            s2="";
        }
        s2="";
        s2+=s1[i];
        s2+=s1[i+1];
        s3=s2;
        if(i+2<s.length())
        s3+=s1[i+2];
        if(isvalid(i+2,2))
            dictionary.insert(s2);
        if(isvalid(i+3,3))
            dictionary.insert(s3);
    }

    
    cout<<dictionary.size()<<endl;
    set<string>::iterator it=dictionary.begin();
    while(it!=dictionary.end()){
        cout<<*it<<endl;
        it++;
    }

}
ll id1(long pos){
    ll remaining=wordLen-(pos+1);
    if(remaining<2)
        return 0;
    if(remaining<4){
        s2="";
        s2+=s1[pos];
        s2+=s1[pos+1];
        if(remaining==3)
            s2+=s1[pos+2];
        dictionary.insert(s2);
        return 1;
    }

}
int main(void){
    

    

    ll test_cases=1,l,seed=1,maxVal;
	

	

    cout << setprecision(15) << fixed;
    memset(dp,-1,sizeof(dp));
    long num;
    ll sum=0,ans=1,maxlen=0,leng;
    double d,h,e,v,area,rainVol;
    for(long T=0;T<test_cases;T++){

        cin>>s1;
        id1(s1);
        


        

        

        

    }
    return 0;
}

