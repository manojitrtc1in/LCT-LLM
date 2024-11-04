
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;



typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef __int128_t int128;
typedef __uint128_t uint128;

template<class A,class B,class C>
struct triple{
    A first;B second;C third;
};



#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define minswap(a,b) min(a,b),max(a,b)
#define maxswap(a,b) max(a,b),min(a,b)



template<class A,class B,class C>
istream&operator>>(istream&stream,triple<A,B,C>&obj){
    stream>>obj.first>>obj.second>>obj.third;
    return stream;
}
template<class A,class B,class C>
ostream&operator<<(ostream&stream,const triple<A,B,C>&obj){
    stream<<obj.first<<" "<<obj.second<<" "<<obj.third;
    return stream;
}

ostream&operator<<(ostream&stream,int128&n){
    string res;
    bool negative=n<0;
    if(negative)n*=-1;
    if(n==0)res="0";
    while(n){
        res+='0'+(n%10);
        n/=10;
    }
    if(negative)res+='-';
    reverse(res.begin(),res.end());
    stream<<res;
    return stream;
}
istream&operator>>(istream&stream,int128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    for(int i=negative;i<s.size();i++)n*=10,n+=s[i]-'0';
    if(negative)n*=-1;
    return stream;
}
ostream&operator<<(ostream&stream,uint128&n){
    string res;
    bool negative=n<0;
    if(negative)n*=-1;
    if(n==0)res="0";
    while(n){
        res+='0'+(n%10);
        n/=10;
    }
    if(negative)res+='-';
    reverse(res.begin(),res.end());
    stream<<res;
    return stream;
}
istream&operator>>(istream&stream,uint128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    for(int i=negative;i<s.size();i++)n*=10,n+=s[i]-'0';
    if(negative)n*=-1;
    return stream;
}

template<typename A,typename B>
istream&operator>>(istream&stream,pair<A,B>&obj){
    stream>>obj.first>>obj.second;
    return stream;
}
template<typename A,typename B>
istream&operator>>(istream&stream,const pair<A,B>&obj){
    stream>>obj.first>>obj.second;
    return stream;
}
template<typename A,typename B>
ostream&operator<<(ostream&stream,const pair<A,B>&obj){
    stream<<obj.first<<" "<<obj.second;
    return stream;
}
template<typename T>
istream&operator>>(istream&stream,optional<T>&obj){
    stream>>obj.value;
    return stream;
}
template<typename T>
ostream&operator<<(ostream&stream,const optional<T>&obj){
    stream<<*obj;
    return stream;
}



template<typename T>
void input(vector<T>&obj,int n){
    obj.resize(n);
    for(auto&e:obj)cin>>e;
}
template<typename T>
void input(T*ptr,int n){
    while(n--){
        cin>>(*ptr);
        ptr++;
    }
}
template<typename T>
void input(set<T>&obj,int n){
    obj.clear();
    while(n--){
        T x;
        cin>>x;
        obj.insert(x);
    }
}
template<typename T>
void input(unordered_set<T>&obj,int n){
    obj.clear();
    while(n--){
        T x;
        cin>>x;
        obj.insert(x);
    }
}
template<typename T>
void input(multiset<T>&obj,int n){
    obj.clear();
    while(n--){
        T x;
        cin>>x;
        obj.insert(x);
    }
}
template<class It>
void print(It it,int n){
    if(n==0)return;
    cout<<*it;
    while(--n)cout<<" "<<*(++it);
    cout<<"\n";
}
template<typename A>
auto amin(A a){
    return a;
}
template<typename A,typename... B>
auto amin(A a, B... b){
    auto res=amin(b...);
    return (a<res)?a:res;
}
template<typename A>
auto amax(A a){
    return a;
}
template<typename A,typename... B>
auto amax(A a, B... b){
    auto res=amax(b...);
    return (a>res)?a:res;
}
template<typename A,typename... B>
void setmin(A&a,B... b){
    auto res=amin(b...);
    a=((a<res)?a:res);
}
template<typename A,typename... B>
void setmax(A&a,B... b){
    auto res=amax(b...);
    a=((a>res)?a:res);
}
template<class It1,class It2>
int first_diff(It1 a,It1 b,It2 A,It2 B){
    for(int i=0;a+i!=b&&A+i!=B;i++){
        if(!(*(a+i)==*(A+i)))return i;
    }
    return -1;
}
template<class It1,class It2,class Eq>
int first_diff(It1 a,It1 b,It2 A,It2 B,Eq f){
    for(int i=0;a+i!=b&&A+i!=B;i++){
        if(f(*(a+i),*(A+i)))return i;
    }
    return -1;
}
template<typename A,typename B,typename C>
bool in_range(A a,B b,C c){
    return (b<=a&&a<=c);
}
template<typename A,typename B,typename C>
auto to_range(A a,B b,C c){
    if(a<b)return b;
    return c;
}



#define TREE_TYPE int
typedef tree<
TREE_TYPE,
null_type,
less<TREE_TYPE>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



const int NMAX=4e5;
vector<int>g[NMAX+5];
vector<int>gg[NMAX+5];
int mark[NMAX+5];
bool used[NMAX+5];
bool has_loop[NMAX+5];

void dfs(int v){
    used[v]=1;
    mark[v]=2;
    for(auto u:g[v]){
        if(!used[u])dfs(u);
    }
}

vector<int>top;
void dfs2(int v){
    used[v]=1;
    for(auto u:g[v]){
        if(!used[u])dfs2(u);
    }
    top.push_back(v);
}

int comp[NMAX+5],sz[NMAX+5];
int COMP=0;
void dfs3(int v){
    used[v]=1;
    comp[v]=COMP;
    sz[COMP]++;
    for(auto u:gg[v])
        if(!used[u])dfs3(u);
}

void dfs4(int v){
    used[v]=1;
    mark[v]=-1;
    for(auto u:g[v]){
        if(!used[u])dfs4(u);
    }
}

int in[NMAX+5];

void dfs5(int v){
    used[v]=1;
    for(auto u:g[v]){
        if(in[u]==1&&mark[u]!=0&&mark[u]!=-1){
            mark[u]=1;
            dfs5(u);
        }
    }
}


void solve(){ 
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        gg[b].push_back(a);
        if(a==b)has_loop[a]=1;
    }
    for(int i=1;i<=n;i++)mark[i]=0;

    dfs(1);
    for(int i=1;i<=n;i++)used[i]=0;

    for(int i=1;i<=n;i++)if(!used[i])dfs2(i);
    for(int i=1;i<=n;i++)used[i]=0;
    reverse(all(top));

    for(auto v:top){
        if(!used[v])COMP++,dfs3(v);
    }
    for(int i=1;i<=n;i++)used[i]=0;

    for(int i=1;i<=n;i++){
        if(!used[i]&&mark[i]!=0&&sz[comp[i]]>1)
            dfs4(i);
        if(!used[i]&&mark[i]!=0&&has_loop[i])
            dfs4(i);
    }
    for(int i=1;i<=n;i++)used[i]=0;
    
    for(int i=1;i<=n;i++){
        for(auto u:g[i]){
            if(mark[i]!=0)in[u]++;
        }
    }
    dfs5(1);
    if(mark[1]!=-1)mark[1]=1;
    


    print(mark+1,n);
    

    


    for(int i=1;i<=n;i++)
    g[i].clear(),
    gg[i].clear(),
    mark[i]=0,
    used[i]=0,
    has_loop[i]=0,
    comp[i]=0,sz[i]=0,
    in[i]=0;
    COMP=0;
    top.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}