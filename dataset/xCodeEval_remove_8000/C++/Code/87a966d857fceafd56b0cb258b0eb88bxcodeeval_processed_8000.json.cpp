

















using namespace std;




string a;

int main()
{
	cin>>a;
	int con = 1;
	long long res = 1;
	
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i]-'0'+a[i-1]-'0' == 9)
		{
			con++;
		}
		else
		{
			if (con > 1 && con%2!=0)
			{
				res*=(con+1)/2;
			}
			con = 1;
		}
	}
	if (con > 1 && con %2 != 0)
	{
		res*=(con+1)/2;
	}
	cout<<res<<endl;


}

