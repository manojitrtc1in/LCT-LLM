





using namespace std;
typedef long long ll;


int getint() { int x; scanf("%d", &x); return x; }

int pr[P], npr;
bool is_pr[P+1];
int sieve() {
    int i, j, d;
    for (i = 3; i <= P; i += 2) is_pr[i] = 1; is_pr[2] = 1;
    for (i = 3; i * i <= P; i += 2) if (is_pr[i]) {
        for (j = i * i, d = i << 1; j <= P; j += d) is_pr[j] = 0;
    }
    for (i = 2; i <= P; i++) if (is_pr[i]) pr[npr++] = i;
    return npr;
}

const int B = 92;
int id0(int c) { if (c >= 92) c--; if (c >= 34) c--; c -= 33; return c; }
ll decode(string s) { ll res = 0, t = 1; for (int i = 0; i < s.size(); i++) res += t * id0(s[i]), t *= B; return res; }

const char *s = "

vector<string> split_string(string str, string delim = "") {
    vector<string> res;
    for (int i = 0; i < (int)str.size(); i++) if (delim.find(str[i]) != string::npos) str[i] = ' ';
    stringstream ss(str);
    while (ss >> str) res.push_back(str);
    return res;
}

vector<string> a;
vector<int> b;

int main () {
    int i, j, tcc, tc = getint();
    sieve();
    a = split_string(s);
    for (i = 0; i < a.size(); i++) {
        b.push_back(decode(a[i]));
    }

    for (tcc = 0; tcc < tc; tcc++) {
        int p = getint();
        for (i = 0; i < npr; i++) {
            if (pr[i] == p) break;
        }
        printf("%d\n", b[i]);
    }
    return 0;
}


