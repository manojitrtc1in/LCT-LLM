
using namespace std;
struct FAST_IO{
	FAST_IO(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	}
}id1;

template<class T, class U=T>
T exchange(T& obj, U&& new_value){
    T old_value=move(obj);
    obj=forward<U>(new_value);
    return old_value;
}


using INT=int;

using i
DEF_NUM(8)DEF_NUM(16)DEF_NUM(32)DEF_NUM(64)
using usize=uintptr_t;using isize=intptr_t;
using f32=float;using f64=double;using f128=long double;







auto &_=std::ignore;
using ll=long long;
template<class T>
using vec=vector<T>;
template<bool B,class T=void>
using enableif_t=typename enable_if<B,T>::type;


template<class U> \
struct name{\
	template<class T>\
	constexpr static auto is(int i)->decltype(exp,true){return true;}\
	template<class T>\
	constexpr static bool is(...){return false;}\
	static const bool value=is<U>(1);\
};









constexpr struct{\
	template<class T>\
	constexpr operator T()const {return numeric_limits<T>::exp();}\
} name;

DEF_CAN(Out,(cout<<*(T*)(0))) DEF_CAN(For,begin(*(T*)(0)))
DEF_INF(INF,max) DEF_INF(MINF,min)
DEF_CAN(Array,declval<T>()[0])

template<size_t i,class T>
auto operator>>(istream& is,T &r)->decltype(id4,is){
	return is;
}
template<size_t i=0,class T>
auto operator>>(istream& is,T &r)->decltype(id0,is){
	is>>get<i>(r);
	return operator>> <i+1>(is,r);
}

template<size_t i,class ...Args>
auto operator>>(istream& is,const tuple<Args&...> &r)->decltype(END_TUPLET(tuple<Args&...>),is){
	return is;
}
template<size_t i=0,class ...Args>
auto operator>>(istream& is,const tuple<Args&...> &r)->decltype(FOR_TUPLET(tuple<Args&...>),is){
	is>>get<i>(r);
	return operator>> <i+1>(is,r);
}

template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLE(T,Out),c+1);
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id4,c+1);
template<size_t i=0,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id0,c+1);
template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,Out),ENABLE(T,For),c+1);


template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLE(T,Out),c+1){
	os << cv;
	while (*c!='}') c++;
	return c+1;
}
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id4,c+1){
	return c;
}
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id0,c+1){
	while (*c!='{') os << *c++;
	c=__format(os,c,get<i>(cv));
	return __format<i+1>(os,c,cv);
}
template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,Out),ENABLE(T,For),c+1){
	const char *ct=c+1;
	if (cv.size()==0){
		int b=1;
		while (1){
			if (*ct=='}') b--;
			if (*ct=='{') b++;
			if (!b) break;
			ct++;
		}
	}else{
		for (auto &i:cv){
			const char *cc=c+1;
			while (*cc!='{') os << *cc++;
			cc=__format(os,cc,i);
			while (*cc!='}') os << *cc++;
			ct=cc;
		}
	}
	return ct+1;
}
void _format(ostream &os,const char *c){
	while (*c!='{'&&*c!='\0') os<< *c++;
}
template<class T,class ...Args>
void _format(ostream &os,const char *c,const T &a,const Args& ...rest){
	while (*c!='{'&&*c!='\0') os<< *c++;
	if (*c=='{') c=__format(os,c,a);
	_format(os,c,rest...);
}
template<class ...Args>
string format(const char *c,const Args& ...rest){
	ostringstream os;
	_format(os,c,rest...);
	return os.str();
}
template<class ...Args>
ostream& print(const char *c,const Args& ...rest){return _format(cout,c,rest...),cout;}
template<class ...Args>
ostream& println(const char *c,const Args& ...rest){return print(c,rest...)<<endl;}









template<class T>
uintptr_t flat(T* b){
	return reinterpret_cast<uintptr_t>(b);
}
template<class T>
auto index(const T a[],uintptr_t p)->decltype(ENABLEN(T,Array),tuple<int>()){
	return (p-flat(&a[0]))/sizeof(T);
}
template<class T>
auto index(const T a[],uintptr_t p)->decltype(ENABLE(T,Array),
	tuple_cat(tuple<int>(),index(a[0],p))){
	int i=(p-flat(a))/sizeof(a[0]);
	p-=i*sizeof(a[0]);
	return tuple_cat(tuple<int>(i),index(a[0],p));
}

template<class T,class ...Args>
struct Rtar{
	T& a;tuple<Args...> n;
	Rtar(T& a,tuple<Args...> n):a(a),n(n){}
};
template<class T,class ...Args>
Rtar<T,Args&...> rtar(T &a,Args&... rest){
	return Rtar<T,Args&...>(a,tie(rest...));
}
template<size_t i,class U,class ...Args,class T=tuple<Args&...>>
auto operator>>(istream& is,Rtar<U,Args&...> r)->decltype(id4,is){
	return is>>r.a;
}
template<size_t i=0,class U,class ...Args,class T=tuple<Args&...>>
auto operator>>(istream& is,Rtar<U,Args&...> r)->decltype(id0,is){
	r.a=typename decay<U>::type(get<i>(r.n));
	for (auto &w:r.a)
		operator>> <i+1>(is,Rtar<decltype(w),Args&...>(w,r.n));
	return is;
}
template<class T1,class T2>
bool cmin(T1 &a,const T2 b){return a>b?a=b,1:0;}
template<class T1,class T2>
bool cmax(T1 &a,const T2 b){return a<b?a=b,1:0;}
template<class T1,class T2,class ...T3>
bool cmin(T1 &a,const T2 b,const T3 ...rest){return cmin(a,b)|cmin(a,rest...);}
template<class T1,class T2,class ...T3>
bool cmax(T1 &a,const T2 b,const T3 ...rest){return cmax(a,b)|cmax(a,rest...);}

bool id2=true;

template<class T,size_t n>
struct arr;

template<class T,size_t n>
class tuple_size<arr<T,n>>{
public:
  constexpr static size_t value=n;
};
template<class T>
struct arr_dtype{using type=T;};
template<class T,size_t n>
struct arr_dtype<arr<T,n>>{using type=typename arr_dtype<T>::type;};
template<class T,size_t n>
struct arr:public array<T,n>{
  using dvalue_type=typename arr_dtype<T>::type;
  using array<T,n>::array;
  template<class ...Args>
  arr(T a,Args... args):array<T,n>{a,args...}{}
  template<class U>
  arr(const arr<U,n>& a){
    for (size_t i=0;i<n;i++)
      (*this)[i]=a[i];
  }
  
  
  TMP_ARR arr<T,n>& operator x
  TMP_ARR arr<T,n>& operator x
  TMP_ARR arr<TU,n> operator x(const arr<T2,n>& b)const{arr<TU,n> c=(*this);for (size_t i=0;i<n;i++) c[i] x
  TMP_ARR arr<TU,n> operator x(const T2& b)const{arr<TU,n> c=(*this);for (size_t i=0;i<n;i++) c[i] x
  op_arr(+) op_arr(-) op_arr(*) op_arr(/)
};
template<class T>
using arr2=arr<T,2>;
template<class T>
using arr3=arr<T,3>;
template<class AT=void,class T,size_t d,class UT=typename conditional<is_same<AT,void>::value,T,AT>::type>
UT dot(const arr<T,d>& a,const arr<T,d>& b){
	UT c=0;
	for (auto& i:operator*<UT>(a,b)) c+=i;
	return c;
}
template<class AT=void,class T,size_t d,class UT=typename conditional<is_same<AT,void>::value,T,AT>::type>
UT _abs(const arr<T,d>& a){return sqrt(dot<UT>(a,a));}
template<class AT=void,class T,size_t d,class UT=typename conditional<is_same<AT,void>::value,T,AT>::type>
arr<UT,d> normalize(const arr<T,d>& a){return a/_abs<UT>(a);}
template<class T>
T crs(const arr2<T> &a,const arr2<T> &b){return a[0]*b[1]-a[1]*b[0];}
template<class T>
arr3<T> crs(const arr3<T> &a,const arr3<T> &b){return {a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]};}

template <class T, size_t n, size_t m> struct mat : public array<arr<T, m>, n> {
  using array<arr<T, m>, n>::array;
  template<class ...Args>
  mat(arr<T,m> a,Args... args):array<arr<T,m>,n>{a,args...}{}
  template<class U>
  mat(const array<arr<U, m>, n>& a){
    for (size_t i=0;i<n;i++)
      (*this)[i]=a[i];
  }
  static mat<T, n, m> unit() {
    mat<T, n, m> a{};
    for (size_t i = 0; i < min(n, m); i++)
      a[i][i] = 1;
    return a;
  }
  static constexpr mat<T, n, m> zero() {
    return mat<T, n, m>{};
  }
};
template <class T, size_t n, size_t m> class tuple_size<mat<T, n, m>> {
public:
  constexpr static size_t value = n;
};

template <class AT = void, class T, class U, size_t n, size_t m,
          class UT = typename conditional<is_same<AT, void>::value,
                                          decltype(declval<T>() * declval<U>()),
                                          AT>::type>
mat<UT, n, m> operator+(const mat<T, n, m> &a, const mat<U, n,m> &b) {
  mat<UT,n,m> x;
  for (size_t i=0;i<n;i++)
    x[i]=a[i]+b[i];
  return x;
}

template <class AT = void, class T, class U, size_t n, size_t m,
          class UT = typename conditional<is_same<AT, void>::value,
                                          decltype(declval<T>() * declval<U>()),
                                          AT>::type>
mat<UT, n, m> operator-(const mat<T, n, m> &a, const mat<U, n,m> &b) {
  mat<UT,n,m> x;
  for (size_t i=0;i<n;i++)
    x[i]=a[i]+b[i];
  return x;
}

template <class T, class U, size_t n, size_t m>
mat<T,n,m>& operator+=(mat<T,n,m>& a,const mat<U,n,m>& b){
  for (size_t i=0;i<n;i++)
    a[i]+=b[i];
  return a;
}

template <class T, class U, size_t n, size_t m>
mat<T,n,m>& operator-=(mat<T,n,m>& a,const mat<U,n,m>& b){
  for (size_t i=0;i<n;i++)
    a[i]+=b[i];
  return a;
}

template <class AT = void, class T, class U, size_t n, size_t m, size_t u,
          class UT = typename conditional<is_same<AT, void>::value,
                                          decltype(declval<T>() * declval<U>()),
                                          AT>::type>
mat<UT, n, u> operator*(const mat<T, n, m> &a, const mat<U, m, u> &b) {
  mat<UT, n, u> x{};
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < u; j++)
      for (size_t k = 0; k < m; k++)
        x[i][j] += a[i][k] * b[k][j];
  return x;
}

template <class AT = void, class T, class U, size_t n, size_t m, size_t u>
mat<T, n, u>& operator*=(mat<T, n, m> &a, const mat<U, m, u> &b) {
  return a = operator*<T>(a, b);
}

template <class T, class U, size_t n, size_t m>
mat<T, n, m>& operator*=(mat<T, n, m> &a, const U &b) {
  for (auto &i:a) i*=b;
  return a;
}

template <class T, class U, size_t n, size_t m>
mat<T, n, m>& operator/=(mat<T, n, m> &a, const U &b) {
  for (auto &i:a) i/=b;
  return a;
}

template <class T, class U, size_t n, size_t m>
mat<T, n, m> operator*(const mat<T, n, m> &a, const U &b) {
  mat<T, n, m> x;
  for (size_t i=0;i<n;i++) x[i]=a[i]*b;
  return x;
}

template <class T, class U, size_t n, size_t m>
mat<T, n, m> operator/(mat<T, n, m> &a, const U &b) {
  mat<T, n, m> x;
  for (size_t i=0;i<n;i++) x[i]=a[i]/b;
  return x;
}

template <
    class AT = void, class T, size_t n, size_t m,
    class UT = typename conditional<is_same<AT, void>::value, T, AT>::type>
pair<int, mat<UT, n, m>> inv(const mat<T, n, m> &_a) {
  mat<UT, n, m> a = _a;
  auto b = mat<UT, n, m>::unit();
  for (int i = 0; i < n - 1; i++) {
    int k = -1;
    for (int j = i; j < n; j++)
      if (a[j][i]) {
        k = j;
        break;
      }
    if (k != -1) {
      swap(a[i], a[k]);
      swap(b[i], b[k]);
      for (int j = i + 1; j < n; j++)
        if (a[k][i]) {
          UT d = a[j][i] / a[k][i];
          a[j] -= a[k] * d;
          b[j] -= b[k] * d;
        }
    }
  }
  int rank = 0;
  for (int i = n - 1; i >= 0; i--) {
    UT aii = a[i][i];
    if (aii) {
      rank++;
      b[i] /= aii;
      a[i] /= aii;
      for (int j = i - 1; j >= 0; j--) {
        UT aji = a[j][i];
        a[j] -= a[i] * aji;
        b[j] -= b[i] * aji;
      }
    }
  }
  return {rank, b};
}

template <
    class AT = void, class T, size_t n, size_t m,
    class UT = typename conditional<is_same<AT, void>::value, T, AT>::type>
UT det(const mat<T, n, m> &_a) {
  mat<UT, n, m> a = _a;
  vector<int> x(n, -1);
  int ans = 0, ii = 0;
  UT D = 1;
  for (int i = 0; i < n; i++) {
    int it = -1;
    for (int j = i; j < n; j++)
      if (a[j][ii]) {
        it = j;
        break;
      }
    if (it == -1)
      continue;
    swap(a[ii], a[it]);
    auto d = a[ii][x[ii] = i];
    a[ii] /= d;
    D *= d;
    for (int j = ii + 1; j < n; j++)
      if (a[j][i]) {
        UT d = a[j][i];
        a[j] -= a[ii] * d;
      }
    ans++;
    ii++;
  }
  return ans != n ? 0 : D;
}
constexpr unsigned long long operator "" _kb(unsigned long long i){return i*1024;}
constexpr unsigned long long operator "" _mb(unsigned long long i){return i*1024_kb;}
char pool[100_mb];unsigned long long pooli=0;
template<class T>
T* alloc(size_t i=1){
	auto pi=pooli;
	pooli+=i*sizeof(T);
	return (T*)(void*)&pool[pi];
}
void reset(){pooli=0;};
template<class T>
struct mallocator{
	typedef T value_type;
	mallocator() = default;
	template <class U> constexpr mallocator(const mallocator <U>&) noexcept {}
	[[nodiscard]] T* allocate(size_t n=1) {return alloc<T>(n);}
	void deallocate(T* p,size_t n) noexcept {}
};
 
template<class T, class U>
bool operator==(const mallocator<T>&,const mallocator<U>&) { return true; }
template<class T, class U>
bool operator!=(const mallocator<T>&,const mallocator<U>&) { return false; }
template<class T,class ...Args>
T* mnew(Args&&... args){
	return ::new((void*)(alloc<T>()))T(std::forward<Args>(args)...);
}
struct none_delete{
	constexpr none_delete()noexcept=default;
	template<class T>
	void operator()(T* p)const{};
};
template<template <class >class Allocator=allocator,class T>
T clone(const T& a){
	return T(&(*(Allocator<typename pointer_traits<T>::element_type>().allocate(1))=*a));
}
template <class T, class IT = int> struct id3 {
  const IT l, r;
  IT mid;
  T fmul, fsum;
  bool fable;
  id3* ch[2];
  id3(const int l, const int r)
      : l(l), r(r), mid(INF), fmul(T::unit()), fsum(){
    		if (l!=r) {wake();fable=true;}
    		else {
    		  fable=false;
    		  fsum=T{arr3<ll>{1,0,0}};
    		}
  }
  bool unwake() { return mid == (IT)INF; }
  bool wake() {
    if (unwake()) {
      mid = (l + r) / 2;
      ch[0]=mnew<id3>(l, mid);
      ch[1]=mnew<id3>(mid + 1, r);
      upload();
      return true;
    }
    return false;
  }
  void dmul(const T &v) {
    fmul *= v;
    fsum *= v;
  }
  void dable(){
    fable=!fable;
  }
  void download() {
    if (fmul != T::unit()) {
      ch[0]->dmul(fmul);
      ch[1]->dmul(fmul);
      fmul = T::unit();
    }
  }
  T sum_op() { return fable?fsum:T(); }

  static T sum_merge1(T a) { return a; }

  static T sum_merge2(T a, T b) { return a + b; }
  static T sum_merge2(T a) { return a; }
  void upload() { fsum = sum_merge2(ch[0]->sum_op(), ch[1]->sum_op()); }
};

  template <class T0, class ...Args, class T3 = decltype(declval<T0>().l)>          \
  void tag(T0 &tree, const T3 &L, const T3 &R, const Args& ...v) {                  \
    if (L <= tree.l && tree.r <= R)                                            \
      return tree.d
    if (!tree.wake())                                                          \
      tree.download();                                                         \
    if (L <= tree.mid)                                                         \
      tag(*tree.ch[0], L, R, v...);                                               \
    if (tree.mid + 1 <= R)                                                     \
      tag(*tree.ch[1], L, R, v...);                                               \
    tree.upload();                                                             \
  }                                                                            

  template <class T0, class T3 = decltype(declval<T0>().l),                    \
            class T2 =                                                         \
                typename decay<decltype(declval<T0>().tag
  T2 tag(T0 &tree, const T3 &L, const T3 &R) {                                 \
    if (L <= tree.l && tree.r <= R || tree.unwake())                           \
      return tree.tag
    tree.wake();                                                               \
    tree.download();                                                           \
    bool l = L <= tree.mid, r = tree.mid + 1 <= R;                             \
    if (l && r)                                                                \
      return tree.tag
                               tag(*tree.ch[1], L, R));                        \
    if (l)                                                                     \
      return tree.tag
    return tree.tag
  }                                                                            \
  template <class T0, class T3 = decltype(declval<T0>().l),                    \
            class T2 =                                                         \
                typename decay<decltype(declval<T0>().tag
  T2 tag(T0 &tree, const T3 &LR) {                                             \
    if (LR == tree.l && tree.r == LR || tree.unwake())                         \
      return tree.tag
    tree.wake();                                                               \
    tree.download();                                                           \
    if (LR <= tree.mid)                                                        \
      return tree.tag
    else                                                                       \
      return tree.tag
  }
def_tree_edit(mul) def_tree_edit(able) def_tree_query(sum)
bool a[200001];
int main(){
  int q,d;
  vec<int> v;
  cin>>q>>d>>rtar(v,q);
  id3<mat<ll,3,3>> t(0,200000);
  mat<ll,3,3> D(
  arr3<ll>{1,1,1},
  arr3<ll>{0,1,2},
  arr3<ll>{0,0,1}),ID=inv<float>(D).second;
  for (auto i:v){
    able(t,i,i);
    if (a[i]=!a[i]){
      mul(t,max(0,i-d),i-1,D);
    }else{
      mul(t,max(0,i-d),i-1,ID);
    }
    cout << (t.fsum[0][2]-t.fsum[0][1])/2 << endl;
  }
}