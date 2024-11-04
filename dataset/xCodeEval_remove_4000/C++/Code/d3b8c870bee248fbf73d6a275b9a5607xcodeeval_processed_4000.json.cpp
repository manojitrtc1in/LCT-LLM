
using namespace std;
 typedef pair<int,int> pii;
 typedef pair<char,char> pcc;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef tuple<int,int,int> tiii;













 
 
 

 







const long double PI = 2*acos(0.0);
const int stdLength = 25;
const ll max_number = 1048575;
typedef vector<bool> vb;
void print(vb &a)
{
 
    for(bool i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vi &a)
{
 
    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vc &a)
{
 
    for(char i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vll &a)
{
 
    for(ll i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}

void print(deque<ll> &a)
{
 
    for(ll i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}

void print(const multiset<ll> &a)
{
    for(auto i: a){
        cout<<i<<' ';
    }
    cout<<'\n';
}

void print(const map<int, int> &a){
    for(auto i:a)
    {
        cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<'\n';
}
void print(vector<vi> &a)
{
    for(vi i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(vector<vll> &a)
{
    for(vll i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(vector<double> &a)
{
 
    for(double i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<long double> &a)
{
 
    for(long double i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<pll> &a)
{
    for(auto i:a)
    {
        cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<"\n";
}
void print(vector<pii> &a)
{
 
    for(auto i:a)
    {
        cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<"\n";
}
void print(pii &p)
{
    cout<<"("<<p.f<<", "<<p.s<<") ";

}
void print(deque<pll> &a)
{
 
    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
}
ll dist_sq(pll a,pll b)
{
    return ((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}
 
ll po(ll a,ll b)
{
    if(b<=0)
        return 1;
    else if(b==1)
        return a;
 
    ll vl = po((a*a),b/2);
    if(b%2==0)
        return vl;
    else
        return (vl)*a;
}
 
ll powMod(ll a,ll b)
{
    a= a%mod;
    if(b<=0)
        return 1%mod;
    else if(b==1)
        return a%mod;
 
    ll vl = powMod((a*a)%mod,b/2);
    vl = vl%mod;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mod;
}

ll powMod(ll a,ll b,ll mo)
{
    a= a%mo;
    if(b<=0)
        return 1%mo;
    else if(b==1)
        return a%mo;
 
    ll vl = powMod((a*a)%mo,b/2);
    vl = vl%mo;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mo;
}
ll id1(ll n, ll mo)
{
    ll val=n;
    ll ans =1;
    while(val>=1)
    {
        ans = (ans*val)%mo;
        val--;
    }
    
    return ans;
}

vll id11(ll n, ll mo){
    vll id1(n+1,1LL);
    
    rep(j, 1, n){
        id1[j] = (j*id1[j-1])%mo;
    }
    
    return id1;
}



ll inverseMod(ll a,ll mo)
{
    return powMod(a,mo-2,mo);
}

vll id17(ll n, ll mo){
    vll id2(n+1,1LL);
    
    rep(j, 1, n){
        id2[j] = (inverseMod(j, mo)*id2[j-1])%mo;
    }
    
    return id2;
}

vll id8(ll a, ll n, ll mo){
    vll powMod(n+1,1LL);
    rep(j, 1, n)
    {
        powMod[j] = (a * powMod[j-1])%mod;
    }
    return powMod;
}

ll id15(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * id1(n,mod))%mod;
    ll invVal =  (inverseMod(id1(i,mod),mod)%mod * inverseMod(id1(n-i,mod),mod)%mod)%mod;
    ans = (ans * invVal)%mod;
    return ans;
}
ll id3(ll a, ll b){
    if(b>a){
        return id3(b,a);
    }
    if(b==0){
        return a;
    }
    
    if(a%b==0){
        return b;
    } else{
        return id3(b,a%b);
    }
}
ll id3( const vll &numList, int st, int en){
    assert(st>=0 and st<(int)numList.size());
    assert(en>=0 and en<(int)numList.size());
    if(st>en){
        return 0;
    } else if(st==en){
        return numList[st];
    } else if(en==st+1){
        return id3(numList[st],numList[st+1]);
    } else{
        return id3(numList[st],id3(numList,st+1,en));
    }
}
ll id3( const vll &numList){
    if(numList.size()==0){
        return 0;
    }
    int st = 0;
    int en = numList.size();
    en--;
    return id3(numList,st,en);
}
vector<vll> id12(int n)
{
    vector<vll> comb(n+1,vll(n+1,0));
    comb[0][0]=1;
    rep(i,1,n)
    {
        comb[i][0] = 1;
        comb[0][i] = 0;
    }
    
    rep(i,1,n)
    {
        rep(j,1,i)
        {
            comb[i][j] = (comb[i-1][j-1]%mod + comb[i-1][j]%mod)%mod;
        }
    }
    
    return comb;
}
ll id0(ll n)
{
    ll h = 0;
    ll p = 1;
    while(p<=n)
    {
        h++;
        p*=2;
    }
    
    return h-1;
}
ll id0(ll n,ll b)
{
    ll h = 0;
    ll p = 1;
    while(p<=n)
    {
        h++;
        p*=b;
    }
    
    return h-1;
}

class Trie {
    private:
    vector<Trie*> children;
    bool id10 = false;
public:
    
    Trie() {
        children.resize(26,NULL);
        id10 = false;
    }
    
    void insert(string word) {
        Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                cur->children[ind] = new Trie();
                
            }
            cur = cur->children[ind];
        }
        
        cur->id10 = true;
    }
    
    
    bool search(string word) {
        Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                return false;
            }        
                cur = cur->children[ind];
        }
        
        
        return cur->id10;
        
    }
    
    
    bool startsWith(string prefix) {
        string word = prefix ;
        
      Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                return false;
            }        
                cur = cur->children[ind];
        }
        
        
        return true;
    }
};

class id22
{
    public:
    vll BIT;
    
    id22(int n=mx5)
    {
        BIT.resize(n+1,0);
    }
    id22(vll a)
    {
        int n = a.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,a[i]);
        }
    }
    id22(vi a)
    {
        vll b(a.begin(),a.end());
        
        int n = b.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,b[i]);
        }
    }
    
    void update(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        int x = ind;
        int sz = BIT.size();
        
        while(x<sz)
        {
            BIT[x]+=val;
            x += (x&-x);
        }
    }
    
    void set(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        ll currentVal = query(ind,ind);
        update(ind,val-currentVal);
    }
    ll query(int l, int r)
    {   
        assert(0<=l and r<BIT.size());
        
        if(r<l)
        {
            return 0;
        }
        else
            return prefQuery(r) - prefQuery(l-1);
    }
    ll prefQuery(int ind)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        ll sum = 0;
        while(x>0)
        {
            sum+=BIT[x];
            x-=(x&-x);
        }
        
        return sum;
    }
};

class id14
{
    public:
    id22 bitTree;
    
    id14(int n)
    {
        bitTree = id22(n+1);
    }

    void updateRange(pii indexRange, ll val)
    {   
        bitTree.update(indexRange.f, val);
        bitTree.update(indexRange.s + 1,-val);
    }
    
    ll query(int ind)
    {   
        return bitTree.prefQuery(ind);
    }
};

struct P{
	int data,version;
	P(int d=0,int ver=0):data(d),version(ver){}
	inline friend bool operator<(const P &a,const P &b){
		return a.version<b.version;
	}
};


class id9
{
    public:
    vector<vector<P> > BIT;
    int currentVersion;
    
    id9(int n=mx5)
    {
        BIT.resize(n+1,{P()});
        currentVersion = 0;
    }
    
    void update(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        int x = ind;
        int sz = BIT.size();
        currentVersion+=1;
        
        while(x<sz)
        {   
            if(BIT[x].empty())
            {
                throw logic_error("empty array spot");
            }
            auto newVal = P(BIT[x].back().data +val,currentVersion);
            BIT[x].push_back(newVal);
            x += (x&-x);
        }
    }
    
    

    

    

        
    

    

    

    

    

    

        
    

    

    

    

    

    

    

    
    

    

    

    

    ll prefQuery(int ind, int version)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        ll sum = 0;
        while(x>0)
        {   
            if(BIT[x].empty())
            {
                throw logic_error("empty array spot");
            }
            
            auto node = *(upper_bound(BIT[x].begin(),BIT[x].end(),P(0,version))-1);
            
            sum+=node.data;
            x-=(x&-x);
        }
        
        return sum;
    }
};

class id4
{
    public:
    id9 bitTree;
    
    id4(int n)
    {
        bitTree = id9(n+1);
    }

    void updateRange(pii indexRange, ll val)
    {   
        bitTree.update(indexRange.f, val);
        bitTree.update(indexRange.s + 1,-val);
    }
    
    ll query(int ind, int version)
    {   
        return bitTree.prefQuery(ind, version);
    }
};

vll id7(ll highestNum){
    
    vb isPrime(highestNum+5,true);
    vll primes;
    rep(i,2,highestNum){
        if(isPrime[i])
        {   primes.push_back(i);
            ll j = i;
            while(j*i<=highestNum){
                isPrime[j*i]=false;
                j++;
            }
        }
    }
    return primes;
}
ll getMultiplicity(ll num, ll prime){
    ll mult = 0;
    while(num%prime==0){
        mult+=1;
        num/=prime;
    }
    return mult;
}
vll id5(ll num, vll &primes){
    int sz = primes.size();
    vll multcities(sz,0);
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return multcities;
        else
        {
            multcities[i] = getMultiplicity(num,prime);
            ll di = po(prime,multcities[i]);
            num = num/di;
        }
    }
    return multcities;
}

map<ll,ll> id13(ll num, vll &primes){
    int sz = primes.size();
    map<ll,ll> primeFac;
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return primeFac;
        else
        {
            primeFac[prime] = getMultiplicity(num,prime);
            ll di = po(prime,primeFac[prime]);
            num = num/di;
        }
    }
    return primeFac;
}
vpll id6(ll num, vll &primes){
    int sz = primes.size();
    vpll primeFac;
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return primeFac;
        else
        {
            ll mult = getMultiplicity(num,prime);
            ll di = po(prime,mult);
            num = num/di;
        
            if(mult>0){
                primeFac.push_back(make_pair(prime,mult));
            }
        }
    }
    return primeFac;
}
vi compute_z(string s)
{
    int n = s.length();
    vi z(n,0);
    int l=0,r=0;
    z[0]=n;
    rep(i,1,n-1)
    {
        if(r<i)
        {
            l=r=i;
            int j = 0;
            if(s[0]!=s[i])
            {
                continue;
            }
            
            while(j<n and s[j] == s[i+j])
            {
                j++;
            }
            r = i+j-1;
            z[i] = r-i+1;
        }
        else
        {
            int beta = r-i+1;
            int k = i-l;
            
            if(z[k]<beta)
            {   
                
                z[i]=z[k];
              
            }
            else
            {
                int j = 0;
                l = i;
                while(r<n and s[r]==s[r-l])
                {   
                    r+=1;
                }
                r-=1;
                
                z[i] = r-i+1;
                
                
            }
        }
    }
    
    return z;
}

vi id24(string s, string t){
    
     string comb = t + "$" + s;
    
     auto z_vals = compute_z(comb);
     
     int n = s.size();
     int t_sz = t.size();
 
     vi occ;
    
     rep(i,0,n-1)
     {
         if(z_vals[t_sz + 1 +  i]==t_sz){
             occ.push_back(i);
         }
     }
     return occ;
}

class DSU{
    private:
    vi parent;
    vi size;
    public:
    DSU(int n){
        parent.resize(n+5,0);
        size.resize(n+5,0);
        rep(i,1,n){
            parent[i]=i;
            size[i] = 1;
        }
    }
    vi getParents(){
        return parent;
    }
     vi getSizes(){
        return size;
    }
    int getRoot(int node){
       int par = parent[node];
       if(parent[par] == par){
           return par;
       }
       
       int root = getRoot(par);
       
       parent[node] = root;
       
       return root;
    }
    
    bool checkSame(int a, int b){
        return getRoot(a)==getRoot(b);
    }
    
    void connectNodes(int a, int b){
        int root1 = getRoot(a);
        int root2 = getRoot(b);
        
        if(size[root1] < size[root2]){
            swap(root1,root2);
        }
        
        parent[root2] = root1;
        size[root1] += size[root2];
    }
};

class id16{
    private:
    
    ll total;
    ll pendingUpdate;
    
   
    public:
    int start,end;
    
    id16(): total(0), start(-1),end(-1),pendingUpdate(0){} 
    
    void assignLeaf(ll value, int start, int end){
        total = value;
        this->start = start;
        this->end = end;
    }
    void merge(id16 &left, id16&right){
        this->start = left.start;
        this->end = right.end;
        ll leftTotal = left.getValue();
        ll rightTotal = right.getValue();
        
        if(left.ifPendingUpdate()){
            leftTotal += left.getSegmentSize() * left.getPendingUpdate();
        }
        
        if(right.ifPendingUpdate()){
            rightTotal += right.getSegmentSize() * right.getPendingUpdate();
        }
        this->total = leftTotal + rightTotal;
        
    }
    ll getValue(){
        return total;
    }
    
    ll getPendingUpdate(){
        return pendingUpdate;
    }
    bool ifPendingUpdate(){
        return pendingUpdate!=0;
    }
    
    void applyPendingUpdate(){
        this->total += (this->pendingUpdate) * (this->getSegmentSize());
        this->pendingUpdate = 0;
    }
    
    void addUpdate(ll val){
        this->pendingUpdate += val;
    }
    
    int getSegmentSize(){
        return (end-start + 1);
    }
};

class SegmentTree{
   
    
    public:
    int N;
    SegmentTree(vll &arr){
        
        this->N = arr.size();
        this-> treeSize = getSegmentTreeSize(this->N);
        

        nodes.resize(this->treeSize);
        
        this->buildTree(arr,1,0,N-1);
    }
    
     void updateRange(int startPos, int endPos, ll val){
         

         updateRange(1,startPos,endPos,val);
     }
    ll getValue(int startPos, int endPos){
        auto res = getValue(1,startPos,endPos);
        return res.getValue();
    }
    private:
     vector<id16> nodes;
     
     int treeSize;
     
     
     void buildTree(vll &arr,int stIndex, int left, int right){
         if(left==right){
             this->nodes[stIndex].assignLeaf(arr[left],left,right);
             return;
         } 
         
         int mid = (left+right)/2;
         int leftIndex = 2*stIndex,rightIndex = leftIndex+1;
         
         buildTree(arr,leftIndex,left,mid);
         buildTree(arr,rightIndex,mid+1,right);
         
         nodes[stIndex].merge(nodes[leftIndex],nodes[rightIndex]);
     }
     
    void updateRange(int stIndex, int startPos, int endPos, ll val){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            nodes[stIndex].addUpdate(val);
            return;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int id18 = 2*stIndex, id21 = id18 + 1;
        
        if(endPos<=mid){
            updateRange(id18,startPos,endPos,val);
        }else if(startPos>mid){
            updateRange(id21,startPos,endPos,val);
        }else{
            updateRange(id18,startPos,mid,val);
            updateRange(id21,mid+1,endPos,val);
        }
        
        nodes[stIndex].merge(nodes[id18],nodes[id21]);
    }
    
    id16 getValue(int stIndex,int startPos, int endPos){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            auto result = nodes[stIndex];
            if(result.ifPendingUpdate())
                result.applyPendingUpdate();
                
            return result;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int id18 = 2*stIndex, id21 = id18 + 1;
        
        id16 result;
        
        if(endPos<=mid){
            result = getValue(id18,startPos,endPos);
        }else if(startPos>mid){
            result = getValue(id21,startPos,endPos);
        }else{
            auto leftResult = getValue(id18,startPos,mid);
            auto rightResult = getValue(id21,mid+1,endPos);
            
            result.merge(leftResult,rightResult);
        }
        
        if(nodes[stIndex].ifPendingUpdate()){
            result.addUpdate(nodes[stIndex].getPendingUpdate());
            result.applyPendingUpdate();
        }
        
        return result;
    }
     int getSegmentTreeSize(int N){
         int x = 1;
         while(x<N){
             x = x*2;
         }
         return x*2;
     }
};


unordered_map<ll, int> getCount(vll &arr) {
    sort(arr.begin(), arr.end());
    
    int sz = arr.size();
    unordered_map<ll, int> counts;
    int cnt = 1;
    
    rep(j, 1, sz-1)
    {
        if(arr[j]!=arr[j-1])
        {
            counts[arr[j-1]] = cnt;
            cnt = 1;
        }else{
            cnt+=1;
        }
    }
    
    counts[arr[sz-1]] = cnt;
    
    return counts;
}

vector<pair<ll ,ll > > id20(vll &arr) {
    sort(arr.begin(), arr.end());
    
    int sz = arr.size();
    vector<pair<ll ,ll > > counts;
    int cnt = 1;
    
    rep(j, 1, sz-1)
    {
        if(arr[j]!=arr[j-1])
        {
            counts.pb(mp(arr[j-1], cnt));
            cnt = 1;
        }else{
            cnt+=1;
        }
    }
    counts.pb(mp(arr[sz-1], cnt));
    
    return counts;
}

int id23(int node, int w, const vector<map<int, int> > &currentBest){
    auto it = currentBest[node].lower_bound(w);
    if(it == currentBest[node].begin()){
        return 0;
    }
    it--;
    
    return it->second;
}

void id19(int node, int w, vector<map<int,int> > &currentBest){
    auto firstDelete = currentBest[node].find(w);
    assert(firstDelete!= currentBest[node].end());
    auto currentVal = firstDelete->second;
    
    firstDelete++;
    
    auto secondDelete = firstDelete;
    
    while(secondDelete!= currentBest[node].end() and secondDelete->second <= currentVal)
    {
        secondDelete++;
    }
    
    currentBest[node].erase(firstDelete, secondDelete);
    return;
}
const int DEBUG = 0;
int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    
    vector<map<int, int> > currentBest(n+1);
    
    auto finalAns = 0;
    
    rep(e, 1, m){
        int a, b, w;
        cin>>a>>b>>w;
        
        auto prevBest = id23(a, w, currentBest);
        
        auto thisBest = 0;
        
        if(currentBest[b].count(w))
        {
            thisBest = currentBest[b][w];  
        } else {
            thisBest = id23(b, w, currentBest);
        }
        
        if(prevBest + 1 > thisBest)
        {
            currentBest[b][w] = prevBest + 1;
            
            

            

            
            

            

            

            

            
            id19(b, w, currentBest);
        }
        
        finalAns = max(finalAns, prevBest+1);  
        
        if(DEBUG){
            cout<<"a, b, w: "<<a<<" "<<b<<" "<<w<<endl;
            cout<<"prevBest: "<<prevBest<<endl;
            cout<<"thisBest: "<<thisBest<<endl;
            
            cout<<"currentBest[a]: "; print(currentBest[a]);
            cout<<"currentBest[b]: ";print(currentBest[b]);
            cout<<"finalAns: "<<finalAns<<endl;
            cout<<endl;
        }
    }
    cout<<finalAns;
    return 0;
}




























