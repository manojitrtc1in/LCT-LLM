
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


class id3{
    private:
    public:
    pair<ll,ll> id2;
    
    int start,end;
    
    int id15, id20;
    
    int thisIndex;
    
    id3(): id2(mp(0,0)), start(-1),end(-1), id15(-1), id20(-1), thisIndex(-1){} 
    
    void assignLeaf(pll value, int start, int end, int thisIndex){
        this->id2 = value;
        this->start = start;
        this->end = end;
        this->thisIndex = thisIndex;
    }
    void merge( id3 &left,  id3&right){
        this->start = left.start;
        this->end = right.end;
        auto id5 = left.getValue();
        auto id1 = right.getValue();
        
        this->id15 = left.thisIndex;
        this->id20 = right.thisIndex;
        
        this->id2 = addPair(id5, id1);
        
    }
    void print(){
         cout<<"\nthisIndex:"<<thisIndex<<"\n";
        cout<<"(start, end): "<<start<<" "<<end<<"\n";
        cout<<"(id15, id20): "<<id15<<" "<<id20<<"\n";
        
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
class id14;

const int DEBUG = 0;

















map<pii,int> versionSeen;

class id14{
    private:
    
    int NODE_COUNTER = 0;
    unordered_map<int, id3> nodes;
    vector<int> rootNodes;
    
    int currentVersion = 0;
    int N = 0;
    int treeSize = 0;
    int rootNodeSize = 0;
    
    int id8 = 0;
    
    public:
    
    id14(const vector<pll> &arr){
        
        this->N = arr.size();
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        

        rootNodes = vector<int>(this->rootNodeSize,-1);
        NODE_COUNTER = 0;
        
        currentVersion = 0;
        
        buildTree(arr);
        
    }
    
    id14(){
        
    }
    
    id14(int N){
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
        
        int id12 = NODE_COUNTER;
        
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
        
        id8 = 0;
        
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
        
        int id15 = buildTree(arr,L,mid);
        int id20 = buildTree(arr,mid+1,R);
        
        int nodeIndex = createParent(id15, id20, L, R);
        return nodeIndex;
    }
    
    int update(int index, int id16, pll val, int L, int R){
        if(L==R)
        {   
            
            if(id16==-1)
            {
                int nodeIndex = createNewLeaf(val, L, R);
                return nodeIndex;
            }
            
            int nodeIndex = copyNewLeaf(val, id16);
            
            

            

            

            

            

            return nodeIndex;
        }
        
        int mid = (L+R)/2;
        
        int id6 = (id16==-1)?-1:nodes[id16].id15;
        int id7 = (id16==-1)?-1:nodes[id16].id20;
        
        if(0<=index and index<=mid)
        {
            id6 = update(index, id6, val, L, mid);    
        }else if(index>mid and index<=R)
        {
            
            id7 = update(index, id7, val, mid+1, R);
        } else 
        {   
            string message = string("Weird index provided") + string(" L:") + to_string(L) + string(" R: ") + to_string(R)+ string(" index: ")+to_string(index);
            throw logic_error(message);
        }
        
        int nodeIndex = createParent(id6, id7, L, R);
        

        

        

        

        
        return nodeIndex;
    }
    
    pll queryVersion(int Lindex, int Rindex, int id16, int L, int R){
        id8+=1;
        if(Rindex<Lindex or id16==-1)
        {
            return mp(0LL,0LL);
        }
        
        if(L==R)
        {
            return nodes[id16].getValue();
        }
        
        if(Lindex ==L and Rindex ==R)
        {
            return nodes[id16].getValue();
        }
        
        int mid = (L+R)/2;
        
        auto leftValue = mp(0LL,0LL);
        auto rightValue = mp(0LL,0LL);
        
        if(Lindex<=mid and nodes[id16].id15!=-1)
        {
            leftValue = queryVersion(Lindex, min(mid,Rindex), nodes[id16].id15, L,mid);
        }
        
        if(Rindex>mid and nodes[id16].id20!=-1){
            rightValue = queryVersion(max(mid+1,Lindex),Rindex,nodes[id16].id20,mid+1, R );
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
    
    int copyNewLeaf(pll val, int id19){
        
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        
        nodes[NODE_COUNTER] = nodes[id19];
        nodes[NODE_COUNTER].id2 = val;
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        
        return NODE_COUNTER;
    }
    
    int createParent(int id15, int id20, int start, int end){
        NODE_COUNTER+=1;
        
        int node_sz = this->treeSize;
        if(NODE_COUNTER>=node_sz)
        {
            throw logic_error("Too many nodes");
        }
        

        

        

        

        

        
        if(id15>=node_sz){
            throw logic_error("bad left child index provided");
        }
        if(id20>=node_sz){
            throw logic_error("bad right child index provided");
        }
        
        auto defaultNode =  id3();
        
        auto leftNode = (id15==-1)?defaultNode:nodes[id15];
        auto rightNode = (id20==-1)?defaultNode:nodes[id20];
        
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
    
    Interval(int id13, int id9, ll a_this, ll b_this, ll id4, ll id18){
        x1 = id13;
        x2 = id9;
        a= a_this;
        b=b_this;
        y1=id4;
        y2 = id18;
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

int id10(vector<Event> &events, ll x){
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
void id11(const vector<Event> &events, const vector<Interval> &intervals, id14 &segTree){
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
vll id17(int n, const vector<Interval> &intervals)
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
    
    id14 segTree(arr);
    
    id11(events,intervals, segTree);
    
    int m;
    cin>>m;
    
    vll ans(m+1,0);
    rep(q_index,1,m){
        int L,R;
        ll x;
        cin>>L>>R>>x;
        
        x = (x+ans[q_index-1])%mx9;
        
        int version = id10(events, x);
        
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
    auto ans = id17(n, intervals);
    
    int ans_sz = ans.size();
    
    rep(j,1,ans_sz-1)
    {
        cout<<ans[j]<<"\n";
    }
    return 0;
}
