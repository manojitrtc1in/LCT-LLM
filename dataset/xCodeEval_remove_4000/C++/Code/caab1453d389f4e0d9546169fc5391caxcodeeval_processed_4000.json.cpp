












































typedef unsigned long long ull;
typedef long long ll;
using namespace std;
bitset<1010> arr[1010];
bitset<1010> iss[1010];
vector<pair <pair<int,int>,int> > VEC;
int n,m;
void f(int x,int y){
    int MIN=min(min(n-x,x-1),min(m-y,y-1));
    int i;
    int yup=y,id0=y,xleft=x,xright=x;
    for (i=0; i<=MIN; ++i){
        yup++,id0--,xright++,xleft--;
        if (arr[xright][y] && arr[xleft][y] && arr[x][yup] && arr[x][id0]){
            iss[xright][y]=1, iss[xleft][y]=1 , iss[x][yup]=1, iss[x][id0]=1;
        }else{
            if (i>0){
                iss[x][y]=1;
                VEC.push_back({{x,y},i});
            }
            return;
        }
    }
    
}
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    char ch;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j){
            cin>>ch;
            if (ch=='*')
                arr[i][j]=1;
        }
    for (int i=2; i<n; ++i){
        for (int j=2; j<m; ++j){
            if (arr[i][j]){
                f(i,j);
            }
        }
    }
    
    for (int i=1;i<=n; ++i)
        for (int j=1; j<=m; ++j){
            if (arr[i][j] && iss[i][j]==0){
                cout<<-1<<en;
                return 0;
            }
        }
    cout<<VEC.size()<<en;
    for (auto i:VEC){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<en;
    }
    return 0;
}
