








using namespace std;
int n, k;
char mat[1005][1005];

void put(int n1, int n2, char c) {
    mat[n1][n2] = mat[n2][n1] = c;
}

void solve() {

    int s = 0;
    vector<int> pos;
    while (k >> s) {
        if ((k >> s) & 1) {
            pos.push_back(s);
        }
        s++;
    }
    int col = pos[pos.size() - 1];
    n = 3 * col + 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] = 'N';
        }
    }


    for (int i = 0; i < col - 1; i++) {
        int n1 = 3 + (2 * i);
        int n2 = n1 + 1;
        put(n1, n1+2, 'Y');
        put(n1, n2+2, 'Y');
        put(n2, n1+2, 'Y');
        put(n2, n2+2, 'Y');
        put(3 + i + 2 * col, 4 + i + 2 * col, 'Y');
    }

    put(1, 3, 'Y');
    put(1, 4, 'Y');
    put(1 + 2 * col, 2, 'Y');
    if (k!=1) {
    put(2 + 2 * col, 2, 'Y');
    put(2 + 3 * col, 2, 'Y');
    }


    for (int i = 0; i < pos.size() - 1; i++) {
        if (pos[i] == 0) {
            put(1, 3 + 2 * col, 'Y');
        } else {
            int n1 = 3 + 2 * (pos[i] - 1);
            int n2 = n1 + 1;
            int n3 = 3 + (pos[i]) + 2 * col;
            put(n1, n3, 'Y');
            put(n2, n3, 'Y');
        }
    }
}


void print() {
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin >> k;
    solve();
    print();
    return 0;
}

























































