














using namespace std;










typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>id3;
ll nums[100005];
ll minSegTree[600004];
ll maxSegTree[600004];
ll id5[100005];
ll nextEndingPoint[100005];
ll dp[100005];


vector<long>primes;
ll N,S;
set<string>dictionary;
set<string>::iterator it;
pair<set<string>::iterator,bool> ret;

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
vector< long> id2(unsigned long max){

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
    if(b==e){
        minSegTree[node]=nums[b];
		maxSegTree[node]=nums[b];
	}
    else{
        long mid=(b+e)/2;
        id0(node*2,b,mid);
        id0(1+node*2,mid+1,e);
		minSegTree[node]=min(minSegTree[node*2],minSegTree[1+(2*node)]);
		maxSegTree[node]=max(maxSegTree[node*2],maxSegTree[1+(2*node)]);
    }
}
long long getMin(long node,long segBeg,long segEnd,long qBeg,long qEnd){
    if(segEnd<qBeg||segBeg>qEnd)
        return 10000000000;
    if(segBeg>=qBeg&&segEnd<=qEnd)
        return minSegTree[node];
    long mid=(segBeg+segEnd)/2;
    long fh=getMin(node*2,segBeg,mid,qBeg,qEnd);
    long sh=getMin(1+node*2,mid+1,segEnd,qBeg,qEnd);
    if(sh<fh)
        return sh;
    return fh;
}

long long getMax(long node,long segBeg,long segEnd,long qBeg,long qEnd){
    if(segEnd<qBeg||segBeg>qEnd)
        return -10000000000;
    if(segBeg>=qBeg&&segEnd<=qEnd)
        return maxSegTree[node];
    long mid=(segBeg+segEnd)/2;
    long fh=getMax(node*2,segBeg,mid,qBeg,qEnd);
    long sh=getMax(1+node*2,mid+1,segEnd,qBeg,qEnd);
    if(sh>fh)
        return sh;
    return fh;
}
ll id6(ll startPoint, ll endPoint){
	ll maxVal=getMax(1,1,N,startPoint,endPoint);
	ll minVal=getMin(1,1,N,startPoint,endPoint);
	return (maxVal-minVal);
}
ll id1(ll startingPoint){
	ll low=startingPoint,high=N,mid;
	while(low<high){
		mid=(low+high+1)/2;
		if(id6(startingPoint,mid)>S)
			high=mid-1;
		else
			low=mid;
	}
	while(low+1<=N&&id6(startingPoint,low+1)<=S)
		low++;
	return low;
}
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,ans,maxVal,L;
	

	vector<string>originalStrings;
	ll curNum;
	long b[400];
   for(long T=0;T<test_cases;T++){
	   cin>>N>>S>>L;
	   for(long i=1;i<=N;i++)
		   cin>>nums[i];
	   id0(1,1,N);
	   long limit=N+2-L;
	   for(long i=1;i<limit;i++)
		   nextEndingPoint[i]=id1(i);
	   if(N<L||nextEndingPoint[limit-1]<N){
		   cout<<-1<<endl;
		   return 0;
	   }
	   memset(id5,0,sizeof(id5));
	   id5[limit-1]=limit-1;
	   memset(dp,-1,sizeof(dp));
	   dp[limit-1]=1;
	   for(long i=limit-2;i>0;i--){
		   if(nextEndingPoint[i]==N){
			   dp[i]=1;
			   id5[i]=i;
		   }
		   else{
			   ll nextPoint=id5[nextEndingPoint[i]+1];
			   if(nextPoint>=i+L){
				   for(long j=i;id5[j]==0;j++)
					   id5[j]=i;
				   dp[i]=1+dp[nextPoint];
			   }
		   }
	   }
	   cout<<dp[1]<<endl;
	   
   }
    return 0;
}
