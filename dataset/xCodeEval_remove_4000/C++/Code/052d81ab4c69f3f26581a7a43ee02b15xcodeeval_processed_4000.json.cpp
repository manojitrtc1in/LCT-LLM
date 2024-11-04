
















using namespace std;




















typedef vector<int> vi;
typedef vector<ll> vl;

void printVec(vector<int> A){
    FOR(i,A.size()) printf("%d ",A[i]);
    NL;
}
void id0(vector<ll> A){
    FOR(i,A.size()) printf("%lld ",A[i]);
    NL;
}

bool check(int x, int y, int ROW, int COL, vector<vector<char> >& A){
    if(x < 0 || y < 0) return false;
    if(x >= ROW || y >= COL) return false;
    if(A[x][y] == '.') return false;
    return true;
}

bool look(int x, int y, int ROW, int COL, vector<vector<char> >& A){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){

            if( (x+i) >= 0 && (x+i) < ROW && (y+j) >= 0 && (y+j) < COL){
                if(A[x+i][y+j] == '*') return true;
                

            }

        }
    }
    return false;
}


void solve(){
    ll n; cin >> n;
    ll m; cin >> m;

    vector<vector<char> > A(n,vector<char> (m));


    FOR(i,n){
        FOR(j,m){
            char c;
            cin >> c;
            

            A[i][j] = c;
        }
        

    }

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    FORl(i,n){
        FORl(j,m){

            if(check(i,j,n,m,A) && check(i-1,j,n,m,A) && check(i,j+1,n,m,A)){
                

                A[i][j] = '.';
                A[i-1][j] = '.';
                A[i][j+1] = '.';
                if(look(i,j,n,m,A) || look(i-1,j,n,m,A) || look(i,j+1,n,m,A)){
                    printf("NO\n");
                    return;
                }
                

                

                

            }
            


            else if(check(i,j,n,m,A) && check(i-1,j,n,m,A) && check(i,j-1,n,m,A)){
                A[i][j] = '.';
                A[i-1][j] = '.';
                A[i][j-1] = '.';
                if(look(i,j,n,m,A) || look(i-1,j,n,m,A) || look(i,j-1,n,m,A)){
                    printf("NO\n");
                    return;
                }
                

                

                

                

            }
            



            else if(check(i,j,n,m,A) && check(i,j-1,n,m,A) && check(i+1,j,n,m,A)){
                A[i][j] = '.';
                A[i][j-1] = '.';
                A[i+1][j] = '.';
                if(look(i,j,n,m,A) || look(i,j-1,n,m,A) || look(i+1,j,n,m,A)){
                    printf("NO\n");
                    return;
                }
                

                

                

            }
            


            else if(check(i,j,n,m,A) && check(i+1,j,n,m,A) && check(i,j+1,n,m,A)){
                A[i][j] = '.';
                A[i+1][j] = '.';
                A[i][j+1] = '.';
                if(look(i,j,n,m,A) || look(i+1,j,n,m,A) || look(i,j+1,n,m,A)){
                    printf("NO\n");
                    return;
                }
                

                

                

            }
            


            

            

            

            


        }
    }


    FOR(i,n){
        FOR(j,m){
            if(A[i][j] == '*'){
                printf("NO\n");
                return;
            }
        }
        

    }

    printf("YES\n");
}


int main(){
    

    

    int t = 1;
    si(t);
    FOR(i,t) {
        

        solve();
    }
    return 0;
}
