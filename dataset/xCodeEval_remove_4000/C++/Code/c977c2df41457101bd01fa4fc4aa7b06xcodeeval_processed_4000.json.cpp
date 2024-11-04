




































using namespace __gnu_pbds;
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int PI = 3.1415926535897932384626433832795;
const int INF = 8000000000000000000;
const int mod = 1000000007;
const int MOD = 1000000007;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};





namespace Output
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

namespace Output1
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

using namespace Output;




bool id1(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int power(int x, int n) 
{
    int res = 1;
    
    while (n > 0) {
        
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;

    }
    
    return res;
}

int gcd(int a, int b) 
{    
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}























namespace Output2
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

namespace Output5
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}


namespace Output3
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}


namespace Output4
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

clock_t startTime;
double id0() 
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

namespace Output121312312
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

namespace Output1wqeqwesd
{
    void print(int x) {cout << x << "\n";}
    void print(unsigned int x) {cout << x << "\n";}
    void print(float x) {cout << x << "\n";}
    void print(double x) {cout << x << "\n";}
    void print(long double x) {cout << x << "\n";}
    void print(char x) {cout << x << "\n";}
    void print(char* x) {cout << x << "\n";}
    void print(unsigned char x) {cout << x << "\n";}
    void print(const char* x) {cout << x << "\n";}
    void print(string x) {cout << x << "\n";}
    void print(bool x) {cout << x << "\n";}

    template <class T, class... Ts> void print(T t, Ts... ts){
        cout << t << " ";
        print(ts...);
    }

    template <typename T1, typename T2> void print(pair <T1, T2> a) {print(a.first, a.second);}
    template <typename T> void print(T a){
        for(int it : a){
            print(it);
        }
    }

    template <class T, class... Ts> void prine(T t, Ts... ts){
        print(t, ts...);
        exit(0);
    }
}

bool compare(string a, string b)
{
    for1 (i, 0, a.size()-1)
    {
        if (a[i]-'0' < b[i]-'0') return 0;
        if (a[i]-'0' > b[i]-'0') return 1;
    }
    return 1; 

}

signed main()
{
    



    

    





    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    _input()
    {
        int n; int k; cin >> n >> k;
        string nstr = to_string(n);
        if (k == 1)
        {
            int check = 0, add = 1;
            for1 (i, 1, nstr.size())
            {
                check += (nstr[0]-'0') * add;
                add *= 10;
            }
            if (check >= n)
            {
                for1 (i, 1, nstr.size()) cout << nstr[0];
            }
            else for1 (i, 1, nstr.size()) cout << nstr[0]-'0'+1;
            cout << endl;
        }
        if (k == 2)
        {
            char nfi = nstr[0];
            while (nstr[0] == nfi) {cout << nfi; nstr.erase(nstr.begin());}
            if (nstr.empty()) {cout << endl; continue;}
            string check = nstr;
            string res = "";
            for1 (i, 0, nstr.size()-1) res += "9";

            for1 (add, 0, 9)
            {
                bool ok = 0, runbreak = 0;
                for1 (i, 0, nstr.size()-1)
                {
                    if (ok) check[i] = min(nfi-'0', add) + '0';
                    else if (nstr[i]-'0' <= min(nfi-'0', add))
                    {
                        if (nstr[i]-'0' < min(nfi-'0', add)) ok = 1;
                        check[i] = min(nfi-'0', add) + '0';
                        if (nstr[i+1]-'0' > max(nfi-'0', add) && i < nstr.size()-1 && !ok)
                        {
                            if (nfi-'0' == add) {runbreak = 1; break;}
                            check[i] = max(nfi-'0', add) + '0';
                            ok = 1;
                        }
                    }
                    else if (nstr[i]-'0' > max(nfi-'0', add)) 
                    {
                        bool runstop = 1;
                        if (nfi-'0' == add) {runbreak = 1; break;}
                        for2 (j, i-1, 0)
                        {
                            if (check[j] == min(nfi-'0', add) + '0')
                            {
                                cerr << j;
                                check[j] = max(nfi-'0', add) + '0';
                                for1 (k, j+1, nstr.size()-1) check[k] = min(nfi-'0', add) + '0';
                                runstop = 0;
                                break;
                            }
                        }
                        if (runstop) runbreak = 1; 
                        break;
                    }
                    else 
                    {
                        if (nstr[i]-'0' < max(nfi-'0', add)) ok = 1;
                        check[i] = max(nfi-'0', add) + '0';
                    }
                }
                if (runbreak) continue;
                if (compare(res, check)) res = check;
            }
            cout << res << endl;
        }

gg:     continue;
    }

    exit(0);
}