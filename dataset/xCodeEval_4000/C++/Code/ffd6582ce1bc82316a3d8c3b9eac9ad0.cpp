#include<bits/stdc++.h>
#define fi(i,n) for(i=0;i<n;++i)

using namespace std;



int main()
{
    int n,i,ans=0;
    string s;
    map<char,int> m;
    cin>>n;
    cin>>s;
    i=0;
    while(i<n)
    {
        if(m.count(s[i])==0)
        {
            m[s[i]]=1;
        }
        else{
            m[s[i]]++;
        }
        i++;
    }
    for(auto itr=m.begin();itr!=m.end();++itr)
    {
        ans+=itr->second-1;
    }
    if(ans>26-(n-ans))ans=-1;
    cout<<ans;
    return 0;
}