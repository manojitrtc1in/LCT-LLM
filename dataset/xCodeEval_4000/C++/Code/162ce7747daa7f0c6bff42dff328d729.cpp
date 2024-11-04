






























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



























































































int main()
{
    
    
    
    int n,k[4]={};
    cin >> n;
    char c;
    for(int z=0;z<4;z++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin >> c;
                if(j%2==i%2 && c=='0') k[z]++;
                if(j%2!=i%2 && c=='1') k[z]++;
            }
    sort(k,k+4);
    
    cout << k[0]+k[1]+2*n*n-k[2]-k[3];
}