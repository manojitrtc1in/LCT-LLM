
#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<list>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<iterator>
#include<time.h> 
#include<sstream>
using namespace std;
int main() { 
	int t;
	string s;
	cin >> t;
	char o = '1',z='0';
	while (t--)
	{
    bool sw = true,l=true;
	int found = -1, count = 0;
		cin >> s;
		while (l)
		{
			if (sw)
			{
				found = s.find(z, found + 1);
				count++;
				if (found == string::npos)
				{
					count--;
					break;
				}
					
					sw = false;
			}
			else
			{
				found = s.find(o, found + 1);
				if (found == string::npos)
				{
					break;
				}
				sw = true;
			}
			if (count >= 2)
			{
				cout << 2 << endl;
				l = false;
			}

		}
		if (l)
			cout << count << endl;
	}

}
