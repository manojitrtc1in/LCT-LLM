#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
#include<math.h>
#include<fstream>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pii pair<int, int>
#define pllll pair<ll, ll>
#define psll pair<string, ll>
#define qi queue<int>
#define qll queue<ll>
#define si set<int>
#define sll set<ll>
#define mulsi multiset<int>
#define mulsll multiset<ll>
#define mulss multiset<string>
#define msi map<string, int>
#define mss map<string, string>
#define mii map<int, int>
#define ci const int
#define cll const ll
#define cld const long double
#define msii multiset<int> :: iterator
#define mslli multiset<ll> :: iterator
#define sii set<int> :: iterator
#define mslli set<ll> :: iterator


int main() {
	string a;
	string b;
	int n;
	cin >> n;
	cin >> a >> b;
	if (a == "aa") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
	}
	else if (a == "ab") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "a";
		} 
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "a";

		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "bac";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "bac";
			}
		}
	}
	else if (a == "ac") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "a";
		} 
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "a";

		} 

		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
	}

	else if (a == "ba") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "b";

		}

		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "cab";
			}
		}
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "b";

		}

		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
	}
	else if (a == "bb") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
	}
	else if (a == "bc") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";

		} 

		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "b";

		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";

		}

		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
	}
	else 	if (a == "ca") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
	}
	else 	if (a == "cb") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "c";

		}

		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "c";
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";
		}

		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << "a";
			for (int i = 0; i < n; i++)
				cout << "b";
			for (int i = 0; i < n; i++)
				cout << "c";

		} 

		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
	}
	else 	if (a == "cc") {
		if (b == "aa") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ab") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ac") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "ba") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "bc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "ca") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "acb";
			}
		}
		else if (b == "cb") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
		else if (b == "cc") {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << "abc";
			}
		}
	}


}
	
	





