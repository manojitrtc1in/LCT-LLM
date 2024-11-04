


































































































































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

   freopen ("C.TXT", "r", stdin);
   freopen ("C.OUT", "w", stdout);




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
   p [0] = 1;
   for ( int i=1; i < N; i++ )
      p [i] = (2 * p [i-1]) % M;







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








   PrintData ();

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


