#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include<vector>
#include<map>
#include<deque>
#include<list>
using namespace std;
int main()
{
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int i=0;
		for(i;i<n-(n+3)/4;i++){
			cout<<9;
		}
		for(i;i<n;i++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}







