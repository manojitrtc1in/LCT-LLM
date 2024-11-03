
 
 
using namespace std;
template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}
template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);
template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, deque<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }
template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}
static inline void id5() {
  cerr << "}";
}
template <class T, class... V>
void id5(T const& t, V const&... v) {
  cerr << t;
  if(sizeof...(v)) { cerr << ", "; }
  id5(v...);
}

using li = long long int;
using lu = long long unsigned;
using ld = long double;
using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;
template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;
struct uint64_hash {
  static inline uint64_t rotr(uint64_t x, unsigned k) {
    return (x >> k) | (x << (8U * sizeof(uint64_t) - k));
  }
  static inline uint64_t hash_int(uint64_t x) noexcept {
    auto h1 = x * (uint64_t)(0xA24BAED4963EE407);
    auto h2 = rotr(x, 32U) * (uint64_t)(0x9FB21C651E98DF25);
    auto h = rotr(h1 + h2, 32U);
    return h;
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t id10 = std::chrono::steady_clock::now().time_since_epoch().count();
    return hash_int(x + id10);
  }
};
template <typename K, typename V, typename Hash = uint64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = uint64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
struct empty_t {};
namespace tuple_access {
  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;
  template<class T>
  auto operator%(T&& v, xx_t) -> decltype(get<0>(forward<T>(v))) { return get<0>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, yy_t) -> decltype(get<1>(forward<T>(v))) { return get<1>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, zz_t) -> decltype(get<2>(forward<T>(v))) { return get<2>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, ww_t) -> decltype(get<3>(forward<T>(v))) { return get<3>(forward<T>(v)); }
}
using namespace tuple_access;
template<class Fun>
class id25 {
  Fun fun_;
  public:
    template<class T>
    explicit id25(T &&fun): fun_(forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(ref(*this), forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) letrec(Fun &&fun) {
  return id25<decay_t<Fun>>(forward<Fun>(fun));
}
template<class Fun>
class id3 {
  Fun fun_;
  public:
    template<class T>
    explicit id3(T &&fun): fun_(forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args const&... args) {
      static map<tuple<Args...>, decltype(fun_(ref(*this), args...))> M;
      auto key = make_tuple(args...);
      auto it = M.find(key);
      if(it != M.end()) return it->second;
      auto r = fun_(ref(*this), args...);
      M[key] = r;
      return r;
    }
};
template<class Fun>
decltype(auto) id22(Fun &&fun) {
  return id3<decay_t<Fun>>(forward<Fun>(fun));
}
int ilog2(int x){ return 31 - __builtin_clz(x); }
li ilog2(li x){ return 63 - __builtin_clzll(x); }
li ctz(li x) { return __builtin_ctzll(x); }
li clz(li x) { return __builtin_clzll(x); }
li popcount(li x) { return __builtin_popcountll(x); }
li getbit(li x, li i){ return (x>>i)&1; }
li setbit(li x, li i) { return x|(1ll<<i); }
li unsetbit(li x, li i) { return x&~(1ll<<i); }
template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};
template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }
template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }
template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}
template<typename T>
T id28(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}
namespace pdqsort_detail {
    enum {
        insertion_sort_threshold = 24,
        ninther_threshold = 128,
        partial_insertion_sort_limit = 8,
        block_size = 64,
        cacheline_size = 64
    };
    template<class T> struct is_default_compare : std::false_type { };
    template<class T> struct is_default_compare<std::less<T>> : std::true_type { };
    template<class T> struct is_default_compare<std::greater<T>> : std::true_type { };
    template<class T>
    inline int log2(T n) {
        int log = 0;
        while (n >>= 1) ++log;
        return log;
    }
    template<class Iter, class Compare>
    inline void id19(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;
        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter id20 = cur - 1;
            if (comp(*sift, *id20)) {
                T tmp = std::move(*sift);
                do { *sift-- = std::move(*id20); }
                while (sift != begin && comp(tmp, *--id20));
                *sift = std::move(tmp);
            }
        }
    }
    template<class Iter, class Compare>
    inline void id7(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;
        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter id20 = cur - 1;
            if (comp(*sift, *id20)) {
                T tmp = std::move(*sift);
                do { *sift-- = std::move(*id20); }
                while (comp(tmp, *--id20));
                *sift = std::move(tmp);
            }
        }
    }
    template<class Iter, class Compare>
    inline bool id21(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return true;
        int limit = 0;
        for (Iter cur = begin + 1; cur != end; ++cur) {
            if (limit > partial_insertion_sort_limit) return false;
            Iter sift = cur;
            Iter id20 = cur - 1;
            if (comp(*sift, *id20)) {
                T tmp = std::move(*sift);
                do { *sift-- = std::move(*id20); }
                while (sift != begin && comp(tmp, *--id20));
                *sift = std::move(tmp);
                limit += cur - sift;
            }
        }
        return true;
    }
    template<class Iter, class Compare>
    inline void sort2(Iter a, Iter b, Compare comp) {
        if (comp(*b, *a)) std::iter_swap(a, b);
    }
    template<class Iter, class Compare>
    inline void sort3(Iter a, Iter b, Iter c, Compare comp) {
        sort2(a, b, comp);
        sort2(b, c, comp);
        sort2(a, b, comp);
    }
    template<class T>
    inline T* id26(T* p) {
        std::size_t ip = reinterpret_cast<std::size_t>(p);
        ip = (ip + cacheline_size - 1) & -cacheline_size;
        return reinterpret_cast<T*>(ip);
    }
    template<class Iter>
    inline void swap_offsets(Iter first, Iter last,
                             unsigned char* id6, unsigned char* id24,
                             int num, bool id0) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (id0) {
            for (int i = 0; i < num; ++i) {
                std::iter_swap(first + id6[i], last - id24[i]);
            }
        } else if (num > 0) {
            Iter l = first + id6[0]; Iter r = last - id24[0];
            T tmp(std::move(*l)); *l = std::move(*r);
            for (int i = 1; i < num; ++i) {
                l = first + id6[i]; *r = std::move(*l);
                r = last - id24[i]; *l = std::move(*r);
            }
            *r = std::move(tmp);
        }
    }
    template<class Iter, class Compare>
    inline std::pair<Iter, bool> id27(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        T pivot(std::move(*begin));
        Iter first = begin;
        Iter last = end;
        while (comp(*++first, pivot));
        if (first - 1 == begin) while (first < last && !comp(*--last, pivot));
        else while ( !comp(*--last, pivot));
        bool id8 = first >= last;
        if (!id8) {
            std::iter_swap(first, last);
            ++first;
        }
        unsigned char offsets_l_storage[block_size + cacheline_size];
        unsigned char offsets_r_storage[block_size + cacheline_size];
        unsigned char* id6 = id26(offsets_l_storage);
        unsigned char* id24 = id26(offsets_r_storage);
        int num_l, num_r, start_l, start_r;
        num_l = num_r = start_l = start_r = 0;
        while (last - first > 2 * block_size) {
            if (num_l == 0) {
                start_l = 0;
                Iter it = first;
                for (unsigned char i = 0; i < block_size;) {
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                }
            }
            if (num_r == 0) {
                start_r = 0;
                Iter it = last;
                for (unsigned char i = 0; i < block_size;) {
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                    id24[num_r] = ++i; num_r += comp(*--it, pivot);
                }
            }
            int num = std::min(num_l, num_r);
            swap_offsets(first, last, id6 + start_l, id24 + start_r,
                         num, num_l == num_r);
            num_l -= num; num_r -= num;
            start_l += num; start_r += num;
            if (num_l == 0) first += block_size;
            if (num_r == 0) last -= block_size;
        }
        int l_size = 0, r_size = 0;
        int unknown_left = (last - first) - ((num_r || num_l) ? block_size : 0);
        if (num_r) {
            l_size = unknown_left;
            r_size = block_size;
        } else if (num_l) {
            l_size = block_size;
            r_size = unknown_left;
        } else {
            l_size = unknown_left/2;
            r_size = unknown_left - l_size;
        }
        if (unknown_left && !num_l) {
            start_l = 0;
            Iter it = first;
            for (unsigned char i = 0; i < l_size;) {
                id6[num_l] = i++; num_l += !comp(*it, pivot); ++it;
            }
        }
        if (unknown_left && !num_r) {
            start_r = 0;
            Iter it = last;
            for (unsigned char i = 0; i < r_size;) {
                id24[num_r] = ++i; num_r += comp(*--it, pivot);
            }
        }
        int num = std::min(num_l, num_r);
        swap_offsets(first, last, id6 + start_l, id24 + start_r, num, num_l == num_r);
        num_l -= num; num_r -= num;
        start_l += num; start_r += num;
        if (num_l == 0) first += l_size;
        if (num_r == 0) last -= r_size;
        if (num_l) {
            id6 += start_l;
            while (num_l--) std::iter_swap(first + id6[num_l], --last);
            first = last;
        }
        if (num_r) {
            id24 += start_r;
            while (num_r--) std::iter_swap(last - id24[num_r], first), ++first;
            last = first;
        }
        Iter pivot_pos = first - 1;
        *begin = std::move(*pivot_pos);
        *pivot_pos = std::move(pivot);
        return std::make_pair(pivot_pos, id8);
    }
    template<class Iter, class Compare>
    inline std::pair<Iter, bool> partition_right(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        T pivot(std::move(*begin));
        Iter first = begin;
        Iter last = end;
        while (comp(*++first, pivot));
        if (first - 1 == begin) while (first < last && !comp(*--last, pivot));
        else while ( !comp(*--last, pivot));
        bool id8 = first >= last;
        while (first < last) {
            std::iter_swap(first, last);
            while (comp(*++first, pivot));
            while (!comp(*--last, pivot));
        }
        Iter pivot_pos = first - 1;
        *begin = std::move(*pivot_pos);
        *pivot_pos = std::move(pivot);
        return std::make_pair(pivot_pos, id8);
    }
    template<class Iter, class Compare>
    inline Iter partition_left(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        T pivot(std::move(*begin));
        Iter first = begin;
        Iter last = end;
        while (comp(pivot, *--last));
        if (last + 1 == end) while (first < last && !comp(pivot, *++first));
        else while ( !comp(pivot, *++first));
        while (first < last) {
            std::iter_swap(first, last);
            while (comp(pivot, *--last));
            while (!comp(pivot, *++first));
        }
        Iter pivot_pos = last;
        *begin = std::move(*pivot_pos);
        *pivot_pos = std::move(pivot);
        return pivot_pos;
    }
    template<class Iter, class Compare, bool Branchless>
    inline void id9(Iter begin, Iter end, Compare comp, int bad_allowed, bool leftmost = true) {
        typedef typename std::iterator_traits<Iter>::difference_type diff_t;
        while (true) {
            diff_t size = end - begin;
            if (size < insertion_sort_threshold) {
                if (leftmost) id19(begin, end, comp);
                else id7(begin, end, comp);
                return;
            }
            diff_t s2 = size / 2;
            if (size > ninther_threshold) {
                sort3(begin, begin + s2, end - 1, comp);
                sort3(begin + 1, begin + (s2 - 1), end - 2, comp);
                sort3(begin + 2, begin + (s2 + 1), end - 3, comp);
                sort3(begin + (s2 - 1), begin + s2, begin + (s2 + 1), comp);
                std::iter_swap(begin, begin + s2);
            } else sort3(begin + s2, begin, end - 1, comp);
            if (!leftmost && !comp(*(begin - 1), *begin)) {
                begin = partition_left(begin, end, comp) + 1;
                continue;
            }
            std::pair<Iter, bool> part_result =
                Branchless ? id27(begin, end, comp)
                           : partition_right(begin, end, comp);
            Iter pivot_pos = part_result.first;
            bool id8 = part_result.second;
            diff_t l_size = pivot_pos - begin;
            diff_t r_size = end - (pivot_pos + 1);
            bool id12 = l_size < size / 8 || r_size < size / 8;
            if (id12) {
                if (--bad_allowed == 0) {
                    std::make_heap(begin, end, comp);
                    std::sort_heap(begin, end, comp);
                    return;
                }
                if (l_size >= insertion_sort_threshold) {
                    std::iter_swap(begin, begin + l_size / 4);
                    std::iter_swap(pivot_pos - 1, pivot_pos - l_size / 4);
                    if (l_size > ninther_threshold) {
                        std::iter_swap(begin + 1, begin + (l_size / 4 + 1));
                        std::iter_swap(begin + 2, begin + (l_size / 4 + 2));
                        std::iter_swap(pivot_pos - 2, pivot_pos - (l_size / 4 + 1));
                        std::iter_swap(pivot_pos - 3, pivot_pos - (l_size / 4 + 2));
                    }
                }
                if (r_size >= insertion_sort_threshold) {
                    std::iter_swap(pivot_pos + 1, pivot_pos + (1 + r_size / 4));
                    std::iter_swap(end - 1, end - r_size / 4);
                    if (r_size > ninther_threshold) {
                        std::iter_swap(pivot_pos + 2, pivot_pos + (2 + r_size / 4));
                        std::iter_swap(pivot_pos + 3, pivot_pos + (3 + r_size / 4));
                        std::iter_swap(end - 2, end - (1 + r_size / 4));
                        std::iter_swap(end - 3, end - (2 + r_size / 4));
                    }
                }
            } else {
                if (id8 && id21(begin, pivot_pos, comp)
                                        && id21(pivot_pos + 1, end, comp)) return;
            }
            id9<Iter, Compare, Branchless>(begin, pivot_pos, comp, bad_allowed, leftmost);
            begin = pivot_pos + 1;
            leftmost = false;
        }
    }
}
template<class Iter, class Compare>
inline void id17(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;
    pdqsort_detail::id9<Iter, Compare,
        pdqsort_detail::is_default_compare<typename std::decay<Compare>::type>::value &&
        std::is_arithmetic<typename std::iterator_traits<Iter>::value_type>::value>(
        begin, end, comp, pdqsort_detail::log2(end - begin));
}
template<class Iter>
inline void id17(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    id17(begin, end, std::less<T>());
}
template<class Iter, class Compare>
inline void id4(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;
    pdqsort_detail::id9<Iter, Compare, true>(
        begin, end, comp, pdqsort_detail::log2(end - begin));
}
template<class Iter>
inline void id4(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    id4(begin, end, std::less<T>());
}

namespace miller_rabin_internal {
  inline li mod_mul(li a, li b, li const& m){
    li r = 0;
    while(b) {
      if(b&1) {
        r = r+a;
        if(r>=m) r -= m;
      }
      a = a+a;
      if(a>=m) a -= m;
      b /= 2;
    }
    return r;
  }
  inline li mod_pow(li a, li b, li const& m){
    li r = 1;
    while(b){
      if(b&1) r = mod_mul(r, a, m);
      a = mod_mul(a, a, m);
      b /= 2;
    }
    return r;
  }
}
bool id15(li const& x, li base){
  if(x < 4) return x > 1;
  if(x%2 == 0) return 0;
  base%=x;
  if(base == 0) return 1;
  li xm1 = x-1;
  int j = 1;
  li d = xm1/2;
  while(d%2 == 0){
    d/=2;
    ++j;
  }
  li t = miller_rabin_internal::mod_pow(base, d, x);
  if(t == 1 || t == xm1) return 1;
  for(li k = (1); k <= (li)(j-1); ++k) {
    t = miller_rabin_internal::mod_mul(t, t, x);
    if(t == xm1) return 1;
    if(t <= 1) break;
  }
  return 0;
}
bool id23(li const&) { return 1; }
template<class... S>
bool id23(li const&x, li const& base, S const&... bases){
  if(!id15(x, base)) return 0;
  return id23(x, bases...);
}
bool is_prime(li const& x) {
  if(x < 316349281) return id23(x, 11000544, 31481107);
  if(x < 4759123141ll) return id23(x, 2, 7, 61);
  return id23(x, 2, 325, 9375, 28178, 450775, 9780504, 1795265022);
}
uint64_t id1(uint64_t const& x, uint64_t const& k, uint64_t const& it_max, uint32_t id18){
  if(__gcd((uint64_t)k, x) != 1) return __gcd((uint64_t)k, x);
  vector<uint16_t> saved;
  uint64_t scaledn = k*x;
  if(scaledn>>62) return 1;
  uint32_t id13 = isqrt(scaledn);
  uint32_t cutoff = isqrt(2*id13)/id18;
  uint32_t q0 = 1;
  uint32_t p1 = id13;
  uint32_t q1 = scaledn-p1*p1;
  if(q1 == 0){
    uint64_t factor = __gcd(x, (uint64_t)p1);
    return factor==x ? 1 : factor;
  }
  uint32_t multiplier = 2*k;
  uint32_t id16 = cutoff * multiplier;
  uint32_t i, j;
  uint32_t p0 = 0;
  uint32_t sqrtq = 0;
  for(i=0; i<it_max; ++i){
    uint32_t q, bits, tmp;
    tmp = id13 + p1 - q1;
    q = 1;
    if(tmp >= q1) q += tmp / q1;
    p0 = q * q1 - p1;
    q0 = q0 + (p1 - p0) * q;
    if(q1 < id16) {
      tmp = q1 / __gcd(q1, multiplier);
      if(tmp < cutoff) saved.push_back((uint16_t)tmp);
    }
    bits = 0;
    tmp = q0;
    while(!(tmp & 1)) {
      bits++;
      tmp >>= 1;
    }
    if(!(bits & 1) && ((tmp & 7) == 1)) {
      sqrtq = (uint32_t)isqrt(q0);
      if(sqrtq * sqrtq == q0) {
        for(j=0; j<saved.size(); ++j) if(saved[j] == sqrtq) break;
        if(j == saved.size()) break;
      }
    }
    tmp = id13 + p0 - q0;
    q = 1;
    if(tmp >= q0) q += tmp / q0;
    p1 = q * q0 - p0;
    q1 = q1 + (p0 - p1) * q;
    if(q0 < id16) {
      tmp = q0 / __gcd(q0, multiplier);
      if(tmp < cutoff) saved.push_back((uint16_t) tmp);
    }
  }
  if(sqrtq == 1) { return 1; }
  if(i == it_max) { return 1; }
  q0 = sqrtq;
  p1 = p0 + sqrtq * ((id13 - p0) / sqrtq);
  q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
  for(j=0; j<it_max; ++j) {
    uint32_t q, tmp;
    tmp = id13 + p1 - q1;
    q = 1;
    if(tmp >= q1) q += tmp / q1;
    p0 = q * q1 - p1;
    q0 = q0 + (p1 - p0) * q;
    if(p0 == p1) {
      q0 = q1;
      break;
    }
    tmp = id13 + p0 - q0;
    q = 1;
    if(tmp >= q0) q += tmp / q0;
    p1 = q * q0 - p0;
    q1 = q1 + (p0 - p1) * q;
    if(p0 == p1)
      break;
  }
  assert(j != it_max);
  uint64_t factor = __gcd((uint64_t)q0, x);
  if(factor == x) factor=1;
  return factor;
}
uint64_t id11(uint64_t const& x){
  static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
  uint64_t id14 = id28(x);
  if(id14*id14*id14 == x) return id14;
  uint32_t iter_lim = 300;
  for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
    for(uint32_t const& k : multipliers){
      if(numeric_limits<uint64_t>::max()/k <= x) continue;
      uint32_t const it_max = iter_fact*iter_lim;
      uint64_t factor = id1(x, k, it_max, 1);
      if(factor==1 || factor==x) continue;
      return factor;
    }
  }
  assert(false);
}
vector<li> factorize(li x){
  vector<li> ret;
  const uint32_t trial_limit = 5000;
  auto trial = [&](int i){while(x%i == 0){x/=i; ret.push_back(i);}};
  trial(2); trial(3);
  for(uint32_t i=5, j=2; i<trial_limit && i*i <= x; i+=j, j=6-j){
    trial(i);
  }
  if(x>1){
    static stack<li> s;
    s.push(x);
    while(!s.empty()){
      x = s.top(); s.pop();
      if(!is_prime(x)){
        li factor = id11(x);
        if(factor == 1 || factor == x){assert(0); return ret;}
        s.push(factor);
        s.push(x/factor);
      } else {
        ret.push_back(x);
      }
    }
  }
  id17(begin(ret), end(ret));
  return ret;
}
template<li M = 998244353>
struct Zn {
  static_assert(M > 2, "M > 2");
  static_assert(M < (1ll<<31), "M < (1ll<<31)");
  int value;
  Zn() : value(0) { }
  Zn(int x) : value(x%M) {
    if(value < 0) value += M;
  }
  Zn(li x) : value(x%M) {
    if(value < 0) value += M;
  }
  Zn& operator+=(Zn const& o) {
    value += o.value;
    if(value >= M) value -= M;
    return *this;
  }
  Zn& operator-=(Zn const& o) {
    value += M - o.value;
    if(value >= M) value -= M;
    return *this;
  }
  Zn& operator*=(Zn const& o) {
    value = ((li)value*(li)o.value)%M;
    return *this;
  }
  Zn& operator/=(Zn const& o) {
    return operator*=(o.inverse());
  }
  Zn operator-() const { Zn r; r.value = value ? M-value : 0; return r; }
  Zn operator+(Zn const& o) const { Zn r; r.value = value+o.value; if(r.value>=M) r.value -= M; return r; }
  Zn operator-(Zn const& o) const { Zn r; r.value = value+M-o.value; if(r.value>=M) r.value -= M; return r; }
  Zn operator*(Zn const& o) const { return Zn((li)value * (li)o.value); }
  Zn operator/(Zn const& o) const { Zn a = *this; a /= o; return a; }
  Zn inverse() const {
    int a = value, b = M, u = 0, v = 1;
    while (a != 0) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    return Zn(u);
  }
  bool operator==(Zn const& o) const { return value == o.value; }
  bool operator!=(Zn const& o) const { return value != o.value; }
  bool operator<(Zn const& o) const { return value < o.value; }
  bool operator>(Zn const& o) const { return value > o.value; }
  bool operator<=(Zn const& o) const { return value <= o.value; }
  bool operator>=(Zn const& o) const { return value >= o.value; }
};
template<li M>
Zn<M> pow(Zn<M> a, li b) {
  Zn<M> r = 1;
  while(b){
    if(b&1) r = r*a;
    a = a * a;
    b /= 2;
  }
  return r;
}
template<li M>
Zn<M> operator+(int const& x, Zn<M> const& o) { return Zn<M>(x) + o; }
template<li M>
Zn<M> operator+(li const& x, Zn<M> const& o) { return Zn<M>(x) + o; }
template<li M>
Zn<M> operator*(int const& x, Zn<M> const& o) { return Zn<M>(x) * o; }
template<li M>
Zn<M> operator*(li const& x, Zn<M> const& o) { return Zn<M>(x) * o; }
template<li M>
Zn<M> operator/(int const& x, Zn<M> const& o) { return Zn<M>(x) / o; }
template<li M>
Zn<M> operator/(li const& x, Zn<M> const& o) { return Zn<M>(x) / o; }
template<li M>
ostream& operator<<(ostream& ss, Zn<M> const& a) {
  return ss << a.value;
}
template<li M>
istream& operator>>(istream& ss, Zn<M> &a) {
  li x; ss>>x;
  a = Zn<M>(x);
  return ss;
}

using ZN = Zn<998244353>;
const int N = 1'000'000;
bool sieve[N];
li ddiv[N];
vector<li> id2(li x) {
  if(x > 900'000) {
    return factorize(x);
  }
  vector<li> res;
  while(x!=1) {res.emplace_back(ddiv[x]); x/=ddiv[x]; }
  return res;
}
ZN sub(li a2, li m2) {
  auto r = id2(a2);
  sort(begin(r), end(r));
  vi rr;
  for(auto x : r) if(rr.empty() || rr.back() != x) rr.emplace_back(x);
  int sz = rr.size();
  ZN cur = 0;
  auto bt = letrec([&](auto bt, int i, li p, li coeff) {
    if(i == sz) {
      cur += coeff * (m2 / p);
      return;
    }
    bt(i+1, p, coeff);
    bt(i+1, p * rr[i], -coeff);
  });
  bt(0,1,1);
  return cur;
}
void solve() {
  li n,m; cin>>n>>m;
  vi A(n); for(li i = 0; i < (li)(n); ++i) cin>>A[i];
  ZN ans = 1;
  for(li i = 0; i < (li)(n-1); ++i) {
    if(A[i] % A[i+1] != 0) { ans = 0; break; }
    else if(A[i+1] == A[i]){
      ans *= ZN(m / A[i+1]);
    }else{
      li a2 = A[i] / A[i+1];
      li m2 = m / A[i+1];
      ans *= sub(a2,m2);
    }
  }
  cout << ans << "\n";
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(li p = (2); p <= (li)(N-1); ++p) sieve[p] = 1;
  for(li p = (2); p <= (li)(N-1); ++p) if(sieve[p]){
    ddiv[p] = p;
    for(li k = 2*p; k < N; k += p) {
      sieve[k] = 0;
      ddiv[k] = p;
    }
  }
  li t; cin>>t; for(li t_ = 0; t_ < (li)(t); ++t_) solve();
  cout << flush;
  return 0;
}
