











using namespace std;
typedef long long ll;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<string, string> pss; typedef pair<double,double> pdd;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef vector<vvvi> vvvvi; typedef vector<vvvvi> vvvvvi;
typedef vector<char> vc; typedef vector<vc> vvc; 
typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<pii> vpii; typedef vector<pll> vpll;
const int mod9=(int)1e9+9;const int mod7=(int)1e9+7; 
const double PI=3.14159265;
const int dx[] = {-1, 0, 1, 0}; const int dy[] = {0, -1, 0, 1}; 



class DS{
private:vi rank;
        vi root;
public:
    DS(int n);
    int find(int x);
    void unionx(int x, int y);
    bool isconnected(int x, int y);
};


int gcd(int a, int b);


unsigned long long power(unsigned long long x, int y, int p);


unsigned long long modInverse(unsigned long long n, int p);


int modFact(int n,int p);


int id2(int n, int p);


unsigned long long id4(unsigned long long n,int r, int p);


template<typename data>
void print(vector<data> res);


template<typename data>
void print2(vector<data> res);


int searchInsert(vector<int>& nums, int target);


vi primeFactors(int n);


bool isprime(ll n);


bool id5(ll n);


double getsin(double a);
double getcos(double a);


pdd ccw(int a, int b, int ca, int cb, double angle);
pdd cw(int a, int b, int ca, int cb, double angle);


ll max(ll a, ll b);
ll min(ll a, ll b);


ll quickhash(ll a);




ll pairhash(ll hash1, ll hash2);


pll id3(ll hashval);


int phi(int n);



template<typename data> 
void printmap(map<data,data> mp);
template<typename data> 
void printmap(unordered_map<data,data> mp);
template<typename data, typename data2> 
void id0(map<data,data2> mp);
template<typename data, typename data2> 
void id0(unordered_map<data,data2> mp);


template<typename data>
void reduce(data& arr);




template<typename data, typename data_map>
void reduce(data arr, data_map & mp);










vvi dirs = {{1,0},{-1,0},{0,1},{0,-1}};
vvi dirss = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

const double eps=1e-8;
const int inf = (int)1e9; 
const ll llinf=9223372036854775807;

const int maxn = 2e5+5;
const int sz = maxn<<1 + 1;

int nums[maxn];
int segmin[sz],segmax[sz];
int prefmin[maxn],prefmax[maxn];

int getmin(int i, int l, int r, int L, int R){
    if(r<=R && l>=L) return segmin[i];
    if(l>R || r<L) return inf;
    int mid = (l+r)>>1;
    return min(getmin(2*i+1,l,mid,L,R),getmin(2*i+2,mid+1,r,L,R));
}

void updmin(int i, int ti, int l, int r, int val){
    if(ti<l || ti>r) return;
    segmin[i] = min(segmin[i],val);
    if(l!=r){
        int mid = (l+r)>>1;
        updmin(2*i+1,ti,l,mid,val);
        updmin(2*i+2,ti,mid+1,r,val);
    }
}

int buildmin(int i, int l, int r){
    if(l==r) {segmin[i] = nums[l];return nums[l];}
    int mid = (l+r)>>1;
    return segmin[i] = min(buildmin(2*i+1,l,mid),buildmin(2*i+2,mid+1,r));
}

int getmax(int i, int l, int r, int L, int R){
    if(r<=R && l>=L) return segmax[i];
    if(l>R || r<L) return -inf;
    int mid = (l+r)>>1;
    return max(getmax(2*i+1,l,mid,L,R),getmax(2*i+2,mid+1,r,L,R));
}

void updmax(int i, int ti, int l, int r, int val){
    if(ti<l || ti>r) return;
    segmin[i] = max(segmax[i],val);
    if(l!=r){
        int mid = (l+r)>>1;
        updmax(2*i+1,ti,l,mid,val);
        updmax(2*i+2,ti,mid+1,r,val);
    }
}

int buildmax(int i, int l, int r){
    if(l==r) {segmax[i] = nums[l];return nums[l];}
    int mid = (l+r)>>1;
    return segmax[i] = max(buildmax(2*i+1,l,mid),buildmax(2*i+2,mid+1,r));
}


int t,n,m,l,r;
string ord;
void solve(){
    cin>>t;
    while(t--){
        memset(segmin,0,sizeof(segmin));memset(segmax,0,sizeof(segmax));
        cin>>n>>m;
        int id1 = 0;
        cin>>ord;
        nums[0]=0;prefmin[0]=0;prefmax[0]=0;
        

        rep(i,1,n+1){
            if(ord[i-1]=='+'){id1++;nums[i]=id1;}
            else{id1--;nums[i]=id1;}
            prefmax[i]=max(prefmax[i-1],id1);prefmin[i]=min(prefmin[i-1],id1);
        }
        buildmin(0,1,n);buildmax(0,1,n);
        int max1,min1,diff,max2,min2,res;




        rep(i,0,m){
            cin>>l>>r;
            max1 = prefmax[l-1];
            min1 = prefmin[l-1];
            diff = nums[r]-nums[l-1];
            if(r==n) {max2 = -inf; min2 = inf;}
            else{
                max2 = getmax(0,1,n,r+1,n)-diff;
                min2 = getmin(0,1,n,r+1,n)-diff;
            }


            max1 = max(max1,max2);
            min1 = min(min1,min2);
            if(max1>0 && min1>0) {res=max(max1,min1)+1;}
            else if (max1<0 && min1<0) {res = min(max1,min1)+1;}
            else {res = max1-min1+1;}
            cout<<res<<endl;
        }   
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}














bool isprime(ll n){
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=6;i<=sqrt(n)+1;i+=6){
        if(n%(i-1)==0 || n%(i+1)==0) return false;
    }
    return true;
}

bool id5(ll n){
    while(n>1){
        if(n%2) return false; 
        n>>=1;
    }
    return true;
}

ll pairhash(ll hash1, ll hash2){
    if(hash1<=hash2){
        return (ll) (hash2*hash2+hash1);
    }
    else{
        return (ll) (hash1*hash1+hash1+hash2);
    }
}

pll id3(ll hashval){
    if(hashval - (ll)(sqrt(hashval))*(ll)(sqrt(hashval))< (ll)(sqrt(hashval))){
        return {hashval - (ll)(sqrt(hashval))*(ll)(sqrt(hashval)),sqrt(hashval)};
    }
    else{
        return {(ll)(sqrt(hashval)),hashval - (ll)(sqrt(hashval))*(ll)(sqrt(hashval))-(ll)(sqrt(hashval))};
    }
}

ll quickhash(ll a){
    ll hash1 =  (power(101,a,mod7)+mod7)%mod7;
    ll hash2 =  (power(37,a,mod7)+mod7)%mod7;
    ll finalhash = pairhash(hash1,hash2);
    return finalhash;
}

int gcd(int a, int b)       
{
if (a<b)                
    return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template<typename data>
void print(vector<data> res){
    rep(i,0,res.size()){
        cout<<res[i]<<" "; 
    }
}

template<typename data>
void print2(vector<data> res){
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[0].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

int searchInsert(vector<int>& nums, int target) {
    int lower = 0, upper = nums.size()-1;
    

    if (target>nums[upper])
        return nums.size();
    while (lower<upper){
        int mid = lower+(upper-lower)/2;
        

        if (target>nums[mid]){
            lower = mid+1;
        }
        else if (target<nums[mid]){
            upper = mid;
        } 
        else {
            return mid;
        }
    }
    return lower;
}

DS::DS(int n){
    root.resize(n);
    rank.resize(n);
    for(int i=0;i<n;++i){
        root[i]=i;
        rank[i]=1;
    }
}
int DS::find(int x){
    if(root[x]==x) return x;
    return root[x]=find(root[x]);
}
void DS::unionx(int x, int y){
    int rootx=find(x),rooty=find(y);
    if(rootx==rooty) return;
    if(rank[rootx]>rank[rooty]){root[rooty]=rootx;}
    else if (rank[rootx]<rank[rooty]){root[rootx]=rooty;}
    else {root[rootx]=rooty;rank[rooty]++;}
}
bool DS::isconnected(int x, int y){
    return find(x)==find(y);
}



vi primeFactors(int n)
{
    vi res;
    

    while (n % 2 == 0)
    {
        res.push_back(2);
        n = n/2;
    }
 
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        

        while (n % i == 0)
        {
            res.push_back(i);
            n = n/i;
        }
    }
 
    

    

    if (n > 2)
       res.push_back(n);
    return res;
}

double getsin(double a){
    return sin(a*PI/180);
}
double getcos(double a){
    return cos(a*PI/180);
}



pair<double,double> ccw(int a, int b, int ca, int cb, double angle){
   double sina = getsin(angle); 
   double cosa = getcos(angle); 
   a-=ca,b-=cb;
   double anew = a * cosa -  b* sina;
   double bnew = a * sina + b* cosa;
   return {anew+ca,bnew+cb};
}


pair<double,double> cw(int a, int b, int ca, int cb, double angle){
   double sina = getsin(angle); 
   double cosa = getcos(angle); 
   a-=ca,b-=cb;
   double anew = a * cosa +  b* sina;
   double bnew = (-1*a) *sina + b* cosa;
   return {anew+ca,bnew+cb};
}

ll max(ll a, ll b) {
    return a>b?a:b;
}
ll min(ll a, ll b){
    return a<b?a:b;
}

template<typename data> 
void printmap(map<data,data> mp){
    for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
}
template<typename data> 
void printmap(unordered_map<data,data> mp){
    for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
}
template<typename data,typename data2> 
void id0(map<data,data2> mp){
    for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
}
template<typename data,typename data2> 
void id0(unordered_map<data,data2> mp){
    for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
}




int modFact(int n, int p)
{
    if (n >= p)
        return 0;
 
    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}
unsigned long long power(unsigned long long x,int y, int p)
{
    unsigned long long res = 1; 

 
    x = x % p; 

    

 
    while (y > 0)
    {
     
        

        if (y & 1)
            res = (res * x) % p;
 
        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;}
unsigned long long modInverse(unsigned long long n,int p)
{
    return power(n, p - 2, p);
}
int id2(int n, int p)
{
    if (p <= n)
        return 0;
    int res = (p - 1);
    for (int i = n+1; i < p; i++)
        res = (res * modInverse(i, p)) % p;
    return res;
}
unsigned long long id4(unsigned long long n,int r, int p)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;
 
    

    

    

    unsigned long long * fac = new unsigned long long [n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

template<typename data>
void reduce(data& arr){
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    rep(i,0,arr.size()){
        int cur = lob(arr.begin(),arr.end(),arr[i])-arr.begin()+1;
        arr[i] = cur;
    }
}

template<typename data, typename data_map>
void reduce(data arr, data_map & mp){
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    rep(i,0,arr.size()){
        int cur = lob(arr.begin(),arr.end(),arr[i])-arr.begin()+1;
        mp[arr[i]] = cur;
    }
}


int phi(int n)
{
    double result = n;
    for(int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (double)p));
        }
    }
    if (n > 1)
        result *= (1.0 - (1.0 / (double)n));
    return (int)result;
}