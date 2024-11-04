#include<bits/stdc++.h>
using namespace std;







































































































































 



#define ll long long
using namespace std;
int i,j,k,n,m,T;
int lowbit(int x){
	return x&(-x);
}

bool at_position(long long int num,long long int pos)
{
    bool bit = num & (1<<pos);
    return bit;
}

bool isPowerOfTwo(long long int n)
{
   if(n==0)
    return false;
   return (ceil(log2(n)) == floor(log2(n)));
}
 
 
void solve()
{
    long long int n;
    cin>>n;
    if(n == 1)
    {
        cout<<"3"<<"\n";
        return;
    }
    if(n % 2 == 1)
    {
        cout<<"1"<<"\n";
        return;
    }
    if(isPowerOfTwo(n) == true)
    {
        cout<<(n+1)<<"\n";
        return;
    }
    cout<<lowbit(n)<<"\n";
}
 
  
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

