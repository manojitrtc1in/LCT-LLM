#include<bits/stdc++.h>
#define int long long
#define double long double
#define space " "
#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define pss pair<string,string>
#define pivi pair<int,vector<int>>
#define pipii pair<int, pii>
#define ptt pair<T,T>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vt vector<T>
#define vpii vector<pii>
#define vpss vector<pss>
#define vptt vector<ptt>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
#define vvs vector<vs>
#define vvt vector<vt>
#define vvpii vector<vpii>
#define MOD1 1000000007
#define F(a,b,c) for(int (a)=(b);(a)<(c);++(a))
#define FN(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define FD(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define FND(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define FSQ(a,b,c) for(int (a)=(b);(a)*(a)<(c);++(a))
#define FNSQ(a,b,c) for(int (a)=(b);(a)*(a)<=(c);++(a))
#define SQR(x) ((int)((x)*(x)))
#define RESET(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define MAXN2 (1e5+10)
#define MAXN1 (1e6+10)
#define INF1 (1e10+10)
#define INF2 (1e12+10)
#define INF3 (1e15+10)
#define INF4 (1e18+10)
#define PI 3.1415926535897932
#define FEACH(a,b) for(auto &(a):(b))
#define TONUM(c) (c-'0')
#define TOCHAR(c) (c+'0')
#define GCD(a,b) (__gcd((a),(b)))
#define LCM(a,b) ((a)*((b)/GCD((a),(b))))
#define ADDM(a,b,mod) (((a)%(mod) + (b)%(mod))%mod)
#define SUBM(a,b,mod) ((((a)%(mod) - (b)%(mod))%mod + mod)%mod)
#define MULM(a,b,mod) (((a)*(b))%mod)
#define YESNO1(b) ((b)?(println("YES")):(println("NO")))
#define YESNO2(b) ((b)?(println("Yes")):(println("No")))
#define YESNO3(b)  ((b)?(println("yes")):(println("no")))
#define MID(a,b) (((a)+(b))/2)
#define LSHIFT(a,b) (((int)(a))<<(b))
#define RSHIFT(a,b) (((int)(a))>>(b))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define BOOLALPHA cout<<boolalpha;
using namespace std;

template<typename T>void read(T &a){cin>>a;}
template<typename T>void read(T &a,T &b){cin>>a>>b;}
template<typename T>void read(T &a,T &b,T &c){cin>>a>>b>>c;}
template<typename T>void read(T a[],int n){F(i,0,n) cin>>a[i];}
template<typename T>void read(ptt & pr){read(pr.first,pr.second);}
template<typename T>void readv(vt & v){FEACH(a,v) read(a);}
template<typename T>void readm(vvt & v){FEACH(a,v) readv(a);}

void print(){cout<<" "<<endl;}
template<typename T>void print(T &a){cout<<a<<" ";}
template<typename T>void print(T &a,T &b){cout<<a<<" "<<b<<" ";}
template<typename T>void print(T &a,T &b,T &c){cout<<a<<" "<<b<<" "<<c<<" ";}
template<typename T>void print(ptt & pr){cout<<pr.first<<" "<<pr.second<<" ";}
void println(){cout<<endl;}
template<typename T>void println(T &a){cout<<a<<endl;}
template<typename T>void println(T &a,T &b){cout<<a<<" "<<b<<endl;}
template<typename T>void println(T &a,T &b,T &c){cout<<a<<" "<<b<<" "<<c<<endl;}
template<typename T>void println(ptt & pr){cout<<pr.first<<" "<<pr.second<<endl;}
template<typename T>void println(T a[],int n){F(i,0,n) cout<<a[i]<<" ";cout<<endl;}
string tostr(int a){ostringstream ostr;ostr<<a;return ostr.str();}
int tonum(string &s){stringstream str(s);int num;str>>num;return num;}

template<typename T> void printv(vt & v){ FEACH(a,v) print(a); println();}
template<typename T> void printm(vvt & v){ FEACH(a,v) printv(a);}
void printb(bool b){cout<<b<<" ";}
void printb(bool b1,bool b2){printb(b1);printb(b2);}
void printlnb(bool b){printb(b);println();}
void printlnb(bool b1,bool b2){printb(b1);printb(b2);println();}
using namespace std;


int stringToInt(const string &s){
	stringstream om(s);
	int num=-1;
	om>>num;
	return num;
}


void checkTimeout(){
	double tm=(float)clock()/CLOCKS_PER_SEC;
	if(tm>=2){
		cerr<<"Time limit exeeded"<<endl;
		exit(0);
	}
}


void findAllFactors(int n,std::vector<int>& factors){

	double sqroot=sqrt(n);
	factors.push_back(1);
	if(n==1){
		return;		
	}
	for(int i=2;i<=sqroot;i++){
		if(n%i == 0){
			factors.push_back(i);
			if(n/i != i){
				factors.push_back(n/i);
			}
		}
	}
	factors.push_back(n);
	sort(factors.begin(),factors.end());
}


pair<int,int> extended_gcd(int a,int b){
	if(b==0) return{1,1};
	pair<int,int> pr=extended_gcd(b,a%b);
	return {pr.second,pr.first-(a/b)*pr.second};
}
int hcf(int a,int b){
	if(a==0 || b==0) return max(a,b);
	pair<int,int> pr=extended_gcd(a,b);
	return (a*pr.first + b*pr.second);
}
int lcm(int a,int b){
	return (a*b)/(__gcd(a,b));
}
int gcd(int a,int b){
	return __gcd(a,b);
}








void print(int *arr,int start,int end){
	for(int i=start;i<=end;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
void print(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
void print(vector<pair<int,int>>& v){
	for(auto &pr:v){
		cout<<"{"<<pr.first<<","<<pr.second<<"}"<<endl;
	}
	cout<<endl;
}
void print(std::vector<int>& v){
	for(auto &num:v) cout<<num<<" ";cout<<endl;
}
void print(std::vector<string>& v){
	for(auto &num:v) cout<<num<<" ";cout<<endl;
}
void print(std::vector<std::vector<int>>& v,int n){
	for(int i=n-1;i>=0;i--){
		print(v[i]);
	}
}
void print(bool b){
	if(b) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}
void print(pair<int,int>& pr){
	cout<<"{"<<pr.first<<","<<pr.second<<"} ";
}



int power(long long x, unsigned int y, int p) 
{ 
    int res = 1; 
    x = x % p; 

    if (x == 0) return 0; 

    while (y > 0) { 
        if (y & 1) res = (res*x) % p; 
        y = y>>1; 

        x = (x*x) % p; 
    } 
    return res; 
} 

int modSub(int a,int b,int mod){
	return ((a%mod - b%mod + mod)%mod);
}
int modMul(int a,int b,int mod){
	return ((a%mod)*(b%mod))%mod;
}
int modAdd(int a,int b,int mod){
	return ((a%mod)+(b%mod))%mod;
}
int modInv(int a,int mod){
	int x,y;
	pair<int,int> pr=extended_gcd(a,mod);
	x=pr.first;
	y=pr.second;
	int g=(a*x + mod*y);
	if(g!=1){
		cerr<<"modular inverse does not exist , gcd != 1"<<endl;
		exit(0);
	}
	

	int res=(x%mod + mod)%mod;
	return res;
}
int modDiv(int a,int b,int mod){
	
	a=a%mod;
	int inv=modInv(b,mod);
	int res=(inv*a)%mod;
	return res;
}
int chineseRem(int arr[],int rem[],int n){
	int prod=1,res=0;
	for(int i=0;i<n;i++) prod*=arr[i];
	for(int i=0;i<n;i++){
		int restProd=prod/arr[i];
		res+=(rem[i]*modInv(restProd,arr[i])*(restProd));
	}
	return (res%prod);
}


class fenwickTree{
	vector<int> BIT;
	int n;
	public : 
	fenwickTree(int n){
		this->n=n;
		BIT=*new vector<int>(n,0);
	}
	fenwickTree(int *arr,int n){
		
		this->n=n;
		BIT=*new vector<int>(n,0);
		BIT[0]=arr[0];
		for(int i=1;i<n;i++){
			this->update(i,arr[i]);
		}
	}
	fenwickTree(vector<int>&v){
		this->n=v.size();
		BIT=*new vector<int>(n,0);
		BIT[0]=v[0];
		for(int i=1;i<n;i++){
			this->update(i,v[i]);
		}
	}
	void update(int index, int delta)
	{
		  if(index==0) {BIT[index]+=delta;return;}
	      for(; index < n; index += index&-index)

	        BIT[index] += delta;
	}
	int get(int index)
	{
	     int sum = BIT[0];
	     for(; index > 0; index -= index&-index)
	        sum += BIT[index];
	     return sum;
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<BIT[i]<<" ";
		}
		cout<<endl;
	}
};
	


class segmentTree{
	vector<int> segTree;
	int *arr;int n;
	bool isVectorContainer=false;
	public: 
	segmentTree(int *arr,int n){
		this->arr=arr;
		this->n=n;
		int size=pow(2,ceil(log2(2*n-1)));
		segTree.resize(size);
		createSegTree(0,0,n-1);
	}
	segmentTree(vector<int> &v){
		isVectorContainer=true;
		n=v.size();
		this->arr=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++){
			arr[i]=v[i];
		}
		int size=pow(2,ceil(log2(2*n-1)));
		segTree.resize(size);
		createSegTree(0,0,n-1);
	}
	int createSegTree(int si,int l,int r){
		if(l==r){	
			segTree[si]=arr[l];
			return arr[l];
		}
		int mid=(l+r)/2;
		segTree[si]=createSegTree(2*si + 1,l,mid)+createSegTree(2*si + 2,mid+1,r);
		return segTree[si];
	}
	int getRangeSum(int sl,int sr,int l,int r,int si){
		

		if(sl>=l && sr<=r){
			return segTree[si];
		}
		if(sl>r || sr<l){
			return 0;
		}
		int mid=(sl+sr)/2;
		return getRangeSum(sl,mid,l,r,2*si+1)+getRangeSum(mid+1,sr,l,r,2*si+2);
	}
	int getRangeSum(int l,int r){
		return this->getRangeSum(0,n-1,l,r,0);
	}

	void updateSegTree(int si,int sl,int sr,int pos,int diff){
		if(sl>pos || sr<pos) return;
		segTree[si]+=diff;
		if(sl != sr){
			int mid((sl+sr)/2);
			updateSegTree(2*si+1,sl,mid,pos,diff);
			updateSegTree(2*si+2,mid+1,sr,pos,diff);
		}
	}
	void update(int pos,int delta){
		return updateSegTree(0,0,n-1,pos,delta);
	}
	~segmentTree(){
		if(isVectorContainer){
			free(arr);
		}
	}
	void print(){
		for(int i=0;i<segTree.size();i++){
			cout<<segTree[i]<<" ";
		}
		cout<<endl;
	}
};

vi tree,lazy;
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
  
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
  
void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}



class sqrtDecomp{
	int *arr;
	int n;
	int len;
	vector<int> decomp;
	public :
	sqrtDecomp(int *arr,int n){
		this->n=n;
		this->arr=arr;
		len=sqrt(n)+1;
		decomp=*new vector<int>(len,0);
		for(int i=0;i<n;i++){
			decomp[i/len]+=arr[i];
		}
	}
	sqrtDecomp(vector<int>& v){
		this->n=n;
		arr=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++) arr[i]=v[i];
		len=sqrt(n)+1;
		decomp=*new vector<int>(len,0);
		for(int i=0;i<n;i++){
			decomp[i/len]+=arr[i];
		}
	}
	int getRangeSum(int l,int r){
		int sum=0;
		for(int i=l;i<=r;){
			if(i%len==0 && i+len-1<=r){
				sum+=decomp[i/len];
				i+=len;
			}else{ 
				sum+=arr[i];
				i++;
			}
		}
		return sum;
	}
};


class disjointSet{
    vector<int> ump;
    public:
    vector<int>& getUmp(){
    	return ump;
    }
    disjointSet(int n){
        ump.assign(n+1,-1);
    }
    int findSet(int u){
        

        int r=u;
        while(ump[r]>=0){
            r=ump[r];
        }
        while(u!=r){
            int par=ump[u];
            ump[u]=r;
            u=par;
        }
        return r;
    }
    bool setUnion(int u,int v){
        

        int uroot=findSet(u);
        int vroot=findSet(v);
        

        if(uroot == vroot) return false;
        int uchild=ump[uroot];
        int vchild=ump[vroot];
        int totalChild=uchild+vchild;
        
        if(uchild>vchild){
	        ump[uroot]=vroot;
	        ump[vroot]=totalChild;
        }else{
	        ump[vroot]=uroot;
	        ump[uroot]=totalChild;
        }
        return true;
    }
    bool prefered_union(int u,int v){
    	int uroot=findSet(u);
    	int vroot=findSet(v);
    	if(uroot==vroot) return false;
    	int uchild=ump[uroot];
        int vchild=ump[vroot];
        int totalChild=uchild+vchild;
        ump[uroot]=vroot;
        ump[vroot]=totalChild;
        return true;
    }
    bool checkOdd(int l,int r){
    	for(int i=l;i<=r;i++){
    		

    		if(ump[i]<0){
    			if(abs(ump[i])%2) return false;
    		}
    	}
    	

    	return true;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

};


int lis(int *v,int n){
	vector<int> seq;
	for(int i=0;i<n;i++){
		int num=v[i];
		auto found=upper_bound(seq.begin(), seq.end(),num);
		if(found==seq.end()) seq.push_back(num);
		else *found=num;
	}
	return seq.size();
}
int lis(vector<int>&v){
	int n=v.size();
	vector<int> seq;
	for(auto num:v){
		auto found=upper_bound(seq.begin(), seq.end(),num);
		if(found==seq.end()) seq.push_back(num);
		else *found=num;
	}
	return seq.size();
}


void lis(int *v,int n,vector<int>&seq){
	for(int i=0;i<n;i++){
		int num=v[i];
		auto found=upper_bound(seq.begin(), seq.end(),num);
		if(found==seq.end()) seq.push_back(num);
		else *found=num;
	}
	return ;
}
void lis(vector<int>&v,vector<int>& seq){
	int n=v.size();
	for(auto num:v){
		auto found=upper_bound(seq.begin(), seq.end(),num);
		if(found==seq.end()) seq.push_back(num);
		else *found=num;
	}
	return;
}



void scan(int *arr,int n){
	for(int i=0;i<n;i++) cin>>arr[i];
}
void scan(vector<int>& v,int n){
	for(int i=0;i<n;i++) cin>>v[i];
}
void scan(int *arr,int n,vector<int>& hash){
	for(int i=0;i<n;i++) {cin>>arr[i];hash[arr[i]]=i;}
}
void scan(vector<int>& v,int n,vector<int>& hash){
	for(int i=0;i<n;i++) {cin>>v[i];hash[v[i]]=i;}
}
void scan(int *arr,int n,unordered_map<int,int>& hash){
	for(int i=0;i<n;i++) {cin>>arr[i];hash[arr[i]]=i;}
}
void scan(vector<int>& v,int n,unordered_map<int,int>& hash){
	for(int i=0;i<n;i++) {cin>>v[i];hash[v[i]]=i;}
}


int primeFactorsBig(int n){
	unordered_set<int> uns;
	int p=2;
	while(true){
		if(n>=p*p){
			if(n%p==0){
				uns.insert(p);
				n/=p;
			}else p++;
		}else{
			uns.insert(n);
			break;
		}
	}
	return uns.size();
}



void primeFactorsBig(int n,map<int,int>& mp){
	int p=2;
	while(true){
		if(n>=p*p){
			if(n%p==0){
				mp[p]++;
				n/=p;
			}else p++;
		}else{
			mp[n]++;
			break;
		}
	}
	return;
}
void primeFactorsBig(int n,vector<int>& v){
	unordered_set<int> uns;
	int p=2;
	while(true){
		if(n>=p*p){
			if(n%p==0){
				uns.insert(p);
				n/=p;
			}else p++;
		}else{
			uns.insert(n);
			break;
		}
	}
	v.resize(uns.size());
	int len=0;
	for(auto num:uns) v[len++]=num;
	sort(v.begin(), v.end());
	return;
}


bool isPrimeBig(int n){
	if(n==1) return false;
	int p=2;
	while(true){
		if(n>=p*p){
			if(n%p==0){
				return false;
				n/=p;
			}else p++;
		}else{
			return true;
			break;
		}
	}
	return false;
}


const int N=1e6+10;




vector<int> primes;


bitset <N> nonPrimeSet;






	














	


void seiveWithAllPrimes(){
	nonPrimeSet[0]=nonPrimeSet[1]=1;
	for(int num=2;num*num<=N;num++){
		if(0==nonPrimeSet[num]){
			for(int j=num*num;j<=N;j+=num){
				nonPrimeSet[j]=1;
			}
		}
	}
	for(int num=2;num<=N;num++){
		if(0==nonPrimeSet[num]){
			primes.pb(num);
		}
	}
}

vector<int> cprimes;
void consecutivePrimes(){
	cprimes.resize(2e5+10);
	cprimes[0]=2;
	int index=0;
	int n=primes.size();
	F(i,1,n){
		if(primes[i]+2<N && 0==nonPrimeSet[primes[i]+2]){
			index++;
			cprimes[index]=primes[i];
		}
	}

	

}
























	
























		









































































































			











int roundOf(int n){
	return (int)pow(2,floor(log2(n)));
}




void createZ(string s,int z[]){
	int n=s.size();
	int l,r,k;
	l=r=0;
	z[0]=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n && s[r]==s[r-l]){
				r++;
			}
			z[i]=r-l;
			r--;
		}else{
			k=i-l;
			if(z[k]<r-i+1){
				z[i]=z[k];
			}else{
				l=i;
				while(r<n && s[r-l]==s[r]){
					r++;
				}
				z[i]=r-l;
				r--;
			}
		}
	}
}
void zSearch(string text,string pattern,vector<int>& match){
	string concat=pattern+"$"+text;
	int sz=concat.length();
	int psize=pattern.size();
	int z[sz];
	createZ(concat,z);
	for(int i=0;i<sz;i++){
		if(z[i]==psize){
			match.push_back(i-psize-1);
		}
	}
	return;
}

bool stringCompare(string &s,int ss,string &r,int rs,int len){
	if(ss+len>s.size() || rs+len>r.size()) return false;
	for(int i=0;i<len;i++,ss++,rs++){
		if(s[ss]!=r[rs]) return false;
	}
	return true;
}
void rabin(string s,string pattern,vector<int>&match){
	int sz=s.size();
	int pz=pattern.size();
	if(pz>sz) return;
	int primeNum=3;
	int hashVal=0;
	int patternHash=0;
	for(int i=0;i<pz;i++){
		patternHash+=((int)(pattern[i]-97 + 1))*pow(primeNum,i);
	}
	
	

	for(int i=0;i<pz;i++){
		hashVal+=((int)(s[i]-97 + 1))*pow(primeNum,i);
	}
	if(hashVal==patternHash) match.push_back(0);
	for(int i=pz;i<sz;i++){
		
		int k=i-pz;
		hashVal-=(int)(s[k]-97+1);
		hashVal/=3;
		hashVal+=((int)(s[i]-97+1))*pow(primeNum,pz-1);
		if(hashVal==patternHash && (stringCompare(s,k+1,pattern,0,pz))) match.push_back(k+1);
	}
}
void prefix_function(string s,vector<int>& pf){
	int n=s.size();
	pf.resize(n);
	pf[0]=0;
	for(int i=1;i<n;i++){
		int j=pf[i-1];
		while(j>0 && s[i]!=s[j]){
			j=pf[j-1];
		}
		if(s[i]==s[j]){
			j++;
		}
		pf[i]=j;
	}
	

}
void kmp(string s,string pattern,vector<int>&match){
	int pz=pattern.size();
	int pos(-1),i(0),j(0);
	vector<int> pf;
	prefix_function(pattern,pf);
	for(auto num:pf) cout<<num<<" ";cout<<endl;
	while(i<s.size()){
		if(s[i]==pattern[j]){
			j++;
			i++;
		}else{
			if(j!=0){
				j=pf[j-1];
			}else i++;
		}
		if(j==pattern.size()){
			match.push_back(i-pz);
		}
	}
}
void reject(){
	cout<<-1<<endl;
	return;
}
void freqscan(int b[],int n,unordered_map<int,int>& hash){
	for(int i=0;i<n;i++){
		cin>>b[i];
		hash[b[i]]++;
	}
}
class sparseTable{
	int *arr;
	int n;
	vector<vector<int>> table;
	int col=0;
	public: 
	void buildTable(){
		for(int i=0;i<n;i++) table[i][0]=arr[i];
		for(int j=1;j<col;j++){
			for(int i=0;i+(1<<j)-1<n;i++){
				table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
			}
		}
	}
	sparseTable(int *arr,int n){
		this->arr=arr;
		this->n=n;
		col=1+log2(n);
		table=*new vector<vector<int>>(n,*new vector<int>(col));
		this->buildTable();
	}
	int getRangeMin(int l,int r){
		int diff=r-l+1;
		int j=log2(diff);
		return min(table[l][j],table[r-(1<<j)+1][j]);
	}
	void print(){
		for(int i=0;i<n;i++){
			for(int j=0;j<col;j++){
				cout<<table[i][j]<<" ";
			}cout<<endl;
		}
	}
};
class Query{
public: 
	int index,l,r,sum;
};
class mosAlgo{
public: 
	
	int *arr;
	int n;
	int len;
	

	mosAlgo(int *arr,int n){
		this->arr=arr;
		this->n=n;
		this->len=sqrt(n);
	}
	void process(vector<Query>& que,vector<int>& v){
		int q=que.size();
		sort(que.begin(), que.end(),[&](Query&a,Query&b){
			if((a.l)/len == (b.l)/len){
				return a.r>b.r;
			}
			return a.l/len<b.l/len;
		});
		int currL=0,currR=-1,currSum=0;
		for(int i=0;i<q;i++){
			Query &query=que[i];
			while(currL<query.l){
				currSum-=arr[currL];
				currL++;
			}
			while(currL>query.l){
				currL--;
				currSum+=arr[currL];
			}
			while(currR<query.r){
				currR++;
				currSum+=arr[currR];
			}
			while(currR>query.r){
				currSum-=arr[currR];
				currR--;
			}
			query.sum=currSum;
			v[query.index]=currSum;
		}
	}
};


class Manacher{
	string s;
	int n;
	vector<int> palCount;
	int mxIndex=-1,mx=0;
	string longestPalindrome;
public: 
	void buildString(string str){
		for(auto c:str){
			s+="$";
			s+=c;
		}
		s+="$";
	}
	Manacher(string s){
		this->n=s.size();
		this->n=2*n+1;
		this->buildString(s);
		palCount=*new vector<int>(n,0);
		this->process();
	}
	void process(){
		int iter=0;
		int start(0),end(0);
		for(int i=0;i<n;){
			while(start>0 && end<n-1 && s[start-1]==s[end+1]){
				start--;
				end++;
			}
			palCount[i]=end-start+1;
			if(end==n-1) break;
			int newCenter=end + ((i%2 == 0)?(1):(0));
			for(int j=i+1;j<=end;j++){
				if(s[i]=='$') continue;
				palCount[j]=min(palCount[i-(j-i)],2*(end-j)+1);
				if(j+palCount[i-(j-i)]/2 == end){
					newCenter=j;
					break;
				}
			}
			i=newCenter;
			end=i+palCount[i]/2;
			start=i-palCount[i]/2;
		}
		for(int i=0;i<n;i++){
			if(palCount[i] >mx){
				mx=palCount[i];
				mxIndex=i;
			}
		}
		longestPalindrome=s.substr(mxIndex-mx/2,mx);
		string dummy=longestPalindrome;
		longestPalindrome="";
		for(auto c:dummy){
			if(c!='$') longestPalindrome+=c;
		}
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<i<<" : "<<palCount[i]<<endl;
		}
	}
	int getLen(){
		return mx/2;
	}
	string getPal(){
		return longestPalindrome;
	}

};
bool isPalindrome(string s){
	string rev=s;
	reverse(s.begin(), s.end());
	return s==rev;
}

class EulerTotient{
	public : 
	int n;
	vector<int> totient;
	EulerTotient(int N){
		this->n=N+1;
		totient.resize(n);
		for(int i=0;i<n;i++){
			totient[i]=i;
		}
		for(int i=2;i<n;i++){
			if(totient[i]==i){
				for(int j=2*i;j<n;j+=i){
					totient[j]*=(i-1);
					totient[j]/=i;
				}
				totient[i]=i-1;
			}
		}
	}
	void print(){
		for(auto num:totient) cout<<num<<" ";cout<<endl;
	}
	inline int get(int index){
		return totient.at(index);
	}
};
class MatrixExp{
	public : 
	int n,row,col;
	vector<vector<int>>& mat;
	vector<vector<int>> resultMat;
	

	vector<vector<int>> matrixMultiply(vector<vector<int>>& mat1,vector<vector<int>>& mat2){
		if(mat1[0].size() != mat2.size()){
			cout<<"invalid matrix matrixMultiply"<<endl;
			exit(0);
		}
		int myrow=(int)mat1.size(),mycol=(int)mat2[0].size(),comm=(int)mat1[0].size();
		vector<vector<int>> mulMat((int)mat1.size(),vector<int>((int)mat2[0].size()));
		for(int i=0;i<myrow;i++){
			for(int j=0;j<mycol;j++){
				mulMat[i][j]=0;
				for(int k=0;k<comm;k++){
					mulMat[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}
		

		

		

		return mulMat;
	}
	

	void makeIdentityMatrix(vector<vector<int>> &identityMat){
		identityMat.resize(row);
		for(int i=0;i<row;i++){
			identityMat[i]=*new vector<int>(row,0);
			identityMat[i][i]=1;
		}
		return;
	}
	

	vector<vector<int>> exponentiate(int power){
		if(power==1){
			return mat;
		}
		vector<vector<int>> mymat;
		if(power==0){
			this->makeIdentityMatrix(mymat);

			return mymat;
		}
		mymat=this->exponentiate(power/2);
		vector<vector<int>> ansmat=matrixMultiply(mymat,mymat);
		if(power & 1){
			ansmat=matrixMultiply(ansmat,mat);
		}
		

		

		return ansmat;
	}
	

	MatrixExp(int N,vector<vector<int>> &vmat):n(N),mat(vmat){
		row=mat.size();
		col=mat[0].size();
		resultMat=this->exponentiate(n);
	}
	

	MatrixExp(int N):n(N),mat(*new vector<vector<int>>{{1,1},{1,0}}){
		row=mat.size();
		col=mat[0].size();
		resultMat=this->exponentiate(n);
	}
	

	vector<vector<int>>& getResultMatrix(){
		return this->resultMat;
	}
	

	void printMatrix(vector<vector<int>>& vmatrix){
		for(auto &rowv:vmatrix){
			for(auto elem:rowv) cout<<elem<<" ";cout<<endl;
		}
	}
	void print(){
		for(auto &rowv:resultMat){
			for(auto elem:rowv) cout<<elem<<" ";cout<<endl;
		}
	}
};
class Fibonacci{
	public :
	int n;
	vector<vector<int>> mymat{{1,1},{1,0}};
	MatrixExp &me;
	Fibonacci(int n):n(n),me(*new MatrixExp(n,mymat)){}
	int get(){
		if(n==0) return 0;
		vector<vector<int>>& fibMatrix=me.getResultMatrix();
		return fibMatrix[0][0];
	}
};

class NCR{
	public : 
	int mod=-1;
	int n,r,res=1;
	void computeNcr(){
		if(r>n){
			res=0;
			return;
		}
		for(int i=0;i<r;i++){
			res*=(n-i);
			res/=(i+1);
		}
	}
	void computeNcrMod(){
		if(r>n){
			res=0;
			return;
		}
		for(int i=0;i<r;i++){
			res=modMul(res,n-i,mod);
			res=modDiv(res,i+1,mod);
		}
	}
	NCR(int n,int r):n(n),r(r){
		if(r>n-r) r=n-r;
		this->computeNcr();
	}
	NCR(int n,int r,int mod):n(n),r(r),mod(mod){
		if(r>n-r) r=n-r;
		this->computeNcrMod();
	}
	int get(){
		return res;
	}
};

class NCRefficient{
	public : 
	int n,mod,r;
	vector<int> fact,invFact,invNum;
	void calculateFactorial(){
		fact[0]=fact[1]=1;
		for(int i=2;i<=n;i++){
			fact[i]=(fact[i-1]*i)%mod;
		}
		return;
	}
	void calculateInverseNum(){
		invNum[0]=invNum[1]=1;
		for(int i=2;i<=n;i++){
			invNum[i]=invNum[mod % i]*(mod - mod/i)%mod;
		}
	}
	void calculateInverseFactorial(){
		invFact[0]=invFact[1]=1;
		for(int i=2;i<=n;i++){
			invFact[i]=(invNum[i]*invFact[i-1])%mod;
		}		
	}
	NCRefficient(int n,int mod):n(n),mod(mod){
		fact.resize(n+1);
		invFact.resize(n+1);
		invNum.resize(n+1);
		this->calculateFactorial();
		this->calculateInverseNum();
		this->calculateInverseFactorial();
	}
	int get(int N,int r){
		if(N>n) return 0;
		if(r<0 || r>N) return 0;
		int ans=(fact[N]*invFact[r])%mod *(invFact[N-r])%mod;
		return ans;
	}
};
class centroidDecomp{
public:
	int no_of_vertices;
	vector<vector<int>> tree;
	vector<vector<int>> centroidTree;
	vector<int> subtreeSizeOf;
	vector<bool> visited;
	vector<bool> isCentroid;
	int stop=0;
	centroidDecomp(int N){
		this->no_of_vertices=N+1;
		tree.resize(no_of_vertices);
		subtreeSizeOf.resize(no_of_vertices);
		centroidTree.resize(no_of_vertices);
		visited.resize(no_of_vertices);
		isCentroid=*new vector<bool>(no_of_vertices,false);
	}
	
	void DFS(int src,int& N){
		

		if(++stop>=100) exit(0);
		visited[src]=true;
		N += 1;
		subtreeSizeOf[src]=1;
		for(auto childNode:tree[src]){
			if(!visited[childNode] && !isCentroid[childNode]){
				DFS(childNode,N);
				subtreeSizeOf[src]+=subtreeSizeOf[childNode];
			}
		}
	}
	int getCentroidUtil(int src,int N){
		bool is_this_node_centroid=true;
		visited[src]=true;
		int heaviest_child=0;
		for(auto childNode:tree[src]){
			if(!visited[childNode] && !isCentroid[childNode]){
				if(subtreeSizeOf[childNode]>N/2){
					is_this_node_centroid=false;
				}
				if(heaviest_child==0 || subtreeSizeOf[childNode] > subtreeSizeOf[heaviest_child]){
					heaviest_child=childNode;
				}
			}
		}
		if(is_this_node_centroid && (N-subtreeSizeOf[src] <= N/2)){
			return src;
		}
		return getCentroidUtil(heaviest_child,N);
	}
	int getCentroid(int src){
		this->clearVisitedAndSubtreeSizeOf();
		int N=0;
		DFS(src,N);
		this->clearVisited();
		int centroid=getCentroidUtil(src,N);
		isCentroid[centroid]=true;
		return centroid;
	}
	int decompose(int root){
		int currCentroidNode=getCentroid(root);
		for(auto childNodeOfCentroid:tree[currCentroidNode]){
			if(!isCentroid[childNodeOfCentroid]){
				int subCentroidNode=this->decompose(childNodeOfCentroid);
				centroidTree[currCentroidNode].push_back(subCentroidNode);
				centroidTree[subCentroidNode].push_back(currCentroidNode);
			}
		}
		return currCentroidNode;
	}
	void addEdge (int u,int v){
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	void clearVisitedAndSubtreeSizeOf(){
		for(int i=0;i<no_of_vertices;i++){
			visited[i]=false;
			subtreeSizeOf[i]=0;
		}
	}
	void clearVisited(){
		for(int i=0;i<no_of_vertices;i++){
			visited[i]=false;
		}
	}
	void print(){
		for(int i=1;i<no_of_vertices;i++){
			cout<<i<<"< : >";
			for(auto node:centroidTree[i]) cout<<node<<" ";cout<<endl;
		}
	}
};
class Trie{
public:

	class TrieNode{
	public:
		bool end=false;
		vector<TrieNode*> nextNodeOf{*new vector<TrieNode*>(26,NULL)};
	};
	TrieNode* trieRoot=NULL;
	Trie(){
		trieRoot=new TrieNode();
	}
	void insert(const string& word){
		TrieNode* currNode=trieRoot;
		for(auto ch:word){
			if(NULL == (currNode->nextNodeOf[ch-'a'])){
				currNode->nextNodeOf[ch-'a'] = new TrieNode();
			}
			currNode=currNode->nextNodeOf[ch-'a'];
		}
		currNode->end=true;
	}
	bool search(const string& key){
		TrieNode* currNode=trieRoot;
		for(auto ch:key){
			if(NULL == (currNode->nextNodeOf[ch-'a'])){
				return false;
			}
			currNode=currNode->nextNodeOf[ch-'a'];
		}
		return currNode->end;
	}
	bool searchPrefix(const string& key){
		TrieNode* currNode=trieRoot;
		for(auto ch:key){
			if(NULL == (currNode->nextNodeOf[ch-'a'])){
				return false;
			}
			currNode=currNode->nextNodeOf[ch-'a'];
		}
		return true;
	}
};

class Graph{
	public : 
	vector<vector<int>> graph;
	vector<vector<int>> solutionColorVectors;
	vector<int> colorOf;
	int n;
	int no_of_colors=0;
	Graph(int n){
		graph.resize(n+1);
		colorOf.assign(n+1,0);
		this->n=n;
	}
	void set_no_of_colors(int m){
		this->no_of_colors=m;
	}
	void addEdge(int u,int v){
		graph[u].push_back(v);
	}
	void printGraph(){
		for(int i=1;i<=n;i++){
			cout<<i<<" : ";
			for(auto neb:graph[i]){
				cout<<neb<<" ";
			}cout<<endl;
		}
	}
	void mcolor(int start){
		if(start>n){
			solutionColorVectors.push_back(colorOf);
			return;
		}
		vector<bool> isValidColor(no_of_colors+1,true);
		for(auto node:graph[start]){
			isValidColor[colorOf[node]]=false;
		}
		for(int i=1;i<=no_of_colors;i++){
			if(isValidColor[i]){
				colorOf[start]=i;
				this->mcolor(start+1);
			}
		}
		colorOf[start]=0;
		return;
	}
	void printSolutionColorVectors(){
		for(auto & colorVector:solutionColorVectors){
			for(int i=1;i<=n;i++){
				cout<<colorVector[i]<<" ";
			}
			cout<<endl;
		}
	}

};
inline int convert(int i,int j,int n){
	return (i*n + j);
}
int fact[16];
unordered_map<int,int> memo;
int setBits(int n){
	bitset<40> bs(n);
	return bs.count();
}
NCRefficient* ncr;
void init(){
	int mod=1e9 + 7;
	ncr=new NCRefficient(N,mod);
}
void segBuild(vector<int>&seg,vector<int>&des,int n){
	int domain,start,bit;
	domain=n;start=domain-1;bit=1;
    while(domain>0){
	    
    	for(int index=start;index<start+domain;index++){
    		if(bit==1){
    			seg[index]=(seg[(2*index) + 1] | seg[(2*index) + 2]);
    		}else{
    			seg[index]=(seg[(2*index) + 1] xor seg[(2*index) + 2]);
    		}
    		des[index]=bit;
    	}

        bit=(bit^1);
    	domain=domain/2;start=domain-1;
    }
}
void segUpdate(vector<int>&seg,vector<int>&des,int pos,int val){
	int domain=pow(2,(1+floor(log2(pos))));pos-=1;
    int mypos=pos+ seg.size()/2;
    seg[mypos]=val;
    while( mypos>0){
    	mypos=(mypos-1)/2;
        if(des[mypos]==1) 
            seg[mypos]=(seg[(2*mypos) + 1] | seg[(2*mypos) + 2]);
        else
            seg[mypos]=(seg[(2*mypos) + 1] xor seg[(2*mypos) + 2]);

    }
        
}

bool isnum(char c){
	return c-'A' < 0;
}
inline bool check(int i,int j,int n,int m){
	return i>=0 and j>=0 and i<n and j<m;
}
 

template <typename T>
void appendVector(vector<T>& v,vector<T>& w){
    v.insert(v.end(),w.begin(),w.end());
}


template <typename T>
vector<T> getSubvector(vector<T>& v,int first,int last){
    vector<T> vector(v.begin()+first,v.begin()+last+1);
    return vector;
}

vector<int> pals;
map<int,bool> isPal;
bool isPalindrome(string &s){
	string copy=s;
	reverse(begin(copy),end(copy));
	return s==copy;
}
string intToString(int n){
	ostringstream ostr;
	ostr<<n;
	return ostr.str();
}
bool isPalindromeNumber(int n){
	return isPalindrome(intToString(n));
}
void kickinit(){
	int MAX_LIMIT=1e5 + 10;
	for(int i=1;i<=MAX_LIMIT;i++){
		if(isPalindromeNumber(i)){
			pals.push_back(i);
			isPal[i]=true;
		}
	}
}
void printKickStartCase(int t){
	cout<<"Case #"<<t<<": ";
}























bool isinrange(int a,int l,int r){
	return a>=l && a<=r;
}
void constructTree(vvi & graph,vi & v,int start,int level=0,int par=-1){
	

	

	

	if(v.size()<=level){
		v.pb(0);
	}
	v[level]++;
	FEACH(node,graph[start]){
		if(par != node){
			constructTree(graph,v,node,level+1,start);
		}
	}
}
bool trythis(vi & v,int n,int m){
	

	int sz=v.size();
	int ctr=0;
	if(n%2){
		
		int index=0;
		F(i,0,sz){
			

			if(v[i]>=3*m){
				if((v[i]-3*m)%(2*m)==0){
					index=i;
					break;
				}
			}else break;
		}
		if(v[index]<3*m) return false;
		ctr+=3;
		

		v[index]-=3*m;
		F(i,0,sz){
			if(v[i]>=2*m) ctr+=(v[i]/m);
		}
		v[index]+=3*m;
	}else{
		F(i,0,sz){
			if(v[i]>=2*m) ctr+=(v[i]/(m));
		}
	}
	

	return ctr>=n;
}
void solve(int t){
	

	int n,m,k;
	read(n,m);
	read(k);
	vi v(k);
	readv(v);
	SORT(v);
	REVERSE(v);
	

	bool first=trythis(v,n,m);
	bool second=trythis(v,m,n);
	if(first || second){
		YESNO2(true);
	}else{
		YESNO2(false);
	}
	



}
inline bool isOpenFiles(){
	return true;
	

}
inline bool isTakeTestCase(){
	return true;
	

}
inline void openfiles(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("error.txt", "w", stderr);
	    freopen("output.txt", "w", stdout);
	#endif
}
inline void printTime(){
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}
signed main(){     
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(isOpenFiles()) openfiles();
	

	

	

	

	

	


	int t=1;
	if(isTakeTestCase()) cin>>t;

	for(int i=0;i<t;i++){
		solve(i+1);
	}

	printTime();
	return 0;
}
