

































































































































































































































































































































































































































































































































































































































































































































































































































































































#include "cstdio"
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct node {
	int num;
	int val;
};
bool cmp(node a, node b)
{
	if (a.num == b.num){
		return a.val < b.val;
	}
	return a.num < b.num;
}
int main(){
	int n;
	int m;
	

	vector<node>a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		node temp;
		scanf("%d", &temp.num);
		temp.val = 1;
		a.push_back(temp);

	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		node temp;
		scanf("%d", &temp.num);
		temp.val = 2;
		a.push_back(temp);

	}
	sort(a.begin(), a.end(), cmp);
	long long sum1 = 3 * n;
	long long sum2 = 3 * m;
	long long temp1 = sum1;
	long long temp2 = sum2;
	long  long max = sum1 - sum2;
	for (int i = 0; i < n + m; i++){

		if (a[i].val == 1)
		{
			temp1--;
			if (temp1 - temp2>max)
			{
				sum1 = temp1;
				sum2 = temp2;
				max = sum1 - sum2;
			}
		}
		if (a[i].val == 2)
		{
			temp2--;
			if (temp1 - temp2>max)
			{
				sum1 = temp1;
				sum2 = temp2;
				max = sum1 - sum2;
			}
		}
	}
	cout << sum1 << ":" << sum2 << endl;




	return 0;
}