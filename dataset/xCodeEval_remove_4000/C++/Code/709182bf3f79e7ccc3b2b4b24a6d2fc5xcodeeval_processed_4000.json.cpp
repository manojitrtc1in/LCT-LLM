














































































































































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

   freopen ("B.TXT", "r", stdin);
   freopen ("B.OUT", "w", stdout);




   int nnn;
   scanf ("%d\n", &nnn);
   for ( int iii=1; iii <= nnn; iii++ )
   {
      ok = false;


















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



   map <string, int>::iterator it;
   char name [11];
   int ii=0;

   for ( it=M.begin (); it != M.end (); it++, ii++ )
   {
      pp [ii].fi = -it->se;
      pp [ii].se = it->fi;






   }

   sort (pp, pp+m);

   for ( int i=0; i < m; i++ )
   {










      cout << pp [i].se << endl;
   }





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







   }


   PrintData ();

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


