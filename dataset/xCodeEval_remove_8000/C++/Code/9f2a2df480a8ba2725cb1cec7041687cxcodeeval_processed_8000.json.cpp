
	

    

























using namespace std;

void id0(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

const ll N = 1e+3 + 333;
const ll M = 998244353;
const ll INF = 1e+5 + 1;

void SOLVE(){
    string word;
    cin >> word;
    int n = word.size();
    if(n <= 2) {
        cout << word << "\n";
        return;
    }
    for(int i = 1; i < n; i++) {
        if(word[i] != word[i - 1]) {
            bool s;
            word[0] == '1' ? s = 1 : s = 0;
            n *= 2;
            for(int i = 0; i < n; i++) {
                if(s && i % 2)cout << 0;
                else if(s && i % 2 == 0) cout << 1;
                else if(!s && i % 2)cout << 1;
                else if(!s && i % 2 == 0)cout << 0;
            }
            break;
        }
        else if(i == n - 1) {
            cout << word;
        }
    }
    cout << "\n";
}

int main() {
    id0();
    int t = 1;
    cin >> t;
    while(t--) {
        SOLVE();
    }
    return 0;
}
