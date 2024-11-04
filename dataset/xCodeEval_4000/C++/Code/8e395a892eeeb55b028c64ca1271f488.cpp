                                        

#include"bits/stdc++.h"
using namespace std;
#define ll long long 
#define f(i,a,n) for(ll i=a;i<n;++i)
#define mll multiset<ll>
#define slb(a) s.lower_bound(a)
#define sei(a) s.erase(a)
#define haa cout<<"Yes"
#define naa cout<<"No"

 
 void printBinary(int num)
    {
        for(int i=10;i>=0;--i)
        {
            cout<<((num>>i)&1);
        }
        

    }

bool isPerfectSquare(long double x)

    {
        
        if (x >= 0) {
    
            long long r = sqrt(x);
            

            return (r * r == x);
        }
        
        return false;
    }


bool pot(long long int n)

    {
    if(n>0) {
        while(n%2 == 0) {
            n/=2;
        }
        if(n == 1) {
            return true;
        }
    }
    if(n == 0 || n != 1) {
        return false;
    }
    return true;
    }

    


    bool isPrime(int n)
    {

        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    


void merge(int arr[],int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    int temp[5];
    while(i<=m and j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            k++;i++;
        }
        else
        {
            temp[k]=arr[j];
            k++; j++;
        }
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        i++; k++;
    }
    while (j<=r)
    {
        temp[k]=arr[j];
        j++; k++;
    }

    for(int i=l;i<=r;++i)
    {
        arr[i]=temp[i];
    }
    
}
void mergesort(int arr[],int l ,int r)
    {
        if(l<r)
        {
            int m=(l+r)/2;
            mergesort(arr,l,m);
            mergesort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }



int gcd(ll a, ll b)

        {
            if(b==0)
            return a;
            else
            return gcd(b,a%b);
        }

int lcm(int a,int b)

        {
            return a*b/gcd(a,b);
        }

int factorial(int n)

        {

            return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
        }

bool palin(ll n)
{

string s=to_string(n);
string t=s;
reverse(t.begin(),t.end());
if(s==t)
{
return true;
}
else return false;
}







void monkey9000()
{
    


ll n; cin>>n;
vector<ll>v(n);
f(i,0,n){cin>>v[i];}

sort(v.begin(),v.end());
ll minvalue=(2*v[0]); ll ans=0;
f(i,0,n)
{
ans+=(v[i]-1)/(minvalue-1);
}

cout<<ans;

























}
int main()

{

 ll testcase; cin>>testcase;
 
 while(testcase--)
 {
    
    monkey9000();
    cout<<endl;






 }


}