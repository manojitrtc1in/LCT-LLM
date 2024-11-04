














































































































































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












const int N = 200104;
const int K = 4;
const int M = 100000;
const int INF = 2000000000;






int n, m, k, l, x, y;
bool ok;




int a, b;

bool dir [K];
char s [N];














































void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();
int Find (char * s);
void Clear ()
{
   for ( int i=0; i < K; i++ )
      dir [i] = false;
}




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

   Clear ();


}

void Main ()
{
   for ( int i=0; i < n; i++ )
      switch ( s [i] )
      {
      case 'R' :
            if ( dir [2] )
            {
               k++;
               Clear ();
            }
            dir [0] = true;
            break;
      case 'D' :
            if ( dir [3] )
            {
               k++;
               Clear ();
            }
            dir [1] = true;
            break;
      case 'L' :
            if ( dir [0] )
            {
               k++;
               Clear ();
            }
            dir [2] = true;
            break;
      case 'U' :
            if ( dir [1] )
            {
               k++;
               Clear ();
            }
            dir [3] = true;
            break;
      }

   k++;


   PrintData (1);

}

void Input ()
{



   scanf ("%d\n%s", &n, s);




































   PrintData ();

}

void Output ()
{












   printf ("%d\n", k);




}



void PrintData (int par)
{
   if ( par == 0 )
   {
      printf ("n=%d\n<%s>", n, s);










   }
   else
   {


   }
   printf ("\n");
}


