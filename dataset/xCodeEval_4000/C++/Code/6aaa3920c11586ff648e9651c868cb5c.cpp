#include <bits/stdc++.h>

const int INF = 1e9;
const int MAXN = 300010;
const int MAXM = 300010;



class Graph {
 
public:
  Graph() {
    e_.clear();
    e_.push_back(Edge(0, 0)); 

    m_ = 0; 
  }
 
  Graph(int n) : n_(n) {
    hd_.assign(n + 1, 0);
    e_.clear();
    e_.push_back(Edge(0, 0)); 

    m_ = 0;
  }
 
  void Init(int n) {
    n_ = n;
    hd_.assign(n + 1, 0);
  }
 
  void Add(int u, int v) {
    Edge edge(v, hd_[u]);
    e_.push_back(edge);
    hd_[u] = ++m_;
  }
 
  int Head(int id_v) {
    return hd_[id_v];
  }
 
  int Next(int id_e) {
    return e_[id_e].nxt;
  }
 
  int To(int id_e) {
    return e_[id_e].v;
  }
 
  int NumNode() {
    return n_;
  }
 
private:
  struct Edge{ 
    int v, nxt; 
    Edge(int _v, int _nxt) : v(_v), nxt(_nxt) {}
  };
 
  int n_;               

  std::vector<int> hd_;
 
  int m_;               

  std::vector<Edge> e_; 

 
}; 

typedef std::shared_ptr<Graph> GraphPtr;



class SegmentTree {

public:
  SegmentTree() {}

  void Init(int n) {
    memset(mx_, -1, sizeof(mx_));
  }

  void Change(int l, int r, int rt, int id, int x) {
    if (l == r) {
      mx_[rt] = x;
      return;
    }
    int m = (l + r) >> 1;
    if (id <= m) {
      Change(l, m, rt << 1, id, x);
    } else {
      Change(m + 1, r, rt << 1 | 1, id, x);
    }
    mx_[rt] = std::max(mx_[rt << 1], mx_[rt << 1 | 1]);
  }

  int MaxInterval(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
      return mx_[rt];
    }
    int m = (l + r) >> 1;
    int ans = -INF;
    if (L <= m) {
      ans = std::max(ans, MaxInterval(l, m, rt << 1, L, R));
    }
    if (R > m) {
      ans = std::max(ans, MaxInterval(m + 1, r, rt << 1 | 1, L, R));
    }
    return ans;
  }

private:
  int mx_[MAXN<<2|1];

}; 




class HLCTree {

public:
  HLCTree() {}

  void Init(GraphPtr& tree) {
    tree_ = tree;
    n_ = tree_->NumNode();
    memset(size_, 0, sizeof(size_));
    memset(dep_, 0, sizeof(dep_));
    memset(fa_, 0, sizeof(fa_));
    Dfs1(1);

    sz_ = 0;
    Dfs2(1, 1);
    

    seg_.Init(n_ + 1);
  }

  

  void Change(int u, int x) {
    seg_.Change(1, n_, 1, pos_[u], x);
  }

  

  int MaxInterval(int x, int y) {
    int mx = -INF;
    while (bl_[x] != bl_[y]) {
      if (dep_[bl_[x]] < dep_[bl_[y]]) {
        std::swap(x, y);
      }
      mx = std::max(mx, seg_.MaxInterval(1, n_, 1, pos_[bl_[x]], pos_[x]));
      x = fa_[bl_[x]];
    }
    if (pos_[x] > pos_[y]) {
      std::swap(x, y);
    }
    mx = std::max(mx, seg_.MaxInterval(1, n_, 1, pos_[x], pos_[y]));
    return mx;
  }

private:
  

  void Dfs1(int x) {
    size_[x] = 1;
    for(int i = tree_->Head(x); i; i = tree_->Next(i)) {
      int v = tree_->To(i);
      if (v == fa_[x]) {
        continue;
      }
      dep_[v] = dep_[x] + 1;
      fa_[v] = x;
      Dfs1(v);
      size_[x] += size_[v];
    }
  }
  
  

  void Dfs2(int x, int chain) {
    pos_[x] = ++sz_;
    bl_[x] = chain;
    

    int k = 0;
    for (int i = tree_->Head(x); i; i = tree_->Next(i)) {
      int v = tree_->To(i);
      if (dep_[v] > dep_[x] && size_[v] > size_[k]) {
        k = v;
      }
    }
    if (!k) {
      out_[x] = sz_;
      return;
    }
    

    Dfs2(k, chain); 
    

    for (int i = tree_->Head(x); i; i = tree_->Next(i)) {
      int v = tree_->To(i);
      if (dep_[v] > dep_[x] && k != v) {
        Dfs2(v, v);
      }
    }
    out_[x] = sz_;
  }

  int n_;                 

  GraphPtr tree_;         


  int size_[MAXN];        

  int dep_[MAXN];         

  int fa_[MAXN];          


  int sz_;                

  int pos_[MAXN];         

  int bl_[MAXN];          

  int out_[MAXN];         


  SegmentTree seg_;

}; 

typedef std::shared_ptr<HLCTree> HLCTreePtr;

class Discretization {

public:
  Discretization() {
    vec_.clear();
  }

  void Add(int x) {
    vec_.push_back(x);
  }

  void Build() {
    std::sort(vec_.begin(), vec_.end());
    vec_.erase(std::unique(vec_.begin(), vec_.end()), vec_.end());
  }

  int Id(int x) {
    auto y = std::lower_bound(vec_.begin(), vec_.end(), x);
    if (*y != x) {
      return -1;
    } else {
      return y - vec_.begin();
    }
  }

  int Size() {
    return vec_.size();
  }

private:
  std::vector<int> vec_;
};

class ACAutomation {

public:
  

  ACAutomation() {
    memset(ch_, 0, sizeof(ch_));
    memset(fail_, -1, sizeof(fail_));
    memset(fail_ch_, 0, sizeof(fail_ch_));
    memset(val_, -1, sizeof(val_));
    memset(pos_, -1, sizeof(pos_));
    memset(weight_, 0, sizeof(weight_));
    fail_tree_ = std::make_shared<Graph>();
    hlc_ = std::make_shared<HLCTree>();
  }

  ~ACAutomation() {

  }

  void Init(int sz, int n) {
    sz_ = sz;
    n_ = n;
    cnt_ = 0;
    CreateNewNode();  

  }

  

  void Add(int i, std::string& s) {
    int cur = 0; 

    for (auto& x : s) {
      int id = idx(x);
      if (!ch_[cur][id]) {
        ch_[cur][id] = CreateNewNode();
        fail_ch_[cur][id] = ch_[cur][id]; 

      }
      cur = ch_[cur][id];
    }
    

    pos_[i] = cur;
    val_[cur] = 0; 

    disc_.Add(cur);
  }

  

  void Build() {
    std::queue<int> q;
    while (!q.empty()) {
      q.pop();
    }
    q.push(0);
    while (!q.empty()) {
      int cur = q.front();
      if (cur) {
        assert(fail_[cur] != -1);
      }
      q.pop();
      for (int i = 0; i < sz_; ++i) {
        int tmp = fail_[cur]; 

        if (ch_[cur][i]) {
          int nxt = ch_[cur][i];

          

          

          

          

          

          

          

          

          

          


          

          if (tmp != -1) {
            fail_[nxt] = fail_ch_[tmp][i];
          } else {
            fail_[nxt] = 0;
          }
          q.push(nxt);
        } else {
          if (tmp != -1) {
            fail_ch_[cur][i] = fail_ch_[tmp][i];
          }
        }
      }
    }

    

    fail_tree_->Init(cnt_);
    

    for (int i = 1; i < cnt_; ++i) {
      assert(fail_[i] >= 0);
      fail_tree_->Add(fail_[i] + 1, i + 1);
    }
    

    hlc_->Init(fail_tree_);
    for (int i = 1; i <= n_; ++i) {
      hlc_->Change(pos_[i] + 1, 0);
    }

    disc_.Build();
    

    for(int i = 0; i < disc_.Size(); ++i) {
      sets_[i].clear();
    }

    for (int i = 1; i <= n_; ++i) {
      int j = disc_.Id(pos_[i]);
      assert(j >= 0 && j < disc_.Size());
      sets_[j].insert(weight_[i]);
    }

  }

  

  int Query(std::string& s) {
    int cur = 0;
    int ans = -1;
    for (auto & x : s) {
      int id = idx(x);

      

      

      

      

      

      

      

      

      

      


      

      cur = fail_ch_[cur][id];

      assert(cur >= 0 && cur < cnt_);
      ans = std::max(ans, hlc_->MaxInterval(1, cur + 1));

      

      

      

      

      

    }
    return ans;
  }

  void Update(int i, int x) {
    int cur = pos_[i];
    assert(cur != -1);
    int j = disc_.Id(pos_[i]); 

    auto iter = sets_[j].find(weight_[i]);
    assert(iter != sets_[j].end());
    sets_[j].erase(iter);
    sets_[j].insert(x);
    weight_[i] = x;
    val_[cur] = *sets_[j].rbegin();
    hlc_->Change(pos_[i] + 1, val_[cur]);
  }

private:

  int idx(char c) {
    return c - 'a';
  }

  

  int CreateNewNode() {
    

    

    

    

    

    

    

    

    

    

    

    

    

    ++cnt_;
    return cnt_ - 1;
  }

  int sz_; 


  

  int ch_[MAXN][26];  

  int fail_[MAXN];      

  

  

  

  int fail_ch_[MAXN][26];
  int cnt_;             


  

  int val_[MAXN];       

                        


  

  int pos_[MAXN];       

  int weight_[MAXN];    

  int n_;               


  Discretization disc_;
  std::multiset<int> sets_[MAXN]; 

  
  GraphPtr fail_tree_;
  HLCTreePtr hlc_;
}; 


int n, m;
std::string s;
ACAutomation ac;

int main() {
  std::cin >> n >> m;
  ac.Init(26, n);
  for(int i = 1; i <= n; ++i) {
    std::cin >> s;
    ac.Add(i, s);
  }

  ac.Build();

  for (int i = 1; i <= m; ++i) {
    int q_id;
    std::cin >> q_id;
    if (q_id == 1) {
      int j, x;
      std::cin >> j >> x;
      ac.Update(j, x);
    } else {
      std::cin >> s;
      std::cout << ac.Query(s) << std::endl;
    }
  }
  return 0;
}