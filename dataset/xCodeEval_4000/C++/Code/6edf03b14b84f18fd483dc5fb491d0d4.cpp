#include <cstring>
#include <vector>


#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>


using namespace std;

typedef long long ll;

int n,k;
string st;
int b[400000+5];

int main(){
	

	cin>>n>>k;
	cin>>st;
	for(int i = 0;i<26;i++)
		for(int j=0;j<st.size();j++)
			if(st[j] == i+'a'&&k>0){
				k--;
				b[j]=1;
			}
		
	
		for(int i = 0;i<st.size();i++)
			if(b[i] == 0)
				cout<<st[i];
	
	
	
	return 0;
}