














using namespace std;










typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>id1;
typedef pair<ll,ll>skill;
typedef pair<ll,ll>depth;
typedef vector<long>adj;
vector<long>primes;
set<long>candidates;
ll nums[200020];
ll cumSum[200020];
ll n;
set<string>dictionary;
set<string>::iterator it;
pair<set<string>::iterator,bool> ret;

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

double getAvg(ll pos,ll halfLen){
    return (double)(cumSum[pos+1]+cumSum[n]-(cumSum[pos-halfLen]+cumSum[n-halfLen]))/(double)((2*halfLen)+1);
}
vector< long> id0(unsigned long max){

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
ll id4(ll pos){
	ll limit=min(pos,n-(pos+1)),len=0;
	double avg=nums[pos],curAvg;
	for(ll i=1;i<=limit;i++){
		curAvg=getAvg(pos,i);
		if(curAvg>avg)
		{
			avg=curAvg;
			len=i;
		}
		else
			return len;
	}
	return len;
}
ll getLen(ll pos){
    if(pos==0||nums[pos-1]+nums[n-1]<=2*nums[pos])
        return 0;
	ll low=1,high=min(pos,n-pos-1),mid,len=0,curSum=nums[pos];
	double avg=nums[pos],curAvg;
	while(low+1<high){
		mid=(low+high)/2;
		curAvg=getAvg(pos,mid);
		if(curAvg>avg){
            avg=curAvg;
			len=(mid*2)+1;
			curSum=cumSum[pos+1]+cumSum[n]-(cumSum[pos-mid]+cumSum[n-mid]);
		}
		if((cumSum[pos+1]+cumSum[n]-(cumSum[pos-mid]+cumSum[n-mid]))*((2*mid)-1)<(cumSum[pos+1]+cumSum[n]-(cumSum[pos+1-mid]+cumSum[n+1-mid]))*((2*mid)+1))
			high=mid-1;
		else
			low=mid;
	}
	mid=low;
	if(pos*2>130062){
		mid=low;
	}
	while(mid<=high){
		ll id3=cumSum[pos+1]+cumSum[n]-(cumSum[pos-mid]+cumSum[n-mid]);
	

		if(id3*len>((2*mid)+1)*curSum){
            avg=curAvg;
            low=mid;
        }
		mid++;
	}
	return low;
}
int main(void){
 

  

    ll test_cases=1;

   

    cout << setprecision(15) << fixed;


	
	cin>>n;
	for(ll i=0;i<n;i++){
		scanf("%lld",&nums[i]);
	}
	sort(nums,nums+n);
	cumSum[0]=0;
	for(ll i=0;i<n;i++)
		cumSum[i+1]=cumSum[i]+nums[i];
	ll skew=0;
	ll sPos=1,sLen=0,sSum=0;
	if(n<3){
		cout<<n<<endl;
		for(long i=0;i<n;i++)
			cout<<nums[i]<<" ";
		return 0;
	}
	for(long i=1;i+1<n;i++){
        ll curLen=getLen(i);
		if(i*2==130064){
			curLen=getLen(i);
		}
		ll id5=cumSum[i+1]+cumSum[n]-(cumSum[i-curLen]+cumSum[n-curLen]+((2*curLen)+1)*nums[i]);
		if(id5*((2*sLen)+1)>skew*((2*curLen)+1)){
			sPos=i;
			sLen=curLen;
			skew=id5;
		}
	}
	if(skew<1)
        cout<<"1\n"<<nums[0];
    else{
        cout<<2*sLen+1<<endl<<nums[sPos]<<" ";
        for(long i=1;i<=sLen;i++)
            cout<<nums[sPos-i]<<" "<<nums[n-i]<<" ";

    }

    return 0;
}
