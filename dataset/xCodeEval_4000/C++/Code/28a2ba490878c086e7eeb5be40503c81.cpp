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
#define F first
#define S second




double eps= 0.0000001;




ll fastpower(ll b,ll p){ll ans=1;while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}return ans;}
ll fastpowermod(ll b,ll p,ll m){ll ans=1;while(p){if (p%2){ans=((ans%m)*(b%m))%m;}b=((b%m)*(b%m))%m;p/=2;}return ans%m;}
string  makeitstring(ll n){string ans;bool ch=0;if (n<0){n*=-1;ch=1;}if (n==0){ans="0";};while (n){ll mo=n%10;mo+=48;char m=mo;ans=m+ans;n/=10;}if (ch){ans='-'+ans;}return ans;}
ll makeitnumber(string s){ll ans=0;for (ll i=0; i<s.size(); i++){if(s[i]!='-'){ll num=s[i]-'0';ans+=(num*fastpower(10,(ll)s.size()-i-1));}}if(s[0]=='-'){return ans*-1;}else {return ans;}}
string makeitbinarystring(ll num){string s;while(num>0){ll m=num%2;char a=m+'0';s=a+s;num/=2;}return s;}
ll makeitnumberbinarynumber(string s){ll ans=0;for (ll i=0;i<s.size();i++){if (s[i]=='1'){ans+=fastpower(2,i);}}return ans;}
































bool compare(double f,double s)
{
 return  (abs(f-s)<eps);
}
ll gcd(ll a,ll b){while(b!=0){ll a2=a;a=b;b=a2%b;}return a;}





const int MAX  = 1000+9;















vector<int>pos[26];
int bs(vector<int>&v,int val)
{
    int last=-1;
   int l=0;
    int r=v.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (v[mid]>=val)
        {
            last=mid;
            r=mid-1;
        }
        else {l=mid+1;}
    }
    return v[last];

}

int main()
{
   time;
  string s1,s2;

  cin>>s1>>s2;
  for (int i=0;i<s1.size();i++)
  {
      pos[s1[i]-'a'].push_back(i);
  }
  int j=0;
  int ans=1;
  for (int i=0;i<s2.size();i++)
  {
      if (pos[s2[i]-'a'].size()==0){cout<<" "<<-1;return 0;}

      if (pos[s2[i]-'a'].back()<j)
      {
          j=0;
          ans++;
      }
      j=bs(pos[s2[i]-'a'],j)+1;
  }
  cout<<ans;
   return 0;
}
