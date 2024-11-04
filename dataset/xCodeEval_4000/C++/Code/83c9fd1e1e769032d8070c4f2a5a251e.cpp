

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

        Wrapper(const Wrapper &a) {
            x = a.x;
        }

        T &get_data() {
            return x;
        }

        T get_data() const {
            return x;
        }

        void set_data(const T &a) {
            x = a;
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













        template<class U> auto operator + (const U &a);

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
            static auto sum(const Wrapper<T> &a, const U &b) {
                return Wrapper<decltype(T() + U())>(a.get_data() + b);
            }
        };

        template<class T, class U>
        struct sss <T, Wrapper<U>> {
            static auto sum(const Wrapper<T> &a, const Wrapper<U> &b) {
                return Wrapper<decltype(T() + U())>(a.get_data() + b.get_data());
            }
        };
    }

    template<class T>
    template<class U>
    auto Wrapper<T>::operator + (const U &a) {
        return extra::sss<T, U>::sum(*this, a);
    }




    template<template<class...> class T, class... Args>
    class Wrapper <T<Args...>> : public T<Args...> {

    public:
        template<class... Arguments>
        Wrapper(Arguments... args) : T<Args...>(args...) {}

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

    


    FILE *operator << (FILE *out, const Wrapper<string> &a) {
        strncpy(details::Buffer, a.c_str(), sizeof(details::Buffer));
        details::Buffer[sizeof(details::Buffer) - 1] = 0;
        fprintf(out, "%s", details::Buffer);
        return out;
    }


    

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


    template<class T>
    Wrapper<bool> operator < (int a, const Wrapper<T> &b) {
        return a < (int)b;
    }

    namespace MakePairNamespace {
        template <class T, class U>
        struct MakePairFunction {
            static auto MakePair(const T &a, const U &b) {
                return Wrapper<pair<Wrapper<T>, Wrapper<U>>>(a, b);
            }
        };

        template <class T, class U>
        struct MakePairFunction <Wrapper<T>, U> {
            static auto MakePair(const Wrapper<T> &a, const U &b) {
                return Wrapper<pair<Wrapper<T>, Wrapper<U>>>(a, b);
            }
        };

        template <class T, class U>
        struct MakePairFunction <T, Wrapper<U>> {
            static auto MakePair(const T &a, const Wrapper<U> &b) {
                return Wrapper<pair<Wrapper<T>, Wrapper<U>>>(a, b);
            }
        };

        template <class T, class U>
        struct MakePairFunction <Wrapper<T>, Wrapper<U>> {
            static auto MakePair(const Wrapper<T> &a, const Wrapper<U> &b) {
                return Wrapper<pair<Wrapper<T>, Wrapper<U>>>(a, b);
            }
        };
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

        static const Char nl = '\n';
        static const Char sp = ' ';

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







#undef NEW_STANDARD_CONTAINER


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






struct vec {
    Int id;
    vi *a;

    vec (vi &v) : a(&v) {}

    vec () {}

    bool operator < (const vec &b) const {
        return (a->back() > (b.a)->back());
    }
};


#define ALL(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MAXN3 = 3e5 + 3;

Vector<vec> a;
Vector<vi> QQQ;
Vector<Bool> used;

int main()
{
    a.resize(MAXN3);
    QQQ.resize(MAXN3);
    used.resize(MAXN3);

    Int n;
    Cin >> n;

    for (int i = 0; i < n; ++i) {
        a[i].id = i + 1;
        a[i].a = &(QQQ[i]);
    }

    Set<vec> s;
    for (Int i = 0; i < n; ++i) {
        Int q, w;
        Cin >> q >> w;
        --q;

        (a[q].a)->push_back(w);
    }

    for (Int i = 0; i < n; ++i) {
        if ((a[i].a)->size() > 0) {
            s.insert(a[i]);
            used[i] = true;
        }
    }

    Int q;
    Cin >> q;
    for (int i = 0; i < q; ++i) {
        Int k;
        Cin >> k;

        vi l;
        l.resize(k);
        for (Int j = 0; j < k; ++j) {
            Cin >> l[j];
        }

        for (Int j = 0; j < sz(l); ++j) {
            if (used[l[j] - 1])
                s.erase(a[l[j] - 1]);
        }

        if (s.size() == 0) {
            Cout << String("0 0\n");
        } else {
            auto it = s.begin();
            vec fir = *it;
            s.erase(it);

            Cout << fir.id << sp;

            if (s.size() == 0) {
                Cout << (fir.a)->at(0) << nl;
            } else {
                auto it2 = s.begin();
                vec sec = *it2;

                Int lower = (sec.a)->back();
                auto it3 = upper_bound(ALL(*(fir.a)), lower);

                Cout << *it3 << nl;
            }

            s.insert(fir);
        }

        for (int j = 0; j < sz(l); ++j) {
            if (used[l[j] - 1])
                s.insert(a[l[j] - 1]);
        }
    }

    return 0;
}
































