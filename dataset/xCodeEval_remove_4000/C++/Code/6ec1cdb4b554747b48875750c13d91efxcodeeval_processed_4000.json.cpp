






























































































using namespace std;













































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












const int N = 1040;
const int M = 100000;
const int INF = 2000000000;






int n, m, k, l, a, b;
bool ok;
int c [N];
















char s [N][N];



__int64 d;



















void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();



int main ()
{

   freopen ("B.TXT", "r", stdin);
   freopen ("B.OUT", "w", stdout);



   int nnn;
   scanf ("%d\n", &nnn);
   for ( int iii=1; iii <= nnn; iii++ )
   {
      ok = false;






      printf ("\n\n\nSAMPLE %d\n", iii);















      Init ();


      Input ();

      Main ();

      Output ();


   }


   return 0;
}

void Init ()
{
   n = 0, k = 0;
   a = 0, b = 0;
   l = 0;
   d = 0;
}

void Main ()
{
   if ( ! ok )
   {
      m = -1;
      return;
   }

   sort (c, c+k);

   m = 1;
   for ( int i=1; i < k; i++ )
      if ( c [i-1] < c [i] )
         m++;


   PrintData (1);

}

void Input ()
{































   char * p;
   ok = true;
   scanf ("%d %d\n", &n, &m);
   for ( int i=0, l; i < n; i++ )
   {
      p = s [i]; l = -1;
      scanf ("%s\n", p);
      for ( int j=0; j < m; j++ )
         if ( p [j] == 'S' )
            {
               if ( l > -1 )
                  c [k++] = j-l;
               else
                  ok = false;
               break;
            }
         else if ( p [j] == 'G' )
            l = j;
   }






   PrintData ();

}

void Output ()
{











   printf ("%d", m);
}

void PrintData (int par)
{
   if ( par == 0 )
   {
      printf ("n=%d m=%d\n", n, m);










      for ( int i=0; i < n; i++ )
         printf ("%s\n", s [i]);



   }
   else
   {
      printf ("k=%d <<", k);
      for ( int i=0; i < k; i++ )
         printf (" %d", c [i]);
   }
   printf ("\n");
}


