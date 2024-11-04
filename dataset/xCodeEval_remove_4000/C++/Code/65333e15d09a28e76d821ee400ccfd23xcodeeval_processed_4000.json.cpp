
 
 






 
 



using namespace std;












































 
const double PI  = 3.141592653589793238463;  

vector<string> id0(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}





 
 
 
inline  void normal(int &a) { a = (a+MOD)%MOD; }
inline  int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline  int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline  int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline  int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline  int modInv(int a) { return modPow(a, MOD-2); }
inline  int modDiv(int a,int b) { return modMul(a, modInv(b)); }
 
 
inline long long toint(const std::string &s) {std::stringstream ss; ss << s; long long x; ss >> x; return x;}
inline std::string tostring(long long number) {std::stringstream ss; ss << number; return ss.str();}
inline std::string tobin(long long x) {return std::bitset<63>(x).to_string();}
 
 
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}    
 
template <typename T> T allmin(T t) {return t;}
template<typename T, typename... Args> T allmin(T t, Args... args) {return min(t, allmin(args...));}
 
template <typename T> T allmax(T t) {return t;}
template<typename T, typename... Args> T allmax(T t, Args... args) {return max(t, allmax(args...));}
 
 


 














vc<int>adj[MAXN];


struct LCA
{   
    int LG=20;
    int lvl[MAXN],P[MAXN][20];

    void build(int n){
        rep(i,0, LG) rep(j,0, n+1) P[j][i] = -1;
        lvl[0] = -1;
        dfs(1,0);
        for(int i=1; i<LG; i++){
            rep(j, 1, n+1)
                if(P[j][i-1] != -1)
                    P[j][i] = P[P[j][i-1]][i-1];
        }
    }

    void dfs(int u, int par){
        lvl[u] = 1+lvl[par];
        P[u][0] = par;
        for(int v:adj[u]){
            if (v == par) continue;
            dfs(v, u);
        }
    }

    int lca(int u, int v){
        int i, lg;
        if (lvl[u] < lvl[v]) swap(u, v);

        for(lg = 0; (1<<lg) <= lvl[u]; lg++);
        lg--;

        for(i=lg; i>=0; i--){
            if (lvl[u] - (1<<i) >= lvl[v])
                u = P[u][i];
        }

        if (u == v) 
            return u;

        for(i=lg; i>=0; i--){
            if (P[u][i] != -1 and P[u][i] != P[v][i])
                u = P[u][i], v = P[v][i];
        }

        return P[u][0];
    }

    

    

    int getAncestor(int u, int dis){
        dis = lvl[u] - dis;
        int i, lg = 0;
        for(; (1<<lg) <= lvl[u]; lg++); lg--;

        for(i=lg; i>=0; i--){
            if (lvl[u] - (1<<i) >= dis)
                u = P[u][i];
        }

        return u;
    }

    

    

    int dis(int u, int v){
        if (lvl[u] < lvl[v]) swap(u, v);
        int w = lca(u, v);
        return lvl[u] + lvl[v] - 2*lvl[w];
    }

    
}lca;
int a[MAXN];
struct RangeSeg
{
    int seg[4*MAXN],lazy[4*MAXN];
    void build(int v,int s,int e){
        if(s==e){
            seg[v]=a[s];
        }
        else{
            int m=(s+e)/2;
            build(2*v,s,m);
            build(2*v+1,m+1,e);
            seg[v]=seg[2*v+1]+seg[2*v];
        }
    }
    void push(int v,int s,int e) {
        if(lazy[v]){    
            seg[v]+=(e-s+1)*lazy[v];
            if(s!=e){
                lazy[2*v]+=lazy[v];
                lazy[2*v+1]+=lazy[v];
            }
            lazy[v]=0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        push(v,tl,tr);
        if(l>tr || r<tl) return ;
        if(l<=tl && tr<=r){
            seg[v]+=(addend)*(tr-tl+1);
            if(tl!=tr){
                lazy[2*v]+=addend;
                lazy[2*v+1]+=addend;
            }
            return;
        }
        int mid=(tr+tl)/2;
        update(2*v,tl,mid,l,r,addend);
        update(2*v+1,mid+1,tr,l,r,addend);
        seg[v]=seg[2*v]+seg[2*v+1];
    }
    int query(int v, int tl, int tr, int l, int r) {
        push(v,tl,tr);
        if (l > r)
            return 0;
        if (l <= tl && tr <= r)
            return seg[v];
        push(v,tl,tr);
        int tm = (tl + tr) / 2;
        return (query(v*2, tl, tm, l, min(r, tm))+
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}st;
int tin[MAXN],tout[MAXN],t=0;
void dfss(int i,int par){
    tin[i]=++t;
    trav(j,adj[i]){
        if(j==par){
            continue;
        }
        dfss(j,i);
    }
    tout[i]=t;
}
void km(){
    int n,m;
    cin>>n>>m;
    vc<int>v(n+1);
    rep(i,1,n+1){
        cin>>v[i];
    }
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfss(1,0);
    rep(i,1,n+1){
        a[tin[i]]=v[i];
    }
    auto f=[&](int root,int u,int x){
        int k=lca.lvl[root]-lca.lvl[u]-1;
        int kth=lca.getAncestor(root,k);
        st.update(1,1,n,1,n,x);
        st.update(1,1,n,tin[kth],tout[kth],-x);
                
    };
    st.build(1,1,n);
    

    

    

    

    

    int curr=1;
    lca.build(n);
    rep(i,0,m){
        int type;
        cin>>type;
        if(type==1){
            int a;cin>>a;
            curr=a;
        }
        else if(type==2){
            int a,b,c;cin>>a>>b>>c;
            int l1=lca.lca(a,b);
            int l2=lca.lca(a,curr);
            int l3=lca.lca(b,curr);
            

            

            int l;
            if(lca.lvl[l1]>=lca.lvl[l2] && lca.lvl[l1]>=lca.lvl[l3]){
                l=l1;
            }
            else if(lca.lvl[l2]>=lca.lvl[l1] && lca.lvl[l2]>=lca.lvl[l3]){
                l=l2;
            }
            else if(lca.lvl[l3]>=lca.lvl[l1] && lca.lvl[l3]>=lca.lvl[l2]){
                l=l3;
            }
            if(l==curr){
                st.update(1,1,n,1,n,c);
                continue;
            }
            

            int j=lca.lca(l,curr);
            

            if(j==l){
                f(curr,l,c);
                continue;
            }
            st.update(1,1,n,tin[l],tout[l],c);

        }
        else{
            int a;
            cin>>a;
            

            if(a==curr){
                

                cout<<st.query(1,1,n,1,n)<<endl;
                int q=st.query(1,1,n,1,n);
                

                continue;
            }
            if(lca.lca(a,curr)==a){
                int ans=st.query(1,1,n,1,n);
                int k=lca.lvl[curr]-lca.lvl[a]-1;
                int kth=lca.getAncestor(curr,k);
                cout<<ans-st.query(1,1,n,tin[kth],tout[kth])<<endl;

                continue;

            }
            cout<<st.query(1,1,n,tin[a],tout[a])<<endl;

        }

    }


    

}


 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    clock_t start, end; 
    start = clock(); 
 
    accuracy;
    int testcases=1;
    

    

    

    
    while(testcases--){
    km();
    }
 
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    

    
 
    }
 