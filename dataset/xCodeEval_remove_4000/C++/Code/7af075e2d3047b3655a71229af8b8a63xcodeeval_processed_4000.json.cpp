
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
 
ll pomod(ll a,ll b)
{
    a= a%mod;
    if(b<=0)
        return 1%mod;
    else if(b==1)
        return a%mod;
 
    ll vl = pomod((a*a)%mod,b/2);
    vl = vl%mod;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mod;
}

ll pomod(ll a,ll b,ll mo)
{
    a= a%mo;
    if(b<=0)
        return 1%mo;
    else if(b==1)
        return a%mo;
 
    ll vl = pomod((a*a)%mo,b/2);
    vl = vl%mo;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mo;
}
ll factmod(ll n, ll mo)
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
ll inv(ll a,ll mo)
{
    return pomod(a,mo-2,mo);
}

ll id24(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * factmod(n,mod))%mod;
    ll invVal =  (inv(factmod(i,mod),mod)%mod * inv(factmod(n-i,mod),mod)%mod)%mod;
    ans = (ans * invVal)%mod;
    return ans;
}
ll id5(ll a, ll b){
    if(b>a){
        return id5(b,a);
    }
    if(b==0){
        return a;
    }
    
    if(a%b==0){
        return b;
    } else{
        return id5(b,a%b);
    }
}
ll id5( const vll &numList, int st, int en){
    assert(st>=0 and st<(int)numList.size());
    assert(en>=0 and en<(int)numList.size());
    if(st>en){
        return 0;
    } else if(st==en){
        return numList[st];
    } else if(en==st+1){
        return id5(numList[st],numList[st+1]);
    } else{
        return id5(numList[st],id5(numList,st+1,en));
    }
}
ll id5( const vll &numList){
    if(numList.size()==0){
        return 0;
    }
    int st = 0;
    int en = numList.size();
    en--;
    return id5(numList,st,en);
}
vector<vll> id18(int n)
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
    bool id16 = false;
public:
    
    Trie() {
        children.resize(26,NULL);
        id16 = false;
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
        
        cur->id16 = true;
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
        
        
        return cur->id16;
        
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

class id32
{
    public:
    vll BIT;
    
    id32(int n=mx5)
    {
        BIT.resize(n+1,0);
    }
    id32(vll a)
    {
        int n = a.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,a[i]);
        }
    }
    id32(vi a)
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

class id23
{
    public:
    id32 bitTree;
    
    id23(int n)
    {
        bitTree = id32(n+1);
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


class id15
{
    public:
    vector<vector<P> > BIT;
    int currentVersion;
    
    id15(int n=mx5)
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

class id6
{
    public:
    id15 bitTree;
    
    id6(int n)
    {
        bitTree = id15(n+1);
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

vll id10(ll highestNum){
    
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
vll id7(ll num, vll &primes){
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

map<ll,ll> id20(ll num, vll &primes){
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
vpll id9(ll num, vll &primes){
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

vi id33(string s, string t){
    
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


class id3{
    private:
    public:
    pair<ll,ll> id2;
    
    int start,end;
    
    int id26, id31;
    
    int thisIndex;
    
    id3(): id2(mp(0,0)), start(-1),end(-1), id26(-1), id31(-1), thisIndex(-1){} 
    
    void assignLeaf(pll value, int start, int end, int thisIndex){
        this->id2 = value;
        this->start = start;
        this->end = end;
        this->thisIndex = thisIndex;
    }
    void merge( id3 &left,  id3&right){
        this->start = left.start;
        this->end = right.end;
        auto id8 = left.getValue();
        auto id1 = right.getValue();
        
        this->id26 = left.thisIndex;
        this->id31 = right.thisIndex;
        
        this->id2 = addPair(id8, id1);
        
    }
    void print(){
         cout<<"\nthisIndex:"<<thisIndex<<"\n";
        cout<<"(start, end): "<<start<<" "<<end<<"\n";
        cout<<"(id26, id31): "<<id26<<" "<<id31<<"\n";
        
        cout<<"id2: ";
        cout<<"("<<id2.f<<", "<<id2.s<<") ";
        cout<<endl<<endl;
        
       
    }
    pll getValue(){
        return id2;
    }

    int getSegmentSize(){
        return (end-start + 1);
    }
    
    pll addPair(const pll &a, const pll &b){
        return mp(a.f+b.f, a.s+b.s);
    }
};
class id25;

const int DEBUG = 0;

















map<pii,int> versionSeen;

class id25{
    private:
    
    int NODE_COUNTER = 0;
    unordered_map<int, id3> nodes;
    vector<int> rootNodes;
    
    int currentVersion = 0;
    int N = 0;
    int treeSize = 0;
    int rootNodeSize = 0;
    
    int id13 = 0;
    
    public:
    
    id25(const vector<pll> &arr){
        
        this->N = arr.size();
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        

        rootNodes = vector<int>(this->rootNodeSize,-1);
        NODE_COUNTER = 0;
        
        currentVersion = 0;
        
        buildTree(arr);
        
    }
    
    id25(){
        
    }
    
    id25(int N){
        this->N = N+1;
        
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        
        

        rootNodes = vector<int>(this->rootNodeSize,-1);
        NODE_COUNTER = 0;
        
        currentVersion = 0;
        rootNodes[currentVersion] = createParent(-1,-1,0, this->N-1);
        
    }
    void resetTree(int N){
        this->N = N+1;
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        
        NODE_COUNTER=0;
        currentVersion = 0;
        
        rootNodes[currentVersion] = createParent(-1,-1,0,this->N-1);
    }
    
    void buildTree(const vector<pll> & arr){
        int firstRoot = buildTree(arr,0,N-1);
        rootNodes[currentVersion] =firstRoot;
    }
    
    void updateCurrentVersion(int index, pll val){
        
        if(currentVersion>this->rootNodeSize  or rootNodes[currentVersion]==-1){
            throw logic_error("weird currentVersion\n");
        }
        
        int id21 = NODE_COUNTER;
        
        int currentRoot = rootNodes[currentVersion];
       
        int newRoot = update(index, currentRoot, val,0,N-1);
        
        

        

        

        

        

        

        
        currentVersion+=1;
        rootNodes[currentVersion] =newRoot;
        
        

        

        
        

        

        

        

        
        if(currentVersion>this->rootNodeSize or rootNodes[currentVersion]==-1){
            throw logic_error("weird next currentVersion\n");
        }
    }
    
    void dummyUpdateVersion(){
        if(currentVersion>this->rootNodeSize  or rootNodes[currentVersion]==-1){
            throw logic_error("weird currentVersion\n");
        }
        
        int currentRoot = rootNodes[currentVersion];
        currentVersion+=1;
        rootNodes[currentVersion] = currentRoot;
        
    }
    
   pll queryVersion(int Lindex, int Rindex, int version){
         if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        auto versionRoot = rootNodes[version];
        
        id13 = 0;
        
        auto ans =  queryVersion(Lindex, Rindex, versionRoot, 0, N-1);
        
        

        

        

        

        

        
        return ans;
        
    }
    
    

    

    

    

        
    

        
    

    

    
    int getCurrentVersion(){
        return this->currentVersion;
    }
    
    static int getPersistentSegmentTreeSize(int N)
    {
        int val = id0(N) + 1;
        
        return val * 6*N+10;
    }
    
    static int getRootNodeSize(int N)
    {
        return 4*N+5;
    }
    
    void debugPrint(int version = 0){
        cout<<"N: "<<N<<"\n";
        cout<<"Latest version: "<<currentVersion<<"\n";
        
        cout<<"Debug version: "<<version<<"\n";
        
        vector<pll> prefix_array(N);
        
        rep(j,1,N-1)
        {
            prefix_array[j] = queryVersion(1,j,version);
        }
        
        cout<<"Type array: "; 
        print(prefix_array);
        
        cout<<endl<<endl;
    }
    private:
    
    int buildTree(const vector<pll> & arr, int L, int R){
        if(L==R)
        {
            int nodeIndex = createNewLeaf(arr[L], L, R);
            return nodeIndex;
        }
        int mid = (L+R)/2;
        
        int id26 = buildTree(arr,L,mid);
        int id31 = buildTree(arr,mid+1,R);
        
        int nodeIndex = createParent(id26, id31, L, R);
        return nodeIndex;
    }
    
    int update(int index, int id27, pll val, int L, int R){
        if(L==R)
        {   
            
            if(id27==-1)
            {
                int nodeIndex = createNewLeaf(val, L, R);
                return nodeIndex;
            }
            
            int nodeIndex = copyNewLeaf(val, id27);
            
            

            

            

            

            

            return nodeIndex;
        }
        
        int mid = (L+R)/2;
        
        int id11 = (id27==-1)?-1:nodes[id27].id26;
        int id12 = (id27==-1)?-1:nodes[id27].id31;
        
        if(0<=index and index<=mid)
        {
            id11 = update(index, id11, val, L, mid);    
        }else if(index>mid and index<=R)
        {
            
            id12 = update(index, id12, val, mid+1, R);
        } else 
        {   
            string message = string("Weird index provided") + string(" L:") + to_string(L) + string(" R: ") + to_string(R)+ string(" index: ")+to_string(index);
            throw logic_error(message);
        }
        
        int nodeIndex = createParent(id11, id12, L, R);
        

        

        

        

        
        return nodeIndex;
    }
    
    pll queryVersion(int Lindex, int Rindex, int id27, int L, int R){
        id13+=1;
        if(Rindex<Lindex or id27==-1)
        {
            return mp(0LL,0LL);
        }
        
        if(L==R)
        {
            return nodes[id27].getValue();
        }
        
        if(Lindex ==L and Rindex ==R)
        {
            return nodes[id27].getValue();
        }
        
        int mid = (L+R)/2;
        
        auto leftValue = mp(0LL,0LL);
        auto rightValue = mp(0LL,0LL);
        
        if(Lindex<=mid and nodes[id27].id26!=-1)
        {
            leftValue = queryVersion(Lindex, min(mid,Rindex), nodes[id27].id26, L,mid);
        }
        
        if(Rindex>mid and nodes[id27].id31!=-1){
            rightValue = queryVersion(max(mid+1,Lindex),Rindex,nodes[id27].id31,mid+1, R );
        }
        
        return mp(leftValue.f+rightValue.f,leftValue.s+rightValue.s);
    }
    
    int createNewLeaf(pll val, int start, int end){
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        nodes[NODE_COUNTER].assignLeaf(val, start, end, NODE_COUNTER);
        
        return NODE_COUNTER;
    }
    
    int copyNewLeaf(pll val, int id30){
        
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        
        nodes[NODE_COUNTER] = nodes[id30];
        nodes[NODE_COUNTER].id2 = val;
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        
        return NODE_COUNTER;
    }
    
    int createParent(int id26, int id31, int start, int end){
        NODE_COUNTER+=1;
        
        int node_sz = this->treeSize;
        if(NODE_COUNTER>=node_sz)
        {
            throw logic_error("Too many nodes");
        }
        

        

        

        

        

        
        if(id26>=node_sz){
            throw logic_error("bad left child index provided");
        }
        if(id31>=node_sz){
            throw logic_error("bad right child index provided");
        }
        
        auto defaultNode =  id3();
        
        auto leftNode = (id26==-1)?defaultNode:nodes[id26];
        auto rightNode = (id31==-1)?defaultNode:nodes[id31];
        
        nodes[NODE_COUNTER].merge(leftNode, rightNode);
        
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        nodes[NODE_COUNTER].start = start;
        nodes[NODE_COUNTER].end = end;
        
        
        return NODE_COUNTER;
    }
};

struct Interval{
    int x1 =0 , x2=0;
    ll a=0,b=0;
    ll y1=0,y2=0;

    int index = 0;
    
    Interval(int id22, int id14, ll a_this, ll b_this, ll id4, ll id29){
        x1 = id22;
        x2 = id14;
        a= a_this;
        b=b_this;
        y1=id4;
        y2 = id29;
    }
    
    Interval(){
        
    }
};

struct Event{
  int ending = 0;
  int x = 0;
  
  int index = 0;
    
  Event(int x_this, int end_this, int index_this){
      x = x_this;
      ending = end_this;
      index = index_this;
  }
  Event(){
  }
};

bool cmp_event(const Event & a, const Event&b){
    if(a.x==b.x){
        return a.ending<b.ending;
    }
    return a.x<b.x;
}

int id17(vector<Event> &events, ll x){
    int best_index = -1;
    int lo = 0;
    int hi = events.size();
    hi--;
    
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        
        if(events[mid].x<x or (events[mid].x==x and events[mid].ending==0))
        {   
            best_index = max(best_index,mid);
            lo = mid+1;
            
        } else 
        {
            hi = mid-1;
        }
    }
    
    return best_index+1;
}
void id19(const vector<Event> &events, const vector<Interval> &intervals, id25 &segTree){
    for(auto event : events){
        
        int ind = event.index;
        
        if(event.ending==0){
            pll newVal = mp(intervals[ind].a, intervals[ind].b);
            segTree.updateCurrentVersion(ind, newVal);
        } else if (event.ending==1){
            pll newVal = mp(0, intervals[ind].y2);
            segTree.updateCurrentVersion(ind, newVal);
        } else {
            throw logic_error("What ending");
        }
    }
}
vll id28(int n, const vector<Interval> &intervals)
{
    vector<Event> events(2*intervals.size());
    int j = 0;
     vector<pll> arr(intervals.size()+1, mp(0,0));
     
    for(auto interval: intervals){
        if(interval.index!=0)
        {   auto startEvent = Event(interval.x1+1,0,interval.index);
            auto endEvent = Event(interval.x2,1,interval.index);
            events[j] = startEvent;
            events[j+1] = endEvent;
            j+=2;
            
            arr[interval.index] = mp(0,interval.y1);
        }
    }
    
    sort(events.begin(), events.end(), cmp_event);
    
   
    
    
    
    id25 segTree(arr);
    
    
    id19(events,intervals, segTree);
    
    int m;
    cin>>m;
    
    vll ans(m+1,0);
    rep(q_index,1,m){
        int L,R;
        ll x;
        cin>>L>>R>>x;
        
        x = (x+ans[q_index-1])%mx9;
        
        int version = id17(events, x);
        
        pll id2 = segTree.queryVersion(L,R,version);
        
        ans[q_index] = id2.f*x + id2.s;
        
    }
    
    

    
    

    
    return ans;
    
    
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    
    vector<Interval> intervals(n+1);
    
    rep(j,1,n)
    {
        cin>>intervals[j].x1>>intervals[j].x2>>intervals[j].y1>>intervals[j].a>>intervals[j].b>>intervals[j].y2;
        intervals[j].index=j;
        
    }
    auto ans = id28(n, intervals);
    
    int ans_sz = ans.size();
    
    rep(j,1,ans_sz-1)
    {
        cout<<ans[j]<<"\n";
    }
    return 0;
}
