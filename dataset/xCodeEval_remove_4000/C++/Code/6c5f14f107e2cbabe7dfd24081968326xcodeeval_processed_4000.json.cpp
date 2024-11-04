















































































































































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












const int N = 100040;
const int M = 100000;
const int INF = 2000000000;






int n, m, k, l, x, y, a, b;
bool ok, oka, okb;
char * alpha = "AHIOMTUVWXY";



















char s [N], si, sj;
























void PrintData (int par=0);
void Input ();
void Output ();
void Main ();
void Init ();



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
   n = 0;
   ok = true;
}

void Main ()
{
   n = strlen (s);
   for ( int i=0, j=n-1; i <= j; i++, j-- )
   {
      si = s [i], sj = s [j];
      oka = false;
      okb = false;
      for ( int l=0; alpha [l]; l++ )
         if ( si == alpha [l] )
         {
		      oka = true; break;
         }
      for ( int l=0; alpha [l]; l++ )
         if ( sj == alpha [l] )
         {
		      okb = true; break;
         }
      
      if ( ! oka || ! okb || si != sj )
      {
         ok = false;
         break;
      }
   }


   PrintData (1);

}

void Input ()
{


























   scanf ("%s\n", s);









   PrintData ();

}

void Output ()
{










   if ( ok )
      printf ("YES");
   else
      printf ("NO");
}

void PrintData (int par)
{
   if ( par == 0 )
   {







      printf ("<%s>\n", s);



   }
   else
   {


   }
   printf ("\n");
}


