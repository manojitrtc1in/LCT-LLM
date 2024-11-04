#define _USE_MATH_DEFINES
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
#define ALL(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for(int i = a;   i <  (int)(b); ++i)
#define FOR_REV(i,a,b)  for(int i = b-1; i >= (int)(a); --i)
#define FOR_EACH(it,a)  for(remove_reference<decltype(a)>::type::iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_REV(it,a) for(remove_reference<decltype(a)>::type::reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
#define FOR_EACH_CONST(it,a) for(remove_reference<decltype(a)>::type::const_iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_CONST_REV(it,a) for(remove_reference<decltype(a)>::type::const_reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 

#define IN_INT(a)            int a;       is >> a;
#define IN_INT2(a,b)         int a,b;     is >> a >> b;
#define IN_INT3(a,b,c)       int a,b,c;   is >> a >> b >> c;
#define IN_INT4(a,b,c,d)     int a,b,c,d; is >> a >> b >> c >> d;
#define IN_LL(a)             ll a;        is >> a;
#define IN_LL2(a,b)          ll a,b;      is >> a >> b;
#define IN_LL3(a,b,c)        ll a,b,c;    is >> a >> b >> c;
#define IN_LL4(a,b,c,d)      ll a,b,c,d;  is >> a >> b >> c >> d;
#define IN_STR(s)            string s;    is >> s;




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

















































































































































































































































































































































































































































































































































































































































void main()
{
  istream& is = input();
  ostream& os = output();

  IN_INT2(n,s);

  

  ll res=0,sa=0,sb=0;
  map<ll,ll> ma,mb;
  FOR (i,0,n)
  {
    IN_LL3(s,a,b);
    res+=s*max(a,b);
    (a>b?sa:sb)+=s;
    (a>b?ma:mb)[abs(a-b)]+=s;
  }

  if (sa%s + sb%s > s){
    os<<res;
    return;
  }
  ll resa=res;
  for (ll left = sa%s;left>0;)
  {
    ll cost = ma.begin()->first;
    ll num = ma.begin()->second;
    ma.erase(ma.begin());
    resa-=min(num,left)*cost;
    left-=num;
  }

  ll resb=res;
  for (ll left = sb%s;left>0;)
  {
    ll cost = mb.begin()->first;
    ll num = mb.begin()->second;
    mb.erase(mb.begin());
    resb-=min(num,left)*cost;
    left-=num;
  }


  os << max(resa,resb);
}



































































