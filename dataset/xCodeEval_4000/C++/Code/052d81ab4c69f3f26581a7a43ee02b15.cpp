


#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstring>
#include <list>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
#define MOD 1000000007


#define NL printf("\n");    

#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORl(i, n) for(ll i = 0; i < n; i++)
#define FoR(i, a, b) for (int i=a; i<(b); i++)
#define FoRl(i, a, b) for (ll i=a; i<(b); i++)
typedef vector<int> vi;
typedef vector<ll> vl;

void printVec(vector<int> A){
    FOR(i,A.size()) printf("%d ",A[i]);
    NL;
}
void printVecLL(vector<ll> A){
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
