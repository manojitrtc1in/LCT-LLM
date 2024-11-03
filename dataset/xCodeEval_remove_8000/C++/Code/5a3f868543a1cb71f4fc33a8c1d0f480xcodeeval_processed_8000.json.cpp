












using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;











inline ll binpow(ll x, ll n){ ll res = 1; while (n){ if (n & 1)res *= x; x *= x; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(int a, int b){ return a / gcd(a, b)*(ll)b; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
inline ll lcm(ll a, ll b, ll c){ return lcm(lcm(a, b), c); }
inline ll lcm(int a, int b, int c){ return lcm(lcm(a, b), (ll)c); }

struct sort_pred {
    bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right) {
        return left.second < right.second;
    }
};












int n; int b[301]; char c[350]; int s[350];
int main()
{
    cin >> n;
    b[0] = 0; 
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < 350; i++)
        c[i] = '0';
    for (int i = 1; i <= n; i++)
    {
        int d = b[i] - b[i - 1];
        if (d>0)
        {
            int idx = 0;
            while (d)
            {
                if (c[idx] == '9')
                {
                    idx++;
                }
                else
                {
                    c[idx]++;
                    d--;
                }
            }
            s[i] = max(idx,s[i-1]);
            for (int j = s[i]; j >= 0; j--)
                printf("%c", c[j]);
            printf("\n");
        }
        else if (d <= 0)
        {
            int right = 0;
            for (int j = 0; j <= s[i-1]; j++)
            {
                right += (c[j] - '0');
                if (right >=( -d+1) && c[j+1]!='9')
                {
                    c[j + 1]++;
                    s[i] = max(s[i - 1], j + 1);
                    for (int k = 0; k <= j; k++)
                    {
                        c[k] = '0';
                    }
                    int idx = 0;
                    right = right - 1 +d ;
                    while (right)
                    {
                        if (c[idx] == '9')
                        {
                            idx++;
                        }
                        else
                        {
                            c[idx]++;
                            right--;
                        }
                    }
                    for (int k = s[i]; k >= 0; k--)
                    {
                        printf("%c", c[k]);
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}






















































































  