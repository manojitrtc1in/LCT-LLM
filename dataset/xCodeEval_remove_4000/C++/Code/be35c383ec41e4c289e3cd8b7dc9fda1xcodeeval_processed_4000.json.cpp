














using namespace std;
typedef long long     ll;
typedef unsigned int  UInt;





template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 


istream& input()
{
  ios_base::sync_with_stdio(false);

  static ifstream is("CodeForces/input.txt");
  return is;

  return cin;
}

ostream& output()
{
  cout << setprecision(15);
  return cout;
}

template <typename T>
class Point2
{
public:
  Point2(){}
  Point2(T x_, T y_):x(x_), y(y_) {}

  bool       operator ==(const Point2<T>&) const;
  bool       operator !=(const Point2<T>&) const;

  Point2<T>& operator +=(const Point2<T>&);
  Point2<T>& operator -=(const Point2<T>&);
  Point2<T>& operator /=(T);
  Point2<T>& operator *=(T);

  T length() const;
  T length_square() const;

public:
  T x;
  T y;
};

template<class T>
inline bool Point2<T>::operator == (const Point2<T>& p) const          
{
  return x == p.x && y == p.y;
}

template<class T>
inline bool Point2<T>::operator != (const Point2<T>& p) const
{
  return x != p.x || y != p.y;
}

template<class T>
inline Point2<T>& Point2<T>::operator +=(const Point2<T>& r)           
{
  x += r.x;
  y += r.y;
  return *this;
}

template<class T>
inline Point2<T>& Point2<T>::operator -=(const Point2<T>& r)            
{
  x -= r.x;
  y -= r.y;
  return *this;
}

template<class T>
inline Point2<T>& Point2<T>::operator *=(T m)
{
  x *= m;
  y *= m;
  return *this;
}

template<class T>
inline Point2<T>& Point2<T>::operator /=(T val)
{
  x /= val;
  y /= val;
  return *this;
}

template<class T>
inline T Point2<T>::length() const 
{
  return sqrt(length_square());
}

template<class T>
inline T Point2<T>::length_square() const 
{
  return (x * x + y * y);
}




template<class T>
inline Point2<T> operator + (const Point2<T>& l, const Point2<T>& r)           
{
  return Point2<T> (l.x+r.x, l.y+r.y);
}

template<class T>
inline Point2<T> operator - (const Point2<T>& l, const Point2<T>& r)            
{
  return Point2<T> (l.x-r.x, l.y-r.y);
}

template<class T>
inline Point2<T> operator * (const Point2<T>& l, T m)
{
  return Point2<T> (l.x*m, l.y*m);
}

template<class T>
inline Point2<T> operator / (const Point2<T>& l, T val)
{
  return Point2<T> (l.x/val, l.y/val);
}

template<class T>
inline T dot(const Point2<T>& l, const Point2<T>& r)
{
  return l.x * r.x + l.y * r.y;
}

template<class T>
inline T cross(const Point2<T>& l, const Point2<T>& r)
{
  return l.x * r.y - l.y * r.x;
}

template <typename T>
bool line_exists(const Point2<T>& line_p, const Point2<T>& line_dir, const Point2<T>& v)
{
  const Point2<T>& vv=v-line_p;
  return cross(line_dir,vv)==0;
}

template<class T>
std::istream& operator >> (std::istream& is, Point2<T>& p)
{
  is >> p.x >> p.y;
  return is;
}

template<class T>
std::ostream& operator << (std::ostream& os, const Point2<T>& p)
{
  os << "(" << p.x << "; " << p.y << ")";
  return os;
}

template <typename T>
struct Point2Less
{
  bool operator()(const Point2<T>& l, const Point2<T>& r) const
  {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
  }
};

typedef Point2<int>       Point2I;






























































































































































































































































































































































































































class id2
{
  typedef unsigned int UInt;

public:
  id2()         {}
  id2(size_t n) { set(n); }
  void set(size_t n); 


  bool empty() const        { return !id3; }
  UInt size() const         { return id3; } 

  size_t nodes_size() const { return m_nodes.size(); } 


  UInt exists(UInt i) const { return i < m_nodes.size() ? m_nodes[i].num : 0; } 

  void insert(UInt);
  void erase(UInt);

  UInt lower_bound(UInt) const; 

  UInt upper_bound(UInt) const; 


  

  UInt find_by_order(UInt) const; 

  UInt order_of_key(UInt) const; 


private:
  struct Node
  {
    UInt   num;               

    size_t left_subtree_size; 


    Node() : num(0), left_subtree_size(0) {}
  };
  vector<Node> m_nodes;
  size_t       id3;
  size_t       id0;
};




void id2::set(size_t n) 
{
  id3 = 0;
  m_nodes.clear();
  m_nodes.resize(n);
  for (id0 = 1; id0 <= n; id0 <<= 1);
  id0 >>= 1;
  

  

  

  

  

  

}

void id2::insert(UInt key)
{
  ++id3;
  for (size_t i = id0, b = id0, n = m_nodes.size(); ; b >>= 1, i |= b)
  {
    if (key < i)
    {
      if (i < n)
        ++m_nodes[i].left_subtree_size;
      i ^= b;
    }
    else if (key == i)
    {
      ++m_nodes[i].num;
      break;
    }
    else
    {
    }
  }
}

void id2::erase(UInt key)
{
  --id3;
  for (UInt i = id0, b = id0, n = m_nodes.size(); ; b >>= 1, i |= b)
  {
    if (key < i)
    {
      if (i < n)
        --m_nodes[i].left_subtree_size;
      i ^= b;
    }
    else if (key == i)
    {
      --m_nodes[i].num;
      break;
    }
    else
    {
    }
  }
}

UInt id2::lower_bound(UInt key) const 

{
  const UInt order = order_of_key(key);
  return find_by_order(order);
}

UInt id2::upper_bound(UInt key) const 

{
  const UInt order = order_of_key(key + 1);
  return find_by_order(order);
}

UInt id2::find_by_order(UInt order) const 

{
  if (order >= id3)
    return nodes_size();

  for (UInt i = id0, b = id0, n = m_nodes.size(); ; b >>= 1, i |= b)
  {
    if (i >= n || m_nodes[i].left_subtree_size > order)
    {
      i ^= b;
    }
    else 
    {
      order -= m_nodes[i].left_subtree_size + m_nodes[i].num;
      if ((int)order < 0)
        return i;
    }
  }
  return nodes_size(); 

}

UInt id2::order_of_key(UInt key) const 

{
  if (key >= m_nodes.size())
    return m_nodes.empty() ? 0 : order_of_key(m_nodes.size() - 1) + m_nodes.back().num;

  UInt order = 0;
  for (UInt i = id0, b = id0, n = m_nodes.size(); ; b >>= 1, i |= b)
  {
    if (key < i)
    {
      i ^= b;
    }
    else if (key == i)
    {
      order += m_nodes[i].left_subtree_size;
      break;
    }
    else
    {
      order += m_nodes[i].left_subtree_size + m_nodes[i].num;
    }
  }
  return order;
}














template<class T, class FUNC_ADD, class FUNC_SUB>
class FenwickTree
{
public:
  void init(int n);
  void init(const vector<T>&);

  void set_value(int i, const T& v_new);
  void set_delta(int i, const T& delta); 


  T func(int r) const; 

  T func(int l, int r) const; 


protected:
  vector<T> t; 

  vector<T> v; 

};


template<class T, class FUNC_ADD, class FUNC_SUB>
void FenwickTree<T, FUNC_ADD, FUNC_SUB>::init(int n)
{
  v.assign(n, 0);
  t.assign(n, 0); 

}

template<class T, class FUNC_ADD, class FUNC_SUB>
void FenwickTree<T, FUNC_ADD, FUNC_SUB>::init(const vector<T>& a)
{
  init(a.size());
  for (unsigned i = 0; i < a.size(); i++)
    set_value(i, a[i]);
}

template<class T, class FUNC_ADD, class FUNC_SUB>
void FenwickTree<T, FUNC_ADD, FUNC_SUB>::set_value(int i, const T& v_new)
{
  T& v_old = v[i]; 

  for (int n = t.size(); i < n; i |= i+1)
    t[i] = FUNC_ADD()(FUNC_SUB()(t[i], v_old), v_new);
  v_old = v_new; 

}

template<class T, class FUNC_ADD, class FUNC_SUB>
void FenwickTree<T, FUNC_ADD, FUNC_SUB>::set_delta(int i, const T& delta) 

{
  v[i] += delta;
  for (int n = t.size(); i < n; i |= i+1)
    t[i] = FUNC_ADD()(t[i], delta);
}

template<class T, class FUNC_ADD, class FUNC_SUB>
T FenwickTree<T, FUNC_ADD, FUNC_SUB>::func(int r) const 

{
  T res = 0;
  for (; r >= 0; r &= r+1, --r)
    res = FUNC_ADD()(res, t[r]);
  return res;
}

template<class T, class FUNC_ADD, class FUNC_SUB>
T FenwickTree<T, FUNC_ADD, FUNC_SUB>::func(int l, int r) const 

{
  return FUNC_SUB()(func(r), func(l-1));
}




template<class T> struct FuncAdd { T operator()(const T& a, const T& b) const { return a+b; } };
template<class T> struct FuncSub { T operator()(const T& a, const T& b) const { return a-b; } };

template<class T>
class id1 : public FenwickTree<T, FuncAdd<T>, FuncSub<T>> 
{
public:
  id1(int n) { init(n); } 


  T sum(int r) const { return func(r); }
  T sum(int l, int r) const { return func(l, r); }
};



void main()
{
  istream& is = input();
  ostream& os = output();

  ll n;
  is >> n;

  vector<int> a(n);
  FOR (i,0,n)
    is >> a[i];

  ll p0 = 0;
  

  vector<ll> s1(n);
  ll ss=0;
  {
    id2 used(n+1);
    id1<ll> ftree(n+1);
    FOR_REV (i,0,n)
    {
      p0+=used.order_of_key(a[i]);
      

      s1[i]=ftree.sum(a[i]);

      ss+=s1[i];
      used.insert(a[i]);
      ftree.set_value(a[i],n-i);
    }
  }


  long double res=p0;
  FOR (i,0,n)
  {
    ll k=n-i;
    res+=(long double)(k*(k+1)*(2*k-2)/12 - ss*2)/n/(n+1);
    

    ss-=s1[i];
  }
  os << res;
}




























