#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<deque>




















	
	
	
	
	
	


	
	


























































































int main() {
	


	


	
	

	


	










	
	
	  
	

	








	














	
	
	

	

	




	
	

	






























int p = 0;
std::string s, a;
std::cin >> s;
a = s[0];
for (int i = 1; i < s.size(); ++i) {
	a.push_back(s[i]);
	

	
	if (a.size()-1 && a[a.size() - 1] == a[a.size() -2])
		{
			++p;
			a.pop_back();
			a.pop_back();
		}


}
if (p % 2 == 1)
std::cout << "YES";
else
std::cout << "NO";









}