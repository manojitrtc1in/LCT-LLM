

using namespace std;



































template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename T>  
string to_string(stack <T> st);
template <typename T>
string to_string(queue<T> q);
string to_string(char c){return string(1, c);}
string to_string(const string s){return '"' + s + '"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(bool b){return (b ? "true" : "false");}
string to_string(vector<bool> v){bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}


template <size_t S>
string to_string(bitset<S> b){string res;res += '{';bool f = true;for (int i = 0; i < S; ++i) {if (!f) {res += ',';}f = false;res += char('0' + b[i]);}res += '}';return res;}
template <typename A>
string to_string(A v){bool first = true;string res = "{";for (const auto& x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename T >
string to_string(stack <T> st){bool first = true;string res = "{";while (!st.empty()) {if (!first) {res += ", ";}first = false;res += to_string(st.top());st.pop();}res += "}";return res;}
template <typename T>
string to_string(queue<T> q){bool first = true;string res = "{";while (!q.empty()) {if (!first) {res += ", ";}first = false;res += to_string(q.front());q.pop();}res += "}";return res;}
template <typename T>
string to_string(T pq, bool ispq){assert(ispq); bool first = true;string res = "{";while (!pq.empty()) {if (!first) {res += ", ";}first = false;res += to_string(pq.top());pq.pop();}res += "}";return res;}


void DBG(){cerr << " ]" << "\n";}
template <typename Head, typename... Tail>
void DBG(Head H, Tail... T){cerr << " " << to_string(H);if (sizeof...(T)) {cerr << ", ";}DBG(T...);}









auto start = std::chrono::system_clock::now();




const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18; 

const int M = 1e9 + 7;





bool id7 = 0; 

bool id1 =  0; 









struct  snode {

    ll val ; 

    ll delta ; 

    snode (ll x){
        val = x ;
        delta = 0  ;
    }

    ll getVal (){
        return val + delta; 
    }


}; 


class stree {

public : 

    vector<ll> L , R , A  ;
    vector<snode> ST ;  

    int n ; 
    stree (vector<ll>& a ){
        A = a; 
        n = a.size(); 
        L.resize(4*n); 
        R.resize(4*n); 
        ST = vector<snode> (4*n , snode(0)); 
        init(1 , 0 , n - 1); 
    }


    void init (int i , int l , int r){
        
        L[i] = l ;
        R[i] = r; 

        if (l == r){
            ST[i] = snode(A[l]); 
            return; 
        }

        ll mid = (l + r)/ 2; 
        init(2*i , l , mid); 
        init(2*i + 1 , mid + 1 , r);

        merge(i); 


    }

    void propogate (int i ){

        ST[2*i].delta += ST[i].delta; 
        ST[2*i + 1].delta += ST[i].delta; 
    }
    void merge (int i ){

        ST[i].val =  (ST[2*i].getVal() +  ST[2*i + 1].getVal()); 
        ST[i].delta = 0 ;
    }
    void update (int i , int l , int r, ll x){
        if (R[i] < l || r < L[i]){
            return; 
        }

        if (l <= L[i] && R[i] <= r){
            ST[i].delta +=  x; 
            return ;
        }

        propogate(i); 
        update(2*i , l , r, x);
        update(2*i + 1 , l , r, x);  
        merge(i); 
    }

    void update(int l , int r, ll x){
        update(1 , l , r , x); 
    }


    ll getVal (int i , int l , int r){

        if (R[i] < l || r < L[i] ){
            return 0LL ;
        }

        if (l <= L[i] && R[i] <= r){
            return ST[i].getVal(); 
        }

        propogate(i); 

        ll left  = getVal(2* i , l , r); 
        ll right = getVal(2 * i + 1 , l, r); 

        merge(i); 

        return left + right; 

    }

    ll getVal(int l , int r){
        return getVal(1 , l , r); 
    }


 


};






class id6 {

public : 

    vector<ll> L , R , A  ;
    vector<snode> ST ;  

    int n ; 
    id6 (vector<ll>& a ){
        A = a; 
        n = a.size(); 
        L.resize(4*n); 
        R.resize(4*n); 
        ST = vector<snode> (4*n , snode(1e18)); 
        init(1 , 0 , n - 1);
    }


    void init (int i , int l , int r){
        
        L[i] = l ;
        R[i] = r; 

        if (l == r){
            ST[i] = snode(A[l]); 
            return; 
        }

        ll mid = (l + r)/ 2; 
        init(2*i , l , mid); 
        init(2*i + 1 , mid + 1 , r);

        merge(i); 


    }

    void propogate (int i ){

        ST[2*i].delta += ST[i].delta; 
        ST[2*i + 1].delta += ST[i].delta; 
    }
    void merge (int i ){

        ST[i].val = min (ST[2*i].getVal() , ST[2*i + 1].getVal()); 
        ST[i].delta = 0 ;
    }
    void update (int i , int l , int r, ll x){
        if (R[i] < l || r < L[i]){
            return; 
        }

        if (l <= L[i] && R[i] <= r){
            ST[i].delta +=  x; 
            return ;
        }

        propogate(i); 
        update(2*i , l , r, x);
        update(2*i + 1 , l , r, x);  
        merge(i); 
    }

    void update(int l , int r , ll x){
        update(1 , l , r , x);
    }

    ll getmin (int i , int l , int r){

        if (R[i] < l || r < L[i] ){
            return 1e18 ;
        }

        if (l <= L[i] && R[i] <= r){
            return ST[i].getVal(); 
        }

        propogate(i); 

        ll left  = getmin(2* i , l , r); 
        ll right = getmin(2 * i + 1 , l, r); 

        merge(i); 

        return min(left , right); 

    }

    ll getmin(int l , int r){
        return getmin(1 , l , r); 
    }

    ll findminind (int i , ll x ){

        if (L[i] == R[i]){
            return L[i]; 
        }

        if (getmin(2*i , L[2*i] , R[2*i] ) == x){
            return findminind (2 * i , x); 
        }

        return  findminind(2*i + 1,x); 

    }

    ll findminind(ll x){
        return findminind(1 , x); 
    }


};











struct DIR_GRAPH {

    
    int n ; 
    vector<vector<ar<int,2>>> adj; 
    bool id8 =  false; 
    int id5 ;
    int diam_len = 0 ;
    vector<int> parent; 
    vector<int> diam_path; 
    vector<int> depths  , tin, tout , subs ;
    vector<vector<ar<int,2>>> tadj, cadj ;
    vector<int>  ind, top_array , comps;
    vector<ar<int,3>> edges;
    vector<int> to1 ;

    int time = 0;  


    DIR_GRAPH (int _n, int id3, bool id0){
        n = _n; 
        adj.resize(n); 
        parent.resize(n, -1); 
        depths.resize(n); 
        tin.resize(n); 
        tout.resize(n); 
        subs.resize(n); 
        to1.resize(n); 
        id5 = id3;
        id8 = id0;
    }

   bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

    void read_graph (){

        int m = id5; 

        int u, v;

        int w;

        for (int i = 0; i < n - 1  ; ++i)
        {

            cin >> u >> v;

            --u;
            --v;

            if (id8)
            {
                cin >> w;
            }
            else
            {
                w = 1;
            }

            edges.push_back({u,v,w});
            adj[u].push_back({v, w});
        }

        for (int i = 0; i < n - 1 ; ++i)
        {

            cin >> u >> v;

            --u;
            --v;

            if (id8)
            {
                cin >> w;
            }
            else
            {
                w = 1;
            }
            edges.push_back({u, v,w});

            to1[u] = w; 
            
        }
    }


    ar<int, 2> dfs_d1(int i, int p, int d, vector<int>& par)
    {

        ar<int, 2> cur = {d, i};

        par[i] = p;

        for (auto j : adj[i])
        {
            if (j[0] == p)
            {
                continue;
            }

            cur = max(cur, dfs_d1(j[0], i, d + 1,par));
        }

        return cur;
    }

    

    void  set_diameter_path()
    {


        vector<int> par = vector<int>(n, -1);

        ar<int, 2> st = dfs_d1(0, -1, 1,par); 


        par = vector<int>(n, -1);

        ar<int, 2> en = dfs_d1(st[1], -1, 1, par);

        diam_len = en[0];

        int u = st[1];
        int v = en[1];

        while (v != u)
        {
            diam_path.push_back(v);
            v = par[v];
        }

        diam_path.push_back(u);
        
    }
    

    void set_others (int i , int p , int d){
        depths[i] =  d; 

        parent[i] = p ;

        int sum = 1 ;

        tin[i] = time; 
        for(auto j : adj[i]){
            if (j[0] == p){
                continue; 
            }
            ++time; 
            set_others(j[0], i , d + 1); 
            sum +=  subs[i]; 
        }
        tout[i] = time; 
        subs[i] = sum; 
    }

    void set_indegree()
    {

        ind.resize(n);

        for (int i = 0; i < n; ++i)
        {
            for (auto j : adj[i])
            {
                ind[j[0]]++;
            }
        }
    }

    void set_topsort()
    {


        ind.clear();
        set_indegree();


        
        queue<int> q;

        for (int i = 0; i < n; ++i)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {

            int u = q.front();
            q.pop();

            top_array.push_back(u);

            for (auto v : adj[u])
            {
                if (--ind[v[0]] == 0)
                {
                    q.push(v[0]);
                }
            }
        }

    }

    void set_transpose_graph()
    {
        tadj.resize(n);
        for (int i = 0; i < n; ++i)
        {
            for (auto &j : adj[i])
            {
                tadj[j[0]].push_back({i, j[1]});
            }
        }
    }

    

    void dfs_sc1(int i, vector<bool> &vis, vector<int> &ord_sc)
    {

        vis[i] = true;

        for (auto &j : adj[i])
        {
            if (vis[j[0]])
            {
                continue;
            }
            dfs_sc1(j[0], vis, ord_sc);
        }

        ord_sc.push_back(i);
    }

    

    void dfs_sc2(int i, int c, vector<bool> &vis)
    {

        vis[i] = true;

        comps[i] = c;

        for (auto j : tadj[i])
        {
            if (vis[j[0]])
            {
                continue;
            }
            dfs_sc2(j[0], c,  vis);
        }
    }

    

    

    void set_compressed_graph()
    {


        vector<bool> vis1(n);

        vector<int> ord_sc;

        comps.resize(n, -1);

        for (int i = 0; i < n; ++i)
        {
            if (vis1[i] == false)
            {
                dfs_sc1(i,  vis1, ord_sc);
            }
        }

        reverse(all(ord_sc));

        set_transpose_graph();

        vector<bool> vis2(n);

        int c = 0;

        for (int i : ord_sc)
        {
            if (vis2[i] == false)
            {
                dfs_sc2(i, c++, vis2);
            }
        }

        cadj.resize(n);

        for (int i = 0; i < n; ++i)
        {
            assert(comps[i] != -1);
            for (auto j : adj[i])
            {
                if (comps[i] == comps[j[0]])
                {
                    continue;
                }
                cadj[comps[i]].push_back({comps[j[0]], j[1]});
            }
        }
    }
};

void dfs(int i , int p , ll cw , vector<ll>& id4 , vector<vector<ar<int,2>>>& adj){

    id4[i] = cw; 

    for(auto j :  adj[i]){
        if (j[0] == p){
            continue; 
        }
        dfs(j[0] , i , cw + j[1] , id4 , adj); 
    }

}



void solve(){

    int n , q; 

    cin >> n  >> q; 

    DIR_GRAPH G(n, 2*n -2, true); 
    G.read_graph(); 
    G.set_others(0,-1, 0);

 


    vector<ll>  id2 (n); 


    vector<ll> A(n); 
    vector<ll> temp (3*n+ 10); 
    stree st(temp) ;
    id6 str(temp); 



    dfs(0 , -1 , 0 , A, G.adj); 
    dbg(G.adj, A); 
    
    for(int i = 0 ; i < n ; ++i){
        st.update(G.tin[i] , G.tin[i] , A[i]); 
        str.update(G.tin[i] , G.tin[i] , A[i] +  G.to1[i]);  
    }

    

    auto dist = [&](int j , int  i ){

        return st.getVal(G.tin[i] , G.tin[i]) -  st.getVal(G.tin[j] , G.tin[j]); 
    }; 

    dbg(G.to1[3] , str.getmin(G.tin[3] , G.tout[3])); 
    int c; 
    
    while(q--){
        cin >>c ;
        if (c == 1){

            int i , w; 

            cin >> i >> w; 
            --i; 

            int u =  G.edges[i][0]; 
            
            int v =  G.edges[i][1]; 
            int &W =  G.edges[i][2]; 

            if (v != 0){
                ll diff = w -W;
                dbg(diff);
                st.update(G.tin[v] , G.tout[v] , diff);
                str.update(G.tin[v],  G.tout[v], diff);   
                W =w; 
            }
            else {
                dbg(u,str.getmin(G.tin[u], G.tin[u])); 
                ll diff =  -str.getmin(G.tin[u], G.tin[u]) + w + st.getVal(G.tin[u],G.tin[u]); 
                dbg("change 1" , diff); 
                str.update(G.tin[u] , G.tin[u] , diff ); 
            }

        
        }
        else {
            int a , b; 
            cin >> a >> b;
            --a;--b;

            if (G.is_ancestor(a,b)){
                cout <<  dist(a,b) << "\n";
            }
            else {
                ll ex = st.getVal(G.tin[a] , G.tin[a]);
                cout << str.getmin(G.tin[a], G.tout[a]) -ex + dist(0,b)  << "\n"; 
            }

        }

    }


    

    


   













}




int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    

    int T = 1 ;

    if (id7){
        id1 =  true; 
    }

    if(id1){
        cin >> T;
    }


    for (int t = 1; t <= T; ++t) {
        if(t == 1){
            
                start = std::chrono::system_clock::now();
            
        }
        if(id7)
            cout << "Case 
        solve();
    }


    
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    


    

    return 0;
}


