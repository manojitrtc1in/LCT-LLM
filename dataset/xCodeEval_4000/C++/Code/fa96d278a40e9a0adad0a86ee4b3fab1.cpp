






























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

struct resul
{
    int team;
    string name;
    int point=0;
    int per=0;
    int pereh=0;
    int pod=0;
};



int main()
{
    set <string> names;
    vector <string> a;
    int n;
    cin >> n;
    string *s=new string[n];
    for(int i=0;i<n;i++)
        cin >> s[i];
    
    for(int i=n-1;i>=0;i--)
    {
        if(names.find(s[i])==names.end())
        {
            names.insert(s[i]);
            a.push_back(s[i]);
        }
    }
    for(int i=0;i<a.size();i++)
        cout << a[i] << endl;
}
