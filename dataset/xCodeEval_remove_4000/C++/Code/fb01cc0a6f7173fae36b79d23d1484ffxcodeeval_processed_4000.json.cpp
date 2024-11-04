





























using namespace std;



namespace WrapperClass {

    typedef FILE *(*file_manipulator)(FILE *);





    namespace details {
        char Buffer[2000002];
    }







































































































    template<class T>
    class Wrapper {
    private:
        T x;

    public:
        template<class... Arguments>
        Wrapper(Arguments... args) : x(T(args...)) {}

        Wrapper(const Wrapper &a) : x(a.x) {}








        T &get_data() {
            return x;
        }

        T get_data() const {
            return x;
        }














































































































































































































































































































































































































































































































        return_type operator op (const U &a) const {\
            return return_type((x op (T)a));\
}


    Wrapper &operator op (const U &a) {\
    x op (T)a;\
    return *this;\
}

        id0(Wrapper<bool>, !=);

        id0(Wrapper, %);

        WRAPPER_BIN_OPERATOR(%=);

        id0(Wrapper, &);

        id0(Wrapper<bool>, &&);

        WRAPPER_BIN_OPERATOR(&=);

        id0(Wrapper, *);

        WRAPPER_BIN_OPERATOR(*=);













        template<class U> auto operator + (const U &a) const;

        WRAPPER_BIN_OPERATOR(+=);

        id0(Wrapper, -);

        WRAPPER_BIN_OPERATOR(-=);

        id0(Wrapper, /);

        WRAPPER_BIN_OPERATOR(/=);

        id0(Wrapper<bool>, <);

        id0(Wrapper, <<);

        WRAPPER_BIN_OPERATOR(<<=);

        id0(Wrapper<bool>, <=);

        WRAPPER_BIN_OPERATOR(=);

        id0(Wrapper<bool>, ==);

        id0(Wrapper<bool>, >);

        id0(Wrapper<bool>, >=);

        id0(Wrapper, >>);

        WRAPPER_BIN_OPERATOR(>>=);

        id0(Wrapper, ^);

        WRAPPER_BIN_OPERATOR(^=);

        id0(Wrapper, |);

        WRAPPER_BIN_OPERATOR(|=);

        id0(Wrapper<bool>, ||);

















    return return_type(op x);\
}

        id3(Wrapper<bool>, !);
        

        

        id3(Wrapper, +);

        id3(Wrapper, -);

        id3(Wrapper, ~);


        

        Wrapper &operator++() {
            ++x;
            return *this;
        }

        Wrapper operator++(int) {
            Wrapper tmp = *this;
            ++*this;
            return tmp;
        }


        

        Wrapper &operator--() {
            --x;
            return *this;
        }

        Wrapper operator--(int) {
            Wrapper tmp = *this;
            --*this;
            return tmp;
        }




        template<class U>
        operator U() const {
            return x;
        }

        template<class U>
        auto &operator[](const U &i) {
            return x[(int)i];
        }

        template<class U>
        const auto &operator[](const U &i) const {
            return x[(int)i];
        }
    };

    namespace extra {
        template<class T, class U>
        struct sss {
            static Wrapper<decltype(T() + U())> sum(const Wrapper<T> &a, const U &b) {
                return Wrapper<decltype(T() + U())>(a.get_data() + b);


            }
        };



























        template<class T, class U>
        struct sss <T, Wrapper<U>> {
            static Wrapper<decltype(T() + U())> sum(const Wrapper<T> &a, const Wrapper<U> &b) {
                return Wrapper<decltype(T() + U())>(a.get_data() + b.get_data());


            }
        };
    }

    template<class T>
    template<class U>
    auto Wrapper<T>::operator + (const U &a) const {
        return extra::sss<T, U>::sum(*this, a);
    }




    template<template<class...> class T, class... Args>
    class Wrapper <T<Args...>> : public T<Args...> {
    public:
        template<class... Arguments>
        Wrapper(Arguments... args) : T<Args...>(args...) {


        }


















        Wrapper<size_t> size() {
            return Wrapper<size_t>(T<Args...>::size());
        }








        template<class U>
        operator U() const {
            return T<Args...>::operator U();
        }

        template<class U>
        auto &operator[](const U &i) {
            return T<Args...>::operator[]((int)i);
        }

        template<class U>
        const auto &operator[](const U &i) const {
            return T<Args...>::operator[]((int)i);
        }
    };


    template<>
    class Wrapper <file_manipulator> {
    private:
        file_manipulator x;

    public:
        template<class... Args>
        Wrapper(Args... args) : x(args...) {}

        Wrapper(const Wrapper &a) : x(a.x) {}

        template<class... Args>
        auto operator()(Args... args) {
            return x(args...);
        }
    };


    template<class T, size_t size>
    class Wrapper <T[size]> {
    private:
        T x[size];

    public:
        template<class U>
        auto &operator[](const U &i) {
            return x[i];
        }

        template<class U>
        const auto &operator[](const U &i) const {
            return x[i];
        }
    };



FILE *operator >> (FILE *in, Wrapper<type> &a) {\
    fscanf(in, "%"
    return in;\
}

    FILE *operator >> (FILE *in, Wrapper<bool> &a) {
        int tmp;
        fscanf(in, "%d", &tmp);
        a.get_data() = (bool)tmp;
        return in;
    }

    id1(signed char, c);

    id1(short, hd);

    id1(int, d);

    id1(long, ld);

    id1(long long, lld);

    id1(float, f);

    id1(double, lf);

    id1(long double, Lf);

    id1(unsigned char, c);

    id1(unsigned short, hu);

    id1(unsigned, u);

    id1(unsigned long, lu);

    id1(unsigned long long, llu);

    


    FILE *operator >> (FILE *in, Wrapper<string> &a) {
        fscanf(in, "%s", details::Buffer);
        a = string(details::Buffer);
        return in;
    }





FILE *operator << (FILE *out, const Wrapper<type> &a) {\
    fprintf(out, "%"
    return out;\
}

    id2(bool, d);

    id2(signed char, c);

    id2(short, hd);

    id2(int, d);

    id2(long, ld);

    id2(long long, lld);

    id2(float, f);

    id2(double, f);

    id2(long double, Lf);

    id2(unsigned char, c);

    id2(unsigned short, hu);

    id2(unsigned, u);

    id2(unsigned long, lu);

    id2(unsigned long long, llu);

    id2(char *, s);

    id2(const char *, s);

    FILE *operator << (FILE *out, const Wrapper<string> &a) {
        strncpy(details::Buffer, a.c_str(), sizeof(details::Buffer));
        details::Buffer[sizeof(details::Buffer) - 1] = 0;
        fprintf(out, "%s", details::Buffer);
        return out;
    }

    FILE *operator << (FILE *out, Wrapper<file_manipulator> func) {


        return func(out);
    }

    id2(char, c);













    

    namespace OutputContainers {
        template<template<class...> class T, class... Args>
        struct for_print {
            static FILE *print(FILE *out, const Wrapper<T<Args...>> &a) {
                for (auto i : a) {
                    out << i;
                    fprintf(out, " ");
                }

                return out;
            }
        };

        template<class... Args>
        struct for_print <pair, Args...> {
            static FILE *print(FILE *out, const Wrapper<pair<Args...>> &a) {
                out << a.first;
                fprintf(out, " ");
                out << a.second;

                return out;
            }
        };
    }

    template<template<class...> class T, class... Args>
    FILE *operator << (FILE *out, const Wrapper<T<Args...>> &a) {
        return OutputContainers::for_print<T, Args...>::print(out, a);
    }

    template<class T, class U>
    FILE *operator << (FILE *out, const pair<T, U> &a) {
        out << a.first;
        fprintf(out, " ");
        out << a.second;

        return out;
    }














    

    

    



    namespace NamespaceForAuxiliaryNamespaces {}

    namespace MakePairNamespace {

        template <class T, class U> \
        struct MakePairFunction <A, B> { \
            static auto MakePair(const A &a, const B &b) { \
                return Wrapper<pair<Wrapper<T>, Wrapper<U>>>(a, b); \
            } \
        };

        template <class T, class U>
        struct MakePairFunction {
            static auto MakePair(const T &a, const U &b) {
                return Wrapper<pair<Wrapper<T>, Wrapper<U>>>(a, b);
            }
        };

        MAKE_PAIR_FUNC(Wrapper<T>, U);

        MAKE_PAIR_FUNC(T, Wrapper<U>);

        MAKE_PAIR_FUNC(Wrapper<T>, Wrapper<U>);









































    }


    namespace ExtraThings {
        typedef Wrapper<bool> Bool;
        typedef Wrapper<signed char> Char;
        typedef Wrapper<short> Short;
        typedef Wrapper<int> Int;
        typedef Wrapper<long> Long;
        typedef Wrapper<long long> LongLong;
        typedef Wrapper<float> Float;
        typedef Wrapper<double> Double;
        typedef Wrapper<long double> LongDouble;
        typedef Wrapper<unsigned char> UChar;
        typedef Wrapper<unsigned short> UShort;
        typedef Wrapper<unsigned int> UInt;
        typedef Wrapper<unsigned long> ULong;
        typedef Wrapper<unsigned long long> ULongLong;
        typedef Wrapper<string> String;

        namespace IO_const {
            static const Char nl = '\n';
            static const Char sp = ' ';











        }

        namespace int_const {
            static const Int nil = 0;
            static const Int one = 1;
        }

        template<class T, class U>
        auto MakePair(const T &a, const U &b) {
            return MakePairNamespace::MakePairFunction<T, U>::MakePair(a, b);
        }







        template<class... Args>\
        using new_container_name = Wrapper<old_container_name<Args...>>;

        NEW_STANDARD_CONTAINER(array, Array);

        NEW_STANDARD_CONTAINER(vector, Vector);

        NEW_STANDARD_CONTAINER(deque, Deque);

        NEW_STANDARD_CONTAINER(forward_list, Forward_list);

        NEW_STANDARD_CONTAINER(list, List);

        NEW_STANDARD_CONTAINER(set, Set);

        NEW_STANDARD_CONTAINER(multiset, Multiset);

        NEW_STANDARD_CONTAINER(map, Map);

        NEW_STANDARD_CONTAINER(multimap, Multimap);

        NEW_STANDARD_CONTAINER(unordered_set, Unordered_set);

        NEW_STANDARD_CONTAINER(unordered_multiset, Unordered_multiset);

        NEW_STANDARD_CONTAINER(unordered_map, Unordered_map);

        NEW_STANDARD_CONTAINER(unordered_multimap, Unordered_multimap);

        NEW_STANDARD_CONTAINER(pair, Pair);













        template<class T, size_t size>
        struct aKa {
            using under = aKa<T, size - 1>;
            using inside = typename under::type;
            using type = Wrapper<vector<inside>>;
        };

        template<class T>
        struct aKa <T, 0> {
            using type = Wrapper<T>;
        };






        template<class T, size_t size>
        using Veector = typename aKa<T, size>::type;










        using ll = LongLong;
        using ld = LongDouble;

        using cint = const Int;
        using cll = const LongLong;

        using vi = Vector<Int>;
        using vll = Vector<LongLong>;
        using si = Set<Int>;
        using sll = Set<LongLong>;
        using mi = Map<Int, Int>;
        using mlli = Map<LongLong, Int>;
        using mill = Map<Int, LongLong>;
    }
}














using WrapperClass::Wrapper;
using namespace WrapperClass::ExtraThings;
using namespace WrapperClass::ExtraThings::IO_const;












FILE *operator << (FILE *out, function<FILE *(FILE *)> func) {



    return func(out);
}





void dfg(Int &&a) {
    a += 10;


}

void ep(int &a) {
    int *p = &a;
    --p;
    cout << *p << endl;
}



















































Wrapper<unsigned long long> operator "" _i(unsigned long long a) {
    return a;
}

Wrapper<const char *> operator "" _s(const char *s, size_t size) {
    return s;
}

Wrapper<char> operator "" _c(char c) {
    return c;
}

using WrapperClass::file_manipulator;


struct fuf {
    int x;

    fuf (int a) : x(a) {}

    bool operator < (const fuf &a) const {
        return x > a.x;
    }
};

struct of : fuf {
    of (int a) : fuf(a) {}







};







































int main() {






















































    LongLong n, k;
    Cin >> n >> k;





    Vector<LongLong> pows;



    if (k == 1)
        pows.push_back(1);
    else if (k == -1)
        pows.push_back(-1), pows.push_back(1);
    else {
        for (LongLong t = 1; (t < 0 ? -t : t) < 1000000LL * 1000000000; t *= k) {
            pows.push_back(t);
        }
    }



    Vector<LongLong> a;
    a.resize(n);
    for (Int i = 0; i < n; ++i) {
        Cin >> a[i];
    }










    Vector<LongLong> pref_sum;
    pref_sum.resize(n + 1);


    pref_sum[0] = 0;


    for (Int i = 0; i < n; ++i) {
        pref_sum[i + 1] = pref_sum[i] + a[i];
    }



    Vector<Pair<LongLong, LongLong>> sums;
    sums.resize(n + 1);


    for (Int i = 0; i < n + 1; ++i) {
        sums[i] = Pair<LongLong, LongLong>(pref_sum[i], (LongLong)i - 1);
    }

    sort(ALL(sums));






    LongLong ans = 0;


    for (Int i = 0; i < n; ++i) {
        for (LongLong pw : pows) {
            LongLong cur_search = pref_sum[i + 1] - pw;

            auto it1 = lower_bound(ALL(sums), Pair<LongLong, LongLong>(cur_search, (LongLong)(-1)));
            auto it2 = upper_bound(ALL(sums), Pair<LongLong, LongLong>(cur_search, (LongLong)i - 1));

            Int sum = (it2 - it1);
            sum = sum < 0 ? (Int)0 : sum;



            ans += sum;
        }
    }



    Cout << ans;


    in.close();
	out.close();

    return 0;
}
















































































































































































































































































































































































































































































































































































