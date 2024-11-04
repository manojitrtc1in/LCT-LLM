










































































































































using namespace std;













































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












const int N = 1000104;
const int K = 21;
const int M = 100000;
const int INF = 2000000000;






int n, m, k, l, x, y;
bool ok;






Pair a [N];














































void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();
int Find (char * s);




int main ()
{

   freopen ("A.TXT", "r", stdin);
   freopen ("A.OUT", "w", stdout);




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
   n = 0, m = 0, k = 0;


}

void Main ()
{
   int max = 0;
   for ( int i=1; i < N; i++ )
      if ( a [i].fi > max )
         max = a [i].fi;

   k = INF, m = INF;
   for ( int i=1; i < N; i++ )
      if ( a [i].fi == max )
         if ( a [i].se < k )
            k = a [i].se, m = i;





}

void Input ()
{



   scanf ("%d\n", &n);
   for ( int i=0; i < n; i++ )
   {
      scanf ("%d", &k);
      a [k].fi++,
      a [k].se = i;
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









      printf ("n=%d\n", n);

   }
   else
   {


   }


}


