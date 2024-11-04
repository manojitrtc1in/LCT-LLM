


 
 
 






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
class id21 {
  Fun fun_;
  public:
    template<class T>
    explicit id21(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(ref(*this), forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) letrec(Fun &&fun) {
  return id21<decay_t<Fun>>(forward<Fun>(fun));
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
decltype(auto) id19(Fun &&fun) {
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
T id25(T const&x) {
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
    inline void id14(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;

        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter id16 = cur - 1;


            if (comp(*sift, *id16)) {
                T tmp = std::move(*sift);

                do { *sift-- = std::move(*id16); }
                while (sift != begin && comp(tmp, *--id16));

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
            Iter id16 = cur - 1;


            if (comp(*sift, *id16)) {
                T tmp = std::move(*sift);

                do { *sift-- = std::move(*id16); }
                while (comp(tmp, *--id16));

                *sift = std::move(tmp);
            }
        }
    }




    template<class Iter, class Compare>
    inline bool id18(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return true;

        int limit = 0;
        for (Iter cur = begin + 1; cur != end; ++cur) {
            if (limit > partial_insertion_sort_limit) return false;

            Iter sift = cur;
            Iter id16 = cur - 1;


            if (comp(*sift, *id16)) {
                T tmp = std::move(*sift);

                do { *sift-- = std::move(*id16); }
                while (sift != begin && comp(tmp, *--id16));

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
    inline T* id22(T* p) {



        std::size_t ip = reinterpret_cast<std::size_t>(p);

        ip = (ip + cacheline_size - 1) & -cacheline_size;
        return reinterpret_cast<T*>(ip);
    }

    template<class Iter>
    inline void swap_offsets(Iter first, Iter last,
                             unsigned char* id6, unsigned char* id20,
                             int num, bool id0) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (id0) {


            for (int i = 0; i < num; ++i) {
                std::iter_swap(first + id6[i], last - id20[i]);
            }
        } else if (num > 0) {
            Iter l = first + id6[0]; Iter r = last - id20[0];
            T tmp(std::move(*l)); *l = std::move(*r);
            for (int i = 1; i < num; ++i) {
                l = first + id6[i]; *r = std::move(*l);
                r = last - id20[i]; *l = std::move(*r);
            }
            *r = std::move(tmp);
        }
    }






    template<class Iter, class Compare>
    inline std::pair<Iter, bool> id24(Iter begin, Iter end, Compare comp) {
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
        unsigned char* id6 = id22(offsets_l_storage);
        unsigned char* id20 = id22(offsets_r_storage);
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
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                    id20[num_r] = ++i; num_r += comp(*--it, pivot);
                }
            }


            int num = std::min(num_l, num_r);
            swap_offsets(first, last, id6 + start_l, id20 + start_r,
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
                id20[num_r] = ++i; num_r += comp(*--it, pivot);
            }
        }

        int num = std::min(num_l, num_r);
        swap_offsets(first, last, id6 + start_l, id20 + start_r, num, num_l == num_r);
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
            id20 += start_r;
            while (num_r--) std::iter_swap(last - id20[num_r], first), ++first;
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
                if (leftmost) id14(begin, end, comp);
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
                Branchless ? id24(begin, end, comp)
                           : partition_right(begin, end, comp);
            Iter pivot_pos = part_result.first;
            bool id8 = part_result.second;


            diff_t l_size = pivot_pos - begin;
            diff_t r_size = end - (pivot_pos + 1);
            bool id11 = l_size < size / 8 || r_size < size / 8;


            if (id11) {

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


                if (id8 && id18(begin, pivot_pos, comp)
                                        && id18(pivot_pos + 1, end, comp)) return;
            }



            id9<Iter, Compare, Branchless>(begin, pivot_pos, comp, bad_allowed, leftmost);
            begin = pivot_pos + 1;
            leftmost = false;
        }
    }
}


template<class Iter, class Compare>
inline void id13(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;


    pdqsort_detail::id9<Iter, Compare,
        pdqsort_detail::is_default_compare<typename std::decay<Compare>::type>::value &&
        std::is_arithmetic<typename std::iterator_traits<Iter>::value_type>::value>(
        begin, end, comp, pdqsort_detail::log2(end - begin));




}

template<class Iter>
inline void id13(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    id13(begin, end, std::less<T>());
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

const li N = 1<<20;
const li C = 70;
li n;
li A[N];
li col[N];

li ul[N], ur[N], dl[N], dr[N];

template<class IT, class F>
IT bsearch(IT lo, IT hi, F&& f) {
  IT it;
  typename iterator_traits<IT>::difference_type sz, step;
  sz = distance(lo,hi);
  while(sz>0) {
    it = lo; step = sz/2; advance(it, step);
    if(!f(*it)){
      lo = ++it;
      sz -= step+1;
    }else{
      sz = step;
    }
  }
  return lo;
}

li read_positive(){
  char c; li x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  n=read_positive();

  for(li i = 0; i < (li)(n); ++i) A[i]=read_positive();
  for(li i = 0; i < (li)(n); ++i) col[i] = __builtin_popcountll(A[i]);
  li tot=0;

  { vi I(n); iota(begin(I), end(I),0);
    id13(begin(I), end(I), [&](int i, int j){ return A[i]<A[j]; });
    for(li i = 0; i < (li)(n); ++i) A[I[i]] = i;
  }

  auto id2 = [&](){
    { vi stk;
      for(li i = 0; i < (li)(n); ++i) {
        while(!stk.empty() && A[stk.back()] > A[i]) stk.pop_back();
        dl[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
      }
    }
    { vi stk;
      for(li i = 0; i < (li)(n); ++i) {
        while(!stk.empty() && A[stk.back()] < A[i]) stk.pop_back();
        ul[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
      }
    }
    { vi stk;
      for(li i = (n-1); i >= (li)(0); --i) {
        while(!stk.empty() && A[stk.back()] > A[i]) stk.pop_back();
        dr[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
      }
    }
    { vi stk;
      for(li i = (n-1); i >= (li)(0); --i) {
        while(!stk.empty() && A[stk.back()] < A[i]) stk.pop_back();
        ur[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
      }
    }
  };
  id2();

  for(li k = 0; k < (li)(2); ++k) {
    for(li i = 0; i < (li)(n); ++i) A[i]=n-1-A[i];

    { vi stk;
      for(li i = 0; i < (li)(n); ++i) {
        while(!stk.empty() && A[stk.back()] >= A[i]) stk.pop_back();
        dl[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
      }
    }
    { vi stk;
      for(li i = 0; i < (li)(n); ++i) {
        while(!stk.empty() && A[stk.back()] <= A[i]) stk.pop_back();
        ul[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
      }
    }
    { vi stk;
      for(li i = (n-1); i >= (li)(0); --i) {
        while(!stk.empty() && A[stk.back()] >= A[i]) stk.pop_back();
        dr[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
      }
    }
    { vi stk;
      for(li i = (n-1); i >= (li)(0); --i) {
        while(!stk.empty() && A[stk.back()] <= A[i]) stk.pop_back();
        ur[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
      }
    }

    vi stk;
    vvi stks(C);
    vvi id17(C,{0});
    vvi id23(C,{0});
    vvi id12(C,{0});
    vvi id1(C,{0});
    vvi id15(C,{0});

    for(li j = 0; j < (li)(n); ++j) {
      while(!stk.empty() && A[stk.back()] > A[j]) {
        int k = stk.back(); stk.pop_back();
        stks[col[k]].pop_back();
        id17[col[k]].pop_back();
        id23[col[k]].pop_back();
        id12[col[k]].pop_back();
        id1[col[k]].pop_back();
        id15[col[k]].pop_back();
      }

      int x0 = distance(begin(stks[col[j]]), bsearch(begin(stks[col[j]]), end(stks[col[j]]), [&](int i){
        return i >= ul[j];
      }));
      int x1 = distance(begin(stks[col[j]]), bsearch(begin(stks[col[j]]), end(stks[col[j]]), [&](int i){
        return dl[i] > ul[j];
      }));
      smax(x1,x0);
      int x2 = distance(begin(stks[col[j]]), bsearch(begin(stks[col[j]]), end(stks[col[j]]), [&](int i){
        return dr[i] < ur[j];
      }));
      smax(x2,x0);

      if(x0 < min(x1,x2)) {

        int fr = x0, to = min(x1,x2);
        tot += (id17[col[j]][to]-id17[col[j]][fr]) * (ur[j]-j)
          - (to-fr) * ul[j] * (ur[j]-j);
      }
      if(max(x0,x1) < x2) {

        int fr = max(x0,x1), to = x2;
        tot += (id23[col[j]][to]-id23[col[j]][fr]) * (ur[j]-j);
      }
      if(max(x0,x2) < x1) {

        int fr = max(x0,x2), to = x1;
        tot += (id12[col[j]][to]-id12[col[j]][fr])
          - (id17[col[j]][to]-id17[col[j]][fr]) * j
          - (id15[col[j]][to]-id15[col[j]][fr]) * ul[j]
          + (to-fr)*j*ul[j];
      }
      if(max(x1,x2) < (int)stks[col[j]].size()) {

        int fr = max(x1,x2), to = stks[col[j]].size();
        tot += (id1[col[j]][to]-id1[col[j]][fr])
          - (id23[col[j]][to]-id23[col[j]][fr]) * j;
      }


      stk.emplace_back(j);
      stks[col[j]].emplace_back(j);
      id17[col[j]].emplace_back(id17[col[j]].back() + (j));
      id23[col[j]].emplace_back(id23[col[j]].back() + (j-dl[j]));
      id12[col[j]].emplace_back(id12[col[j]].back() + (j)*dr[j]);
      id1[col[j]].emplace_back(id1[col[j]].back() + (j-dl[j])*dr[j]);
      id15[col[j]].emplace_back(id15[col[j]].back() + dr[j]);
    }
  }
  cout << tot+n << endl;

  return 0;
}
