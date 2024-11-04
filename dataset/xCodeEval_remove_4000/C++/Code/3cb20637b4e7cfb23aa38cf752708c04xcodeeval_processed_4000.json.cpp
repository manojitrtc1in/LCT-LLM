

using namespace std;



int dp[1000010] , to[1000100] , n , m ;

int location(char dir , int x , int y){

    if(dir == 'L'){
        return (x - 1) * m + (y - 1) ;
    }
    else if(dir == 'R'){
        return (x - 1) * m + (y + 1) ;
    }
    else if(dir == 'U'){
        return (x - 2) * m + y ;
    }
    else {
        return x * m + y ;
    }
}
int main(){

    int t; cin >> t ;

    while(t--){
        cin >> n >> m ;
        vector< vector<char > > colors ;

        for(int i = 0 ; i <= n ; i++){
            vector<char> x;
            for(int j = 0 ; j <= m ; j++){
                x.push_back('0') ;
            }
            colors.push_back(x) ;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                cin >> colors[i][j] ;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                char x ; cin >> x ;
                to[(i - 1) * m + j] = location(x , i , j);
            }
        }

        for(int depth = 1 ; depth <= 30 ; depth++){

            for(int i = 1 ; i <= n * m ; i++){
                dp[i] = to[to[i]] ;
            }
            for(int i = 1 ; i <= n * m ; i++){
                to[i] = dp[i] ;
            }
        }

        map<int , int> mp , black ;

        int ans  = 0 ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                mp[dp[(i - 1) * m + j]] += 1 ;
                black[dp[(i - 1) * m + j]] += (colors[i][j] == '0');
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(black[(i - 1) * m + j] > 0){
                    ans += 1 ;
                }
            }
        }

        cout << mp.size() << " " << ans << endl ;
    }
}























