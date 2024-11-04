




using namespace std;















double eps=1e-9;
double pi=acos(-1);


ll fastpower(ll b,ll p)
{
    ll ans=1;
    while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}
    return ans;
}

ll id0(ll b,ll p,ll m)
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
string  id1(ll n)
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
ll sumo[sz];
ll sumt[sz];
int main()
{
     

    

    

      time;
     

     ll n;
     cin>>n;

     for (int i=0;i<n;i++)
     {
         ll x;
         cin>>x;
         if (x==1)
         {
           sumo[i]+=1;
           if (i>0){sumo[i]+=sumo[i-1];}
         }
         else {
            sumt[i]+=1;
            if (i>0){sumt[i]+=sumt[i-1];}
         }
     }
     ll maxi=0;
     for (int i=1;i<n;i++)
     {
        if (!sumo[i]){sumo[i]=sumo[i-1];}
        if (!sumt[i]){sumt[i]=sumt[i-1];}
     }
     for (int i=0;i<n;i++)
     {
         maxi=max(min(sumo[i],sumt[i])*2,maxi);
     }
     cout<<maxi;
     return 0;

}
