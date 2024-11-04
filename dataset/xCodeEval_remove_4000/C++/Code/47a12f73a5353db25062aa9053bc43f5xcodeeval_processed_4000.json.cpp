
using namespace std;































int mod = 1000000000 + 7;
























ll add(ll a, ll b){return((a % mod + b % mod) % mod);}


ll mul(ll a, ll b){return(((a % mod) * (b % mod)) % mod);}






void fun()
{
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    

}









































signed main() 
{
    rko;
    fun();
    

    int tests=1; cin >> tests;
    while(tests--)
    {
        int n, m; cin >> n >> m;
        char a[n+2][m+2];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
            }
        }

        std::vector<pair<int, int > > v;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j] == '1')
                {
                    int count = 0;
                    count += (int)(a[i][j] - '0');
                    count += (int)(a[i+1][j] - '0');
                    count += (int)(a[i+1][j+1] - '0');
                    count += (int)(a[i][j+1] - '0');
                    if(count == 1)
                    {
                        v.push_back(make_pair(i, j));
                        v.push_back(make_pair(i + 1, j));
                        v.push_back(make_pair(i + 1, j + 1));

                        v.push_back(make_pair(i, j));
                        v.push_back(make_pair(i + 1, j));
                        v.push_back(make_pair(i, j + 1));

                        v.push_back(make_pair(i, j));
                        v.push_back(make_pair(i, j + 1));
                        v.push_back(make_pair(i + 1, j + 1));
                    }
                    
                    if(count == 2)
                    {
                        if(a[i+1][j] == '1') {
                            v.push_back(make_pair(i, j));
                            v.push_back(make_pair(i, j + 1));
                            v.push_back(make_pair(i + 1, j + 1));

                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i, j + 1));
                            v.push_back(make_pair(i + 1, j + 1));
                            
                            a[i+1][j] = '0';
                        }

                        if(a[i+1][j+1] == '1') {
                            v.push_back(make_pair(i, j));
                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i, j + 1));

                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i, j + 1));
                            v.push_back(make_pair(i + 1, j + 1));
                            
                            a[i+1][j+1] = '0';
                        }

                        if(a[i][j+1] == '1') {
                            v.push_back(make_pair(i, j));
                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i + 1, j + 1));

                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i, j + 1));
                            v.push_back(make_pair(i + 1, j + 1));
                            
                            a[i][j+1] = '0';
                        }
                    }

                    if(count == 3) 
                    {
                        if(a[i+1][j] == '1' and a[i+1][j+1] == '1') {
                            v.push_back(make_pair(i, j));
                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i + 1, j + 1));
                            
                            a[i+1][j] = '0'; a[i+1][j+1] = '0';
                        }

                        if(a[i+1][j] == '1' and a[i][j+1] == '1') {
                            v.push_back(make_pair(i, j));
                            v.push_back(make_pair(i + 1, j));
                            v.push_back(make_pair(i, j + 1));
                            
                            a[i+1][j] = '0'; a[i][j+1] = '0';
                        } 

                        if(a[i+1][j+1] == '1' and a[i][j+1] == '1') {
                            v.push_back(make_pair(i, j + 1));
                            v.push_back(make_pair(i, j));
                            v.push_back(make_pair(i + 1, j + 1));
                            
                            a[i+1][j+1] = '0'; a[i][j+1] = '0';
                        }
                    }

                    if(count == 4) {

                        v.push_back(make_pair(i, j + 1));
                        v.push_back(make_pair(i + 1, j));
                        v.push_back(make_pair(i + 1, j + 1));

                        v.push_back(make_pair(i, j));
                        v.push_back(make_pair(i + 1, j));
                        v.push_back(make_pair(i + 1, j + 1));

                        v.push_back(make_pair(i, j));
                        v.push_back(make_pair(i + 1, j));
                        v.push_back(make_pair(i, j + 1));

                        v.push_back(make_pair(i, j));
                        v.push_back(make_pair(i, j + 1));
                        v.push_back(make_pair(i + 1, j + 1));

                        a[i][j+1] = '0'; a[i+1][j+1] = '0'; a[i+1][j] = '0';
                    }
                    a[i][j] = '0';
                }
            }
        }
        

        

        

        

        

        

        

        

        for(int i=1;i<n;i++)
        {
            if(a[i][m] == '1') 
            {
                int count = 1;
                count += (int)(a[i+1][m] - '0');
                count += (int)(a[i+1][m-1] - '0');
                count += (int)(a[i][m-1] - '0');
                if(count == 1)
                {
                    v.push_back(make_pair(i, m));
                    v.push_back(make_pair(i + 1, m));
                    v.push_back(make_pair(i, m - 1));

                    v.push_back(make_pair(i, m));
                    v.push_back(make_pair(i + 1, m));
                    v.push_back(make_pair(i + 1, m - 1));

                    v.push_back(make_pair(i, m));
                    v.push_back(make_pair(i, m - 1));
                    v.push_back(make_pair(i + 1, m - 1));

                    a[i][m] = '0';
                }

                if(count == 2)
                {
                    if(a[i+1][m] == '1') {
                        v.push_back(make_pair(i, m));
                        v.push_back(make_pair(i, m - 1));
                        v.push_back(make_pair(i + 1, m - 1));

                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i + 1, m - 1));
                        v.push_back(make_pair(i, m - 1));

                        a[i+1][m] = '0';
                    }

                    if(a[i+1][m-1] == '1') {
                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i, m - 1));
                        v.push_back(make_pair(i + 1, m - 1));

                        v.push_back(make_pair(i, m));
                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i, m - 1));

                        a[i+1][m-1] = '0';
                    }

                    if(a[i][m-1] == '1') {
                        v.push_back(make_pair(i, m));
                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i + 1, m - 1));

                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i + 1, m - 1));
                        v.push_back(make_pair(i, m - 1));

                        a[i][m-1] = '0';
                    }

                    a[i][m] = '0';
                }

                if(count == 3) 
                {
                    if(a[i+1][m] == '1' and a[i+1][m-1] == '1') {
                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i + 1, m - 1));
                        v.push_back(make_pair(i, m));

                        a[i+1][m] = '0'; a[i+1][m-1] = '0';
                    }

                    if(a[i+1][m] == '1' and a[i][m-1] == '1') {
                        v.push_back(make_pair(i + 1, m));
                        v.push_back(make_pair(i, m - 1));
                        v.push_back(make_pair(i, m));

                        a[i+1][m] = '0'; a[i][m-1] = '0';
                    }

                    if(a[i][m-1] == '1' and a[i+1][m-1] == '1') {
                        v.push_back(make_pair(i, m - 1));
                        v.push_back(make_pair(i + 1, m - 1));
                        v.push_back(make_pair(i, m));
                    
                        a[i+1][m-1] = '0'; a[i][m-1] = '0';
                    }

                    a[i][m] = '0';
                }
            }
        }
        

        

        

        

        

        

        

        


        for(int i=1;i<m;i++)
        {
            if(a[n][i] == '1')
            {
                int count = 1;
                count += (int)(a[n][i+1] - '0');
                count += (int)(a[n-1][i] - '0');
                count += (int)(a[n-1][i+1] - '0');
                if(count == 1)
                {
                    v.push_back(make_pair(n, i));
                    v.push_back(make_pair(n - 1, i));
                    v.push_back(make_pair(n, i + 1));

                    v.push_back(make_pair(n, i));
                    v.push_back(make_pair(n - 1, i + 1));
                    v.push_back(make_pair(n, i + 1));

                    v.push_back(make_pair(n, i));
                    v.push_back(make_pair(n - 1, i + 1));
                    v.push_back(make_pair(n - 1, i));

                    a[n][i] = '0';
                }

                if(count == 2)
                {
                    if(a[n][i+1] == '1') {
                        v.push_back(make_pair(n, i));
                        v.push_back(make_pair(n - 1, i));
                        v.push_back(make_pair(n - 1, i + 1));

                        v.push_back(make_pair(n - 1, i + 1));
                        v.push_back(make_pair(n - 1, i));
                        v.push_back(make_pair(n, i + 1));

                        a[n][i+1] = '0';
                    }   
                    
                    if(a[n-1][i] == '1') {
                        v.push_back(make_pair(n, i + 1));
                        v.push_back(make_pair(n - 1, i));
                        v.push_back(make_pair(n - 1, i + 1));

                        v.push_back(make_pair(n - 1, i + 1));
                        v.push_back(make_pair(n, i));
                        v.push_back(make_pair(n, i + 1));

                        a[n-1][i] = '0';
                    }

                    if(a[n-1][i+1] == '1') {
                        v.push_back(make_pair(n, i + 1));
                        v.push_back(make_pair(n - 1, i));
                        v.push_back(make_pair(n - 1, i + 1));

                        v.push_back(make_pair(n, i));
                        v.push_back(make_pair(n - 1, i));
                        v.push_back(make_pair(n, i + 1));

                        a[n-1][i+1] = '0';
                    }

                    a[n][i] = '0';

                }

                if(count == 3)
                {
                    if(a[n][i+1] == '1' and a[n-1][i+1] == '1') {
                        v.push_back(make_pair(n, i));
                        v.push_back(make_pair(n, i + 1));
                        v.push_back(make_pair(n - 1, i + 1));

                        a[n][i+1] = '0'; a[n - 1][i + 1] = '0';
                    }

                    if(a[n][i+1] == '1' and a[n-1][i] == '1') {
                        v.push_back(make_pair(n, i));
                        v.push_back(make_pair(n, i + 1));
                        v.push_back(make_pair(n - 1, i));

                        a[n][i+1] = '0'; a[n - 1][i] = '0';
                    }

                    if(a[n-1][i] == '1' and a[n-1][i+1] == '1') {
                        v.push_back(make_pair(n, i));
                        v.push_back(make_pair(n - 1, i));
                        v.push_back(make_pair(n - 1, i + 1));

                        a[n-1][i] = '0'; a[n - 1][i + 1] = '0';
                    }

                    a[n][i] = '0';
                }
            }
        }

        if(a[n][m] == '1')
        {
            v.push_back(make_pair(n, m));
            v.push_back(make_pair(n - 1, m));
            v.push_back(make_pair(n - 1, m - 1));

            v.push_back(make_pair(n, m));
            v.push_back(make_pair(n - 1, m));
            v.push_back(make_pair(n, m - 1));

            v.push_back(make_pair(n, m));
            v.push_back(make_pair(n, m - 1));
            v.push_back(make_pair(n - 1, m - 1));

            a[n][m] = '0';
        }            

        

        

        

        

        

        

        

        



        cout << (int)v.size() / 3 << '\n';
        int count = 0;
        for(auto it: v)
        {
            cout << it.first << ' ' << it.second << ' ';
            count++;
            if(count == 3) count = 0, cout << '\n';
        }

    }    
    cerr << "time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}