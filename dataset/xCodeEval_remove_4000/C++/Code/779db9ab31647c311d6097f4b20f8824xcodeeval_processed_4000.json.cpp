






using namespace std;

typedef pair<int, int> PII;
typedef pair<char, int> PCI;
const double eps = 1e-4;
const int N = 200010;
 
int n, q, T;
char s[N];
PCI p[N];

bool cmp(PCI a, PCI b) {
    return a.y < b.y;
}

int main()
{ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> s;
        cin >> n;
        int len = strlen(s), sum = 0;
        for (int i = 0; i < len; i++) {
            p[i].x = s[i];
            p[i].y = i;
            sum += s[i] - 'a' + 1;
        }

        sort(p, p + len);
        while (sum > n) {
            len--;
            sum -= p[len].x - 'a' + 1;
        }

        sort(p, p + len, cmp);
        for (int i = 0; i < len; i++)
            cout << p[i].x;
        cout << endl;
    }
    return 0;
}
    



