#pragma comment(linker, "/STACK:1267777216")
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<cctype>
#include<fstream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
#include<functional>
#include<cassert>
#include<bitset>


#define ll long long
#define ull unsigned long long


#define Inf (1000*1000*1000 + 7)
#define InfL (ll)((ll)1000*1000*1000*1000*1000 + 7)
#define pii pair < ll , ll >
#define vi vector < ll >
#define Graph vector < vi >
#define mp make_pair
#define in(n) int (n); cin >> (n)
#define sqr(x) ((double)(x)*(x))
#define Pi 3.14159265358979
#define Eps 1e-6
#define all(x) x.begin() , x.end()
#define re(x) reverse(all(x))
#define so(x) sort(all(x))
#define For for ( int i = 0 ; i < n ; i++ )
#define Forr(i,n) for ( int (i) = 0 ; (i) < (n) ; (i)++ )
#define Forn for ( int i = n - 1 ; i >= 0 ; i-- )
#define iv(x) for ( int i = 0 ; i < x.size() ; cin >> x [ i++ ] )
#define ov(x) for ( int i = 0 ; i < x.size() ; cout << x [ i++ ] << ' ' ); cout << endl
using namespace std;
namespace
{  
    ll binpow ( ll a , ll n )
    {
        ll res = 1;
        while ( n )
        {
            if ( n & 1 )
            {
                res *= a;
                res %= Inf;
            }
            n >>= 1;
            a *= a;
            a %= Inf;
        }
        return res;
    }
    namespace sieve 
    {
        const int MAXN = 1000100;
        vector < int > primes;
        vector < int > mark ( MAXN , 1 );
        void sieve()
        {
            primes.push_back ( 2 );
            for ( int i = 4 ; i < MAXN ; i += 2 )
                mark [ i ] = 0;
            for ( int i = 3 ; i < MAXN ; i += 2 )
            {
                if ( mark [ i ] ) 
                {
                    primes.push_back ( i );
                    for ( ll j = 1ll * i * i ; j < mark.size() ; j += i )
                        mark [ j ] = 0;
                }
            }
        }
    }
	namespace dijkstra
	{
		vi dijkstra ( vector < vector < pii > > vec , int s , int f )
		{
			int n = vec.size();
			vector < ll > d ( n , InfL );
			d [ s ] = 0;
			set < pii > se;
			se.insert ( mp ( d [ s ] , s ) );
			while ( !se.empty() )
			{
				int v = se.begin()->second;
				se.erase ( se.begin() );

				for ( int i = 0 ; i < vec [ v ].size() ; i++ )
					if ( vec [ v ] [ i ].second < InfL )
						if ( d [ vec [ v ] [ i ].first ] > d [ v ] + vec [ v ] [ i ].second )
						{
							se.erase ( mp ( d [ vec [ v ] [ i ].first ] , vec [ v ] [ i ].first ) );
							d [ vec [ v ] [ i ].first ] = d [ v ] + vec [ v ] [ i ].second;
							se.insert ( mp ( d [ vec [ v ] [ i ].first ] , vec [ v ] [ i ].first ) );
						}
			}
			return d;
		}
	}
	namespace segment_tree
	{
		int n;
		vector < int > vec;
		int func ( int a , int b )
		{
			return a + b ;
		}
		const int MAXN = 5 * 1e5;
		int tree [ 4 * MAXN ];
		void build_tree ( int v = 1 , int tl = 0 , int tr = n - 1 )
		{
			if ( tl == tr )
				tree [ v ] = vec [ tl ];
			else
			{
				int tm = ( tl + tr ) >> 1;
				build_tree ( 2 * v , tl , tm );
				build_tree ( 2 * v + 1 , tm + 1 , tr );
				tree [ v ] = func ( tree [ 2 * v ] , tree [ 2 * v + 1 ] );
			}
		}
		int query ( int l , int r , int v = 1 , int tl = 0 , int tr = n - 1 )
		{
			if ( r < l )
				return 0;
			if ( l == tl && r == tr )
				return tree [ v ];
			else
			{
				int tm = ( tl + tr ) >> 1;
				return func ( query ( l , min ( r , tm ) , 2 * v , tl , tm ) , 
							query ( max ( l , tm + 1 ) , r , 2 * v + 1 , tm + 1 , tr ) ) ;
			}
		}
		void update ( int i , int val , int v = 1 , int tl = 0 , int tr = n - 1 )
		{
			if ( tl == tr )
			{
				tree [ v ] = val;
				vec [ i ] = val;
			}
			else 
			{
				int tm = ( tl + tr ) >> 1;
				if ( i <= tm )
					update ( i , val , 2 * v , tl , tm );
				else
					update ( i , val , 2 * v + 1 , tm + 1 , tr );
				tree [ v ] = func ( tree [ 2 * v ] , tree [ 2 * v + 1 ] );
			}
		}
	}
	vi bfs ( int v , Graph & vec )
	{
		vi dist ( vec.size() , InfL );
		vi used ( vec.size() );
		used [ v ] = 1;
		dist [ v ] = 0;
		queue < ll > q;
		q.push ( v );
		while ( !q.empty() )
		{
			int from = q.front();
			q.pop();
			for ( int i = 0 ; i < vec [ from ].size() ; i++ )
			{
				int to = vec [ from ] [ i ];
				if ( !used [ to ] )
				{
					dist [ to ] = dist [ from ] + 1;
					used [ to ] = 1;
					q.push ( to );
				}
			}
		}
		return dist;
	}
	bool comp ( pii a , pii b )
	{
		return a.second < b.second;
	}
	long long C ( int n , int m ) 
	{
		long long res = 1;
		for ( int i = 0 ; i < m ; ++i )
			res *= (n - i);
		for ( int i = 2 ; i <= m ; ++i ) 
			res /= i;
		return res;
	}
	namespace LCA 
	{
		const int MAXN = 1e5 + 100;
		vector < int > out [ MAXN ] , in [ MAXN ];  

		int par [ MAXN ] [ 20 ];
		int dist [ MAXN ] [ 2 ];
		int depth [ MAXN ];
		
		void dfs ( int v , int p = -1 )
		{
			for ( int i = 0 ; i < 19 ; i++ )
				par [ v ] [ i + 1 ] = par [ par [ v ] [ i ] ] [ i ];
			for ( int i = 0 ; i < out [ v ].size() ; i++ )
			{
				int nxt = out [ v ] [ i ];
				if ( nxt == p ) continue;
				par [ nxt ] [ 0 ] = v;
				depth [ nxt ] = depth [ v ] + 1;
				dist [ nxt ] [ 1 ] = dist [ v ] [ 1 ] + 1;
				dist [ nxt ] [ 0 ] = 0;
				dfs ( nxt , v );
			}
			for ( int i = 0 ; i < in [ v ].size() ; i++ )
			{
				int nxt = in [ v ] [ i ];
				if ( nxt == p ) continue;
				par [ nxt ] [ 0 ] = v;
				depth [ nxt ] = depth [ v ] + 1;
				dist [ nxt ] [ 0 ] = dist [ v ] [ 0 ] + 1;
				dist [ nxt ] [ 1 ] = 0;
				dfs ( nxt , v );
			}
			
		}

		int lca ( int a , int b )
		{
			if ( depth [ a ] < depth [ b ] ) 
				swap  ( a , b );
			for ( int i = 19 ; i >= 0 ; i-- )
				if ( depth [ a ] >= depth [ b ] + ( 1 << i ) )
					a = par [ a ] [ i ];
			if ( a == b )
				return a;
			for ( int i = 19 ; i >= 0 ; i-- )
				if ( par [ a ] [ i ] != par [ b ] [ i ] )
					a = par [ a ] [ i ] , b = par [ b ] [ i ];
			return par [ a ] [ 0 ];
		}
		bool query ( int x , int y )
		{
			int z = lca ( x , y );
			return ( dist [ x ] [ 0 ] >= depth [ x ] - depth [ z ] ) &&
					( dist [ y ] [ 1 ] >= depth [ y ] - depth [ z ] );
		}
	}
	vector < vector < int > > g;
	namespace HLD
	{
		int N;
		vector < vector < int > > paths;
		vector < vector < int > > trees;
		vector < int > roots;
		vector < int > dist;
		vector < int > s;
		vector < int > pvs;
		vector < int > number_of_path;
		vector < int > tin , tout;
		int timer;
		queue < int > lists;
		int dfs ( int v , int depth = 0 , int p = -1 ) 
		{
			tin [ v ] = ++timer;
			pvs [ v ] = p;
			dist [ v ] = depth;
			int sons = 0;
			for ( int i = 0 ; i < g [ v ].size() ; i++ )
			{
				int to = g [ v ] [ i ];
				if ( to != p ) 
					sons += dfs ( to , depth + 1 , v );
			}
			if ( sons == 0 )
				lists.push ( v );
			tout [ v ] = ++timer;
			return s [ v ] = sons + 1;
		}
		void create_pathes()
		{
			while ( !lists.empty() )
			{
				int start = lists.front();
				lists.pop();
				paths.push_back ( vector < int >() );
				while ( pvs [ start ] != -1 && s [ start ] >= 2 * s [ pvs [ start ] ] )
				{
					paths.back().push_back ( start );
					number_of_path [ start ] = paths.size() + 1;
					start = pvs [ start ];
				}
				if ( pvs [ start ] != -1 )
					lists.push ( start );
			}
		}
		int func ( int a , int b )
		{
			return max ( a , b );
		}
		void build_tree ( int index , int v = 1 , int tl = 0 , int tr = N )
		{
			if ( tr == tl )
			{
				trees [ index ] [ v ] = 0;
			}
			else
			{
				int tm = ( tl + tr ) >> 1;
				build_tree ( index , 2 * v , tl , tm );
				build_tree ( index , 2 * v + 1, tm + 1 , tr );
				trees [ index ] [ v ] = func ( trees [ index ] [ 2 * v ] , trees [ index ] [ 2 * v + 1 ] );
			}
		}
		void update ( int index , int pos , int value , int v = 1 , int tl = 0 , int tr = N )
		{
			if ( tl == tr && tl == pos )
			{
				trees [ index ] [ pos ] += v;
			}
			else
			{
				int tm = ( tl + tr ) >> 1;
				if ( tm < pos )
					update ( index , pos , value , 2 * v , tl , tm );
				else
					update ( index , pos , value , 2 * v + 1 , tm + 1 , tr );
				trees [ index ] [ v ] = func ( trees [ index ] [ 2 * v ] , trees [ index ] [ 2 * v + 1 ] );
			}
		}
		int query ( int index , int l , int r , int v = 1 , int tl = 0 , int tr = N )
		{
			if ( l > r )
				return 0;
			if ( tl == l && tr == r )
			{
				return trees [ index ] [ v ];
			}
			else
			{
				int tm = ( tl + tr ) >> 1;
				return func ( query ( index , l , min ( tm , r ) , 2 * v , tl , tm ) , 
							query ( index , max ( tm + 1 , l ) , r , 2 * v + 1 , tm + 1 , tr ) );
								
			}

		}
		int query ( int u , int v ) 
		{
			int res = 0;
			int root = roots [ u ]; 
			while ( tin [ root ] < tin [ v ] && tout [ root ] > tout [ v ] )
			{
				res = func ( res , query ( number_of_path [ u ] , u , v ) );
				u = pvs [ u ];
				root = roots [ u ];
			}
			root = roots [ v ]; 
			while ( tin [ root ] < tin [ u ] && tout [ root ] > tout [ u ] )
			{
				res = func ( res , query ( number_of_path [ v ] , u , v ) );
				u = pvs [ v ];
				root = roots [ v ];
			}
			res = func ( res , query ( u , min ( dist [ u ] , dist [ v ] ) , max ( dist [ u ] , dist [ v ] ) ) );
			return res;

		}
		void update ( int pos , int value )
		{
			update ( number_of_path [ pos ] , pos , value );
		}
		void init ( int n )
		{
			N = n;
			roots.resize ( n );
			dist.resize ( n );
			s.resize ( n );
			pvs.resize ( n );
			tin.resize ( n );
			tout.resize ( n );
			number_of_path.resize ( n );
			dfs ( 0 );
			create_pathes();
			trees.resize ( paths.size() );
			for ( int i = 0 ; i < n ; i++ )
			{
				trees [ i ].resize ( paths [ i ].size() << 2 );
				build_tree ( i );
			}
		}
	}
	int check ( vi & vec )
	{
		int ret = -1 , c = 0;
		for ( int i = 1 ; i < vec.size() ; i++ )
		{
			if ( vec [ i ] != vec [ i - 1 ] )
				c++;
			else
			{
				ret = max ( ret , c - 1 );
				c = 0;
			}
		}
		return max ( ret , c - 1 );
	}
	void run()
    {
		int n;
		cin >> n;
		vi vec ( n ) ;
		iv ( vec );
		vi temp ( n );
		temp = vec;
		int count = 0;
		int ans = ( check ( vec ) + 1 ) / 2;
		for ( int i = 1 , j = 0 ; i < n ; i++ )
		{
			while ( vec [ i ] != vec [ i - 1 ] )
			{
				if ( i == n - 1 )
					break;
				i++;
				
			}
			if ( j == i - 1 )
			{
				j = i;
				continue;
			}
			if ( vec [ i ] == vec [ j ] )
				for ( int k = j ; k <= i ; k++ )
					temp [ k ] = vec [ i ];
			else
			{
				for ( int k = j ; k < j + ( i - j + 1 ) / 2 ; k++ )
				{
					temp [ k ] = vec [ j ];
				}
				for ( int k = j + ( i - j + 1 ) / 2 ; k < i ; k++ )
				{
					temp [ k ] = vec [ i ];
				}

			}
			j = i;
		}
		
		cout << ans << endl;
		ov ( temp );

	}
}
int main()  
{










    cout << fixed << setprecision( 13 );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    run(); return 0;
}