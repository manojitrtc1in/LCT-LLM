#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































int row[1010]={0},col[1010]={0};
char symb[1010][1010]={0},signal[1010][1010]={0};
int main()
{
	int n,m,num=0,sum_row=0,sum_col=0;
	cin>>n>>m;
	
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			cin>>symb[i][j];
			if (symb[i][j]=='*')
			{
				++row[i];
				++col[j];
				signal[i][j]=1;
				++num;
			}
		}
	}
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if ((row[i]+col[j]-signal[i][j])==num)
			{
				cout<<"YES"<<endl;
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;

}