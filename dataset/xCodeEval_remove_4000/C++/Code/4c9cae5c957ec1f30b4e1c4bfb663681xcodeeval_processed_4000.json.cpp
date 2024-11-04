













using namespace std;







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
double dp[2][2],p;
long nextRight[2012];
long nextLeft[2012];
ll treepos[20];
ll H,N;
ll h[100005],maxvals[6],minvals[2],curMax=-1,curMin=11111111111;
ll lPoint[100005],rPoint[100005];
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
long long id3(long long a,long long b){
    long long c=a/gcd(a,b);
    return b*c;
}
ll n;
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
    

}
ll id1(ll b, ll e, ll node, ll qb, ll qe){
    if(b>qe||e<qb)
        return 0;
    if(b>=qb&&e<=qe)
        return maxvals[node];
    ll m=(b+e)/2;
    ll f=id1(b,m,node*2,qb,qe),s=id1(m+1,e,1+(node*2),qb,qe);
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
ll le,ri;
ll getVal(long pos){
    ll val,prevLen,nextLen;
    ll low=le,high=pos-1,mid;
    mid=max((low+high)/2,low);
    while(low<=high){
        mid=(low+high)/2;
        if(id1(1,n,1,mid,pos-1)<h[pos])
            high=mid-1;
        else
            low=mid+1;
    }
    while(mid<pos&&id1(1,n,1,mid,pos-1)>=h[pos])
        mid++;
    prevLen=pos-mid;
    low=pos+1,high=ri;
    mid=min((low+high)/2,high);
    while(low<=high){
        mid=(low+high)/2;
        if(id1(1,n,1,mid,pos-1)<=h[pos])
            low=mid+1;
        else
            high=mid-1;
    }
    while(mid>pos&&id1(1,n,1,pos+1,mid)>h[pos])
        mid--;
    nextLen=mid-pos;
   return ((prevLen+1)*(1+nextLen))*h[pos];
}

double angle[1];
vector<ll>nvals;
vector<ll>mvals;
int main(void){


 

    ll test_cases=1;

 

  

  

    cout << setprecision(15) << fixed;
 

 memset(maxvals,0,sizeof(maxvals));
 ll bx,by,x=0,y=0,p=1,d,m,f;
 string s,curWord;
 vector<string>words;
 vector<string>numbers;
 bool isNumber=true;
 long cnts[26],odds=0,id5;
 memset(cnts,0,sizeof(cnts));
 long minDistByBus[410],minDistByTrain[410];
    for(long T=0;T<test_cases;T++){
        cin>>s;
        for(long i=0;i<s.size();i++)
            cnts[s[i]-'a']++;
        for(long i=0;i<26;i++){
            if(cnts[i]%2==1)
                odds++;
        }
        id5=odds/2;
        vector<char>oddChars;
        for(long i=0;i<26;i++)
        {
            if(cnts[i]%2==1)
                oddChars.push_back('a'+i);
        }
        for(long i=0;i<id5;i++)
            cnts[oddChars[i]-'a']++;
        for(long i=id5+s.size()%2;i<odds;i++){
            cnts[oddChars[i]-'a']--;
        }
        char midchar='x';
        for(long i=0;i<26;i++){
            char ch='a'+i;
            for(long j=0;j<cnts[i]/2;j++){
                cout<<ch;
            }
            if(cnts[i]%2==1){
                midchar='a'+i;
            }
        }
        if(s.size()%2==1){
            cout<<midchar;
        }
        for(long i=25;i>-1;i--){
            char ch='a'+i;
            for(long j=0;j<cnts[i]/2;j++)
                cout<<ch;
        }
        cout<<endl;

     

    }
    return 0;
}

