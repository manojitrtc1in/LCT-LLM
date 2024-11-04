


















 
using namespace std;
using namespace __gnu_pbds;














long long mx = id0, mn = id3;

struct id2
{
    vector<long long> fact;
    vector<bool> is_prime;
    id2(int n = 200001, long long q = R)
    {
        fact.resize(n);
        is_prime.assign(n + 1, true);

        fact[0] = 1;
        for(int i = 1; i < n; i++)
            fact[i] = (fact[i-1] * i) % q;

        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= n; i++)
            if(is_prime[i])
                for(int j = i + i; j <= n; j += i)
                    is_prime[j] = false;
    }
    long long power_mod_q(long long x, long long n, long long q = R)
    {
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return power_mod_q((x * x) % q, n / 2, q);
        else 
            return (x * power_mod_q((x * x) % q, n / 2, q)) % q; 
    }

    long long inverse_mod_q(long long n, long long q = R)
    {
        return power_mod_q(n, q-2, q);
    }

    long long nCr_mod_q(long long n, long long r, long long q = R)
    {
        return (((fact[n] * inverse_mod_q(fact[r], q)) % q) * inverse_mod_q(fact[n-r], q)) % q;
    }

    long long power(long long x, long long n)
    {
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return power(x * x, n / 2);
        else 
            return x * power(x * x, n / 2); 
    }

    grid multiply(grid& a, grid& b)
    {
        int p = a.size(), q = b.size(), r = b[0].size();
        grid c(p, vector<long long>(r, 0));
        for(int i = 0; i < p; i++)
            for(int j = 0; j < r; j++)
                for(int k = 0; k < q; k++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    grid add(grid& a, grid& b)
    {
        int p = a.size(), q = a[0].size();
        grid c(p, vector<long long>(q));
        for(int i = 0; i < p; i++)
            for(int j = 0; j < q; j++)
                c[i][j] = a[i][j] + b[i][j];
        return c;
    }

    grid power(grid& a, long long n)
    {
        grid c(a.size(), vector<long long>(a.size(), 0));
        if(n == 0)
        {
            for(int i = 0; i < a.size(); i++)
                c[i][i] = 1;
            return c;
        }
        if(n % 2 == 0)
            return power(c = multiply(a, a), n / 2);
        else
            return multiply(a, c = power(c = multiply(a, a), n / 2));
        
    }
}u(1000001);

struct dsu
{
    vector<int> rank, parent, num;
    dsu(int n)
    {
        rank.assign(n, 0);
        parent.resize(n);
        num.assign(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_set(int i)
    {
        if(i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }
    bool is_same_set(int i, int j)
    {
        if(find_set(i) == find_set(j))
            return true;
        return false;
    }
    void union_set(int i, int j)
    {
        if(!is_same_set(i, j))
        {
            int u = find_set(i), v = find_set(j);
            if(rank[u] == rank[v])
            {
                parent[v] = u;
                rank[u] += 1;
                num[u] += num[v];
            }
            else if(rank[u] > rank[v])
                parent[v] = u, num[u] += num[v];
            else 
                parent[u] = v, num[v] += num[u];
        }
    }

};

struct segment_tree
{
    struct node
    {
        long long sum;
    };

    node merge(node a, node b)
    {
        return {a.sum + b.sum};
    }
    
    vector<long long> a;
    vector<node> tree;
    int n;
    
    segment_tree(vector<long long> a, int buffer = 0)
    {
        n = a.size();
        while((n & (n-1)) != 0)
        {
            a.push_back(buffer);
            n = a.size();
        }
        this -> a = a;
        tree.resize(2 * n - 1);
        build(0, 0,  n - 1);
    }

    void build(int i, int l, int r)
    {
        if(l == r)
        {
            tree[i].sum = a[l];
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * i + 1, l, mid);
            build(2 * i + 2, mid + 1, r);
            tree[i] = merge(tree[2*i + 1], tree[2 * i + 2]);
        }
    }

    node query(int i, int s, int e, int l, int r)
    {
        if(l == s && r == e)
            return tree[i];

        int mid = (l + r) /2 ;
        if(e <= mid)
            return query(2 * i + 1, s, e, l, mid);
        else if(s > mid)
            return query(2 * i + 2, s, e, mid + 1, r);
        return merge(query(2 * i + 1, s, mid, l, mid), query(2 * i + 2, mid + 1, e, mid + 1, r));
    }

    void update(int i, int idx, int val, int l, int r)
    {
        if(l == r)
        {
            a[idx] = val;
            tree[i].sum = val;
        }
        else
        {
            int mid = (l + r) / 2;
            if(idx <= mid)
                update(2 * i + 1, idx, val, l, mid);
            else
                update(2 * i + 2, idx, val, mid + 1, r);

            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }
    

};

struct graph
{
    int v, time, count;
    vector<pair<int, int>>* adj;
    grid matrix;
    vector<bool> visited, in_stack, ap, in_MST;
    stack<int> s;
    vector<int> color, cc, f, d, finish_time, l, indegree, id1, topo, outdegree, pred, child, euler;
    vector<long long> dist;
    graph(int n)
    {
        v = n;
        adj = new vector<pair<int, int>>[n];
        

        

        

    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        

        

    }

    void dfs()
    {
        color.assign(v, 0);
        cc.assign(v, -1);
        d.assign(v, -1);
        f.assign(v, -1);
        time = count = 0;
        finish_time.assign(2 * v, -1);
        visited.assign(v, false);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
        {
            if(color[i] == 0)
            {
                dfs(i);
                count++;
            }
        }
        for(int i = 0; i < v; i++)
            finish_time[f[i]] = i;
    }

    void dfs(int i)
    {
        color[i] = 1;
        euler.push_back(i);
        cc[i] = count;
        d[i] = time;
        time++;
        for(auto x : adj[i])
        {
            if(!color[x.first])
            {
                pred[x.first] = i;
                dfs(x.first);
            }
        }
        color[i] = 2;
        f[i] = time;
        time++;
    }

    void bfs(int u)
    {
        color.assign(v, 0);
        pred.assign(v, -1);
        d.assign(v, 0);
        queue<int> q;
        color[u] = 1;
        q.push(u);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(auto x : adj[i])
            {
                if(!color[x.first])
                {
                    pred[x.first] = i;
                    color[x.first] = 1;
                    d[x.first] = d[i] + 1;
                    q.push(x.first);
                }
            }
            color[i] = 2;
        }
    }

    void scc()
    {
        graph g_t(v);
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                g_t.add_edge(x.first, i, x.second);
        dfs();
        g_t.color.assign(v, 0);
        g_t.cc.assign(v, -1);
        g_t.d.assign(v, -1);
        g_t.f.assign(v, -1);
        g_t.time = g_t.count = 0;
        g_t.finish_time.assign(2 * v, -1);
        g_t.visited.assign(v, false);
        g_t.pred.assign(v, -1);
        for(int i = 2 * v - 1; i >= 0; i--)
        {
            if(finish_time[i] != -1 && g_t.color[finish_time[i]] == 0)
            {
                g_t.dfs(finish_time[i]);
                g_t.count++;
            }
        }
        id1 = g_t.cc;
        count = g_t.count;
    }

    void topological_sort()
    {
        indegree.assign(v, 0);
        outdegree.assign(v, 0);
        for(int i = 0; i < v; i++)
            if(adj[i].size())
                outdegree[i] = adj[i].size();
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                indegree[x.first]++;
        vector<int> zero;
        for(int i = 0; i < v; i++)
            if(!indegree[i])
                zero.push_back(i);
        
        while(!zero.empty())
        {
            int v = zero.back();
            topo.push_back(v);
            zero.pop_back();
            for(auto x : adj[v])
            {
                indegree[x.first]--;
                if(!indegree[x.first])
                    zero.push_back(x.first);
            }
        }
    }

    void tarjan()
    {
        for(int i = 0; i < v; i++)
            if(!color[i])
                tarjan(i);
    }

    void tarjan(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        s.push(i);
        in_stack[i] = true;
        for(auto x : adj[i])
        {
            if(!color[x.first])
            {
                tarjan(x.first);
                l[i] = min(l[i], l[x.first]);
            }
            else if(in_stack[x.first])
            {
                l[i] = min(l[i], d[x.first]);
            }
        }
        
        color[i] = 2;
        f[i] = time;
        time++;
        if(d[i] == l[i])
        {
            while(s.top() != i)
                cout << s.top() << ' ', in_stack[s.top()] = false, s.pop();
            cout << s.top() << '\n', in_stack[s.top()] = false, s.pop();
        }
    }

    graph kruskal()
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                edges.push_back(make_pair(x.second, make_pair(i, x.first)));
        sort(edges.begin(), edges.end());
        dsu d(v);
        graph mst(v);
        for(auto x : edges)
        {
            if(!d.is_same_set(x.second.first, x.second.second))
            {
                mst.add_edge(x.second.first, x.second.second, x.first);
                d.union_set(x.second.first, x.second.second);
            }

        }
        return mst;
    }

    graph prims(int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        d.assign(v, id3);
        pred.assign(v, -1);
        in_MST.assign(v, false);
        count = 0;
        d[s] = 0;
        pq.push({0, s});
        while(count < v)
        {
            int u = pq.top().second;
            if(!in_MST[u])
                in_MST[u] = true, count++;
            pq.pop();
            for(auto x : adj[u])
            {
                if(!in_MST[x.first] && d[x.first] > x.second)
                {
                    pq.push({x.second, x.first});
                    pred[x.first] = u;
                    d[x.first] = x.second;
                }
            }
        }
        graph mst(v);
        for(int i = 0; i < v; i++)
        {
            if(pred[i] != -1)
                mst.add_edge(i, pred[i], d[i]);
        }
        return mst;
    }

    void dijkstra(int s)
    {
        d.assign(v, id3);
        visited.assign(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({d[s] = 0, s});
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if(!visited[u])
            {
                visited[u] = true;
                for(auto x : adj[u])
                {
                    if(d[x.first] > d[u] + x.second)
                    {
                        d[x.first] = d[u] + x.second;
                        pq.push({d[x.first], x.first});
                    }
                }
            }
        }
    } 
};

struct kmp
{
    vector<int> lps;
    string p, t;
    kmp(string& p, string& t)
    {
        this -> p = p;
        this -> t = t;
        

        lps.assign(p.size(), 0);
        lps[0] = 0;
        int len = 0, i = 1, j;
        while(i < p.size())
        {
            if(p[i] == p[len])
                lps[i++] = ++len;
            else if(len)
                len = lps[len-1];
            else 
                lps[i++] = 0;
        }
        

        i = j = 0;
        while(i < t.size())
        {
            if(p[j] == t[i])
                j++, i++;
            
            if(j == p.size())
            {
                

                j = lps[j-1];
            }
            else if(i < t.size() && p[j] != t[i])
            {
                if(j)
                    j = lps[j-1];
                else 
                    i++;
            }
        }

        
    }
};

struct Trie
{
    struct node
    {
        char c;
        bool is_leaf;
        vector<node *> child;
        node(char ch)
        {
            c = ch;
            is_leaf = false;
            child.assign(L, nullptr);
        }
    };
    node * root;
    Trie()
    {
        root = new node('
    }

    void insert(string& s)
    {
        node * temp = root;
        for(auto x : s)
        {
            if(!(temp -> child)[x])
                (temp -> child)[x] = new node(x);
            temp = (temp -> child)[x];
        }
        temp -> is_leaf = true;
    }

    bool has_child(node * temp)
    {
        for(auto x : temp -> child)
            if(x)
                return true;
        return false;
    }

    bool search(string& s)
    {
        node * temp = root;
        bool flag = true;
        for(auto x : s)
        {
            if(!(temp -> child)[x])
            {
                flag = false;
                break;
            }
            temp = (temp -> child)[x];
        }
        if(flag && temp -> is_leaf)
            return true;
        else
            return false;
    }

    void remove(string& s)
    {
        if(search(s))
            root = remove(root, 0, s);
    }
    node * remove(node * root, int pos, string& s)
    {
        if(pos <= s.length() - 1)
        {
            (root -> child)[s[pos]] = remove((root -> child)[s[pos]], pos + 1, s);
            bool flag = true;
            for(int i = 0; i < L; i++)
                if((root -> child)[i])
                    flag = false;
            if(root -> c != '
            {
                delete(root);
                root = nullptr;
            }
        }
        else
        {
            root -> is_leaf = false;

            bool flag = true;
            for(int i = 0; i < L; i++)
                if((root -> child)[i])
                    flag = false;
            if(flag)
            {
                delete(root);
                root = nullptr;
            }
        }
        return root;
    }
};

struct lazy_seg
{
    struct node
    {
        long long sum;
    };
    vector<long long> a, pending;
    int n;
    vector<node> tree;
    node merge(node a, node b)
    {
        return {a.sum + b.sum};
    }

    lazy_seg(vector<long long> a, int buffer)
    {
        n = a.size();
        while(n & (n - 1))
        {
            a.push_back(buffer);
            n = a.size();
        }
        this -> a = a;
        tree.resize(2 * n - 1);
        pending.assign(2 * n - 1, 0);
        build(0, 0, n - 1);
    }

    void build(int i, int l, int r)
    {
        if(l == r)
        {
            tree[i] = {a[l]};
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * i + 1, l, mid);
            build(2 * i + 2, mid + 1, r);
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    node query(int i, int s, int e, int l, int r)
    {
        apply_pending(i, l, r);
        if(s == l && e == r)
            return tree[i];
        else
        {
            int mid = (l + r) / 2;
            if(e <= mid)
                return query(2 * i + 1, s, e, l, mid);
            else if(s > mid)
                return query(2 * i + 2, s, e, mid + 1, r);
            else
                return merge(query(2 * i + 1, s, mid, l, mid), query(2 * i + 2, mid + 1, e, mid + 1, r));
        }

    }

    void update(int i, int idx, long long val, int l, int r)
    {
        if(l == r)
        {
            a[idx] = val;
            tree[i] = {val};
        }
        else
        {
            int mid = (l + r) / 2;
            if(idx <= mid)
                update(2 * i + 1, idx, val, l, mid);
            else
                update(2 * i + 2, idx, val, mid + 1, r);
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void apply_pending(int i, int s, int e)
    {
        if(pending[i])
        {
            tree[i].sum = tree[i].sum + (e - s + 1) * pending[i];
            if(s != e)
            {
                pending[2 * i + 1] += pending[i];
                pending[2 * i + 2] += pending[i];
            }
            pending[i] = false;
        }
    }

    void update_range(int i, int s, int e, long long val, int l, int r)
    {
        apply_pending(i, l, r);
        if(s == l && r == e)
        {
            tree[i].sum = tree[i].sum + (e - s + 1) * val;
            if(s != e)
            {
                pending[2 * i + 1] += val;
                pending[2 * i + 2] += val;
            }
        }
        else
        {
            int mid = (l + r) / 2;
            if(e <= mid)
                update_range(2 * i + 1, s, e, val, l, mid);
            else if(s > mid)
                update_range(2 * i + 2, s, e, val, mid + 1, r);
            else
            {
                update_range(2 * i + 1, s, mid, val, l, mid);
                update_range(2 * i + 2, mid + 1, e, val, mid + 1, r);
            }
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
        }

        
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n - 1));
    vector<int> b(n);
    for(int i = 0; i < n - 1; i++)
        cin >> a[0][i];
    for(int i = 0; i < n - 1; i++)
        cin >> a[1][i];
    for(int& x : b)
        cin >> x;
    vector<int> routes;
    for(int i = n- 1; i >= 0; i--)
    {
        int cnt = 0;
        for(int j = n - 2; j >= i; j--)
            cnt += a[1][j];
        cnt += b[i];
        for(int j = i - 1; j >= 0; j--)
            cnt += a[0][j];
        routes.push_back(cnt);
    }
    sort(routes.begin(), routes.end());
    cout << routes[0] + routes[1] << '\n';
    return 0;
}

