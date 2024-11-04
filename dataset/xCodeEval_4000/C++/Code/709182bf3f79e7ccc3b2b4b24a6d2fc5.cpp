














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

# include <string>



















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


# define fi  first
# define se  second


# define x  X
# define y  Y
# define x1 X1
# define y1 Y1
# define x2 X2
# define y2 Y2


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












const int N = 200104;
const int K = 21;


const int INF = 2000000000;






int n, m, k, l, x, y;
bool ok;


map <string, int> M;
pair <string, int> p;
pair <int, string> pp [N];


void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();
int Find (char * s);

__int64 Code (char * pname)
{
   __int64 k=0;
   int i;
   for ( i=0; pname [i]; i++ )
      k = k*27 + pname [i] - 'a' + 1;
   for ( ; i < 10; i++ )
      k = k*27;
   return k;
}

void DeCode (__int64 k, char * pname)
{
   int i, m;
   for ( i=9; i >= 0; i-- )
   {
      m = k % 27;
      if ( m > 0 )
  		   pname [i] = m + 'a' - 1;
	   else
 		   pname [i] = 0;
	   k /= 27;
   }
}


int main ()
{
# ifndef ONLINE_JUDGE
   freopen ("B.TXT", "r", stdin);
   freopen ("B.OUT", "w", stdout);
# endif


# ifndef ONLINE_JUDGE
   int nnn;
   scanf ("%d\n", &nnn);
   for ( int iii=1; iii <= nnn; iii++ )
   {
      ok = false;



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


}

void Main ()
{



   map <string, int>::iterator it;
   char name [11];
   int ii=0;

   for ( it=M.begin (); it != M.end (); it++, ii++ )
   {
      pp [ii].fi = -it->se;
      pp [ii].se = it->fi;
# ifndef ONLINE_JUDGE




# endif
   }

   sort (pp, pp+m);

   for ( int i=0; i < m; i++ )
   {


# ifndef ONLINE_JUDGE


# endif




      cout << pp [i].se << endl;
   }

# ifndef ONLINE_JUDGE


# endif
}

void Input ()
{





   map <string, int>::iterator it;
   char name [11];

   scanf ("%d\n", &n);
   for ( int i=0; i < n; i++ )
   {


      cin >> name;
      p.fi = name;     

      p.se = i;
      it = M.find (p.fi);
      if ( it == M.end () )
      {
         M.insert (p);
         m++;
      }
      else
      {
		 	it->se = i;
		}

# ifndef ONLINE_JUDGE




# endif
   }

# ifndef ONLINE_JUDGE
   PrintData ();
# endif
}

void Output ()
{






}



void PrintData (int par)
{
   if ( par == 0 )
   {












   }
   else
   {


   }


}


