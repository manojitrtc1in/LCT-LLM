






#include <bits/stdc++.h>



#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(i, e) for( int i = 0 ; i < (e) ; i++ )
#define ITER(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define IOS ios_base::sync_with_stdio( 0 )
#define DEBUG 1
#define fst first
#define snd second
#define PB push_back
#ifdef ONLINE_JUDGE
#define FILE( fn ) \
    freopen(fn".in","r",stdin); \
    freopen(fn".out","w",stdout);
#else
#define FILE( fn )
#endif

#ifdef AKAI
#define debug( ... ) fprintf( stderr , __VA_ARGS__ )
#else
#define debug( ... )
#endif

using namespace std;



typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int> tli;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
typedef unsigned long long ull;



const double EPS = 1e-8;
const double Pi = acos(-1);



bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

int _R( int& x ) { return scanf( "%d" , &x ); }
int _R( ll& x ) { return scanf( "%" PRId64 , &x ); }
int _R( double& x ) { return scanf( "%lf" , &x ); }
int _R( char* s ) { return scanf( "%s" , s ); }

int R() { return 0; }

template< typename T1 , typename... T2 >
int R( T1& x , T2&... tail )
{
  int tmp = _R( x );
  return tmp + R( tail... );
}

template< typename Iter , typename F >
inline void out( Iter s , Iter e , F of )
{
  bool flag = 0;
  for( Iter it = s ; it != e ; it++ )
  {
    if( flag ) printf( " " );
    else flag = 1;
    of( *it );
  }
  puts( "" );
}






const int MAXN = 1e5+10;
const int LOG = 18;

typedef double type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
const type INF = 1e15;
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void out( const Pt& pt ) { debug( "(%.6f, %.6f)" , pt.X , pt.Y ); }
void out( const Line& ln ) {
  debug( "[" );out(ln.first);debug(", ");out(ln.second);debug( "]\n" );
}

void real_out( const Pt& pt ) { printf( "(%.6f, %.6f)" , pt.X , pt.Y ); }
void real_out( const Line& ln ) {
  printf( "[" );real_out(ln.first);printf(", ");real_out(ln.second);printf( "]\n" );
}

bool in_seg( Line seg , Pt p ) {
  debug("in_seg\n");
  out(seg);
  out(p);debug("\n");
  if( equ( p.X , seg.first.X ) && equ( p.Y , seg.first.Y ) )
    return 1;
  if( equ( p.X , seg.second.X ) && equ( p.Y , seg.second.Y ) )
    return 1;
  type dots = (p-seg.first)*(p-seg.second);
  bool res = 0;
  if( dots < -EPS ) {
    res = equ( (p-seg.first)^(p-seg.second) , 0 );
  }
  debug( "  return %d\n" , res ? 1 : 0 );
  return res;
}

type interPntX( Line l1, Line l2 ){
  Pt p1, p2, q1, q2;
  tie(p1, p2) = l1;
  tie(q1, q2) = l2;
  type f1 = (p2 - p1) ^ (q1 - p1);
  type f2 = (p2 - p1) ^ (p1 - q2);
  type f = (f1 + f2);
  if( fabs(f) < EPS ) {
    debug("weird\n");
    out(l1);
    out(l2);
    debug("weird\n");
    type res = INF;
    if( in_seg( l1 , q1 ) ) res = min( res , q1.X );
    if( in_seg( l1 , q2 ) ) res = min( res , q2.X );
    if( in_seg( l2 , p1 ) ) res = min( res , p1.X );
    if( in_seg( l2 , p2 ) ) res = min( res , p2.X );
    return res;
  }
  type res = q1.X * (f2 / f) + q2.X * (f1 / f);
  if( res < q1.X-EPS || q2.X+EPS < res ) return INF;
  if( res < p1.X-EPS || p2.X+EPS < res ) return INF;
  return res;
}

type y_at_x( const Line& l , type x ) {
  if( equ( l.first.X , l.second.X ) )
    return l.second.Y;
  type tot = l.second.X - l.first.X;
  type par = ( x - l.first.X ) / tot;
  return l.first.Y * ( 1.-par ) + l.second.Y * par;
}

int n , m;
vector<Line> segs[ MAXN ];

type now_x;
vector<Line> lines;
struct SegInter {
  typedef pair< Pt , int > Event;
  struct Cmp {
    bool operator()( int a , int b ) {
      Line la = lines[ a ];
      Line lb = lines[ b ];
      type ya = y_at_x( la , now_x );
      type yb = y_at_x( lb , now_x );
      

      

      

      

      if( equ( ya , yb ) ) return a < b;
      return ya < yb;
    }
  };
  type intersecs( vector<Line> _lines ) {
    lines = _lines;
    if( m <= 2000 ) {
      type rres = INF;
      FOR( i , SZ( lines ) ) {
        auto li = lines[ i ];
        REP( j , i+1 , SZ( lines )-1 ) {
          auto lj = lines[ j ];
          type intpx = interPntX( li , lj );
          

            

              

              

              

            

          

          rres = min( rres , intpx );
        }
      }
      return rres;
    }

    vector<Event> events;
    FOR( i , SZ( lines ) ) {
      auto line = lines[ i ];
      debug("id %d ", i);out( line );
      if( line.first > line.second )
        swap( line.first , line.second );
      events.push_back( { line.first , -i-1 } );
      events.push_back( { line.second , i } );
    }
    sort( ALL( events ) );
    set< int , Cmp > bst;
    type res = INF;
    for( auto event : events ) {
      now_x = event.first.X;
      if( now_x > res-EPS ) break ;
      int id = event.second;
      debug( "cur res %.6f\n" , res );
      debug( "event id %d now_x %.6f\n" , id , now_x );
      if( id < 0 ) {
        id = -id-1;
        bst.insert( id );
        auto it = bst.lower_bound( id );
        debug( "it data %d\n" , *it );

        assert( it != bst.end() );
        if( it != bst.begin() ) {
          auto it_p = it;
          --it_p;
          type intpx = interPntX( lines[ id ] , lines[ *it_p ] );
          debug( "it_p data %d\n" , *it_p );
          debug( "line %d %d X @ %.6f\n" , id , *it_p , intpx );
          

            

            

          

          res = min( res , intpx );
        }
        if( ++it != bst.end() ) {
          auto it_n = it;
          type intpx = interPntX( lines[ id ] , lines[ *it_n ] );
          debug( "it_n data %d\n" , *it_n );
          debug( "line %d %d X @ %.6f\n" , id , *it_n , intpx );
          

            

            

          

          res = min( res , intpx );
        }
      } else {
        

        auto it = bst.lower_bound( id );
        assert( it != bst.end() );
        debug( "it data %d\n" , *it );
        if( it != bst.begin() ) {
          auto it_p = it;
          --it_p;
          auto it_n = it;
          ++it_n;
          if( it_n != bst.end() ) {
            type intpx = interPntX( lines[ *it_p ] , lines[ *it_n ] );
            debug( "line %d %d X @ %.6f\n" , *it_p , *it_n , intpx );
            

              

              

            

            res = min( res , intpx );
          }
        }
        debug( "erase %d\n" , *it );
        bst.erase( it );
        debug( "erase done\n" );
      }
    }
    debug( "res %.6f\n" , res );
    return res;
  }
} seg_inter;

struct HLD{
  int n;
  vector<int> g[MAXN];
  int sz[MAXN], dep[MAXN];
  int ts, tid[MAXN], tdi[MAXN], tl[MAXN], tr[MAXN];
  

  

  

  

  int mom[MAXN][LOG], head[MAXN];
  

  void dfssz(int u, int p){
    dep[u] = dep[p] + 1;
    mom[u][0] = p;
    sz[u] = 1;
    head[u] = u;
    for(int& v:g[u]) if(v != p){
      dep[v] = dep[u] + 1;
      dfssz(v, u);
      sz[u] += sz[v];
    }
  }
  void dfshl(int u){
    

    ts++;
    tid[u] = tl[u] = tr[u] = ts;
    tdi[tid[u]] = u;
    sort(ALL(g[u]), [&](int a, int b){return sz[a] > sz[b];});
    bool flag = 1;
    for(int& v:g[u]) if(v != mom[u][0]){
      if(flag) head[v] = head[u], flag = 0;
      dfshl(v);
      tr[u] = tr[v];
    }
  }
  inline int lca(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);
    

    int diff = dep[b] - dep[a];
    REPD(k, LOG-1, 0) if(diff & (1<<k)){
      

      b = mom[b][k];
    }
    if(a == b) return a;
    REPD(k, LOG-1, 0) if(mom[a][k] != mom[b][k]){
      a = mom[a][k];
      b = mom[b][k];
    }
    return mom[a][0];
  }
  void init( int _n ){
    n = _n;
    REP( i , 1 , n ) g[ i ].clear();
  }
  void addEdge( int u , int v ){
    g[ u ].push_back( v );
    g[ v ].push_back( u );
  }
  void yutruli(){
    dfssz(1, 0);
    ts = 0;
    dfshl(1);
    REP(k, 1, LOG-1) REP(i, 1, n)
      mom[i][k] = mom[mom[i][k-1]][k-1];
  }
  vector< tii > getPath( int u , int v ){
    vector< tii > res;
    while( tid[ u ] < tid[ head[ v ] ] ){
      res.push_back( tii( tid[ head[ v ] ] , tid[ v ] ) );
      v = mom[ head[ v ] ][ 0 ];
    }
    res.push_back( tii( tid[ u ]+1 , tid[ v ] ) );
    reverse( ALL( res ) );
    return res;
    
  }
} tree;

void go_seg() {
  int t , c , u , v;
  R( t , c , u , v );
  debug( "now %d %d %d %d\n" , t , c , u , v );

  if( u == v ) {
    Line the_seg;
    the_seg.first = { t , tree.dep[ u ] };
    the_seg.second = { t , tree.dep[ u ] };
    segs[ tree.head[ u ] ].push_back( the_seg );
    return;
  }

  int anc = tree.lca( u , v );

  type unit_t = 1. / c;
  type cur_t = t;

  set<int> added;

  vector< tii > path = tree.getPath( anc , u );
  reverse( ALL( path ) );
  debug( "path u ~> anc\n" );
  for( tii tp : path ) {
    int l , r;tie( l , r ) = tp;
    if( l > r+1 ) continue ;
    int uu = tree.tdi[ l ] , vv = tree.tdi[ r ];
    debug( "%d ~> %d\n" , vv , uu );
    int id = tree.head[ uu ];
    Line seg;
    seg.first = { cur_t , tree.dep[ vv ] };
    int dist = tree.dep[ vv ] - tree.dep[ uu ] + 1;
    cur_t += unit_t * dist;
    seg.second = { cur_t , tree.dep[ uu ]-1 };
    if( added.count( id ) == 0 ) {
      debug( "  %d add " , id );out(seg);
      segs[ id ].push_back( seg );
      added.insert( id );
    } else {
      Line old_seg = segs[ id ].back();
      if( equ( old_seg.first.X , old_seg.second.X ) && equ( old_seg.first.Y , old_seg.second.Y ) )
        segs[ id ].back() = seg;
    }
  }

  path = tree.getPath( anc , v );
  debug( "path anc ~> v\n" );
  for( tii tp : path ) {
    int l , r;tie( l , r ) = tp;
    if( l > r+1 ) continue ;
    int uu = tree.tdi[ l ] , vv = tree.tdi[ r ];
    debug( "%d ~> %d\n" , uu , vv );
    int id = tree.head[ uu ];
    Line seg;
    seg.first = { cur_t , tree.dep[ uu ]-1 };
    int dist = tree.dep[ vv ] - tree.dep[ uu ] + 1;
    cur_t += unit_t * dist;
    seg.second = { cur_t , tree.dep[ vv ] };
    if( added.count( id ) == 0 ) {
      debug( "  %d add " , id );out(seg);
      segs[ id ].push_back( seg );
      added.insert( id );
    } else {
      Line old_seg = segs[ id ].back();
      if( equ( old_seg.first.X , old_seg.second.X ) && equ( old_seg.first.Y , old_seg.second.Y ) )
        segs[ id ].back() = seg;
    }
  }
}

int main()
{
  R( n , m );
  tree.init( n );
  FOR( i , n-1 ) {
    int u , v;R( u , v );
    tree.addEdge( u , v );
  }
  tree.yutruli();
  REP( i , 1 , m ) {
    go_seg();
  }
  debug( "input done\n" );
  REP( i , 1 , n ) debug( "head %d %d\n" , i , tree.head[ i ] );
  type ans = INF;
  REP( i , 1 , n ) {
    debug( "doing chain head %d\n" , i );
    ans = min( ans , seg_inter.intersecs( segs[ i ] ) );
  }
  if( ans > 1e10 ) puts( "-1" );
  else printf( "%.10f\n" , ans );
}
