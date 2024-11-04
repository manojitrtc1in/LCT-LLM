










































































































































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
   alpha = PI / n;
   s = n * r * r * sin (alpha/2.0) * sin (alpha) / sin (alpha*1.5);



   PrintData ();

}

void Input ()
{



   scanf ("%d %lf", &n, &r);







































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


