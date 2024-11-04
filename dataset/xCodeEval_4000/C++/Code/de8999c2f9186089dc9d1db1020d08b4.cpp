#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<deque>





















	
	
	
	
	
	


	
	





























































int main() {
	


	


	
	

	


	










	
	
	  
	

	








	














	
	
	

	

	




	int n, p = 0;
	std::cin >> n;
	std::stack<char> a, b;
	for (int i = 0; i < n; ++i)
	{
		char ch;
		std::cin >> ch;
		if (ch == '(')
		{
			a.push(ch);
		}
		else
		{
			if (a.empty())
			{
				++p;
				b.push(ch);
			}
			else
			{
				a.pop();
			}
		}
	}
	if (p > 1 || a.size() - b.size() != 0) {
		

		

			

		std::cout << "NO";
	}
	else
		std::cout << "YES";
}
