

#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>
#include <bitset>

#include <x86intrin.h>
#include <cstdint>
#define assert

namespace qs {


void scalar_partition_epi32(uint32_t* array, const uint32_t pivot, int& left, int& right) {

    while (left <= right) {

        while (array[left] < pivot) {
            left += 1;
        }

        while (array[right] > pivot) {
            right -= 1;
        }

        if (left <= right) {
            const uint32_t t = array[left];
            array[left]      = array[right];
            array[right]     = t;

            left  += 1;
            right -= 1;
        }
    }
}

    namespace avx2 {

        __m256i bitmask_to_bytemask_epi32(uint8_t bm) {

            const __m256i mask = _mm256_set1_epi32(bm);
            const __m256i bits = _mm256_setr_epi32(0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80);
            const __m256i tmp  = _mm256_and_si256(mask, bits);

            return _mm256_cmpeq_epi32(tmp, bits);
        }


        void align_masks(uint8_t& a, uint8_t& b, uint8_t& rem_a, uint8_t& rem_b, __m256i& shuffle_a, __m256i& shuffle_b) {

            assert(a != 0);
            assert(b != 0);

            uint8_t tmpA = a;
            uint8_t tmpB = b;

            uint32_t __attribute__((__aligned__(32))) tmpshufa[8];
            uint32_t __attribute__((__aligned__(32))) tmpshufb[8];

            while (tmpA != 0 && tmpB != 0) {
                int idx_a = __builtin_ctz(tmpA);
                int idx_b = __builtin_ctz(tmpB);

                tmpA = tmpA & (tmpA - 1);
                tmpB = tmpB & (tmpB - 1);

                tmpshufb[idx_a] = idx_b;
                tmpshufa[idx_b] = idx_a;
            }

            a = a ^ tmpA;
            b = b ^ tmpB;

            assert(a != 0);
            assert(b != 0);
            assert(_mm_popcnt_u64(a) == _mm_popcnt_u64(b));

            rem_a = tmpA;
            rem_b = tmpB;

            shuffle_a = _mm256_load_si256((__m256i*)tmpshufa);
            shuffle_b = _mm256_load_si256((__m256i*)tmpshufb);
        }


        __m256i merge(const __m256i mask, const __m256i a, const __m256i b) {

            return _mm256_or_si256(
                    _mm256_and_si256(mask, a),
                    _mm256_andnot_si256(mask, b)
            );
        }


       void swap_epi32(
            __m256i& a, __m256i& b,
            uint8_t mask_a, const __m256i shuffle_a,
            uint8_t mask_b, const __m256i shuffle_b) {

            const __m256i to_swap_b = _mm256_permutevar8x32_epi32(a, shuffle_a);
            const __m256i to_swap_a = _mm256_permutevar8x32_epi32(b, shuffle_b);
            const __m256i ma    = bitmask_to_bytemask_epi32(mask_a);
            const __m256i mb    = bitmask_to_bytemask_epi32(mask_b);

            a = merge(ma, to_swap_a, a);
            b = merge(mb, to_swap_b, b);
        }



#define _mm256_iszero(vec) (_mm256_testz_si256(vec, vec) != 0)

        void partition_epi32(uint32_t* array, uint32_t pv, int& left, int& right) {

            const int N = 8; 


            __m256i L;
            __m256i R;
            uint8_t maskL = 0;
            uint8_t maskR = 0;

            const __m256i pivot = _mm256_set1_epi32(pv);

            int origL = left;
            int origR = right;

            while (true) {

                if (maskL == 0) {
                    while (true) {
                        if (right - (left + N) + 1 < 2*N) {
                            goto end;
                        }

                        L = _mm256_loadu_si256((__m256i*)(array + left));
                        const __m256i bytemask = _mm256_cmpgt_epi32(pivot, L);

                        if (_mm256_testc_ps((__m256)bytemask, (__m256)_mm256_set1_epi32(-1))) {
                            left += N;
                        } else {
                            maskL = ~_mm256_movemask_ps((__m256)bytemask);
                            break;
                        }
                    }

                }

                if (maskR == 0) {
                    while (true) {
                        if ((right - N) - left + 1 < 2*N) {
                            goto end;
                        }

                        R = _mm256_loadu_si256((__m256i*)(array + right - N + 1));
                        const __m256i bytemask = _mm256_cmpgt_epi32(pivot, R);
                        if (_mm256_iszero(bytemask)) {
                            right -= N;
                        } else {
                            maskR = _mm256_movemask_ps((__m256)bytemask);
                            break;
                        }
                    }

                }

                assert(left <= right);
                assert(maskL != 0);
                assert(maskR != 0);

                uint8_t mL;
                uint8_t mR;
                __m256i shuffleL;
                __m256i shuffleR;

                align_masks(maskL, maskR, mL, mR, shuffleL, shuffleR);
                swap_epi32(L, R, maskL, shuffleL, maskR, shuffleR);

                maskL = mL;
                maskR = mR;

                if (maskL == 0) {
                    _mm256_storeu_si256((__m256i*)(array + left), L);
                    left += N;
                }

                if (maskR == 0) {
                    _mm256_storeu_si256((__m256i*)(array + right - N + 1), R);
                    right -= N;
                }

            } 


        end:

            assert(!(maskL != 0 && maskR != 0));

            if (maskL != 0) {
                _mm256_storeu_si256((__m256i*)(array + left), L);
            } else if (maskR != 0) {
                _mm256_storeu_si256((__m256i*)(array + right - N + 1), R);
            }

            if (left < right) {
                int less    = 0;
                int greater = 0;
                const int all = right - left + 1;

                for (int i=left; i <= right; i++) {
                    less    += int(array[i] < pv);
                    greater += int(array[i] > pv);
                }

                if (all == less) {
                    

                    scalar_partition_epi32(array, pv, origL, left);
                } else if (all == greater) {
                    

                    scalar_partition_epi32(array, pv, left, origR);
                } else {
                    scalar_partition_epi32(array, pv, left, right);
                }
            }
        }

        void quicksort(uint32_t* array, int left, int right) {

            int i = left;
            int j = right;

            const uint32_t pivot = array[(i + j)/2];
            const int AVX2_REGISTER_SIZE = 8; 


            if (j - i >= 2 * AVX2_REGISTER_SIZE) {
                qs::avx2::partition_epi32(array, pivot, i, j);
            } else {
                scalar_partition_epi32(array, pivot, i, j);
            }

            if (left < j) {
                quicksort(array, left, j);
            }

            if (i < right) {
                quicksort(array, i, right);
            }
        }

    } 


} 


#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr < '0') {
        ++b;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 3e5;

#include <chrono>
struct Hash {
  static uint64_t& global_seed() { static uint64_t global_seed = chrono::steady_clock::now().time_since_epoch().count(); return global_seed; }

  Hash(uint64_t seed = 0) : seed{seed += global_seed() += 0x9e3779b97f4a7c15} {
  }

  size_t operator()(uint64_t x) const {
    x += seed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  const uint64_t seed;
};

struct HPII {
  Hash h;

  size_t operator()(const auto& pii) const {
    return h(int64_t(pii.first) << 32 ^ pii.second);
  }

  static auto dec(const auto& pii) {
    return uint64_t(pii.first) << 32 ^ pii.second;
  }
};


struct Bloom {
  static constexpr int am = 2;
  static constexpr int sz = 1 << 22;
  static constexpr __attribute__ ((vector_size (128))) uint64_t vsz{sz - 1, sz - 1};
  static constexpr __attribute__ ((vector_size (128))) uint64_t m1{0xbf58476d1ce4e5b9, 0xbf58476d1ce4e5b9};
  static constexpr __attribute__ ((vector_size (128))) uint64_t m2{0x94d049bb133111eb, 0x94d049bb133111eb};
  using T = pair<int, int>;
  using H = HPII;

  bitset<sz> a[am];
  H h[am];

#define $hsh \
    __attribute__ ((vector_size (128))) uint64_t val{HPII::dec(v) + h[0].h.seed, HPII::dec(v) + h[1].h.seed};\
    val ^= val >> 30;\
    val *= m1;\
    val ^= val >> 27;\
    val *= m2;\
    val &= vsz

  void insert(const T& v) {
    $hsh;
    a[0][val[0]] = 1;
    a[1][val[1]] = 1;
  }

  void erase(const T& v) {
    $hsh;
    a[0][val[0]] = 0;
    a[1][val[1]] = 0;
  }

  void clear() {
    for (int i = 0; i < am; ++i) {
      a[i].reset();
    }
  }

  bool contains(const T& v) const {
    $hsh;
    return a[0][val[0]] & a[1][val[1]];
  }
#undef $hsh
} forbidden;

auto canonize(auto pii) {
  return pair{min(pii.first, pii.second), max(pii.first, pii.second)};
}

bool check(auto pii) {
  return pii.first != pii.second && !forbidden.contains(canonize(pii));
}

int a[N];
pair<int, int> fb[N];
vector<int> c2v[N];

int main() {
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = $;
    int64_t ans = 0;
    reader(a, n);
    qs::avx2::quicksort(reinterpret_cast<uint32_t*>(a), 0, n - 1);
    reader(&fb[0].first, 2 * m);
    for (int i = 0; i < m; ++i) {
      forbidden.insert(fb[i]);
    }
    for (int i = 0; i < n; ) {
      int j = i;
      while (j < n && a[i] == a[j]) {
        ++j;
      }
      c2v[j - i].push_back(a[i]);
      i = j;
    }
    for (int i = n - 1; i > -1; ) {
      int j = i;
      while (j > -1 && a[i] == a[j]) {
        --j;
      }
      int cnt = i - j;
      for (int c = cnt; c; --c)
      for (int j = c2v[c].size(); j-- && (cnt + c) * int64_t(a[i] + c2v[c][j]) > ans; ) if (check(pair{a[i], c2v[c][j]})) {
        ans = (cnt + c) * int64_t(a[i] + c2v[c][j]);
      }
      i = j;
    }
    print(ans);
    if (testcase == 1) {
      break;
    }
    if (m >= Bloom::sz / 32) {
      forbidden.clear();
    } else {
      for (int i = 0; i < m; ++i) {
        forbidden.erase(fb[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      c2v[i].clear();
    }
  }
}
