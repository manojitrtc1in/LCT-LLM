



























using namespace std;

























typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef vector<vector<int> > vvi;
typedef vector<pii> vpi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<ull> vull;


template<class T> void checkmin(T &a, T b){if (b<a)a=b;}
template<class T> void checkmax(T &a, T b){if (b>a)a=b;}
template<class T> void out(T t[], int n){REP(i, n)cout<<t[i]<<" "; cout<<endl;}
template<class T> void out(vector<T> t, int n=-1){for (int i=0; i<(n==-1?t.size():n); ++i) cout<<t[i]<<" "; cout<<endl;}
inline int count_bit(int n){return (n==0)?0:1+count_bit(n&(n-1));}
inline int low_bit(int n){return (n^n-1)&n;}
inline int ctz(int n){return (n==0?0:ctz(n>>1)+1);}
int toInt(string s){int a; istringstream(s)>>a; return a;}
string toStr(int a){ostringstream os; os<<a; return os.str();}
string reverse(string& s){ int n=s.size();REP(i,n/2) s[i]=s[n-1-i];return s;}
inline int isvalid(int i,int j,int H,int L){ return (i>=H||i<0||j>=L||j<0)? 0:1;}
inline int id0(double x,double y){if(fabs(x-y)<=EPS) return 0; if(x<y) return -1; return 1;}




























int main()
{
    

    int n, m;
    cin >> n >> m;
    map<string, int> ma;
    string s;
    vi tag(n);
    REP(i, n) cin >> tag[i];
    REP(i, m){
        cin >> s;
        ma[s]++;
    }
    vi tab(ma.size());
    vi bat(ma.size());
    int j = 0;
    for (map<string, int>::iterator it = ma.begin(); it != ma.end(); it++, j++)
        tab[j] = it->second;
    sort(RALL(tab));
    sort(ALL(tag));
    ll mi = 0, mam = 0;
    FORE(i, tab){
        mi += tab[i] * tag[i];
    }
    sort(RALL(tag));
    FORE(i, tab){
        mam += tab[i] * tag[i];
    }

    cout << mi << " " << mam << endl;
    
    

    return 0;
}