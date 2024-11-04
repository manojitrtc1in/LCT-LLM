














using namespace std;










typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>id2;
ll heights[5005];
ll prevPos[5005];
ll prevHigher[5005];
ll nextHigher[5005];
ll nextBase[5005];
ll prevBase[5005];
ll segTree[30000];
ll dp[2][5002][5002];
vector<long>primes;
ll N;
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
vector< long> id1(unsigned long max){

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
ll id5(ll prev,ll sPos,ll ePos){
	if(prev==-1||dp[prev][sPos][ePos]==0){
		ll baseVal=0,basepos;
		if(prev==0){
			basepos=prevBase[sPos]-1;
			baseVal=heights[basepos];
		}
		else if(prev==1){
			basepos=nextBase[ePos]+1;
			baseVal=heights[basepos];
		}		
		if(prev<0)
			prev++;
		dp[prev][sPos][ePos]=1+ePos-sPos;
		ll id3=getMin(1,1,N,sPos,ePos);
		ll alternateValue=heights[id3]-baseVal;
		alternateValue+=(min(nextHigher[sPos],ePos)-sPos);
		alternateValue+=(ePos-max(sPos,prevHigher[ePos]));
		if(alternateValue<dp[prev][sPos][ePos]){
			if(prevPos[ePos]<=sPos)
				dp[prev][sPos][ePos]=alternateValue;
			else{
				if(id3>sPos)
					alternateValue+=id5(1,min(nextHigher[sPos],ePos),id3-1);
				if(id3<ePos)
					alternateValue+=id5(0,id3+1,max(sPos,prevHigher[ePos]));
				if(alternateValue<dp[prev][sPos][ePos])
					dp[prev][sPos][ePos]=alternateValue;
			}
		}
		
	}
	return dp[prev][sPos][ePos];
}
int main(void){
 

 

    ll test_cases=1,l,r,seed=1,ans,maxVal;
	memset(dp,0,sizeof(dp));
   for(long T=0;T<test_cases;T++){
	   cin>>N>>heights[1];
	   prevPos[1]=1;
	   prevBase[1]=1;
	   prevHigher[1]=1;

	   for(long i=2;i<=N;i++){
		   cin>>heights[i];
		   if(heights[i]==heights[i-1])
			   prevPos[i]=prevPos[i-1];
		   else
			   prevPos[i]=i;
		   if(heights[i]>heights[i-1])
			   prevHigher[i]=prevHigher[i-1];
		   else
			   prevHigher[i]=i;
		   if(heights[i]<heights[i-1])
			   prevBase[i]=prevBase[i-1];
		   else
			   prevBase[i]=i;
	   }
	   nextBase[N]=N;
	   nextHigher[N]=N;
	   for(long i=N-1;i>0;i--){
		   if(heights[i]>heights[i+1])
			   nextHigher[i]=nextHigher[i+1];
		   else
			   nextHigher[i]=i;
		   if(heights[i]<heights[i+1])
			   nextBase[i]=nextBase[i+1];
		   else
			   nextBase[i]=i;
	   }
	   heights[N+1]=(1<<30);
	   id0(1,1,N);
	   cout<<id5(-1,1,N)<<endl;
   }
    return 0;
}
