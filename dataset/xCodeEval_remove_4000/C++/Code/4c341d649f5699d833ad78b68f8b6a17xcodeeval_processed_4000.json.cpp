


using namespace std;
















template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}


using ll = long long int;
using P = pair<int, int>;


const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} id19;

int ato_int(char c){
  return int(c - 'a');
}

char id18(int i){
  return char(i + 'a');
}

int id9(char c){
  if('a' <= c && c <= 'z')return int(c - 'a');
  return int(c - 'A') + 26;
}

char id2(int i){
  if(i < 26)return char(i + 'a');
  return char(i - 26 + 'A');
}

int dto_int(char c){
  return int(c - '0');
}

char id14(int i){
  return char(i + '0');
}

typedef struct id17 {
  int size;
  int block = 32;
  int l = 256;
  vector<uint32_t> B;
  vector<unsigned> L, S;
  id17(){}
  id17(int size_){
    size = size_;
    B.assign((size + block - 1) / block, 0U);
    L.assign((size + l - 1) / l, 0U);
    S.assign((size + block - 1) / block, 0U);
  }
  void set_bit(int at){
    B[at / block] |= (1U << (at % block));
  }
  void build(){
    int true_count = 0;
    for(int i = 0; i < ((size + block - 1) / block) * block; i+=block){
      if(i % l == 0)L[i / l] = true_count;
      S[i / block] = true_count - L[i / l];
      true_count += __builtin_popcount(B[i / block]);
    }
  }
  bool access(int at){
    return (B[at / block] >> (at % block)) & 1U;
  }
  bool operator[](int at){
    return access(at);
  }
  

  int rank(int at){
    return L[at / l] + S[at / block] + __builtin_popcount((B[at / block] & ((1U << (at % block)) - 1)));
  }
  int rank(bool val, int at){
    return (val ? rank(at): at - rank(at));
  }
  int select(bool val, int x){
    if(x < 0 || x >= rank(val, size))return -1;
    int ld = 0, rd = size;
    while(rd - ld > 1){
      int md = (rd + ld) / 2;
      if(rank(val, md) >= x + 1)rd = md;
      else ld = md;
    }
    return rd - 1;
  }
  int select(int x){
    return select(1, x);
  }
  int select(bool val, int x, int l){
    return select(val, x + rank(val, l));
  }
} SuccinctBitVector;

vector<int> ato_vector(const string &s){
  vector<int> v(s.size());
  for(int i = 0; i < s.size(); i++){
    v[i] = ato_int(s[i]);
  }
  return v;
}

template <typename T>
struct id1{
  int n = 0;
  int len = 0;
  vector<SuccinctBitVector> mat;
  vector<int> zc;
  vector<int> bl, br;
  vector<vector<T>> sum;
  id1(T m, vector<T> s){
    len = s.size();
    while((1LL<< n) <= m)n++;
    mat.resize(n);
    zc.resize(n);
    bl.resize(n);
    br.resize(n);
    sum.resize(n + 1, vector<T>(len + 1, 0));

    for(int i = 0; i < len; i++)sum[0][i + 1] = sum[0][i] + s[i];

    vector<T> l(len), r(len);
    for(int i = 0; i < n; i++){
      mat[i] = SuccinctBitVector(len + 1);
      int li = 0, ri = 0;
      for(int j = 0; j < len; j++){
        if((s[j] >> (n - i - 1)) & 1){
          r[ri++] = s[j];
          mat[i].set_bit(j);
        }else{
          l[li++] = s[j];
        }
      }
      zc[i] = li;
      mat[i].build();
      swap(l, s);
      for(int j = 0; j < ri; j++)s[li + j] = r[j];
      for(int j = 0; j < len; j++)sum[i+1][j+1] = sum[i+1][j] + s[j];
    }
  }
  T access(int i){
    int res = 0;
    for(int j = 0; j < n; j++){
      bool bit = mat[j][i];
      res = (res << 1) | bit;
      i = zc[j] * bit + mat[j].rank(bit, i);
    }
    return res;
  }
  T operator[](int i){
    return access(i);
  }
  int rank(T val, int i){
    int l = 0, r = i;
    for(int j = 0; j < n; j++){
      bl[j] = l, br[j] = r;
      bool bit = (val >> (n - j - 1)) & 1;
      l = zc[j] * bit + mat[j].rank(bit, l);
      r = zc[j] * bit + mat[j].rank(bit, r);
    }
    return r - l;
  }
  int select(T val, int i){
    rank(val, len);
    for(int j = n - 1; j >= 0; j--){
      bool bit = (val >> (n - j - 1)) & 1;
      i = mat[j].select(bit, i, bl[j]);
      if(i >= br[j] || i < 0)return -1;
      i -= bl[j];
    }
    return i;
  }
  int select(T val, int i, int l){
    return select(val, i + rank(val, l));
  }
  T quantile(int s, int e, int k){
    if(e - s <= k || k < 0)return -1;
    T res = 0;
    for(int i = 0; i < n; i++){
      int l = mat[i].rank(1, s);
      int r = mat[i].rank(1, e);
      if(r - l > k){
        s = zc[i] + l;
        e = zc[i] + r;
        res = res | (1LL << (n - i - 1));
      }else{
        k -= (r - l);
        s -= l;
        e -= r;
      }
    }
    return res;
  }
  

  tuple<int, int, int> rankall(T x, int s, int e){
    if(s >= e)return make_tuple(0, 0, 0);
    int rank_lt = 0, rank_gt = 0;
    for(int i = 0; i < n && s < e; i++){
      bool bit = (x >> (n - i - 1)) & 1;
      int s0 = mat[i].rank(0, s);
      int s1 = s - s0;
      int e0 = mat[i].rank(0, e);
      int e1 = e - e0;
      if(bit){
        rank_lt += e0 - s0;
        s = zc[i] + s1;
        e = zc[i] + e1;
      }else{
        rank_gt += e1 - s1;
        s = s0;
        e = e0;
      }
    }
    return make_tuple(e - s - rank_lt - rank_gt, rank_lt, rank_gt);
  }
  int rangefreq(int s, int e, T mini, T maxi){
    tuple<int, int, int> id10 = rankall(maxi, s, e);
    tuple<int, int, int> mini_t = rankall(mini, s, e);
    return get<1>(id10) - get<1>(mini_t);
  }
  int ranklt(T x, int s, int e){
    return get<1>(rankall(x, s, e));
  }
  int rankgt(T x, int s, int e){
    return get<2>(rankall(x, s, e));
  }
  T rangemax(int s, int e){
    return quantile(s, e, 0);
  }
  T rangemin(int s, int e){
    return quantile(s, e, e - s - 1);
  }
  vector<pair<T, int>> topk(int s, int e, int k){
    vector<pair<T, int>> res;
    using v_t = tuple<int, int, int, int, T>;
    auto comp = [](const v_t &a, const v_t &b){
      if(get<0>(a) != get<0>(b))return get<0>(a) < get<0>(b);
      if(get<3>(a) != get<3>(b))return get<3>(a) > get<3>(b);
      return get<3>(a) > get<3>(b);
    };
    priority_queue<v_t, vector<v_t>, decltype(comp)> pq(comp);
    pq.push(make_tuple(e - s, s, e, 0, 0));
    while(!pq.empty()){
      auto p = pq.top(); pq.pop();
      int width, li, ri, dep;
      T val;
      tie(width, li, ri, dep, val) = p;
      if(dep >= n){
        res.emplace_back(make_pair(val, ri - li));
        if(res.size() >= k)break;
        continue;
      }
      int l0 = mat[dep].rank(0, li);
      int r0 = mat[dep].rank(0, ri);
      if(l0 < r0)pq.push(make_tuple(r0 - l0, l0, r0, dep + 1, val));
      int l1 = zc[dep] + mat[dep].rank(1, li);
      int r1 = zc[dep] + mat[dep].rank(1, ri);
      if(l1 < r1)pq.push(make_tuple(r1 - l1, l1, r1, dep + 1, val | (1LL << (n - dep - 1))));
    }
    return res;
  }
  T rangesum(int s, int e, int depth, T val, T x, T y){
    if(s == e)return 0;
    if(depth == n){
      if(x <= val && val < y)return val * (e - s);
      return 0;
    }
    T nv = (1LL << (n - depth - 1)) | val;
    T nnv = ((1LL << (n - depth - 1)) - 1) | nv;
    if(nnv < x || y <= val)return 0;
    if(x <= val && nnv < y)return sum[depth][e] - sum[depth][s];
    int s0 = mat[depth].rank(0, s);
    int s1 = s - s0;
    int e0 = mat[depth].rank(0, e);
    int e1 = e - e0;
    return rangesum(s0, e0, depth + 1, val, x, y) + rangesum(zc[depth] + s1, zc[depth] + e1, depth + 1, nv, x, y);
  }
  T rangesum(int s, int e, T x, T y){
    return rangesum(s, e, 0, 0, x, y);
  }
  T prev(int s, int e, T x, T y){
    y--;
    using v_t = tuple<int, int, int, T, bool>;
    stack<v_t> st;
    st.push(make_tuple(s, e, 0, 0, true));
    while(!st.empty()){
      auto p = st.top(); st.pop();
      int li, ri, depth;
      T val;
      bool tight;
      tie(li, ri, depth, val, tight) = p;

      if(depth == n){
        if(val >= x)return val;
        continue;
      }
      
      bool bit = (y >> (n - depth - 1)) & 1;
      int l0 = mat[depth].rank(0, li);
      int l1 = li - l0;
      int r0 = mat[depth].rank(0, ri);
      int r1 = ri - r0;
      if(l0 != r0){
        st.push(make_tuple(l0, r0, depth + 1, (val << 1), tight && !bit));
      }
      if(l1 != r1){
        if(!tight || bit){
          st.push(make_tuple(zc[depth] + l1, zc[depth] + r1, depth + 1, ((val<<1)|1), tight));
        }
      }
    }
    return -1;
  }
  T next(int s, int e, T x, T y){
    using v_t = tuple<int, int, int, T, bool>;
    stack<v_t> st;
    st.push(make_tuple(s, e, 0, 0, true));
    while(!st.empty()){
      auto p = st.top(); st.pop();
      int li, ri, depth;
      T val;
      bool tight;
      tie(li, ri, depth, val, tight) = p;
      if(depth == n){
        if(val < y)return val;
        continue;
      }
      
      bool bit = (x >> (n - depth - 1)) & 1;
      int l0 = mat[depth].rank(0, li);
      int l1 = li - l0;
      int r0 = mat[depth].rank(0, ri);
      int r1 = ri - r0;
      if(l1 != r1){
        st.push(make_tuple(zc[depth] + l1, zc[depth] + r1, depth + 1, ((val<<1)|1), tight && bit));
      }
      if(l0 != r0){
        if(!tight || !bit){
          st.push(make_tuple(l0, r0, depth + 1, (val << 1), tight));
        }
      }
    }
    return -1;
  }
  vector<tuple<T, int, int>> intersect(int s1, int e1, int s2, int e2){
    using v_t = tuple<int, int, int, int, int, T>;
    vector<tuple<T, int, int>> res;
    queue<v_t> q;
    q.push(make_tuple(s1, e1, s2, e2, 0, 0));
    while(!q.empty()){
      auto p = q.front(); q.pop();
      int id4, id11, id3, id0, depth;
      T val;
      tie(id4, id11, id3, id0, depth, val) = p;
      if(depth == n){
        res.emplace_back(make_tuple(val, id11 - id4, id0 - id3));
        continue;
      }

      int id15 = mat[depth].rank(0, id4);
      int id12 = mat[depth].rank(0, id11);
      int id6 = mat[depth].rank(0, id3);
      int id13 = mat[depth].rank(0, id0);

      if(id15 != id12 && id6 != id13){
        q.push(make_tuple(id15, id12, id6, id13, depth + 1, val));
      }

      int id5 = id4 - id15 + zc[depth];
      int id8 = id11 - id12 + zc[depth];
      int id7 = id3 - id6 + zc[depth];
      int id16 = id0 - id13 + zc[depth];

      if(id5 != id8 && id7 != id16){
        q.push(make_tuple(id5, id8, id7, id16, depth + 1, val | (1LL << (n - depth - 1))));
      }
    }
    return res;
  }
  void max_dfs(int d, int s, int e, int &k, T val, vector<T> &vs){
    if(s >= e || !k)return;
    if(d == n){
      while(s++ < e && k > 0)vs.emplace_back(val), k--;
      return;
    }
    int l1 = mat[d].rank(1, s);
    int r1 = mat[d].rank(1, e);
    max_dfs(d + 1, zc[d] + l1, zc[d] + r1, k, (1LL<<(n-d-1))|val, vs);
    max_dfs(d + 1, s - l1, e - r1, k, val, vs);
  }
  vector<T> maximum(int s, int e, int k){
    if(e - s < k)k = e - s;
    if(k < 0)return {};
    vector<T> res;
    max_dfs(0, s, e, k, 0, res);
    return res;
  }
  void list_dfs(int d, int s, int e, T val, T a, T b, vector<pair<T, int>> &vs){
    if(val >= b || e - s <= 0)return;
    if(d == n){
      if(a <= val){
        vs.emplace_back(make_pair(val, e - s));
      }
      return;
    }
      T nv = val | (1LL<<(n-d-1)), nnv = nv | ((1LL<<(n-d-1))-1);
      if(nnv < a)return;
      int l0 = mat[d].rank(1, s);
      int r0 = mat[d].rank(1, e);
      list_dfs(d + 1, s - l0, e - r0, val, a, b, vs);
      list_dfs(d + 1, zc[d] + l0, zc[d] + r0, nv, a, b, vs);
  }
  vector<pair<T, int>> freq_list(int s, int e, T a, T b){
    vector<pair<T, int>> res;
    list_dfs(0, s, e, 0, a, b, res);
    return res;
  }
  vector<pair<int, T>> get_rect(int s, int e, T a, T b){
    vector<pair<T, int>> fl = freq_list(s, e, a, b);
    vector<pair<int, T>> res;
    for(auto &e: fl){
      for(int i = 0; i < e.second; i++){
        res.emplace_back(make_pair(select(e.first, i, s), e.first));
      }
    }
    return res;
  }
};

string s[3010];
int ri[3010][3010], uri[3010][3010];

int main(int argc, char const* argv[])
{
  int n, m; cin >> n >> m;
  rep(i, n)cin >> s[i];
  rrep(j, m){
    rep(i, n){
      if(s[i][j] != 'z'){
        uri[i][j] = ri[i][j] = 0;
      }else{
        ri[i][j] = 1 + ri[i][j+1];
        if(i > 0)uri[i][j] = 1 + uri[i-1][j+1];
        else uri[i][j] = 1;
      }
    }
  }
  ll res = 0;
  rep(j, m){
    vector<int> v(n, 0);
    rep(i, n)v[i] = i - min(uri[i][j], ri[i][j]) + 1;
    id1<int> wm = id1<int>(3001, v);
    rep(i, n){
      if(s[i][j] != 'z')continue;
      res += wm.rangefreq(i, min(n, i + ri[i][j]), 0, i + 1);
      

    }
  }
  cout << res << endl;
  return 0;
}
