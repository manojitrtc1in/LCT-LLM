

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>







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













































































































































































































































































































































































































































































































#define WRAPPER_BIN_OPERATOR_CONST(return_type, op) template<class U>\
        return_type operator op (const U &a) const {\
            return return_type((x op (T)a));\
}

#define WRAPPER_BIN_OPERATOR(op) template<class U>\
    Wrapper &operator op (const U &a) {\
    x op (T)a;\
    return *this;\
}

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, !=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, %);

        WRAPPER_BIN_OPERATOR(%=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, &);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, &&);

        WRAPPER_BIN_OPERATOR(&=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, *);

        WRAPPER_BIN_OPERATOR(*=);













        template<class U> auto operator + (const U &a) const;

        WRAPPER_BIN_OPERATOR(+=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, -);

        WRAPPER_BIN_OPERATOR(-=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, /);

        WRAPPER_BIN_OPERATOR(/=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, <);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, <<);

        WRAPPER_BIN_OPERATOR(<<=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, <=);

        WRAPPER_BIN_OPERATOR(=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, ==);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, >);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, >=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, >>);

        WRAPPER_BIN_OPERATOR(>>=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, ^);

        WRAPPER_BIN_OPERATOR(^=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper, |);

        WRAPPER_BIN_OPERATOR(|=);

        WRAPPER_BIN_OPERATOR_CONST(Wrapper<bool>, ||);












#undef WRAPPER_BIN_OPERATOR_CONST
#undef WRAPPER_BIN_OPERATOR


#define WRAPPER_UN_OPERATOR_CONST(return_type, op) return_type operator op () const {\
    return return_type(op x);\
}

        WRAPPER_UN_OPERATOR_CONST(Wrapper<bool>, !);
        

        

        WRAPPER_UN_OPERATOR_CONST(Wrapper, +);

        WRAPPER_UN_OPERATOR_CONST(Wrapper, -);

        WRAPPER_UN_OPERATOR_CONST(Wrapper, ~);


        

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

#undef WRAPPER_UN_OPERATOR_CONST


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


#define WRAPPER_INPUT_FILE(type, qualifier) \
FILE *operator >> (FILE *in, Wrapper<type> &a) {\
    fscanf(in, "%"#qualifier, &a.get_data());\
    return in;\
}

    FILE *operator >> (FILE *in, Wrapper<bool> &a) {
        int tmp;
        fscanf(in, "%d", &tmp);
        a.get_data() = (bool)tmp;
        return in;
    }

    WRAPPER_INPUT_FILE(signed char, c);

    WRAPPER_INPUT_FILE(short, hd);

    WRAPPER_INPUT_FILE(int, d);

    WRAPPER_INPUT_FILE(long, ld);

    WRAPPER_INPUT_FILE(long long, lld);

    WRAPPER_INPUT_FILE(float, f);

    WRAPPER_INPUT_FILE(double, lf);

    WRAPPER_INPUT_FILE(long double, Lf);

    WRAPPER_INPUT_FILE(unsigned char, c);

    WRAPPER_INPUT_FILE(unsigned short, hu);

    WRAPPER_INPUT_FILE(unsigned, u);

    WRAPPER_INPUT_FILE(unsigned long, lu);

    WRAPPER_INPUT_FILE(unsigned long long, llu);

    


    FILE *operator >> (FILE *in, Wrapper<string> &a) {
        fscanf(in, "%s", details::Buffer);
        a = string(details::Buffer);
        return in;
    }

#undef WRAPPER_INPUT_FILE


#define WRAPPER_OUTPUT_FILE(type, qualifier) \
FILE *operator << (FILE *out, const Wrapper<type> &a) {\
    fprintf(out, "%"#qualifier, a.get_data());\
    return out;\
}

    WRAPPER_OUTPUT_FILE(bool, d);

    WRAPPER_OUTPUT_FILE(signed char, c);

    WRAPPER_OUTPUT_FILE(short, hd);

    WRAPPER_OUTPUT_FILE(int, d);

    WRAPPER_OUTPUT_FILE(long, ld);

    WRAPPER_OUTPUT_FILE(long long, lld);

    WRAPPER_OUTPUT_FILE(float, f);

    WRAPPER_OUTPUT_FILE(double, f);

    WRAPPER_OUTPUT_FILE(long double, Lf);

    WRAPPER_OUTPUT_FILE(unsigned char, c);

    WRAPPER_OUTPUT_FILE(unsigned short, hu);

    WRAPPER_OUTPUT_FILE(unsigned, u);

    WRAPPER_OUTPUT_FILE(unsigned long, lu);

    WRAPPER_OUTPUT_FILE(unsigned long long, llu);

    WRAPPER_OUTPUT_FILE(char *, s);

    WRAPPER_OUTPUT_FILE(const char *, s);

    FILE *operator << (FILE *out, const Wrapper<string> &a) {
        strncpy(details::Buffer, a.c_str(), sizeof(details::Buffer));
        details::Buffer[sizeof(details::Buffer) - 1] = 0;
        fprintf(out, "%s", details::Buffer);
        return out;
    }

    FILE *operator << (FILE *out, Wrapper<file_manipulator> func) {


        return func(out);
    }

    WRAPPER_OUTPUT_FILE(char, c);













    

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


#undef WRAPPER_OUTPUT_FILE











    

    

    



    namespace NamespaceForAuxiliaryNamespaces {}

    namespace MakePairNamespace {
#define MAKE_PAIR_FUNC(A, B) \
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

#undef MAKE_PAIR_FUNC







































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


#define Cout stdout
#define Cin stdin


#define NEW_STANDARD_CONTAINER(old_container_name, new_container_name) \
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







#undef NEW_STANDARD_CONTAINER


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







#include <functional>




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








#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>




#define FOR(i, s, f) for (decltype(s) (i) = (s); (i) < (f); ++(i))

#define forn(i, f) FOR((i), 0, (f))

#define ALL(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


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

#ifdef FILEIO
    in.close();
	out.close();
#endif
    return 0;
}
















































































































































































































































































































































































































































































































































































