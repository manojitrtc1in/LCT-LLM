
 

 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
 


























 
inline string id0(LL a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}
 
inline LL id1(string a)
{
    char x[100];
    LL res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}
 
inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}
 
inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';
    return s;
}
 
inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    return s;
}
 
void solve() {
    int n;
    scanf("%i", &n);
    int a[n];
    int counter[n + 1];
    for(int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
        counter[a[i]]++;
    }
    int meh = 0, meh_update = 0;
    vi way;
    int ans = 0;
    int id2 = 0;
    bool z[n + 2];
    int anss[n + 1];
    while(meh_update < n) {
        memset(z, 0, sizeof(z));
        for(int i = meh_update; i < n; i++) {
            z[a[i]] = true;
            if(a[i] == meh){
                meh_update = i;
                for(int h = meh; z[h]; h++) {
                    meh = h + 1;
                }
                if(!counter[meh]) break;
            }
        }
        anss[ans] = meh;
        meh_update++;
        meh = 0;
        ans++;
    }
    printf("%i\n", ans);
    for(int i = 0; i < ans; i++) {
        printf("%i ", anss[i]);
    }
    printf("\n");
}
 
int main()
{
    int k;
    scanf("%i", &k);
    while(k--) {
        solve();
    }
    return 0;
}