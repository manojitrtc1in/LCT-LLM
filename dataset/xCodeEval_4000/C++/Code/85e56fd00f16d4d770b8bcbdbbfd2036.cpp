













































































































































































































#include <bits/stdc++.h>





#define read_array(arr, len) for (int i = 0; i < len && cin >> arr[i]; i++)
#define read2Darr(arr, row, col) for (int i = 0; i < row; i++) for (int j = 0; j < col && cin >> arr[i][j]; j++)



#define endl "\n"
#define ll long long
#define ull unsigned long long
#define MOD 1'000'000'007
#define INF 2'000'000'000
#define EPS 1e-9
#define PI1 acos(-1)
#define PI2 3.141592653
#define all(s) s.begin(), s.end()
#define for0(n) for(int i = 0; i<n; i++)
#define for1(n) for(int i = 1; i<=n; i++)
#define loop(a, b) for(int i = a; i<b; i++)
#define endl "\n"
#define bloop(a, b) for (int i = a; i>=b; i--)


#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>

#define umsi unordered_map<string, int>
#define umss unordered_map<string, string>
#define umis unordered_map<int, string>
#define umii unordered_map<int, int>
#define usi unordered_set<int>
#define uss unordered_set<string>

#define msi map<string, int>
#define mss map<string, string>
#define mis map<int, string>
#define mii map<int, int>
#define si set<int>
#define ss set<string>

using namespace std;


int test = 1;
vi primes;
vi composite;
vi coprimes[1001];

ll lcm(int a, int b){ ll g = __gcd(a, b); return (a * b) / g;}




















































































































int mid(int n){
  return ceil((double) n  / 2.0);
}



















void phoenix()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> test;
}


void solve(){
  string s;
  cin>> s;
  int totalB = 0;
  int totalA = 0;
  int totalC = 0;
  for (int i =0; i<s.length(); i++){
    if(s[i] == 'A'){
      totalA++;
    }
    else if(s[i] == 'B'){
      totalB++;
    }
    else{
      totalC++;
    }
  }
  if(totalB == totalA + totalC){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

}

int main(){
    phoenix();
    

    

    while (test--)
    {
		solve();
    }
    return 0;
}
