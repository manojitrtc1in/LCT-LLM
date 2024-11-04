































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





















































































#define v   vector 
#define sz(v)  (int)(v.size())
#define pb(a)  push_back(a)
#define each(it,s)  for(auto it = s.begin(); it != s.end(); ++it)
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

















































































































































































int main()
{
    int n, U;
    db kpd=0;
    cin >> n >> U;
    int *E=new int [n];
    rep(i,0,n)
        cin >> E[i];
    
    int now=1;
    rep(i,0,n-2)
    {
        while(now<n && E[now]-E[i]<=U)
            now++;
        if(now==n || E[now]-E[i]>U)
            now--;
        kpd=max(kpd,(double)(E[now]-E[i+1])/(double)(E[now]-E[i]));
    }
    
    if(kpd==0)
        cout << -1;
    else
        cout << fixed << setprecision(10) << kpd;
}