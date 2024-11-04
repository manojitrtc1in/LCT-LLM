





    
    
    

    



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
    inline void id5(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;

        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter id10 = cur - 1;

            

            if (comp(*sift, *id10)) {
                T tmp = PDQSORT_PREFER_MOVE(*sift);

                do { *sift-- = PDQSORT_PREFER_MOVE(*id10); }
                while (sift != begin && comp(tmp, *--id10));

                *sift = PDQSORT_PREFER_MOVE(tmp);
            }
        }
    }

    

    

    template<class Iter, class Compare>
    inline void id13(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return;

        for (Iter cur = begin + 1; cur != end; ++cur) {
            Iter sift = cur;
            Iter id10 = cur - 1;

            

            if (comp(*sift, *id10)) {
                T tmp = PDQSORT_PREFER_MOVE(*sift);

                do { *sift-- = PDQSORT_PREFER_MOVE(*id10); }
                while (comp(tmp, *--id10));

                *sift = PDQSORT_PREFER_MOVE(tmp);
            }
        }
    }

    

    

    

    template<class Iter, class Compare>
    inline bool id0(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (begin == end) return true;

        int limit = 0;
        for (Iter cur = begin + 1; cur != end; ++cur) {
            if (limit > partial_insertion_sort_limit) return false;

            Iter sift = cur;
            Iter id10 = cur - 1;

            

            if (comp(*sift, *id10)) {
                T tmp = PDQSORT_PREFER_MOVE(*sift);

                do { *sift-- = PDQSORT_PREFER_MOVE(*id10); }
                while (sift != begin && comp(tmp, *--id10));

                *sift = PDQSORT_PREFER_MOVE(tmp);
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
    inline T* id8(T* p) {

        std::uintptr_t ip = reinterpret_cast<std::uintptr_t>(p);

        std::size_t ip = reinterpret_cast<std::size_t>(p);

        ip = (ip + cacheline_size - 1) & -cacheline_size;
        return reinterpret_cast<T*>(ip);
    }

    template<class Iter>
    inline void swap_offsets(Iter first, Iter last,
                             unsigned char* id11, unsigned char* id4,
                             int num, bool id1) {
        typedef typename std::iterator_traits<Iter>::value_type T;
        if (id1) {
            

            

            for (int i = 0; i < num; ++i) {
                std::iter_swap(first + id11[i], last - id4[i]);
            }
        } else if (num > 0) {
            Iter l = first + id11[0]; Iter r = last - id4[0];
            T tmp(PDQSORT_PREFER_MOVE(*l)); *l = PDQSORT_PREFER_MOVE(*r);
            for (int i = 1; i < num; ++i) {
                l = first + id11[i]; *r = PDQSORT_PREFER_MOVE(*l);
                r = last - id4[i]; *l = PDQSORT_PREFER_MOVE(*r);
            }
            *r = PDQSORT_PREFER_MOVE(tmp);
        }
    }

    

    

    

    

    

    template<class Iter, class Compare>
    inline std::pair<Iter, bool> id12(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;

        

        T pivot(PDQSORT_PREFER_MOVE(*begin));
        Iter first = begin;
        Iter last = end;

        

        

        while (comp(*++first, pivot));

        

        

        if (first - 1 == begin) while (first < last && !comp(*--last, pivot));
        else                    while (                !comp(*--last, pivot));

        

        

        bool id2 = first >= last;
        if (!id2) {
            std::iter_swap(first, last);
            ++first;
        }

        

        

        unsigned char offsets_l_storage[block_size + cacheline_size];
        unsigned char offsets_r_storage[block_size + cacheline_size];
        unsigned char* id11 = id8(offsets_l_storage);
        unsigned char* id4 = id8(offsets_r_storage);
        int num_l, num_r, start_l, start_r;
        num_l = num_r = start_l = start_r = 0;

        while (last - first > 2 * block_size) {
            

            if (num_l == 0) {
                start_l = 0;
                Iter it = first;
                for (unsigned char i = 0; i < block_size;) {
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                    id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
                }
            }
            if (num_r == 0) {
                start_r = 0;
                Iter it = last;
                for (unsigned char i = 0; i < block_size;) {
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                    id4[num_r] = ++i; num_r += comp(*--it, pivot);
                }
            }

            

            int num = std::min(num_l, num_r);
            swap_offsets(first, last, id11 + start_l, id4 + start_r,
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
                id11[num_l] = i++; num_l += !comp(*it, pivot); ++it;
            }
        }
        if (unknown_left && !num_r) {
            start_r = 0;
            Iter it = last;
            for (unsigned char i = 0; i < r_size;) {
                id4[num_r] = ++i; num_r += comp(*--it, pivot);
            }
        }

        int num = std::min(num_l, num_r);
        swap_offsets(first, last, id11 + start_l, id4 + start_r, num, num_l == num_r);
        num_l -= num; num_r -= num;
        start_l += num; start_r += num;
        if (num_l == 0) first += l_size;
        if (num_r == 0) last -= r_size;

        

        if (num_l) {
            id11 += start_l;
            while (num_l--) std::iter_swap(first + id11[num_l], --last);
            first = last;
        }
        if (num_r) {
            id4 += start_r;
            while (num_r--) std::iter_swap(last - id4[num_r], first), ++first;
            last = first;
        }

        

        Iter pivot_pos = first - 1;
        *begin = PDQSORT_PREFER_MOVE(*pivot_pos);
        *pivot_pos = PDQSORT_PREFER_MOVE(pivot);

        return std::make_pair(pivot_pos, id2);
    }

    

    

    

    

    

    template<class Iter, class Compare>
    inline std::pair<Iter, bool> partition_right(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;

        

        T pivot(PDQSORT_PREFER_MOVE(*begin));

        Iter first = begin;
        Iter last = end;

        

        

        while (comp(*++first, pivot));

        

        

        if (first - 1 == begin) while (first < last && !comp(*--last, pivot));
        else                    while (                !comp(*--last, pivot));

        

        

        bool id2 = first >= last;

        

        

        

        while (first < last) {
            std::iter_swap(first, last);
            while (comp(*++first, pivot));
            while (!comp(*--last, pivot));
        }

        

        Iter pivot_pos = first - 1;
        *begin = PDQSORT_PREFER_MOVE(*pivot_pos);
        *pivot_pos = PDQSORT_PREFER_MOVE(pivot);

        return std::make_pair(pivot_pos, id2);
    }

    

    

    

    

    template<class Iter, class Compare>
    inline Iter partition_left(Iter begin, Iter end, Compare comp) {
        typedef typename std::iterator_traits<Iter>::value_type T;

        T pivot(PDQSORT_PREFER_MOVE(*begin));
        Iter first = begin;
        Iter last = end;

        while (comp(pivot, *--last));

        if (last + 1 == end) while (first < last && !comp(pivot, *++first));
        else                 while (                !comp(pivot, *++first));

        while (first < last) {
            std::iter_swap(first, last);
            while (comp(pivot, *--last));
            while (!comp(pivot, *++first));
        }

        Iter pivot_pos = last;
        *begin = PDQSORT_PREFER_MOVE(*pivot_pos);
        *pivot_pos = PDQSORT_PREFER_MOVE(pivot);

        return pivot_pos;
    }


    template<class Iter, class Compare, bool Branchless>
    inline void id6(Iter begin, Iter end, Compare comp, int bad_allowed, bool leftmost = true) {
        typedef typename std::iterator_traits<Iter>::difference_type diff_t;

        

        while (true) {
            diff_t size = end - begin;

            

            if (size < insertion_sort_threshold) {
                if (leftmost) id5(begin, end, comp);
                else id13(begin, end, comp);
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
                Branchless ? id12(begin, end, comp)
                           : partition_right(begin, end, comp);
            Iter pivot_pos = part_result.first;
            bool id2 = part_result.second;

            

            diff_t l_size = pivot_pos - begin;
            diff_t r_size = end - (pivot_pos + 1);
            bool id9 = l_size < size / 8 || r_size < size / 8;

            

            if (id9) {
                

                if (--bad_allowed == 0) {
                    std::make_heap(begin, end, comp);
                    std::sort_heap(begin, end, comp);
                    return;
                }

                if (l_size >= insertion_sort_threshold) {
                    std::iter_swap(begin,             begin + l_size / 4);
                    std::iter_swap(pivot_pos - 1, pivot_pos - l_size / 4);

                    if (l_size > ninther_threshold) {
                        std::iter_swap(begin + 1,         begin + (l_size / 4 + 1));
                        std::iter_swap(begin + 2,         begin + (l_size / 4 + 2));
                        std::iter_swap(pivot_pos - 2, pivot_pos - (l_size / 4 + 1));
                        std::iter_swap(pivot_pos - 3, pivot_pos - (l_size / 4 + 2));
                    }
                }

                if (r_size >= insertion_sort_threshold) {
                    std::iter_swap(pivot_pos + 1, pivot_pos + (1 + r_size / 4));
                    std::iter_swap(end - 1,                   end - r_size / 4);

                    if (r_size > ninther_threshold) {
                        std::iter_swap(pivot_pos + 2, pivot_pos + (2 + r_size / 4));
                        std::iter_swap(pivot_pos + 3, pivot_pos + (3 + r_size / 4));
                        std::iter_swap(end - 2,             end - (1 + r_size / 4));
                        std::iter_swap(end - 3,             end - (2 + r_size / 4));
                    }
                }
            } else {
                

                

                if (id2 && id0(begin, pivot_pos, comp)
                                        && id0(pivot_pos + 1, end, comp)) return;
            }

            

            

            id6<Iter, Compare, Branchless>(begin, pivot_pos, comp, bad_allowed, leftmost);
            begin = pivot_pos + 1;
            leftmost = false;
        }
    }
}


template<class Iter, class Compare>
inline void id3(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;


    pdqsort_detail::id6<Iter, Compare,
        pdqsort_detail::is_default_compare<typename std::decay<Compare>::type>::value &&
        std::is_arithmetic<typename std::iterator_traits<Iter>::value_type>::value>(
        begin, end, comp, pdqsort_detail::log2(end - begin));

    pdqsort_detail::id6<Iter, Compare, false>(
        begin, end, comp, pdqsort_detail::log2(end - begin));

}

template<class Iter>
inline void id3(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    id3(begin, end, std::less<T>());
}

template<class Iter, class Compare>
inline void id7(Iter begin, Iter end, Compare comp) {
    if (begin == end) return;
    pdqsort_detail::id6<Iter, Compare, true>(
        begin, end, comp, pdqsort_detail::log2(end - begin));
}

template<class Iter>
inline void id7(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type T;
    id7(begin, end, std::less<T>());
}






using namespace std;
using lli = long long int;
const int N=500001;
int fx[N+1], fy[N+1];
int X[N+1];
int Y[N+1];
int Z[N+1];
int I[N+1];

inline int read_positive(){
  char c; int x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}

int main(){
  lli n,x1,y1,z1;
  n=read_positive();
  x1=read_positive();
  y1=read_positive();
  z1=read_positive();
  FOR(x,x1+1) fx[x]=y1;
  FOR(y,y1+1) fy[y]=x1;
  FOR(i,n) {
    I[i]=i;
    X[i]=read_positive();
    Y[i]=read_positive();
    Z[i]=read_positive();
    fx[X[i]]=min<int>(fx[X[i]],y1-Y[i]);
    fy[Y[i]]=min<int>(fy[Y[i]],x1-X[i]);
  }
  id3(I,I+n,[&](int i, int j) { return Z[i]>Z[j]; });
  FORD(x,x1-1,0) fx[x]=min(fx[x],fx[x+1]);
  FORD(y,y1-1,0) fy[y]=min(fy[y],fy[y+1]);
  lli x0=1,y0=1;
  lli ans=0;
  FOR(i,n) {
    lli x=X[I[i]];
    lli y=Y[I[i]];
    lli z=Z[I[i]];
    if(x<x0&&y<y0) continue;
    lli x00=x0, y00=y0;
    lli dxy=0;
    while(x0<x+1) {
      dxy+=min<lli>(fx[x0],y1-y00+1);
      x0++;
    }
    while(y0<y+1) {
      dxy+=min<lli>(fy[y0],x1-x00+1);
      y0++;
    }
    ans += lli(z1-z)*lli(dxy);
  }
  ans += lli(x1-x0+1)*lli(y1-y0+1)*lli(z1);
  cout << ans << endl;
  return 0;
}
