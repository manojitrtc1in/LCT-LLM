








using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        putchar((i % 4) < 2 ? 'a' : 'b');
}

int main() {
    if(ONLINE_JUDGE) { 

    } else { 

        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
