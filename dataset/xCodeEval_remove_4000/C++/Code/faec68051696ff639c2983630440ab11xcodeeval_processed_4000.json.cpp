
 

 
using namespace std;
 

 
typedef long unsigned long ull;

void solve() {
    int n;
    cin >> n;
    ull hp[n], sec[n];
    ull mana = 0;
    for(int i = 0; i < n; i++) {
        cin >> sec[i];
    } 
    for(int i = 0; i < n; i++) {
        cin >> hp[i];
    }
    int nx = n - 1;
    int i = nx;
    while(i >= 0 && nx >= 0) {
        bool flag = false;
        i = nx--;
        mana += (1 + hp[i])*hp[i]/2;
        while(nx >= 0 && i > nx){
            while(nx >= 0 && hp[i] >= sec[i] - sec[nx] + hp[nx]) {
                nx--;
            }
            if(nx < 0 || hp[i] <= sec[i] - sec[nx]){
                break;
            }
            else{
                ull mcl = hp[nx] - hp[i] + sec[i] - sec[nx];
                mana += (hp[i])*mcl + mcl*(mcl + 1)/2;
                for(int j = nx + 1; j <= i; j++) {
                    hp[j] += mcl;
                }
            }
        }
    }
    cout << mana << "\n";
}

int main()
{
    cin.tie(NULL); 

    int k = 1;
    cin >> k;
    while(k--) {
        solve();
    }
    return 0;
}

