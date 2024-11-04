















using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll sum = 0;
        for(int i = 0; i < n; i++){
            int zero = 0;
            for(int j = i; j >= 0; j--){
                if(a[j] == 0)
                    zero++;
                sum += i-j+zero+1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}