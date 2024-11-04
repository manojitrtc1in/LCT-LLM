


























using __gnu_cxx::rope;
using std::bitset;
using std::cerr;
using std::deque;
using std::endl;
using std::fill;
using std::function;
using std::ios_base;
using std::istream;
using std::istream_iterator;
using std::iterator;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::sort;
using std::string;
using std::stringstream;
using std::swap;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::unordered_map;
using std::vector;
using std::reverse;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());







  {                                                    \
    std::cout << "Input file name:";                   \
    string file;                                       \
    std::cin >> file;                                  \
    if (file != "stdin") {                             \
      file = string(__FILE__) + "/../" + file + ".in"; \
      std::cout << "Open file:" << file << std::endl;  \
      freopen(file.data(), "r", stdin);                \
    }                                                  \
  }





  int main() {                                      \
    PREPARE_INPUT;                                  \
    std::ios_base::sync_with_stdio(false);          \
    std::cin.tie(0);                                \
    std::cout << std::setiosflags(std::ios::fixed); \
    std::cout << std::setprecision(15);             \
    solve(1, std::cin, std::cout);                  \
    return 0;                                       \
  }


  int main() {                                      \
    PREPARE_INPUT;                                  \
    std::ios_base::sync_with_stdio(false);          \
    std::cin.tie(0);                                \
    std::cout << std::setiosflags(std::ios::fixed); \
    std::cout << std::setprecision(15);             \
    int t;                                          \
    std::cin >> t;                                  \
    for (int i = 1; i <= t; i++) {                  \
      solve(i, std::cin, std::cout);                \
    }                                               \
    return 0;                                       \
  }



































namespace pretty_print
{
    namespace detail
    {
        


        struct sfinae_base
        {
            using yes = char;
            using no  = yes[2];
        };

        template <typename T>
        struct has_const_iterator : private sfinae_base
        {
        private:
            template <typename C> static yes & test(typename C::const_iterator*);
            template <typename C> static no  & test(...);
        public:
            static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
            using type =  T;
        };

        template <typename T>
        struct has_begin_end : private sfinae_base
        {
        private:
            template <typename C>
            static yes & f(typename std::enable_if<
                std::is_same<decltype(static_cast<typename C::const_iterator(C::*)() const>(&C::begin)),
                             typename C::const_iterator(C::*)() const>::value>::type *);

            template <typename C> static no & f(...);

            template <typename C>
            static yes & g(typename std::enable_if<
                std::is_same<decltype(static_cast<typename C::const_iterator(C::*)() const>(&C::end)),
                             typename C::const_iterator(C::*)() const>::value, void>::type*);

            template <typename C> static no & g(...);

        public:
            static bool const beg_value = sizeof(f<T>(nullptr)) == sizeof(yes);
            static bool const end_value = sizeof(g<T>(nullptr)) == sizeof(yes);
        };

    }  



    


    template <typename TChar>
    struct delimiters_values
    {
        using char_type = TChar;
        const char_type * prefix;
        const char_type * delimiter;
        const char_type * postfix;
    };


    


    template <typename T, typename TChar>
    struct delimiters
    {
        using type = delimiters_values<TChar>;
        static const type values; 
    };


    

    

    


    template <typename T,
              typename TChar = char,
              typename TCharTraits = ::std::char_traits<TChar>,
              typename TDelimiters = delimiters<T, TChar>>
    struct id0
    {
        using delimiters_type = TDelimiters;
        using ostream_type = std::basic_ostream<TChar, TCharTraits>;

        template <typename U>
        struct printer
        {
            static void print_body(const U & c, ostream_type & stream)
            {
                using std::begin;
                using std::end;

                auto it = begin(c);
                const auto the_end = end(c);

                if (it != the_end)
                {
                    for ( ; ; )
                    {
                        stream << *it;

                    if (++it == the_end) break;

                    if (delimiters_type::values.delimiter != NULL)
                        stream << delimiters_type::values.delimiter;
                    }
                }
            }
        };

        id0(const T & container)
        : container_(container)
        { }

        inline void operator()(ostream_type & stream) const
        {
            if (delimiters_type::values.prefix != NULL)
                stream << delimiters_type::values.prefix;

            printer<T>::print_body(container_, stream);

            if (delimiters_type::values.postfix != NULL)
                stream << delimiters_type::values.postfix;
        }

    private:
        const T & container_;
    };

    


    template <typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    template <typename T1, typename T2>
    struct id0<T, TChar, TCharTraits, TDelimiters>::printer<std::pair<T1, T2>>
    {
        using ostream_type = typename id0<T, TChar, TCharTraits, TDelimiters>::ostream_type;

        static void print_body(const std::pair<T1, T2> & c, ostream_type & stream)
        {
            stream << c.first;
            if (id0<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter != NULL)
                stream << id0<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter;
            stream << c.second;
        }
    };

    


    template <typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    template <typename ...Args>
    struct id0<T, TChar, TCharTraits, TDelimiters>::printer<std::tuple<Args...>>
    {
        using ostream_type = typename id0<T, TChar, TCharTraits, TDelimiters>::ostream_type;
        using element_type = std::tuple<Args...>;

        template <std::size_t I> struct Int { };

        static void print_body(const element_type & c, ostream_type & stream)
        {
            tuple_print(c, stream, Int<0>());
        }

        static void tuple_print(const element_type &, ostream_type &, Int<sizeof...(Args)>)
        {
        }

        static void tuple_print(const element_type & c, ostream_type & stream,
                                typename std::conditional<sizeof...(Args) != 0, Int<0>, std::nullptr_t>::type)
        {
            stream << std::get<0>(c);
            tuple_print(c, stream, Int<1>());
        }

        template <std::size_t N>
        static void tuple_print(const element_type & c, ostream_type & stream, Int<N>)
        {
            if (id0<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter != NULL)
                stream << id0<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter;

            stream << std::get<N>(c);

            tuple_print(c, stream, Int<N + 1>());
        }
    };

    


    template<typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    inline std::basic_ostream<TChar, TCharTraits> & operator<<(
        std::basic_ostream<TChar, TCharTraits> & stream,
        const id0<T, TChar, TCharTraits, TDelimiters> & helper)
    {
        helper(stream);
        return stream;
    }


    


    template <typename T>
    struct is_container : public std::integral_constant<bool,
                                                        detail::has_const_iterator<T>::value &&
                                                        detail::has_begin_end<T>::beg_value  &&
                                                        detail::has_begin_end<T>::end_value> { };

    template <typename T, std::size_t N>
    struct is_container<T[N]> : std::true_type { };

    template <std::size_t N>
    struct is_container<char[N]> : std::false_type { };

    template <typename T>
    struct is_container<std::valarray<T>> : std::true_type { };

    template <typename T1, typename T2>
    struct is_container<std::pair<T1, T2>> : std::true_type { };

    template <typename ...Args>
    struct is_container<std::tuple<Args...>> : std::true_type { };


    


    template <typename T> struct delimiters<T, char> { static const delimiters_values<char> values; };
    template <typename T> const delimiters_values<char> delimiters<T, char>::values = { "[", ", ", "]" };
    template <typename T> struct delimiters<T, wchar_t> { static const delimiters_values<wchar_t> values; };
    template <typename T> const delimiters_values<wchar_t> delimiters<T, wchar_t>::values = { L"[", L", ", L"]" };


    


    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::set<T, TComp, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::set<T, TComp, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::set<T, TComp, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::set<T, TComp, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::multiset<T, TComp, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::multiset<T, TComp, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename TComp, typename TAllocator>
    struct delimiters< ::std::multiset<T, TComp, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename TComp, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::multiset<T, TComp, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char> { static const delimiters_values<char> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<char> delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char>::values = { "{", ", ", "}" };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    struct delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

    template <typename T, typename THash, typename TEqual, typename TAllocator>
    const delimiters_values<wchar_t> delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };


    


    template <typename T1, typename T2> struct delimiters<std::pair<T1, T2>, char> { static const delimiters_values<char> values; };
    template <typename T1, typename T2> const delimiters_values<char> delimiters<std::pair<T1, T2>, char>::values = { "(", ", ", ")" };
    template <typename T1, typename T2> struct delimiters< ::std::pair<T1, T2>, wchar_t> { static const delimiters_values<wchar_t> values; };
    template <typename T1, typename T2> const delimiters_values<wchar_t> delimiters< ::std::pair<T1, T2>, wchar_t>::values = { L"(", L", ", L")" };

    template <typename ...Args> struct delimiters<std::tuple<Args...>, char> { static const delimiters_values<char> values; };
    template <typename ...Args> const delimiters_values<char> delimiters<std::tuple<Args...>, char>::values = { "(", ", ", ")" };
    template <typename ...Args> struct delimiters< ::std::tuple<Args...>, wchar_t> { static const delimiters_values<wchar_t> values; };
    template <typename ...Args> const delimiters_values<wchar_t> delimiters< ::std::tuple<Args...>, wchar_t>::values = { L"(", L", ", L")" };


    

    

    


    struct custom_delims_base
    {
        virtual ~custom_delims_base() { }
        virtual std::ostream & stream(::std::ostream &) = 0;
        virtual std::wostream & stream(::std::wostream &) = 0;
    };

    template <typename T, typename Delims>
    struct id3 : custom_delims_base
    {
        id3(const T & t_) : t(t_) { }

        std::ostream & stream(std::ostream & s)
        {
            return s << id0<T, char, std::char_traits<char>, Delims>(t);
        }

        std::wostream & stream(std::wostream & s)
        {
            return s << id0<T, wchar_t, std::char_traits<wchar_t>, Delims>(t);
        }

    private:
        const T & t;
    };

    template <typename Delims>
    struct id2
    {
        template <typename Container>
        id2(const Container & c) : base(new id3<Container, Delims>(c)) { }

        std::unique_ptr<custom_delims_base> base;
    };

    template <typename TChar, typename TCharTraits, typename Delims>
    inline std::basic_ostream<TChar, TCharTraits> & operator<<(std::basic_ostream<TChar, TCharTraits> & s, const id2<Delims> & p)
    {
        return p.base->stream(s);
    }


    

    


    template<typename T>
    struct id5
    {
        typedef const T * const_iterator;
        typedef T value_type;

        id5(const T * const a, size_t n) : _array(a), _n(n) { }
        inline const_iterator begin() const { return _array; }
        inline const_iterator end() const { return _array + _n; }

    private:
        const T * const _array;
        size_t _n;
    };


    

    


    template <typename T>
    struct id1
    {
        typedef typename T::const_local_iterator const_iterator;
        typedef typename T::size_type size_type;

        const_iterator begin() const
        {
            return m_map.cbegin(n);
        }

        const_iterator end() const
        {
            return m_map.cend(n);
        }

        id1(const T & m, size_type bucket) : m_map(m), n(bucket) { }

    private:
        const T & m_map;
        const size_type n;
    };

}   






template<typename T>
inline pretty_print::id5<T> id4(const T * const a, size_t n)
{
    return pretty_print::id5<T>(a, n);
}

template <typename T> pretty_print::id1<T>
bucket_print(const T & m, typename T::size_type n)
{
    return pretty_print::id1<T>(m, n);
}







namespace std
{
    


    template<typename T, typename TChar, typename TCharTraits>
    inline typename enable_if< ::pretty_print::is_container<T>::value,
                              basic_ostream<TChar, TCharTraits> &>::type
    operator<<(basic_ostream<TChar, TCharTraits> & stream, const T & container)
    {
        return stream << ::pretty_print::id0<T, TChar, TCharTraits>(container);
    }
}








  {                                          \
    string _s = 
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(std::istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(std::istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}









const int charset = 'z' - 'a' + 1;



namespace segment {
class Segment {
 public:
  Segment(int l, int r) {
    _dirty = 1e9;
    int m = (l + r) >> 1;
    if (l < r) {
      _l = new Segment(l, m);
      _r = new Segment(m + 1, r);
      pushUp();
    } else {
      _index = l;
    }
  }





  void update(int ql, int qr, int l, int r, int x) {
    if (NO_INTERSECTION) {
      return;
    }
    if (COVER) {
      modify(x);
      return;
    }
    pushDown();
    int m = (l + r) >> 1;
    _l->update(ql, qr, l, m, x);
    _r->update(ql, qr, m + 1, r, x);
    pushUp();
  }

  int query(int ql, int qr, int l, int r) {
    if (NO_INTERSECTION) {
      return 1e9;
    }
    if (COVER) {
      return _dirty + _index;
    }
    pushDown();
    int m = (l + r) >> 1;
    return min(_l->query(ql, qr, l, m), _r->query(ql, qr, m + 1, r));
  }




 private:
  Segment *_l, *_r;
  int _index;
  int _dirty;

  void modify(int d) { _dirty = min(_dirty, d); }

  void pushDown() {
    _l->modify(_dirty);
    _r->modify(_dirty);
  }

  void pushUp() {}
};
}  





using segment::Segment;

struct Node {
  Node() {
    memset(next, 0, sizeof(next));
    l = 0;
    r = 0;
    word = 0;
    dist = 0;
    c = 0;
    parent = 0;
  }

  int l;
  int r;
  bool word;
  int dist;
  char c;
  Node *parent;
  Node *next[charset];
  Node *get(int i) {
    if (next[i] == 0) {
      next[i] = new Node();
      next[i]->c = i + 'a';
      next[i]->parent = this;
    }
    return next[i];
  }

  string to_string(){
    if(parent == 0){
      return "";
    }
    return parent->to_string() + c;
  }

};

int order = 0;
void dfs(Node *root) {
  if (root == 0) {
    return;
  }
  if (root->word) {
    root->l = order++;
  } else {
    root->l = order;
  }
  for (int i = 0; i < charset; i++) {
    dfs(root->next[i]);
  }
  root->r = order - 1;
}

void dfs2(Node *root, Segment *seg, int step) {
  if (root == 0) {
    return;
  }
  if (root->word) {
    step = min(step, seg->query(root->l, root->l, 0, order));
    root->dist = step;
  }
  int plus = 0;
  if (root->word) {
    plus++;
  }
  seg->update(root->l, root->r, 0, order, plus + step + 1 - root->l);
  for (int i = 0; i < charset; i++) {
    dfs2(root->next[i], seg, step + 1);
  }
}

void solve(int testId, istream &in, ostream &out) {
  int n;
  in >> n;
  vector<Node *> nodes(n + 1);
  nodes[0] = new Node();
  for (int i = 1; i <= n; i++) {
    int last;
    char c;
    in >> last >> c;
    nodes[i] = nodes[last]->get(c - 'a');
  }
  int k;
  in >> k;
  vector<Node *> qs(k);
  for (int i = 0; i < k; i++) {
    int x;
    in >> x;
    qs[i] = nodes[x];
    qs[i]->word = true;
    

  }

  dbg(0, order);
  dfs(nodes[0]);
  Segment *seg = new Segment(0, order);
  dfs2(nodes[0], seg, 0);
  for (int i = 0; i < k; i++) {
    out << qs[i]->dist << endl;
  }
}

RUN_ONCE