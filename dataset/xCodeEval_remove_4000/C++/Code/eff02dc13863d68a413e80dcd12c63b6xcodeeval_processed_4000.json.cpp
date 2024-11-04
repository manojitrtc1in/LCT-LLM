







using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

namespace my {
    ii operator+(const ii &a, const ii &b) {return {a.x + b.x, a.y + b.y};}
    ii operator-(const ii &a, const ii &b) {return {a.x - b.x, a.y - b.y};}
    ii operator*(const ii &a, const ii &b) {return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
    ii operator*(const ii &a, const int &b) {return {a.x * b, a.y * b};}
    ii operator/(const ii &a, const int &b) {return {a.x / b, a.y / b};}
    ostream& operator<<(ostream &s, const ii &p) {s << '(' << p.x << ", " << p.y << ')';return s;}
}

using namespace my;

struct Node;
int n, k;
Node *root;

struct Node {
    Node *child[26];
    bool win, lose;
    Node() {
        for(int i = 0;i < 26;i++)
            child[i] = nullptr;
    }
    void push(const string &s, const int &pos) {
        if(pos == s.length())
            return;
        if(child[s[pos] - 'a'] == nullptr)
            child[s[pos] - 'a'] = new Node();
        child[s[pos] - 'a']->push(s, pos + 1);
    }
    void dfs() {
        bool id0 = false;
        for(int i = 0;i < 26;i++)
            if(child[i] != nullptr) {
                child[i]->dfs();
                id0 = true;
            }
        if(id0) {
            win = false;
            lose = false;
            for(int i = 0;i < 26;i++) {
                win |= (child[i] != nullptr && !child[i]->win);
                lose |= (child[i] != nullptr && !child[i]->lose);
            }
        } else {
            win = false;
            lose = true;
        }
    }
};

void solve() {
    root = new Node();
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        root->push(s, 0);
    }
    root->dfs();
    if(!root->win) {
        printf("Second"); 

    } else if(root->win && root->lose) {
        printf("First"); 

    } else { 

        printf("%s", (k % 2 == 1 ? "First" : "Second"));
    }
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
