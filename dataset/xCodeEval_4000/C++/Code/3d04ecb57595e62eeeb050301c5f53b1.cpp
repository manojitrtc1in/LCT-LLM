#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
























long long fnum = 1000000007;


const long long qnum = 200001;



































long long hcf(long long a, long long b)
{
    long long p, q, x, y;
    p = min(a, b);
    q = max(a, b);

    while (p != 0)
    {
        x = (q / p);
        q -= (x * p);

        y = p;
        p = q;
        q = y;
    }

    return y;
}





































































































































































































































































































































































































int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    


    long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, t, v, x, y, z;
    long long num, val, check, count, sum, maxm, minm, mid, ind, ans, fre, mfre;
    long long c0, c1;
    

    string s, u, w;
    cin >> t;
    v = t;
    


    

    

    

    

    

    

    

    


    

    

    

    


    

    

    

    


    

    

    

    


    while (v > 0)
    {
        v--;
        cin >> a >> b >> c >> d;
        


        

        


        

        


        

        


        

        


        

        

        

        


        

        

        

        

        

        

        


        

        

        

        


        

        

        

        


        

        

        

        


        

        


        

        

        


        

        

        

        


        

        

        


        

        

        


        

        

        

        


        

        

        


        

        

        


        

        

        

        

        


        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        

        


        

        

        


        

        

        

        

        

        


        

        


        

        

        

        

        


        

        

        

        

        

        


        

        

        


        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        


        

        

        

        

        


        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        


        

        


        

        

        


        

        

        

        


        

        


        

        


        

        

        

        

        

        

        


        


        x = (a * b);
        check = 0;

        if ((c - (c % x)) >= x && (c - (c % x)) > a)
        {
            cout << (c - (c % x)) << " " << (b + 1) << endl;
            continue;
        }

        if ((d - (d % x)) >= x && (d - (d % x)) > b)
        {
            cout << (a + 1) << " " << (d - (d % x)) << endl;
            continue;
        }

        vector<long long> v1;
        vector<long long> v2;
        map<long long, long long> mm;

        v1.push_back(1);
        v1.push_back(a);
        x = a;

        for (i = 2; (i * i) <= a; i++)
        {
            while (x % i == 0)
            {
                v1.push_back(x / i);
                v1.push_back(i);

                x /= i;
            }
        }

        v2.push_back(1);
        v2.push_back(b);
        x = b;

        for (i = 2; (i * i) <= b; i++)
        {
            while (x % i == 0)
            {
                v2.push_back(x / i);
                v2.push_back(i);

                x /= i;
            }
        }

        for (i = 0; i < v1.size(); i++)
        {
            for (j = 0; j < v2.size(); j++)
            {
                mm[v1[i] * v2[j]]++;
            }
        }

        

        

        

        


        

        

        

        

        


        

        auto it = mm.begin();

        

        

        

        

        


        check = 0;
        


        it = mm.begin();
        while (it != mm.end())
        {
            x = (a * b);
            y = (x / (*it).first);
            num = 0;

            m = ((a + 1) / (*it).first);
            n = (c / (*it).first);

            if (m == n)
            {
                if ((a + 1) == (m * (*it).first))
                {
                    num = -1;
                }
            }
            else
            {
                num = 1;
            }

            if (num != 0)
            {
                y = (x / hcf (x, (c - (c % (*it).first))));

                p = (b + 1) / y;
                q = (d / y);

                if (p == q)
                {
                    if ((b + 1) == (p * y))
                    {
                        if (num == -1)
                        {
                            cout << (m * (*it).first) << " " << (p * y) << endl;
                            check = 1;
                            break;
                        }
                        else
                        {
                            cout << (n * (*it).first) << " " << (p * y) << endl;
                            check = 1;
                            break;
                        }
                    }
                }
                else
                {
                    if (num == -1)
                    {
                        cout << (m * (*it).first) << " " << (q * y) << endl;
                        check = 1;
                        break;
                    }
                    else
                    {
                        cout << (n * (*it).first) << " " << (q * y) << endl;
                        check = 1;
                        break;
                    }
                }
            }

            m = ((b + 1) / (*it).first);
            n = (d / (*it).first);

            num = 0;
            if (m == n)
            {
                if ((b + 1) == (m * (*it).first))
                {
                    num = -1;
                }
            }
            else
            {
                num = 1;
            }

            if (num != 0)
            {
                y = (x / hcf (x, (d - (d % (*it).first))));
                
                p = (a + 1) / y;
                q = (c / y);

                if (p == q)
                {
                    if ((a + 1) == (p * y))
                    {
                        if (num == -1)
                        {
                            cout << (p * y) << " " << (m * (*it).first) << endl;
                            check = 1;
                            break;
                        }
                        else
                        {
                            cout << (p * y) << " " << (n * (*it).first) << endl;
                            check = 1;
                            break;
                        }
                    }
                }
                else
                {
                    if (num == -1)
                    {
                        cout << (q * y) << " " << (m * (*it).first) << endl;
                        check = 1;
                        break;
                    }
                    else
                    {
                        cout << (q * y) << " " << (n * (*it).first) << endl;
                        check = 1;
                        break;
                    }
                }
            }

            it ++;
        }

        if (check == 0)
        {
            cout << -1 << " " << -1 << endl;
        }
    }

    return 0;
}