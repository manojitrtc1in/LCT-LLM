
#include <bits/stdc++.h>
#define SUPERPOWER ios_base::sync_with_stdio(false); cout.tie(0);
#define asd "\12"
#define forn(i,n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

using namespace std;

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int nPr(int n, int r)
{
    return factorial(n) / factorial(n - r);
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}


int main()
{
    SUPERPOWER
    int tt, a, a1, b, ans, i;
    cin >> tt;
    while(tt--)
    {
        cin >> a >> b;
        ans = 0;
        a1 = a;
        i = 1;
        if( b == 1)
            ans = 99999999;
        else
        {
            while(a1 != 0)
            {
                a1 /= b;
                ans++;
            }
        }
        for(;;)
        {
            int num = i;
            int a2 = a, b1 = b;
            while(a2 != 0)
            {
                a2 /= (b1 + i);
                num++;
            }
            if(num <= ans)
            {
                ans = num;
                i++;
            }
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}


