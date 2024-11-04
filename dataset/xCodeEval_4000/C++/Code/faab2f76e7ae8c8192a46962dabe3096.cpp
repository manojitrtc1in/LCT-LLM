#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>

#define FOR(i, n) for (int i = 0; i < (n); ++i)


using namespace std;





bool __hack = std::ios::sync_with_stdio(false);


auto __hack1 = cin.tie(nullptr);


















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


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}







#include <cstddef>
#include <cstdint>
#include <cstdlib>


  

#include <initializer_list>
#include <utility>
#include <type_traits>
#include <iterator>
#include <chrono>
#include <thread>


#define RANDUTILS_CPU_ENTROPY 0

#define RANDUTILS_GETPID 0

#define RANDUTILS_GENERALIZED_CONSTEXPR


namespace randutils {














    template <size_t count = 4, typename IntRep = uint32_t,
            size_t mix_rounds = 1 + (count <= 2)>
    struct seed_seq_fe {
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
        seed_seq_fe(const seed_seq_fe&)     = delete;
        void operator=(const seed_seq_fe&)  = delete;

        
        template <typename InputIter>
        seed_seq_fe(InputIter begin, InputIter end)
        {
            seed(begin, end);
        }

        

        template <typename RandomAccessIterator>
        void generate(RandomAccessIterator first, RandomAccessIterator last) const;

        
        template <typename InputIter>
        void seed(InputIter begin, InputIter end)
        {
            mix_entropy(begin, end);
            

            

            for (size_t i = 1; i < mix_rounds; ++i)
                stir();
        }

        seed_seq_fe& stir()
        {
            mix_entropy(mixer_.begin(), mixer_.end());
            return *this;
        }

    };

    template <size_t count, typename IntRep, size_t r>
    template <typename InputIter>
    void seed_seq_fe<count, IntRep, r>::mix_entropy(InputIter begin, InputIter end)
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

    
    template <size_t count, typename IntRep, size_t mix_rounds>
    template <typename RandomAccessIterator>
    void seed_seq_fe<count,IntRep,mix_rounds>::generate(
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

    
    using seed_seq_fe256 = seed_seq_fe<8, uint32_t>;















    template <typename SeedSeq>
    class auto_seeded : public SeedSeq {
        using default_seeds = std::array<uint32_t, 11>;

        template <typename T>
        static uint32_t crushto32(T value)
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
            return crushto32(std::hash<typename std::remove_reference<
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
                            &auto_seeded::crushto32));

            

            

            auto thread_id  = hash(std::this_thread::get_id());

            

            


            auto type_id   = crushto32(typeid(*this).hash_code());


            

            auto pid = crushto32(RANDUTILS_GETPID);
            auto cpu = crushto32(RANDUTILS_CPU_ENTROPY);

            return {{random_int, crushto32(hitime), stack, heap, self_data,
                            self_func, exit_func, thread_id, type_id, pid, cpu}};
        }


    public:
        using SeedSeq::SeedSeq;

        using base_seed_seq = SeedSeq;

        
        base_seed_seq& base()
        {
            return *this;
        }

        auto_seeded(default_seeds seeds)
                : SeedSeq(seeds.begin(), seeds.end())
        {
            

        }

        auto_seeded()
                : auto_seeded(local_entropy())
        {
            

        }
    };

    
    using auto_seed_256 = auto_seeded<seed_seq_fe256>;















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
        static constexpr bool has_base_seed_seq(typename T::base_seed_seq*)
        {
            return true;
        }

        template <typename T>
        static constexpr bool has_base_seed_seq(...)
        {
            return false;
        }


        template <typename SeedSeqBased>
        static auto seed_seq_cast(SeedSeqBased&& seq,
                                  typename std::enable_if<
                                          has_base_seed_seq<SeedSeqBased>(0)>::type* = 0)
        -> decltype(seq.base())
        {
            return seq.base();
        }

        template <typename SeedSeq>
        static SeedSeq seed_seq_cast(SeedSeq&& seq,
                                     typename std::enable_if<
                                             !has_base_seed_seq<SeedSeq>(0)>::type* = 0)
        {
            return seq;
        }

    public:
        template <typename Seeding = default_seed_type,
                typename... Params>
        random_generator(Seeding&& seeding = default_seed_type{})
                : engine_{seed_seq_cast(std::forward<Seeding>(seeding))}
        {
            

        }

        

        

        

        

        

        template <typename Seeding = default_seed_type,
                typename... Params>
        void seed(Seeding&& seeding = default_seed_type{})
        {
            engine_.seed(seed_seq_cast(seeding));
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

    
    int getInt(const int up_to) const {
        return rng.uniform(0, up_to - 1);
    }

    
    


    
};

Random rnd;
typedef struct Node* tNode;

struct Node {
  int priority;
  int value;
  int id;
  int originalId;
  int upd = 0;
  tNode l, r;
};

void push(tNode it) {
  if (it && it->upd) {
    it->value += it->upd;
    if (it->l) it->l->upd += it->upd;
    if (it->r) it->r->upd += it->upd;
    it->upd = 0;
  }
}

void merge(tNode& t, tNode l, tNode r) {
  push(l);
  push(r);
  if (!l || !r)
    t = l ? l : r;
  else if (l->priority > r->priority)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
}

void split(tNode t, int key, tNode& l, tNode& r) {
  if (!t)
    return void(l = r = 0);
  push(t);
  if (key < t->value)
    split(t->l, key, l, t->l), r = t;
  else
    split(t->r, key, t->r, r), l = t;
}

tNode root;

const int MAX_NODES = 2000000;
Node memo[MAX_NODES];
int countNodes = 0;

tNode newNode(int value, int id) {
  tNode p = &memo[countNodes++];
  p->priority = rnd.getInt(1000000000);
  p->value = value;
  p->originalId = id;
  p->id = -1;
  return p;
}

vector<int> p;

void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto m = next<int>(in);
  root = NULL;

  FOR(i, n) {
    Node* t = newNode(i, i);
    merge(root, root, t);
  }
  set<int> leftIds;
  FOR(i, n) {
    leftIds.insert(i);
  }

  FOR(i, m) {
    int id = next<int>(in) - 1;
    int pos = next<int>(in) - 1;

    Node* t1;
    Node* t2;
    Node* t3;
    split(root, pos - 1, t1, t2);
    split(t2, pos, t2, t3);

    if (t2->id != -1) {
      if (t2->id != id) {
        out << "-1\n";
        return;
      }
    } else {
      if (!leftIds.count(id)) {
        out << "-1\n";
        return;
      }
      leftIds.erase(id);
      t2->id = id;
    }
    t2->value = 0;
    t2->upd = 0;
    if (t1) {
      t1->upd++;
    }
    merge(root, t2, t1);
    merge(root, root, t3);
  }

  p = vector<int>(n, -1);

  FOR(i, n) {
    Node* t1;
    split(root, i, t1, root);
    if (t1->id != -1) {
      p[t1->originalId] = t1->id;
    }
  }

  FOR(i, n) {
    if (p[i] == -1) {
      p[i] = *leftIds.begin();
      leftIds.erase(leftIds.begin());
    }
  }

  FOR(i, n) {
    out << p[i] + 1 << ' ';
  }
  out << "\n";

}






int main() {




    solve(cin, cout);


    return 0;
}
