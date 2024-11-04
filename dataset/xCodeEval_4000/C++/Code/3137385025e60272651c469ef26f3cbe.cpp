
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl;
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);


#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.first < b.first )
        return true;
    if( a.first==b.first && a.S != b.second )
       return true;
    return false;
}


ll const mod = 1e9+7;
ll const inf = 1e18;
ll const maxn = 1e5+1;

void solve()
{      
      ll n,m; cin >> n >> m;
      ll a[n][m];
      array<ll, 6> ops[3*n*m + 1];
      ll it = 0;
      string s[n]; f(i,0,n) cin >> s[i];
      f(i,0,n) f(j,0,m) a[i][j] = (ll)(s[i][j]-'0');

      for(ll i =0; i<n-1; i++){

            for(ll j = 0; j<m-1; j++){

                  ll cur = a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];

                  if( cur==4 ){
                        

                        ops[it][0] = j, ops[it][1] = i; 
                        ops[it][2] = j+1, ops[it][3] = i; 
                        ops[it][4] = j+1, ops[it++][5] = i+1;
                        a[i][j]=a[i][j+1]=a[i+1][j+1] = 0; 
                  }
                  else if(cur == 3){
                        

                        ll h = 0;
                        if( a[i][j]==1 ){
                              ops[it][h++] = j, ops[it][h++] =i;
                              a[i][j] = 0;
                        }
                        if( a[i][j+1] == 1 ){
                              ops[it][h++] = j+1, ops[it][h++] =i;
                              a[i][j+1] = 0;
                        }
                        if( a[i+1][j] == 1 ){
                              ops[it][h++] = j, ops[it][h++] =i+1;
                              a[i+1][j] = 0;
                        }
                        if( a[i+1][j+1] == 1 ){
                              ops[it][h++] = j+1, ops[it][h] =i+1;
                              a[i+1][j+1] = 0;
                        }
                        it++;

                  }
                  else if(cur == 2){
                        

                        array<ll,2> A,B,C;
                        bool g = 0;
                        f(p,0,2){
                              f(q,0,2){
                                    if( a[i+p][j+q]==0 && g==0){
                                          B[0] = i+p, B[1] = j+q;
                                          

                                          g=1;
                                    }
                                    else if( a[i+p][j+q]==0 && g){
                                          C[0] = i+p, C[1] = j+q;
                                          

                                          goto kkgk;
                                    }
                              }
                        }
                        kkgk:
                        ;
                        f(p,0,2){
                              f(q,0,2){
                                    if( a[i+p][j+q]==1 ){
                                          a[i+p][j+q] = 0;
                                          A[0] = i+p, A[1] = j+q;
                                          goto fgff;
                                    }
                              }
                        }
                        fgff:
                        a[B[0]][B[1]] = 1;
                        a[C[0]][C[1]] = 1;
                        ops[it][0] = A[1], ops[it][1] = A[0]; 
                        ops[it][2] = B[1], ops[it][3] = B[0]; 
                        ops[it][4] = C[1], ops[it++][5] = C[0];

                        ll h = 0;
                        if( a[i][j]==1 ){
                              ops[it][h++] = j, ops[it][h++] =i;
                              a[i][j] = 0;
                        }
                        if( a[i][j+1] == 1 ){
                              ops[it][h++] = j+1, ops[it][h++] =i;
                              a[i][j+1] = 0;
                        }
                        if( a[i+1][j] == 1 ){
                              ops[it][h++] = j, ops[it][h++] =i+1;
                              a[i+1][j] = 0;
                        }
                        if( a[i+1][j+1] == 1 ){
                              ops[it][h++] = j+1, ops[it][h] =i+1;
                              a[i+1][j+1] = 0;
                        }
                        it++;

                  }
                  else if(cur == 1){
                        

                        array<ll,2> A,B,C;
                        bool g = 0;
                        f(p,0,2){
                              f(q,0,2){
                                    if( a[i+p][j+q]==1 ){
                                          

                                          A[0] = i+p, A[1] = j+q;
                                          
                                    }
                              }
                        }
                        f(p,0,2){
                              f(q,0,2){
                                    if( a[i+p][j+q]==0 && g==0){
                                          B[0] = i+p, B[1] = j+q;
                                          a[B[0]][B[1]]=1;
                                          g=1;
                                    }
                                    else if( a[i+p][j+q]==0 && g){
                                          C[0] = i+p, C[1] = j+q;
                                          a[C[0]][C[1]]=1;
                                          goto kkkkk;
                                    }
                              }
                        }kkkkk:
                        a[A[0]][A[1]] = 0;
                    
                        ops[it][0] = A[1], ops[it][1] = A[0]; 
                        ops[it][2] = B[1], ops[it][3] = B[0]; 
                        ops[it][4] = C[1], ops[it][5] = C[0];
                        
                        it++;
                        g = 0;
                        f(p,0,2){
                              f(q,0,2){
                                    if( a[i+p][j+q]==0 && g==0){
                                          B[0] = i+p, B[1] = j+q;
                                          

                                          g=1;
                                    }
                                    else if( a[i+p][j+q]==0 && g){
                                          C[0] = i+p, C[1] = j+q;
                                          

                                          goto kkkk;
                                    }
                              }
                        }
                        kkkk:
                        ;
                        f(p,0,2){
                              f(q,0,2){
                                    if( a[i+p][j+q]==1 ){
                                          a[i+p][j+q] = 0;
                                          A[0] = i+p, A[1] = j+q;
                                          goto ffff;
                                    }
                              }
                        }
                        ffff:
                        a[B[0]][B[1]] = 1;
                        a[C[0]][C[1]] = 1;
                        ops[it][0] = A[1], ops[it][1] = A[0]; 
                        ops[it][2] = B[1], ops[it][3] = B[0]; 
                        ops[it][4] = C[1], ops[it++][5] = C[0];

                        ll h = 0;
                        if( a[i][j]==1 ){
                              ops[it][h++] = j, ops[it][h++] =i;
                              a[i][j] = 0;
                        }
                        if( a[i][j+1] == 1 ){
                              ops[it][h++] = j+1, ops[it][h++] =i;
                              a[i][j+1] = 0;
                        }
                        if( a[i+1][j] == 1 ){
                              ops[it][h++] = j, ops[it][h++] =i+1;
                              a[i+1][j] = 0;
                        }
                        if( a[i+1][j+1] == 1 ){
                              ops[it][h++] = j+1, ops[it][h] =i+1;
                              a[i+1][j+1] = 0;
                        }
                        it++;


                  }
                  

            }

      }

      for(ll i=0; i<n-1; i++){
            ll j = m-2;
            ll cur = a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
            

            if(cur==0)continue;
            array<ll,2> A,B,C;
            bool g = 0;
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==1 ){
                              

                              A[0] = i+p, A[1] = j+q;
                              
                        }
                  }
            }
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==0 && g==0){
                              B[0] = i+p, B[1] = j+q;
                              a[B[0]][B[1]]=1;
                              g=1;
                        }
                        else if( a[i+p][j+q]==0 && g){
                              C[0] = i+p, C[1] = j+q;
                              a[C[0]][C[1]]=1;
                              goto kkkkh;
                        }
                  }
            }kkkkh:
            a[A[0]][A[1]] = 0;
        
            ops[it][0] = A[1], ops[it][1] = A[0]; 
            ops[it][2] = B[1], ops[it][3] = B[0]; 
            ops[it][4] = C[1], ops[it][5] = C[0];
            
            it++;
            g = 0;
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==0 && g==0){
                              B[0] = i+p, B[1] = j+q;
                              

                              g=1;
                        }
                        else if( a[i+p][j+q]==0 && g){
                              C[0] = i+p, C[1] = j+q;
                              

                              goto kkkh;
                        }
                  }
            }
            kkkh:
            ;
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==1 ){
                              a[i+p][j+q] = 0;
                              A[0] = i+p, A[1] = j+q;
                              goto fffh;
                        }
                  }
            }
            fffh:
            a[B[0]][B[1]] = 1;
            a[C[0]][C[1]] = 1;
            ops[it][0] = A[1], ops[it][1] = A[0]; 
            ops[it][2] = B[1], ops[it][3] = B[0]; 
            ops[it][4] = C[1], ops[it++][5] = C[0];

            ll h = 0;
            if( a[i][j]==1 ){
                  ops[it][h++] = j, ops[it][h++] =i;
                  a[i][j] = 0;
            }
            if( a[i][j+1] == 1 ){
                  ops[it][h++] = j+1, ops[it][h++] =i;
                  a[i][j+1] = 0;
            }
            if( a[i+1][j] == 1 ){
                  ops[it][h++] = j, ops[it][h++] =i+1;
                  a[i+1][j] = 0;
            }
            if( a[i+1][j+1] == 1 ){
                  ops[it][h++] = j+1, ops[it][h] =i+1;
                  a[i+1][j+1] = 0;
            }
            it++;
      }
      for(ll j=0;j<m-1; j++){
            ll i = n-2;
            ll cur = a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
            

            if(cur==0)continue;
            array<ll,2> A,B,C;
            bool g = 0;
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==1 ){
                              

                              A[0] = i+p, A[1] = j+q;
                              
                        }
                  }
            }
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==0 && g==0){
                              B[0] = i+p, B[1] = j+q;
                              a[B[0]][B[1]]=1;
                              g=1;
                        }
                        else if( a[i+p][j+q]==0 && g){
                              C[0] = i+p, C[1] = j+q;
                              a[C[0]][C[1]]=1;
                              goto hkkkh;
                        }
                  }
            }hkkkh:
            a[A[0]][A[1]] = 0;
        
            ops[it][0] = A[1], ops[it][1] = A[0]; 
            ops[it][2] = B[1], ops[it][3] = B[0]; 
            ops[it][4] = C[1], ops[it][5] = C[0];
            
            it++;
            g = 0;
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==0 && g==0){
                              B[0] = i+p, B[1] = j+q;
                              

                              g=1;
                        }
                        else if( a[i+p][j+q]==0 && g){
                              C[0] = i+p, C[1] = j+q;
                              

                              goto hkkh;
                        }
                  }
            }
            hkkh:
            ;
            f(p,0,2){
                  f(q,0,2){
                        if( a[i+p][j+q]==1 ){
                              a[i+p][j+q] = 0;
                              A[0] = i+p, A[1] = j+q;
                              goto hffh;
                        }
                  }
            }
            hffh:
            a[B[0]][B[1]] = 1;
            a[C[0]][C[1]] = 1;
            ops[it][0] = A[1], ops[it][1] = A[0]; 
            ops[it][2] = B[1], ops[it][3] = B[0]; 
            ops[it][4] = C[1], ops[it++][5] = C[0];

            ll h = 0;
            if( a[i][j]==1 ){
                  ops[it][h++] = j, ops[it][h++] =i;
                  a[i][j] = 0;
            }
            if( a[i][j+1] == 1 ){
                  ops[it][h++] = j+1, ops[it][h++] =i;
                  a[i][j+1] = 0;
            }
            if( a[i+1][j] == 1 ){
                  ops[it][h++] = j, ops[it][h++] =i+1;
                  a[i+1][j] = 0;
            }
            if( a[i+1][j+1] == 1 ){
                  ops[it][h++] = j+1, ops[it][h] =i+1;
                  a[i+1][j+1] = 0;
            }
            it++;
      }
      cout << it << endl;
      for(ll i = 0; i<it; i++){
            cout << ops[i][1]+1 << " " << ops[i][0]+1 << " " << ops[i][3]+1 << " " << ops[i][2]+1 << " " << ops[i][5]+1 << " " << ops[i][4]+1 << endl;
      }
}    
                
int main() {
Knucklehead 


#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
 
        
          ll t;
          cin>>t;
          f(testcases,0,t){
               

               solve();
          }
 
 
    return 0;
}     