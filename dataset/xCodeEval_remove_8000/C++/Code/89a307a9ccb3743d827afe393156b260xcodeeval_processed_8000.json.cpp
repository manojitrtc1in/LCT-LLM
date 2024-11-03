




















































using namespace std;

template<class A, class B, class C> struct Triple { A first; B second; C third;
    bool operator<(const Triple& t) const { if (fi != t.fi) return fi < fi.st; if (se != t.se) return se < t.se; return th < t.th; } };


int gcd(int a,int b){
    while (a && b)
        if (a>b) a=a%b; else b=b%a;
    return a+b;
}

int bp(int a,int b,int &md){
    int res=1;
    while (b) {
        if (b&1) res*=a;
        a*=a;
        a%=md;
        res%=md;
        b>>=1;
    }
    return res;
}

vector <int> z_function(string &s){
    int n=sz(s);
    vector <int> ans(n,0);
    int l=0,r=0;
    for (int i=1; i<n; ++i){
        ans[i]=min(r-i+1,ans[i-l]);
        while (ans[i]+i<n && s[ans[i]]==s[i+ans[i]]){
            ++ans[i];
        }
        if (i+ans[i]-1>r){
            l=i,r=i+ans[i]-1;
        }
        r=max(r,i);
    }
    return ans;
}


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef Triple<int, int, int> tiii;


const ld EPS=0.000000001;
const ld id0=1000000000;
const ll INF64=1000000000000000000;
const ll INF32=1000000000;
const ll one=1;



vi G[maxN];

map<string,vi>MP;

string arr[maxN][3];

int iss[maxN];

vector<int> VEC;

int k;

bool bl[maxN];

void dfs(int v,string fr){
    if (v==k){
        VEC.push_back(v);
        for (int i:G[v]){
            dfs (i, arr[v][iss[v]]);
        }
    }else{
        if (iss[v]) return;
        VEC.push_back(v);
        if (fr==arr[v][1])
            iss[v]=2;
        else
            iss[v]=1;
        for (int i:G[v]){
            dfs (i, arr[v][iss[v]]);
        }
    }
}

bool ch(vi &V){
    for (int i:V){
        for (int j:V){
            if (i==j) continue;
            if (arr[i][iss[i]]==arr[j][iss[j]]) return 0;
        }
    }
    return 1;
}

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i){
        string s,t;
        cin>>s>>t;
        string S,T;
        S.clear(),T.clear();
        S.push_back(s[0]);S.push_back(s[1]);S.push_back(t[0]);
        T.push_back(s[0]);T.push_back(s[1]);T.push_back(s[2]);
        
        

        

        arr[i][1]=S;
        arr[i][2]=T;
        

        if (S==T){
            for (int j:MP[S]){
                G[i].push_back(j);
                G[j].push_back(i);
            }
            MP[S].push_back(i);
        }else{
            for (int j:MP[S]){
                G[i].push_back(j);
                G[j].push_back(i);
            }
            MP[S].push_back(i);
            for (int j:MP[T]){
                G[i].push_back(j);
                G[j].push_back(i);
            }
            MP[T].push_back(i);
        }
    }
    
    set<int> SET;
    
    for (int i=1; i<=n; ++i){
        for (int j=i+1; j<=n; ++j){
            if (arr[i][1]==arr[j][1]){
                bl[i]=1;
                bl[j]=1;
                iss[i]=2;
                iss[j]=2;
                SET.insert(i);
                SET.insert(j);
            }
        }
    }
    
    for (int i:SET){
        k=i;
        if (!iss[i]){
            VEC.clear();
            iss[i]=1;
            dfs(i, arr[i][iss[i]]);
            if (ch(VEC)) continue;
            else{
                cout<<"NO"<<en;
                return 0;
            }
        }
    }
    
    for (int i=1; i<=n; ++i){
        k=i;
        if (!iss[i]){
            VEC.clear();
            iss[i]=1;
            dfs(i, arr[i][iss[i]]);
            if (ch(VEC)) continue;
            else{
                for (int j:VEC) if (!bl[j]) iss[j]=0;
                iss[i]=2;
                VEC.clear();
                dfs(i, arr[i][iss[i]]);
            }
        }
    }
    VEC.clear();
    for (int i=1; i<=n; ++i)
        VEC.push_back(i);
    if (ch(VEC)){
        cout<<"YES"<<en;
        for (int i=1; i<=n; ++i)
            cout<<arr[i][iss[i]]<<en;
        return 0;
    }
    cout<<"NO"<<en;
    return 0;
    
}




