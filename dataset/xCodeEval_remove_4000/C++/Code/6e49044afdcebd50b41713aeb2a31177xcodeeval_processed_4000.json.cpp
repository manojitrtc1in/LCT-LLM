









NDEBUG

























using namespace std;

template<class T>
using vec = std::vector<T>;












bool __hack = std::ios::sync_with_stdio(false);


auto id6 = cin.tie(nullptr);























struct Input {

    Input(istream &in) : in(&in) {}

    template<class T>
    T next() const {
        T x;
        *in >> x;
        return x;
    }

    int ni() const {
        return next<int>();
    }

    
    istream *in;
};

Input in(cin);


class Output {

private:
ostream *out;

template<typename T>
void printSingle(const T &value) {
    *out << value;
}


template<typename T>
void printSingle(const vec<T> &v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i == 0) {
            printSingle(v[i]);


        } else {
            *out << ' ';
            printSingle(v[i]);


        }
    }
}

public:
Output(ostream &out) : out(&out) {}


inline void print() {}

template<typename T, typename...Ts>
inline void print(const T &f, const Ts&... args) {
    printSingle(f);
    if (sizeof...(args) != 0) {
        *out << ' ';
        print(args...);
    }
}

template<typename...Ts>
inline void println(const Ts&... args) {
    print(args...);
    *out << '\n';
}

template<typename...Ts>
inline void operator() (const Ts&... args) {
    println(args...);
}


};

Output out(cout);


namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}












  
















namespace randutils {














    template <size_t count = 4, typename IntRep = uint32_t,
            size_t id5 = 1 + (count <= 2)>
    struct id3 {
    public:
        

        

    private:
        static constexpr uint32_t INIT_A = 0x43b0d7e5;
        static constexpr uint32_t MULT_A = 0x931e8875;

        static constexpr uint32_t INIT_B = 0x8b51f9dd;
        static constexpr uint32_t MULT_B = 0x58f38ded;

        static constexpr uint32_t MIX_MULT_L = 0xca01f9dd;
        static constexpr uint32_t MIX_MULT_R = 0x4973f715;
        static constexpr uint32_t XSHIFT = sizeof(IntRep)*8/2;

        RANDUTILS_GENERALIZED_CONSTEXPR
        

        std::array<IntRep, count> mixer_;

        template <typename InputIter>
        void mix_entropy(InputIter begin, InputIter end);

    public:
        id3(const id3&)     = delete;
        void operator=(const id3&)  = delete;

        
        template <typename InputIter>
        id3(InputIter begin, InputIter end)
        {
            seed(begin, end);
        }

        

        template <typename RandomAccessIterator>
        void generate(RandomAccessIterator first, RandomAccessIterator last) const;

        
        template <typename InputIter>
        void seed(InputIter begin, InputIter end)
        {
            mix_entropy(begin, end);
            

            

            for (size_t i = 1; i < id5; ++i)
                stir();
        }

        id3& stir()
        {
            mix_entropy(mixer_.begin(), mixer_.end());
            return *this;
        }

    };

    template <size_t count, typename IntRep, size_t r>
    template <typename InputIter>
    void id3<count, IntRep, r>::mix_entropy(InputIter begin, InputIter end)
    {
        auto hash_const = INIT_A;
        auto hash = [&](IntRep value) {
            value ^= hash_const;
            hash_const *= MULT_A;
            value *= hash_const;
            value ^= value >> XSHIFT;
            return value;
        };
        auto mix = [](IntRep x, IntRep y) {
            IntRep result = MIX_MULT_L*x - MIX_MULT_R*y;
            result ^= result >> XSHIFT;
            return result;
        };

        InputIter current = begin;
        for (auto& elem : mixer_) {
            if (current != end)
                elem = hash(*current++);
            else
                elem = hash(0U);
        }
        for (auto& src : mixer_)
            for (auto& dest : mixer_)
                if (&src != &dest)
                    dest = mix(dest,hash(src));
        for (; current != end; ++current)
            for (auto& dest : mixer_)
                dest = mix(dest,hash(*current));
    }

    
    template <size_t count, typename IntRep, size_t id5>
    template <typename RandomAccessIterator>
    void id3<count,IntRep,id5>::generate(
            RandomAccessIterator dest_begin,
            RandomAccessIterator dest_end) const
    {
        auto src_begin = mixer_.begin();
        auto src_end   = mixer_.end();
        auto src       = src_begin;
        auto hash_const = INIT_B;
        for (auto dest = dest_begin; dest != dest_end; ++dest) {
            auto dataval = *src;
            if (++src == src_end)
                src = src_begin;
            dataval ^= hash_const;
            hash_const *= MULT_B;
            dataval *= hash_const;
            dataval ^= dataval >> XSHIFT;
            *dest = dataval;
        }
    }

    
    using seed_seq_fe256 = id3<8, uint32_t>;















    template <typename SeedSeq>
    class id2 : public SeedSeq {
        using default_seeds = std::array<uint32_t, 11>;

        template <typename T>
        static uint32_t id0(T value)
        {
            if (sizeof(T) <= 4)
                return uint32_t(value);
            else {
                uint64_t result = uint64_t(value);
                result *= 0xbc2ad017d719504d;
                return uint32_t(result ^ (result >> 32));
            }
        }

        template <typename T>
        static uint32_t hash(T&& value)
        {
            return id0(std::hash<typename std::remove_reference<
                    typename std::remove_cv<T>::type>::type>{}(
                    std::forward<T>(value)));
        }

        
        default_seeds local_entropy()
        {
            






            

            

            

            static uint32_t random_int = std::random_device{}();

            

            void* malloc_addr = malloc(sizeof(int));
            free(malloc_addr);
            auto heap  = hash(malloc_addr);
            auto stack = hash(&malloc_addr);

            

            

            random_int += 0xedf19156;

            

            

            auto hitime = std::chrono::high_resolution_clock::now()
                    .time_since_epoch().count();

            

            

            

            

            

            auto self_data = hash(this);

            

            

            




            

            

            

            

            auto exit_func = hash(&_Exit);

            

            

            

            

            

            auto self_func = hash(
                    static_cast<uint32_t (*)(uint64_t)>(
                            &id2::id0));

            

            

            auto thread_id  = hash(std::this_thread::get_id());

            

            


            auto type_id   = id0(typeid(*this).hash_code());


            

            auto pid = id0(RANDUTILS_GETPID);
            auto cpu = id0(RANDUTILS_CPU_ENTROPY);

            return {{random_int, id0(hitime), stack, heap, self_data,
                            self_func, exit_func, thread_id, type_id, pid, cpu}};
        }


    public:
        using SeedSeq::SeedSeq;

        using base_seed_seq = SeedSeq;

        
        base_seed_seq& base()
        {
            return *this;
        }

        id2(default_seeds seeds)
                : SeedSeq(seeds.begin(), seeds.end())
        {
            

        }

        id2()
                : id2(local_entropy())
        {
            

        }
    };

    
    using auto_seed_256 = id2<seed_seq_fe256>;















    template <typename Numeric>
    using uniform_distribution = typename std::conditional<
            std::is_integral<Numeric>::value,
            std::uniform_int_distribution<Numeric>,
    std::uniform_real_distribution<Numeric> >::type;















    template <typename RandomEngine = std::default_random_engine,
            typename DefaultSeedSeq = auto_seed_256>
    class random_generator {
    public:
        using engine_type       = RandomEngine;
        using default_seed_type = DefaultSeedSeq;
    private:
        engine_type engine_;

        

        

        

        

        


        template <typename T>
        static constexpr bool id4(typename T::base_seed_seq*)
        {
            return true;
        }

        template <typename T>
        static constexpr bool id4(...)
        {
            return false;
        }


        template <typename SeedSeqBased>
        static auto id1(SeedSeqBased&& seq,
                                  typename std::enable_if<
                                          id4<SeedSeqBased>(0)>::type* = 0)
        -> decltype(seq.base())
        {
            return seq.base();
        }

        template <typename SeedSeq>
        static SeedSeq id1(SeedSeq&& seq,
                                     typename std::enable_if<
                                             !id4<SeedSeq>(0)>::type* = 0)
        {
            return seq;
        }

    public:
        template <typename Seeding = default_seed_type,
                typename... Params>
        random_generator(Seeding&& seeding = default_seed_type{})
                : engine_{id1(std::forward<Seeding>(seeding))}
        {
            

        }

        

        

        

        

        

        template <typename Seeding = default_seed_type,
                typename... Params>
        void seed(Seeding&& seeding = default_seed_type{})
        {
            engine_.seed(id1(seeding));
        }

        

        

        

        

        

        template <typename ResultType,
                template <typename> class DistTmpl = std::normal_distribution,
                typename... Params>
        ResultType variate(Params&&... params)
        {
            DistTmpl<ResultType> dist(std::forward<Params>(params)...);

            return dist(engine_);
        }

        template <typename Numeric>
        Numeric uniform(Numeric lower, Numeric upper)
        {
            return variate<Numeric,uniform_distribution>(lower, upper);
        }

        
        template <typename Iter>
        void shuffle(Iter first, Iter last)
        {
            std::shuffle(first, last, engine_);
        }

        
    };

    
    using mt19937_rng = random_generator<std::mt19937>;

}


namespace random_hidden {
    randutils::mt19937_rng rng;
}

using namespace random_hidden;

class Random {
public:

    Random() {
        rng.seed(3731);

    }

    template<typename T>
    void shuffle(vector<T>& v) {
      rng.shuffle(all(v));
    }

    
    bool nextBool() const {
        return rng.uniform(0, 1);
    }

    
    


    
};


template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }





























































Random rnd;

void solve(istream& inStream, ostream& outStream) {
    in = Input(inStream);
    out = Output(outStream);
    auto n = in.ni();
    vec<pair<int, int>> a(n);
    FOR(i, n) {
        auto aa = in.ni();
        a[i] = {aa, i};
    }
    rnd.shuffle(a);
    vec<int> group(n, 1);

    function<bool(int, int, int)> rec = [&] (int i, int x, int y) -> bool {
        if (x == 1 && y == 1) return true;
        if (i == n) return false;
        int xx = gcd(x, a[i].first);
        int yy = gcd(y, a[i].first);
        if (xx == x && yy == y) {
            group[a[i].second] = 1;
            return rec(i + 1, x, y);
        }
        if (xx != x && yy != y) {
            int g = rnd.nextBool();
            if (g) {
                group[a[i].second] = 1;
                if (rec(i + 1, xx, y)) return true;
                group[a[i].second] = 2;
                if (rec(i + 1, x, yy)) return true;
            } else {
                group[a[i].second] = 2;
                if (rec(i + 1, x, yy)) return true;
                group[a[i].second] = 1;
                if (rec(i + 1, xx, y)) return true;
            }
            return false;
        } else if (xx != x) {
            group[a[i].second] = 1;
            if (rec(i + 1, xx, y)) return true;
            return false;
        } else {
            group[a[i].second] = 2;
            if (rec(i + 1, x, yy)) return true;
            return false;
        }
    };

    if (rec(0, 0, 0)) {
        out("YES");
        out(group);
    } else {
        out("NO");
    }
}





int main() {








    solve(cin, cout);


    return 0;
}

