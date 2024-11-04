


























































































































































































































































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
