


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;























typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;

const int maxn = int(1.5 * 1e7);
const int inf = ~0U >> 1;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

char a[128],c[128];
int b,d,t[128];
int main(){
  	scanf("%d%d" , &b , &d);
  	scanf("%s%s" , a , c);
  	int s = 0,n = strlen(c);
  	for(int i = 0;c[i];++i){
	    int &k = t[i];
	    for(int j = 0;a[j];++j)
			if(a[j] == c[(i + k) % n])
				++k;
  	}
  	for(int i = 0;i < b;++i)
		s += t[s % n];
  printf("%d\n",s / n / d);
}