
using namespace std;

const int N = 300009;
typedef long long ll;

int a[N],b[N];

ll m = 1000000999;

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin>> a[i];
    for(int i = 1;i <= n;i++){
        if(a[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
        if(i - 1 > n - i){
            b[i] = min(a[i],a[1]) / (i - 1);
        }
        else if(i - 1 < n - i){
            b[i] = min(a[i],a[n]) / (n - i);
        }
        else{
            b[i] = min(min(a[i],a[1]) / (i - 1),min(a[i],a[n]) / (n - i));
        }
        if(b[i] == 0){
            cout << 0 << endl;
            return 0;
        }
        if(m > b[i]){
            m = b[i];
        }
    }
    cout << m << endl;
    return 0;
}


























































































