



























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

















int r=0,n,w,h;
vector<pair<pii,int> > v;
int dp[5002];
int pre[5002];
int solve(int i)
{
    int &ret = dp[i];
    if(ret!=-1)  return ret;
    ret=1;
    REP(j,n+1){
        if(v[j].st.st>v[i].st.st&&v[j].st.nd>v[i].st.nd){
            if(ret<1+solve(j)){
                ret=1+solve(j);
                pre[i]=v[j].nd;
            }
        }
    }
    return ret;
}
void prin(int d){
    if(d==-1) return;
    prin(pre[d]);
    cout<<v[d].nd<<" ";
}
int main()
{ 
    int a,b;
    
    cin>>n;
    v.resize(n+1);
    REP(i,n+1) {
        cin>>v[i].st.st>>v[i].st.nd;
        v[i].nd=i;
    }
    clr(dp,-1);
    clr(pre,-1);
    cout<<solve(0)-1<<endl;
    

    for (int i = pre[0]; i != -1; i = pre[i])
        cout<<i<<" ";
    
    return 0;
}


