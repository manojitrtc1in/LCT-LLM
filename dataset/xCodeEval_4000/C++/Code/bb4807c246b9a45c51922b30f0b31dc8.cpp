#define _USE_MATH_DEFINES
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long     ll;
typedef unsigned int  uint;
#define ALL(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for(int i = a;   i <  (int)(b); ++i)
#define FOR_REV(i,a,b)  for(int i = b-1; i >= (int)(a); --i)
#define FOR_EACH(it,a)  for(remove_reference<decltype(a)>::type::iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_REV(it,a) for(remove_reference<decltype(a)>::type::reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
#define FOR_EACH_CONST(it,a) for(remove_reference<decltype(a)>::type::const_iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_CONST_REV(it,a) for(remove_reference<decltype(a)>::type::const_reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int round_i(T t) { return int(t < 0 ? t-0.5f : t+0.5f); } 

template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 

template<class T> inline T   gcd(T a, T b) { while(b) { T t = b; b   = a % b; a   = t; } return a; }
#define IN_INT(a)            int a;       is >> a;
#define IN_INT2(a,b)         int a,b;     is >> a >> b;
#define IN_INT3(a,b,c)       int a,b,c;   is >> a >> b >> c;
#define IN_INT4(a,b,c,d)     int a,b,c,d; is >> a >> b >> c >> d;
#define IN_LL(a)             ll a;        is >> a;
#define IN_LL2(a,b)          ll a,b;      is >> a >> b;
#define IN_LL3(a,b,c)        ll a,b,c;    is >> a >> b >> c;
#define IN_LL4(a,b,c,d)      ll a,b,c,d;  is >> a >> b >> c >> d;
#define IN_CHAR(c)           char c;      is >> c;
#define IN_STR(s)            string s;    is >> s;



bool io_interactive = true;

istream& input()
{
  ios_base::sync_with_stdio(false);
  if (io_interactive)
    return cin;
#ifdef INPUT_FROM_FILE
  static ifstream is("CodeForces/input.txt");
  return is;
#endif
  if (!io_interactive)
    cin.tie(NULL);
  return cin;
}

ostream& output()
{
  cout << setprecision(15);
  if (!io_interactive)
    cout.tie(NULL);
  return cout;
}


template <typename T>
void init_v2(vector<vector<T>>& v, int lx, int ly, const T& val = T())
{
  v.resize(lx);
  FOR (i,0,lx)
    v[i].resize(ly, val);
};



































































template<typename T>
inline size_t upper_bit (T v) 
{
  assert(v>=0);
  T p2 = 1;
  size_t res = 0;
  for (; p2 < v; ++res, p2<<=1);
  return p2 != v ? res-1 : res;
}
inline uint log2i (uint v)
{
  const uint i = upper_bit(v);
  return (1u<<i) >= v ? i : i+1; 

}

template<class SumT>
struct PrefixSum
{
  template<class ElementT>
  PrefixSum(const vector<ElementT>& v) : pref_sum(v.size()+1)
  {
    pref_sum[0] = 0;
    FOR (i,0,v.size())
      pref_sum[i+1]=pref_sum[i]+v[i];
  }

  SumT sum(int l, int r) const { return pref_sum[r]-pref_sum[l]; }

  vector<SumT> pref_sum;
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
  void  set_value(int i, const Value& v) { apply_on_segment(i, i+1, v);     }

  

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




template<class Value, class Updater>
void SegmentTree<Value, Updater>::set(size_t n)
{
  

  m_size = 1<<log2i(n);
  m_nodes.clear();
  m_nodes.resize(1<<(log2i(n)+1));
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
    ((Updater*)this)->merge_values(vl, vr, res);
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
    ((Updater*)this)->merge_values(m_nodes[childs.first].value, m_nodes[childs.second].value, m_nodes[node_index].value);
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
class SegmentTree_Sum : public SegmentTree<Value, SegmentTree_Sum<Value>>
{
  typedef SegmentTree<Value, SegmentTree_Sum<Value>> Base;

public:
  SegmentTree_Sum(size_t n) : m_update_query (update_none)
  {
    set(n);
    m_childs_update_data.resize(nodes_size(), make_pair(update_none, Value()));
  }

  Value value(int index) const                 { return Base::value(index);    }
  Value sum(int l, int r) const                { return value_on_segment(l,r); }
  void set_value(int index, const Value& v)    { m_update_query = update_set; Base::set_value(index,v);  m_update_query = update_none; }
  void set_value(int l, int r, const Value& v) { m_update_query = update_set; apply_on_segment(l, r, v); m_update_query = update_none; }
  void increase(int l, int r, const Value& v)  { m_update_query = update_inc; apply_on_segment(l, r, v); m_update_query = update_none; }

protected:
  static void merge_values(const Value& vl, const Value& vr, Value& v)
  {
    v = vl + vr;
  }

  void apply_for_node_(size_t node_index, const Value& v)
  {
    assert (m_childs_update_data[node_index].first == update_none || !childs_exist(node_index));
    switch (m_update_query)
    {
    case update_set:
      node_value(node_index) = v * array_segment_size(node_index);
      break;
    case update_inc:
      node_value(node_index) += v * array_segment_size(node_index);
      break;
    case update_none:
      assert (m_update_query != update_none);
      break;
    }

    if (childs_exist(node_index))
    {
      m_childs_update_data[node_index].first  = m_update_query;
      m_childs_update_data[node_index].second = v;
    }
  }

  void update_childs_by_node_(size_t node_index, size_t child0_index, size_t child1_index)
  {
    if (m_childs_update_data[node_index].first != update_none)
    {
      const UpdateType update_query_orig = m_update_query;

      m_update_query = m_childs_update_data[node_index].first;
      apply_for_node_(child0_index, m_childs_update_data[node_index].second);
      apply_for_node_(child1_index, m_childs_update_data[node_index].second);
      m_childs_update_data[node_index].first = update_none;

      m_update_query = update_query_orig;
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
  UpdateType                      m_update_query;
  vector<pair<UpdateType, Value>> m_childs_update_data;
};

template<class WidthT, class HeightT>
class Stairsteps
{
public:
  Stairsteps(WidthT stair0_x, HeightT stair0_h)
  {
    m[stair0_x] = stair0_h;
    minv[stair0_h] = stair0_x;
  }

  HeightT height(WidthT x) const
  {
    assert(x >= m.begin()->first);
    typename Map::const_iterator it = m.upper_bound(x);
    return (--it)->second;
  }

  WidthT width(HeightT h) const
  {
    assert(h >= m.begin()->second);
    typename MapInv::const_iterator it = minv.upper_bound(h);
    return (--it)->second;
  }

  WidthT width_last() const { return m.rbegin()->first; }

  void inc_height(WidthT x, HeightT h_new)
  {
    assert(x >= m.begin()->first);
    

    if (h_new > height(x))
    {
      typename Map::iterator it = m.find(x);
      if (it == m.end())
        it = m.insert(make_pair(x, h_new)).first;
      else
        minv.erase(it->second);
      it->second = h_new;
      for (++it; it != m.end() && it->second <= h_new; )
      {
        minv.erase(it->second);
        m.erase(it++);
      }
      minv[h_new] = x;
    }
  }

private:
  typedef std::map<WidthT, HeightT> Map;
  typedef std::map<HeightT, WidthT> MapInv;
  Map    m;
  MapInv minv;
};




































































































































































































void main()
{
  io_interactive = false;
  istream& is = input();
  ostream& os = output();

  IN_INT2(n,m);
  vector<int> p(n);
  FOR (i,0,n)
  {
    is>>p[i];
    --p[i];
  }

  vector<vector<int>> a(n);
  FOR (i,0,m)
  {
    IN_INT2(u,v);
    --u,--v;
    a[v].push_back(u);
  }
  FOR (i,0,n)
    sort(ALL(a[i]));

  

  list<int> q;
  FOR (i,0,n-1)
  {
    if (binary_search(ALL(a[p[n-1]]),p[i]))
      

      q.push_back(p[i]);
    else
    {
      vector<int> s(1,p[i]);
      for (list<int>::iterator it = q.end(); it != q.begin(); )
      {
        int v = *(--it);
        bool ok = true;
        FOR_EACH (it_s, s)
          if (!binary_search(ALL(a[*it_s]),v))
          {
            ok = false;
            break;
          }
        if (!ok)
        {
          s.push_back(v);
          it = q.erase(it);
        }
      }
      

      

      

      

      

      

    }
  }
  os << q.size();
  return;
}



































