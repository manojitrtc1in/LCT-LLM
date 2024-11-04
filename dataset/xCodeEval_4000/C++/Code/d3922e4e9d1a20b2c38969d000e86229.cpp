






























#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <time.h>
using namespace std;





















































































#define vc   vector 
#define sz(v)  (int)(v.size())
#define pb(a)  push_back(a)
#define each(it,s)  for(auto it = s.begin(); it != s.end(); it++)
#define rep(i, b, n)  for(int i = (b); i < (n); i++)
#define all(v)  v.begin(), v.end()
#define FI  first
#define SE  second
#define rr(i,j,n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
#define NO  cout << "NO"
#define YES cout << "YES"
#define ex(n) return n;
typedef long long int lli;
typedef long long ll;
typedef double db;


























































































int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    ll n, m, k, x, y;
    cin >> n >> m >> k;
    ll s = 2 * n * m;
    if (s % k != 0) 
    {
        NO; return 0;
    }
    s /= k;
    y = s / n + (s % n > 0);
    x = y * n - s;
    cout << "YES"<<endl << "0 0"<<endl << n << ' ' << 1 << endl << x << ' ' << y << endl;
}