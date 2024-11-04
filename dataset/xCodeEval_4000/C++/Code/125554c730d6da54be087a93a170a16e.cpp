#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<iomanip>
#include<functional>
#include<cassert>
#include<ctime>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<list>

#include<bitset>
#define ll long long
#define Buffon_Color system ("color a");
#define Buffon_testes int t;cin>>t;while(t--)
#define Buffon_speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Buffon_out cout<<fixed<<setprecision(6);
#define pp push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
bool is_prime(ll n)
{
    

    if(n==1||n==0)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}


int fib(int n)
{
    

    if(n<=1)
    {
        return n;
    }
    

    return fib(n-1)+fib(n-2);
}


int gcd(int a,int b)
{
    

    

    if(b==0)
        return a;
    

    return(b,a%b);
}


int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}


long long fac(ll n)
{
    

    if(n==1)
    {
        return n;
    }
    

    return n*fac(n-1);
}










int pow(int a,int b)
{
    

    if(b==0)return 1;
    

    int sum=pow(a,b/2);
    sum*=sum;
    if(b%2!=0)sum*=a;
    return sum;
}


long long sumpow(long long a,int k)
{
    

    if(k==0)return 0;
    if(k%2==1)return a*(1+sumpow(a,k/2-1));
    

    long long h=sumpow(a,k/2-1);
    return h*(1+h-sumpow(a,k/2-1));
}


bool sbs( pair<int ,char> &a,
          pair<int ,char> &b)
{
    if(a.second==b.second)
        return(a.first>b.first);
    else
        return (a.second > b.second);
}


bool sbss( pair<int ,char> &a,
           pair<int ,char> &b)
{
    if(a.first==b.first)
        return(a.second>b.second);
    else
        return (a.first < b.first);
}


bool so(string s,string z)
{
    return s+z<z+s;
}


bool can_be_palindrome(string s)
{
    int co[256]={};
    for (int i=0; s[i]; i++)
        co[s[i]]++;
    int o = 0;
    for (int i = 0; i < 256; i++) {
        if (co[i] & 1)
            o++;

        if (o > 1)
            return 0;
    }
    return 1;
}











int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};



bool is_factorial(ll n)
{
    ll sum=1;
    for(int i=1;i<=20;i++)
    {
        sum*=i;
        if(sum==n)return 1;
    }
    return 0;
}


ll int decimal (string s)
{
    int n=s.size();unsigned ll sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {


            sum+=(pow(2,n-i-1));
        }
    }
    return sum;
}






struct graph {
    int n;
    int m;

    vvi al;
    vi morphism;

    vvi dfs_children;
    vi dfs_parent;
    vi dfs_num;
    vi dfs_low;
    int dfs_count;

    bool is_root_ac = false;

    bool bad_biccon = false;
    vii repr_edge;

    void dt_dfs(int v, int par) {
        dfs_parent[v] = par;
        dfs_num[v] = dfs_low[v] = dfs_count++;
        for(int u : al[v]) {
            if(u == par) {
                

            }
            else if(dfs_num[u] == -1) {
                dfs_children[v].push_back(u);
                dt_dfs(u, v);
                dfs_low[v] = min(dfs_low[v], dfs_low[u]);
            }
            else {
                dfs_low[v] = min(dfs_low[v], dfs_num[u]);
            }
        }
    }

    ii min_repr_edge(ii a, ii b) {
        if(a.first == -1) return b;
        if(b.first == -1) return a;
        if(dfs_num[a.second] < dfs_num[b.second]) return a;
        if(dfs_num[a.second] > dfs_num[b.second]) return b;
        if(dfs_num[a.first] > dfs_num[b.first]) return a;
        if(dfs_num[a.first] < dfs_num[b.first]) return b;
        return a;
    }

    void dt_dfs_hamil(int v) {
        repr_edge[v] = ii(-1, -1);

        for(int u : dfs_children[v]) {
            dt_dfs_hamil(u);
            repr_edge[v] = min_repr_edge(repr_edge[v], repr_edge[u]);
        }

        for(int u : al[v]) {
            if(u == dfs_parent[v]) {
                

            }
            else if(dfs_num[u] < dfs_num[v]) {
                repr_edge[v] = min_repr_edge(repr_edge[v], ii(v, u));
            }

        }

        if(dfs_parent[v] == -1) {
            


            

        }
        else {
            if(dfs_children[v].size() == 0) {
                

            }
            else if(dfs_children[v].size() == 1) {
                

                if(dfs_low[dfs_children[v][0]] != dfs_low[v] && dfs_low[dfs_children[v][0]] != dfs_num[dfs_parent[v]]) {
                    bad_biccon = true;
                }
            }
            else if(dfs_children[v].size() == 2) {
                

                if(dfs_parent[dfs_parent[v]] != -1) {
                    if(!((dfs_low[dfs_children[v][0]] == dfs_num[dfs_parent[v]]) ^ (dfs_low[dfs_children[v][1]] == dfs_num[dfs_parent[v]]))) {
                        bad_biccon = true;
                    }
                }
                if(dfs_low[v] < min(dfs_low[dfs_children[v][0]], dfs_low[dfs_children[v][1]])) {
                    bad_biccon = true;
                }
            }
            else {
                bad_biccon = true;
            }
        }
    }

    void dt_dfs_cedges(vvii& cedges, vii& edge_stack, int v, int par) {
        dfs_parent[v] = par;
        dfs_num[v] = dfs_low[v] = dfs_count++;
        for(int u : al[v]) {
            if(u == par) {
                

            }
            else if(dfs_num[u] == -1) {
                dfs_children[v].push_back(u);
                edge_stack.emplace_back(v, u);
                dt_dfs_cedges(cedges, edge_stack, u, v);
                dfs_low[v] = min(dfs_low[v], dfs_low[u]);

                if((par == -1 && is_root_ac) || (par != -1 && dfs_low[u] >= dfs_num[v])) {
                    vii comp;
                    while(edge_stack.back().first != v || edge_stack.back().second != u) {
                        comp.push_back(edge_stack.back());
                        edge_stack.pop_back();
                    }
                    comp.push_back(edge_stack.back());
                    edge_stack.pop_back();
                    cedges.push_back(comp);
                }
            }
            else {
                dfs_low[v] = min(dfs_low[v], dfs_num[u]);
                if(dfs_num[u] < dfs_num[v]) {
                    edge_stack.emplace_back(v, u);
                }
            }
        }
    }

    void generate_dfs_tree(int root) {
        dfs_children = vvi(n, vi());
        dfs_parent = vi(n);
        dfs_count = 0;
        dfs_num = vi(n, -1);
        dfs_low = vi(n, -1);
        dt_dfs(root, -1);
    }

    void generate_edge_partition(vvii& cedges, vii& edge_stack, int root) {
        generate_dfs_tree(root);
        is_root_ac = (dfs_children[root].size() > 1);

        dfs_children = vvi(n, vi());
        dfs_parent = vi(n);
        dfs_count = 0;
        dfs_num = vi(n, -1);
        dfs_low = vi(n, -1);
        dt_dfs_cedges(cedges, edge_stack, root, -1);
        if(!edge_stack.empty()) cedges.push_back(edge_stack);
    }

    void generate_hamil_dfs_tree(int root) {
        generate_dfs_tree(root);
        repr_edge = vii(n, ii());
        dt_dfs_hamil(root);
    }
};

vector<graph> partition_biconnected(graph& g) {
    vvii cedges;
    vii edge_stack;
    g.generate_edge_partition(cedges, edge_stack, 0);
    vector<graph> comp;
    for(vii& vec : cedges) {
        graph h;
        h.n = 0;
        h.m = vec.size();
        unordered_map<int, int> rmorph;
        for(ii e : vec) {
            if(rmorph.find(e.first) == rmorph.end()) {
                rmorph[e.first] = h.n++;
            }
            if(rmorph.find(e.second) == rmorph.end()) {
                rmorph[e.second] = h.n++;
            }
        }
        h.morphism = vi(h.n);
        h.al = vvi(h.n);
        for(ii e : vec) {
            int u = rmorph[e.first];
            int v = rmorph[e.second];
            h.morphism[u] = g.morphism[e.first];
            h.morphism[v] = g.morphism[e.second];
            h.al[u].push_back(v);
            h.al[v].push_back(u);
        }
        comp.push_back(h);
    }
    return comp;
}

void upwards_path(graph& g, vi& hc, int v, int tar);

void downwards_path(graph& g, vi& hc, int v, int tar);

void upwards_path(graph& g, vi& hc, int v, int tar) {
    if(g.dfs_children[v].size() == 2) {
        int u1 = g.dfs_children[v][0];
        int u2 = g.dfs_children[v][1];
        if(g.repr_edge[u1] == g.repr_edge[v]) swap(u1, u2);
        hc.push_back(v);
        downwards_path(g, hc, u1, g.repr_edge[u1].first);
        if(v != tar) {
            upwards_path(g, hc, g.dfs_parent[v], tar);
        }
    }
    else if(g.dfs_children[v].size() == 1) {
        int u = g.dfs_children[v][0];
        hc.push_back(v);
        if(g.repr_edge[u] != g.repr_edge[v]) {
            downwards_path(g, hc, u, g.repr_edge[u].first);
        }
        if(v != tar) {
            upwards_path(g, hc, g.dfs_parent[v], tar);
        }
    }
    else {
        hc.push_back(v);
        if(v != tar) {
            upwards_path(g, hc, g.dfs_parent[v], tar);
        }
    }
}

void downwards_path(graph& g, vi& hc, int v, int tar) {
    if(g.dfs_children[v].size() == 2) {
        int u1 = g.dfs_children[v][0];
        int u2 = g.dfs_children[v][1];
        if(g.repr_edge[u1] == g.repr_edge[v]) swap(u1, u2);
        upwards_path(g, hc, g.repr_edge[u1].first, u1);
        hc.push_back(v);
        downwards_path(g, hc, u2, tar);
    }
    else if(g.dfs_children[v].size() == 1) {
        int u = g.dfs_children[v][0];
        if(v == tar) {
            upwards_path(g, hc, g.repr_edge[u].first, u);
            hc.push_back(v);
        }
        else {
            hc.push_back(v);
            downwards_path(g, hc, u, tar);
        }
    }
    else {
        hc.push_back(v);
    }
}

vi hamiltonian_cycle(graph& g) {
    g.generate_hamil_dfs_tree(0);
    if(g.bad_biccon) return vi();
    vi hc;
    downwards_path(g, hc, 0, g.repr_edge[0].first);
    assert((int)hc.size() == g.n);
    return hc;
}

int comp_index;
bool cyclic_comparator(int a, int b) {
    if(a < comp_index) a += 1e7;
    if(b < comp_index) b += 1e7;
    return a < b;
}

graph sort_graph(const graph& g, const vi& hc) {
    graph h;
    h.n = g.n;
    h.m = g.m;
    h.morphism = vi(g.n);
    h.al = vvi(g.n);
    vi rhc(g.n);
    for(int i=0; i < g.n; ++i) {
        h.morphism[i] = g.morphism[hc[i]];
        rhc[hc[i]] = i;
    }
    for(int i=0; i < g.n; ++i) {
        for(int j : g.al[hc[i]]) {
            h.al[i].push_back(rhc[j]);
        }
        comp_index = i;
        

        sort(h.al[i].begin(), h.al[i].end(), cyclic_comparator);
    }
    return h;
}

bool has_crossing(const graph& g) {
    vii bad_stack;
    for(int i=0; i < g.n; ++i) {
        comp_index = i;
        while(!bad_stack.empty() && i == bad_stack.back().first) bad_stack.pop_back();
        for(int j=(int)g.al[i].size()-2; j > 0; --j) {
            int u = g.al[i][j];
            if(!bad_stack.empty() && cyclic_comparator(bad_stack.back().first, u) && cyclic_comparator(u, bad_stack.back().second)) {
                return true;
            }
            if(u > i && (bad_stack.empty() || u != bad_stack.back().first)) {
                bad_stack.emplace_back(u, i);
            }
        }
    }
    return false;
}

void merge_ans(const graph& g, vvi& ans) {
    for(int i=0; i < g.n; ++i) {
        for(int j : g.al[i]) {
            ans[g.morphism[i]].push_back(g.morphism[j]);
        }
    }
}

void merge_single_edge_ans(const graph& g, vvi& ans) {
    int u = g.morphism[0];
    int v = g.morphism[1];
    ans[u].push_back(v);
    ans[v].push_back(u);
}

vvi solve(graph& input_graph) {
    vvi ans(input_graph.n);
    vector<graph> components = partition_biconnected(input_graph);
    for(graph g : components) {
        if(g.n == 1) {
            

        }
        else if(g.n == 2) {
            merge_single_edge_ans(g, ans);
        }
        else {
            vi hc = hamiltonian_cycle(g);
            if(hc.empty()) {
                return vvi();
            }
            graph g2 = sort_graph(g, hc);
            if(has_crossing(g2))  return vvi();
            merge_ans(g2, ans);
        }
    }
    return ans;
}

graph read_graph() {
    graph g;
    int n, m;
    cin >> n >> m;
    g.n = n;
    g.m = m;
    g.al = vvi(n, vi());
    g.morphism = vi(n, 0);
    for(int i=0; i < n; ++i) {
        g.morphism[i] = i;
    }
    for(int i=0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.al[u].push_back(v);
        g.al[v].push_back(u);
    }
    return g;
}

void print_ans(const vvi& ans) {
    int n = ans.size();
    if(n == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for(int i=0; i < n; ++i) {
            for(int x : ans[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
int main() {




    Buffon_speed


    Buffon_testes
    {
        graph input_graph = read_graph();
        vvi ans = solve(input_graph);
        print_ans(ans);
    }


    return 0;
}
