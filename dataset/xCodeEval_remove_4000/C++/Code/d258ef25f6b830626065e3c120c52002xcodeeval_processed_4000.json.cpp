
using namespace std;

int aa1,ab1,ac1,ba1,bb1,bc1,ca1,cb1,cc1;
int aa2,ab2,ac2,ba2,bb2,bc2,ca2,cb2,cc2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	cout<<"YES"<<endl;
	if(s1 == "aa")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"ac";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"ab";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"ac";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"ca";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"ab";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"ba";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
	}
	if(s1 == "ab")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"ac";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"bc";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"ca";
		}
	}
	if(s1 == "ac")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"ab";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"bc";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"bc";
		}
	}
	if(s1 == "ba")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"ac";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"cb";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"ca";
		}
	}
	if(s1 == "bb")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"bc";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"cb";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"cb";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"ab";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"cb";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"ba";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
	}
	if(s1 == "bc")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"ab";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"ab";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"ba";
			for(int i=0;i<n;i++)cout<<"c";
		}
	}
	if(s1 == "ca")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"ab";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"ab";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"bc";
		}
	}
	if(s1 == "cb")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"ab";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"ab";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
			for(int i=0;i<n;i++)cout<<"c";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"c";
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"ca";
			for(int i=0;i<n;i++)cout<<"b";
		}
	}
	if(s1 == "cc")
	{
		if(s2 == "aa")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
		if(s2 == "ab")
		{
			for(int i=0;i<n;i++)cout<<"ac";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ac")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"bc";
		}
		if(s2 == "ba")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"cb";
		}
		if(s2 == "bb")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
		if(s2 == "bc")
		{
			for(int i=0;i<n;i++)cout<<"ca";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "ca")
		{
			for(int i=0;i<n;i++)cout<<"a";
			for(int i=0;i<n;i++)cout<<"bc";
		}
		if(s2 == "cb")
		{
			for(int i=0;i<n;i++)cout<<"ca";
			for(int i=0;i<n;i++)cout<<"b";
		}
		if(s2 == "cc")
		{
			for(int i=0;i<n;i++)cout<<"abc";
		}
	}
	cout<<endl;
	return 0;
}