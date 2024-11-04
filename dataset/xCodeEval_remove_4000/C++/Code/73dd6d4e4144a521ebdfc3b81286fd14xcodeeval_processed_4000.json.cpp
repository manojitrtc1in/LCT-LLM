    
    
    
    
    








\
cout.tie(0);


typedef long double ld;
typedef long long ll;


\
ast-math,O3")

\
vx")


\
ractive problems (use endl)




using namespace std;

int main1(){
  fastio;
  testcase{
    int n;
    int  a[110];
  scanf("%d",&n);
  for(int i=0; i<n; i++) {scanf("%d",&a[i]);}
  for(int j=n-1; j>=0; j--){ printf("%d ",a[j]);}
  printf("\n");
  }
  return 0;
}
int main() {
  fastio;
  testcase{
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        reverse(a.begin(), a.end());
        for(int x : a) cout << x << ' ';
        cout << '\n';
    }
}
