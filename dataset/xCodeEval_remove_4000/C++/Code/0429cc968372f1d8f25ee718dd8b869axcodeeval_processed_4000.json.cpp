




using namespace std;














double eps= 0.0000001;


int N=50;


ll fastpower(ll b,ll p){ll ans=1;while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}return ans;}
ll id1(ll b,ll p,ll m){ll ans=1;while(p){if (p%2){ans=((ans%m)*(b%m))%m;}b=((b%m)*(b%m))%m;p/=2;}return ans%m;}
string  id4(ll n){string ans;bool ch=0;if (n<0){n*=-1;ch=1;}if (n==0){ans="0";};while (n){ll mo=n%10;mo+=48;char m=mo;ans=m+ans;n/=10;}if (ch){ans='-'+ans;}return ans;}
ll id0(string s){ll ans=0;for (ll i=0; i<s.size(); i++){if(s[i]!='-'){ll num=s[i]-'0';ans+=(num*fastpower(10,(ll)s.size()-i-1));}}if(s[0]=='-'){return ans*-1;}else {return ans;}}
string id2(ll num){string s;while(num>0){ll m=num%2;char a=m+'0';s=a+s;num/=2;}return s;}
ll id3(string s){ll ans=0;for (ll i=0;i<s.size();i++){if (s[i]=='1'){ans+=fastpower(2,i);}}return ans;}
































bool compare(double f,double s){return  (abs(f-s)<eps);}
ll gcd(ll a,ll b){while(b!=0){ll a2=a;a=b;b=a2%b;}return a;}





const int MAX  = 1000+9;















ll h(ll num)
{
    ll b=1;ll m=0;
    while(b<num)
    {
        b*=4;
        m++;
    }
    return m;
}
int main()
{
   time;
   ll n;
   cin>>n;
   ll maxi=0;
   ll ans=0;
   for (int i=0;i<n;i++)
   {
   ll k,a;
   cin>>k>>a;
   maxi=max(k,maxi);
   ll f=h(a);
   ans=max(ans,k+f);

   }
   if (maxi==ans){ans++;}
   cout<<ans;
   return 0;
}
