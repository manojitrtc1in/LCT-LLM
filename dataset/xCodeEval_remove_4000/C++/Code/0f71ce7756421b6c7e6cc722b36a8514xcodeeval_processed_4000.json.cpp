















using namespace std;
typedef long long     ll;
typedef unsigned int  UInt;







template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 














istream& input(bool id2 = false)
{
  ios_base::sync_with_stdio(false);

  static ifstream is("CodeForces/input.txt");
  return is;

  if (id2)
    cin.tie(NULL);
  return cin;
}

ostream& output(bool id2 = false)
{
  cout << setprecision(15);
  if (id2)
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
































































































class id3
{
public:
  id3(int vertex_num) : m_adj_list (vertex_num) {}

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

template<class T> 
inline vector<pair<T, int>> id1(T a)
{
  vector<pair<T, int>> r;
  r.reserve(16);
  for (T i = 2; i*i <= a; ++i)
  {
    if (a % i == 0)
    {
      r.push_back(make_pair(i,0));
      while (a%i == 0)
      {
        ++r.back().second;
        a /= i;
      }
    }
  }

  if (a != 1)
    r.push_back(make_pair(a,1));

  return r;
}



























































































































































































































































































































































































































































































































































































struct Line
{
  map<int,int> ps; 

  int shift;

  Line():shift(0){}
};

void main()
{
  istream& is = input(true);
  ostream& os = output(true);

  IN_INT3(n,w,h);

  


  map<int,Line> lines;
  FOR (i,0,n)
  {
    IN_INT3(d,p,t);  
    Point2I pp;
    int line_ind;
    int line_pos;

    if (d==1)
    {
      pp = Point2I(p,-t);
      line_ind = pp.x+pp.y;
      line_pos = p;
    }
    else
    {
      pp = Point2I(-t,p);
      line_ind = pp.x+pp.y;
      line_pos = -t;
    }

    lines[line_ind].ps[line_pos] = i;
  }

  vector<Point2I> res(n);
  id0 (line_it,lines)
  {
    

    int line_ind = line_it->first;
    map<int,int> ps = line_it->second.ps;
    

    map<int,int>::iterator it = ps.lower_bound(1);

    if (it==ps.begin())
    {
      id0 (it,ps)
        res[it->second] = Point2I(it->first,h);
    }
    else
    {
      for (; it != ps.end(); ++it)
      {
        res[ps.begin()->second] = Point2I(it->first,h);
        ps.erase(ps.begin());
        

      }

      map<int,int>::iterator it1 = line_it->second.ps.begin();
      id0 (it,ps)
      {
        res[it->second] = Point2I(w,-it1->first + line_ind);
        ++it1;
      }
    }


  }

  id0 (it, res)
    os<<it->x<<" "<<it->y<<"\n";
}
































