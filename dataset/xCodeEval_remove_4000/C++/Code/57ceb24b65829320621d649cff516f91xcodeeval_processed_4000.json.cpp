

















using namespace std;










const int MAX = 3e5 + 20;
const int INFINITE = INT_MAX;
const int MAXNUM = MAX;

template<typename T>
struct SegTree {

    struct SegTreeNode
    {
        int l ,r;
        T val;
        T addMark;
    };

    vector<SegTreeNode> nodes; 
    T *arr;
    int istart,iend,maxIndex; 
	
    SegTree() {}
    SegTree(T *arr1,int start,int end):arr(arr1), istart(start), iend(end) {
        nodes.resize((end - start + 1) << 2); 
         maxIndex=-1; build(0,arr,istart,iend);
    }
    
    void build(int root, T arr[], int istart, int iend)
    {
        nodes[root].addMark = 0;
        if(istart == iend) {
            if(root>maxIndex) maxIndex=root;
            nodes[root].l = istart, nodes[root].r = iend;
            nodes[root].val = arr[istart];
        } else {
            int mid = (istart + iend) / 2;
            build(root*2+1, arr, istart, mid);
            build(root*2+2, arr, mid+1, iend);
            nodes[root].l = istart, nodes[root].r = iend; 
            nodes[root].val = max(nodes[root*2+1].val, nodes[root*2+2].val);
        }
    }
    
    void pushDown(int root)
    {
        if(nodes[root].addMark != 0)
        {
            int len = nodes[root].r - nodes[root].l + 1;
            nodes[root].val = len - nodes[root].val;
            
            if((root<<1)+1<=maxIndex)
                nodes[(root<<1)+1].addMark ^= 1;
            if((root<<1)+2<=maxIndex)
                nodes[(root<<1)+2].addMark ^= 1;
            
            nodes[root].addMark = 0;
        }
    }
    
    T query(int qstart,int qend) {
        return query(0,istart,iend,qstart,qend);
    }
    
    T query(int root, int nstart, int nend, int qstart, int qend)
    {
        
        if(qstart > nend || qend < nstart) {
			pushDown(root);
            return 0;
		}
        
        if(qstart <= nstart && qend >= nend) {
            pushDown(root);
            return nodes[root].val;
        }
        
        pushDown(root); 
        int mid = (nstart + nend) / 2;
        return query(root*2+1, nstart, mid, qstart, qend) + 
                   query(root*2+2, mid + 1, nend, qstart, qend);

    }
    
    void update(int ustart,int uend) {
        update(0,istart,iend,ustart,uend);
    }
    
    void update(int root, int nstart, int nend, int ustart, int uend)
    {
        
        if(ustart > nend || uend < nstart)
            return ;
        
        if(ustart <= nstart && uend >= nend)
        {
            nodes[root].addMark ^= 1;
            pushDown(root);
            return ;
        }
        pushDown(root); 
        
        int mid = (nstart + nend) / 2;
        update(root*2+1, nstart, mid, ustart, uend);
        update(root*2+2, mid+1, nend, ustart, uend);
        
        nodes[root].val = nodes[root*2+1].val + nodes[root*2+2].val;
    }
    
    void updateOne(int index, T addVal) {
        updateOne(0,istart,iend,index,addVal);
    }
    
    void updateOne(int root, int nstart, int nend, int index)
    {
        if(nstart == nend)
        {
            if(index == nstart) {
                pushDown(root);
                nodes[root].val ^= 1;
            }
            return;
        }
        int mid = (nstart + nend) / 2;
        pushDown(root);
        if(index <= mid)
            updateOne(root*2+1, nstart, mid, index);
        else updateOne(root*2+2, mid+1, nend, index);
        
        nodes[root].val = nodes[root*2+1].val + nodes[root*2+2].val;
    }
};

const int V = MAX;  
struct node {
    int v; int idx; bool flag; 
    int tmpv;
    node(int a = 0, int b = 0, bool c = 0) : v(a), idx(b), flag(c) {}
};
vector<node> adj[V];  
int parent[V], heavy[V];  
int depth[V], size[V];
int chain[V], head[V] ,pos[V];
int vist[V];
vector<int> realChain[V]; 

SegTree<int> trees[V];
int ids[V];

vector<pair<int, int> > id2; 
int n, m;

void DFS(int i)
{
    size[i] = 1, vist[i] = 1;
    for (int k=0; k<adj[i].size(); ++k)
    {
        auto &ele = adj[i][k];
        int j = ele.v;
        if (j == parent[i]) { ele.flag = 1; continue; }
        if (vist[j] == 1) { ele.flag = 0; continue; }

        ele.flag = 1;
        parent[j] = i;
        if (i == n + 1)
            ids[j] = ele.tmpv;
        depth[j] = depth[i] + 1;

        DFS(j);

        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]])
            heavy[i] = j;
    }
}

int syy[MAX];
void id0(int N)
{
    memset(heavy, -1, sizeof(heavy));
    mem(parent);
    memset(vist, 0, sizeof(vist));
    parent[N] = -1;
    depth[N] = 0;
    DFS(N);

    int c = 0;
    for (int i=1; i<=N; ++i)
        if (syy[i] == -1 && (parent[i] == -1 || heavy[parent[i]] != i))
        {
            for (int k = i,p=0; k != -1; k = heavy[k]) {
                chain[k] = c, head[k] = i ,pos[k] = p++;
                realChain[c].push_back(0); 
            }
            c++;
        }
    for (int i = 0; i < c; i++) {
        trees[i] = SegTree<int> (realChain[i].data(), 0, (int)realChain[i].size() - 1);
    }
}

vector<node> adj1[MAX];
stack<int> S;
int pa[MAX];
bool findC = 0;
void dfsC(int v) {
    vist[v] = 1;
    for (int i = 0; i < adj1[v].size(); i++) {
        auto &ele = adj1[v][i];
        int u = ele.v;
        if (!vist[u]) {
            pa[u] = v;
            dfsC(u);
        } else if (u != pa[v]) {
            if (!findC) {
                findC = 1;
                int tmp = v;
                while (tmp != u) {
                    S.push(tmp);
                    tmp = pa[tmp];
                }
                S.push(u);
            }
        }
    } 
}
vector<int> CC;
pair<int, int> bb[MAX];
vector<int> cVal;
SegTree<int> cTree;

int id1(int i, int j) 
{
    while (chain[i] != chain[j])
        if (depth[head[i]] > depth[head[j]])
            i = parent[head[i]];
        else
            j = parent[head[j]];

    return depth[i] < depth[j] ? i : j;
}
int findIn(int i) {
    if (syy[i] != -1) return i;
    else {
        int cj = -1;
        int si = i;
        

        while (head[si] != n + 1) {
            

            si = head[si];
            if (parent[si] == n + 1) cj = ids[si];
            si = parent[si];
        }
        if (cj != -1) return cj;
        else return ids[heavy[n + 1]];
    }
}

int query1(int i, int j) {
    int syi = syy[i] != -1? n + 1 : i;
    int syj = syy[j] != -1? n + 1 : j;
    int la = id1(syi, syj);
    int ans = 0;
    int cid, pp, pp2;
    while (chain[syi] != chain[syj])
    {
        if (depth[head[syi]] > depth[head[syj]])
            swap(syi, syj);
        cid = chain[syj], pp = pos[syj];  
        ans += trees[cid].query(0, pp); 
        syj = parent[head[syj]];
    }
        
    cid = chain[syi], pp = pos[syi], pp2 = pos[syj];
    if (pp > pp2) swap(pp, pp2); 
    
    if (pp != pp2) {
        pp++;
        ans += trees[cid].query(pp, pp2);
    }
    if (la != n + 1) return ans;
    int ie = findIn(i), je = findIn(j); 
    int pi = syy[ie], pj = syy[je];
    

    if (pi == pj) return ans;
    int dist = abs(pj - pi), t1 = CC.size() - dist;
    if (dist == t1) {
        int prev = pi == 0? CC.size() - 1 : pi - 1;
        int nxt = pi == CC.size() - 1?  0 : pi + 1;
        if ((pj < pi && CC[prev] < CC[nxt]) || (pj > pi && CC[nxt] < CC[prev])) {
            if (pi > pj) swap(pi, pj);
            return ans + cTree.query(pi + 1, pj);
        } else {
            if (pi > pj) swap(pi, pj);
            return ans + cTree.query(0, pi) + (pj == CC.size() - 1? 0 : cTree.query(pj + 1, CC.size() - 1));
        }
    } else {
        if (dist < t1) {
            if (pi > pj) swap(pi, pj);
            return ans + cTree.query(pi + 1, pj);
        } else {
            if (pi > pj) swap(pi, pj);
            return ans + cTree.query(0, pi) + (pj == CC.size() - 1? 0 : cTree.query(pj + 1, CC.size() - 1));
        }
    }
}
void update1(int i, int j) {
    int syi = syy[i] != -1? n + 1 : i;
    int syj = syy[j] != -1? n + 1 : j;
    

    int la = id1(syi, syj);
    

    int cid, pp, pp2;
    while (chain[syi] != chain[syj])
    {
        if (depth[head[syi]] > depth[head[syj]])
            swap(syi, syj);
        cid = chain[syj], pp = pos[syj];  
        

        trees[cid].update(0, pp); 
        syj = parent[head[syj]];
    }
        
    cid = chain[syi], pp = pos[syi], pp2 = pos[syj];
    if (pp > pp2) swap(pp, pp2); 
    

    if (pp != pp2) {
        pp++;
        trees[cid].update(pp, pp2);
    }
    if (la != n + 1) return;
    

    int ie = findIn(i), je = findIn(j); 
    

    int pi = syy[ie], pj = syy[je];
    

    if (pi == pj) return;
    int prev = pi == 0? CC.size() - 1 : pi - 1;
    int nxt = pi == CC.size() - 1?  0 : pi + 1;
    int dist = abs(pj - pi), t1 = CC.size() - dist;
    if (dist == t1) {
        if ((pj < pi && CC[prev] < CC[nxt]) || (pj > pi && CC[nxt] < CC[prev])) {
            if (pi > pj) swap(pi, pj);
            cTree.update(pi + 1, pj);
        } else {
            if (pi > pj) swap(pi, pj);
            cTree.update(0, pi);
            if (pj == CC.size() - 1) return;
            else cTree.update(pj + 1, CC.size() - 1);
        }
    } else {
        if (dist < t1) {
            if (pi > pj) swap(pi, pj);
            cTree.update(pi + 1, pj);
        } else {
            if (pi > pj) swap(pi, pj);
            cTree.update(0, pi);
            if (pj == CC.size() - 1) return;
            else cTree.update(pj + 1, CC.size() - 1);
        }
    }
}

int curone;

void sol(int i, int j) {
    int q1 = query1(i, j);
    update1(i, j);
    int q2 = query1(i, j);
    curone = curone - q1 + q2;
    int cnum = cTree.query(0, CC.size() - 1);
    if (cnum == CC.size()) Pn(n - curone + 1);
    else Pn(n - curone);
}
int main() {
    Mem(syy);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        bb[i] = {a, b};
        adj1[a].push_back({b, i});
        adj1[b].push_back({a, i});
    }
    findC = 0, mem(vist), pa[1] = -1;
    dfsC(1);
    while (!S.empty()) {
        CC.push_back(S.top()), S.pop();
    }
    Mem(syy);
    for (int i = 0; i < CC.size(); i++) syy[CC[i]] = i;
    int ad = n + 1;
    for (int i = 1; i <= n; i++) {
        int a = bb[i].first, b = bb[i].second;
        if (syy[a] != -1 && syy[b] != -1) continue;
        int xa, xb;
        if (syy[a] != -1) xa = ad;
        else xa = a;
        if (syy[b] != -1) xb = ad;
        else xb = b;
        adj[xa].push_back({xb, i});
        if (xa == ad)
            adj[xa][adj[xa].size() - 1].tmpv = a;
        adj[xb].push_back({xa, i});
        if (xb == ad)
            adj[xb][adj[xb].size() - 1].tmpv = b;
    }
    

    

    cVal.resize(CC.size(), 0);
    cTree = SegTree<int> (cVal.data(), 0, (int)cVal.size() - 1);    
    id0(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        sol(a, b);
    } 
    return 0;
}
