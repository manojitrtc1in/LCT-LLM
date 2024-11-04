



using namespace std;
namespace fast_sort {
















using namespace std;

namespace detail
{

template<typename count_type, typename It, typename OutIt, typename ExtractKey>
void id22(It begin, It end, OutIt out_begin, ExtractKey &&extract_key) {
  count_type counts[256] = {};
  for (It it = begin; it != end; ++it)
    ++counts[extract_key(*it)];
  count_type total = 0;
  for (count_type &count: counts) {
    count_type old_count = count;
    count = total;
    total += old_count;
  }
  for (; begin != end; ++begin) {
    uint8_t key = extract_key(*begin);
    out_begin[counts[key]++] = move(*begin);
  }
}
template<typename It, typename OutIt, typename ExtractKey>
void id22(It begin, It end, OutIt out_begin, ExtractKey && extract_key) {
  id22<uint64_t>(begin, end, out_begin, extract_key);
}

inline bool id16(bool b) { return b; }
inline unsigned char id16(unsigned char c) { return c; }
inline unsigned char id16(signed char c) { return static_cast<unsigned char>(c) + 128; }
inline unsigned char id16(char c) { return static_cast<unsigned char>(c); }
inline uint16_t id16(char16_t c) { return static_cast<uint16_t>(c); }
inline uint32_t id16(char32_t c) { return static_cast<uint32_t>(c); }
inline uint32_t id16(id21 c) { return static_cast<uint32_t>(c); }
inline unsigned short id16(short i) { return static_cast<unsigned short>(i) + static_cast<unsigned short>(1 << (sizeof(short) * 8 - 1)); }
inline unsigned short id16(unsigned short i) { return i; }
inline unsigned int id16(int i) { return static_cast<unsigned int>(i) + static_cast<unsigned int>(1 << (sizeof(int) * 8 - 1)); }
inline unsigned int id16(unsigned int i) { return i; }
inline unsigned long id16(long l) { return static_cast<unsigned long>(l) + static_cast<unsigned long>(1l << (sizeof(long) * 8 - 1)); }
inline unsigned long id16(unsigned long l) { return l; }
inline unsigned long long id16(long long l) { return static_cast<unsigned long long>(l) + static_cast<unsigned long long>(1ll << (sizeof(long long) * 8 - 1)); }
inline unsigned long long id16(unsigned long long l) { return l; }
inline uint32_t id16(float f) {
  union { float f; uint32_t u; } as_union = { f };
  uint32_t sign_bit = -int32_t(as_union.u >> 31);
  return as_union.u ^ (sign_bit | 0x80000000);
}
inline uint64_t id16(double f) {
  union { double d; uint64_t u; } as_union = { f };
  uint64_t sign_bit = -int64_t(as_union.u >> 63);
  return as_union.u ^ (sign_bit | 0x8000000000000000);
}
template<typename T>
inline size_t id16(T * ptr) {
  return reinterpret_cast<size_t>(ptr);
}
template<size_t>
struct SizedRadixSorter;
template<>
struct SizedRadixSorter<1> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey &&extract_key) {
    id22(begin, end, buffer_begin, [&](auto &&o) {
      return id16(extract_key(o));
    });
    return true;
  }
  static constexpr size_t pass_count = 2;
};
template<>
struct SizedRadixSorter<2> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey &&extract_key) {
    ptrdiff_t num_elements = end - begin;
    if (num_elements <= (1ll << 32))
      return sort_inline<uint32_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
    else
      return sort_inline<uint64_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
  }
  template<typename count_type, typename It, typename OutIt, typename ExtractKey>
  static bool sort_inline(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key) {
    count_type counts0[256] = { };
    count_type counts1[256] = { };
    for (It it = begin; it != end; ++it) {
      uint16_t key = id16(extract_key(*it));
      ++counts0[key & 0xff];
      ++counts1[(key >> 8) & 0xff];
    }
    count_type total0 = 0;
    count_type total1 = 0;
    for (int i = 0; i < 256; ++i) {
      count_type id18 = counts0[i];
      count_type id0 = counts1[i];
      counts0[i] = total0;
      counts1[i] = total1;
      total0 += id18;
      total1 += id0;
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it));
      out_begin[counts0[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 8;
      begin[counts1[key]++] = move(*it);
    }
    return false;
  }
  static constexpr size_t pass_count = 3;
};
template<>
struct SizedRadixSorter<4> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    ptrdiff_t num_elements = end - begin;
    if (num_elements <= (1ll << 32))
      return sort_inline<uint32_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
    else
      return sort_inline<uint64_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
  }
  template<typename count_type, typename It, typename OutIt, typename ExtractKey>
  static bool sort_inline(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key) {
    count_type counts0[256] = { };
    count_type counts1[256] = { };
    count_type counts2[256] = { };
    count_type counts3[256] = { };
    for (It it = begin; it != end; ++it) {
      uint32_t key = id16(extract_key(*it));
      ++counts0[key & 0xff];
      ++counts1[(key >> 8) & 0xff];
      ++counts2[(key >> 16) & 0xff];
      ++counts3[(key >> 24) & 0xff];
    }
    count_type total0 = 0;
    count_type total1 = 0;
    count_type total2 = 0;
    count_type total3 = 0;
    for (int i = 0; i < 256; ++i) {
      count_type id18 = counts0[i];
      count_type id0 = counts1[i];
      count_type id27 = counts2[i];
      count_type id17 = counts3[i];
      counts0[i] = total0;
      counts1[i] = total1;
      counts2[i] = total2;
      counts3[i] = total3;
      total0 += id18;
      total1 += id0;
      total2 += id27;
      total3 += id17;
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it));
      out_begin[counts0[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 8;
      begin[counts1[key]++] = move(*it);
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 16;
      out_begin[counts2[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 24;
      begin[counts3[key]++] = move(*it);
    }
    return false;
  }
  static constexpr size_t pass_count = 5;
};
template<>
struct SizedRadixSorter<8> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    ptrdiff_t num_elements = end - begin;
    if (num_elements <= (1ll << 32))
      return sort_inline<uint32_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
    else
      return sort_inline<uint64_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
  }
  template<typename count_type, typename It, typename OutIt, typename ExtractKey>
  static bool sort_inline(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key) {
    count_type counts0[256] = { };
    count_type counts1[256] = { };
    count_type counts2[256] = { };
    count_type counts3[256] = { };
    count_type counts4[256] = { };
    count_type counts5[256] = { };
    count_type counts6[256] = { };
    count_type counts7[256] = { };
    for (It it = begin; it != end; ++it) {
      uint64_t key = id16(extract_key(*it));
      ++counts0[key & 0xff];
      ++counts1[(key >> 8) & 0xff];
      ++counts2[(key >> 16) & 0xff];
      ++counts3[(key >> 24) & 0xff];
      ++counts4[(key >> 32) & 0xff];
      ++counts5[(key >> 40) & 0xff];
      ++counts6[(key >> 48) & 0xff];
      ++counts7[(key >> 56) & 0xff];
    }
    count_type total0 = 0;
    count_type total1 = 0;
    count_type total2 = 0;
    count_type total3 = 0;
    count_type total4 = 0;
    count_type total5 = 0;
    count_type total6 = 0;
    count_type total7 = 0;
    for (int i = 0; i < 256; ++i) {
      count_type id18 = counts0[i];
      count_type id0 = counts1[i];
      count_type id27 = counts2[i];
      count_type id17 = counts3[i];
      count_type id26 = counts4[i];
      count_type id30 = counts5[i];
      count_type id12 = counts6[i];
      count_type id19 = counts7[i];
      counts0[i] = total0;
      counts1[i] = total1;
      counts2[i] = total2;
      counts3[i] = total3;
      counts4[i] = total4;
      counts5[i] = total5;
      counts6[i] = total6;
      counts7[i] = total7;
      total0 += id18;
      total1 += id0;
      total2 += id27;
      total3 += id17;
      total4 += id26;
      total5 += id30;
      total6 += id12;
      total7 += id19;
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it));
      out_begin[counts0[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 8;
      begin[counts1[key]++] = move(*it);
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 16;
      out_begin[counts2[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 24;
      begin[counts3[key]++] = move(*it);
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 32;
      out_begin[counts4[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 40;
      begin[counts5[key]++] = move(*it);
    }
    for (It it = begin; it != end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 48;
      out_begin[counts6[key]++] = move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
      uint8_t key = id16(extract_key(*it)) >> 56;
      begin[counts7[key]++] = move(*it);
    }
    return false;
  }
  static constexpr size_t pass_count = 9;
};

template<typename>
struct RadixSorter;
template<>
struct RadixSorter<bool>{
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    size_t false_count = 0;
    for (It it = begin; it != end; ++it)
      if (!extract_key(*it)) ++false_count;
    size_t true_position = false_count;
    false_count = 0;
    for (; begin != end; ++begin)
      if (extract_key(*begin)) buffer_begin[true_position++] = move(*begin);
      else buffer_begin[false_count++] = move(*begin);
    return true;
  }
  static constexpr size_t pass_count = 2;
};
template<>struct RadixSorter<signed char> : SizedRadixSorter<sizeof(signed char)> {};
template<>struct RadixSorter<unsigned char> : SizedRadixSorter<sizeof(unsigned char)> {};
template<>struct RadixSorter<signed short> : SizedRadixSorter<sizeof(signed short)> {};
template<>struct RadixSorter<unsigned short> : SizedRadixSorter<sizeof(unsigned short)> {};
template<>struct RadixSorter<signed int> : SizedRadixSorter<sizeof(signed int)> {};
template<>struct RadixSorter<unsigned int> : SizedRadixSorter<sizeof(unsigned int)> {};
template<>struct RadixSorter<signed long> : SizedRadixSorter<sizeof(signed long)> {};
template<>struct RadixSorter<unsigned long> : SizedRadixSorter<sizeof(unsigned long)> {};
template<>struct RadixSorter<signed long long> : SizedRadixSorter<sizeof(signed long long)> {};
template<>struct RadixSorter<unsigned long long> : SizedRadixSorter<sizeof(unsigned long long)> {};
template<>
struct RadixSorter<float> : SizedRadixSorter<sizeof(float)> {};
template<>
struct RadixSorter<double> : SizedRadixSorter<sizeof(double)> {};
template<>
struct RadixSorter<char> : SizedRadixSorter<sizeof(char)> {};
template<>
struct RadixSorter<id21> : SizedRadixSorter<sizeof(id21)> {};
template<>
struct RadixSorter<char16_t> : SizedRadixSorter<sizeof(char16_t)> {};
template<>
struct RadixSorter<char32_t> : SizedRadixSorter<sizeof(char32_t)> {};
template<typename K, typename V>
struct RadixSorter<pair<K, V>> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    bool first_result = RadixSorter<V>::sort(begin, end, buffer_begin, [&](auto &&o) {
      return extract_key(o).second;
    });
    auto extract_first = [&](auto && o) {
      return extract_key(o).first;
    };
    if (first_result) return !RadixSorter<K>::sort(buffer_begin, buffer_begin + (end - begin), begin, extract_first);
    else return RadixSorter<K>::sort(begin, end, buffer_begin, extract_first);
  }
  static constexpr size_t pass_count = RadixSorter<K>::pass_count + RadixSorter<V>::pass_count;
};
template<typename K, typename V>
struct RadixSorter<const pair<K, V> &> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    bool first_result = RadixSorter<V>::sort(begin, end, buffer_begin, [&](auto &&o)->const V & {
      return extract_key(o).second;
    });
    auto extract_first = [&](auto &&o)->const K & {
      return extract_key(o).first;
    };
    if (first_result) return !RadixSorter<K>::sort(buffer_begin, buffer_begin + (end - begin), begin, extract_first);
    else return RadixSorter<K>::sort(begin, end, buffer_begin, extract_first);
  }
  static constexpr size_t pass_count = RadixSorter<K>::pass_count + RadixSorter<V>::pass_count;
};
template<size_t I, size_t S, typename Tuple>
struct TupleRadixSorter {
  using NextSorter = TupleRadixSorter<I + 1, S, Tuple>;
  using ThisSorter = RadixSorter<typename tuple_element<I, Tuple>::type>;
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key) {
    bool which = NextSorter::sort(begin, end, out_begin, out_end, extract_key);
    auto extract_i = [&](auto && o) {
      return get<I>(extract_key(o));
    };
    if (which) return !ThisSorter::sort(out_begin, out_end, begin, extract_i);
    else return ThisSorter::sort(begin, end, out_begin, extract_i);
  }
  static constexpr size_t pass_count = ThisSorter::pass_count + NextSorter::pass_count;
};
template<size_t I, size_t S, typename Tuple>
struct TupleRadixSorter<I, S, const Tuple &> {
  using NextSorter = TupleRadixSorter<I + 1, S, const Tuple &>;
  using ThisSorter = RadixSorter<typename tuple_element<I, Tuple>::type>;
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key) {
    bool which = NextSorter::sort(begin, end, out_begin, out_end, extract_key);
    auto extract_i = [&](auto && o) -> decltype(auto) {
      return get<I>(extract_key(o));
    };
    if (which) return !ThisSorter::sort(out_begin, out_end, begin, extract_i);
    else return ThisSorter::sort(begin, end, out_begin, extract_i);
  }
  static constexpr size_t pass_count = ThisSorter::pass_count + NextSorter::pass_count;
};
template<size_t I, typename Tuple>
struct TupleRadixSorter<I, I, Tuple> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It, It, OutIt, OutIt, ExtractKey &&) {
    return false;
  }
  static constexpr size_t pass_count = 0;
};
template<size_t I, typename Tuple>
struct TupleRadixSorter<I, I, const Tuple &> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It, It, OutIt, OutIt, ExtractKey &&) {
    return false;
  }
  static constexpr size_t pass_count = 0;
};
template<typename... Args>
struct RadixSorter<tuple<Args...>> {
  using SorterImpl = TupleRadixSorter<0, sizeof...(Args), tuple<Args...>>;
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    return SorterImpl::sort(begin, end, buffer_begin, buffer_begin + (end - begin), extract_key);
  }
  static constexpr size_t pass_count = SorterImpl::pass_count;
};
template<typename... Args>
struct RadixSorter<const tuple<Args...> &> {
  using SorterImpl = TupleRadixSorter<0, sizeof...(Args), const tuple<Args...> &>;
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    return SorterImpl::sort(begin, end, buffer_begin, buffer_begin + (end - begin), extract_key);
  }
  static constexpr size_t pass_count = SorterImpl::pass_count;
};
template<typename T, size_t S>
struct RadixSorter<array<T, S>> {
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    auto buffer_end = buffer_begin + (end - begin);
    bool which = false;
    for (size_t i = S; i > 0; --i) {
      auto extract_i = [&, i = i - 1](auto && o) {
        return extract_key(o)[i];
      };
      if (which) which = !RadixSorter<T>::sort(buffer_begin, buffer_end, begin, extract_i);
      else which = RadixSorter<T>::sort(begin, end, buffer_begin, extract_i);
    }
    return which;
  }
  static constexpr size_t pass_count = RadixSorter<T>::pass_count * S;
};
template<typename T>
struct RadixSorter<const T> : RadixSorter<T> {
};
template<typename T>
struct RadixSorter<T &> : RadixSorter<const T &> {
};
template<typename T>
struct RadixSorter<T &&> : RadixSorter<T> {
};
template<typename T>
struct RadixSorter<const T &> : RadixSorter<T> {
};
template<typename T>
struct RadixSorter<const T &&> : RadixSorter<T> {
};












struct ExampleStructA { int i; };
struct ExampleStructB { float f; };
inline int id7(ExampleStructA a) { return a.i; }
inline float id7(ExampleStructB b) { return b.f; }
template<typename T, typename Enable = void>
struct FallbackRadixSorter : RadixSorter<decltype(id7(declval<T>()))> {
  using base = RadixSorter<decltype(id7(declval<T>()))>;
  template<typename It, typename OutIt, typename ExtractKey>
  static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key) {
    return base::sort(begin, end, buffer_begin, [&](auto && a)->decltype(auto) {
      return id7(extract_key(a));
    });
  }
};
template<typename...>
struct nested_void {
  using type = void;
};
template<typename... Args>
using void_t = typename nested_void<Args...>::type;
template<typename T>
struct has_subscript_operator_impl {
  template<typename U, typename = decltype(declval<U>()[0])>
  static true_type test(int);
  template<typename>
  static false_type test(...);
  using type = decltype(test<T>(0));
};
template<typename T>
using has_subscript_operator = typename has_subscript_operator_impl<T>::type;
template<typename T>
struct FallbackRadixSorter<T, void_t<decltype(id16(declval<T>()))>>
  : RadixSorter<decltype(id16(declval<T>()))> {
};
template<typename T>
struct RadixSorter : FallbackRadixSorter<T> {
};
template<typename T>
size_t id24 = RadixSorter<T>::pass_count;
template<typename It, typename Func>
inline void id31(It begin, size_t iteration_count, Func && to_call) {
  size_t loop_count = iteration_count / 4;
  size_t id14 = iteration_count - loop_count * 4;
  for (; loop_count > 0; --loop_count) {
    to_call(begin);
    ++begin;
    to_call(begin);
    ++begin;
    to_call(begin);
    ++begin;
    to_call(begin);
    ++begin;
  }
  switch(id14) {
  case 3:
    to_call(begin);
    ++begin;
  case 2:
    to_call(begin);
    ++begin;
  case 1:
    to_call(begin);
  }
}
template<typename It, typename F>
inline It id20(It begin, It end, F && func) {
  for (;; ++begin) {
    if (begin == end) return end;
    if (!func(*begin)) break;
  }
  It it = begin;
  for(++it; it != end; ++it) {
    if (!func(*it)) continue;
    iter_swap(begin, it);
    ++begin;
  }
  return begin;
}
struct PartitionInfo {
  PartitionInfo()
    : count(0) { }
  union {
    size_t count;
    size_t offset;
  };
  size_t next_offset;
};
template<size_t>
struct UnsignedForSize;
template<>
struct UnsignedForSize<1> {
  typedef uint8_t type;
};
template<>
struct UnsignedForSize<2> {
  typedef uint16_t type;
};
template<>
struct UnsignedForSize<4> {
  typedef uint32_t type;
};
template<>
struct UnsignedForSize<8> {
  typedef uint64_t type;
};
template<typename T>
struct SubKey;
template<size_t Size>
struct SizedSubKey {
  template<typename T>
  static auto sub_key(T && value, void *)
  {
    return id16(value);
  }
  typedef SubKey<void> next;
  using sub_key_type = typename UnsignedForSize<Size>::type;
};
template<typename T>
struct SubKey<const T> : SubKey<T> {
};
template<typename T>
struct SubKey<T &> : SubKey<T> {
};
template<typename T>
struct SubKey<T &&> : SubKey<T> {
};
template<typename T>
struct SubKey<const T &> : SubKey<T> {
};
template<typename T>
struct SubKey<const T &&> : SubKey<T> {
};
template<typename T, typename Enable = void>
struct FallbackSubKey
  : SubKey<decltype(id7(declval<T>()))> {
  using base = SubKey<decltype(id7(declval<T>()))>;
  template<typename U>
  static decltype(auto) sub_key(U && value, void * data) {
    return base::sub_key(id7(value), data);
  }
};
template<typename T>
struct FallbackSubKey<T, void_t<decltype(id16(declval<T>()))>>
  : SubKey<decltype(id16(declval<T>()))> {
};
template<typename T>
struct SubKey : FallbackSubKey<T> {
};
template<>
struct SubKey<bool> {
  template<typename T>
  static bool sub_key(T && value, void *) {
    return value;
  }
  typedef SubKey<void> next;
  using sub_key_type = bool;
};
template<>
struct SubKey<void>;
template<>
struct SubKey<unsigned char> : SizedSubKey<sizeof(unsigned char)> {
};
template<>
struct SubKey<unsigned short> : SizedSubKey<sizeof(unsigned short)> {
};
template<>
struct SubKey<unsigned int> : SizedSubKey<sizeof(unsigned int)> {
};
template<>
struct SubKey<unsigned long> : SizedSubKey<sizeof(unsigned long)> {
};
template<>
struct SubKey<unsigned long long> : SizedSubKey<sizeof(unsigned long long)> {
};
template<typename T>
struct SubKey<T *> : SizedSubKey<sizeof(T *)> {
};
template<typename F, typename S, typename Current>
struct PairSecondSubKey : Current {
  static decltype(auto) sub_key(const pair<F, S> & value, void * sort_data) {
    return Current::sub_key(value.second, sort_data);
  }
  using next = typename conditional<is_same<SubKey<void>, typename Current::next>::value, SubKey<void>, PairSecondSubKey<F, S, typename Current::next>>::type;
};
template<typename F, typename S, typename Current>
struct PairFirstSubKey : Current {
  static decltype(auto) sub_key(const pair<F, S> & value, void * sort_data) {
    return Current::sub_key(value.first, sort_data);
  }
  using next = typename conditional<is_same<SubKey<void>, typename Current::next>::value, PairSecondSubKey<F, S, SubKey<S>>, PairFirstSubKey<F, S, typename Current::next>>::type;
};
template<typename F, typename S>
struct SubKey<pair<F, S>> : PairFirstSubKey<F, S, SubKey<F>> {
};
template<size_t Index, typename First, typename... More>
struct TypeAt : TypeAt<Index - 1, More..., void> {
};
template<typename First, typename... More>
struct TypeAt<0, First, More...> {
  typedef First type;
};
template<size_t Index, typename Current, typename First, typename... More>
struct TupleSubKey;
template<size_t Index, typename Next, typename First, typename... More>
struct NextTupleSubKey {
  using type = TupleSubKey<Index, Next, First, More...>;
};
template<size_t Index, typename First, typename Second, typename... More>
struct NextTupleSubKey<Index, SubKey<void>, First, Second, More...> {
  using type = TupleSubKey<Index + 1, SubKey<Second>, Second, More...>;
};
template<size_t Index, typename First>
struct NextTupleSubKey<Index, SubKey<void>, First> {
  using type = SubKey<void>;
};
template<size_t Index, typename Current, typename First, typename... More>
struct TupleSubKey : Current {
  template<typename Tuple>
  static decltype(auto) sub_key(const Tuple & value, void * sort_data) {
    return Current::sub_key(get<Index>(value), sort_data);
  }
  using next = typename NextTupleSubKey<Index, typename Current::next, First, More...>::type;
};
template<size_t Index, typename Current, typename First>
struct TupleSubKey<Index, Current, First> : Current {
  template<typename Tuple>
  static decltype(auto) sub_key(const Tuple & value, void * sort_data) {
    return Current::sub_key(get<Index>(value), sort_data);
  }
  using next = typename NextTupleSubKey<Index, typename Current::next, First>::type;
};
template<typename First, typename... More>
struct SubKey<tuple<First, More...>> : TupleSubKey<0, SubKey<First>, First, More...> {
};
struct BaseListSortData {
  size_t current_index;
  size_t recursion_limit;
  void * id1;
};
template<typename It, typename ExtractKey>
struct ListSortData : BaseListSortData {
  void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *);
};
template<typename CurrentSubKey, typename T>
struct ListElementSubKey : SubKey<typename decay<decltype(declval<T>()[0])>::type> {
  using base = SubKey<typename decay<decltype(declval<T>()[0])>::type>;
  using next = ListElementSubKey;
  template<typename U>
  static decltype(auto) sub_key(U && value, void * sort_data) {
    BaseListSortData * list_sort_data = static_cast<BaseListSortData *>(sort_data);
    const T & list = CurrentSubKey::sub_key(value, list_sort_data->id1);
    return base::sub_key(list[list_sort_data->current_index], list_sort_data->id1);
  }
};
template<typename T>
struct ListSubKey {
  using next = SubKey<void>;
  using sub_key_type = T;
  static const T & sub_key(const T & value, void *) {
    return value;
  }
};
template<typename T>
struct FallbackSubKey<T, typename enable_if<has_subscript_operator<T>::value>::type> : ListSubKey<T> {
};
template<typename It, typename ExtractKey>
inline void id9(It begin, It end, ExtractKey & extract_key) {
  sort(begin, end, [&](auto && l, auto && r){ return extract_key(l) < extract_key(r); });
}
template<ptrdiff_t id11, typename It, typename ExtractKey>
inline bool id15(It begin, It end, ptrdiff_t num_elements, ExtractKey & extract_key) {
  if (num_elements <= 1) return true;
  if (num_elements >= id11) return false;
  id9(begin, end, extract_key);
  return true;
}
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, typename SubKeyType = typename CurrentSubKey::sub_key_type>
struct InplaceSorter;
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, size_t NumBytes, size_t Offset = 0>
struct UnsignedInplaceSorter {
  static constexpr size_t ShiftAmount = (((NumBytes - 1) - Offset) * 8);
  template<typename T>
  inline static uint8_t current_byte(T && elem, void * sort_data) {
    return CurrentSubKey::sub_key(elem, sort_data) >> ShiftAmount;
  }
  template<typename It, typename ExtractKey>
  static void sort(It begin, It end, ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *), void * sort_data) {
    if (num_elements < id4) id28(begin, end, extract_key, next_sort, sort_data);
    else id6(begin, end, extract_key, next_sort, sort_data);
  }
  template<typename It, typename ExtractKey>
  static void id28(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *), void * sort_data) {
    PartitionInfo partitions[256];
    for (It it = begin; it != end; ++it)
      ++partitions[current_byte(extract_key(*it), sort_data)].count;
    size_t total = 0;
    uint8_t id5[256];
    int id29 = 0;
    for (int i = 0; i < 256; ++i) {
      size_t count = partitions[i].count;
      if (!count) continue;
      partitions[i].offset = total;
      total += count;
      partitions[i].next_offset = total;
      id5[id29] = i;
      ++id29;
    }
    if (id29 > 1) {
      uint8_t * current_block_ptr = id5;
      PartitionInfo * current_block = partitions + *current_block_ptr;
      uint8_t * last_block = id5 + id29 - 1;
      It it = begin;
      It block_end = begin + current_block->next_offset;
      It last_element = end - 1;
      for (;;) {
        PartitionInfo * block = partitions + current_byte(extract_key(*it), sort_data);
        if (block == current_block) {
          ++it;
          if (it == last_element) break;
          else if (it == block_end) {
            for (;;) {
              ++current_block_ptr;
              if (current_block_ptr == last_block) goto recurse;
              current_block = partitions + *current_block_ptr;
              if (current_block->offset != current_block->next_offset) break;
            }
            it = begin + current_block->offset;
            block_end = begin + current_block->next_offset;
          }
        }
        else {
          size_t offset = block->offset++;
          iter_swap(it, begin + offset);
        }
      }
    }
    recurse:
    if (Offset + 1 != NumBytes || next_sort) {
      size_t start_offset = 0;
      It partition_begin = begin;
      for (uint8_t * it = id5, * part_end = id5 + id29; it != part_end; ++it) {
        size_t end_offset = partitions[*it].next_offset;
        It partition_end = begin + end_offset;
        ptrdiff_t num_elements = end_offset - start_offset;
        if (!id15<id11>(partition_begin, partition_end, num_elements, extract_key)) {
          UnsignedInplaceSorter<id11, id4, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
        }
        start_offset = end_offset;
        partition_begin = partition_end;
      }
    }
  }
  template<typename It, typename ExtractKey>
  static void id6(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *), void * sort_data) {
    PartitionInfo partitions[256];
    for (It it = begin; it != end; ++it)
      ++partitions[current_byte(extract_key(*it), sort_data)].count;
    uint8_t id5[256];
    size_t total = 0;
    int id29 = 0;
    for (int i = 0; i < 256; ++i) {
      size_t count = partitions[i].count;
      if (count) {
        partitions[i].offset = total;
        total += count;
        id5[id29] = i;
        ++id29;
      }
      partitions[i].next_offset = total;
    }
    for (uint8_t * last_remaining = id5 + id29, * end_partition = id5 + 1; last_remaining > end_partition;) {
      last_remaining = id20(id5, last_remaining, [&](uint8_t partition) {
        size_t & begin_offset = partitions[partition].offset;
        size_t & end_offset = partitions[partition].next_offset;
        if (begin_offset == end_offset)
          return false;
        id31(begin + begin_offset, end_offset - begin_offset, [partitions = partitions, begin, &extract_key, sort_data](It it) {
          uint8_t this_partition = current_byte(extract_key(*it), sort_data);
          size_t offset = partitions[this_partition].offset++;
          iter_swap(it, begin + offset);
        });
        return begin_offset != end_offset;
      });
    }
    if (Offset + 1 != NumBytes || next_sort) {
      for (uint8_t * it = id5 + id29; it != id5; --it) {
        uint8_t partition = it[-1];
        size_t start_offset = (partition == 0 ? 0 : partitions[partition - 1].next_offset);
        size_t end_offset = partitions[partition].next_offset;
        It partition_begin = begin + start_offset;
        It partition_end = begin + end_offset;
        ptrdiff_t num_elements = end_offset - start_offset;
        if (!id15<id11>(partition_begin, partition_end, num_elements, extract_key)) {
          UnsignedInplaceSorter<id11, id4, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
        }
      }
    }
  }
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, size_t NumBytes>
struct UnsignedInplaceSorter<id11, id4, CurrentSubKey, NumBytes, NumBytes> {
  template<typename It, typename ExtractKey>
  inline static void sort(It begin, It end, ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *), void * id1) {
    next_sort(begin, end, num_elements, extract_key, id1);
  }
};
template<typename It, typename ExtractKey, typename ElementKey>
size_t CommonPrefix(It begin, It end, size_t start_index, ExtractKey && extract_key, ElementKey && element_key) {
  const auto & id25 = extract_key(*begin);
  size_t largest_match = id25.size();
  if (largest_match == start_index)
    return start_index;
  for (++begin; begin != end; ++begin) {
    const auto & current_list = extract_key(*begin);
    size_t current_size = current_list.size();
    if (current_size < largest_match) {
      largest_match = current_size;
      if (largest_match == start_index)
        return start_index;
    }
    if (element_key(id25[start_index]) != element_key(current_list[start_index]))
      return start_index;
    for (size_t i = start_index + 1; i < largest_match; ++i) {
      if (element_key(id25[i]) != element_key(current_list[i])) {
        largest_match = i;
        break;
      }
    }
  }
  return largest_match;
}
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, typename ListType>
struct ListInplaceSorter {
  using ElementSubKey = ListElementSubKey<CurrentSubKey, ListType>;
  template<typename It, typename ExtractKey>
  static void sort(It begin, It end, ExtractKey & extract_key, ListSortData<It, ExtractKey> * sort_data) {
    size_t current_index = sort_data->current_index;
    void * id1 = sort_data->id1;
    auto current_key = [&](auto && elem) -> decltype(auto) {
      return CurrentSubKey::sub_key(extract_key(elem), id1);
    };
    auto element_key = [&](auto && elem) -> decltype(auto) {
      return ElementSubKey::base::sub_key(elem, sort_data);
    };
    sort_data->current_index = current_index = CommonPrefix(begin, end, current_index, current_key, element_key);
    It id8 = partition(begin, end, [&](auto && elem) {
      return current_key(elem).size() <= current_index;
    });
    ptrdiff_t id23 = id8 - begin;
    if (sort_data->next_sort && !id15<id11>(begin, id8, id23, extract_key)) {
      sort_data->next_sort(begin, id8, id23, extract_key, id1);
    }
    ptrdiff_t num_elements = end - id8;
    if (!id15<id11>(id8, end, num_elements, extract_key)) {
      void (*sort_next_element)(It, It, ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, ptrdiff_t, ExtractKey &, void *)>(&id2);
      InplaceSorter<id11, id4, ElementSubKey>::sort(id8, end, num_elements, extract_key, sort_next_element, sort_data);
    }
  }
  template<typename It, typename ExtractKey>
  static void id2(It begin, It end, ptrdiff_t, ExtractKey & extract_key, void * id1) {
    ListSortData<It, ExtractKey> offset = *static_cast<ListSortData<It, ExtractKey> *>(id1);
    ++offset.current_index;
    --offset.recursion_limit;
    if (offset.recursion_limit == 0) id9(begin, end, extract_key);
    else sort(begin, end, extract_key, &offset);
  }
  template<typename It, typename ExtractKey>
  static void sort(It begin, It end, ptrdiff_t, ExtractKey & extract_key, void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *), void * id1) {
    ListSortData<It, ExtractKey> offset;
    offset.current_index = 0;
    offset.recursion_limit = 16;
    offset.next_sort = next_sort;
    offset.id1 = id1;
    sort(begin, end, extract_key, &offset);
  }
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id11, id4, CurrentSubKey, bool> {
  template<typename It, typename ExtractKey>
  static void sort(It begin, It end, ptrdiff_t, ExtractKey & extract_key, void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *), void * sort_data) {
    It middle = partition(begin, end, [&](auto && a){ return !CurrentSubKey::sub_key(extract_key(a), sort_data); });
    if (next_sort) {
      next_sort(begin, middle, middle - begin, extract_key, sort_data);
      next_sort(middle, end, end - middle, extract_key, sort_data);
    }
  }
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id11, id4, CurrentSubKey, uint8_t> : UnsignedInplaceSorter<id11, id4, CurrentSubKey, 1> {
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id11, id4, CurrentSubKey, uint16_t> : UnsignedInplaceSorter<id11, id4, CurrentSubKey, 2> {
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id11, id4, CurrentSubKey, uint32_t> : UnsignedInplaceSorter<id11, id4, CurrentSubKey, 4> {
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id11, id4, CurrentSubKey, uint64_t> : UnsignedInplaceSorter<id11, id4, CurrentSubKey, 8> {
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, typename SubKeyType, typename Enable = void>
struct FallbackInplaceSorter;
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, typename SubKeyType>
struct InplaceSorter : FallbackInplaceSorter<id11, id4, CurrentSubKey, SubKeyType> {
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey, typename SubKeyType>
struct FallbackInplaceSorter<id11, id4, CurrentSubKey, SubKeyType, typename enable_if<has_subscript_operator<SubKeyType>::value>::type>
  : ListInplaceSorter<id11, id4, CurrentSubKey, SubKeyType> {
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct SortStarter;
template<ptrdiff_t id11, ptrdiff_t id4>
struct SortStarter<id11, id4, SubKey<void>> {
  template<typename It, typename ExtractKey>
  static void sort(It, It, ptrdiff_t, ExtractKey &, void *) {
  }
};
template<ptrdiff_t id11, ptrdiff_t id4, typename CurrentSubKey>
struct SortStarter {
  template<typename It, typename ExtractKey>
  static void sort(It begin, It end, ptrdiff_t num_elements, ExtractKey & extract_key, void * id1 = nullptr) {
    if (id15<id11>(begin, end, num_elements, extract_key))
      return;

    void (*next_sort)(It, It, ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id11, id4, typename CurrentSubKey::next>::sort);
    if (next_sort == static_cast<void (*)(It, It, ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id11, id4, SubKey<void>>::sort))
      next_sort = nullptr;
    InplaceSorter<id11, id4, CurrentSubKey>::sort(begin, end, num_elements, extract_key, next_sort, id1);
  }
};
template<ptrdiff_t id11, ptrdiff_t id4, typename It, typename ExtractKey>
void id3(It begin, It end, ExtractKey & extract_key) {
  using SubKey = SubKey<decltype(extract_key(*begin))>;
  SortStarter<id11, id4, SubKey>::sort(begin, end, end - begin, extract_key);
}
struct IdentityFunctor {
  template<typename T>
  decltype(auto) operator()(T && i) const {
    return forward<T>(i);
  }
};
}

template<typename It, typename ExtractKey>
static void ska_sort(It begin, It end, ExtractKey && extract_key) {
  detail::id3<128, 1024>(begin, end, extract_key);
}
template<typename It>
static void ska_sort(It begin, It end) {
  ska_sort(begin, end, detail::IdentityFunctor());
}
template<typename It, typename OutIt, typename ExtractKey>
bool id10(It begin, It end, OutIt buffer_begin, ExtractKey && key) {
  ptrdiff_t num_elements = end - begin;
  if (num_elements < 128 || detail::id24<typename result_of<ExtractKey(decltype(*begin))>::type> >= 8) {
    ska_sort(begin, end, key);
    return false;
  }
  else
    return detail::RadixSorter<typename result_of<ExtractKey(decltype(*begin))>::type>::sort(begin, end, buffer_begin, key);
}
template<typename It, typename OutIt>
bool id10(It begin, It end, OutIt buffer_begin) {
  return id10(begin, end, buffer_begin, detail::IdentityFunctor());
}
}

using fast_sort::ska_sort;
using fast_sort::id10;








static char _in_buf[_InputSize], _out_buf[_OutputSize];
char *_in_p = _in_buf, *_out_p = _out_buf;
__attribute__((constructor))
void read_buffer() { fread(_in_buf, 1, _InputSize, stdin); }
__attribute__((destructor))
void write_buffer() { fwrite(_out_buf, 1, _out_p - _out_buf, stdout); }
__attribute__((__always_inline__)) __inline
void read(int *n) {
  while (*_in_p < 48 || *_in_p > 57) _in_p++;
  for (*n = *_in_p++ ^ 48; *_in_p > 47 && *_in_p < 58; )
    *n = (*n << 3) + (*n << 1) + (*_in_p++ ^ 48);
}
__attribute__((__always_inline__)) __inline
int readstr(char *str) {
  while (*_in_p < 33) _in_p++;
  register int len = 0;
  while (*_in_p > 32) *str++ = *_in_p++, len++;
  return len;
}
__attribute__((__always_inline__)) __inline
void write_char(char c) { *_out_p++ = c; }
__attribute__((__always_inline__)) __inline
void write(int n) {
  static char _buf[10]; char* _pos = _buf;
  do *_pos++ = n % 10 ^ 48; while (n /= 10);
  while (_pos != _buf) *_out_p++ = *--_pos;
}





int n, m, q;
int st[Maxn], len[Maxn];
int L[Maxn], R[Maxn];
char s[Maxn];

int sa[Maxn], rnk[Maxn], height[Maxn];
int wa[Maxn], wb[Maxn], wc[Maxn], _s[Maxn];
void id13(char *ss, int n, int m) {
  register int *x = wa, *y = wb, *tmp;
  register int i, j, w;
  for (i = 1; i <= n; ++i) _s[i] = ss[i];
  for (i = 1; i <= n; ++i) x[i] = _s[i], y[i] = i;
  for (i = 1; i <= m; ++i) wc[i] = 0;
  for (i = 1; i <= n; ++i) wc[x[i]]++;
  for (i = 2; i <= m; ++i) wc[i] += wc[i - 1];
  for (i = n; i >= 1; --i) sa[wc[x[y[i]]]--] = y[i];
  for (w = 1; w <= n; w <<= 1) {
    register int tot = 0;
    for (i = n - w + 1; i <= n; ++i) y[++tot] = i;
    for (i = 1; i <= n; ++i) if (sa[i] > w) y[++tot] = sa[i] - w;
    for (i = 1; i <= m; ++i) wc[i] = 0;
    for (i = 1; i <= n; ++i) wc[x[i]]++;
    for (i = 2; i <= m; ++i) wc[i] += wc[i - 1];
    for (i = n; i >= 1; --i) sa[wc[x[y[i]]]--] = y[i];
    tmp = x, x = y, y = tmp, x[sa[1]] = 1, tot = 1;
    for (i = 2; i <= n; ++i)
      x[sa[i]] = ((y[sa[i]] == y[sa[i - 1]] && y[sa[i] + w] == y[sa[i - 1] + w]) ? tot : ++tot);
    if (tot == n) break; m = tot;
  }
  for (i = 1; i <= n; ++i) rnk[sa[i]] = i;
  for (i = 1, w = 0; i <= n; ++i) {
    if (rnk[i] == 1) continue;
    if (w) --w;
    int j = sa[rnk[i] - 1];
    while (i + w <= n && j + w <= n && _s[i + w] == _s[j + w]) w++;
    height[rnk[i]] = w;
  }
}





int ST[LOG][Maxn];

int ans[Maxm];

struct Query {
  int op, id, x, y, val;
} qry[C_Maxn];
int tot;











int bit[Maxn];

int main() {
  register int i, j;
  read(&n), read(&q);
  m = 0;
  for (i = 1; i <= n; ++i) {
    len[i] = readstr(s + (st[i] = m + 1));
    s[st[i] + len[i]] = '$';
    m = st[i] + len[i];
  }
  
  id13(s, m, 128);
  for (i = 1; i <= m; ++i) ST[0][i] = height[i];
  for (j = 1; j < LOG; ++j)
    for (i = 1; i + (1 << j) - 1 <= m; ++i) {
      int a = ST[j - 1][i], b = ST[j - 1][i + (1 << (j - 1))];
      ST[j][i] = (a < b ? a : b);
    }
  for (i = 1, j; i <= n; ++i) {
    int l = rnk[st[i]], r = rnk[st[i]];
    int length = len[i];
     {
      for (j = 0; l - (1 << j) + 1 >= 2; ++j);
      for (; ~--j; ) {
        if (l - (1 << j) + 1 >= 2 && ST[j][l - (1 << j) + 1] >= length) {
          l -= (1 << j);
        }
      }
    }
     {
      for (j = 0; r + (1 << j) <= m; ++j);
      for (; ~--j; ) {
        if (r + (1 << j) <= m && ST[j][r + 1] >= length) {
          r += (1 << j);
        }
      }
    }
    L[i] = l, R[i] = r;


  }
  
  tot = 0;
  for (i = 1; i <= m; ++i)
    qry[tot++] = (struct Query){1, 0, i, rnk[i], 0};
  for (i = 1; i <= q; ++i) {
    int l, r, k;
    read(&l), read(&r), read(&k);
    int xl = st[l], xr = st[r] + len[r], yl = L[k], yr = R[k];
    qry[tot++] = (struct Query){2, i, xl - 1, yl - 1, 1};
    qry[tot++] = (struct Query){2, i, xl - 1, yr, -1};
    qry[tot++] = (struct Query){2, i, xr, yl - 1, -1};
    qry[tot++] = (struct Query){2, i, xr, yr, 1};
  }
  ska_sort(qry, qry + tot, [&](const Query &x) {
    return x.x * 10 + x.op;
  });
  for (i = 0; i < tot; ++i) {
    int x = qry[i].y;
    if (qry[i].op == 1) {
      while (x < Maxn)
        bit[x]++, x += x & -x;
    }
    else {
      int res = 0;
      while (x) {
        res += bit[x];
        x -= x & -x;
      }
      ans[qry[i].id] += qry[i].val * res;
    }
  }
  for (int i = 1; i <= q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
