#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;






























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































int main()
{
	int n,m,i,tmp1,tmp2,col=0,row=0;
	long long sum;
	cin>>n>>m;
	vector<int> locate_x,locate_y,a(100010,1),b(100010,1);
	vector<long long> safe_num(100010,0);
	for (i=0;i<m;++i)
	{
		cin>>tmp1>>tmp2;
		locate_x.push_back(tmp1);
		locate_y.push_back(tmp2);
	}
	sum=(long long)n*n;
	for (i=0;i<m;++i)
	{
		if (a[locate_x[i]]==1)
		{
			sum=sum-n+col;
			a[locate_x[i]]=0;
			++row;
		}
		if (b[locate_y[i]]==1)
		{
			sum=sum-n+row;
			b[locate_y[i]]=0;
			++col;
		}
		safe_num[i]=sum;
	}
	for (i=0;i<m;++i)
	{
		cout<<safe_num[i]<<" ";
	}
	cout<<endl;
	return 0;
}