 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define mp make_pair
#define pb push_back
#define all(n) (n).begin,(n).end
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

int n,m;
priority_queue<ll> q;
int a[500005],l[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>l[i];
	for(int i=1;i<=n;i++)
	{
		while(!q.empty() and -q.top() <=a[i])
		q.pop() ;
		if(q.size() <m)
		{
			ll ans=a[i]+l[i];
			cout<<ans<<endl;
			q.push(-ans); 
		}
		else
		{
			ll ans=-q.top() +l[i];
			cout<<ans<<endl;
			q.pop() ;
			q.push(-ans); 
		}
	}
	return 0;
}
