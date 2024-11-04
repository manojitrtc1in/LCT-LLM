













































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;

bool id1(pii a,pii b,pii c,pii point){
    int x1=a.first,x2=b.first,x3=c.first,x0=point.first;
    int y1=a.second,y2=b.second,y3=c.second,y0=point.second;
    int aa=(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int bb=(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int cc=(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if (aa==0 || bb==0 || cc==0) return 1;
    if (aa>=0 && bb>=0 && cc>=0) return 1;
    if (aa<=0 && bb<=0 && cc<=0) return 1;
    return 0;
}

bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool equal(double _1,double _2){ return (abs(_1-_2)<EPS);}
bool id2(int &__1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 1;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}

char mat[2222][2222];
vector<pii> VEC[4444];
int cnt[2222][2222];
int numb[2222][2222];int n;
char mini[2222][2222];
string ans;
vector<pii> id0;
vector<pii> vec;
bool iss[2222][2222];
string dfs(vector<pii> ANS){
    ans.clear();
    id0.clear();
    for (pii i:ANS) id0.push_back(i);mem0(iss);
    while (id0.size()){
        
        vec.clear();
        pii xx=id0.front();
        if (xx.first==n && xx.second==n){
            return ans;
        }
        char z='z';
        for (auto i:id0){
            z=min(z,mat[i.first][i.second+1]);
            z=min(z,mat[i.first+1][i.second]);
        }
        ans.push_back(z);
        for (auto i:id0){
            if  (i.first+1<=n &&  mat[i.first+1][i.second]==z &&!iss[i.first+1][i.second]){
                vec.push_back({i.first+1,i.second});
                iss[i.first+1][i.second]=1;
            }
            if (i.second+1<=n &&mat[i.first][i.second+1]==z && !iss[i.first][i.second+1]){
                iss[i.first+1][i.second]=1;
                vec.push_back({i.first,i.second+1});
                iss[i.first][i.second+1]=1;
            }
        }
        id0=vec;
    }
    return "))))";
}vector<pii> ANS;string anss; string z,s;
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int k;
    cin>>k;
    for (int i=0; i<2222; ++i)
        for (int j=0; j<2222; ++j){
            mat[i][j]='z';
        }
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            cin>>mat[j][i];
        }
    }
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            cnt[j][i]=(mat[j][i]=='a')+max(cnt[j-1][i],cnt[j][i-1]);
            numb[j][i]=max(numb[j-1][i],numb[j][i-1])+1;
            VEC[numb[j][i]].push_back({j,i});
        }
    }
    int ans=0;
    
    for (int i=1; i<=2*n-1; ++i){
        for (pii j:VEC[i]){
            if (cnt[j.first][j.second]+k>=i){
                if (ans<i){
                    ans=i;
                    ANS.clear();
                    ANS.push_back(j);
                }elif (ans==i){
                    ANS.push_back(j);
                }
            }
        }
    }
    
    for (int i=0; i<ans; ++i) anss.push_back('a');
    for (int i=ans; i<2*n-1; ++i)
        z.push_back('z');
    if (ans==0){
        anss.push_back(mat[1][1]);
        ANS.push_back({1,1});
    }
    {
        s=dfs(ANS);
        if (z>s)
            z=s;
    }
    cout<<anss<<z<<en;
}
