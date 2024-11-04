




#include<bits/stdc++.h>
#include<cmath>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define debug printf("Debug\n");
#define en '\n'


#define ll long long
#define ull unsigned long long

#define pi acos(-1.0)
#define mod 1000000007
#define INF 1e18
#define _INF -1e18

#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define in_fre  freopen("in.txt", "r", stdin);
#define out_fre freopen("out.txt", "w", stdout);

struct Node{
    ll val,pos;
};



template<typename T> using Pbds=tree<T,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;



template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}



struct CartesianPoint{double x,y;};
struct PolarPoint{double r,ang;};

template <typename T> T SQR(T x){return x*x;}
template <typename T> T DOT(T x1,T y1,T x2,T y2){ return x1*x2+y1*y2;}
template <typename T> T CROSS(T x1,T y1,T x2,T y2){ return x1*y2-x2*y1;}
template <typename T> T PolarR(T x,T y){ return sqrt(SQR(x)+SQR(y));}
template <typename T> T PolarAngle(T x,T y){ return atan2(double(y),double(x));}
template <typename T> T CartesianX(T r,T ang){ return r*cos(double(ang));}
template <typename T> T CartesianY(T r,T ang){ return r*sin(double(ang));}
template <typename T> T CartesianDis(T x1,T y1,T x2,T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T PolarDis(T r1,T ang1,T r2,T ang2){return sqrt(SQR(r1)+SQR(r2)-2.00*r1*r2*cos(ang1-ang2));}
template <typename T> T MiddlePoint(T x1,T x2){return (x1+x2)/2;}
template <typename T> T InternalSection(T x1,T x2,T m1,T m2){ return (m1*x2+m2*x1)/(m1+m2);}
template <typename T> T ExternalSection(T x1,T x2,T m1,T m2){ return (m1*x2-m2*x1)/(m1-m2);}
template <typename T> T AreaOfTriangle(T x1,T y1,T x2,T y2,T x3,T y3){ return (x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1);}
template <typename T> T GradAngle(T x1,T y1,T x2,T y2){ return atan2( double(y1-y2) , double(x1-x2));}
template <typename T> T Grad(T x1,T y1,T x2,T y2){ return (x1-x2)==0.00?1.00*1e18:( double(y1-y2) / double(x1-x2));}
template <typename T> T Line(T m,T c,T x,T y){ return y-m*x-c;}
template <typename T> T Line(T m,T x1,T y1,T x,T y){ return (y-y1)-m*(x-x1);}
template <typename T> T Line(T x1,T y1,T x2,T y2,T x,T y){ return (y2-y1)*x-(x2-x1)*y+(x1*y2-y1*x2);}
template <typename T> T OrthogonalLine(T x1,T y1,T x2,T y2,T lx,T ly,T ox,T oy){ return -lx*(x2-x1)-ly*(y2-y1)+(y2-y1)*ox+(x2-x1)*oy;}
template <typename T> T LineOrthogonalLineIntersecX(T x1,T y1,T x2,T y2,T ox,T oy){ return ((x1-x2)*((y2-y1)*ox+(x2-x1)*oy)-(y1-y2)*(x1*y2-x2*y1))/((y2-y1)*(y1-y2)-SQR(x1-x2));}
template <typename T> T LineOrthogonalLineIntersectY(T x1,T y1,T x2,T y2,T ox,T oy){ return ((x1-x2)*(x1*y2-x2*y1)-(y2-y1)*((y2-y1)*ox+(x2-x1)*oy))/((y2-y1)*(y1-y2)-SQR(x1-x2));}
template <typename T> bool IsParallel(T x1,T y1,T x2,T y2){ (CROSS(x1,y1,x2,y2)==0.00)?true:false;}
template <typename T> bool IsOrthogonal(T x1,T y1,T x2,T y2){ (DOT(x1,y1,x2,y2)==0.00)?true:false;}
template <typename T> T IntersecX(T a1,T b1,T c1,T a2,T b2,T c2){ return (b1*c2-b2*c1)/(a1*b2-a2*b1);}
template <typename T> T IntersecY(T a1,T b1,T c1,T a2,T b2,T c2){ return (b1*c2-b2*c1)/(a1*b2-a2*b1);}
template <typename T> T PointToLineDis(T a,T b,T c,T x,T y){ return (a*x+b*y+c)/sqrt(SQR(a)+SQR(b));}
template <typename T> T PointToLineDis(T x1,T y1,T x2,T y2,T x,T y){ return PointToLineDis(y2-y1,x1-x2,x1*y2-x2*y1);}
template <typename T> T LineToLineDis(T a,T b,T c1,T c2){ return abs(c1-c2)/sqrt(SQR(a)+SQR(b));}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}



class Bitwise_operation{
public:
    ull a[65];
    ull A,B;
    bool check(ull N,ull pos){ return (bool)(N & (1LL<<pos)); }
    ull Set1(ull N,ull pos){ return N=N | (1LL<<pos); }
    ull Set0(ull N,ull pos){ return N=N & ~(1LL<<pos); }
    ull flip(ull N,ull pos){ return N=N ^ (1LL<<pos); }
    bool isPowerOf2(ull n){return !(n&(n-1))?true:false;}
    void swap(){ A = A ^ B;B = A ^ B;A = A ^ B;}
    ull FindLargestPowerof2(ull N){N=N|N>>1;N=N|N>>2;N=N|N>>4;N=N|N>>8;N=N|N>>16;N=N|N>>32; return(N+1)>>1;}
    ull GetRightmost1(ull x){return (x & (-x));}
    ull GetRightmost1spos(ull x){return __builtin_ffs(x)-1;}
    ll CountNumberof1s(ull x){ll cnt=0;while( x ){x = x&(x-1);cnt++;}return cnt;}
    ll CountLeadingZeros(ull x){return __builtin_clz(x);}
    ll CountTrailingZeros(ull x){return __builtin_ctz(x);}
    void possibleSubsets(ll N);

};



class GraphTheory_BFS_DFS{
public:
    ll nodes,edges;
    vector<ll>graph[200005];ll vis[200005];ll cnt[200005];
    void CLR(ll n);
    bool isLeaf(ll node);
    void Connect(ll u,ll v);
    void bfs(ll src);
    void dfs(ll src);
    void CountSubtreeSize(ll cur);
    ll dirx[5]={1,-1,0,0};
    ll diry[5]={0,0,1,-1};
    void GirdBfs(ll i,ll j);
    void GridDfs(ll i,ll j);
};


class DataStructure_DSU{
public:
    ll parent[200005];ll Size[200005];ll Rank[200005];
    void CLR(ll n);
    void make_set(ll v);
    ll find_set(ll v);
    void union_sets(ll a, ll b);
    ll Path_Compressed_find_set(ll v);
    void union_sets_considering_size(ll a, ll b);
    void union_sets_considering_rank(ll a, ll b);
    void union_sets_considering_size_without_path_compression(ll a, ll b);
};

class DataStructure_Trie{
public:
    bool f;
    ll tot;
    ll tri[400005][30],emark[400005],cnt[400005],depth[400005];
    string s;
    void CLR(ll n);
    void build();
    ll Find();
};

class DataStructure_SQRT_DCOM{
public:

};

vector<ll>v;
deque<ll>dq;
stack<ll>stk;
map<ll,pair<ll,ll>>mp;
map<ll,ll>cnt;
unordered_map<ll,ll>ump;
set<ll>st;
multiset<ll>mst;
unordered_set<ll>ust;
unordered_multiset<ll>umst;
priority_queue<ll,deque<ll>,greater<ll>>pq;
Pbds<ll>ost;


int main(){
    

    v={0,4,8,15,16,23,42};
    for(ll i=1;i<6;i++){
        for(ll j=i+1;j<=6;j++){
            mp[v[i]*v[j]]={v[i],v[j]};
        }
    }

    ll ans[10];

    ll x,y;
    cout<<"? 1 2"<<en<<flush;
    cin>>x;
    cout<<"? 2 3"<<en<<flush;
    cin>>y;

    pair<ll,ll>p1,p2;
    p1=mp[x];
    p2=mp[y];
    cnt.clear();
    cnt[p1.first]++;
    cnt[p1.second]++;
    ll b;
    cnt[p2.first]++;
    if(cnt[p2.first]==2) b=p2.first;
    cnt[p2.second]++;
    if(cnt[p2.second]==2) b=p2.second;
    ans[1]=x/b;
    ans[2]=b;
    ans[3]=y/b;


    cout<<"? 4 5"<<en<<flush;
    cin>>x;
    cout<<"? 5 6"<<en<<flush;
    cin>>y;
    p1=mp[x];
    p2=mp[y];
    cnt.clear();
    cnt[p1.first]++;
    cnt[p1.second]++;
    cnt[p2.first]++;
    if(cnt[p2.first]==2) b=p2.first;
    cnt[p2.second]++;
    if(cnt[p2.second]==2) b=p2.second;
    ans[4]=x/b;
    ans[5]=b;
    ans[6]=y/b;

    cout<<"! "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<" "<<ans[5]<<" "<<ans[6]<<en<<flush;



    return 0;
}




void Bitwise_operation::possibleSubsets(ll N){
    for(ll i = 0;i <(1 << N); ++i){
        for(ll j = 0;j < N;++j)
            if(check(i,j))
                cout << a[j]<<' ';
        cout << endl;
    }
}



void GraphTheory_BFS_DFS::CLR(ll n){
    for(ll i=0;i<=n+1;i++){
        graph[i].clear();
        vis[i]=0;
    }
    nodes=n;
}
bool GraphTheory_BFS_DFS::isLeaf(ll node){
    if(graph[node].size()==1) return true;
    else return false;
}

void GraphTheory_BFS_DFS::Connect(ll u,ll v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void GraphTheory_BFS_DFS::bfs(ll src){
    vis[src]=1;
    deque<ll>dq;
    dq.push_back(src);
    while(!dq.empty()){
        src=dq.front();
        dq.pop_front();
        for(ll i=0;i<graph[src].size();i++){
            ll adj=graph[src][i];
            if(vis[adj]==0){
                vis[adj]=1;
                dq.push_back(adj);
            }
        }
    }
}
void GraphTheory_BFS_DFS::dfs(ll src){
    vis[src]=1;
    for(ll i=0;i<graph[src].size();i++){
        ll adj=graph[src][i];
        if(!vis[adj]){
            dfs(adj);
        }
    }
}
void GraphTheory_BFS_DFS::CountSubtreeSize(ll cur){
    vis[cur]=1;
    cnt[cur]++;
    for(ll i=0;i<graph[cur].size();i++){
        ll adj=graph[cur][i];
        if(!vis[adj]){
            CountSubtreeSize(adj);
            cnt[cur]+=cnt[adj];
           

        }
    }
}






void DataStructure_DSU::CLR(ll n){
    for(ll i=0;i<=n+1;i++){
        parent[i]=i;
        Rank[i]=0;
        Size[i]=1;
    }
}
void DataStructure_DSU::make_set(ll v) {
    parent[v] = v;
}
ll DataStructure_DSU::find_set(ll v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void DataStructure_DSU::union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
ll DataStructure_DSU::Path_Compressed_find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v]=Path_Compressed_find_set(parent[v]);
}
void DataStructure_DSU::union_sets_considering_size(ll a, ll b) {
    a = Path_Compressed_find_set(a);
    b = Path_Compressed_find_set(b);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}
void DataStructure_DSU::union_sets_considering_rank(ll a, ll b){
    a = Path_Compressed_find_set(a);
    b = Path_Compressed_find_set(b);
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}
void DataStructure_DSU::union_sets_considering_size_without_path_compression(ll a, ll b){
    

    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}




void DataStructure_Trie::CLR(ll n){
    for(ll i=0;i<=n+1;i++){
        memset(tri[i],0,sizeof(tri[i]));
        emark[i]=0;
        cnt[i]=0;
    }
    s.clear();
    tot=0;
}

void DataStructure_Trie::build(){
    ll now=0;
    ll len=s.length();
    for(ll i=0;i<len;i++){
        ll x=s[i]-'0';
        if(tri[now][x]==0){
            tot++;
            tri[now][x]=tot;
            depth[tot]=depth[now]+1;
            now=tot;
        }
        else{
            now=tri[now][x];
        }
        cnt[now]++;
        if(i==len-1) emark[now]++;
    }
}

ll DataStructure_Trie::Find(){
    ll ans=0;
    ll now=0;
    ll len=s.length();
    for(ll i=0;i<len;i++){
        ll x=s[i]-'0';
        if(tri[now][x]==0){
            return 0;
        }
        else{
            now=tri[now][x];
        }
        if(i==len-1){
            ans=cnt[now];
        }
    }
    return ans;
}



