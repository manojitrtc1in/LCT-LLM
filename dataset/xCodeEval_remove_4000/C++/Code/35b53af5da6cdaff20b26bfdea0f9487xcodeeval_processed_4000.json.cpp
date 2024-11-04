
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

ll id10(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * factmod(n,mod))%mod;
    ll invVal =  (inv(factmod(i,mod),mod)%mod * inv(factmod(n-i,mod),mod)%mod)%mod;
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
vector<vll> id8(int n)
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


class id2{
    private:
    public:
    int total;
    
    int start,end;
    
    int id14, id17;
    
    int thisIndex;
    
    id2(): total(0), start(-1),end(-1), id14(-1), id17(-1), thisIndex(-1){} 
    
    void assignLeaf(ll value, int start, int end, int thisIndex){
        total = value;
        this->start = start;
        this->end = end;
        this->thisIndex = thisIndex;
    }
    void merge( id2 &left,  id2&right){
        this->start = left.start;
        this->end = right.end;
        int leftTotal = left.getValue();
        int rightTotal = right.getValue();
        
        this->id14 = left.thisIndex;
        this->id17 = right.thisIndex;
        
        this->total = leftTotal + rightTotal;
        
    }
    void print(){
         cout<<"\nthisIndex:"<<thisIndex<<"\n";
        cout<<"(start, end): "<<start<<" "<<end<<"\n";
        cout<<"(id14, id17): "<<id14<<" "<<id17<<"\n";
        
        cout<<"total: "<<total<<endl<<endl;
        
       
    }
    int getValue(){
        return total;
    }

    int getSegmentSize(){
        return (end-start + 1);
    }
};
class id12;

const int DEBUG = 0;
const int MAX_VAL = mx6+1;
const int id1 = 4*mx6+5;
const int id13 = 8*20*mx6+10;



unordered_map<int, id2> nodes;
int rootNodes[id1]={-1};




map<pii,int> versionSeen;

class id12{
    private:
    
    int NODE_COUNTER = 0;
    

    

    int currentVersion = 0;
    int N = 0;
    int treeSize = 0;
    int rootNodeSize = 0;
    
    int id7 = 0;
    
    public:
    
    

        
    

    

    

    

    

    

    

        
    

        
    

        
    

    
    id12(){
        
    }
    
    id12(int N){
        

        
        this->N = N+1;
        
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        
        

        

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
    
    void buildTree(const vll & arr){
        int firstRoot = buildTree(arr,0,N-1);
        rootNodes[currentVersion] =firstRoot;
    }
    
    void updateCurrentVersion(int index, ll val){
        
        if(currentVersion>this->rootNodeSize  or rootNodes[currentVersion]==-1){
            throw logic_error("weird currentVersion\n");
        }
        
        int id9 = NODE_COUNTER;
        
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
    
    int queryVersion(int Lindex, int Rindex, int version){
         if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        int versionRoot = rootNodes[version];
        
        id7 = 0;
        
        int ans =  queryVersion(Lindex, Rindex, versionRoot, 0, N-1);
        
        

        

        

        

        

        
        return ans;
        
    }
    
    int getLatestKthVal(int k, int version){
        if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        int ans = getLatestKthVal(k, rootNodes[version], 0, N-1);
        
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
        
        vi prefix_array(N,0);
        
        rep(j,1,N-1)
        {
            prefix_array[j] = queryVersion(1,j,version);
        }
        
        cout<<"Type array: "; 
        print(prefix_array);
        
        cout<<endl<<endl;
    }
    private:
    
    int buildTree(const vll & arr, int L, int R){
        if(L==R)
        {
            int nodeIndex = createNewLeaf(arr[L], L, R);
            return nodeIndex;
        }
        int mid = (L+R)/2;
        
        int id14 = buildTree(arr,L,mid);
        int id17 = buildTree(arr,mid+1,R);
        
        int nodeIndex = createParent(id14, id17, L, R);
        return nodeIndex;
    }
    
    int update(int index, int id15, ll val, int L, int R){
        if(L==R)
        {   
            
            if(id15==-1)
            {
                int nodeIndex = createNewLeaf(val, L, R);
                return nodeIndex;
            }
            
            int nodeIndex = copyNewLeaf(val, id15);
            
            

            

            

            

            

            return nodeIndex;
        }
        
        int mid = (L+R)/2;
        
        int id5 = (id15==-1)?-1:nodes[id15].id14;
        int id6 = (id15==-1)?-1:nodes[id15].id17;
        
        if(0<=index and index<=mid)
        {
            id5 = update(index, id5, val, L, mid);    
        }else if(index>mid and index<=R)
        {
            
            id6 = update(index, id6, val, mid+1, R);
        } else 
        {   
            string message = string("Weird index provided") + string(" L:") + to_string(L) + string(" R: ") + to_string(R)+ string(" index: ")+to_string(index);
            throw logic_error(message);
        }
        
        int nodeIndex = createParent(id5, id6, L, R);
        

        

        

        

        
        return nodeIndex;
    }
    
    int queryVersion(int Lindex, int Rindex, int id15, int L, int R){
        id7+=1;
        if(Rindex<Lindex or id15==-1)
        {
            return 0;
        }
        
        if(L==R)
        {
            return nodes[id15].getValue();
        }
        
        if(Lindex ==L and Rindex ==R)
        {
            return nodes[id15].getValue();
        }
        
        int mid = (L+R)/2;
        
        int leftValue = 0, rightValue = 0;
        
        if(Lindex<=mid and nodes[id15].id14!=-1)
        {
            leftValue = queryVersion(Lindex, min(mid,Rindex), nodes[id15].id14, L,mid);
        }
        
        if(Rindex>mid and nodes[id15].id17!=-1){
            rightValue = queryVersion(max(mid+1,Lindex),Rindex,nodes[id15].id17,mid+1, R );
        }
        
        return leftValue + rightValue;
    }
    
    int getLatestKthVal(int k, int id15, int L, int R){
        if(id15 == -1 or nodes[id15].getValue()<k)
            return this->N;
        
        if(L==R)
        {   
            

            
            

            

            

            

            

            

            
            return L;

        }
        
        int mid = (L+R)/2;
        
        int id14 = nodes[id15].id14;
        int id17 = nodes[id15].id17;
        
        int leftTotal = id14==-1?0:nodes[id14].getValue();
        
        if(leftTotal>=k)
            return getLatestKthVal(k, id14, L, mid);
        else 
            return getLatestKthVal(k-leftTotal, id17, mid+1,R);
    }
    
    int createNewLeaf(int val, int start, int end){
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        nodes[NODE_COUNTER].assignLeaf(val, start, end, NODE_COUNTER);
        
        return NODE_COUNTER;
    }
    
    int copyNewLeaf(int val, int id16){
        
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        
        nodes[NODE_COUNTER] = nodes[id16];
        nodes[NODE_COUNTER].total+=val;
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        
        return NODE_COUNTER;
    }
    
    int createParent(int id14, int id17, int start, int end){
        NODE_COUNTER+=1;
        
        int node_sz = this->treeSize;
        if(NODE_COUNTER>=node_sz)
        {
            throw logic_error("Too many nodes");
        }
        

        

        

        

        

        
        if(id14>=node_sz){
            throw logic_error("bad left child index provided");
        }
        if(id17>=node_sz){
            throw logic_error("bad right child index provided");
        }
        
        auto defaultNode =  id2();
        
        auto leftNode = (id14==-1)?defaultNode:nodes[id14];
        auto rightNode = (id17==-1)?defaultNode:nodes[id17];
        
        nodes[NODE_COUNTER].merge(leftNode, rightNode);
        
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        nodes[NODE_COUNTER].start = start;
        nodes[NODE_COUNTER].end = end;
        
        
        return NODE_COUNTER;
    }
    
    
    
};




vi id4(int n, vll &a)
{   
    vi prev_location(n+1,0);
    
    vector<vi> id11(n+1);
    
    rep(j,1,n)
    {
        
        id11[prev_location[a[j]]+1].push_back(j);
        prev_location[a[j]] =j;
    }
    

    
    id12 segTree(n);
    vi versionNumber(n+1,0);
    
    rep(j,1,n)
    {   
        if(j>1)
            segTree.updateCurrentVersion(j-1,-1);
            
        for(auto new_index: id11[j]){
            segTree.updateCurrentVersion(new_index,1);
        }
        versionNumber[j] = segTree.getCurrentVersion();
        
    }
    vi ans(n,0);
    
    if(DEBUG)
     {   
         rep(L,1,n)
        {   
            cout<<"Type array at L= " <<L<<"\n";
            segTree.debugPrint(versionNumber[L]);    
        }
        
     }
    
    
    rep(k,1,n)
    {
        int ans_k = 0;
        
        int L = 1;
        
        while(L<=n)
        {   
            ans_k+=1;
            

            int R = segTree.getLatestKthVal(k+1, versionNumber[L]);
            

            L = R;
        }
        
        ans[k-1] = ans_k;
    }
    
    return ans;
    
    
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vll a(n+1,0);
    
    rep(j,1,n){
        cin>>a[j];
    }
    
    vi ans = id4(n, a);
    
    print(ans);
    return 0;
}
