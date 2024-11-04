#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <error.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <conio.h>
#include <numeric>
#include <list>
#include <windows.h>
#include <cfloat>
#include <climits>
#include <tuple>
using namespace std;
















































































































































































































































































































































































































































































































































int n;
string a;
bool check(string s)
{
	for(int j=1;a[j];j++)
		if(!isdigit(a[j]) && !isdigit(a[j-1]))
			return false;
	for(int j=1;a[j];j++)
		if(!isdigit(a[j]))
			return true;
	return false;
}
void type1(string s)
{
	int r=0,c=0;
	for(int i=0;i<s.size();i++)
	{
		if(!isdigit(a[i]))
			c=c*26+(a[i]-'A'+1);
		else
			r=r*10+(a[i]-'0');
	}
	cout<<"R"<<r<<"C"<<c<<endl;
}
void type2(string s)
{
	int i=1;
	while(isdigit(s[i]))	i++;i--;
	string No1=s.substr(1,i);
	i+=2;
	string No2=s.substr(i,s.size()-i),C;
	int No11=atoi(No2.c_str());
	int mmm=No11;
	

	int j;
	for(j=0;No11!=0;j++){
		

		if(No11%26!=0)	C[j]=char('@'+No11%26),No11/=26;
		else	C[j]='Z',No11/=26,No11--;
		

	}
	for(int k=j-1;k>=0;k--)	cout<<C[k];
	cout<<No1<<endl;

}
int main()
{
	cin>>n;
	for(int cnt=0;cnt<n;cnt++)
	{
		cin>>a;
		if(!check(a))
		{
			type1(a);
		}
		else
		{
			type2(a);
		}
	}
	return 0;
}
