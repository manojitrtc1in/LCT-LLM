﻿#define _USE_MATH_DEFINES
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long     ll;
typedef unsigned int  UInt;
#define IN_INT(a)         int a;       is >> a;
#define IN_INT2(a,b)      int a,b;     is >> a >> b;
#define IN_INT3(a,b,c)    int a,b,c;   is >> a >> b >> c;
#define IN_INT4(a,b,c,d)  int a,b,c,d; is >> a >> b >> c >> d;
#define IN_LL(a)          ll a;        is >> a;
#define IN_LL2(a,b)       ll a,b;      is >> a >> b;
#define IN_LL3(a,b,c)     ll a,b,c;    is >> a >> b >> c;
#define IN_LL4(a,b,c,d)   ll a,b,c,d;  is >> a >> b >> c >> d;
#define IN_STR(s)         string s;    is >> s;
#define ALL(a)         (a).begin(), (a).end()
#define FOR(i,a,b)     for(int i = a;   i <  (int)(b); ++i)
#define FOR_REV(i,a,b) for(int i = b-1; i >= (int)(a); --i)
#define FOR_EACH(it,a) for(remove_reference<decltype(a)>::type::iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_REV(it,a) for(remove_reference<decltype(a)>::type::reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
#define FOR_EACH_CONST(it,a) for(remove_reference<decltype(a)>::type::const_iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_CONST_REV(it,a) for(remove_reference<decltype(a)>::type::const_reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 

template<class T> inline T   gcd(T a, T b) { while(b) { T t = b; b = a % b; a = t; } return a; }




istream& input(bool release_tie = false)
{
  ios_base::sync_with_stdio(false);
#ifdef INPUT_FROM_FILE
  static ifstream is("CodeForces/input.txt");
  return is;
#endif
  if (release_tie)
    cin.tie(NULL);
  return cin;
}

ostream& output(bool release_tie = false)
{
  cout << setprecision(15);
  if (release_tie)
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

template <typename T>
int quadratic_equation(T a, T b, T c, T& x0, T& x1)
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




class GraphAdjacentList
{
public:
  GraphAdjacentList(int vertex_num) : m_adj_list (vertex_num) {}

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




template<class T, class SegmentData>
class SegmentsUnion
{
public:
  void add_segment(T l, T r, const SegmentData& data) 

  {
    bool insertion_need = true, r_inclusive = true;
    typename M::iterator it = find_rightmost(r, r_inclusive);
    if (it != m.end())
    {
      cut_rightmost(it->second, l, r, r_inclusive, data);
      for(it = find_rightmost(r, r_inclusive); it != m.end(); insertion_need &= cut(it, l, r, data));
    }

    if (insertion_need)
    {
      Segment s = {r,true,r_inclusive,data};
      typename M::iterator it1 = m.find(l); 

      m.insert(it1, make_pair(l,s));
    }
  }

  template<class Enum>
  void enumerate(T l, T r, Enum& enumerator) const
  {
    typename M::const_iterator it = m.upper_bound(r);
    for (; it != m.begin() && (it == m.end() || it->second.r >= l); )
    {
      --it;
      const Segment& s = it->second;
      const T sl = max(l, it->first);
      const T sr = min(r, s.r);
      const bool l_incl = s.l_inclusive || sl > it->first;
      const bool r_incl = s.r_inclusive || sr < s.r;

      if (sl < sr || (sl == sr && l_incl))
        enumerator(sl, sr, l_incl, r_incl, s.data);
    }
  }

private:
  struct Segment
  {
    T           r;
    bool        l_inclusive, r_inclusive;
    SegmentData data;
  };
  typedef multimap<T,Segment> M;

private:
  typename M::iterator find_rightmost(const T& r, bool r_inclusive)
  {
    typename M::iterator it = m.upper_bound(r);
    if (it != m.begin())
    {
      --it;
      if (it->first < r || (r_inclusive && it->second.l_inclusive))
        return it;
      if (it != m.begin())
      {
        --it;
        if (it->first < r || (r_inclusive && it->second.l_inclusive)) 

          return it;
        if (it != m.begin())
          return --it;
      }
    }
    return m.end();
  }

  void cut_rightmost(const Segment& s, const T& l, T& r, bool& r_inclusive, const SegmentData& data)
  {
    if (s.r > r)
    {
      if (s.data == data)
      {
        r = s.r;
        r_inclusive = s.r_inclusive;
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
          s.r_inclusive = true;
          return false;
        }
        else
        {
          s.r = l;
          s.r_inclusive = false;
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

inline UInt log2i (UInt v)
{
  const UInt i = upper_bit(v);
  return (1u<<i) >= v ? i : i+1; 

}


























































































































































































































struct CalcRes
{
  CalcRes():res(0){}
  void operator()(int l, int r, bool li, bool ri, const int& data) { res+=data; }
  int res;
};

bool complete(int i, const SegmentsUnion<int,int>& ts)
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

































