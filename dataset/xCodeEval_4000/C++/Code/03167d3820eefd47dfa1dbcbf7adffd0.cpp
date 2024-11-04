#pragma GCC optimize("-Ofast","-funroll-all-loops")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lson rt << 1
#define rson rt << 1 | 1
int _;

























































































































































































































































































































	

	

	

		

	



















  

  





  

  

  

    

    

    

    

  

  

    

    

    

          

    



    



    

    

    

    

  

  

  

  

  

  

  


















































































































































const int mod = 998244353;
const int M = 2000;
const int N = 2000;
int pp2[M * N + 10];

void init(){
    pp2[0] = 1;
    for(int i = 1; i <= M * N + 1; i++){
        pp2[i] = 1ll * pp2[i-1] * 2 % mod;
    }
}

int f[M * N + 10];
int sz[M * N + 10];
int rc[N * M + 10];

int find(int x){
    return f[x] < 0 ? x : (f[x] = find(f[x]));
}

void join(int i, int j){
    i = find(i);
    j = find(j);
    if(i == j){
        return ;
    }
    f[i] = j;
}


int n, m;
char s[N+10][M+10];
int rr[N+10], cc[N+10];

void solve(){
    int k, k_, r, c;
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == '1'){
                rr[i] ^= 1;
                cc[j] ^= 1;
            }
        }
    }    

    if(n % 2 == 0 && m % 2 == 0){
        k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i][j] == '?'){
                    k++;
                }
            }
        }
        cout << pp2[k] << "\n";
    }
    else if(n % 2 == 0){
        r = -1, k_ = 0;
        for(int i = 0; i < n; i++){
            k = 0;
            for(int j = 0; j < m; j++){
                if(s[i][j] == '?')
                    k++;
            }
            if(k > 0){
                k_ += k - 1;
            }
            else{
                if(r == -1){
                    r = rr[i];
                }
                else if(r != rr[i]){
                    cout << "0" << "\n";
                    return ;
                }
            }
        }
        if(r == -1){
            k_++;
        }
        cout << pp2[k_] << "\n";
    }
    else if(m % 2 == 0){
        c = -1, k_ = 0;
        for(int j = 0; j < m; j++){
            k = 0;
            for(int i = 0; i < n; i++){
                if(s[i][j] == '?'){
                    k++;
                }
            }
            if(k > 0){
                k_ += k - 1;
            }
            else{
                if(c == -1){
                    c = cc[j];
                }
                else{
                    if(c != cc[j]){
                        cout << "0" << "\n";
                        return ;
                    }
                }
            }
        }
        if(c == -1){
            k_++;
        }
        cout << pp2[k_] << "\n";
    }
    else{
        for(int i = 0; i < n*m; i++){
            f[i] = -1;
        }
        k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i][j] == '?'){
                    k++;
                    join(i, n + j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            int u = find(i);
            sz[u]++;
            rc[u] ^= rr[i];
        }
        for(int j = 0; j < m; j++){
            int u = find(n + j);
            sz[u]++;
            rc[u] ^= cc[j];
        }

        k_ = k, r = -1;
        for(int u = 0; u < n + m; u++){
            if(f[u] < 0){
                

                

                k_ -= sz[u] - 1;
                

                if(sz[u] % 2 == 0){
                    if(rc[u]){
                        cout << "0" << "\n";
                        return ;
                    }
                }
                else{
                        if(r == -1){
                            r = rc[u];
                        }
                        else if(r != rc[u]){
                            cout << "0" << "\n";
                            return ;
                        }
                    }
            }
        }
        if(r == -1){
            k_++;
        }
        cout << pp2[k_] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}
