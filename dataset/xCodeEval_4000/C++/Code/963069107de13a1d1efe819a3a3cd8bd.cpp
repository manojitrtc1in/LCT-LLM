















































#include<bits/stdc++.h>

using namespace std;






#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double eps = 1e-7;




const int N = 2e5 + 5, M = 3e5 + 5;
int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
}

bool isSubSequence(string s1, string s2, int m, int n)
{
      int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (s1[j] == s2[i])
            j++;
    return (j == m);
}
int mex(vector<int> v)
{   int m=0;
    for(int i=0;i<v.size();i++)
  {
     if(v[i]==m)
     {
          m++;
     }
  }
  return m;
}
bool ispower(ll n)
{
   if(n==0)
   return false;
   return (ceil(log2(n)) == floor(log2(n)));
}
void findstring(vector<pair<string,string>>& v,string s1,string s2)
{
    if(s1.size()==18 && s2.size()==18)
    {
        return;
    }
     v.push_back(make_pair(s1,s2));
     findstring(v,'1'+s1,'1'+s2);
    findstring(v,'0'+s1,'0'+s2);
}
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
void test() {
ll n;
cin>>n;
vector<int> v(n);
map<ll,int> mp;
ll s=0;
for(int i=0;i<n;i++)
{cin>>v[i];
s+=v[i];
mp[v[i]]++;}


if(s%n==0 && mp[s/n]!=0)
cout<<"YES\n";
else
cout<<"NO\n";


}
int main() {
    fast
    int cases = 1;
   cin >> cases;
    while (cases--)
        test();
}










