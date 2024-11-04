


using namespace std;
using namespace __gnu_pbds;




long long int mod97 = 1000000007;
double pi = 3.1415926536;
bool comp(pair<long long int, long long int>a, pair<long long int, long long int>b)
{
    if (a.first == b.first)
    {
        if (a.second <= b.second)
            return true;
        else
            return false;
    }
    if (a.first > b.first)
        return true;
    else return false;
}
bool rev(long long int a, long long int b)
{
    if (a > b)return true;
    else return false;
}
bool compa(pair<string, pair<int, int>>a, pair<string, pair<int, int>>b)
{
    if (a.first == b.first)
    {
        if (a.second.first > b.second.first)
            return true;
        else
            return false;
    }
    if (a.first < b.first)
        return true;
    else
        return false;
}
long long int gcd(long long int bdda, long long int chota)
{
    if (chota == 0)
        return bdda;
    return gcd(chota, bdda % chota);
}
long long int lcm(long long int a, long long int b)
{
    return a * b / gcd(max(a, b), min(a, b));
}
long long int powerm(long long int a, long long int n, long long int modn)
{
    if (n == 0)return 1;
    if (n % 2 == 0)
    {
        long long int val = powerm(a, n / 2, mod97);
        val = (val * val) % modn; return val;
    }
    else
    {
        long long int val = powerm(a, n / 2, mod97);
        val = ((val * val) % modn * a) % modn; return val;
    }
}
long long int power(long long int a, long long int n)
{
    if (n == 0)return 1;
    if (n % 2 == 0)
    {
        long long int val = power(a, n / 2);
        val = (val * val); return val;
    }
    else
    {
        long long int val = power(a, n / 2);
        val = ((val * val) * a) ; return val;
    }
}
bool id0(string a, string b)
{
    if (a.size() > b.size())return true;
    else return false;

}
void solve()
{
    long long int n, m; cin >> n >> m;
    char a[n][m]; long long int count = 0;
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    long long int ii = 0, jj = 0;
    vector<vector<long long int>>fin; vector<long long int>v(6);
    long long int check = 0;
    if (n % 2 == 1)
    {
        check++;
        ii++;
        for (long long int i = 0, j = 0; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                a[i][j] = '0';
                count++;
                if (j == 0)
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    a[i][j] = '0';
                    if (a[i][j + 1] == '1')
                    {
                        a[i][j + 1] = '0';
                    }
                    else
                        a[i][j + 1] = '1';
                    if (a[i + 1][j] == '1')
                    {
                        a[i + 1][j] = '0';
                    }
                    else a[i + 1][j] = '1';
                }
                else if (j == m - 1)
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j; v[4] = i + 2; v[5] = j + 1;
                    if (a[i + 1][j - 1] == '1')
                    {
                        a[i + 1][j - 1] = '0';
                    }
                    else
                        a[i + 1][j - 1] = '1';
                    if (a[i + 1][j] == '1')
                    {
                        a[i + 1][j] = '0';
                    }
                    else
                        a[i + 1][j] = '1';
                }
                else
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    if (a[i][j + 1] == '1')
                    {
                        a[i][j + 1] = '0';
                    }
                    else
                        a[i][j + 1] = '1';
                    if (a[i + 1][j] == '1')
                    {
                        a[i + 1][j] = '0';
                    }
                    else
                        a[i + 1][j] = '1';
                }
                fin.push_back(v);
            }
        }
    }
    

    if (m % 2 == 1)
    {
        jj++;
        for (long long int i = check, j = 0; i < n; i++)
        {
            if (a[i][j] == '1')
            {
                a[i][j] = '0';
                count++;
                if (i == 0)
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    if (a[i][j + 1] == '1')
                    {
                        a[i][j + 1] = '0';
                    }
                    else
                        a[i][j + 1] = '1';
                    if (a[i + 1][j] == '1')
                    {
                        a[i + 1][j] = '0';
                    }
                    else
                        a[i + 1][j] = '1';
                }
                else if (i == n - 1)
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i; v[3] = j + 2; v[4] = i + 1; v[5] = j + 2;
                    

                    

                    if (a[i - 1][j + 1] == '1')
                    {
                        a[i - 1][j + 1] = '0';
                    }
                    else
                        a[i - 1][j + 1] = '1';
                    if (a[i][j + 1] == '1')
                    {
                        a[i][j + 1] = '0'; 

                    }
                    else
                        a[i][j + 1] = '1';
                }
                else
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    if (a[i][j + 1] == '1')
                    {
                        a[i][j + 1] = '0';
                    }
                    else
                        a[i][j + 1] = '1';
                    if (a[i + 1][j] == '1')
                    {
                        a[i + 1][j] = '0';
                    }
                    else
                        a[i + 1][j] = '1';
                }
                fin.push_back(v);
            }
        }
    }
    

    

    for (long long int i = ii; i < n; i += 2)
    {
        for (long long int j = jj; j < m; j += 2)
        {
            long long int sum = 0, flag = 0;
            sum += a[i][j] - '0'; sum += a[i + 1][j] - '0'; sum += a[i][j + 1] - '0'; sum += a[i + 1][j + 1] - '0';
            if (sum == 4)
            {
                count += 1;
                flag++;
                a[i][j] = '0'; a[i + 1][j] = '0'; a[i][j + 1] = '0';
                v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                fin.push_back(v);
            }
            else if (sum == 3)
            {
                count += 1;
                if (a[i][j] == '0')
                {
                    v[0] = i + 2; v[1] = j + 2; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                }
                else if (a[i + 1][j] == '0')
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 2;
                }
                else if (a[i][j + 1] == '0')
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                }
                else
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                }
                fin.push_back(v);
            }
            else if (sum == 2)
            {
                if (a[i][j] == '1')
                {
                    if (a[i + 1][j] == '1')
                    {
                        flag++; count++; a[i][j] = '0'; a[i + 1][j] = '0'; a[i][j + 1] = '1';
                        v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                        fin.push_back(v);
                    }
                    else if (a[i][j + 1] == '1')
                    {
                        flag++; count++; a[i][j] = '0'; a[i + 1][j] = '1'; a[i][j + 1] = '0';
                        v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                        fin.push_back(v);
                    }
                    else
                    {
                        count += 2;
                        v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                        fin.push_back(v);
                        v[0] = i + 2; v[1] = j + 2; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                        fin.push_back(v);
                    }
                }
                else if (a[i + 1][j + 1] == '1')
                {
                    if (a[i][j + 1] == '1')
                    {
                        flag++; count++; a[i + 1][j + 1] = '0'; a[i + 1][j] = '1'; a[i][j + 1] = '0';
                        v[0] = i + 2; v[1] = j + 2; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                        fin.push_back(v);
                    }
                    else if (a[i + 1][j] == '1')
                    {
                        flag++; count++; a[i + 1][j + 1] = '0'; a[i + 1][j] = '0'; a[i][j + 1] = '1';
                        v[0] = i + 2; v[1] = j + 2; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                        fin.push_back(v);
                    }
                }
                else
                {
                    count += 2;
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 2;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                }
            }
            else if (sum == 1)
            {
                flag++;
            }
            else
            {
                continue;
            }
            if (flag == 1)
            {
                count += 3;
                if (a[i][j] == '1')
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 1; v[4] = i + 2; v[5] = j + 2;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 2;
                    fin.push_back(v);
                }
                else if (a[i + 1][j] == '1')
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 2; v[2] = i + 2; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                }
                else if (a[i][j + 1] == '1')
                {
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 2; v[4] = i + 1; v[5] = j + 2;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 2; v[2] = i + 2; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                }
                else
                {
                    v[0] = i + 2; v[1] = j + 2; v[2] = i + 1; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 2; v[4] = i + 1; v[5] = j + 2;
                    fin.push_back(v);
                    v[0] = i + 1; v[1] = j + 1; v[2] = i + 2; v[3] = j + 2; v[4] = i + 2; v[5] = j + 1;
                    fin.push_back(v);
                }
            }
        }
    }
    cout << count << endl;
    for (long long int i = 0; i < fin.size(); i++)
    {
        for (auto x : fin[i])
            cout << x << " ";
        cout << endl;
    }

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);

    int t;
    t = 1;
    cin >> t; 

    while (t--)
    {
        

        solve();
    }
}