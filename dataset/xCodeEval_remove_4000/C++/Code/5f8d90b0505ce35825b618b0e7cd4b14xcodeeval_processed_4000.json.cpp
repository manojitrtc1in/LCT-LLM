























using namespace std;






















































































































































template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;} 

inline int Qceil(int x, int y) {return x ? (x - 1) / y + 1 : 0;} 


const int inf = 0x3f3f3f3f; 

const long long llinf = 0x3f3f3f3f3f3f3f3fLL; 

const double pi = acos(-1.0);















































typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p2;
typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;
typedef vector<int>::iterator viter;
typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vector<int>, greater<int> > spqi; 













const double eps = 1e-8;












inline int isSQ(int n) {int tmp = Sqrt(n); return sq(tmp) == n ? tmp : 0;}
inline bool isint(double x) {return fabs(x - round(x)) < eps;}








int cas;
const int mx = int(1e5) + 5;

double k;

inline bool test(int i, int j)
{
    if (!isint(k * i) || !isint(k * j)) return false;
    return (int)round(k * i) != j;
}

int main()
{
    int a, b, i, j;
    SII(a, b);
    if (a > b) swap(a, b);
    k = (double)b / a;
    Forr(i, 1, a)
    {
        j = sq(a) - sq(i);
        if ((j = isSQ(j)) && test(i, j))
        {
            puts("YES");
            PII(0, 0);
            PII(i, j);
            PII(-(int)round(k * j), (int)round(k * i));
            return 0;
        }
    }
    puts("NO");
    return 0;
}
