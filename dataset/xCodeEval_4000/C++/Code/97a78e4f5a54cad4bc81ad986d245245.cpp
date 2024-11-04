




















#include <iostream>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace::std;

#define lli long long int



#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>

#define vpl vector<pair<long long,long long>>

#define pb push_back

#define all(v) (v).begin(),(v).end()
#define rall(a) (a).rbegin(), (a).rend()



#define si set<int>
#define sl set<long long>
#define ss set<string>



#define mii map<int,int>
#define mll map<long long,long long>
#define mss map<string,string>
#define msi map<string,int>
#define mis map<int,string>
#define msl map<string,long long>
#define mls map<long long,string>



#define pi pair<int,int>
#define pl pair<long long,long long>

#define fi first
#define se second




#define pie (3.141592653589)




#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))




#define maxar *max_element
#define minar *min_element




#define gcd2(a,b) __gcd(a,b)
#define lcm2(a,b) ((a*b)/(__gcd(a,b)))

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)





































 



int main()
{
    lli t,i,j;
    cin>>t;
    
    while (t--)
    {
        lli n,count=0,c1=0,x,y,z;
        cin>>n;
        
        lli a[n];
        
        for (i=0; i<n; i++)
            cin>>a[i];
    
        
        
        
        for (i=0; i<n; i++)
        {
            count+=(a[i]-1);
        }
        
        
        if (count%2==0)
        {
            cout << "maomao90" << endl;
            
        }
        else
            cout << "errorgorn" << endl;
    }
}


