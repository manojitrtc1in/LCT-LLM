
























using namespace std;



















































































































































template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;} 

inline int Qceil(int x, int y) {return x ? (x - 1) / y + 1 : 0;} 


const int inf = 0x3f3f3f3f; 

const long long llinf = 0x3f3f3f3f3f3f3f3fLL; 

const double pi = acos(-1.0);












int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}






















typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int>::iterator viter;
typedef set<int>::iterator siter; 

typedef map<int, int>::iterator miter; 

typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
typedef priority_queue<int> pqi; 

typedef priority_queue<int, vector<int>, greater<int> > spqi; 

typedef pair<int, int> p2; 

typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;













inline bool okC(char &c) {return c = getchar(), c != 10 && ~c;} 

inline bool okS(char *s) {return s = gets(s), s && *s;}




int cas;
const int mx = int(1e5) + 5;

vector<int> tmp, ans;
bool vis[mx];

int main()
{
    int n, m, i, j;
    SI(n);
    m = n >> 1;
    Forr(i, 3, m + 1)
    {
        tmp.clear();
        Forrr(j, i, n + 1, i) if (!vis[j]) tmp.PB(j);
        

        if (tmp.size() & 1)
        {
            if (tmp.size() == 1) continue;
            ans.PB(tmp[0]), ans. PB(tmp[2]), vis[tmp[0]] = vis[tmp[2]] = true;
            Forr(j, 3, tmp.size()) ans.PB(tmp[j]), vis[tmp[j]] = true;
        }
        else if (!tmp.empty())
        {
            

            For(j, tmp.size()) ans.PB(tmp[j]), vis[tmp[j]] = true;
        }
        

    }
    Forrr(i, 2, n + 1, 2) if (!vis[i]) ans.PB(i);
    PI(ans.size() >> 1);
    Forrr(i, 1, ans.size(), 2) PII(ans[i-1], ans[i]);
    return 0;
}
