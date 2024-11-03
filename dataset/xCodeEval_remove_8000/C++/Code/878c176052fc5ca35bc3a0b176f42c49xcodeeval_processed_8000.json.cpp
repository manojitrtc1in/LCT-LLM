
using namespace std;










inline int num1(char k) {return k-'0';}
inline ll num(string s) {ll ans=0;for (int i=s.length()-1;i>=0;i--){ans+=num1(s[i])*pow(10,s.length()-i-1);}return ans;}
int main()
{
    Fast;
    int t;cin>>t;
    while (t--)
    {
        string s;cin>>s;s[0]-='1'-'0';
        while (s[0]=='0'&&s.length()!=1) s.erase(0,1);
        cout<<s<<endl;
    }
}
