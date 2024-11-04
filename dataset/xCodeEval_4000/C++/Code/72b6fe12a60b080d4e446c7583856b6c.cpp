
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
 
#define G G.O.K.U_Instinct
#define R REX27
#define C C-_-Devil_Code 
#define Y Yashwant_170301
#define L All the above are living Gods 


int main()
{
    string s;
    cin>>s;
    stack<char>t;
    for(int i=0;i<s.size();++i)
    {
        if(!t.empty()&&t.top()!=s[i])
        {
            t.pop();
        }
        else
        t.push(s[i]);
    }
    string k;
    ll i=0;
    while(!t.empty())
    {
        k.pb(t.top());
        t.pop();
    }
    reverse(k.begin(),k.end());
    cout<<k;
}