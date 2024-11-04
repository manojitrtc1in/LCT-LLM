















































using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;












template <typename T>
bool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <typename T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }
























namespace impl {
  template <typename T, typename F, size_t... Is>
  F for_each(T& t, F f, index_sequence<Is...>) {
    auto l = { (f(get<Is>(t), Is), 0)... };
    (void) l;
    return f;
  }
}

template <typename... Ts, typename F>
F for_each(tuple<Ts...>& t, F f) { 
  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename... Ts, typename F>
F for_each(const tuple<Ts...>& t, F f) { 
  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});
}






template <typename T> true_type id1(typename T::const_iterator*);
template <typename T> false_type id1(...);
template <typename T> struct IsC : decltype(id1<T>(nullptr)) {};


template <> struct IsC<string> : false_type {};










template <typename T>
enable_if_t<IsC<T>::value, ostream&> operator<<(ostream&, const T&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);



template <typename... Ts>
ostream& operator<<(ostream& o, const tuple<Ts...>& t) {
    o << '(';
    for_each(t, [&](auto& x, size_t i) { if(i) o << ", "; o << x; });
    return o << ')';
}



template <typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
  return o << get<0>(t);
}



template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << '(' << p.fi << ", " << p.se << ')';
}



template <typename T>
enable_if_t<IsC<T>::value, ostream&> operator<<(ostream& o, const T& c) {
  o << '[';
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    o << *it << (next(it) != c.cend() ? ", " : "");
  return o << ']';
}








template <typename... Ts>
struct DB {
  string n;
  tuple<Ts...> d;
  DB(const string& ns, Ts... ds) : n{ns}, d{ds...} {}
  friend ostream& operator<<(ostream& o, const DB& db) {
    int i = 0;
    for_each(db.d, [&](const auto& e, int idx) {
      (idx ? o << " " : o) << "[";
      while (i < SZ(db.n) and issep(db.n[i])) ++i;
      while (i < SZ(db.n) and not issep(db.n[i])) o << db.n[i++];
      o << ": " << e << "]";
    });
    return o; 
  }
  static inline bool issep(char c) {
    return set<char>{' ', ','}.count(c);
  }
};
template <typename... Ts>
DB<Ts...> mkDB(const string& n, Ts... d) { return DB<Ts...>(n, d...); }














template <typename T, size_t N>
struct PP {
  

  const T& v; 
  

  shared_ptr<array<string, N>> se;
  

  size_t idx;
  PP(const T& value, shared_ptr<array<string, N>> p, size_t i = 0) 
      : v{value}, se{p}, idx{i} {}
};





template <typename T, size_t M>
enable_if_t<not IsC<T>::value, ostream&>
operator<<(ostream& o, const PP<T, M>& p) {
  return o << p.v;
}



template <size_t M, typename... Ts>
ostream& operator<<(ostream& o, const PP<tuple<Ts...>, M>& p) {
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  for_each(p.v, [&](auto& x, size_t i) { 
    if(i) o << sep; 
    o << PP<decay_t<decltype(x)>, M>(x, p.se, p.idx + 1);
  });
  return o;
}



template <typename T1, typename T2, size_t M>
ostream& operator<<(ostream& o, const PP<pair<T1, T2>, M>& p) {
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  return o << PP<T1, M>(p.v.fi, p.se, p.idx + 1) << sep
           << PP<T2, M>(p.v.se, p.se, p.idx + 1);
}



template <typename T, size_t M>
enable_if_t<IsC<T>::value, ostream&>
operator<<(ostream& o, const PP<T, M>& p) {
  

  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  

  for (auto it = p.v.cbegin(); it != p.v.cend(); ++it)
    o << PP<typename T::value_type, M>(*it, p.se, p.idx + 1)
      << (next(it) != p.v.cend() ? sep : "");
  return o;
}



template <typename T, typename... Ts, size_t N = sizeof...(Ts)>
PP<T, N> pp(const T& value, Ts... seps) {
  return PP<T, N>(value, make_shared<array<string, N>>(array<string, N>{seps...}));
}










template <typename T>
enable_if_t<IsC<T>::value, istream&> operator>>(istream&, T&);
template <typename T1, typename T2>
istream& operator>>(istream&, pair<T1, T2>&);



template <typename... Ts>
istream& operator>>(istream& i, tuple<Ts...>& t) {
  for_each(t, [&](auto& x, int) { i >> x; });
  return i;
}



template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& p) {
  return i >> p.fi >> p.se;
}



template <typename T>
enable_if_t<IsC<T>::value, istream&> operator>>(istream& i, T& v) {
  for (auto& x : v) i >> x;
  return i;
}
template<typename T>
set<T>& operator+=(set<T>& s, const T& e) {
  return s.insert(e), s;
}
template<typename T>
set<T>& operator-=(set<T>& s, const T& e) {
  return s.erase(e), s;
}
template<typename T>
set<T>& operator&=(set<T>& a, const set<T>& b) {
  set<T> o;
  set_intersection(ALL(a), ALL(b), inserter(o, o.begin()));
  return a.swap(o), a;
}
template<typename T>
set<T>& operator|=(set<T>& a, const set<T>& b) {
  return a.insert(ALL(b)), a;
}
template<typename T>
set<T> operator&(set<T> a, const set<T>& b) {
  return a &= b;
}
template<typename T>
set<T> operator|(set<T> a, const set<T>& b) {
  return a |= b;
}
template<typename T>
bool operator<(const set<T>& s, const T& e) {
  return static_cast<bool>(s.count(e));
}


















namespace impl {
  template <typename T, typename U, typename F, size_t... Is>
  T zipWith(const T& t, const U& u, F f, index_sequence<Is...>) { 
    return mt((static_cast<tuple_element_t<Is, T>>(f(get<Is>(t), get<Is>(u), Is)))...);
  }

  template <typename T, typename U, typename F, size_t... Is>
  F id3(T& t, const U& u, F f, index_sequence<Is...>) {
    auto l = { (f(get<Is>(t), get<Is>(u)), 0)... };
    (void) l;
    return f;
  }
}

template <typename... Ts, typename... Us, typename F>
tuple<Ts...> zipWith(const tuple<Ts...>& t, const tuple<Us...>& u, F f) { 
  static_assert(sizeof...(Ts) == sizeof...(Us), "Tuples must be the same size");
  return impl::zipWith(t, u, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename... Ts, typename... Us, typename F>
F id3(tuple<Ts...>& t, const tuple<Us...>& u, F f) { 
  static_assert(sizeof...(Ts) == sizeof...(Us), "Tuples must be the same size");
  return impl::id3(t, u, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename T> true_type id0(typename tuple_size<T>::type*);
template <typename T> false_type id0(...);
template <typename T> struct IsT : decltype(id0<T>(nullptr)) {};
template <typename T> true_type stream_check(typename T::off_type*);
template <typename T> false_type stream_check(...);
template <typename T> struct IsSt : decltype(stream_check<T>(nullptr)) {};
template <typename T> struct IsS : integral_constant<bool, IsT<T>::value or IsC<T>::value or IsSt<T>::value> {};


  template <typename T, typename U> \
  vector<T>& name(vector<T>&, const U&); \
  template <typename T, typename U> \
  vector<T>& name(vector<T>&, const vector<U>&);


  template <typename T, typename U> \
  vector<T>& name(vector<T>& v, const U& x) { \
    for (auto& i : v) i op x; \
    return v; \
  } \
  template <typename T, typename U> \
  vector<T>& name(vector<T>& v, const vector<U>& w) { \
    id4 (i, min(SZ(v), SZ(w))) v[i] op w[i]; \
    return v; \
  }


  template<typename T> \
  vector<T>& name(vector<T>&); \
  template<typename T> \
  vector<T> name(vector<T>&, int);


  template<typename T> \
  vector<T>& name(vector<T>& v) { \
    for (auto& x : v) op x; \
    return v; \
  } \
  template<typename T> \
  vector<T> name(vector<T>& v, int) { \
    vector<T> t{v}; \
    op v; \
    return t; \
  }


  template <typename T, typename U> \
  vector<T> name(vector<T>, const vector<U>&); \
  template <typename T, typename U> \
  vector<T> name(vector<T>, const U&); \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U&, vector<T>);


  template <typename T, typename U> \
  vector<T> name(vector<T> v, const vector<U>& u) { return v op u; } \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const U& u) { return v op u; } \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U& u, vector<T> v) { return v op u; }


  template <typename T, typename U> \
  vector<T> name(vector<T> v, const vector<U>& u) { return v op u; } \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const U& u) { return v op u; } \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U& u, vector<T> v) { for (auto& i : v) i = u ex i; return v; }


  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2>& name(pair<T1, T2>&, const pair<U1, U2>&); \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2>& name(pair<T1, T2>&, const U&); 


  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2>& name(pair<T1, T2>& p1, const pair<U1, U2>& p2) { \
    p1.fi op p2.fi; p1.se op p2.se; return p1; \
  } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2>& name(pair<T1, T2>& p, const U& u) { \
    p.fi op u; p.se op u; return p; \
  }


  template<typename T1, typename T2> \
  pair<T1, T2>& name(pair<T1, T2>&); \
  template<typename T1, typename T2> \
  pair<T1, T2> name(pair<T1, T2>&, int);


  template<typename T1, typename T2> \
  pair<T1, T2>& name(pair<T1, T2>& p) { \
    op p.fi; op p.se; \
    return p; \
  } \
  template<typename T1, typename T2> \
  pair<T1, T2> name(pair<T1, T2>& p, int) { \
    pair<T1, T2> t{p}; \
    op p; \
    return t; \
  }


  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2>, const pair<U1, U2>&); \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2>, const U&); \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U&, pair<T1, T2>);


  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2> p, const U& u) { return p op u; } \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U& u, pair<T1, T2> p) { return p op u; }


  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2> p, const U& u) { return p op u; } \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U& u, pair<T1, T2> p) { p.fi = u ex p.fi; p.se = u ex p.se; }


  template <typename... Ts, typename U> \
  tuple<Ts...>& name(tuple<Ts...>&, const U&); \
  template <typename... Ts, typename... Us> \
  tuple<Ts...>& name(tuple<Ts...>&, const tuple<Us...>&);


  template <typename... Ts, typename U> \
  tuple<Ts...>& name(tuple<Ts...>& t, const U& u) { \
    for_each(t, [&](auto& x, int) { x op u; }); \
    return t; \
  } \
  template <typename... Ts, typename... Us> \
  tuple<Ts...>& name(tuple<Ts...>& t1, const tuple<Us...>& t2) { \
    id3(t1, t2, [](auto& x, const auto& y) { x op y; }); \
    return t1; \
  }


  template<typename... Ts> \
  tuple<Ts...>& name(tuple<Ts...>&); \
  template<typename... Ts> \
  tuple<Ts...> name(tuple<Ts...>&, int);


  template<typename... Ts> \
  tuple<Ts...>& name(tuple<Ts...>& t) { \
    for_each(t,  [](auto& x, int) { op x; }); \
    return t; \
  } \
  template<typename... Ts> \
  tuple<Ts...> name(tuple<Ts...>& t, int) { \
    tuple<Ts...> tp{t}; \
    op t; \
    return tp; \
  }


  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...>, const tuple<Us...>&); \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...>, const U&); \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U&, tuple<Ts...>);


  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...> t, const tuple<Us...>& u) {return t op u; } \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U& u, tuple<Ts...> t) { return t op u; }


  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...> t, const tuple<Us...>& u) {return t op u; } \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U& u, tuple<Ts...> t) { for_each(t, [&](auto& x, int) { x = u ex x; }); return t; }



vAssignmentOpF(operator+=) vAssignmentOpF(operator-=)
vAssignmentOpF(operator*=) vAssignmentOpF(operator/=) vAssignmentOpF(operator%=)
vAssignmentOpF(operator^=) vAssignmentOpF(operator|=) vAssignmentOpF(operator&=)
vAssignmentOpF(operator<<=) vAssignmentOpF(operator>>=)
id6(operator+) id6(operator-)
id6(operator*) id6(operator/) id6(operator%)
id6(operator^) id6(operator|) id6(operator&)
id6(operator<<) id6(operator>>)
vIncDecF(operator++) vIncDecF(operator--)
template <typename T> vector<T> operator-(vector<T> v);
template <typename T> vector<T> operator+(vector<T> v);



pAssignmentOpF(operator+=) pAssignmentOpF(operator-=)
pAssignmentOpF(operator*=) pAssignmentOpF(operator/=) pAssignmentOpF(operator%=)
pAssignmentOpF(operator^=) pAssignmentOpF(operator|=) pAssignmentOpF(operator&=)
pAssignmentOpF(operator<<=) pAssignmentOpF(operator>>=)
id5(operator+) id5(operator-)
id5(operator*) id5(operator/) id5(operator%)
id5(operator^) id5(operator|) id5(operator&)
id5(operator<<) id5(operator>>)
pIncDecF(operator++) pIncDecF(operator--)
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p);
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p);



tAssignmentOpF(operator+=) tAssignmentOpF(operator-=)
tAssignmentOpF(operator*=) tAssignmentOpF(operator/=) tAssignmentOpF(operator%=)
tAssignmentOpF(operator^=) tAssignmentOpF(operator|=) tAssignmentOpF(operator&=)
tAssignmentOpF(operator<<=) tAssignmentOpF(operator>>=)
id2(operator+) id2(operator-)
id2(operator*) id2(operator/) id2(operator%)
id2(operator^) id2(operator|) id2(operator&)
id2(operator<<) id2(operator>>)
tIncDecF(operator++) tIncDecF(operator--)
template <typename... Ts> tuple<Ts...> operator-(tuple<Ts...> v);
template <typename... Ts> tuple<Ts...> operator+(tuple<Ts...> v);



vAssignmentOp(operator+=, +=) vAssignmentOp(operator-=, -=)
vAssignmentOp(operator*=, *=) vAssignmentOp(operator/=, /=) vAssignmentOp(operator%=, %=)
vAssignmentOp(operator^=, ^=) vAssignmentOp(operator|=, |=) vAssignmentOp(operator&=, &=)
vAssignmentOp(operator<<=, <<=) vAssignmentOp(operator>>=, >>=)
vBinOp(operator+, +=) vBinOpNo(operator-, -=, -)
vBinOp(operator*, *=) vBinOpNo(operator/, /=, /) vBinOpNo(operator%, %=, %)
vBinOp(operator^, ^=) vBinOp(operator|, |=) vBinOp(operator&, &=)
vBinOpNo(operator<<, <<=, <<) vBinOpNo(operator>>, >>=, <<)
vIncDec(operator++, ++) vIncDec(operator--, --)
template <typename T> vector<T> operator-(vector<T> v) {
  for (auto& i : v) i = -i;
  return v;
}
template <typename T> vector<T> operator+(vector<T> v) {
  for (auto& i : v) i = +i;
  return v;
}



pAssignmentOp(operator+=, +=) pAssignmentOp(operator-=, -=)
pAssignmentOp(operator*=, *=) pAssignmentOp(operator/=, /=) pAssignmentOp(operator%=, %=)
pAssignmentOp(operator^=, ^=) pAssignmentOp(operator|=, |=) pAssignmentOp(operator&=, &=)
pAssignmentOp(operator<<=, <<=) pAssignmentOp(operator>>=, >>=)
pBinOp(operator+, +=) pBinOpNo(operator-, -=, -)
pBinOp(operator*, *=) pBinOpNo(operator/, /=, /) pBinOpNo(operator%, %=, %)
pBinOp(operator^, ^=) pBinOp(operator|, |=) pBinOp(operator&, &=)
pBinOpNo(operator<<, <<=, <<) pBinOpNo(operator>>, >>=, <<)
pIncDec(operator++, ++) pIncDec(operator--, --)
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p) { return mp(-p.fi, -p.se); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p) { return mp(+p.fi, +p.se); }



tAssignmentOp(operator+=, +=) tAssignmentOp(operator-=, -=)
tAssignmentOp(operator*=, *=) tAssignmentOp(operator/=, /=) tAssignmentOp(operator%=, %=)
tAssignmentOp(operator^=, ^=) tAssignmentOp(operator|=, |=) tAssignmentOp(operator&=, &=)
tAssignmentOp(operator<<=, <<=) tAssignmentOp(operator>>=, >>=)
tBinOp(operator+, +=) tBinOpNo(operator-, -=, -)
tBinOp(operator*, *=) tBinOpNo(operator/, /=, /) tBinOpNo(operator%, %=, %)
tBinOp(operator^, ^=) tBinOp(operator|, |=) tBinOp(operator&, &=)
tBinOpNo(operator<<, <<=, <<) tBinOpNo(operator>>, >>=, <<)
tIncDec(operator++, ++) tIncDec(operator--, --)
template <typename... Ts> tuple<Ts...> operator-(tuple<Ts...> t) {
  for_each(t, [](auto& x, int) { x = -x; });
  return t;
}
template <typename... Ts> tuple<Ts...> operator+(tuple<Ts...> t) {
  for_each(t, [](auto& x, int) { x = +x; });
  return t;
}










int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vi a;
    id4(i, n) {
        int k; 
        cin >> k;
        if(!SZ(a) || a.back() != k)
            a.pb(k);
    }
    n = SZ(a);

    map<int, queue<int>> nextOcc;
    id4(i, n)
        nextOcc[a[i]].push(i);

    dout << dvar(a) << endl;
    int last1 = 0, last2 = 0;
    int res = 0;
    for(int x : a) {

        if(last1 != x && last2 != x) {
            if(!SZ(nextOcc[last2]) || (SZ(nextOcc[last1]) && nextOcc[last1].front() < nextOcc[last2].front())) {
                last2 = x;
            } else {
                last1 = x;
            }
            res++;
        }
        if(SZ(nextOcc[x]))
            nextOcc[x].pop();
    }
    cout << res << endl;
}
