







 
using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi; 
typedef vector <ii> vii;

vvi G, P, dp1, dp2, far, son;
vi first, last, level;
int L, cnt = 0;

void dfs(int v, int p, int l){
    first[v] = cnt++;
    level[v] = l;

    P[v][0] = p;
    for (int i = 1; i <= L; ++i) P[v][i] = P[P[v][i-1]][i-1];

    vvi V;

    for (int i = 0; i < G[v].size(); ++i){
        int u = G[v][i];
        if (u == p) continue;

        dfs(u, v, l + 1);
        V.push_back({-far[u][0], u});
    }

    sort(V.begin(), V.end());
    if (V.size() > 0) {
        far[v][0] = 1 - V[0][0];
        son[v][0] = V[0][1];
    }
    if (V.size() > 1) {
        far[v][1] = 1 - V[1][0];
        son[v][1] = V[1][1];
    }
    if (V.size() > 2) {
        far[v][2] = 1 - V[2][0];
        son[v][2] = V[2][1];
    }

    last[v] = cnt++;
}

bool ancestor(int u, int v){ 

    return (first[u] <= first[v] and last[u] >= last[v]); 
}

int LCA(int u, int v){
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;

    for (int i = L; i >= 0; --i){
        if (not ancestor(P[u][i], v)) u = P[u][i];
    }

    return P[u][0];
}

int find_up(int u, int d){
    for (int i = L; i >= 0; --i){
        int pw = 1 << i;

        if (pw > d) continue;
        u = P[u][i];
        d -= pw;
    }

    return u;
}

ll rec1(int v, int i){ 

    ll& ans = dp1[v][i];    
    if (ans != -1) return ans;

    if (not i) {
        int ans = 1;

        if (son[P[v][0]][0] == v) ans += far[P[v][0]][1];
        else ans += far[P[v][0]][0];

        return ans;
    }

    ans = rec1(P[v][i-1], i-1) + (1 << (i - 1));
    ans = max(ans, rec1(v, i-1));

    return ans;
}



ll rec2(int v, int i){ 

    ll& ans = dp2[v][i];    
    if (ans != -1) return ans;

    if (not i) {
        int ans = 0;

        if (son[P[v][0]][0] == v) ans += far[P[v][0]][1];
        else ans += far[P[v][0]][0];

        ans = max(ans, 1);

        return ans;
    }

    ans = rec2(P[v][i-1], i-1);
    ans = max(ans, rec2(v, i-1) + (1 << (i-1)));

    return ans;
}

ll dist1(int v, int h){ 

    ll ans = 0;
    int d = 0;

    for (int i = L; i >= 0; --i){
        if ((1 << i) > h) continue;

        ans = max(ans, d + rec1(v, i));
        v = P[v][i];
        d += (1 << i);
        h -= (1 << i);
    }

    return ans;
}

ll dist2(int v, int h){ 

    ll ans = 0;
    
    for (int i = L; i >= 0; --i){
        if ((1 << i) > h) continue;

        ans = max(ans, h - (1 << i) + rec2(v, i));
        v = P[v][i];
        h -= (1 << i);
    }

    return ans;
}


void solve_middle(int x, int y, int l){
    ll d = level[x] + level[y] - 2*level[l];

    int prevx = find_up(x, level[x] - level[l] - 1);
    int prevy = find_up(y, level[y] - level[l] - 1);

    ll rooted = far[l][0];
    if (son[l][0] == prevx or son[l][0] == prevy){
        rooted = far[l][1];
        if (son[l][1] == prevx or son[l][1] == prevy) rooted = far[l][2];
    }

    rooted = max(rooted, dist1(l, level[l]));

    ll ans1 = max(far[x][0], max(dist1(x, d/2 - 1), d/2 + rooted));
    ll ans2 = max(far[y][0], max(dist1(y, d/2 - 1), d/2 + rooted));

    cout << max(ans1, ans2) << '\n';
}

void id0(int x, int y){
    ll d = level[x] - level[y];

    int mx = find_up(x, d/2);
    int my = find_up(x, (d/2)+1);

    ll ans1 = max(far[x][0], dist1(x, level[x] - level[mx]));
    ll ans2 = max(dist1(y, level[y]), dist2(my, level[my] - level[y]));

    int prevy = find_up(x, level[x] - level[y] - 1);
    ll root = far[y][0];
    if (son[y][0] == prevy) root = far[y][1];

    ans2 = max(ans2, root);

    int prevxx = find_up(x,level[x] - level[my] - 1);
    ll root2 = far[my][0];
    if (son[my][0] == prevxx) root2 = far[my][1];

    ans2 = max(ans2, root2 + level[my] - level[y]);

    cout << max(ans1, ans2) << '\n';
}

void id1(int x, int y, int l){
    ll d = level[x] + level[y] - 2*level[l];

    int mx = find_up(x, d/2), my = l;
    int prevx = mx, prevy = find_up(y, level[y] - level[l] - 1);
    
    ll ans1 = max(far[x][0], dist1(x, level[x] - level[mx]));
    ll ans2 = max(far[y][0], dist1(y, level[y] - level[l] - 1));

    ll root = far[l][0];
    if (son[l][0] == prevx or son[l][0] == prevy){
        root = far[l][1];
        if (son[l][1] == prevx or son[l][1] == prevy) root = far[l][2];
    }
    root = max(root, dist1(l, level[l]));

    ans2 = max(ans2, root + level[y] - level[l]);

    cout << max(ans1, ans2) << '\n';
}

void solve_normal(int x, int y, int l){
    ll d = level[x] + level[y] - 2*level[l];

    int mx = find_up(x, d/2);
    int my = find_up(x, (d+1)/2);

    ll ans1 = max(far[x][0], dist1(x, level[x] - level[mx]));
    ll ans2 = max(far[y][0], dist1(y, level[y] - level[l] - 1));

    int prevx = find_up(x, level[x] - level[l] - 1);
    int prevy = find_up(y, level[y] - level[l] - 1);

    ll root = far[l][0];
    if (son[l][0] == prevx or son[l][0] == prevy){
        root = far[l][1];
        if (son[l][1] == prevx or son[l][1] == prevy) root = far[l][2];
    }

    root = max(root, dist1(l, level[l]));

    root = max(root, 1 + dist2(my, level[my] - level[prevx])); 

    ll prevxx = find_up(x, level[x] - level[my] - 1);
    
    ll root2 = far[my][0];
    if (son[my][0] == prevxx) root2 = far[my][1];

    
    root = max(root, root2 + level[my] - level[l]);

    ans2 = max(ans2, root + level[y] - level[l]);

    cout << max(ans1, ans2) << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    L = ceil(log2(n));
    G = vvi(n);
    first = last = level = vi(n, -1);
    far = son = vvi(n, vi(3, 0));
    P = dp1 = dp2 = vvi(n, vi(L+1, -1));

    for (int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x; --y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(0, 0, 0);

    
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i){
        int x, y;
        cin >> x >> y;
        --x; --y;

        if (level[y] > level[x]) swap(x, y); 


        int l = LCA(x, y); 

        if (y == l) {
            id0(x, y);
            continue;
        }

        if (level[x] == level[y]){
            solve_middle(x, y, l);
            continue;
        }

        if (level[x] == level[y] + 1){
            id1(x, y, l);
            continue;
        }

        solve_normal(x, y, l);
    }
}















































