


using namespace std;

typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;













































v adj[100005];
v rev[100005];
vb visited;

void add_edge(ll a,ll b){
    adj[a].push_back(b);
    rev[b].push_back(a);
}

void top(ll u,stack<ll> &st){
    visited[u] = true;
    for(auto i : adj[u]){
        if(!visited[i]){
            top(i,st);
        }
    }
    st.push(u);
}

void SCC(ll u,v &cur){
    visited[u] = true;
    for(ll i:rev[u]){
        if(!visited[i]){
            SCC(i,cur);
        }
    }
    cur.push_back(u);
}

pair<ll,ll> cost(ll n,v &city){
    ll c = 0,no=1,mod=1000000007;
    stack<ll> st;
    visited.assign(n, false);
    for(ll i=0;i<n;i++){
        if(!visited[i]){
            top(i,st);
        }
    }
    stack<v> id0;
    visited.clear();
    visited.assign(n, false);
    while(!st.empty()){
        auto t = st.top();
        st.pop();
        if(!visited[t]){
            v cur;
            SCC(t,cur);
            id0.push(cur);
        }
    }
    while(!id0.empty()){
        auto x = id0.top();
        id0.pop();
        ll m = INT_MAX,cnt=0;
        for(ll i:x){
            m = min(city[i],m);
        }
        for(ll i:x){
            if(city[i] == m){
                cnt++;
                cnt%=mod;
            }
        }
        c+=m;
        no*=cnt;
        no%=mod;
    }
    return {c,no};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n,m;
    cin >> n;
    v city(n);
    for(ll i=0;i<n;i++){
        cin >> city[i];
    }
    cin >> m;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        add_edge(--x,--y);
    }
    auto x = cost(n,city);
    cout << x.first<< " " << x.second;
    return 0;
}