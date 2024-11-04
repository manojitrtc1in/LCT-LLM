










































































































































typedef long long int lli;
using namespace std;


bool id1(pair<int,int> a, pair<int,int> b)
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


int id0(char c)
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


void print_vector(const vector<int>& h)
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

void print_vector(const vector<long long>& h)
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



void id6(const vector<vector<int> >& h)
{
  int Ly =  h.size();
        
  for(int i = 0; i < Ly; ++ i)
    {
      int Lx = h[i].size(); 
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

void id6(const vector<vector<long long> >& h)
{
  int Ly =  h.size();
        
  for(int i = 0; i < Ly; ++ i)
    {
      int Lx = h[i].size();
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

void id6(const vector<string>& h)
{
  int Ly =  h.size();
        
  for(int i = 0; i < Ly; ++ i)
    {
      int Lx = h[i].size();
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
  Type_value id2;
  
public:
  SegmentTree( vector<Type_value> v, Type_value id3 ) 

  {
    int sz = v.size();
    id2 = id3;
    n = 1;
    while(n < sz)
      {
	n <<= 1;
      }
    
    node.resize(2*n-1, id2);

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
	return id2;
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
struct id4 

{
  
private:
  int size_;
  vector< Type_value > data;

public:
  id4(int sz, Type_value id5 = 0.0 ) 

  {
    size_ = sz;
    data.resize(sz+1,id5);
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

struct RollingHash
{

  
  
private:
  vector<unsigned long long> hash;
  vector<unsigned long long> base_pow;
  unsigned long long base, modulus;

  const unsigned long long id8 = (1ULL << 61) - 1;
  const unsigned long long MASK30 = (1ULL << 30) - 1;
  const unsigned long long MASK31 = (1ULL << 31) - 1;
  const unsigned long long BASE_MIN = 1e7;

  unsigned long long Modulus_2pow61m1( unsigned long long val )
  {
    val = (val & id8) + (val >> 61);

    if( id8 < val )
      {
	val -= id8;
      }

    return val;
  }
  

  unsigned long long Multiple_2pow61m1( unsigned long long a, unsigned long long b )
  {
    unsigned long long au = a >> 31;
    unsigned long long ad = a & MASK31;
    unsigned long long bu = b >> 31;
    unsigned long long bd = b & MASK31;

    unsigned long long mid = ad * bu + au * bd;
    unsigned long long midu = mid >> 30;
    unsigned long long midd = mid & MASK30;

    return Modulus_2pow61m1( ( (au * bu) << 1 ) + midu + (midd << 31) + ad * bd );
  }
 
  void initialize(string& S)
  {
    int N = S.size();
    vector<int> s(N);
    for(int i = 0; i < N; ++i)
      {
	s[i] = S[i];
      }
    
    initialize(s);
  }
 
  void initialize(vector<int>& S)
  {
    hash.resize(S.size()+1);
    base_pow.resize(S.size()+1);
    hash[0] = 0;
    base_pow[0] = 1;

    if( modulus == id8 )
      {	
	for(int i = 1; i <= S.size(); ++i)
	  {
	    hash[i] = Modulus_2pow61m1( Multiple_2pow61m1(hash[i-1],base) + S[i-1] );
	    base_pow[i] = Multiple_2pow61m1(base_pow[i-1],base);
	  }
      }
    else
      {
	for(int i = 1; i <= S.size(); ++i)
	  {
	    hash[i] = ( hash[i-1] * base + S[i-1] ) % modulus;
	    base_pow[i] = ( base_pow[i-1] * base ) % modulus;
	  }
      }
  }

public:
  RollingHash(string S = "", unsigned long long base_ = 0, unsigned long long id7 = 0)
  {
    if( 0 < id7 )
      {
	modulus = id7;
      }
    else
      {
	modulus = id8;
      }

    if( 0 < base_ )
      {
	base = base_;
      }
    else
      {
	mt19937_64 mt64(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<unsigned long long> rand_uniform(BASE_MIN,modulus-BASE_MIN);
	base = rand_uniform(mt64);
      }

    if( S.size() > 0 )
      {
	initialize(S);
      }
  }
  
  

  unsigned long long between(int a, int b)
  {
    if( modulus == id8 )
      {
	return Modulus_2pow61m1( modulus + hash[b] - Multiple_2pow61m1(hash[a],base_pow[b-a]) );
      }
    
    return ( modulus + hash[b] - ( hash[a] * base_pow[b-a] ) % modulus ) % modulus;
  }
};







signed main()
{
  IOS; 
  int N,Q;
  SCAND2(N,Q);
  vector<int> a(N);
  map<int,int> compb;
  map<int,int> comp;
  REP(i,N)
    {
      SCAND(a[i]);
      ++ compb[a[i]];

      if( compb[a[i]] == a[i] )
	{
	  ++ comp[a[i]];
	}
    }

  vector<int> h;
  int num = 0;
  for( auto& elem : comp )
    {
      h.push_back(elem.first);
      elem.second = num;
      ++ num;
    }

  vector<vector<int> > X(num,vector<int>(N+1,0));
  
  REP(i,N)
    {
      if( comp.count(a[i]) )
	{
	  ++ X[comp[a[i]]][i+1];
	}
    }

  REP(id,num)
    {
      REP(i,N)
	{
	  X[id][i+1] += X[id][i];
	}
    }
  
  REP(_,Q)
    {
      int l,r;
      SCAND2(l,r);
      -- l;
      -- r;

      int cnt = 0;
      REP(id,num)
	{
	  if( X[id][r+1] -X[id][l] == h[id] )
	    {
	      ++ cnt;
	    }
	}

      PRINTD(cnt);
      
    }

  
  
  

}