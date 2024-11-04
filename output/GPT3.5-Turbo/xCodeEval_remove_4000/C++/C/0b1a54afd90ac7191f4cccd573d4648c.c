#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long lli;

int ctoi(char c)
{
  if( c >= '0' && c <= '9' )
  {
    return (int)(c-'0');
  }

  return -1;
}

int alphabet_pos(char c) 
{
  if( c >= 'a' && c <= 'z' )
  {
    return (int)(c-'a');
  }

  return -1;
}

int id6(char c)
{
  if( c >= 'A' && c <= 'Z' )
  {
    return (int)(c-'A');
  }

  return -1;
}

int gcd( int a , int b ) 
{
  if( a < b )
  {
    int temp = a;
    a = b;
    b = temp;
  }

  if( b == 0 )
  {
    return a;
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
    long long temp = a;
    a = b;
    b = temp;
  }

  if( b == 0LL )
  {
    return a;
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
  long long** val;
  int size;

  CombinationTable( int size ) 
  {
    this->size = size;
    val = (long long**)malloc((size+1) * sizeof(long long*));
    for( int i = 0 ; i <= size ; ++ i ) 
    {
      val[i] = (long long*)malloc((size+1) * sizeof(long long));
    }

    for( int i = 0 ; i <= size ; ++ i ) 
    {
      for( int j = 0 ; j <= i ; ++ j )
      {
        if( j == 0 || j == i )
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

void print_vector(int* h, int L, bool verbose)
{
  for(int i = 0; i < L; ++ i)
  {
    if( verbose )
    {
      printf("%d",h[i]);
    }
    else
    {
      fprintf(stderr, "%d", h[i]);
    }

    if( i != L-1 )
    {
      if( verbose )
      {
        printf(" ");
      }
      else
      {
        fprintf(stderr, " ");
      }
    }
    else
    {
      if( verbose )
      {
        printf("\n");
      }
      else
      {
        fprintf(stderr, "\n");
      }
    }
  }    
}

void print_vector(lli* h, int L, bool verbose)
{
  for(int i = 0; i < L; ++ i)
  {
    if( verbose )
    {
      printf("%lld",h[i]);
    }
    else
    {
      fprintf(stderr, "%lld", h[i]);
    }

    if( i != L-1 )
    {
      if( verbose )
      {
        printf(" ");
      }
      else
      {
        fprintf(stderr, " ");
      }
    }
    else
    {
      if( verbose )
      {
        printf("\n");
      }
      else
      {
        fprintf(stderr, "\n");
      }
    }
  }    
}

void id7(int** h, int Ly, int Lx, bool verbose)
{
  for(int i = 0; i < Ly; ++ i)
  {
    for(int j = 0; j < Lx; ++ j)
    {	  
      if( verbose )
      {
        printf("%d",h[i][j]);
      }
      else
      {
        fprintf(stderr, "%d", h[i][j]);
      }

      if( j != Lx-1 )
      {
        if( verbose )
        {
          printf(" ");
        }
        else
        {
          fprintf(stderr, " ");
        }
      }
      else
      {
        if( verbose )
        {
          printf("\n");
        }
        else
        {
          fprintf(stderr, "\n");
        }
      }	  
    }
  }    
}

void id7(lli** h, int Ly, int Lx, bool verbose)
{
  for(int i = 0; i < Ly; ++ i)
  {
    for(int j = 0; j < Lx; ++ j)
    {
      if( verbose )
      {
        printf("%lld",h[i][j]);
      }
      else
      {
        fprintf(stderr, "%lld", h[i][j]);
      }

      if( j != Lx-1 )
      {
        if( verbose )
        {
          printf(" ");
        }
        else
        {
          fprintf(stderr, " ");
        }
      }
      else
      {
        if( verbose )
        {
          printf("\n");
        }
        else
        {
          fprintf(stderr, "\n");
        }
      }
    }
  }
}

void id7(char** h, int Ly, bool verbose)
{
  for(int i = 0; i < Ly; ++ i)
  {
    int Lx = strlen(h[i]);
    for(int j = 0; j < Lx; ++ j)
    {
      if( verbose )
      {
        printf("%c",h[i][j]);
      }
      else
      {
        fprintf(stderr, "%c", h[i][j]);
      }
    }
  
    if( verbose )
    {
      printf("\n");
    }
    else
    {
      fprintf(stderr, "\n");
    }
  }    
}

void print_binary(int val, int num_digit, bool verbose)
{
  for(int k = num_digit-1; k >= 0; -- k)
  {
    if( verbose )
    {
      printf("%d",(val>>k)&1);
    }
    else
    {
      fprintf(stderr, "%d", ((val>>k)&1));
    }    
  }
  
  if( verbose )
  {
    printf("\n");
  }
  else
  {
    fprintf(stderr, "\n");
  }
}

void print_binary(lli val, int num_digit, bool verbose)
{
  for(int k = num_digit-1; k >= 0; -- k)
  {
    if( verbose )
    {
      printf("%lld",((val>>k)&1));
    }
    else
    {
      fprintf(stderr, "%lld", ((val>>k)&1));
    }    
  }
  
  if( verbose )
  {
    printf("\n");
  }
  else
  {
    fprintf(stderr, "\n");
  }
}

typedef struct SegmentTree 
{
  int n;
  lli* node;
  lli id0;
} SegmentTree;

SegmentTree* createSegmentTree(int* v, int size, lli id3)
{
  SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
  st->n = 1;
  while(st->n < size)
  {
    st->n <<= 1;
  }
  
  st->node = (lli*)malloc((2*st->n-1) * sizeof(lli));
  st->id0 = id3;

  for( int i = 0 ; i < size ; ++ i )
  {
    st->node[i+st->n-1] = v[i];
  }
    
  for( int i = st->n-2 ; i >= 0 ; -- i )
  {
    st->node[i] = (st->node[2*i+1] < st->node[2*i+2]) ? st->node[2*i+1] : st->node[2*i+2];
  } 

  return st;
}

void update(SegmentTree* st, int x, lli val)
{
  x += (st->n - 1);
  st->node[x] = val;
    
  while( x > 0 )
  {
    x = (x - 1) / 2;
    st->node[x] = (st->node[2*x+1] < st->node[2*x+2]) ? st->node[2*x+1] : st->node[2*x+2];
  }
}

lli getmin(SegmentTree* st, int a, int b, int k, int l, int r)
{
  if( r < 0 )
  {
    r = st->n;
  } 
  if( r <= a || b <= l )
  {
    return st->id0;
  } 
  if( a <= l && r <= b )
  {
    return st->node[k];
  }
    
  lli vl = getmin(st, a, b, 2*k+1, l, (l+r)/2);
  lli vr = getmin(st, a, b, 2*k+2, (l+r)/2, r);
  return (vl < vr) ? vl : vr;
}

typedef struct id1 
{
  int size_;
  lli* data;
} id1;

id1* create_id1(int sz, lli id2)
{
  id1* id = (id1*)malloc(sizeof(id1));
  id->size_ = sz;
  id->data = (lli*)malloc((sz+1) * sizeof(lli));
  for(int i = 0; i <= sz; ++i)
  {
    id->data[i] = id2;
  }

  return id;
}

lli sum(id1* id, int i)
{
  if( i <= 0 )
  {
    return (lli) 0.0;
  }

  if( i > id->size_ )
  {
    i = id->size_;
  }
    
  lli sm = 0.0;
  while( i > 0 )
  {
    sm += id->data[i];
    i -= i & -i;
  }
    
  return sm;
}

void add(id1* id, int i, lli x)
{
  if( i < 0 || i >= id->size_ )
  {
    return;
  }
  ++ i;
  while( i <= id->size_ )
  {
    id->data[i] += x;
    i += i & -i;
  }
}

typedef struct RollingHash
{
  unsigned long long* hash;
  unsigned long long* base_pow;
  unsigned long long base, modulus;
  const unsigned long long id5;
  const unsigned long long MASK30;
  const unsigned long long MASK31;
  const unsigned long long BASE_MIN;
} RollingHash;

RollingHash* createRollingHash(char* S, unsigned long long base_, unsigned long long id4)
{
  RollingHash* rh = (RollingHash*)malloc(sizeof(RollingHash));
  rh->id5 = (1ULL << 61) - 1;
  rh->MASK30 = (1ULL << 30) - 1;
  rh->MASK31 = (1ULL << 31) - 1;
  rh->BASE_MIN = 1e7;

  if( 0 < id4 )
  {
    rh->modulus = id4;
  }
  else
  {
    rh->modulus = rh->id5;
  }

  if( 0 < base_ )
  {
    rh->base = base_;
  }
  else
  {
    rh->base = rh->BASE_MIN;
  }

  if( strlen(S) > 0 )
  {
    initialize(S);
  }

  return rh;
}

void initialize(RollingHash* rh, char* S)
{
  int N = strlen(S);
  int* s = (int*)malloc(N * sizeof(int));
  for(int i = 0; i < N; ++i)
  {
    s[i] = S[i];
  }
    
  initialize(rh, s);
}

void initialize(RollingHash* rh, int* S)
{
  int N = strlen(S);
  rh->hash = (unsigned long long*)malloc((N+1) * sizeof(unsigned long long));
  rh->base_pow = (unsigned long long*)malloc((N+1) * sizeof(unsigned long long));
  rh->hash[0] = 0;
  rh->base_pow[0] = 1;

  if( rh->modulus == rh->id5 )
  {	
    for(int i = 1; i <= N; ++i)
    {
      rh->hash[i] = Modulus_2pow61m1( Multiple_2pow61m1(rh->hash[i-1],rh->base) + S[i-1] );
      rh->base_pow[i] = Multiple_2pow61m1(rh->base_pow[i-1],rh->base);
    }
  }
  else
  {
    for(int i = 1; i <= N; ++i)
    {
      rh->hash[i] = ( rh->hash[i-1] * rh->base + S[i-1] ) % rh->modulus;
      rh->base_pow[i] = ( rh->base_pow[i-1] * rh->base ) % rh->modulus;
    }
  }
}

unsigned long long between(RollingHash* rh, int a, int b)
{
  if( rh->modulus == rh->id5 )
  {
    return Modulus_2pow61m1( rh->modulus + rh->hash[b] - Multiple_2pow61m1(rh->hash[a],rh->base_pow[b-a]) );
  }
    
  return ( rh->modulus + rh->hash[b] - ( rh->hash[a] * rh->base_pow[b-a] ) % rh->modulus ) % rh->modulus;
}

int N;
lli* a;
lli* b;

int main()
{
  scanf("%d", &N);
  a = (lli*)malloc(N * sizeof(lli));
  int* mp = (int*)calloc(N, sizeof(int));
  for(int i = 0; i < N; ++i)
  {
    scanf("%lld", &a[i]);
    ++ mp[a[i]];
  }
  b = (lli*)malloc(N * sizeof(lli));
  for(int i = 0; i < N; ++i)
  {
    scanf("%lld", &b[i]);
  }

  lli* vs = (lli*)malloc(N * sizeof(lli));
  int vs_size = 0;
  for( int i = 0 ; i < N ; ++ i )
  {
    if( mp[a[i]] > 1 )
    {
      vs[vs_size++] = a[i];
    }
  }

  lli ans = 0;
  for(int i = 0; i < N; ++i)
  {
    bool isok = false;
    for( int j = 0 ; j < vs_size ; ++ j )
    {
      if( ( vs[j] & a[i] ) == a[i] )
      {
        isok = true;
        break;
      }
    }

    if( isok )
    {
      ans += b[i];
    }
  }

  printf("%lld\n", ans);

  free(a);
  free(b);
  free(mp);
  free(vs);

  return 0;
}
