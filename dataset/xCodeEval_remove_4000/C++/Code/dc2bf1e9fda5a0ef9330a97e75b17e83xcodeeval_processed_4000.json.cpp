
































using namespace std;
int main()
{
    int n = 1,count = 0;
  vector <int> myvector;
  int a,b;
  cin >> a;
  for(int i = 1; i <= a; i++){
    cin >> b;
    myvector.push_back(b);
  }
  if(a > 1){
  for(int i = 0; i < a - 1; i++){
    if(myvector[i] < myvector[i + 1]){
        n++;
    }
    else{
        n = 1;
    }
    if(n > count){
        count = n;
    }
  }
  cout << count << endl;
  }
 else{
    cout << n << endl;
 }
}

