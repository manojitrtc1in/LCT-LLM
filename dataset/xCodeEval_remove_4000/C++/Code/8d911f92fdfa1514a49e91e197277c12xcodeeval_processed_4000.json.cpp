















using namespace std;
typedef long long     ll;
typedef unsigned int  UInt;
















template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 

template<class T> inline T   gcd(T a, T b) { while(b) { T t = b; b = a % b; a = t; } return a; }




istream& input(bool id5 = false)
{
  ios_base::sync_with_stdio(false);

  static ifstream is("CodeForces/input.txt");
  return is;

  if (id5)
    cin.tie(NULL);
  return cin;
}

ostream& output(bool id5 = false)
{
  cout << setprecision(15);
  if (id5)
    cout.tie(NULL);
  return cout;
}

template <typename T>
void id9(vector<vector<T>>& v, int lx, int ly, const T& val = T())
{
  v.resize(lx);
  FOR (i,0,lx)
    v[i].resize(ly, val);
};

template <typename T>
int id4(T a, T b, T c, T& x0, T& x1)
{
  if (a == 0)
  {
    if (b == 0)    
      return c == 0 ? -1 : 0;
    else
    {
      x0 = - c / b;
      return 1;
    }
  } 
  else
  {
    const T d = b*b - 4*a*c;
    if (d < 0)
    {
      return 0;
    }
    else if (d == 0)
    {
      x0 = - b / (2*a);
      return 1;
    }
    else 

    {
      const T sqrt_d = sqrt(d);
      x0 = (-b - sqrt_d) / (2*a);
      x1 = (-b + sqrt_d) / (2*a);
      if (a<0)
        swap(x0,x1);
      return 2;
    }
  }
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
bool line_contains(const Point2<T>& line_p, const Point2<T>& line_dir, const Point2<T>& v)
{
  const Point2<T>& vv=v-line_p;
  return cross(line_dir,vv)==0;
}

typedef Point2<int>       Point2I;




class id7
{
public:
  id7(int vertex_num) : m_adj_list (vertex_num) {}

  void add_edge(int u, int v) 

  {
    m_adj_list[u].push_back(v);
    m_adj_list[v].push_back(u);
  }

  void load(istream& is, int edges_num) 

  {
    

    FOR (i, 0, edges_num)
    {
      int u,v;
      is>>u>>v;
      add_edge(u-1, v-1);
    }
  }

  const vector<int>& adjacent_list(int vertex_index) const { return m_adj_list[vertex_index]; } 


public:
  vector<vector<int>> m_adj_list;
  

};




template<class Value, class Updater>
class SegmentTree
{
public:
  size_t size() const { return m_size; } 


protected:
  SegmentTree() : m_size(0) {}
  void set(size_t n); 

  size_t nodes_size() const { return m_nodes.size(); }

  

  Value value(int i) const               { return value_on_segment(i, i+1); }
  void  set_value(int i, const Value& v) { apply_on_segment(i, i+1, v); }

  

  Value value_on_segment(int l, int r) const           { assert(l<r); return l<r ? value_on_segment(1,0,size(),l,r) : Value(); }
  void  apply_on_segment(int l, int r, const Value& v) { assert(l<r); if (l<r) apply_on_segment(1,0,size(),l,r,v); }

protected:
  Value&               node_value(size_t node_index)         { return m_nodes[node_index].value; }
  const Value&         node_value(size_t node_index) const   { return m_nodes[node_index].value; }
  bool                 childs_exist(size_t node_index) const { return (node_index<<1) < m_nodes.size(); }
  pair<size_t, size_t> childs_indexes(size_t node_index) const { pair<size_t, size_t> res(node_index<<1, 0); res.second = res.first + 1; return res; }
  size_t               array_segment_size(size_t node_index) const;

private:
  Value value_on_segment(int i, int tl, int tr, int ql, int qr) const;
  void  apply_on_segment(int i, int tl, int tr, int ql, int qr, const Value& v);

  void apply_for_node(size_t node_index, const Value&);
  void update_node_by_childs(size_t node_index);
  void update_childs_by_node(size_t node_index);

private:
  struct Node
  {
    Value value;
    bool  update_childs_need; 

    bool  update_by_childs_need;
    Node() : update_childs_need (false), update_by_childs_need (false) {}
  };

private:
  size_t       m_size; 

  vector<Node> m_nodes;
};




inline UInt upper_bit (UInt v) 

{
  for (int i = 31; i > 0; --i)
  {
    int p = 1 << i;    
    if (v & p)
      return i;
  }
  return 0;
}

inline UInt id10 (UInt v)
{
  const UInt i = upper_bit(v);
  return (1u<<i) >= v ? i : i+1; 

}

template<class Value, class Updater>
void SegmentTree<Value, Updater>::set(size_t n)
{
  

  m_size = 1<<id10(n);
  m_nodes.clear();
  m_nodes.resize(1<<(id10(n)+1));
}

template<class Value, class Updater>
size_t SegmentTree<Value, Updater>::array_segment_size(size_t node_index) const
{
  return m_size >> upper_bit(node_index);
}

template<class Value, class Updater>
Value SegmentTree<Value, Updater>::value_on_segment(int vi, int tl, int tr, int ql, int qr) const
{
  if (tl==ql && tr==qr)
  {
    const_cast<SegmentTree<Value, Updater>*>(this)->update_node_by_childs(vi);
    return m_nodes[vi].value;
  }

  const_cast<SegmentTree<Value, Updater>*>(this)->update_childs_by_node(vi);

  const pair<size_t, size_t> childs = childs_indexes(vi);
  const int tm = (tl+tr)>>1;
  if (qr <= tm)
    return value_on_segment(childs.first, tl, tm, ql, qr);
  else if (ql >= tm)
    return value_on_segment(childs.second, tm, tr, ql, qr);
  else
  {
    const Value& vl = value_on_segment(childs.first, tl, tm, ql, tm);
    const Value& vr = value_on_segment(childs.second, tm, tr, tm, qr);
    Value res;
    Updater::merge_values(vl, vr, res);
    return res;
  }
}

template<class Value, class Updater>
void SegmentTree<Value, Updater>::apply_on_segment(int vi, int tl, int tr, int ql, int qr, const Value& v)
{
  if (tl==ql && tr==qr)
  {
    update_childs_by_node(vi);
    update_node_by_childs(vi);
    apply_for_node(vi, v);
  }
  else
  {
    update_childs_by_node(vi);

    const pair<size_t, size_t> childs = childs_indexes(vi);
    const int tm = (tl+tr)>>1;
    if (qr <= tm)
      apply_on_segment(childs.first, tl, tm, ql, qr, v);
    else if (ql >= tm)
      apply_on_segment(childs.second, tm, tr, ql, qr, v);
    else
    {
      apply_on_segment(childs.first, tl, tm, ql, tm, v);
      apply_on_segment(childs.second, tm, tr, tm, qr, v);
    }

    m_nodes[vi].update_by_childs_need = true;
    

  }
}

template<class Value, class Updater>
void SegmentTree<Value, Updater>::apply_for_node(size_t node_index, const Value& v)
{
  assert(!m_nodes[node_index].update_by_childs_need);
  ((Updater*)this)->apply_for_node_(node_index, v);
  

  if (childs_exist(node_index))
    m_nodes[node_index].update_childs_need = true;
}

template<class Value, class Updater>
void SegmentTree<Value, Updater>::update_node_by_childs(size_t node_index)
{
  if (m_nodes[node_index].update_by_childs_need)
  {
    assert(!m_nodes[node_index].update_childs_need);
    const pair<size_t, size_t> childs = childs_indexes(node_index);
    update_node_by_childs(childs.first);
    update_node_by_childs(childs.second);
    Updater::merge_values(m_nodes[childs.first].value, m_nodes[childs.second].value, m_nodes[node_index].value);
    m_nodes[node_index].update_by_childs_need = false;
  }
}

template<class Value, class Updater>
void SegmentTree<Value, Updater>::update_childs_by_node(size_t node_index)
{
  if (m_nodes[node_index].update_childs_need)
  {
    assert(!m_nodes[node_index].update_by_childs_need);
    const pair<size_t, size_t> childs = childs_indexes(node_index);
    assert(!m_nodes[childs.first].update_by_childs_need && !m_nodes[childs.second].update_by_childs_need);

    if (m_nodes[childs.first].update_childs_need)
      update_childs_by_node(childs.first);
    if (m_nodes[childs.second].update_childs_need)
      update_childs_by_node(childs.second);

    ((Updater*)this)->update_childs_by_node_(node_index, childs.first, childs.second);
    if (childs_exist(childs.first)) 
      m_nodes[childs.first].update_childs_need = true;
    if (childs_exist(childs.second)) 
      m_nodes[childs.second].update_childs_need = true;

    m_nodes[node_index].update_childs_need = false;
  }
}

template<class Value>
class id13 : public SegmentTree<Value, id13<Value>>
{
  typedef SegmentTree<Value, id13<Value>> Base;

public:
  id13(size_t n) : id1 (update_none)
  {
    set(n);
    m_childs_update_data.resize(nodes_size(), make_pair(update_none, Value()));
  }

  Value value(int index) const                 { return Base::value(index);    }
  Value sum(int l, int r) const                { return value_on_segment(l,r); }
  void set_value(int index, const Value& v)    { Base::set_value(index,v);     }
  void set_value(int l, int r, const Value& v) { id1 = update_set; apply_on_segment(l, r, v); }
  void increase(int l, int r, const Value& v)  { id1 = update_inc; apply_on_segment(l, r, v); }

protected:
  static void merge_values(const Value& vl, const Value& vr, Value& v)
  {
    v = vl + vr;
  }

  void apply_for_node_(size_t node_index, const Value& v)
  {
    assert (m_childs_update_data[node_index].first == update_none || !childs_exist(node_index));
    switch (id1)
    {
    case update_set:
      node_value(node_index) = v * array_segment_size(node_index);
      break;
    case update_inc:
      node_value(node_index) += v * array_segment_size(node_index);
      break;
    case update_none:
      assert (id1 != update_none);
      break;
    }

    if (childs_exist(node_index))
    {
      m_childs_update_data[node_index].first  = id1;
      m_childs_update_data[node_index].second = v;
    }
  }

  void update_childs_by_node_(size_t node_index, size_t id6, size_t id0)
  {
    if (m_childs_update_data[node_index].first != update_none)
    {
      const UpdateType id11 = id1;

      id1 = m_childs_update_data[node_index].first;
      apply_for_node_(id6, m_childs_update_data[node_index].second);
      apply_for_node_(id0, m_childs_update_data[node_index].second);
      m_childs_update_data[node_index].first = update_none;

      id1 = id11;
    }
  }

private:
  friend Base;
  enum UpdateType
  {
    update_none,
    update_set,
    update_inc,
  };
  UpdateType                      id1;
  vector<pair<UpdateType, Value>> m_childs_update_data;
};

























































































































































































































template<class T, class SegmentData>
class SegmentsUnion
{
public:
  void add_segment(T l, T r, const SegmentData& data) 

  {
    bool id3 = true, id2 = true;
    typename M::iterator it = find_rightmost(r, id2);
    if (it != m.end())
    {
      cut_rightmost(it->second, l, r, id2, data);
      for(it = find_rightmost(r, id2); it != m.end(); id3 &= cut(it, l, r, data));
    }

    if (id3)
    {
      Segment s = {r,true,id2,data};
      typename M::iterator it1 = m.find(l); 

      m.insert(it1, make_pair(l,s));
    }
  }

  template<class Enum>
  void enumerate(T l, T r, Enum& enumerator)
  {
    typename M::iterator it = m.upper_bound(r);
    for (; it != m.begin() && (it == m.end() || it->second.r >= l); )
    {
      --it;
      const Segment& s = it->second;
      const T sl = max(l, it->first);
      const T sr = min(r, s.r);
      const bool id12 = s.l_inclusive || sl > it->first;
      const bool id8 = s.id2 || sr < s.r;

      if (sl < sr || (sl == sr && id12))
        enumerator(sl, sr, id12, id8, s.data);
    }
  }

private:
  struct Segment
  {
    T           r;
    bool        l_inclusive, id2;
    SegmentData data;
  };
  typedef multimap<T,Segment> M;

private:
  typename M::iterator find_rightmost(const T& r, bool id2)
  {
    typename M::iterator it = m.upper_bound(r);
    if (it != m.begin())
    {
      --it;
      if (it->first < r || (id2 && it->second.l_inclusive))
        return it;
      if (it != m.begin())
      {
        --it;
        if (it->first < r || (id2 && it->second.l_inclusive)) 

          return it;
        if (it != m.begin())
          return --it;
      }
    }
    return m.end();
  }

  void cut_rightmost(const Segment& s, const T& l, T& r, bool& id2, const SegmentData& data)
  {
    if (s.r > r)
    {
      if (s.data == data)
      {
        r = s.r;
        id2 = s.id2;
      }
      else
      {
        Segment s1 (s);
        s1.l_inclusive = false;
        m.erase(r);
        m.insert(make_pair(r,s1));
      }
    }
  }

  bool cut(typename M::iterator& it, const T& l, const T& r, const SegmentData& data)
  {
    Segment& s = it->second;
    if (s.r >= l)
    {
      if (it->first < l)
      {
        it = m.end();
        if (s.data == data)
        {
          s.r = r;
          s.id2 = true;
          return false;
        }
        else
        {
          s.r = l;
          s.id2 = false;
        }
      }
      else
      {
        it = m.erase(it); 

        it == m.begin() ? it = m.end() : --it;
      }
    }
    else 
      it = m.end();

    return true;
  }

private:
  M m;
};


struct CalcRes
{
  CalcRes():res(0){}

  void operator()(int l, int r, bool li, bool ri, const int& data)
  {
    res+=data;
  }

  int res;
};

bool complete(int i, SegmentsUnion<int,int>& ts)
{
  CalcRes res;
  ts.enumerate(i,i,res);
  return i == 0 || res.res;
}


void main()
{
  istream& is = input();
  ostream& os = output();

  IN_INT3(n,k,d);
  vector<int> a(n);
  FOR (i,0,n)
    is >> a[i];
  sort(ALL(a));

  SegmentsUnion<int,int> ts;
  

  FOR (i,0,n)
    if (complete(i,ts))
    {
      int j = lower_bound(ALL(a), a[i] + d + 1) - a.begin();
      if (j - i >= k)
      {
        ts.add_segment(i+k,j,1);
      }
    }

  os<<(complete(n,ts)?"YES":"NO");
}

































































void mainc()
{
  istream& is = input();
  ostream& os = output();

  IN_INT(n);

  

  

  


  

}


































