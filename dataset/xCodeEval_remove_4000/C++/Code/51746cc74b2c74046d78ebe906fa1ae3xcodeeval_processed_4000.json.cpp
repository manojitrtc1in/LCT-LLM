




using namespace std;













double eps= 0.0000001;




ll fastpower(ll b,ll p){ll ans=1;while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}return ans;}
ll id1(ll b,ll p,ll m){ll ans=1;while(p){if (p%2){ans=((ans%m)*(b%m))%m;}b=((b%m)*(b%m))%m;p/=2;}return ans%m;}
string  id4(ll n){string ans;bool ch=0;if (n<0){n*=-1;ch=1;}if (n==0){ans="0";};while (n){ll mo=n%10;mo+=48;char m=mo;ans=m+ans;n/=10;}if (ch){ans='-'+ans;}return ans;}
ll id0(string s){ll ans=0;for (ll i=0; i<s.size(); i++){if(s[i]!='-'){ll num=s[i]-'0';ans+=(num*fastpower(10,(ll)s.size()-i-1));}}if(s[0]=='-'){return ans*-1;}else {return ans;}}
string id2(ll num){string s;while(num>0){ll m=num%2;char a=m+'0';s=a+s;num/=2;}return s;}
ll id3(string s){ll ans=0;for (ll i=0;i<s.size();i++){if (s[i]=='1'){ans+=fastpower(2,i);}}return ans;}




























bool compare(double f,double s){return  (abs(f-s)<eps);}
ll gcd(ll a,ll b){while(b!=0){ll a2=a;a=b;b=a2%b;}return a;}





const int MAX  = 1000+9;















const int N=5000+10;







ll arr[(int)3e5+10];
vector<ll>v,rid,dri;
ll bs(ll l,ll r,ll val)
{
    ll last=-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if (dri[mid]>=val)
        {
             r=mid-1;
             last=mid;
        }
        else {l=mid+1;}
    }
    return last;
}
int main()
{
 ll n,m;
 cin>>n>>m;

 for (int i=0;i<n+m;i++)
 {

     ll x;
     cin>>x;
     v.push_back(x);

 }

 for (int i=0;i<n+m;i++)
 {

     int t;
     cin>>t;
     if (!t){rid.push_back(v[i]);}
     else {dri.push_back(v[i]);}
}
sort(rid.begin(),rid.end());
sort(dri.begin(),dri.end());
 for (int i=0;i<rid.size();i++)
 {
  ll dis,dis2;
  dis=dis2=1e18;
  ll index=bs(0,dri.size()-1,rid[i]);
  if (index!=-1)
  {
     dis2=dri[index]-rid[i];
     if (index>0)
     {
        dis=rid[i]-dri[index-1];
        if (dis<=dis2)
        {
        arr[index-1]++;
        }
        else {arr[index]++;}
     }
     else {
        arr[index]++;
     }

  }
  else {

    arr[dri.size()-1]++;
  }
  }
 for (int i=0;i<dri.size();i++)
 {

     cout<<arr[i]<<" ";
 }
 return 0;
}