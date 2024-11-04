














using namespace std;










typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>id3;
ll heights[5];
ll segTree[3];
long nums[5005];
long g[5005];


vector<long>primes;
vector<long>id6;
long funcVal[1000006];
ll N;
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
long long id4(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=id4(mdlo%n);
    mInv[n]=(m%mdlo);
    return mInv[n];
}
vector< long> id2(unsigned long maxN){

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
void id1(long node,long b,long e){
    if(b==e)
        segTree[node]=b;
    else{
        long mid=(b+e)/2;
        id1(node*2,b,mid);
        id1(1+node*2,mid+1,e);
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
string id0(ll val){
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
typedef vector<long>bigInteger;
long maxBuild;
bigInteger mult(bigInteger A,bigInteger B){
    long len1=A.size(),len2=B.size();
    bigInteger C;
    for(long i=0;i<len1;i++){
        long carry=0;
        for(long j=0;j<len2;j++){
            long pos=i+j;
            long val=carry+(A[i]*B[j]);
            carry=val/10;
            val=val%10;
            if(pos>=C.size()){
                C.push_back(val);
            }
            else{
                C[pos]+=val;
                carry=C[pos]/10;
                C[pos]=C[pos]%10;
            }
        }
        if(carry>0)
            C.push_back(carry);
    }
    return C;
}
bigInteger getVal(long power){
    bigInteger C;
    C.push_back(5);
    if(power==1)
        return C;
    bigInteger B=getVal(power/2);
    B=mult(B,B);
    if(power%2==1)
        B=mult(B,C);
    return B;
}

long id5(long num,long startPos,bool bp){
    if(num<=maxBuild||(num<1000000&&funcVal[num]!=0))
        return funcVal[num];
	if(bp){
		for(long i=startPos;i<id6.size()&&id6[i]<=num;i++)
			if(num%id6[i]==0)
				return id5(num/id6[i],i,true)-1;
		startPos=0;
	}
    long limit=1+sqrt((double)(num+1));
    for(long i=startPos;i<primes.size()&&primes[i]<limit;i++)
        if(num%primes[i]==0)
            return 1+id5(num/primes[i],i,false);
    return 1;
}
void id7(){
    maxBuild=1;
	memset(funcVal,0,sizeof(funcVal));
    for(long i=2;i<33000;i++){
        funcVal[i]=id5(i,0,true);
        maxBuild=i;
    }
}
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,maxVal;
	

	vector<string>originalStrings;
	ll curNum;
	ll m,n;
	long nums[5006];
	ll ans=0;
	id2(32000);
  for(long T=0;T<test_cases;T++){
	   cin>>n>>m>>nums[0];
	   g[0]=nums[0];
	   for(long i=1;i<n;i++){
		scanf("%ld",&nums[i]);
        g[i]=gcd(nums[i],g[i-1]);
	   }
	   for(long i=0;i<m;i++){
        scanf("%lld",&curNum);
        id6.push_back(curNum);
	
	   }
	id7();

	   ll divv=1;
	   for(long i=n-1;i>-1;i--){
            long divVal=g[i]/divv;
            long fVal=id5(divVal,0,true);
            if(fVal<0){
                divv*=divVal;
                ans+=id5(nums[i]/divv,0,true);
            }
            else{
                ans+=(id5(nums[i]/g[i],0,true)+id5(g[i]/divv,0,true));
            }
	   }
	   cout<<ans<<endl;
   }
    return 0;
}

  
