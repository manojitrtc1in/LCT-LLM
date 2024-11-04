
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
long long a, b, x, dif;

using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		
		cin >> a >> b >> x;
		bool sw = true;
		while (a != 0 && b != 0)
		{
				if (max(a,b) >= x && (max(a,b) - x) % min(a,b) == 0)
				{
					cout << "YES" << endl; 
					sw = false;
					break;
				}
				if (a > b)
					a = a % b;
				else
					b = b % a;
		}
		if(sw)
		cout << "NO" << endl;
	}
}

