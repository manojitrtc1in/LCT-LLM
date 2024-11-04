









using namespace std;

void id20(void) {
    long n;
    short k;
    cin >> n >> k;
    long result = n;
    for (short i = k; i > 0; i--) {
        if (result % 10) {
            result--;
        } else {
            result /= 10;
        }
    }
    cout << result << endl;
}

void id5() {
    int l, b, k;
    cin >> l >> b;
    k = floor(log((double)b / l) / log((double)3 / 2)) + 1;
    cout << k << endl;
}

void id2(void) {
    unsigned int n;
    cin >> n;
    unsigned int result = 0;
    if (n >= 100) {
        result += n / 100;
        n -= ((unsigned int)n / 100) * 100;
    }
    if (n >= 20) {
        result += n / 20;
        n -= ((unsigned int)n / 20) * 20;
    }
    if (n >= 10) {
        result += n / 10;
        n -= ((unsigned int)n / 10) * 10;
    }
    if (n >= 5) {
        result += n / 5;
        n -= ((unsigned int)n / 5) * 5;
    }
    if (n >= 1) {
        result += n;
        n = 0;
    }
    cout << result << endl;
}

void Drinks(void) {
    int n;
    cin >> n;
    vector<int> p(n);
    float result = 0, ratio = 1 / (float)n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        result += ratio * ((float)p[i] / 100);
    }
    result *= 100;
    cout << result << endl;
}

void id13(void) {
    int n;
    cin >> n;
    vector<string> line(n);
    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }
    for (int i = 0; i < n; i++) {
        int length = line[i].size();
        if (length > 10) {
            cout << line[i][0] << length - 2 << line[i][length - 1] << endl;
        } else {
            cout << line[i] << endl;
        }
    }
}

void Bitpp(void) {
    int n;
    cin >> n;
    int x = 0;
    string in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in[1] == '+')
            x++;
        else
            x--;
    }
    cout << x << endl;
}

void id26(void) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    list<int> num;
    int temp, result = 0;
    ;
    while (ss >> temp) {
        num.push_back(temp);
        result += temp;
    }
    num.sort();
    int prev = -1;
    int count = 0;
    priority_queue<int> pq;
    int current = 0;
    while (!num.empty()) {
        if (num.back() == prev) {
            count++;
            if (count < 3)
                current += prev;
        } else {
            if (count) {
                current += prev;
                pq.push(current);
                current = 0;
                count = 0;
            }
        }
        prev = num.back();
        num.pop_back();
    }
    if (count) {
        current += prev;
        pq.push(current);
        count = 0;
    }
    if (!pq.empty())
        result -= pq.top();
    cout << result << endl;
}

bool id24(vector<list<int>> &graph, int target, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> id15;
    id15.push(start);
    visited[start] = true;
    int current;
    while (!id15.empty()) {
        current = id15.top();
        id15.pop();
        if (current == target) {
            return true;
        }
        for (list<int>::iterator i = graph[current].begin();
             i != graph[current].end(); i++) {
            if (visited[*i] == false) {
                id15.push(*i);
                visited[*i] = true;
            }
        }
    }
    return false;
}

void KingEscape(void) {
    int n, ax, ay, bx, by, cx, cy, a, b, c;
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    a = (ax - 1) + (ay - 1) * n;
    b = (bx - 1) + (by - 1) * n;
    c = (cx - 1) + (cy - 1) * n;
    vector<list<int>> KingGraph(n * n);
    int node;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            node = x + y * n;
            if (x == ax - 1 || y == ay - 1 || (x - y) == (ax - ay) ||
                x + y == ax + ay - 2) {
                continue;
            }
            for (int k = max(0, y - 1); k < min(n, y + 2); k++) {
                for (int l = max(0, x - 1); l < min(n, x + 2); l++) {
                    if (l == ax - 1 || k == ay - 1 ||
                        abs(l - k) == abs(ax - ay) || l + k == ax + ay - 2 ||
                        node == l + k * n) {
                        continue;
                    }
                    KingGraph[node].push_back(l + k * n);
                }
            }
        }
    }
    if (id24(KingGraph, c, b))
        cout << "YES\n";
    else {
        cout << "NO\n";
    }
}

void id0(void) {
    int n;
    cin >> n;
    string line;
    cin >> line;
    stack<char> xStack;
    stack<char> yStack;
    for (char c : line) {
        if (c == 'L') {
            if (xStack.empty()) {
                xStack.push('L');
            } else {
                if (xStack.top() == 'R') {
                    xStack.pop();
                } else {
                    xStack.push('L');
                }
            }
        } else if (c == 'R') {
            if (xStack.empty()) {
                xStack.push('R');
            } else {
                if (xStack.top() == 'L') {
                    xStack.pop();
                } else {
                    xStack.push('R');
                }
            }
        } else if (c == 'U') {
            if (yStack.empty()) {
                yStack.push('U');
            } else {
                if (yStack.top() == 'D') {
                    yStack.pop();
                } else {
                    yStack.push('U');
                }
            }
        } else if (c == 'D') {
            if (yStack.empty()) {
                yStack.push('D');
            } else {
                if (yStack.top() == 'U') {
                    yStack.pop();
                } else {
                    yStack.push('D');
                }
            }
        }
    }
    cout << n - (xStack.size() + yStack.size()) << endl;
}

void CableWay(void) {
    int r, g, b; 

    cin >> r >> g >> b;
    int nr = floor(r / 2) + r % 2, ng = floor(g / 2) + g % 2,
        nb = floor(b / 2) + b % 2; 

    int dr, db, dg;                

    dr = (nr - 1) * 3 + 0;
    dg = (ng - 1) * 3 + 1;
    db = (nb - 1) * 3 + 2;
    int time = 30 + max(dr, max(db, dg));
    cout << time << endl;
}

void id18(void) {
    long m;
    int n;
    unsigned long count = 0;
    cin >> n >> m;
    for (int i = 1; i <= min(n, (int)floor(sqrt(m))); i++) {
        int div = m / i;
        if (div <= n && m % i == 0) {
            count += 2;
        }
        if (i * i == m) {
            count--;
        }
    }
    cout << count << endl;
}

int id19(vector<int> arr, int l, int r, int element) {
    int pivot = (l + r) / 2;
    int pick = arr[pivot];
    if (l <= r) {
        if (pick <= element) {
            if (pivot == arr.size() - 1) {
                return pivot;
            }
            if (arr[pivot + 1] > element) {
                return pivot;
            }
            return id19(arr, pivot + 1, r, element);
        }
        return id19(arr, l, pivot - 1, element);
    }
    return -1;
}

void InterestingDrink(void) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<int> map(100001);
    int j = 1;
    for (int i = x.front(); i <= 100000; i++) {
        while (x[j] <= i && j < x.size()) {
            j++;
        }
        map[i] = j;
    }

    int q;
    cin >> q;
    int m;
    for (int i = 0; i < q; i++) {
        cin >> m;
        cout << map[min(100000, m)] << endl;
    }
}

class AVL { 

    class Node {
      public:
        int key;
        Node *left;
        Node *right;
        int height;
    };

  public:
    Node *root;
    int size;
    AVL() {
        root = NULL;
        size = 0;
    }

    

    

    


    

    

    int height(Node *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    

    

    int max(int a, int b) { return (a > b) ? a : b; }

    
    Node *newNode(int key) {
        Node *node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; 

                          

        return (node);
    }

    

    

    

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        

        x->right = y;
        y->left = T2;

        

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        

        return x;
    }

    

    

    

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        

        y->left = x;
        x->right = T2;

        

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        

        return y;
    }

    

    int getBalance(Node *N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    

    

    

    Node *insert(Node *node, int key) {
        
        if (node == NULL) {
            this->size++;
            return (newNode(key));
        }

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else 

            return node;

        
        node->height = 1 + max(height(node->left), height(node->right));

        
        int balance = getBalance(node);

        

        


        

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        
        return node;
    }

    

    

    

    

    void preOrder(Node *root) {
        if (root != NULL) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

void id28() {
    int n, m;
    cin >> n >> m;
    vector<int> id1(n);
    AVL tree = AVL();
    int data;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> data;
        st.push(data);
    }
    for (int i = 0; i < n; i++) {
        tree.root = tree.insert(tree.root, st.top());
        st.pop();
        id1[n - i - 1] = tree.size;
    }

    for (int i = 0; i < m; i++) {
        cin >> data;
        data--;
        cout << id1[data] << endl;
    }
}

void id27(void) {
    int n;
    cin >> n;
    vector<long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long curLength = 0, curMean = 0, maxLength = 0, maxMean = 0;
    long long curSum = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] + curSum) / (curLength + 1) >= curMean) {
            curMean = (arr[i] + curSum) / (curLength + 1);
            curSum += arr[i];
            curLength++;
            if (arr[i] > curMean) {
                curMean = arr[i];
                curSum = arr[i];
                curLength = 1;
            }
        } else {
            curMean = arr[i];
            curSum = arr[i];
            curLength = 1;
        }

        if (curMean >= maxMean) {
            if (curMean == maxMean)
                maxLength = max(curLength, maxLength);
            else {
                maxLength = curLength;
            }
            maxMean = curMean;
        }
    }
    cout << maxLength << endl;
}

void id9(void) {
    int n;
    cin >> n;
    vector<vector<int>> table(100, vector<int>(100, 0));
    int x1, x2, y1, y2;
    long sum = 0;
    for (int k = 0; k < n; k++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1 - 1; x < x2; x++) {
            for (int y = y1 - 1; y < y2; y++) {
                table[x][y]++;
                sum++;
            }
        }
    }
    cout << sum << endl;
}

void id10(void) {
    int n, sum = 0;
    cin >> n;
    vector<int> al(n, 1);
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    int j = 1;
    int a, b;
    int i = 0, previ;
    int c = 1;
    for (i = 1; i < sum; i++) {
        if (i == (n - c + 1)) {
            al[n - c] = 0;
            c++;
        }
        if (n - c) {
            al[(previ - 1) % (n - c)] = 1;
            al[(i - 1) % (n - c)] = 0;
        }
        previ = i;
        a = sum - i;
        b = sum - a;
        if ((int)(__gcd(a, b)) == (float)(__gcd(a, b)) && __gcd(a, b) > 1) {
            break;
        }
    }
    if (i == sum) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << n - c << " ";
        for (int i = 0; i < n; i++) {
            if (al[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl << c << " ";
        for (int i = 0; i < n; i++) {
            if (!al[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

void MaximumControl(void) {
    int n;
    cin >> n;
    vector<int> V(n + 1, 0);
    int v1, v2;
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        V[v1]++;
        V[v2]++;
    }
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (V[i] == 1) {
            count++;
        }
    }
    cout << count << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Subtraction(void) {
    int n;
    cin >> n;
    int a, b, num = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a != max(a, b)) {
            swap(a, b);
        }
        num = 0;
        while (a > 0 && b > 0) {
            if (a != b) {
                num += a / b;
                a = a % b;
                swap(a, b);
            } else {
                b = 0;
                num++;
            }
        }
        cout << num << endl;
    }
}

void id3() {
    int n, temp;
    cin >> n;
    vector<int> inp;
    vector<pair<int, int>> seq;
    list<int> output;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        inp.push_back(temp);
    }
    sort(inp.begin(), inp.end());
    int j = 0;
    seq.push_back(pair<int, int>(inp[0], 1));
    for (int i = 1; i < n; i++) {
        if (inp[i] == seq.back().first) {
            seq.back().second++;
        } else {
            seq.push_back(pair<int, int>(inp[i], 1));
        }
    }
    int m = seq.size();
    output.push_back(seq.back().first);
    seq.back().second--;
    for (int i = m - 1; i >= 0; i--) {
        if (seq[i].second && seq[i].first != output.back()) {
            output.push_back(seq[i].first);
            seq[i].second--;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        if (seq[i].second && seq[i].first != output.front()) {
            output.push_front(seq[i].first);
            seq[i].second--;
        }
    }

    cout << output.size() << endl;
    for (list<int>::iterator i = output.begin(); i != output.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void id11() {
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }
    int max1 = 0, min1 = INT_MAX, max2 = 0, min2 = INT_MAX, sum1 = 0, sum2 = 0;
    int id17, id14, id4, id22;
    for (int i = 0; i < n; i++) {
        sum1 += arr[i];
        if (arr[i] < min1) {
            min1 = arr[i];
            id17 = i;
        }
        if (arr[i] > max1) {
            max1 = arr[i];
            id4 = i;
        }
    }
    for (int i = n; i < 2 * n; i++) {
        sum2 += arr[i];
        if (arr[i] < min2) {
            min2 = arr[i];
            id14 = i;
        }
        if (arr[i] > max2) {
            max2 = arr[i];
            id22 = i;
        }
    }
    if (min1 == max2 && min2 == max1) {
        cout << -1 << endl;
        return;
    }
    if (sum1 == sum2)
        if (min1 != max2) {
            swap(arr[id17], arr[id22]);
        } else if (min2 != max1) {
            swap(arr[id14], arr[id4]);
        }
    for (int i = 0; i < 2 * n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isOdd(int n) {
    if (n % 2 == 0) {
        return false;
    }
    return true;
}

void id23(void) {
    int n;
    cin >> n;
    vector<int> arr(n);
    int nOdd = 0, nEven = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (isOdd(arr[i])) {
            nOdd++;
        } else {
            nEven++;
        }
    }
    if (min(nOdd, nEven)) {
        sort(arr.begin(), arr.end());
    }
    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void id7() {
    int n, l;
    cin >> n >> l;
    vector<int> id12(n);
    for (int i = 0; i < n; i++) {
        cin >> id12[i];
    }
    sort(id12.begin(), id12.end());
    int i = 1, prev = 0;
    double maxDis = 0, diff;
    if (id12[0] != 0) {
        maxDis = id12[0];
        prev = id12[0];
    }
    for (; i < n; i++) {
        diff = ((double)(id12[i] - prev) / (double)2);
        if (diff > maxDis) {
            maxDis = diff;
        }
        prev = id12[i];
    }
    i--;
    if (id12[i] < l) {
        diff = ((double)(l - id12[i]));
        if (diff > maxDis) {
            maxDis = diff;
        }
    }
    cout << setprecision(9) << (double)maxDis << endl;
}

void id16() {
    int n;
    cin >> n;
    vector<int> pN(n);
    for (int i = 0; i < n; i++) {
        cin >> pN[i];
    }
    int max = 1, current = 1;
    int prev = pN[0];
    for (int i = 1; i < n; i++) {
        if (prev * 2 >= pN[i] && pN[i] > prev) {
            current++;
        } else {
            if (current > max) {
                max = current;
            }
            current = 1;
        }
        prev = pN[i];
    }
    if (current > max) {
        max = current;
    }
    cout << max << endl;
}

void id25() {
    string n;
    cin >> n;
    bool flag = true;
    for (string::iterator it = n.begin(); it != n.end(); it++) {
        if (*it == '0') {
            n.erase(it);
            flag = false;
            break;
        }
    }
    if (flag) {
        n.erase(n.begin());
    }

    cout << n << endl;
}

void id29() {
    int n;
    cin >> n;
    vector<int> price(n + 1);
    vector<bool> prime(n + 1, true);
    vector<int> color(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        price[i] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; price[j] <= (int)sqrt(price[i]); j++) {
            if (price[i] % price[j] == 0) {
                if (prime[j]) {
                    prime[i] = false;
                    if (color[i] == color[j]) {
                        color[i]++;
                    }
                }
            }
        }
    }
    int c = 2;
    if (n < 3) {
        c--;
    }
    cout << c << endl;
    for (int i = 1; i < n + 1; i++) {
        cout << color[i] << " ";
    }

    cout << "\n";
}

int id21(string &str1, string &str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    } else if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1; 

}



string id6(string first, string second) {
    string result; 


    

    int length = id21(first, second);

    int carry = 0; 


    

    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        

        int sum = (firstBit ^ secondBit ^ carry) + '0';

        result = (char)sum + result;

        

        carry =
            (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    

    if (carry)
        result = '1' + result;

    return result;
}

void id8() {
    int n;
    cin >> n;
    map<string, int> combs;
    vector<vector<int>> grid(n, vector<int>(n));
    int maxKey = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        int count = 0;
        for (int j = 0; j < n; j++) {
            grid[i][j] = (line[j]) - 48;
            if (grid[i][j]) {
                count++;
            }
        }
        if (count == n) {
            maxVal++;
        }
    }
    for (int i = 0; i < n; i++) {
        bitset<100> k;
        string key = k.to_string();
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) {
                bitset<100> bs;
                string s = bs.to_string();
                s[j] = '1';
                key = id6(key, s);
            }
        }
        if (key.find('1') >= 0)
            combs[key]++;
    }
    for (map<string, int>::iterator it = combs.begin(); it != combs.end();
         it++) {
        if (it->second > maxVal) {
            maxVal = it->second;
        }
    }
    cout << maxVal << "\n";
}

int main(void) {

    id8();

    return 0;
}