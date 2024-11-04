
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
 
    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
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

ll id21(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * factmod(n,mod))%mod;
    ll invVal =  (inv(factmod(i,mod),mod)%mod * inv(factmod(n-i,mod),mod)%mod)%mod;
    ans = (ans * invVal)%mod;
    return ans;
}
ll id7(ll a, ll b){
    if(b>a){
        return id7(b,a);
    }
    if(b==0){
        return a;
    }
    
    if(a%b==0){
        return b;
    } else{
        return id7(b,a%b);
    }
}
ll id7( const vll &numList, int st, int en){
    assert(st>=0 and st<(int)numList.size());
    assert(en>=0 and en<(int)numList.size());
    if(st>en){
        return 0;
    } else if(st==en){
        return numList[st];
    } else if(en==st+1){
        return id7(numList[st],numList[st+1]);
    } else{
        return id7(numList[st],id7(numList,st+1,en));
    }
}
ll id7( const vll &numList){
    if(numList.size()==0){
        return 0;
    }
    int st = 0;
    int en = numList.size();
    en--;
    return id7(numList,st,en);
}
vector<vll> id16(int n)
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
    bool id15 = false;
public:
    
    Trie() {
        children.resize(26,NULL);
        id15 = false;
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
        
        cur->id15 = true;
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
        
        
        return cur->id15;
        
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

class id31
{
    public:
    vll BIT;
    
    id31(int n)
    {
        BIT.resize(n+1,0);
    }
    id31(vll a)
    {
        int n = a.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,a[i]);
        }
    }
    id31(vi a)
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
vll id13(ll highestNum){
    
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
vll id9(ll num, vll &primes){
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

map<ll,ll> id17(ll num, vll &primes){
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
vpll id10(ll num, vll &primes){
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

vi id32(string s, string t){
    
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

class id22{
    private:
    
    ll total;
    ll pendingUpdate;
    
   
    public:
    int start,end;
    
    id22(): total(0), start(-1),end(-1),pendingUpdate(0){} 
    
    void assignLeaf(ll value, int start, int end){
        total = value;
        this->start = start;
        this->end = end;
    }
    void merge(id22 &left, id22&right){
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
     vector<id22> nodes;
     
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
        int id25 = 2*stIndex, id30 = id25 + 1;
        
        if(endPos<=mid){
            updateRange(id25,startPos,endPos,val);
        }else if(startPos>mid){
            updateRange(id30,startPos,endPos,val);
        }else{
            updateRange(id25,startPos,mid,val);
            updateRange(id30,mid+1,endPos,val);
        }
        
        nodes[stIndex].merge(nodes[id25],nodes[id30]);
    }
    
    id22 getValue(int stIndex,int startPos, int endPos){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            auto result = nodes[stIndex];
            if(result.ifPendingUpdate())
                result.applyPendingUpdate();
                
            return result;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int id25 = 2*stIndex, id30 = id25 + 1;
        
        id22 result;
        
        if(endPos<=mid){
            result = getValue(id25,startPos,endPos);
        }else if(startPos>mid){
            result = getValue(id30,startPos,endPos);
        }else{
            auto leftResult = getValue(id25,startPos,mid);
            auto rightResult = getValue(id30,mid+1,endPos);
            
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
vector<pii> jiro(100+5);
vi ciel(100+5);
vi id28(100+5);
int n,m;



    






    






    






    
   


    




            




            


            











map<pair<vector<pii>,vi>,int> dpAns;
int calcTotal(int id20, int id18){
    if(id20<0 or id20>n)
    {
        return 0;
    }
    
    if(id18<0 or id18>m){
        return 0;    
    }
    
    if(id18==0){
        return 0;
    }
    
    if(id20==0){
        int ans = 0;
        rep(j,1,id18){
            if(ciel[j]>0){
                ans+=ciel[j];
            }
        }
        return ans;
    }
    
    auto seenBefore = mp(jiro, ciel);
    
    if(dpAns.count(seenBefore)){
        return dpAns[seenBefore];
    }
    bool id1 = true;
    
    rep(jiro_ind,1,id20){
        if( jiro[jiro_ind].first<=8000)
        {
            id1 = false;
            break;
        }
    }
    
    if(id1){
        int id6 = 0;
        rep(id14, 1, id18){
            if(ciel[id14]>0){
                id6+=ciel[id14];
            }
        }
        dpAns[seenBefore]=id6;
        return id6;
    }
    int max_ans = 0;
    rep(id14, 1, id18){
        rep(jiro_ind, 1, id20){
            bool firstCheck = jiro[jiro_ind].second and ciel[id14]>=jiro[jiro_ind].first;
            bool secondCheck = jiro[jiro_ind].second==0 and ciel[id14]>jiro[jiro_ind].first;
            int damage = 0;
            if(!(firstCheck or secondCheck))
            {
                continue;
            }
            
            if(firstCheck){
                damage = ciel[id14] - jiro[jiro_ind].first;
            }
            
            int id11 = ciel[id14];
            int id29 = jiro[jiro_ind].first;
            
            ciel[id14] = -1;
            jiro[jiro_ind].first = 8001;
            
            int rest_damage = calcTotal(id20, id18);
            
            ciel[id14] = id11;
            jiro[jiro_ind].first = id29;
            
            max_ans = max(max_ans, damage+rest_damage);
        }
    }
    dpAns[seenBefore]=max_ans;
    return max_ans;
}

const int DEBUG = 0;

int id4(vi &ciel, vi &id2, vi &id12){
    vector<bool> id8(ciel.size(),false);
    int id5 = ciel.size();
    for(auto jiro_def_card: id12){
        bool found_card = false;
        rep(j,0,id5-1){
            if(ciel[j]>jiro_def_card and !id8[j]){
                id8[j]=1;
                found_card = true;
                break;
            }
        }
        if(!found_card)
            return 0;
    }
    
    int ans = 0;
    int id27 = id2.size();
    
    reprev(jiro_ind,id27-1,0){
        auto id24 = id2[jiro_ind];
        
        bool found_card = false;
        reprev(j,id5-1,0){
            if(ciel[j]>=id24 and !id8[j]){
                id8[j]=1;
                found_card = true;
                ans+=ciel[j]-id24;
                break;
            }
        }
        if(!found_card)
            return 0;
    }
    
    rep(j,0,id5-1){
        if(!id8[j])
        {
            ans+=ciel[j];
        }
    }
    return ans;
    
}

int kPossible(vi &ciel, vi &id2, int k){
    int id5 = ciel.size();
    int id27 = id2.size();
    
    if(k>id27 or k>id5)
        return 0;
    
    int ans = 0;   
    rep(jiro_ind, 0,k-1)
    {
        int id14 = id5-k+jiro_ind;
        
        if(ciel[id14]>=id2[jiro_ind]){
            ans+=ciel[id14]-id2[jiro_ind];
        } else
        {
            return 0;
        }
    }
    return ans;
}
int id23(vi &ciel, vi &id2, vi &id12){
    int id5 = ciel.size();
    int id27 = id2.size();
    
    int maxk = min(id27,id5);
    int ans = 0;
    reprev(k, maxk, 1){
        int id26 = kPossible(ciel, id2, k);
        if(DEBUG){
            cout<<"k, id26: "<<k<<" "<<id26<<"\n";
        }
        ans = max(id26,ans);
    }
    return ans;
}

int computeAns(vi &ciel,vi &id2,vi &id12){
    int id3 = id4(ciel, id2, id12);
    int id19 = id23(ciel, id2, id12);
    if(DEBUG){
        cout<<"id3: "<<id3<<"\n";
        cout<<"id19: "<<id19<<"\n";
    }
    return max(id3, id19);
}
int s = mx6;
map<pair<int,ll>,bool> dp;
vi ans;

bool compute(int start, ll sum, vb & all, vi &vals){
    ll sumval = s-start;
    auto seenVal = mp(start, sum);
    
     if(dp.count(seenVal)){
        return dp[seenVal];
    }
    
    if(sum<0){
        dp[seenVal] =false;
        return false;
    }
    
    if(sumval==sum and all[start])
    {   
        dp[seenVal] =true;
        vals.push_back(start);
        

        return true;
    }
    
    if(sum==0){
        dp[seenVal] =true;
        return true;
    }
    
    
    if(start>s){
        dp[seenVal] =false;
        return false;
    }
   
    bool primaryVal = all[start] and compute(start+1, sum-sumval, all, vals);
    if(primaryVal){
        dp[seenVal] =true;
        vals.push_back(start);
        return true;
    }
    
    bool secondaryVal = compute(start+1,sum, all, vals);
    
    if(secondaryVal){
        dp[seenVal] =true;
        return true;
    }
    dp[seenVal] = false;
    
    return false;
}

vector<int> constructSolution(int start, int sum, vb & all){
    vector<int> ans;
    while(start<s)
    {   int sumval = s-start;
        if(all[start] and dp[mp(start+1, sum-sumval)]){
            ans.push_back(start);
            sum-=sumval;
        }
        start = start+1;
        
    }
    
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    vector<bool> all(mx6+1,true);
    vi X;
    ll sum = 0;
    
    rep(i,1,n)
    {
        int x;
        cin>>x;
        sum+=((ll)x-1);
        all[x]=false;
        X.pb(x);
    }
    
    vi vals;
    
    for(auto x: X){
        if(all[s-(x-1)]){
            sum-=(x-1);
            all[s-(x-1)] = false;
            vals.pb(s-(x-1));
        }
    }
    
    int md = sum%(s-1);
    int mult = sum/(s-1);
    

    

    

    assert(md==0);
    

    

    

    

    

   
    

    
    rep(x,1,s){
        if(sum==0)
            break;
        if(all[x] and all[s-(x-1)]){
            all[x]=false;
            all[s-(x-1)]=false;
            sum-=(s-1);
            vals.pb(x);
            vals.pb(s-(x-1));
        }
    }
    
    printf("%d\n",vals.size());
    for(auto vl: vals){
        printf("%d ",vl);
    }
    return 0;
}