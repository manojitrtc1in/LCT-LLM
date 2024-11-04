#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD (long)(1e9 + 7)
#define MOD2 MOD * MOD
#define pInf INT_MAX
#define nInf INT_MIN

void solve();
int maxRight(int x, int a[], int size);
int minLeft(int x, int a[], int size);
int lowerBound(int key, int a[], int size);
int upperBound(int key, int a[], int size);
long c2(long n);
long mul(long a, long b);
long add(long a, long b);
long sub(long a, long b);

int main()
{
    int test = 1;

    while (test-- > 0)
        solve();

    return 0;
}

void solve()
{
    char s[100000];
    char t[100000];
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    int m = strlen(t);
    int pre[m];
    int suf[m];
    int i, j;
    for (i = 0, j = 0; i < m; i++)
    {
        while (s[j] != t[i])
            j++;
        pre[i] = j++;
    }
    for (i = m - 1, j = n - 1; i >= 0; i--)
    {
        while (s[j] != t[i])
            j--;
        suf[i] = j--;
    }
    int ans = (suf[0] > (n - 1 - pre[m - 1])) ? suf[0] : (n - 1 - pre[m - 1]);
    for (i = 0; i < m - 1; i++)
    {
        int temp = (suf[i + 1] - 1 - pre[i]);
        ans = (temp > ans) ? temp : ans;
    }
    printf("%d\n", ans);
}

int maxRight(int x, int a[], int size)
{
    int l = -1;
    int r = size;

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (a[m] <= x)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l + 1;
}

int minLeft(int x, int a[], int size)
{
    int l = -1;
    int r = size;

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (a[m] < x)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return r + 1;
}

int lowerBound(int key, int a[], int size)
{
    int s = 0;
    int e = size - 1;
    if (e == -1)
    {
        return 0;
    }
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m] >= key)
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return (ans == -1) ? s : ans;
}

int upperBound(int key, int a[], int size)
{
    int s = 0;
    int e = size - 1;
    if (e == -1)
    {
        return 0;
    }
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m] > key)
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return (ans == -1) ? s : ans;
}

long c2(long n)
{
    if ((n & 1) == 0)
    {
        return mul(n / 2, n - 1);
    }
    else
    {
        return mul(n, (n - 1) / 2);
    }
}

long mul(long a, long b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

long add(long a, long b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

long sub(long a, long b)
{
    return ((a % MOD) - (b % MOD)) % MOD;
}
