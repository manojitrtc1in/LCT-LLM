














































using namespace std;


typedef __int128 lll;
typedef double ld;













ll inf = 1e18, mod = 1e9 + 7;
int N = 400001;


int gcd(int a, int b){
    if(a > b) swap(a, b);
    if(a == 0) return b;
    return gcd(b % a, a);
}


int minn = 1e9 + 1;
int ii = -1, ij = -1;
int ii2 = -1, ij2 = -1;
int ii3 = -1, ij3 = -1;
void id0(vector<vector<int>>arr, int n, int m){
    minn = 1e9+1, ii = -1, ij = -1, ii2 = -1, ij2 = -1, ii3 = -1, ij3 = -1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){

            if(arr[i][j] == 1){
                int cnt = 1;
                if(arr[i+1][j] == 1) ++cnt;
                if(arr[i+1][j+1] == 1) ++cnt;
                if(minn > cnt && i + 1 <= n && j + 1 <= m){
                    minn = cnt;
                    ii = i+1, ij = j;
                    ii2 = i + 1, ij2 = j + 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;
                if(arr[i-1][j] == 1) ++cnt;
                if(arr[i][j-1] == 1) ++cnt;
                if(minn > cnt && i - 1 >= 1 && j -1 >= 1){
                    minn = cnt;
                    ii = i-1, ij = j;
                    ii2 = i , ij2 = j - 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;
                if(arr[i-1][j] == 1) ++cnt;
                if(arr[i][j+1] == 1) ++cnt;
                if(minn > cnt && i - 1 >= 1 && j +1 <= m){
                    minn = cnt;
                    ii = i-1, ij = j;
                    ii2 = i, ij2 = j + 1;
                    ii3 = i, ij3 = j;
                }
                if(arr[i+1][j] == 1) ++cnt;
                if(arr[i][j-1] == 1) ++cnt;
                if(minn > cnt && i + 1 <= n && j -1 >= 1){
                    minn = cnt;
                    ii = i+1, ij = j;
                    ii2 = i , ij2 = j - 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;
                if(arr[i+1][j] == 1) ++cnt;
                if(arr[i][j+1] == 1) ++cnt;
                if(minn > cnt && i + 1 <= n && j +1 <= m){
                    minn = cnt;
                    ii = i+1, ij = j;
                    ii2 = i, ij2 = j + 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;
                if(arr[i+1][j] == 1){
                    ++cnt;
                }
                if(arr[i+1][j-1] == 1) ++cnt;
                if(minn > cnt && i + 1 <= n && j-1 >= 1){
                    minn = cnt;
                    ii = i+1, ij = j;
                    ii2 = i + 1, ij2 = j - 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][ j + 1] == 1){
                    ++cnt;
                }
                if(arr[i+1][j] == 1) ++cnt;
                if(minn > cnt && i + 1 <= n && j+1 <= m){
                    minn = cnt;
                    ii = i, ij = j+1;
                    ii2 = i + 1, ij2 = j;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][ j + 1] == 1){
                    ++cnt;
                }
                if(arr[i-1][j] == 1) ++cnt;
                if(minn > cnt && i - 1 >=1 && j+1 <= m){
                    minn = cnt;
                    ii = i, ij = j+1;
                    ii2 = i - 1, ij2 = j;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][ j - 1] == 1){
                    ++cnt;
                }
                if(arr[i-1][j] == 1) ++cnt;
                if(minn > cnt && i - 1 >=1&& j-1 >= 1){
                    minn = cnt;
                    ii = i, ij = j-1;
                    ii2 = i - 1, ij2 = j;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][ j - 1] == 1){
                    ++cnt;
                }
                if(arr[i+1][j] == 1) ++cnt;
                if(minn > cnt && i + 1 <= n && j-1 >= 1){
                    minn = cnt;
                    ii = i, ij = j-1;
                    ii2 = i + 1, ij2 = j;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i-1][j] == 1){
                    ++cnt;
                }
                if(arr[i-1][j-1] == 1) ++cnt;
                if(minn > cnt && i-1 >= 1 && j - 1 >= 1){
                    minn = cnt;
                    ii = i-1, ij = j;
                    ii2 = i - 1, ij2 = j - 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i-1][j] == 1){
                    ++cnt;
                }
                if(arr[i-1][j+1] == 1) ++cnt;
                if(minn > cnt && i-1 >= 1 && j + 1 <= m){
                    minn = cnt;
                    ii = i-1, ij = j;
                    ii2 = i - 1, ij2 = j + 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][j-1] == 1){
                    ++cnt;
                }
                if(arr[i-1][j-1] == 1) ++cnt;
                if(minn > cnt && j-1 >= 1 && i-1 >= 1){
                    minn = cnt;
                    ii = i, ij = j-1;
                    ii2 = i - 1, ij2 = j - 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][j-1] == 1){
                    ++cnt;
                }
                if(arr[i+1][j-1] == 1) ++cnt;
                if(minn > cnt && j-1 >= 1 && i + 1 <= n){
                    minn = cnt;
                    ii = i, ij = j-1;
                    ii2 = i + 1, ij2 = j - 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][j+1] == 1){
                    ++cnt;
                }
                if(arr[i+1][j+1] == 1) ++cnt;
                if(minn > cnt && j + 1 <= m && i + 1 <= n){
                    minn = cnt;
                    ii = i, ij = j+1;
                    ii2 = i + 1, ij2 = j + 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;

                if(arr[i][j+1] == 1){
                    ++cnt;
                }
                if(arr[i-1][j+1] == 1) ++cnt;
                if(minn > cnt && i-1 >= 1 && j + 1 <= m){
                    minn = cnt;
                    ii = i, ij = j+1;
                    ii2 = i - 1, ij2 = j + 1;
                    ii3 = i, ij3 = j;
                }
                cnt = 1;



            }


        }
    }
}


void qq(vector<vector<int>>arr, int n, int m, int i, int j){
        minn = 1e9+1, ii = -1, ij = -1, ii2 = -1, ij2 = -1, ii3 = -1, ij3 = -1;
        if(arr[i][j] == 1){
            int cnt = 1;
            if(arr[i+1][j] == 1) ++cnt;
            if(arr[i+1][j+1] == 1) ++cnt;
            if(minn > cnt && i + 1 <= n && j + 1 <= m){
                minn = cnt;
                ii = i+1, ij = j;
                ii2 = i + 1, ij2 = j + 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;
            if(arr[i-1][j] == 1) ++cnt;
            if(arr[i][j-1] == 1) ++cnt;
            if(minn > cnt && i - 1 >= 1 && j -1 >= 1){
                minn = cnt;
                ii = i-1, ij = j;
                ii2 = i , ij2 = j - 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;
            if(arr[i-1][j] == 1) ++cnt;
            if(arr[i][j+1] == 1) ++cnt;
            if(minn > cnt && i - 1 >= 1 && j +1 <= m){
                minn = cnt;
                ii = i-1, ij = j;
                ii2 = i, ij2 = j + 1;
                ii3 = i, ij3 = j;
            }
            if(arr[i+1][j] == 1) ++cnt;
            if(arr[i][j-1] == 1) ++cnt;
            if(minn > cnt && i + 1 <= n && j -1 >= 1){
                minn = cnt;
                ii = i+1, ij = j;
                ii2 = i , ij2 = j - 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;
            if(arr[i+1][j] == 1) ++cnt;
            if(arr[i][j+1] == 1) ++cnt;
            if(minn > cnt && i + 1 <= n && j +1 <= m){
                minn = cnt;
                ii = i+1, ij = j;
                ii2 = i, ij2 = j + 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;
            if(arr[i+1][j] == 1){
                ++cnt;
            }
            if(arr[i+1][j-1] == 1) ++cnt;
            if(minn > cnt && i + 1 <= n && j-1 >= 1){
                minn = cnt;
                ii = i+1, ij = j;
                ii2 = i + 1, ij2 = j - 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][ j + 1] == 1){
                ++cnt;
            }
            if(arr[i+1][j] == 1) ++cnt;
            if(minn > cnt && i + 1 <= n && j+1 <= m){
                minn = cnt;
                ii = i, ij = j+1;
                ii2 = i + 1, ij2 = j;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][ j + 1] == 1){
                ++cnt;
            }
            if(arr[i-1][j] == 1) ++cnt;
            if(minn > cnt && i - 1 >=1 && j+1 <= m){
                minn = cnt;
                ii = i, ij = j+1;
                ii2 = i - 1, ij2 = j;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][ j - 1] == 1){
                ++cnt;
            }
            if(arr[i-1][j] == 1) ++cnt;
            if(minn > cnt && i - 1 >=1&& j-1 >= 1){
                minn = cnt;
                ii = i, ij = j-1;
                ii2 = i - 1, ij2 = j;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][ j - 1] == 1){
                ++cnt;
            }
            if(arr[i+1][j] == 1) ++cnt;
            if(minn > cnt && i + 1 <= n && j-1 >= 1){
                minn = cnt;
                ii = i, ij = j-1;
                ii2 = i + 1, ij2 = j;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i-1][j] == 1){
                ++cnt;
            }
            if(arr[i-1][j-1] == 1) ++cnt;
            if(minn > cnt && i-1 >= 1 && j - 1 >= 1){
                minn = cnt;
                ii = i-1, ij = j;
                ii2 = i - 1, ij2 = j - 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i-1][j] == 1){
                ++cnt;
            }
            if(arr[i-1][j+1] == 1) ++cnt;
            if(minn > cnt && i-1 >= 1 && j + 1 <= m){
                minn = cnt;
                ii = i-1, ij = j;
                ii2 = i - 1, ij2 = j + 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][j-1] == 1){
                ++cnt;
            }
            if(arr[i-1][j-1] == 1) ++cnt;
            if(minn > cnt && j-1 >= 1 && i-1 >= 1){
                minn = cnt;
                ii = i, ij = j-1;
                ii2 = i - 1, ij2 = j - 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][j-1] == 1){
                ++cnt;
            }
            if(arr[i+1][j-1] == 1) ++cnt;
            if(minn > cnt && j-1 >= 1 && i + 1 <= n){
                minn = cnt;
                ii = i, ij = j-1;
                ii2 = i + 1, ij2 = j - 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][j+1] == 1){
                ++cnt;
            }
            if(arr[i+1][j+1] == 1) ++cnt;
            if(minn > cnt && j + 1 <= m && i + 1 <= n){
                minn = cnt;
                ii = i, ij = j+1;
                ii2 = i + 1, ij2 = j + 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;

            if(arr[i][j+1] == 1){
                ++cnt;
            }
            if(arr[i-1][j+1] == 1) ++cnt;
            if(minn > cnt && i-1 >= 1 && j + 1 <= m){
                minn = cnt;
                ii = i, ij = j+1;
                ii2 = i - 1, ij2 = j + 1;
                ii3 = i, ij3 = j;
            }
            cnt = 1;
    }

}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>arr(n+2, vector<int>(m+2, -1));
    int r = 0;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j){
            if(s[j] == '1') arr[i][j + 1] = 1;
            else arr[i][j + 1] = 0, ++r;
        }
    }
    if(r == n * m){
        cout << "0\n";
        return;
    }
    id0(arr, n, m);
    arr[ii][ij] = 0, arr[ii2][ij2] = 0, arr[ii3][ij3] = 0;
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(arr[i][j] == 1) ++ans;
        }
    }
    cout << ans << '\n';


}




signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while(t--){
        solve();
    }

}
