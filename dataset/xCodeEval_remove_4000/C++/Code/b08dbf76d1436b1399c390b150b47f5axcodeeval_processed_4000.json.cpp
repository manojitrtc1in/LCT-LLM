










































































































































typedef long long int lli;
using namespace std;


bool id0(pair<int,int> a, pair<int,int> b)
{
  if( a.second != b.second )
    {
      return a.second < b.second;
    }
  else
    {
      return a.first < b.first;
    }
  
}

int ctoi(char c)
{
  if( c >= '0' and c <= '9' )
    {
      return (int)(c-'0');
    }

  return -1;
}

int alphabet_pos(char c) 
{
  if( c >= 'a' and c <= 'z' )
    {
      return (int)(c-'a');
    }

  return -1;
}


int id5(char c)
{
  if( c >= 'A' and c <= 'Z' )
    {
      return (int)(c-'A');
    }

  return -1;
}


vector<string> split(string str, char ch)
{
  int first = 0;
  int last = str.find_first_of(ch);
  
  if(last == string::npos)
    {
      last = SIZ(str);
    }

  vector<string> result;

  while( first < SIZ(str) )
    {
      string Ssubstr(str, first, last - first);
      result.push_back(Ssubstr);
      first = last + 1;
      last = str.find_first_of(ch, first);

      if(last == string::npos)
	{
	  last = SIZ(str);
	}
    }
  
  return result;
}



int gcd( int a , int b ) 

{
  if( a < b )
    {
      swap(a,b);
    }

  if( a == 0 )
    {
      return b;
    }
  
  if( a % b == 0 )
    {
      return b;    
    }

  return gcd( b , a % b );
  
}

long long gcd( long long a , long long b ) 

{
  if( a < b )
    {
      swap(a,b);
    }

  if( a == 0LL )
    {
      return b;
    }
  
  if( a % b == 0 )
    {
      return b;
    }

  return gcd( b , a % b );
  
}

int lcm( int a , int b ) 

{
  return  a * b / gcd( a , b );
  
}

long long lcm( long long a , long long b ) 

{
  return  a * b / gcd( a , b );
  
}

long long pow_fast( long long x, long long n_power , long long modulus )
{
  
  if( n_power == 0 )
    {
      return 1;
    }
  
  if( n_power % 2 == 0)
    {
      return pow_fast( x * x % modulus , n_power / 2 , modulus );  
    }

  
  return x * pow_fast( x , n_power - 1 , modulus ) % modulus;
}


struct CombinationTable
{
  vector<vector<long long> > val;

  CombinationTable( int size ) : val( size+1 , vector<long long>( size+1 ) ) 

  {
    for( int i = 0 ; i <= size ; ++ i ) 

      {

	for( int j = 0 ; j <= i ; ++ j )
	  {
	    
	    if( j == 0 or j == i )
	      {
		val[i][j] = 1LL;
	      }
	    else
	      {
		val[i][j] = val[i-1][j-1] + val[i-1][j];
	      }

	  }
	
	
      }
    
  }

  
};


void print_vector(vector<int>& h)
{
  int L =  h.size();
  
  for(int i = 0; i < L; ++ i)
    {
      printf("%d",h[i]);

      if( i != L-1 )
	{
	  printf(" ");
	}
      else
	{
	  printf("\n");
	}
    }    
}

void print_vector(vector<long long>& h)
{
  int L =  h.size();
  
  for(int i = 0; i < L; ++ i)
    {
      printf("%lld",h[i]);

      if( i != L-1 )
	{
	  printf(" ");
	}
      else
	{
	  printf("\n");
	}
    }    
}



void id6(vector<vector<int> >& h)
{
  int Ly =  h.size();
  int Lx = h[0].size();
        
  for(int i = 0; i < Ly; ++ i)
    {
      for(int j = 0; j < Lx; ++ j)
        {
	  printf("%d",h[i][j]);

	  if( j != Lx-1 )
	    {
	      printf(" ");
	    }
	  else
	    {
	      printf("\n");
	    }	  
        }
    }    
}

void id6(vector<vector<long long> >& h)
{
  int Ly =  h.size();
  int Lx = h[0].size();
        
  for(int i = 0; i < Ly; ++ i)
    {
      for(int j = 0; j < Lx; ++ j)
        {
	  printf("%lld",h[i][j]);

	  if( j != Lx-1 )
	    {
	      printf(" ");
	    }
	  else
	    {
	      printf("\n");
	    }
        }
    }
}

void id6(vector<string>& h)
{
  int Ly =  h.size();
  int Lx = h[0].size();
        
  for(int i = 0; i < Ly; ++ i)
    {
      for(int j = 0; j < Lx; ++ j)
        {
	  printf("%c",h[i][j]);
        }
      printf("\n");
    }    
}

void print_binary(int val, int num_digit = 31, bool verbose = false)
{
  for(int k = num_digit-1; k >= 0; -- k)
    {
      if( verbose )
	{
	  printf("%d",(val>>k)&1);
	}
      else
	{
	  cerr << ((val>>k)&1);
	}    
    }
  
  if( verbose )
    {
      printf("\n");
    }
  else
    {
      cerr << "\n";
    }
}

void print_binary(long long val, int num_digit = 63, bool verbose = false)
{
  for(int k = num_digit-1; k >= 0; -- k)
    {
      if( verbose )
	{
	  printf("%lld",((val>>k)&1));
	}
      else
	{
	  cerr << ((val>>k)&1);
	}    
    }
  
  if( verbose )
    {
      printf("\n");
    }
  else
    {
      cerr << "\n";
    }
}



struct UnionFind 

{
  vector<int> parent, treesize;
  
  UnionFind( int size ) : parent( size ) , treesize( size , 1 ) 

  {
    for( int i = 0 ; i < size ; ++ i )
      {
	parent[i] = i;
      }
  }

  int root( int x )
  {
    if( parent[x] == x )
      {
	return x;
      }
    
    return parent[x] = root(parent[x]);
  }

  void unite( int x, int y )
  {
    x = root(x); 
    y = root(y);
    
    if( x == y )
      {
	return; 
      }

    if( treesize[x] < treesize[y] )
      {
	parent[x] = y;
	treesize[y] += treesize[x];
      }
    else
      {
	parent[y] = x;
	treesize[x] += treesize[y];	
      }
    
  }

  bool sametree( int x, int y )
  {
    return root(x) == root(y);
  }

  int gettreesize( int x )
  {
    return treesize[root(x)];
  }
  
};

template< typename Type_value >
struct SegmentTree 

{

private:
  int n;
  vector<Type_value> node;
  Type_value id1;
  
public:
  SegmentTree( vector<Type_value> v, Type_value id4 ) 

  {
    int sz = v.size();
    id1 = id4;
    n = 1;
    while(n < sz)
      {
	n <<= 1;
      }
    
    node.resize(2*n-1, id1);

    for( int i = 0 ; i < sz ; ++ i )
      {
	node[i+n-1] = v[i];
      }
    
    for( int i = n-2 ; i >= 0 ; -- i )
      {
	node[i] = min(node[2*i+1], node[2*i+2]);
      } 
  }
 
  void update(int x, Type_value val)
  {
    x += (n - 1);
    node[x] = val;
    
    while( x > 0 )
      {
	x = (x - 1) / 2;
	node[x] = min(node[2*x+1], node[2*x+2]);
      }
  }
 
  Type_value getmin( int a, int b, int k = 0, int l = 0, int r = -1 ) 

  {
    

    

    
    if( r < 0 )
      {
	r = n;
      } 
    if( r <= a or b <= l )
      {
	return id1;
      } 
    if( a <= l and r <= b )
      {
	return node[k];
      }
    
    Type_value vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    Type_value vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
  }
  
};


template< typename Type_value >
struct id2 

{
  
private:
  int size_;
  vector< Type_value > data;

public:
  id2(int sz, Type_value id3 = 0.0 ) 

  {
    size_ = sz;
    data.resize(sz+1,id3);
  }

  Type_value sum(int i) 

  {
    if( i <= 0 )
      {
	return (Type_value) 0.0;
      }

    if( i > size_ )
      {
	i = size_;
      }
    
    Type_value sm = 0.0;
    while( i > 0 )
      {
	sm += data[i];
	i -= i & -i;
      }
    
    return sm;
  }

  void add(int i, Type_value x)
  {
    if( i < 0 or i >= size_ )
      {
	return;
      }
    ++ i;
    while( i <= size_ )
      {
	data[i] += x;
	i += i & -i;
      }
  }
};




int N,K;
vector<int> G[50001];
lli dp[50001][501];
int parent[50001];

lli calc( int id, int k, int par )
{
  if( dp[id][k] != -1 )
    {
      return dp[id][k];
    }

  if( k == 0 )
    {
      return dp[id][k] = 1;
    }

  lli ans = 0LL;
  REP(i,SIZ(G[id]))
    {
      int jd = G[id][i];
      if( jd != par )
	{
	  ans += calc(jd,k-1,id);
	}
    }
  return dp[id][k] = ans;
  
}

void dfs( int id, int par )
{
  parent[id] = par;
  REP(i,SIZ(G[id]))
    {
      int jd = G[id][i];
      if( jd != par )
	{
	  dfs(jd,id);
	}
    }
}

signed main()
{
  IOS; 
  CIN2(N,K);

  REP(_,N-1)
    {
      int a,b;
      CIN2(a,b);
      -- a;
      -- b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

  REP(i,N)
    {
      REP(j,K+1)
	{
	  dp[i][j] = -1;
	}
    }
  
  dfs(0,-1);
  lli ans = 0;
  REP(i,N)
    {
      lli a = calc(i,K,parent[i]);
      lli b = 0;

      REP(j,SIZ(G[i]))
	{
	  int jd = G[i][j];

	  if( jd != parent[i] )
	    {
	      FOR(x,1,K)
		{
		  b += calc(jd,x-1,i) *( calc(i,K-x,parent[i]) - calc(jd,K-x-1,i) );
		}
	    }
	}
      ans += a + (b >> 1);
    }
  
  cout << ans << endl;

}