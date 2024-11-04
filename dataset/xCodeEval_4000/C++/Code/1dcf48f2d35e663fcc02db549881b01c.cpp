#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <functional>
#include <cassert>
#include <climits>
#include <iomanip>
#include <numeric>
#include <memory>
#include <random>
#define all(obj) (obj).begin(), (obj).end()
#define range(i, l, r) for(int i=l;i<r;i++)
#define bit_subset(i, S) for(int i=S, zero_cnt=0;(zero_cnt+=i==S)<2;i=(i-1)&S)
#define bit_kpop(i, n, k) for(int i=(1<<k)-1,x_bit,y_bit;i<(1<<n);x_bit=(i&-i),y_bit=i+x_bit,i=(!i?(1<<n):((i&~y_bit)/x_bit>>1)|y_bit))
#define bit_kth(i, k) ((i >> k)&1)
#define bit_highest(i) (i?63-__builtin_clzll(i):-1)
#define bit_lowest(i) (i?__builtin_ctzll(i):-1)
#define c2(n) ((ll(n)*(n-1))/2)
#define c3(n) (((ll(n)*(n-1))*(n-2))/6)
using ll = long long;
using ld = long double;
using ul = uint64_t;
using pi = std::pair<int, int>;
using pl = std::pair<ll, ll>;
using namespace std;

constexpr uint32_t MASK32 = 0xffffffff;
constexpr uint32_t SIGN32 = 0x80000000;
uint64_t encode_signed(int a, int b){return ((uint64_t(a)+SIGN32)<<32)+(uint64_t(b)+SIGN32);}
pi decode_signed(uint64_t x){return {int((x>>32)-SIGN32),int((x&MASK32)-SIGN32)};}
ll encode(int a, int b){return (ll(a)<<32)+b;}
pi decode(ll x){return {x>>32,x&MASK32};}

template<typename F, typename S>
std::ostream &operator<<(std::ostream &dest, const std::pair<F, S> &p){
  dest << p.first << ' ' << p.second;
  return dest;
}
template<typename T>
std::ostream &operator<<(std::ostream &dest, const std::vector<std::vector<T>> &v){
  int sz = v.size();
  if(sz==0) return dest;
  for(int i=0;i<sz;i++){
    int m = v[i].size();
    for(int j=0;j<m;j++) dest << v[i][j] << (i!=sz-1&&j==m-1?'\n':' ');
  }
  return dest;
}
template<typename T>
std::ostream &operator<<(std::ostream &dest, const std::vector<T> &v){
  int sz = v.size();
  if(sz==0) return dest;
  for(int i=0;i<sz-1;i++) dest << v[i] << ' ';
  dest << v[sz-1];
  return dest;
}
template<typename T, size_t sz>
std::ostream &operator<<(std::ostream &dest, const std::array<T, sz> &v){
  if(sz==0) return dest;
  for(int i=0;i<sz-1;i++) dest << v[i] << ' ';
  dest << v[sz-1];
  return dest;
}
template<typename T>
std::ostream &operator<<(std::ostream &dest, const std::set<T> &v){
  for(auto itr=v.begin();itr!=v.end();){
    dest << *itr;
    itr++;
    if(itr!=v.end()) dest << ' ';
  }
  return dest;
}
template<typename T, typename E>
std::ostream &operator<<(std::ostream &dest, const std::map<T, E> &v){
  for(auto itr=v.begin();itr!=v.end();){
    dest << '(' << itr->first << ", " << itr->second << ')';
    itr++;
    if(itr!=v.end()) dest << '\n';
  }
  return dest;
}
template<typename T>
vector<T> make_vec(size_t sz, T val){return std::vector<T>(sz, val);}
template<typename T, typename... Tail>
auto make_vec(size_t sz, Tail ...tail){
  return std::vector<decltype(make_vec<T>(tail...))>(sz, make_vec<T>(tail...));
}
template<typename T>
vector<T> read_vec(size_t sz){
  std::vector<T> v(sz);
  for(int i=0;i<sz;i++) std::cin >> v[i];
  return v;
}
template<typename T, typename... Tail>
auto read_vec(size_t sz, Tail ...tail){
  auto v = std::vector<decltype(read_vec<T>(tail...))>(sz);
  for(int i=0;i<sz;i++) v[i] = read_vec<T>(tail...);
  return v;
}
template<typename T>
bool mul_overflow(T a, T b){
  static T INF = numeric_limits<T>::max();
  return (INF / a) < b;
}
template<typename T>
bool add_overflow(T a, T b){
  static T INF = numeric_limits<T>::max();
  return (INF - a) < b;
}
template<typename T>
bool chmax(T &a, const T b){
  if(a >= b) return false;
  a = b;
  return true;
}
template<typename T>
bool chmin(T &a, const T b){
  if(a <= b) return false;
  a = b;
  return true;
}
template<typename T>
T max(vector<T> &v, int l=0, int r = -1){
  return *std::max_element(v.begin()+l, v.begin()+(r==-1?v.size():r));
}
template<typename T>
T min(vector<T> &v, int l=0, int r = -1){
  return *std::min_element(v.begin()+l, v.begin()+(r==-1?v.size():r));
}
template<typename T>
int argmax(vector<T> &v, int l=0, int r=-1){
  T res = max(v, l, r);
  if(r==-1) r = v.size();
  for(int i=l;i<r;i++) if(v[i]==res) return i;
  return -1;
}
template<typename T>
int argmin(vector<T> &v, int l=0, int r=-1){
  T res = min(v, l, r);
  if(r==-1) r = v.size();
  for(int i=l;i<r;i++) if(v[i]==res) return i;
  return -1;
}
ll gcd(ll _a, ll _b) {
  uint64_t a = abs(_a), b = abs(_b);
  if(a == 0) return b;
  if(b == 0) return a;
  int shift = __builtin_ctzll(a | b);
  a >>= __builtin_ctzll(a);
  do{
    b >>= __builtin_ctzll(b);
    if(a > b) std::swap(a, b);
    b -= a;
  }while(b);
  return (a << shift);
}
ll lcm(ll a, ll b){
  return (a / gcd(a, b)) * b;
}
ll llpow(ll a, ll b){
  ll ret = 1, mul = a;
  while(b){
    if(b&1) ret *= mul;
    mul *= mul;
    b >>= 1;
  }
  return ret;
}
template<int MOD>
ll mpow(ll a, ll b){
  int ret = (MOD==1?0:1), mul = a % MOD;
  while(b){
    if(b&1) ret = (ll(ret) * mul) % MOD;
    mul = (ll(mul) * mul) % MOD;
    b >>= 1;
  }
  return ret;
}
ll mpow(ll a, ll b, ll MOD){
  int ret = (MOD==1?0:1), mul = a % MOD;
  while(b){
    if(b&1) ret = (ll(ret) * mul) % MOD;
    mul = (ll(mul) * mul) % MOD;
    b >>= 1;
  }
  return ret;
}

template<class _Key, class _Hash, bool DOWNSIZE> class UnorderedSetIterator;

template<class _Key, class _Hash = hash<_Key>, bool DOWNSIZE = false>
class UnorderedSet{
private:
    using iterator = UnorderedSetIterator<_Key, _Hash, DOWNSIZE>;
    friend UnorderedSetIterator<_Key, _Hash, DOWNSIZE>;
    struct bucket {
        _Key _key;
        short int _dist;
        bool _last, _end;
        bucket() noexcept : _dist(-1), _last(false), _end(false){}
        bucket& operator=(const bucket& another) = default;
        ~bucket(){ if(!empty()) _key.~_Key(); }
        inline void clear() noexcept { _dist = -1; }
        inline void _delete(){ _dist = -1, _key.~_Key(); }
        inline bool empty() const noexcept { return (_dist == -1); }
    };
    inline static unsigned int ceilpow2(unsigned int u) noexcept {
        if(u == 0u) return 0u;
        --u, u |= u >> 1, u |= u >> 2, u |= u >> 4, u |= u >> 8;
        return (u | (u >> 16)) + 1;
    }
    inline static bucket *increment(bucket *cur) noexcept {
        for(++cur; !cur->_end; ++cur){
            if(!cur->empty()) break;
        }
        return cur;
    }
    inline bucket *next_bucket(bucket *cur) const noexcept {
        return cur->_last ? _buckets : cur + 1;
    }
    inline unsigned int make_hash(const _Key& key) const noexcept {
        return _Hash()(key);
    }
    inline float load_rate() const noexcept {
        return (float)_data_count / _bucket_count;
    }
    bucket *insert(bucket *cur, short int dist, _Key&& key){
        bucket *ret = cur;
        bool flag = false;
        while(true){
            if(cur->empty()){
                cur->_key = move(key), cur->_dist = dist;
                if(!flag) ret = cur, flag = true;
                break;
            }else if(dist > cur->_dist){
                swap(key, cur->_key), swap(dist, cur->_dist);
                if(!flag) ret = cur, flag = true;
            }
            ++dist;
            cur = next_bucket(cur);
        }
        return ret;
    }
    bucket *_find(const _Key& key) const {
        bucket *cur = _buckets + (make_hash(key) & _mask);
        int dist = 0;
        while(dist <= cur->_dist){
            if(key == cur->_key) return cur;
            ++dist, cur = next_bucket(cur);
        }
        return _buckets + _bucket_count;
    }
    template<class Key>
    bucket *find_insert(Key&& key){
        unsigned int hash = make_hash(key);
        bucket *cur = _buckets + (hash & _mask);
        int dist = 0;
        while(dist <= cur->_dist){
            if(key == cur->_key) return cur;
            ++dist, cur = next_bucket(cur);
        }
        ++_data_count;
        if(rehash_check()){
            cur = _buckets + (hash & _mask), dist = 0;
        }
        _Key new_key = forward<Key>(key);
        return insert(cur, dist, move(new_key));
    }
    template<typename... Args>
    bucket *emplace(Args&&... args){
        return find_insert(_Key(forward<Args>(args)...));
    }
    bucket *backward_shift(bucket *cur, bool next_ret){
        bucket *next = next_bucket(cur), *ret = cur;
        if(next->_dist < 1) return next_ret ? increment(cur) : cur;
        do {
            cur->_key = next->_key, cur->_dist = next->_dist - 1;
            cur = next, next = next_bucket(cur);
        }while(next->_dist >= 1);
        cur->clear();
        return ret;
    }
    bucket *erase_impl(bucket *cur, bool next_ret){
        assert(static_cast<size_t>(cur - _buckets) != _bucket_count);
        cur->_delete();
        --_data_count;
        return backward_shift(cur, next_ret);
    }
    bucket *erase_itr(bucket *cur, bool next_ret = true){
        const _Key key = cur->_key;
        return erase_impl(rehash_check() ? _find(key) : cur, next_ret);
    }
    size_t erase_key(const _Key& key){
        rehash_check();
        bucket *cur = _find(key);
        if(static_cast<size_t>(cur - _buckets) == _bucket_count){
            return 0;
        }else{
            erase_impl(cur, false);
            return 1;
        }
    }
    bool rehash_check(){
        if(_bucket_count == 0){
            rehash(1u);
            return true;
        }else if(load_rate() >= MAX_LOAD_RATE){
            rehash(_bucket_count * 2u);
            return true;
        }else if(DOWNSIZE){
            if(load_rate() <= MIN_LOAD_RATE && _bucket_count >= DOWNSIZE_THRESHOLD){
                rehash(_bucket_count / 2u);
                return true;
            }
        }
        return false;
    }
    void move_data(bucket *cur){
        insert(_buckets + (make_hash(cur->_key) & _mask), 0, move(cur->_key));
    }
    void rehash(unsigned int new_bucket_count){
        UnorderedSet new_unordered_set(new_bucket_count);
        new_unordered_set._data_count = _data_count;
        for(bucket *cur = _buckets; !cur->_end; ++cur){
            if(!cur->empty()){
                new_unordered_set.move_data(cur);
            }
        }
        swap(*this, new_unordered_set);
    }
    friend void swap(UnorderedSet& ust1, UnorderedSet& ust2){
        swap(ust1._bucket_count, ust2._bucket_count);
        swap(ust1._mask, ust2._mask);
        swap(ust1._data_count, ust2._data_count);
        swap(ust1._buckets, ust2._buckets);
    }

private:
    unsigned int _bucket_count, _mask, _data_count;
    bucket *_buckets;
public:
    const float MAX_LOAD_RATE = 0.5f;
    const float MIN_LOAD_RATE = 0.1f;
    const unsigned int DOWNSIZE_THRESHOLD = 16u;
    UnorderedSet(unsigned int bucket_size = 0u)
     : _bucket_count(ceilpow2(bucket_size)), _mask(_bucket_count - 1),
        _data_count(0u), _buckets(new bucket[_bucket_count + 1]){
        if(_bucket_count > 0) _buckets[_bucket_count - 1]._last = true;
        else _mask = 0;
        _buckets[_bucket_count]._end = true;
    }
    UnorderedSet(const UnorderedSet& another)
        : _bucket_count(another._bucket_count), _mask(another._mask), _data_count(another._data_count){
        _buckets = new bucket[_bucket_count + 1u];
        for(unsigned int i = 0u; i <= _bucket_count; ++i){
            _buckets[i] = another._buckets[i];
        }
    }
    UnorderedSet(UnorderedSet&& another)
        : _bucket_count(move(another._bucket_count)), _mask(move(another._mask)),
            _data_count(move(another._data_count)), _buckets(another._buckets){
        another._buckets = nullptr;
    }
    UnorderedSet& operator=(const UnorderedSet& another){
        delete[] _buckets;
        _bucket_count = another._bucket_count;
        _mask = another._mask;
        _data_count = another._data_count;
        _buckets = new bucket[_bucket_count + 1u];
        for(unsigned int i = 0u; i <= _bucket_count; ++i){
            _buckets[i] = another._buckets[i];
        }
        return *this;
    }
    UnorderedSet& operator=(UnorderedSet&& another){
        delete[] _buckets;
        _bucket_count = move(another._bucket_count);
        _mask = move(another._mask);
        _data_count = move(another._data_count);
        _buckets = another._buckets;
        another._buckets = nullptr;
        return *this;
    }
    void allocate(unsigned int element_size){
        rehash(ceilpow2(ceil(element_size / MAX_LOAD_RATE) + 1));
    }
    ~UnorderedSet(){ delete[] _buckets; }
    friend ostream& operator<< (ostream& os, UnorderedSet& ust) noexcept {
        for(_Key& val : ust) os << val << " ";
        return os;
    }
    void clear(){
        UnorderedSet new_unordered_set(0u);
        swap(*this, new_unordered_set);
    }
    size_t size() const noexcept { return _data_count; }
    size_t bucket_count() const noexcept { return _bucket_count; }
    bool empty() const noexcept { return (_data_count == 0); }
    iterator begin() noexcept {
        return (_buckets->empty() && _bucket_count > 0) ? iterator(increment(_buckets)) : iterator(_buckets);
    }
    iterator end() noexcept { return iterator(_buckets + _bucket_count); }
    iterator find(const _Key& key) const { return iterator(_find(key)); }
    size_t count(const _Key& key) const { return (_find(key) != _buckets + _bucket_count); }
    iterator insert(const _Key& key){ return iterator(find_insert(key)); }
    iterator insert(_Key&& key){ return iterator(find_insert(move(key))); }
    template<typename... Args>
    iterator emplace(Args&&... args){ return iterator(_emplace(forward<Args>(args)...)); }
    size_t erase(const _Key& key){ return erase_key(key); }
    iterator erase(const iterator& itr){ return iterator(erase_itr(itr.bucket_ptr)); }
    void simple_erase(const _Key& key){ erase_key(key); }
    void simple_erase(const iterator& itr){ erase_itr(itr.bucket_ptr, false); }

    

    short int maximum_distance() const noexcept {
        short int ret = -1;
        for(bucket *cur = _buckets; !cur->_end; ++cur){
            ret = max(ret, cur->_dist);
        }
        return ret;
    }
};

template<class _Key, class _Hash, bool DOWNSIZE>
class UnorderedSetIterator {
private:
    friend UnorderedSet<_Key, _Hash, DOWNSIZE>;
    typename UnorderedSet<_Key, _Hash, DOWNSIZE>::bucket *bucket_ptr;
    using iterator_category = forward_iterator_tag;
    using value_type = _Key;
    using difference_type = ptrdiff_t;
    using pointer = _Key*;
    using reference = _Key&;

private:
    UnorderedSetIterator(typename UnorderedSet<_Key, _Hash, DOWNSIZE>::bucket *_bucket_ptr)
        noexcept : bucket_ptr(_bucket_ptr){}
public:
    UnorderedSetIterator() noexcept : bucket_ptr(){}
    UnorderedSetIterator(const UnorderedSetIterator& itr) noexcept : bucket_ptr(itr.bucket_ptr){}
    UnorderedSetIterator& operator=(const UnorderedSetIterator& itr)
        & noexcept { return bucket_ptr = itr.bucket_ptr, *this; }
    UnorderedSetIterator& operator=(const UnorderedSetIterator&& itr)
        & noexcept { return bucket_ptr = itr.bucket_ptr, *this; }
    reference operator*() const noexcept { return bucket_ptr->_key; }
    pointer operator->() const noexcept { return &(bucket_ptr->_key); }
    UnorderedSetIterator& operator++() noexcept {
        return bucket_ptr = UnorderedSet<_Key, _Hash, DOWNSIZE>::increment(bucket_ptr), *this;
    }
    UnorderedSetIterator operator++(int) const noexcept {
        return UnorderedSetIterator(UnorderedSet<_Key, _Hash, DOWNSIZE>::increment(this->bucket_ptr));
    }
    bool operator==(const UnorderedSetIterator& itr) const noexcept { return !(*this != itr); };
    bool operator!=(const UnorderedSetIterator& itr) const noexcept { return bucket_ptr != itr.bucket_ptr; }
};

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;std::cin >> n;
  vector<UnorderedSet<int>> g(n);
  for(int i=0;i<n-1;i++){
    int a, b;std::cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  vector<int> fib{1, 2, 3, 5,
  8, 13, 21, 34, 55,
  89, 144, 233, 377, 610,
  987, 1597, 2584, 4181, 6765,
  10946, 17711, 28657, 46368, 75025, 121393, 196418};

  auto k = lower_bound(all(fib), n) - fib.begin();
  if(k==fib.size()||fib[k]!=n){
    std::cout << "NO" << '\n';
    return 0;
  }

  vector<int> sz(n);

  auto szset = [&](auto &&szset, int now, int from)->int{
    int res = 1;
    for(auto to:g[now]){
      if(to==from) continue;
      res += szset(szset, to, now);
    }
    return sz[now] = res;
  };
  int L, R;

  auto search = [&](auto &&search, int now, int from, int K)->void{
    if(L!=-1&&R!=-1) return;
    for(auto to:g[now]){
      if(to==from) continue;
      if(sz[to]==fib[K-1]){
        L = to, R = now;
      }else if(sz[to]==fib[K-2]){
        L = now, R = to;
      }
      search(search, to, now, K);
    }
  };
  auto dfs = [&](auto &&dfs, int root, int K)->bool{
    if(K<=1) return true;
    szset(szset, root, -1);
    

    L = R = -1;
    search(search, root, -1, K);
    if(L==-1||R==-1) return false;
    g[L].erase(R);
    g[R].erase(L);
    int X = L, Y = R;
    if(dfs(dfs, X, K-1) && dfs(dfs, Y, K-2)) return true;
    return false;
  };
  std::cout << (dfs(dfs, 0, k) ? "YES": "NO") << '\n';
}
