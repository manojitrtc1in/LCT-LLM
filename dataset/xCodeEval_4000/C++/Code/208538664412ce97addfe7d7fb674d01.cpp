#include<bits/stdc++.h>




using namespace std;
#define time ios_base::sync_with_stdio(0);cin.tie(0);
#define dpp(arr,val) memset(arr,val,sizeof (arr))
#define ll long long
#define ull unsigned long long
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair




double eps=1e-9;
double pi=acos(-1);


ll fastpower(ll b,ll p)
{
    ll ans=1;
    while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}
    return ans;
}

ll fastpowermod(ll b,ll p,ll m)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=((ans%m)*(b%m))%m;
        }
        b=((b%m)*(b%m))%m;
        p/=2;
    }
    return ans%m;
}
string  makeitstring(ll n)
{
    string ans;
    bool ch=0;
    if (n<0)
    {
        n*=-1;
        ch=1;
    }
    if (n==0)
    {
        ans="0";
    };
    while (n)
    {
        ll mo=n%10;
        mo+=48;
        char m=mo;
        ans=m+ans;
        n/=10;
    }
    if (ch)
    {
        ans='-'+ans;
    }
    return ans;
}












bool checksqrt(ll f){ll num=sqrt(f);return (num*num==f);}














bool compare(double f,double s)
{
    return  (abs(f-s)<eps);
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}





























const int N=1e6+1;






const int sz=1e6;
int main()
{
     

    

    

      time;
     

     ll n;
     cin>>n;
   vector<ll>clown,acrobate,none,both;
   string s1,s2;
   cin>>s1>>s2;
     for (int i=0;i<n;i++)
     {
       if (s1[i]==s2[i]){
        if (s1[i]=='0'){none.push_back(i+1);}
        else {both.push_back(i+1);}
       }
       else if (s1[i]=='1')
       {
           clown.push_back(i+1);
       }
       else if(s2[i]=='1'){
        acrobate.push_back(i+1);
       }
     }
     ll Ac=clown.size();
     ll Ab=both.size();
     ll Aa=acrobate.size();
     ll An=none.size();
     

     

     

     ll caneeded=-1;
     ll nneeded=-1;
     ll bneeded=-1;
     for (int no=An;no>=0;no--)
     {
         ll b=n/2-Aa-Ab-no;
            b*=-1;
         ll ca=Aa+Ab-2*b;
         if (b>=0&&ca>=0&&b<=Ab&&Ac+Aa>=ca&&ca+b+no==n/2&&ca+2*b==Aa+Ab&&no-b==n/2-Aa-Ab)
         {

            bneeded=b;
            caneeded=ca;
            nneeded=no;
       

             break;
         }
     }
     if (bneeded<0||caneeded<0||nneeded<0){cout<<-1;return 0;}
     ll aneeded=-1;
     ll cneeded=-1;
     for (int a=0;a<=Aa;a++)
     {
         ll c=caneeded-a;
         if (c<=Ac&&c+a<=caneeded){
            aneeded=a;
            cneeded=c;
            break;

         }

     }
     if (cneeded<0||aneeded<0){cout<<-1;return 0;}
     for (int i=0;i<aneeded;i++)
     {
         cout<<acrobate[acrobate.size()-1]<<" ";
         acrobate.pop_back();
     }
     for (int i=0;i<cneeded;i++)
     {
         cout<<clown[clown.size()-1]<<" ";
         clown.pop_back();
     }
     for (int i=0;i<nneeded;i++)
     {
         cout<<none[none.size()-1]<<" ";
         none.pop_back();
     }

     for (int i=0;i<bneeded;i++)
     {
         cout<<both[both.size()-1]<<" ";
         both.pop_back();
     }
     return 0;

}
