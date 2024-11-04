#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <numeric>
#include <bitset>
#include <cassert>
#include <ctime>
#include <deque>
#include <list>
#include <functional>
#include <iterator>
#include <memory.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second
#define endl '\n'
#define MAX 1000005
#define MOD 1000000007
#define ll long long
#define inf 1e18
#define ld long double
#define int ll

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int dp[1005][25][11];

int go(string A, int i, int pv, int v)
{
    if (i == A.length())
    {
        if (pv == 0)
            return 1;
        return 0;
    }
    if (dp[i][pv][v] != -1)
        return dp[i][pv][v];
    int ans = 0;
    if (A[i] == '_')
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int y = pv * 10 + j;
            y %= 25;
            ans += go(A, i + 1, y, v);
        }
    }
    else if (A[i] == 'X')
    {
        if (v != 10)
        {
            ans += go(A, i + 1, (pv * 10 + v) % 25, v);
        }
        else
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int y = pv * 10 + j;
                y %= 25;
                ans += go(A, i + 1, y, j);
            }
        }
    }
    else
    {
        ans += go(A, i + 1, (pv * 10 + (A[i] - '0')) % 25, v);
    }
    return dp[i][pv][v] = ans;
}

signed main()
{
    fastio;
    int ttt = 1;
    while (ttt--)
    {
        string A;
        cin >> A;
        if (A.length() == 1 && A[0] == '0')
        {
            cout << "1" << endl;
            return 0;
        }
        if (A[0] == '0')
        {
            cout << "0" << endl;
            return 0;
        }
        if (A.length() == 1)
        {
            if (A[0] == 'X' || A[0] == '_')
            {
                cout << "1" << endl;
                return 0;
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << go(A, 0, 0, 10) << endl;
    }
    return 0;
}
