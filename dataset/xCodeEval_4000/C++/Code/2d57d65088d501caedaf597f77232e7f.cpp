
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define pi 3.1415926536
#include <sstream>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int prime_factor(int number)
{
	int count = 0;
	for (int i = 2; i * i <= number; i++)
	{
		while (number % i == 0)
		{
			count++;
			number /= i;
		}
	}
	if (number != 1)
		count++;
	return count;
}

 

ll const N=2e6;
ll a[N];
vector<ll>v;
void print(ll x)
{
    if(x>4444477777 )return;
    v.push_back(x);
    print(x*10+4);
    print(x*10+7);
}




int main()
{
  fast;
 int tc;cin>>tc;
 while(tc--)
 {
     ll x;cin>>x;
     vector<ll>v1,v2;
     for(int i=0;i<2*x;i++){
        cin>>a[i];
     }
     sort(a,a+(2*x));

     for(int i=0;i<x;i++){
        v1.push_back(a[i]);
     }
     for(int i=x;i<2*x;i++){
        v2.push_back(a[i]);
     }
     for(int i=0;i<x;i++){
        cout<<v1[i]<<" "<<v2[i]<<" ";
        }
        cout<<el;

 }

}

  	     	 	 	 		 	   			 						