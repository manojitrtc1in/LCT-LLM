#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<deque>





















	
	
	
	
	
	


	
	

















































































int main() {
	


	


	
	

	


	










	
	
	  
	

	








	














	
	
	

	

	




	
	

	int n, m,sum = 0;
	std::cin >> n >> m;
	std::vector<std::string> po(n);
	for (int i = 0; i < n; ++i) { 
		std::cin >> po[i];
	}
	for (int i = 0; i < m; ++i) { 
		std::string s;
		std::cin >> s;
		for (int j = 0; j < n; ++j)
			if (po[j] == s) {
				++sum;
				break;
			}
	}
	if (n - sum / 2 > m - sum / 2 - sum % 2)
		std::cout << "YES";
	else
		std::cout << "NO";
}
