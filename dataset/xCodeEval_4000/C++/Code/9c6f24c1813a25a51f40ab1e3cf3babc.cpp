
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <experimental/random>

class EmptyList { };
class EmptyDict { };

template <class T, class S>
struct CommonType { };

struct String;

template <class T>
struct List {
    std::shared_ptr<std::vector<T>> inner;

    List() : inner(std::shared_ptr<std::vector<T>>(new std::vector<T>())) {}
    List(std::vector<T> a) : inner(std::shared_ptr<std::vector<T>>(new std::vector<T>(a))) {}
    template <class S>
    List(List<S> a) : inner(std::shared_ptr<std::vector<T>>(new std::vector<T>(a.inner->begin(), a.inner->end()))) {}
    List(EmptyList) : inner(std::shared_ptr<std::vector<T>>(new std::vector<T>())) {}
    T &operator[](size_t index) { return (*inner)[index]; }
    const T &operator[](size_t index) const { return (*inner)[index]; }
    void push(T value) { inner->push_back(value); }
    void pop() { inner->pop_back(); }
    int64_t length() const { return inner->size(); }

    template <class SortFn>
    void sort(SortFn sortFn) { std::sort(inner->begin(), inner->end(), sortFn); }

    template <class S>
    List<typename CommonType<T, S>::inner> concat(List<S> other) { List<typename CommonType<T, S>::inner> ret = EmptyList(); ret.inner->insert(ret.inner->end(), inner->begin(), inner->end()); ret.inner->insert(ret.inner->end(), other.inner->begin(), other.inner->end()); return ret; }
    String join(String delim);
};

struct String {
    std::shared_ptr<std::string> inner;

    String() : inner(std::shared_ptr<std::string>(new std::string())) {}
    String(const char* a) : inner(std::shared_ptr<std::string>(new std::string(a))) {}
    String(std::string a) : inner(std::shared_ptr<std::string>(new std::string(a))) {}
    String operator +(String other) { return String(*inner + *other.inner); }
    operator std::string() { return *inner; }
    String operator[](size_t index) const { return String(std::string({(*inner)[index]})); }
    int64_t charCodeAt(size_t index) const { return (*inner)[index]; }
    String operator+(String &other) const { return String(*inner + *other.inner); }
    String& operator+=(const String &other) { *inner += *other.inner; return *this; }
    char operator <(const String &other) const { return *inner < *other.inner; }
    char operator >(const String &other) const { return *inner > *other.inner; }
    char operator <=(const String &other) const { return *inner <= *other.inner; }
    char operator >=(const String &other) const { return *inner >= *other.inner; }
    char operator ==(const String &other) const { return *inner == *other.inner; }
    char operator !=(const String &other) const { return *inner != *other.inner; }
    int64_t length() const { return inner->size(); }

    String trim() {
        std::string s = *inner;
        const char* ws = " \t\n\r\f\v";
        s.erase(s.find_last_not_of(ws) + 1);
        s.erase(0, s.find_first_not_of(ws));
        return String(s);
    }
    List<String> split(String delim) { std::vector<String> ret; size_t last = 0; size_t next = 0; while ((next = inner->find(*delim.inner, last)) != std::string::npos) {   ret.push_back(String(inner->substr(last, next-last)));   last = next + delim.length(); } ret.push_back(String(inner->substr(last))); return ret; }
};

template<> String List<String>::join(String delim) {
    std::string ret; bool first = true; for (const auto& it: *inner) { if (!first) ret += *delim.inner; first = false; ret += *it.inner; } return ret;
}

template <class K, class V> 
struct Dict {
    using Inner = __gnu_pbds::tree<K, V, std::less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
    std::shared_ptr<Inner> inner;

    Dict() : inner(std::shared_ptr<Inner>(new Inner())) {}
    Dict(std::vector<std::pair<K, V>> a) : inner(std::shared_ptr<Inner>(new Inner(a.begin(), a.end()))) {}
    template <class K2, class V2>
    Dict(Dict<K2, V2> a) : inner(std::shared_ptr<Inner>(new Inner(a.inner->begin(), a.inner->end()))) {}
    Dict(EmptyDict) : inner(std::shared_ptr<Inner>(new Inner())) {}
    V &operator[](K key) { return (*inner)[key]; }
    const V &operator[](K key) const { return (*inner)[key]; }
    int64_t length() const { return inner->size(); }
    bool contains(const K& k) const { return inner->find(k) != inner->end(); }
    void remove(const K& k) const { inner->erase(k); }
    K keyAt(int64_t pos) const { return inner->find_by_order(pos)->first; }
    int64_t bisect(const K& value) const { return inner->order_of_key(value); }

    List<K> keys() const { std::vector<K> ret; for (auto const& it: *inner) { ret.push_back(it.first); }; return List<K>(ret); }
};

template <class T> struct CommonType<List<T>, EmptyList> { using inner = List<T>; };
template <class T> struct CommonType<EmptyList, List<T>> { using inner = List<T>; };
template <class T, class S> struct CommonType<List<T>, List<S>> { using inner = List<typename CommonType<T, S>::inner>; };

template <class T> struct CommonType<std::nullptr_t, std::shared_ptr<T>> { using inner = std::shared_ptr<T>; };
template <class T> struct CommonType<std::shared_ptr<T>, std::nullptr_t> { using inner = std::shared_ptr<T>; };

template <class K, class V> struct CommonType<Dict<K, V>, EmptyDict> { using inner = Dict<K, V>; };
template <class K, class V> struct CommonType<EmptyDict, Dict<K, V>> { using inner = Dict<K, V>; };
template <class K, class V, class K2, class V2> struct CommonType<Dict<K, V>, Dict<K2, V2>> { using inner = Dict<typename CommonType<K, K2>::inner, typename CommonType<V, V2>::inner>; };

template <> struct CommonType<int64_t, int64_t> { using inner = int64_t; };
template <> struct CommonType<EmptyList, EmptyList> { using inner = EmptyList; };
template <> struct CommonType<EmptyDict, EmptyDict> { using inner = EmptyDict; };
template <> struct CommonType<std::nullptr_t, std::nullptr_t> { using inner = std::nullptr_t; };
template <> struct CommonType<char, char> { using inner = char; };
template <> struct CommonType<String, String> { using inner = String; };

int64_t cast_int(int64_t x) { return x; }
int64_t cast_int(double x) { return x; }
int64_t cast_int(String x) { return std::strtoll(x.inner->c_str(), NULL, 10); }

double cast_float(int64_t x) { return x; }
double cast_float(double x) { return x; }
double cast_float(String x) { return std::strtod(x.inner->c_str(), NULL); }

String cast_str(int64_t x) { return String(std::to_string(x)); }
String cast_str(double x) { return String(std::to_string(x)); }
String cast_str(bool x) { return String(std::to_string(x)); }
String cast_str(String x) { return x; }

bool rand_bool() { return rand() % 100 < 50; }
int64_t rand_int(int64_t upper) { return std::experimental::randint(int64_t(0), upper); }
String chr(int64_t x) { return String(std::string({(char)x})); }

template <class T>
struct TypeHolder { };

template <class T, class S, class Filter, class Mapper>
List<T> linq(const List<S> &input, Filter filter, Mapper mapper, TypeHolder<T> type_holder) {
    List<T> ret;
    for (const auto &it: *input.inner) {
        if (filter(it)) {
            ret.push(mapper(it));
        }
    }
    return ret;
}

struct kek;
int64_t func(List<int64_t> pw, List<int64_t> hs, int64_t mod, int64_t x, int64_t y, int64_t k);
std::shared_ptr<kek> g(String s, List<int64_t> pw, List<int64_t> hs, int64_t mod, int64_t x, int64_t y, int64_t n);
char SORT(List<int64_t> p, String s, List<int64_t> pw, List<int64_t> hs, int64_t mod, int64_t l, int64_t r, int64_t n);
int64_t get(List<List<int64_t>> s_p, List<int64_t> lg, List<int64_t> lg2, int64_t l, int64_t r);
String solve(String input);
struct kek{int64_t a;int64_t b;};
int64_t func(List<int64_t> pw, List<int64_t> hs, int64_t mod, int64_t x, int64_t y, int64_t k) {
int64_t a = (hs)[((x+k)-1ll)];
if ((x>0ll)) {
a-=(hs)[(x-1ll)];
}
if ((a<0ll)) {
a+=mod;
}
int64_t b = (hs)[((y+k)-1ll)];
if ((y>0ll)) {
b-=(hs)[(y-1ll)];
}
if ((b<0ll)) {
b+=mod;
}
a = (((a*(pw)[y]))%mod);
b = (((b*(pw)[x]))%mod);
if ((a==b)) {
return 1ll;
}
return 0ll;
}
std::shared_ptr<kek> g(String s, List<int64_t> pw, List<int64_t> hs, int64_t mod, int64_t x, int64_t y, int64_t n) {
std::shared_ptr<kek> ans = std::shared_ptr<kek>(new kek{0ll,0ll});
if ((x==y)) {
ans->b = (n-x);
return ans;
}
int64_t l = 1ll;
int64_t r = (n-x);
if ((r>(n-y))) {
r = (n-y);
}
while ((l<=r)) {
int64_t c = (((l+r))/2ll);
if (((func)(pw, hs, mod, x, y, c)==1ll)) {
ans->b = c;
l = (c+1ll);
} else {r = (c-1ll);
}

}
if (((x+ans->b)==n)) {
return ans;
}
if (((y+ans->b)==n)) {
ans->a = 1ll;
return ans;
}
if (((int64_t)((s).charCodeAt((x+ans->b)))<(int64_t)((s).charCodeAt((y+ans->b))))) {
return ans;
}
ans->a = 1ll;
return ans;
}
char SORT(List<int64_t> p, String s, List<int64_t> pw, List<int64_t> hs, int64_t mod, int64_t l, int64_t r, int64_t n) {
if ((l==r)) {
return true;
}
int64_t c = (((l+r))/2ll);
(SORT)(p, s, pw, hs, mod, l, c, n);
(SORT)(p, s, pw, hs, mod, (c+1ll), r, n);
List<int64_t> tmp = EmptyList();
int64_t l1 = l;
int64_t l2 = (c+1ll);
while (((l1<=c)&&(l2<=r))) {
if (((g)(s, pw, hs, mod, (p)[l1], (p)[l2], n)->a==0ll)) {
(tmp).push((p)[l1]);
l1+=1ll;
} else {(tmp).push((p)[l2]);
l2+=1ll;
}

}
while ((l1<=c)) {
(tmp).push((p)[l1]);
l1+=1ll;

}
while ((l2<=r)) {
(tmp).push((p)[l2]);
l2+=1ll;

}
for (int64_t i = 0ll; (i<(int64_t)((tmp).length())); i+=1ll) {
(p)[(i+l)] = (tmp)[i];

}
return true;
}
int64_t get(List<List<int64_t>> s_p, List<int64_t> lg, List<int64_t> lg2, int64_t l, int64_t r) {
int64_t d = (lg)[((r-l)+1ll)];
int64_t cur_mn = ((s_p)[d])[l];
if ((cur_mn>((s_p)[d])[((r-(lg2)[d])+1ll)])) {
cur_mn = ((s_p)[d])[((r-(lg2)[d])+1ll)];
}
return cur_mn;
}
String solve(String input) {
List<String> lines = (input).split(String("\n"));
int64_t T = cast_int((lines)[0ll]);
int64_t cur_line = 0ll;
String ans = String("");
List<int64_t> lg = EmptyList();
List<int64_t> lg2 = EmptyList();
List<List<int64_t>> s_p = EmptyList();
(lg).push(0ll);
(lg).push(0ll);
for (int64_t i = 2ll; (i<=5000ll); i+=1ll) {
(lg).push(((lg)[(i/2ll)]+1ll));

}
(lg2).push(1ll);
for (int64_t i = 1ll; (i<=12ll); i+=1ll) {
(lg2).push(((lg2)[(i-1ll)]*2ll));

}
for (int64_t i = 0ll; (i<=12ll); i+=1ll) {
List<int64_t> tmp2 = EmptyList();
for (int64_t j = 0ll; (j<=5000ll); j+=1ll) {
(tmp2).push(1000000ll);

}
(s_p).push(linq(tmp2, [=](int64_t _) { return true;  }, [=](int64_t _) { return cast_int(_); }, TypeHolder<int64_t>()));

}
for (int64_t z = 0ll; (z<T); z+=1ll) {
cur_line+=1ll;
int64_t n = cast_int((lines)[cur_line]);
cur_line+=1ll;
String s = (lines)[cur_line];
List<int64_t> pw = EmptyList();
List<int64_t> hs = EmptyList();
int64_t mod = 1000000103ll;
(pw).push(1ll);
List<int64_t> p = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(p).push(i);
(pw).push(((((pw)[i]*31ll))%mod));
(hs).push(0ll);
if ((i>0ll)) {
(hs)[i] = (hs)[(i-1ll)];
}
(hs)[i]+=((((pw)[i]*(((int64_t)((s).charCodeAt(i))-96ll))))%mod);
(hs)[i]%=mod;

}
(SORT)(p, s, pw, hs, mod, 0ll, (n-1ll), n);
List<int64_t> L = EmptyList();
(L).push(0ll);
for (int64_t i = 1ll; (i<n); i+=1ll) {
(L).push((g)(s, pw, hs, mod, (p)[(i-1ll)], (p)[i], n)->b);

}
for (int64_t i = 0ll; (i<=12ll); i+=1ll) {
for (int64_t j = 0ll; (j<n); j+=1ll) {
((s_p)[i])[j] = 1000000ll;

}

}
for (int64_t i = 1ll; (i<n); i+=1ll) {
((s_p)[0ll])[i] = (L)[i];

}
for (int64_t i = 1ll; (i<=12ll); i+=1ll) {
for (int64_t j = 0ll; (j<=(n-(lg2)[i])); j+=1ll) {
int64_t cur_mn = ((s_p)[(i-1ll)])[j];
if ((cur_mn>((s_p)[(i-1ll)])[(j+(lg2)[(i-1ll)])])) {
cur_mn = ((s_p)[(i-1ll)])[(j+(lg2)[(i-1ll)])];
}
((s_p)[i])[j] = cur_mn;

}

}
List<int64_t> p2 = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(p2).push(0ll);

}
for (int64_t i = 0ll; (i<n); i+=1ll) {
(p2)[(p)[i]] = i;

}
List<int64_t> dp = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(dp).push((n-i));

}
String DBG = String("");
for (int64_t i = 0ll; (i<n); i+=1ll) {
for (int64_t j = (i+1ll); (j<n); j+=1ll) {
int64_t l = (p2)[i];
int64_t r = (p2)[j];
if ((l>=r)) {
continue;
}
int64_t cur_dp = ((((dp)[i]+n)-j)-(get)(s_p, lg, lg2, (l+1ll), r));
if (((dp)[j]<cur_dp)) {
(dp)[j] = cur_dp;
}

}

}
int64_t best = 0ll;
String dbg = String("");
for (int64_t i = 0ll; (i<n); i+=1ll) {
if ((best<(dp)[i])) {
best = (dp)[i];
}
dbg+=(cast_str((dp)[i])+String("\n"));

}
ans+=(cast_str(best)+String("\n"));

}
return ans;
}
int main() { std::ios::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ; std::string line, input; while (std::getline(std::cin, line)) { input += line + "\n"; } std::cout << *solve(String(input)).inner; return 0; }