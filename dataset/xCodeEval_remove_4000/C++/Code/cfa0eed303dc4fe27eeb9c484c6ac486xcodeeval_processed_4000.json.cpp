








using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    string s;
    s = "aabb";
    for(int i = 0;i < 50000;i++)
        s += "aabb";
    cout << s.substr(0, n);
}

int main() {
    if(ONLINE_JUDGE) { 

    } else { 

        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}