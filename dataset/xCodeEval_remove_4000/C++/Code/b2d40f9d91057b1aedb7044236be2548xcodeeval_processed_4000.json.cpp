


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<pii, int> P;
typedef pair<double, ll> pdl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = 1e18;
const double EPS = 1e-8;

const int MOD = 998244353;



int n, m;
vector<int> G1[200005];
vector<int> G2[200005];
vector<int> G3[200005];

pii Aid[200005 * 45];
int Bid[200005][45];

bool vis1[200005 * 45];
ll dis1[200005 * 45];

priority_queue<pli> PQ1;

void id2() {
    for(int i = 1; i <= n; ++i) {
        for(int k = 0; k <= 40; ++k) {
            vis1[Bid[i][k]] = 0;
            dis1[Bid[i][k]] = LINF;
        }
    }
    int s = Bid[1][0];
    dis1[s] = 0;
    PQ1.push({-dis1[s], s});
    while(!PQ1.empty()) {
        int q = PQ1.top().second;;
        PQ1.pop();
        if(vis1[q])
            continue;
        vis1[q] = 1;
        int u = Aid[q].first;
        int k = Aid[q].second;
        if((k & 1) == 0) {
            for(int &v : G1[u]) {
                int q2 = Bid[v][k];
                if(vis1[q2])
                    continue;
                if(dis1[q2] <= dis1[q] + 1)
                    continue;
                dis1[q2] = dis1[q] + 1;
                PQ1.push({-dis1[q2], q2});
            }
            if(k + 1 <= 40) {
                for(int &v : G2[u]) {
                    int q2 = Bid[v][k + 1];
                    if(vis1[q2])
                        continue;
                    if(dis1[q2] <= dis1[q] + (1LL << k) + 1)
                        continue;
                    dis1[q2] = dis1[q] + (1LL << k) + 1;
                    PQ1.push({-dis1[q2], q2});
                }
            }
        } else {
            for(int &v : G2[u]) {
                int q2 = Bid[v][k];
                if(vis1[q2])
                    continue;
                if(dis1[q2] <= dis1[q] + 1)
                    continue;
                dis1[q2] = dis1[q] + 1;
                PQ1.push({-dis1[q2], q2});
            }
            if(k + 1 <= 40) {
                for(int &v : G1[u]) {
                    int q2 = Bid[v][k + 1];
                    if(vis1[q2])
                        continue;
                    if(dis1[q2] <= dis1[q] + (1LL << k) + 1)
                        continue;
                    dis1[q2] = dis1[q] + (1LL << k) + 1;
                    PQ1.push({-dis1[q2], q2});
                }
            }
        }
    }
    
}

bool vis2[200005 * 2];
pii dis2[200005 * 2];
priority_queue<P, vector<P>, greater<P> > PQ2;

void id0()  {
    for(int i = 1; i <= n; ++i) {
        vis2[i << 1] = 0;
        vis2[i << 1 | 1] = 0;
        dis2[i << 1] = {INF, INF};
        dis2[i << 1 | 1] = {INF, INF};
    }
    int s = 1 << 1;
    dis2[s] = {0, 0};
    PQ2.push({dis2[s], s});
    while(!PQ2.empty()) {
        int q = PQ2.top().second;
        PQ2.pop();
        if(vis2[q])
            continue;
        vis2[q] = 1;
        int u = q >> 1;
        int k = q & 1;
        if((k & 1) == 0) {
            for(int &v : G1[u]) {
                int q2 = v << 1;
                if(vis2[q2])
                    continue;
                pii id1 = dis2[q];
                id1.second += 1;
                

                if(dis2[q2] <= id1)
                    continue;
                dis2[q2] = id1;
                PQ2.push({dis2[q2], q2});
            }
            for(int &v : G2[u]) {
                int q2 = v << 1 | 1;
                

                if(vis2[q2])
                    continue;
                pii id1 = dis2[q];
                id1.first += 1;
                id1.second += 1;
                

                if(dis2[q2] <= id1)
                    continue;
                dis2[q2] = id1;
                PQ2.push({dis2[q2], q2});
            }
        } else {
            for(int &v : G2[u]) {
                int q2 = v << 1 | 1;
                

                if(vis2[q2])
                    continue;
                pii id1 = dis2[q];
                id1.second += 1;
                

                if(dis2[q2] <= id1)
                    continue;
                dis2[q2] = id1;
                PQ2.push({dis2[q2], q2});
            }
            for(int &v : G1[u]) {
                int q2 = v << 1;
                

                if(vis2[q2])
                    continue;
                pii id1 = dis2[q];
                id1.first += 1;
                id1.second += 1;
                

                if(dis2[q2] <= id1)
                    continue;
                dis2[q2] = id1;
                PQ2.push({dis2[q2], q2});
            }
        }
    }
    
}

ll qpow(ll x, ll n) {
    ll res = 1;
    while(n) {
        if(n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G1[u].push_back(v);
        G2[v].push_back(u);
    }
    int Aidtop = 0;
    for(int i = 1; i <= n; ++i) {
        for(int k = 0; k <= 40; ++k) {
            Bid[i][k] = ++Aidtop;
            Aid[Aidtop] = {i, k};
        }
    }
    id2();
    ll ans = LINF;
    for(int k = 0; k <= 40; ++k)
        ans = min(ans, dis1[Bid[n][k]]);
    if(ans < LINF) {
        printf("%lld\n", ans % MOD);
        return;
    }
    id0();
    ans = 0;
    if(dis2[n << 1] <= dis2[n << 1 | 1]) {
        ans += qpow(2, dis2[n << 1].first) - 1;
        ans += dis2[n << 1].second;
    } else {
        ans += qpow(2, dis2[n << 1 | 1].first) - 1;
        ans += dis2[n << 1 | 1].second;
    }
    printf("%lld\n", ans % MOD);
    return;
}

int main() {

    freopen("A.txt", "r", stdin);


    int T = 1;
    

    for(int i = 1; i <= T; ++i) {
        

        solve();
    }
    return 0;
}
