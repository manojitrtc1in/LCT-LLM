




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







string findSum(string str1, string str2)
{
    

    

    if (str1.length() > str2.length())
        swap(str1, str2);

    

    string str = "";

    

    int n1 = str1.length(), n2 = str2.length();

    

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        

        

        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        

        carry = sum/10;
    }

    

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    

    if (carry)
        str.push_back(carry+'0');

    

    reverse(str.begin(), str.end());

    return str;
}
int arr[2000+10];
int main()
{
     

     int n,m,k;
     cin>>n>>m>>k;
     vector<int>ans;
     int have=0;
     for (int i=0;i<n+m;i++)
     {
         while(have<k)
         {
         arr[i+n-1]--;
         have++;
         ans.push_back(i+1);
         }
         have+=arr[i];
         if (!have)
         {
          ans.push_back(i+1);
          have++;
          arr[i+n-1]--;
         }
     }
     cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
