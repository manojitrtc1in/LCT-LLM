#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const int N = 10000000;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ll lgona(ll a)
{
if (a == 0)
{
    return 1;
}
ll r = 1;

while (a != 0)
{
    a = a / 2;
    r = r * 2;
}
return r;
}
#define MAX 200















int lookup[MAX][20];



struct Query
{
int L, R;
};





void preprocess(int arr[], int n)
{




for (int i = 0; i < n; i++)
    lookup[i][0] = i;





for (int j = 1; (1 << j) <= n; j++)
{
    

    

    

    for (int i = 0; (i + (1 << j) - 1) < n; i++)
    {
        

        

        

        if (arr[lookup[i][j - 1]] < arr[lookup[i + (1 << (j - 1))][j - 1]])
            lookup[i][j] = lookup[i][j - 1];
        else
            lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
    }
}
}



int query(int arr[], int L, int R)
{


int j = (int)log2(R - L + 1);






return __gcd(arr[lookup[L][j]], arr[lookup[R - (1 << j) + 1][j]]);
}





void RMQ(int arr[], int n, Query q[], int m)
{


preprocess(arr, n);



for (int i = 0; i < m; i++)
{
    

    

    int L = q[i].L, R = q[i].R;

    

    cout << "Minimum of [" << L << ", "
            << R << "] is "
            << query(arr, L, R) << endl;
}
}
ll divSum(ll num)
{


ll result = 0;
if (num == 1) 

    return result;


for (ll i = 2; i <= sqrt(num); i++)
{
    

    if (num % i == 0)
    {
        

        

        if (i == (num / i))
            result += i;
        else
            result += (i + num / i);
    }
}



return (result + 1ll);
}



int main()
{

int te = 1;



for (int tt = 0; tt < te; tt++)
{
    ll n, d;
    cin >> n >> d;
    ll a[n];
    int o = 0;

    vector<int> v[10];
    double tot[10] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v[a[i] % 10].push_back(a[i]);
        tot[a[i] % 10] += log10((double)(a[i]));

        o += (a[i] % 2);
    }
    for (int i = 0; i < 10; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    if (d != 0 && d != 5)
    {
        

        double an = 0;
        vector<int> v1;
        ll t = 1;
        for (int i = 0; i < 5; i++)
        {
            

            ll y = 1;
            for (int j = 0; j < 3; j++)
            {
                ll h = 1;
                for (int q = 0; q < 2; q++)
                {
                    ll r = 1;
                    for (int s = 0; s < 5; s++)
                    {
                        ll t1 = 1;
                        for (int i1 = 0; i1 < 2; i1++)
                        {
                            ll y1 = 1;
                            for (int j1 = 0; j1 < 5; j1++)
                            {
                                ll h1 = 1;

                                for (int q1 = 0; q1 < 5; q1++)
                                {
                                    ll r1 = 1;
                                    for (int s1 = 0; s1 < 3; s1++)
                                    {

                                        if ((r * y * h * t * h1 * t1 * r1 * y1) % 10 == d)
                                        {
                                            

                                            

                                            if (v[2].size() < i || v[4].size() < j || v[6].size() < q || v[8].size() < s || v[1].size() < i1 || v[3].size() < j1 || v[7].size() < q1 || v[9].size() < s1)
                                                { continue;}


                                    

                                            
                                            double f = 0;
                                            cout.precision(20);

                                            int u = 0;
                                            vector<int> v2;

                                            

                                            f += tot[8];


                                            for (int e = 0; e < v[8].size(); e++)
                                            {
                                                if (s == 0)
                                                {
                                                    f -= tot[8];
                                                    break;
                                                }
                                                if ((v[8].size() - e) % 4 == s % 4)
                                                {
                                                    u++;
                                                    break;
                                                }
                                                if (u == 0)
                                                {

                                                    f -= log10((double)(v[8][e]));
                                                }
                                            }
                                            

                                            u = 0;
                                            f += tot[2];
                                            for (int e = 0; e < v[2].size(); e++)
                                            {
                                                if (i == 0)
                                                {
                                                    f -= tot[2];
                                                    break;
                                                    continue;
                                                }

                                                if ((v[2].size() - e) % 4 == i % 4)
                                                    u++;
                                                if (u > 0)
                                                    break;
                                                f -= log10((double)(v[2][e]));

                                                

                                            }
                                            

                                            u = 0;
                                            f += tot[4];
                                            for (int e = 0; e < v[4].size(); e++)
                                            {
                                                if (j == 0)
                                                {
                                                    f -= tot[4];
                                                    break;
                                                    continue;
                                                }

                                                if ((v[4].size() - e) % 2 == j % 2)
                                                    u++;
                                                if (u > 0)
                                                    break;
                                                ;
                                                f -= log10((double)(v[4][e]));

                                                

                                            }
                                            u = 0;
                                            f += tot[6];
                                            for (int e = 0; e < v[6].size(); e++)
                                            {
                                                if (q == 0)
                                                {
                                                    f -= tot[6];
                                                    break;
                                                    continue;
                                                }
                                                if ((v[6].size() - e) % 1 == 0)
                                                    u++;
                                                if (u > 0)
                                                    break;
                                                ;
                                                f -= log10((double)(v[6][e]));

                                                

                                            }
                                            u = 0;
                                            f += tot[9];
                                            

                                            

                                            for (int e = 0; e < v[9].size(); e++)
                                            {
                                                if (s1 == 0)
                                                {
                                                    f -= tot[9];
                                                    break;
                                                    continue;
                                                }
                                                if ((v[9].size() - e) % 2 == s1 % 2)
                                                    u++;
                                                if (u > 0)
                                                    { break;}
                                                f -= log10((double)(v[9][e]));

                                                

                                            }
                                            

                                            u = 0;
                                            f += tot[1];
                                            for (int e = 0; e < v[1].size(); e++)
                                            {
                                                if (i1 == 0)
                                                {
                                                    f -= tot[1];
                                                    break;
                                                    continue;
                                                }
                                                if ((v[1].size() - e) % 1 == 0)
                                                    u++;
                                                if (u > 0)
                                                    break;
                                                ;
                                                f -= log10((double)(v[1][e]));

                                                

                                            }
                                            u = 0;
                                            f += tot[3];
                                            for (int e = 0; e < v[3].size(); e++)
                                            {
                                                if (j1 == 0)
                                                {
                                                    f -= tot[3];
                                                    break;
                                                    continue;
                                                }
                                                if ((v[3].size() - e) % 4 == j1 % 4)
                                                    u++;
                                                if (u > 0)
                                                    break;
                                                f -= log10((double)(v[3][e]));

                                                

                                            }
                                            u = 0;
                                            f += tot[7];
                                            for (int e = 0; e < v[7].size(); e++)
                                            {
                                                if (q1 == 0)
                                                {
                                                    f -= tot[7];
                                                    break;
                                                    continue;
                                                }
                                                if ((v[7].size() - e) % 4 == q1 % 4)
                                                    u++;
                                                if (u > 0)
                                                    break;
                                                f -= log10((double)(v[7][e]));
                                            }
                                                

                                            if (f > an)
                                            {
                                                v2.push_back(s);
                                                v2.push_back(i);
                                                v2.push_back(j);
                                                v2.push_back(q);
                                                v2.push_back(s1);
                                                v2.push_back(i1);
                                                v2.push_back(j1);
                                                v2.push_back(q1);
                                                


                                                v1 = v2;
                                                an = f;

                                               

                                            }
                                        }

                                        r1 = r1 * 9;
                                    }
                                    h1 *= 7;
                                }
                                y1 *= 3;
                            }
                            t1 = t1 * 1;
                        }

                        r = r * 8;
                    }
                    h *= 6;
                }
                y = y * 4;
            }
            t = t * 2;
        }
        if (v1.size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> v3;
            int u = 0;
            for (int e = 0; e < v[8].size(); e++)
            {
                if (v1[0] == 0)
                {
                    

                    break;
                    continue;
                }
                if ((v[8].size() - e) % 4 == v1[0] % 4)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[8][e]);
                }
            }
            

            u = 0;
            

            for (int e = 0; e < v[2].size(); e++)
            {
                if (v1[1] == 0)
                {
                    

                    break;
                    continue;
                }
                if ((v[2].size() - e) % 4 == v1[1] % 4)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[2][e]);
                }
            }
            

            u = 0;
            

            for (int e = 0; e < v[4].size(); e++)
            {
                if (v1[2] == 0)
                {
                    

                    continue;
                }
                if ((v[4].size() - e) % 2== v1[2] % 2)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[4][e]);
                }
            }
            u = 0;
            

            for (int e = 0; e < v[6].size(); e++)
            {
                if (v1[3] == 0)
                {
                    

                    continue;
                }
                if ((v[6].size() - e) % 1 == v1[3] %1)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[6][e]);
                }
                

            }
            u = 0;
            

            for (int e = 0; e < v[9].size(); e++)
            {
                if (v1[4] == 0)
                {
                    

                    continue;
                }
                if ((v[9].size() - e) % 2 == v1[4] % 2)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[9][e]);
                }
            }
            u = 0;
            

            for (int e = 0; e < v[1].size(); e++)
            {
                if (v1[5] == 0)
                {
                    

                    continue;
                }
                if ((v[1].size() - e) % 1 == v1[5] % 1)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[1][e]);
                }
            }
            u = 0;
            

            for (int e = 0; e < v[3].size(); e++)
            {
                if (v1[6] == 0)
                {
                    

                    continue;
                }
                if ((v[3].size() - e) % 4 == v1[6] % 4)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[3][e]);
                }
            }
            u = 0;
            

            for (int e = 0; e < v[7].size(); e++)
            {
                if (v1[7] == 0)
                {
                    

                    continue;
                }
                if ((v[7].size() - e) % 4 == v1[7] % 4)
                {
                    u++;
                }

                if (u > 0)
                {
                    v3.push_back(v[7][e]);
                }
            }
            cout<<v3.size()<<endl;

            for (auto x : v3)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    if (d == 0)
    {
        if (v[0].size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << n << endl;
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
        }
    }
    if (d == 5)
    {
        if (v[5].size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << o << endl;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                    continue;
                cout << a[i] << " ";
            }
        }
    }
}

return 0;
}
