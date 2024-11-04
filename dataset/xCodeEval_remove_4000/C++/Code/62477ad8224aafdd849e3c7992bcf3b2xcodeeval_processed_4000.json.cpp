

using namespace std;

const int N = 105;
int t, n, m;
char b[N][N];
int a[N][N];
vector< pair<int, int> > op;
int main(){
    cin>>t;
    while(t--){
        cin >> n >> m;
        op.clear();
        int anss = 0;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                cin >> b[i][j];
                if(b[i][j]=='1'){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < n - 2;i++){
            for (int j = 0; j < m - 1;j++){
                if(a[i][j]==1){
                    op.push_back({i + 1, j + 1});
                    op.push_back({i + 1+1, j + 1});
                    op.push_back({i + 1, j + 1+1});
                    a[i][j] = -a[i][j];
                    a[i][j+1] = -a[i][j+1];
                    a[i+1][j] = -a[i+1][j];
                    anss++;
                }
            }
            if(a[i][m-1]==1){
                op.push_back({i + 1, m-1 + 1});
                op.push_back({i + 1+1, m-1 + 1});
                op.push_back({i + 1+1, m-1 -1+1});
                a[i][m-1] = -a[i][m-1];
                a[i+1][m-1] = -a[i+1][m-1];
                a[i+1][m-1-1] = -a[i+1][m-1-1];
                anss++;
            }
        }
        for (int j = 0; j < m - 2;j++){
            if(a[n-2][j]==1){
                op.push_back({n - 2 + 1, j + 1});
                op.push_back({n - 2 + 1+1, j + 1});
                op.push_back({n - 2 + 1, j + 1+1});
                anss++;
                a[n - 2][j] = -a[n - 2][j];
                a[n - 2+1][j] = -a[n - 2+1][j];
                a[n - 2][j+1] = -a[n - 2][j+1];
            }
            if(a[n-1][j]==1){
                op.push_back({n - 1 + 1, j + 1});
                op.push_back({n - 1 + 1, j + 1+1});
                op.push_back({n - 1 + 1-1, j + 1+1});
                anss++;
                a[n - 1][j] = -a[n - 1][j];
                a[n - 1][j+1] = -a[n - 1][j+1];
                a[n - 2][j+1] = -a[n - 2][j+1];
            }
        }
        if(a[n-2][m-2]==1&&a[n-1][m-2]==1&&a[n-2][m-1]==1&&a[n-1][m-1]==1){
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==1&&a[n-2][m-1]==1&&a[n-1][m-1]==1){
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==1&&a[n-1][m-2]==-1&&a[n-2][m-1]==1&&a[n-1][m-1]==1){
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==1&&a[n-1][m-2]==1&&a[n-2][m-1]==-1&&a[n-1][m-1]==1){
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==1&&a[n-1][m-2]==1&&a[n-2][m-1]==1&&a[n-1][m-1]==-1){
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==1&&a[n-1][m-2]==-1&&a[n-2][m-1]==-1&&a[n-1][m-1]==1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                    

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==1&&a[n-2][m-1]==1&&a[n-1][m-1]==-1){  

            op.push_back({n - 2 + 1, m - 2 +1});                                    

            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }

        else if(a[n-2][m-2]==1&&a[n-1][m-2]==1&&a[n-2][m-1]==-1&&a[n-1][m-1]==-1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==-1&&a[n-2][m-1]==1&&a[n-1][m-1]==1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==1&&a[n-1][m-2]==-1&&a[n-2][m-1]==1&&a[n-1][m-1]==-1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==1&&a[n-2][m-1]==-1&&a[n-1][m-1]==1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==1&&a[n-1][m-2]==-1&&a[n-2][m-1]==-1&&a[n-1][m-1]==-1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
             op.push_back({n - 2 + 1, m - 2 + 1});                                 
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==-1&&a[n-2][m-1]==1&&a[n-1][m-1]==-1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==1&&a[n-2][m-1]==-1&&a[n-1][m-1]==-1){  

            op.push_back({n - 2 + 1+1, m - 2 + 1});                               

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
           op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        else if(a[n-2][m-2]==-1&&a[n-1][m-2]==-1&&a[n-2][m-1]==-1&&a[n-1][m-1]==1){  

            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1});                                 

            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
            op.push_back({n - 2 + 1, m - 2 + 1+1});
            op.push_back({n - 2 + 1+1, m - 2 + 1});
            op.push_back({n - 2 + 1+1, m - 2 + 1+1});
            anss++;
        }
        cout << anss << endl;
        int cnt = 0;
        for (int i = 0; i < op.size();i++){
            cout << op[i].first << ' '<< op[i].second<<' ';
            cnt++;
            if(cnt==3){
                cout << endl;
                cnt = 0;
            }
        }
            
    }
    return 0;
}