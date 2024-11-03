
using namespace std;










inline int num1(char k) {return k-'0';}
inline ll num(string s) {ll ans=0;for (int i=s.length()-1;i>=0;i--){ans+=num1(s[i])*pow(10,s.length()-i-1);}return ans;}
int main()
{
    Fast;
    int t;cin>>t;
    while (t--)
    {
        string s;cin>>s;
        s[0]=s[0]-'1'+'0';
        int i=0;
        while (s[i]=='0') i++;
        if (i==s.length()) cout<<0;
        else
        for (int j=i;j<s.length();j++) cout<<s[j];
        cout<<endl;
    }
}
