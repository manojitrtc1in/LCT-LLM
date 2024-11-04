













# include <iostream>
# include <iomanip>
# include <cmath>
# include <cstring>
# include <cstdio>
# include <cstdlib>





















































































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












const int N = 2104;
const int K = 21;
const int M = 100000;
const int INF = 2000000000;



const double PI = 3.14159265358979323846 ;

int n, m, k, l, x, y;
bool ok;
double r, s;
double alpha;





















































void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();
int Find (char * s);




int main ()
{
# ifndef ONLINE_JUDGE
   freopen ("A.TXT", "r", stdin);
   freopen ("A.OUT", "w", stdout);
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


}

void Main ()
{
   alpha = PI / n;
   s = n * r * r * sin (alpha/2.0) * sin (alpha) / sin (alpha*1.5);


# ifndef ONLINE_JUDGE
   PrintData ();
# endif
}

void Input ()
{



   scanf ("%d %lf", &n, &r);



































# ifndef ONLINE_JUDGE


# endif
}

void Output ()
{












   printf ("%0.9lf", s);




}




void PrintData (int par)
{
   if ( par == 0 )
   {









      printf ("n=%d r=%0.5lf\n", n, r);
      printf ("alpha=%0.5lf\n", alpha);


   }
   else
   {


   }


}


