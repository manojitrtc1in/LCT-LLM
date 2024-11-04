



using namespace std;

typedef long long ll;


int _;

























































































































































































































































































































	

	

	

		

	



















  

  





  

  

  

    

    

    

    

  

  

    

    

    

          

    



    



    

    

    

    

  

  

  

  

  

  

  


















































































































































int n, m;
int id[75][75];
int a[6020][270];
int ans[270];
int num, k;

void solve(){
    memset(a, 0, sizeof a);
    memset(ans, 0, sizeof ans);
    memset(id, 0, sizeof id);
    num = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        id[x][y] = id[y][x] = i;
        if(w != -1){
            ++num;
            a[num][i] = 1;
            a[num][m+1] = w;

        }
    }
    for(int x = 1; x <= n; x++){
        for(int y = x + 1; y <= n; y++){
            for(int z = y + 1; z <= n; z++){
                if(id[x][y] && id[y][z] && id[x][z]){
                    

                    ++num;
                    a[num][id[x][y]] = a[num][id[x][z]] = a[num][id[y][z]] = 1;
                    a[num][m+1] = 0;
                }
            }
        }
    }
    k = 0;
    for(int i = 1; i <= m; i++){
        

        int pos = 0;

        for(int j = k + 1; j <= num; j++){
            if(a[j][i]){
                pos = j;
                break;
            }
        }
        if(!pos){
            continue;
        }
        ++k;
        swap(a[k], a[pos]);
        if(a[k][i] == 2){
            for(int j = i; j <= m + 1; j++){
                a[k][j] = (9 - a[k][j]) % 3;
            }
        }
        for(int j = 1; j <= num; j++){
            if(j != k && a[j][i]){
                int x = a[j][i];
                for(int t = i; t <= m + 1; t++){
                    a[j][t] = (a[j][t] - x * a[k][t] + 9) % 3;
                }
            }
        }
    }
    int ok = 1;
    for(int i = k + 1; i <= num; i++){
        if(a[i][m+1]){
            ok = 0;
            break;
        }
    }
    if(!ok){
        cout << "-1" << "\n";
        return ;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                ans[j] = a[i][m+1];
                break;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(ans[i]){
            cout << ans[i] << " ";
        }
        else{
            cout << "3" << " ";
        }
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> _;
    while(_--)
        solve();
    return 0;
}
