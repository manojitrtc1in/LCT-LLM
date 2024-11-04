





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

int64_t cast_int(long int x) { return x; }
int64_t cast_int(long long int x) { return x; }
int64_t cast_int(double x) { return x; }
int64_t cast_int(String x) { return std::strtoll(x.inner->c_str(), NULL, 10); }

double cast_float(long int x) { return x; }
double cast_float(long long int x) { return x; }
double cast_float(double x) { return x; }
double cast_float(String x) { return std::strtod(x.inner->c_str(), NULL); }

String cast_str(long int x) { return String(std::to_string(x)); }
String cast_str(long long int x) { return String(std::to_string(x)); }
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

struct edge2;struct edge3;
char edge2$less(std::shared_ptr<edge2> self, std::shared_ptr<edge2> other);
void edge3$edge(std::shared_ptr<edge3> self);
char edge3$less(std::shared_ptr<edge3> self, std::shared_ptr<edge3> other);
int64_t getp(List<int64_t> p, int64_t a);
int64_t _abs(int64_t v);
char _min(std::shared_ptr<edge3> a, std::shared_ptr<edge3> b);
char unite(List<int64_t> p, List<int64_t> rk, int64_t a, int64_t b);
int64_t _max(int64_t v1, int64_t v2);
void dfs(List<List<std::shared_ptr<edge2>>> g, List<int64_t> mn, int64_t v, int64_t p, int64_t d);
String solve(String input);
struct edge2{int64_t u;int64_t w;};
bool operator < (std::shared_ptr<edge2> self, std::shared_ptr<edge2> other) {
return (self->u<other->u);
}
struct edge3{int64_t v;int64_t u;int64_t w;};
bool operator < (std::shared_ptr<edge3> self, std::shared_ptr<edge3> other) {
return (_min)(self, other);
}
char edge2$less(std::shared_ptr<edge2> self, std::shared_ptr<edge2> other) {
return (self->u<other->u);
}
void edge3$edge(std::shared_ptr<edge3> self) {
if ((self->v>self->u)) {
int64_t t = self->v;
self->v = self->u;
self->u = t;
}
}
char edge3$less(std::shared_ptr<edge3> self, std::shared_ptr<edge3> other) {
return (_min)(self, other);
}
int64_t getp(List<int64_t> p, int64_t a) {
if ((a==(p)[a])) {
return a;
} else {(p)[a] = (getp)(p, (p)[a]);
return (p)[a];
}
}
int64_t _abs(int64_t v) {
if ((v<0ll)) {
return - v;
} else {return v;
}
}
char _min(std::shared_ptr<edge3> a, std::shared_ptr<edge3> b) {
if ((a->w!=b->w)) {
return (a->w<b->w);
}
if ((a->v!=b->v)) {
return (a->v<b->v);
}
return (a->u<b->u);
}
char unite(List<int64_t> p, List<int64_t> rk, int64_t a, int64_t b) {
a = (getp)(p, a);
b = (getp)(p, b);
if ((a==b)) {
return false;
}
if (((rk)[a]<(rk)[b])) {
int64_t t = a;
a = b;
b = t;
}
(rk)[a]+=(rk)[b];
(p)[b] = a;
return true;
}
int64_t _max(int64_t v1, int64_t v2) {
if ((v1>v2)) {
return v1;
} else {return v2;
}
}
void dfs(List<List<std::shared_ptr<edge2>>> g, List<int64_t> mn, int64_t v, int64_t p, int64_t d) {
(mn)[v] = d;
for (int64_t i = 0ll; (i<(int64_t)(((g)[v]).length())); i+=1ll) {
if ((((g)[v])[i]->u!=p)) {
(dfs)(g, mn, ((g)[v])[i]->u, v, (_max)(d, ((g)[v])[i]->w));
}

}
}
String solve(String input) {
List<List<String>> lines = linq((input).split(String("\n")), [=](String x) { return true;  }, [=](String x) { return (x).split(String(" ")); }, TypeHolder<List<String>>());
int64_t n = cast_int(((lines)[0ll])[0ll]);
int64_t q = cast_int(((lines)[0ll])[1ll]);
int64_t s = cast_int(((lines)[0ll])[2ll]);
int64_t d = cast_int(((lines)[0ll])[3ll]);
List<int64_t> a = linq((lines)[1ll], [=](String x) { return true;  }, [=](String x) { return cast_int(x); }, TypeHolder<int64_t>());
s-=1ll;
List<int64_t> p = EmptyList();
List<int64_t> rk = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(p).push(i);
(rk).push(1ll);

}
List<List<std::shared_ptr<edge2>>> g = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(g).push(EmptyList());

}
int64_t cnt = n;
int64_t iter = 0ll;
int64_t inf = 1000000000ll;
while ((cnt>1ll)) {
iter+=1ll;
List<std::shared_ptr<edge3>> es = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(es).push(std::shared_ptr<edge3>(new edge3{- 1ll,- 1ll,inf}));

}
int64_t j = 0ll;
int64_t mn1 = - 1ll;
int64_t mn2 = - 1ll;
for (int64_t i = 0ll; (i<n); i+=1ll) {
(getp)(p, i);

}
for (int64_t i = 0ll; (i<n); i+=1ll) {
while (((j<n)&&(((a)[i]-(a)[j])>d))) {
if (((mn1==- 1ll)||((p)[mn1]==(p)[j]))) {
mn1 = j;
} else {mn2 = mn1;
mn1 = j;
}
j+=1ll;

}
if (((mn1!=- 1ll)&&((p)[mn1]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}
if (((mn2!=- 1ll)&&((p)[mn2]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}

}
j = 0ll;
mn1 = - 1ll;
mn2 = - 1ll;
for (int64_t i = 0ll; (i<n); i+=1ll) {
while (((j<n)&&(((a)[j]-(a)[i])<=d))) {
if (((mn1==- 1ll)||((p)[mn1]==(p)[j]))) {
mn1 = j;
} else {mn2 = mn1;
mn1 = j;
}
j+=1ll;

}
if (((mn1!=- 1ll)&&((p)[mn1]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}
if (((mn2!=- 1ll)&&((p)[mn2]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}

}
j = (n-1ll);
mn1 = - 1ll;
mn2 = - 1ll;
for (int64_t i = (n-1ll); (i>=0ll); i-=1ll) {
while (((j>=0ll)&&(((a)[j]-(a)[i])>d))) {
if (((mn1==- 1ll)||((p)[mn1]==(p)[j]))) {
mn1 = j;
} else {mn2 = mn1;
mn1 = j;
}
j-=1ll;

}
if (((mn1!=- 1ll)&&((p)[mn1]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}
if (((mn2!=- 1ll)&&((p)[mn2]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}

}
j = (n-1ll);
mn1 = - 1ll;
mn2 = - 1ll;
for (int64_t i = (n-1ll); (i>=0ll); i-=1ll) {
while (((j>=0ll)&&(((a)[i]-(a)[j])<=d))) {
if (((mn1==- 1ll)||((p)[mn1]==(p)[j]))) {
mn1 = j;
} else {mn2 = mn1;
mn1 = j;
}
j-=1ll;

}
if (((mn1!=- 1ll)&&((p)[mn1]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn1,i,(_abs)(((_abs)(((a)[i]-(a)[mn1]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}
if (((mn2!=- 1ll)&&((p)[mn2]!=(p)[i]))) {
std::shared_ptr<edge3> tmp = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)(tmp);
if (!(_min)((es)[(p)[i]], tmp)) {
(es)[(p)[i]] = std::shared_ptr<edge3>(new edge3{mn2,i,(_abs)(((_abs)(((a)[i]-(a)[mn2]))-d))});
(edge3$edge)((es)[(p)[i]]);
}
}

}
for (int64_t i = 0ll; (i<n); i+=1ll) {
if (((es)[i]->v!=- 1ll)) {
if ((unite)(p, rk, (es)[i]->v, (es)[i]->u)) {
cnt-=1ll;
((g)[(es)[i]->v]).push(std::shared_ptr<edge2>(new edge2{(es)[i]->u,(es)[i]->w}));
((g)[(es)[i]->u]).push(std::shared_ptr<edge2>(new edge2{(es)[i]->v,(es)[i]->w}));
}
}

}

}
List<int64_t> mn = EmptyList();
for (int64_t i = 0ll; (i<n); i+=1ll) {
(mn).push(0ll);

}
String res = String("");
(dfs)(g, mn, s, - 1ll, 0ll);
for (int64_t i = 2ll; (i<(q+2ll)); i+=1ll) {
if (((mn)[(cast_int(((lines)[i])[0ll])-1ll)]<=cast_int(((lines)[i])[1ll]))) {
res+=String("Yes");
} else {res+=String("No");
}
if ((i!=(q+1ll))) {
res+=String("\n");
}

}
return res;
}
int main() {  std::ios::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ; std::string line, input; while (std::getline(std::cin, line)) { input += line + "\n"; } std::cout << *solve(String(input)).inner; return 0; }