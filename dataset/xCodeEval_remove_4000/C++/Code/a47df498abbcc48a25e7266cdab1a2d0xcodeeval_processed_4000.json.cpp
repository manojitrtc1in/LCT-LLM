


















using namespace std;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const dl EPS = 1e-7;













































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































vector<vector<ll>> precost(ll n, vector<ll> &p,vector<ll> &id){
    vector<vector<ll>> res(n,vector<ll> (n));


    for(int i = 0 ; i < n ; i ++){
        vector<ll> deg(p.size());
        for(int j = 1; j <p.size() ; j++){
            deg[p[j]]++;
        }
        ll val = 0;
        for(int j = i; j < n ; j ++){

            ll cur = id[j];
            while(cur!=0 && deg[cur] == 0){
                val++;
                deg[p[cur]]--;
                cur = p[cur];
            }
            res[i][j] = val;
        }
    }
    return res;
}
int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> adj(2);
    vector<vector<ll>> id(2,vector<ll> (n));
    for (int i = 0; i < 2; i++) {
        ll a;
        cin >> a;
        adj[i].resize(a);
        for (int j = 1; j <= a - 1; j++) {
            cin>>adj[i][j];
            adj[i][j]--;
        }
        for(int j = 0 ; j < n ; j ++){
            cin>>id[i][j];
            id[i][j]--;
        }
    }
    vector<vector<vector<ll>>> cost(2);
    for(int i =0 ; i < 2; i ++){
        cost[i] = precost(n,adj[i],id[i]);
    }
    vector<ll> dp(n+1);
    for(int i = 0; i <n ; i ++){
        for(int j = i+1 ; j <= n ; j ++){
            dp [j] = max (dp[j], dp[i] + max(cost[0][i][j-1],cost[1][i][j-1]));
        }
    }
    cout<<dp[n];
    return 0;
}