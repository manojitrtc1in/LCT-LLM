








# include <stdio.h>
# include <math.h>
# include <string.h>
# include <memory.h>

# include <iostream>
# include <iomanip>
# include <cmath>
# include <cstring>
# include <cstdio>
# include <cstdlib>


















# include <map>



























































# include <vector>





























# include <algorithm>


using namespace std;



# define iabs(x) ( (x) < 0 ? (-(x)) : (x) )
# define imax(x,y) ( (x) < (y) ? (y) : (x) )
# define imin(x,y) ( (x) > (y) ? (y) : (x) )
# define sqr(x) ((x)*(x))

# define isalpha(c) ( (c) >= 'a' && (c) <= 'z' )
# define isAlpha(c) ( (c) >= 'A' && (c) <= 'Z' )

# define isdigit(c) ( (c) >= '0' && (c) <= '9' )
# define digit(c) ( (c) - '0' )

# define alpha(c) ( isalpha (c) ? (c) : ( isAlpha (c) ? (c) - 'A' + 'a' : (c) ) )
# define Alpha(c) ( isAlpha (c) ? (c) : ( isalpha (c) ? (c) - 'a' + 'A' : (c) ) )






# define NUM(r,c) ( ((r) << 8) + (c) )
# define ROW(n) ( (n) >> 8 )
# define COL(n) ( (n) & 0XFF )

# define CHECK(r,c) ( (r) >= 0 && (r) < n && (c) >= 0 && (c) < m )


# define between(a,b,c) ( (a) > (b) && (a) < (c) )
# define Between(a,b,c) ( (a) >= (b) && (a) <= (c) )


# define x  X
# define y  Y
# define x1 X1
# define y1 Y1
# define x2 X2
# define y2 Y2

# define fi first
# define se second


typedef pair <int, int>          Pair;
typedef long long int            Long;
typedef unsigned int             uint;
typedef unsigned long long int   ULong;
typedef unsigned char            uchar;






struct Point
{

   double x, y;
   void Input () { scanf ("%lf %lf", &x, &y); }
   void Print () { printf ("x=%10.3lf y=%10.3lf\n", x, y); }
   double Dist (Point p) { return sqrt (sqr (x-p.x) + sqr (y-p.y)); }
};

struct Line
{

   double A, B, C;
   void Create (Point a, Point b) { A = b.y - a.y, B = a.x - b.x, C = -A*a.x - B*a.y; }
   double Dist (Point p) { return fabs ((A*p.x+B*p.y+C)/sqrt (A*A + B*B)); }
   void Print () { printf ("A=%10.3lf B=%10.3lf C=%10.3lf\n", A, B, C); }
};












const int N = 302104;
const int K = 256;
const int M = 1000000007;
const int INF = 2000000000;






int n, k, l;
bool ok;
__int64 m;




__int64 x [N];
__int64 p [N];















































void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();
int Find (char * s);




int main ()
{
# ifndef ONLINE_JUDGE
   freopen ("C.TXT", "r", stdin);
   freopen ("C.OUT", "w", stdout);
# endif


# ifndef ONLINE_JUDGE
   int nnn;
   scanf ("%d\n", &nnn);
   for ( int iii=1; iii <= nnn; iii++ )
   {
      ok = false;








      printf ("\n\n\nSAMPLE %d\n", iii);
# endif














      Init ();


      Input ();

      Main ();

      Output ();

# ifndef ONLINE_JUDGE
   }
# endif

   return 0;
}

void Init ()
{
   n = 0, m = 0, k = 0;
   p [0] = 1;
   for ( int i=1; i < N; i++ )
      p [i] = (2 * p [i-1]) % M;



# ifndef ONLINE_JUDGE


# endif
}

void Main ()   

{
   sort (x, x+n);

   for ( int i=0, j=n-1; i < n; i++, j-- )
   {


      m = (m + x [i] * ((p [i] - p [n - i - 1] + M) % M) ) % M;


   }
}

void Input ()
{



   scanf ("%d", &n);



























   for ( int i=0; i < n; i++ )
   {
      scanf ("%I64d", & x [i]);
   }







# ifndef ONLINE_JUDGE
   PrintData ();
# endif
}

void Output ()
{












   printf ("%I64d", m);




}



void PrintData (int par)
{
   if ( par == 0 )
   {














   }
   else
   {
      for ( int i=0; i < 20; i++ )
         printf ("%d ", p [i]);


   }
   printf ("\n");
}


