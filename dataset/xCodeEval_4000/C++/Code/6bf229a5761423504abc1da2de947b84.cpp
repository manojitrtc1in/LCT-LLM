#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<deque>




















	
	
	
	
	
	


	
	


























































































int main() {
	


	


	
	

	


	










	
	
	  
	

	








	














	
	
	

	

	




	
	

	



































long long n, k;
std::cin >> n >> k;
long long l = std::min(n, k);
std::vector<long long> v(n);
for (int i = 0; i < n; ++i)
	std::cin >> v[i];
for (int i = 0; i < l; ++i) {
	if (v[0] > v[1])
	{
		
		int p = v[1];
		for (int j = 1; j < v.size()-1; ++j)
			v[j] = v[j + 1];
		v[v.size() - 1] = p;
	}
	else {
		i = 0;
		int p = v[0];
		for (int j = 0; j < v.size() - 1; ++j)
			v[j] = v[j + 1];
		v[v.size() - 1] = p;
	}
}
std::cout << v[0];



}
