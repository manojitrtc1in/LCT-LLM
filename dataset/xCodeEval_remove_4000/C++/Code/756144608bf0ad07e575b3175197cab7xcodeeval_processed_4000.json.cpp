

    

    
    
    

    
    


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    using namespace std;

    
    
    
    
    using namespace tr1;
    
    
    
    
    

    
    
    
    using namespace __gnu_pbds;
    

    typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;
    

    typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;
    

    
    typedef unsigned int ui;
    typedef unsigned long long ull;
    typedef long long ll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll> pll;
    typedef pair <double, double> pdd;
    typedef vector <int> vi;
    typedef vector <ll> vll;
    typedef vector <double> vd;
    typedef vector <string> vs;
    typedef map <string, int> mpsi;
    typedef map <double, int> mpdi;
    typedef map <int, int> mpii;

    const double pi = acos(0.0) * 2.0;
    const long double eps = 1e-10;
    const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

    template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

    
    template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
    template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
    template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
    template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
    template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
    template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
    template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
    template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }
    
    template <typename t, typename t1>
    t min1(t a, t1 b) { return a < b ? a : b; }
    template <typename t, typename... arg>
    t min1(t a, arg... arr) { return min1(a, min1(arr...)); }
    template <typename t, typename t1>
    t max1(t a, t1 b) { return a > b ? a : b; }
    template <typename t, typename... arg>
    t max1(t a, arg... arr) { return max1(a, max1(arr...)); }
    

    inline int jud(double a, double b){
      if(abs(a) < eps && abs(b) < eps) return 0;
      else if(abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
      if(a < b) return -1;
      return 1;
    }
    template <typename t> inline int jud(t a, t b){
      if(a < b) return -1;
      if(a == b) return 0;
      return 1;
    }

    

    template <typename it, typename t1>
    inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
      if(na == 0) return 0;
      int be = 0, en = na - 1;
      if(*a <= *(a + na - 1)){
        if(f_lb == 0) while(be < en){
          int mid = (be + en + 1) / 2;
          if(jud(*(a + mid), val) != 1) be = mid;
          else en = mid - 1;
        }else while(be < en){
          int mid = (be + en) / 2;
          if(jud(*(a + mid), val) != -1) en = mid;
          else be = mid + 1;
        }
        if(f_small && jud(*(a + be), val) == 1) be--;
        if(!f_small && jud(*(a + be), val) == -1) be++;
      } else {
        if(f_lb) while(be < en){
          int mid = (be + en + 1) / 2;
          if(jud(*(a + mid), val) != -1) be = mid;
          else en = mid - 1;
        }else while(be < en){
          int mid = (be + en) / 2;
          if(jud(*(a + mid), val) != 1) en = mid;
          else be = mid + 1;
        }
        if(!f_small && jud(*(a + be), val) == -1) be--;
        if(f_small && jud(*(a + be), val) == 1) be++;
      }
      return be;
    }

    template <class T> inline T lowb(T num) {return num & (-num); }
    
    inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
    inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
    inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
    inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
    inline int id4(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
    inline int id4(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
    inline int id4(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id4(int(a)); }
    inline int id4(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id4(int(a)); }
    
    

    long long pow(long long n, long long m, long long mod = 0){
      if(m < 0) return 0;
      long long ans = 1;
      long long k = n;
      while(m){
        if(m & 1) {
          ans *= k;
          if(mod) ans %= mod;
        }
        k *= k;
        if(mod) k %= mod;
        m >>= 1;
      }
      return ans;
    }

    
    template <class t1, class t2>
    inline void add(t1 &a, t2 b, int mod = -1) {
      if(mod == -1) mod = MOD;
      a += b;
      while(a >= mod) a -= mod;
      while(a < 0) a += mod;
    }
    template <class t>
    void output1(t arr) {
      for(int i = 0; i < (int)arr.size(); i++)
        cerr << arr[i] << ' ';
      cerr << endl;
    }
    template <class t>
    void output2(t arr) {
      for(int i = 0; i < (int)arr.size(); i++)
        output1(arr[i]);
    }

    


    const int maxn = 1000100;

    int n;

    
    
    
    
    struct SegmentNode{
      int be, en;
      NODE_VAL_TYPE maxv, add;
    };
    struct SegmentTree{
      int l;
      SegmentNode tree[SEGMENT_TREE_MAXN * 4];

      inline int GetLeft(int no) {return no << 1;}
      inline int GetRight(int no) {return (no << 1) + 1;}
      inline int GetFa(int no) {return no >> 1;}
      inline SegmentTree(){ l = 0; }

      void Build(int no, int l, int r, NODE_VAL_TYPE orig = 0, NODE_VAL_TYPE *a = NULL){
        if(l > r) r = l;
        if(l == r){
          tree[no].be = tree[no].en = l;
          tree[no].add = 0;
          if(a == NULL) tree[no].maxv = orig;
          else tree[no].maxv = a[l];
          tree[no].add = 0;
          return;
        }
        tree[no].be = l; tree[no].en = r;
        int mid = (l + r) / 2;
        Build(GetLeft(no), l, mid, orig, a);
        Build(GetRight(no), mid + 1, r, orig, a);
        tree[no].add = 0;
        PushUp(no);
      }
      inline void PushUp(int no) {
        tree[no].maxv = max1(tree[GetLeft(no)].maxv, tree[GetRight(no)].maxv);
      }
      inline void PushDown(int no) {
        int le = GetLeft(no), ri = GetRight(no);
        tree[le].add = max(tree[le].add, tree[no].add);
        tree[le].maxv = max(tree[le].maxv, tree[no].add);
        tree[ri].add = max(tree[ri].add, tree[no].add);
        tree[ri].maxv = max(tree[ri].maxv, tree[no].add);
        tree[no].add = 0;
      }
      void Upd(int l, int r, int no, NODE_VAL_TYPE id5){
    	  if (r < l) return;
    	while (!(l >= 0 && r <= n));
        if(l <= tree[no].be && r >= tree[no].en){
          tree[no].add = max(id5, tree[no].add);
          tree[no].maxv = max(tree[no].maxv, id5);
          return;
        }
        if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
        int mid = (tree[no].be + tree[no].en) >> 1;
        if(r >= tree[no].be && l <= mid) Upd(l, r, GetLeft(no), id5);
        if(r >= mid + 1 && l <= tree[no].en) Upd(l, r, GetRight(no), id5);
        PushUp(no);
      }
      NODE_VAL_TYPE GetMaxv(int l, int r, int no){
        if(l > r) return 0;
        if(l <= tree[no].be && r >= tree[no].en)
          return tree[no].maxv;
        if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
        NODE_VAL_TYPE ans = 0;
        int mid = (tree[no].be + tree[no].en) >> 1;
        if(r >= tree[no].be && l <= mid)
          ans = max(ans, GetMaxv(l, r, GetLeft(no)));
        if(r >= mid + 1 && l <= tree[no].en)
          ans = max(ans, GetMaxv(l, r, GetRight(no)));

        return ans;
      }
    } id1, id3;

    int tree_array[maxn];

    void Upd(int no, int add = 1) {
      while (no <= n) {
        tree_array[no] += add;
        no += lowb(no);
      }
    }

    int GetSum(int no) {
      int ans = 0;
      if (no == 0) return ans;
      while (no) {
        ans += tree_array[no];
        no -= lowb(no);
      }
      return ans;
    }

    struct Edge {
      int to, nxt;
    } e[maxn * 2];
    int head[maxn], le;

    void AddEdge(int a, int b) {
      e[le].to = b;
      e[le].nxt = head[a];
      head[a] = le++;
    }

    int dfs_order[maxn], ld;
    pii range[maxn];
    int deep[maxn], max_deep[maxn];

    void id0(int no, int fa) {
      dfs_order[ld] = no;
      range[no].first = ld++;
      max_deep[no] = deep[no];
      for (int i = head[no]; i != -1; i = e[i].nxt) if (e[i].to != fa) {
        if (no >= 0) {
          deep[e[i].to] = deep[no] + 1;
        }
        id0(e[i].to, no);
        max_deep[no] = max(max_deep[no], max_deep[e[i].to]);
      }
      range[no].second = ld - 1;
    }

    int temp_all_cnt[maxn];

    void id8(int no, int fa, int id2) {
      

    







      vector<pii> id6;
    

      for (int i = head[no]; i != -1; i = e[i].nxt) if (e[i].to != fa) {
    

        id6.push_back(
            mpr(max_deep[e[i].to] - deep[e[i].to] + 1, no));
        for (int j = head[e[i].to]; j != -1; j = e[j].nxt) if (e[j].to != no) {
          id6.push_back(
              mpr(max_deep[e[j].to] - deep[e[j].to] + 1, e[i].to));
        }
    

      }
      id6.push_back(mpr(id2, no));

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


      sort(id6.begin(), id6.end(),
           [&](const pii& a, const pii& b) {
    	  if (a == b) return false;
        if (a.first == b.first) {
          if (a.second == no) return false;
          else if (b.second == no) return true;
          else return a.second < b.second;
        }
        return a.first < b.first;
      });

      for (auto it = id6.rbegin();
          it != id6.rend(); it++) {
        if (it->second == no) {
          temp_all_cnt[no]++;
        } else {
          temp_all_cnt[it->second]++;
          id3.Upd(
              1, it->first, 1, temp_all_cnt[it->second] + temp_all_cnt[no] - 1);
        }
      }

      for (const auto rit : id6) {
        temp_all_cnt[rit.second]--;
      }

      sort(id6.begin(), id6.end(),
           [&](const pii& a, const pii& b) {
    	  if (a == b) return false;
        if (a.first == b.first) {
            if (a.second == no) return true;
            else if (b.second == no) return false;
            else return a.second < b.second;
        }
        return a.first < b.first;
      });

      int id9 = 0;
      for (auto it = id6.rbegin();
          it != id6.rend(); it++) {
        if (it->second == no) {
          temp_all_cnt[no]++;
          id3.Upd(
              1, it->first, 1, temp_all_cnt[no] + id9 - 1);
        } else {
          temp_all_cnt[it->second]++;
          if (id9 < temp_all_cnt[it->second]) {
            id9 = temp_all_cnt[it->second];
          }
        }
      }

      for (const auto rit : id6) {
        temp_all_cnt[rit.second]--;
      }

      

      vi id7;
      id7.push_back(id2);
      id7.push_back(0);
      for (int i = head[no]; i != -1; i = e[i].nxt) if (e[i].to != fa) {
        id7.push_back(max_deep[e[i].to] - deep[no]);
      }
      sort(id7.begin(), id7.end());
      for (int i = id7.size() - 1, j = id7.size(); i >= 0; i--) {
        while (j > 0 && id7[j - 1] >= id7[i] + 1) {
          j--;
        }
        id1.Upd(0, id7[i], 1, id7.size() - j + 1);
        id1.Upd(0, id7[i] - 1, 1, id7.size() - i);












        id3.Upd(0, id7[i], 1, id7.size() - i);
      }

      pii maxp = mpr(id2, -1);
      for (int i = head[no]; i != -1; i = e[i].nxt) if (e[i].to != fa) {
        if (maxp.second < max_deep[e[i].to] - deep[no]) {
          maxp.second = max_deep[e[i].to] - deep[no];
        }
        if (maxp.second > maxp.first) {
          swap(maxp.second, maxp.first);
        }
      }

      for (int i = head[no]; i != -1; i = e[i].nxt) if (e[i].to != fa) {
        id8(e[i].to, no,
               maxp.first == max_deep[e[i].to] - deep[no] ? maxp.second + 1 : maxp.first + 1);
      }

    }

    int main() {

    


      ios_base::sync_with_stdio(0);
      

      freopen("input.txt", "r", stdin);
      


      memset(head, -1, sizeof(head));
      scanf("%d", &n);
      for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        AddEdge(a, b);
        AddEdge(b, a);
      }
      deep[0] = 0;
      id0(0, -1);
      id1.Build(1, 0, n);
      id3.Build(1, 0, n);
      id8(0, -1, 0);

      for (int i = 0; i < n; i += 2) {
        printf("%d ", max(1, id1.GetMaxv(i / 2, i / 2, 1)));
        if (i + 1 < n) {
          printf("%d ", max(1, id3.GetMaxv(i / 2 + 1, i / 2 + 1, 1)));
        }
      }

      cerr << 1 << endl;


      return 0;
    }
