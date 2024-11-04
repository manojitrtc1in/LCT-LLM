

#include<bits/stdc++.h>



using namespace std;
typedef long long int ll;
bool isPrime(ll n) 
{  if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}

int main() {
ll t;
cin>>t;
while(t--)
    {ll n;
     cin>>n;
     string str;
     cin>>str;
     char a[n];
     ll k=0;
     for(ll i=0;i<str.length();i=i+2)
        {

         a[k]=str[i];
         k++;
        }
     for(ll i=0;i<n;i++)
        {cout<<a[i]<<"";}
     cout<<"\n";    
     
    }
	return 0;
}
