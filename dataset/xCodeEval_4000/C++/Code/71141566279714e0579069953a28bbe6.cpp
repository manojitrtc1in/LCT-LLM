














#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <random>

using namespace std;

void ans996A(){
    

    

    int money;
    cin >> money;
    cout << money / 100 + (money % 100) / 20 + (money % 20) / 10 + (money % 10) / 5 + (money % 5) << endl;
}

void ans617A(){
    

    

    int length;
    cin >> length;
    if(length % 5){
        cout << length / 5 + 1 << endl;
    }
    else{
        cout << length / 5 << endl;
    }
}

void ans749A(){
    

    

    int num;
    cin >> num;
    int ans = num / 2;
    cout << ans << endl;
    for(int i = 0; i < ans - 1; i ++){
        cout << "2 ";
    }
    cout << num - (ans - 1) * 2 << endl;
}

void ans894A(){
    

    

    string str;
    cin >> str;
    int l = str.length();
    vector<int> countQ;
    int count = 0;
    int sumQ = 0;
    for(int i = 0; i < l; i ++){
        if(str[i] == 'Q'){
            count ++;
            sumQ ++;
        }
        else if(str[i] == 'A'){
            countQ.push_back(count);
            count = 0;
        }
    }
    countQ.push_back(count);
    int ll = countQ.size();
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < ll; i ++){
        sum += countQ[i];
        ans += sum * (sumQ - sum);
    }
    cout << ans << endl;
}

void ans266B(){
    

    

    int l;
    int time;
    string str;
    cin >> l;
    cin >> time;
    cin >> str;
    int sumB = 0;
    int sumG = 0;
    for(int i = 0; i < time; i ++){
        for(int j = 0; j < l - 1; j ++){
            if(str[j] == 'B' && str[j + 1] == 'G'){
                str[j] = 'G';
                str[j + 1] = 'B';
                j ++;
            }
        }
    }
    cout << str << endl;
}

void ans513A(){
    

    

    int n1, n2, k1, k2;
    cin >> n1;
    cin >> n2;
    cin >> k1;
    cin >> k2;
    if(n1 > n2){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
}

void ans318A(){
    

    

    long long n, k;
    cin >> n;
    cin >> k;
    if(k <= (n + 1) / 2){
        cout << 2 * k - 1 << endl;
    }
    else{
        cout << 2 * (k - (n + 1) / 2) << endl;
    }
}

void ans805A(){
    

    

    int a, b;
    cin >> a;
    cin >> b;
    if(a == b){
        cout << a << endl;
    }
    else{
        cout << 2 << endl;
    }
}

void ans805B(){
    

    

    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        if(i % 4 < 2){
            cout << 'a';
        }
        else{
            cout << 'b';
        }
    }
    cout << endl;
}

void ans556A(){
    

    

    int length;
    string str;
    cin >> length;
    cin >> str;
    int num0 = 0;
    int num1 = 0;
    for(int i = 0; i < length; i ++){
        if(str[i] == '0'){
            num0 ++;
        }
        else{
            num1 ++;
        }
    }
    cout << abs(num0 - num1) << endl;
}

void ans766B(){
    

    

    int length;
    int input;
    vector<int> number;
    cin >> length;
    for(int i = 0; i < length; i ++){
        cin >> input;
        number.push_back(input);
    }
    sort(number.begin(), number.end());
    for(int i = 0; i < length - 2; i ++){
        if(number[i] + number[i + 1] > number[i + 2]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void ans519C(){
    

    

    int a, b;
    cin >> a;
    cin >> b;
    int m = min(a, b);
    int n = max(a, b);
    if(n >= 2 * m){
        cout << m << endl;
    }
    else{
        int s = 2 * m - n;
        if(s % 3 == 0){
            cout << m - s / 3 << endl;
        }
        else{
            cout << m - s / 3 - 1 << endl;
        }
    }
}

void ans617B(){
    

    

    int length;
    int temp;
    vector<int> choco;
    cin >> length;
    for(int i = 0; i < length; i ++){
        cin >> temp;
        choco.push_back(temp);
    }
    int index = 0;
    long long ans = 1;
    temp = 0;
    for(; index < length; index ++){
        if(choco[index] == 1){
            break;
        }
    }
    if(index == length){
        cout << 0 << endl;
        return;
    }
    for(; index < length; index ++){
        if(choco[index] == 0){
            temp ++;
        }
        else{
            ans *= temp + 1;
            temp = 0;
        }
    }
    cout << ans << endl;
}

void ans550C(){
    

    

    string num;
    cin >> num;
    int length = num.length();
    for(int i = length - 3; i >= 0; i --){
        if(num[i] == '0'){
            continue;
        }
        for(int j = i + 1; j < length; j ++){
            for(int k = j + 1; k < length; k ++){
                int integer = stoi(num.substr(i, 1)) * 100 + stoi(num.substr(j, 1)) * 10 + stoi(num.substr(k, 1));
                if(integer % 8 == 0){
                    cout << "YES" << endl;
                    cout << num.substr(0, i) << num[i] << num[j] << num[k] << endl;
                    return;
                }
            }
        }
    }
    for(int i = 0; i < length; i ++){
        if(num[i] == '0'){
            continue;
        }
        for(int j = i + 1; j < length; j ++){
            int integer = stoi(num.substr(i, 1)) * 10 + stoi(num.substr(j, 1));
            if(integer % 8 == 0){
                cout << "YES" << endl;
                cout << num[i] << num[j] << endl;
                return;
            }
        }
    }
    for(int i = 0; i < length; i ++){
        if(stoi(num.substr(i, 1)) % 8 == 0){
            cout << "YES" << endl;
            cout << stoi(num.substr(i, 1)) << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void ans576A(){
    

    

    int n;
    cin >> n;
    vector<int> prime;
    vector<int> ans;
    if(n == 1){
        cout << 0 << endl;
    }
    else if(n == 2){
        cout << 1 << endl;
        cout << 2 << endl;
    }
    else if(n == 3){
        cout << 2 << endl;
        cout << 2 << " 3" << endl;
    }
    else{
        prime.push_back(2);
        prime.push_back(3);
        for(int i = 4; i <= n; i ++){
            int j = 0;
            for(; j < prime.size(); j ++){
                if(i % prime[j] == 0){
                    break;
                }
            }
            if(j == prime.size()){
                prime.push_back(i);
            }
        }
        for(int i = 0; i < prime.size(); i ++){
            int pow = prime[i];
            for(int j = 1;; j ++){
                if(pow <= n){
                    ans.push_back(pow);
                    pow *= prime[i];
                }
                else{
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        cout << ans[0];
        for(int i = 1; i < ans.size(); i ++){
            cout << " " << ans[i];
        }
        cout << endl;
    }
}

struct node510B {
    int used = 0;
    string ch = "";
    vector<node510B*> edge;
};

int dfs510B(node510B* father, node510B* node, int num){
    node -> used = num;
    int res = 0;
    for(int i = 0; i < (node -> edge).size(); i ++){
        if((node -> edge)[i] == node){
            continue;
        }
        if((node -> edge)[i] -> used == num && (node -> edge)[i] != father){
            return 1;
        }
        else if((node -> edge)[i] -> used == 0 && (node -> edge)[i] -> ch == node -> ch){
            res = dfs510B(node, (node -> edge)[i], num);
            if(res == 1){
                return 1;
            }
        }
    }
    return 0;
}

void ans510B(){
    

    

    int m;
    int n;
    cin >> m;
    cin >> n;
    node510B nodes[m][n];
    string temp;
    for(int i = 0; i < m; i ++){
        cin >> temp;
        for(int j = 0; j < n; j ++){
            nodes[i][j].ch = temp.substr(j, 1);
        }
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(j < n - 1 && nodes[i][j].ch == nodes[i][j + 1].ch){
                nodes[i][j].edge.push_back(&(nodes[i][j + 1]));
                nodes[i][j + 1].edge.push_back(&(nodes[i][j]));
            }
            if(i < m - 1 && nodes[i][j].ch == nodes[i + 1][j].ch){
                nodes[i][j].edge.push_back(&(nodes[i + 1][j]));
                nodes[i + 1][j].edge.push_back(&(nodes[i][j]));
            }
        }
    }
    int count = 1;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(nodes[i][j].used == 0){
                int res = dfs510B(NULL, &(nodes[i][j]), count);
                if(res == 1){
                    cout << "Yes" << endl;
                    return;
                }
                else{
                    count ++;
                }
            }
        }
    }
    cout << "No" << endl;
}

void ans460B(){
    

    

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    vector<int> ans;
    for(int i = 1; i <= 81; i ++){
        int res = b * pow(i, a) + c;
        int temp = res;
        int sum = 0;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == i && res > 0 && res < 1000000000){
            ans.push_back(res);
        }
    }
    cout << ans.size() << endl;
    if(ans.size() != 0){
        cout << ans[0];
        for(int i = 1; i < ans.size(); i ++){
            cout << " " << ans[i];
        }
        cout << endl;
    }
}

struct msg {
    string name;
    int time;
};

bool compareMsg(msg a, msg b){
    return a.time > b.time;
}

void ans637B(){
    

    

    int num;
    cin >> num;
    map<string, int> chat;
    string temp;
    for(int i = 0; i < num; i ++){
        cin >> temp;
        chat[temp] = i;
    }
    vector<msg> message;
    for(map<string, int>::iterator it = chat.begin(); it != chat.end(); it ++){
        msg temp;
        temp.name = it -> first;
        temp.time = it -> second;
        message.push_back(temp);
    }
    sort(message.begin(), message.end(), compareMsg);
    for(int i = 0; i < message.size(); i ++){
        cout << message[i].name << endl;
    }
}

struct node445B {
    int num = 0;
    vector<node445B*> edge;
};

void dfs445B(int n, node445B* node){
    if(node -> num == n){
        return;
    }
    else{
        node -> num = n;
        for(int i = 0; i < (node -> edge).size(); i ++){
            dfs445B(n, (node -> edge)[i]);
        }
    }
}

void ans445B(){
    

    

    int n, m;
    node445B nodes[51];
    cin >> n;
    cin >> m;
    int a, b;
    for(int i = 0; i < m; i ++){
        cin >> a;
        cin >> b;
        nodes[a].edge.push_back(&(nodes[b]));
        nodes[b].edge.push_back(&(nodes[a]));
    }
    int p = 0;
    for(int i = 1; i <= n; i ++){
        if(nodes[i].num == 0){
            p ++;
            dfs445B(p, &(nodes[i]));
        }
    }
    long long ans  = 1;
    for(int i = 0; i < n - p; i ++){
        ans *= 2;
    }
    cout << ans << endl;
}

void ans165C(){
    

    

    int num;
    string str;
    cin >> num;
    cin >> str;
    int sum = 1;
    vector<long long> count;
    for(int i = 0; i < str.length(); i ++){
        if(str[i] == '0'){
            sum ++;
        }
        else{
            count.push_back(sum);
            sum = 1;
        }
    }
    count.push_back(sum);
    long long ans = 0;
    if(num){
        for(int i = 0; i + num < count.size(); i ++){
            ans += count[i] * count[i + num];
        }
    }
    else{
        for(int i = 0; i + num < count.size(); i ++){
            ans += count[i] * (count[i] - 1) / 2;
        }
    }
    cout << ans << endl;
}

void ans468A(){
    

    

    int n;
    cin >> n;
    if(n < 4){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        int begin;
        if(n % 2 == 0){
            cout << "1 * 2 = 2" << endl;
            cout << "2 * 3 = 6" << endl;
            cout << "6 * 4 = 24" << endl;
            begin = 5;
        }
        else{
            cout << "3 * 5 = 15" << endl;
            cout << "2 * 4 = 8" << endl;
            cout << "15 + 8 = 23" << endl;
            cout << "23 + 1 = 24" << endl;
            begin = 6;
        }
        for(int i = begin; i < n; i += 2){
            cout << i + 1 << " - " << i << " = 1" << endl;
            cout << "24 * 1 = 24" << endl;
        }
    }
}

void ans282C(){
    

    

    string str1,str2;
    cin >> str1;
    cin >> str2;
    int sum1 = 0;
    int sum2 = 0;
    if(str1.length() != str2.length()){
        cout << "NO" << endl;
    }
    else{
        for(int i = 0; i < str1.length(); i ++){
            if(str1[i] == '1'){
                sum1 ++;
            }
            if(str2[i] == '1'){
                sum2 ++;
            }
        }
        if((sum1 == 0 && sum2 != 0) || (sum2 == 0 && sum1 != 0)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}

void ans1166C(){
    

    

    int n;
    vector<int> points;
    int temp;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> temp;
        points.push_back(abs(temp));
    }
    sort(points.begin(), points.end());
    long long ans = 0;
    int j = 1;
    temp = 0;
    for(int i = 0; i < n; i ++){
        while(j < n && points[j] <= 2 * points[i]){
            temp ++;
            j ++;
        }
        ans += temp;
        temp = temp - 1;
    }
    cout << ans << endl;
}

struct num1185D {
    num1185D(int a, int b){
        this -> num = a;
        this -> place = b;
    }
    int num;
    int place;
};

bool compareNum1185D(num1185D a, num1185D b){
    return a.num < b.num;
}

void ans1185D(){
    

    

    int n;
    cin >> n;
    if(n < 4){
        cout << 1 << endl;
        return;
    }
    vector<num1185D> array;
    int temp;
    for(int i = 0; i < n; i ++){
        cin >> temp;
        array.push_back(num1185D(temp, i + 1));
    }
    sort(array.begin(), array.end(), compareNum1185D);
    vector<num1185D> sub;
    for(int i = 0; i < n - 1; i ++){
        sub.push_back(num1185D(array[i + 1].num - array[i].num, i));
    }
    int isSame = 1;
    for(int i = 1; i < n - 2; i ++){
        if(sub[i].num != sub[1].num){
            isSame = 0;
            break;
        }
    }
    if(n == 4 || isSame == 0){
        sort(sub.begin(), sub.end(), compareNum1185D);
        isSame = 1;
        int sameNum = sub[2].num;
        for(int i = 2; i < n - 1; i ++){
            if(sub[i].num != sub[2].num){
                isSame = 0;
                break;
            }
        }
        if(isSame && (sub[0].num + sub[1].num == sameNum)){
            cout << array[max(sub[0].place, sub[1].place)].place << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if(sub[0].num == sub[1].num && sub[n - 2].num == sub[1].num){
        cout << array[0].place << endl;
    }
    else if(sub[0].num == sub[1].num && sub[n - 2].num != sub[1].num){
        cout << array[n - 1].place << endl;
    }
    else if(sub[0].num != sub[1].num && sub[n - 2].num == sub[1].num){
        cout << array[0].place << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void ans540B(){
    

    

    int n, k, p, x, y;
    cin >> n;
    cin >> k;
    cin >> p;
    cin >> x;
    cin >> y;
    vector<int> exams;
    int temp;
    int sum = 0;
    for(int i = 0; i < k; i ++){
        cin >> temp;
        sum += temp;
        exams.push_back(temp);
    }
    sort(exams.begin(), exams.end());
    int remain = x - sum;
    int small = 0;
    for(int i = 0; i < k; i ++){
        if(exams[i] < y){
            small ++;
        }
        else{
            break;
        }
    }
    if(remain > 0 && small <= n / 2 && ((n / 2 - small) * 1 + y * (n / 2 - (k - small) + 1)) <= remain){
        if(small < n / 2){
            cout << 1;
        }
        for(int i = 1; i < min(n / 2 - small, n - k); i ++){
            cout << " " << 1;
        }
        for(int i = 0; i < n / 2 - (k - small) + 1; i ++){
            cout << " " << y;
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}

struct node1027D {
    int cost;
    int treenum = 0;
    vector<node1027D*> son;
    int father = 0;
};

node1027D tree1027D[200002];

int mincost(node1027D* top){
    if(top -> father == 0){
        return top -> cost;
    }
    else{
        return min(top -> cost, mincost(&tree1027D[top -> father]));
    }
}

void changetreenum(node1027D* top, int num){
    if(top -> treenum == num){
        return;
    }
    top -> treenum = num;
    for(int i = 0; i < (top -> son).size(); i ++){
        changetreenum((top -> son)[i], num);
    }
    if(top -> father != 0){
        changetreenum(&tree1027D[top -> father], num);
    }
}

void ans1027D(){
    

    

    int n;
    cin >> n;
    int temp;
    node1027D* tree = tree1027D;
    for(int i = 1; i <= n; i ++){
        cin >> tree[i].cost;
    }
    int treecount = 1;
    int count[200001];
    for(int i = 0; i < 200002; i ++){
        count[i] = 0;
    }
    vector<int> selected;
    for(int i = 1; i <= n; i ++){
        cin >> temp;
        if(i == temp){
            selected.push_back(temp);
        }
        else if(tree[i].treenum == 0 && tree[temp].treenum == 0){
            tree[i].treenum = treecount;
            tree[temp].treenum = treecount;
            count[treecount] += 2;
            treecount ++;
            tree[i].father = temp;
            tree[temp].son.push_back(&(tree[i]));
        }
        else if(tree[i].treenum == 0){
            tree[i].treenum = tree[temp].treenum;
            count[tree[i].treenum] ++;
            tree[i].father = temp;
            tree[temp].son.push_back(&(tree[i]));
        }
        else if(tree[temp].treenum == 0){
            tree[temp].treenum = tree[i].treenum;
            count[tree[temp].treenum] ++;
            tree[i].father = temp;
            tree[temp].son.push_back(&(tree[i]));
        }
        else if(tree[i].treenum == tree[temp].treenum){
            selected.push_back(temp);
        }
        else{
            if(count[tree[i].treenum] < count[tree[temp].treenum]){
                changetreenum(&tree[i], tree[temp].treenum);
                count[tree[temp].treenum] += count[tree[i].treenum];
                count[tree[i].treenum] = 0;
            }
            else{
                changetreenum(&tree[temp], tree[i].treenum);
                count[tree[i].treenum] += count[tree[temp].treenum];
                count[tree[temp].treenum] = 0;
            }
            tree[i].father = temp;
            tree[temp].son.push_back(&(tree[i]));
        }
    }
    int ret = 0;
    for(int i = 0; i < selected.size(); i ++){
        ret += mincost(&tree[selected[i]]);
    }
    cout << ret << endl;
}

void ans1194D(){
    

    

    int T, n, k;
    cin >> T;
    for(int i = 0; i < T; i ++){
        cin >> n;
        cin >> k;
        if(n == k){
            cout << "Alice" << endl;
        }
        else if(n < k || k % 3 != 0){
            if(n % 3 != 0){
                cout << "Alice" << endl;
            }
            else{
                cout << "Bob" << endl;
            }
        }
        else{
            if((n + 1) % (k + 1) == 0){
                cout << "Alice" << endl;
            }
            else if((n - n / (k + 1) * (k + 1)) % 3 == 0){
                cout << "Bob" << endl;
            }
            else{
                cout << "Alice" << endl;
            }
        }
    }
}


void ans276C(){
    

    

    

    int n, q;
    cin >> n;
    cin >> q;
    long long num[n];
    long long array[n];
    for(int i = 0; i < n; i ++){
        cin >> array[i];
        num[i] = 0;
    }
    int begin, end;
    for(int i = 0; i < q; i ++){
        cin >> begin;
        cin >> end;
        num[begin - 1] ++;
        if(end < n){
            num[end] --;
        }
    }
    for(int i = 1; i < n; i ++){
        num[i] = num[i] + num[i - 1];
    }
    sort(array, array + n);
    sort(num, num + n);
    long long ans = 0;
    for(int i = 0; i < n; i ++){
        ans += array[i] * num[i];
    }
    cout << ans << endl;
}

void buildTree(int* tree, int root, int left, int right, int n){
    if(left == right){
        cin >> tree[root];
    }
    else{
        buildTree(tree, root << 1, left, (left + right) / 2, n - 1);
        buildTree(tree, (root << 1) | 1, (left + right) / 2 + 1, right, n - 1);
        if(n & 1){
            tree[root] = tree[root << 1] | tree[(root << 1) | 1];
        }
        else{
            tree[root] = tree[root << 1] ^ tree[(root << 1) | 1];
        }
    }
}

void ans339D(){
    

    

    

    int n, m;
    cin >> n;
    cin >> m;
    int tree339D[1 << (n + 1)];
    buildTree(tree339D, 1, 1, 1 << n, n);
    int index;
    int count;
    for(int i = 0; i < m; i ++){
        cin >> index;
        count = 0;
        int temp = (1 << n) - 1 + index;
        for(; temp > 0; count ++, temp /= 2){
            if(count == 0){
                cin >> tree339D[temp];
            }
            else if(count & 1){
                tree339D[temp] = tree339D[temp << 1] | tree339D[(temp << 1) | 1];
            }
            else{
                tree339D[temp] = tree339D[temp << 1] ^ tree339D[(temp << 1) | 1];
            }
        }
        cout << tree339D[1] << endl;
    }
}

int array546D[5000001];
bool prime546D[5000001];

void ans546D(){
    

    

    

    for(int i = 1; i < 5000001; i ++){
        array546D[i] = 0;
        prime546D[i] = true;
    }
    for(int i = 2; i < 5000001; i ++){
        if(prime546D[i]){
            for(int j = i; j < 5000001; j += i){
                int temp = j;
                while(temp % i == 0){
                    array546D[j] ++;
                    temp /= i;
                }
                prime546D[j] = false;
            }
        }
    }
    for(int i = 2; i <= 5000000; i ++){
        array546D[i] = array546D[i] + array546D[i - 1];
    }
    int t;
    int a, b;
    cin >> t;
    for(int i = 0; i < t; i ++){
        scanf("%d%d", &a, &b);
        printf("%d\n", array546D[a] - array546D[b]);
    }
}

struct edge682C {
    edge682C(int a, int b){
        this -> nextNode = a;
        this -> weight = b;
    }
    int nextNode;
    int weight;
};

struct node682C {
    int num;
    int count = 1;
    vector<edge682C> edges;
};

node682C tree682C[100000 + 1];

int countDFS682C(int father, int node){
    for(int i = 0; i < tree682C[node].edges.size(); i ++){
        if(tree682C[node].edges[i].nextNode != father){
            tree682C[node].count += countDFS682C(node, tree682C[node].edges[i].nextNode);
        }
    }
    return tree682C[node].count;
}

int getAns682C(int father, int node, int maxDist){
    int ans = 0;
    if(maxDist > tree682C[node].num){
        return tree682C[node].count;
    }
    for(int i = 0; i < tree682C[node].edges.size(); i ++){
        if(tree682C[node].edges[i].nextNode != father){
            ans += getAns682C(node, tree682C[node].edges[i].nextNode, max(0, maxDist + tree682C[node].edges[i].weight));
        }
    }
    return ans;
}

void ans682C(){
    

    

    

    int n;
    cin >> n;
    int tempWeight;
    int tempNode;
    for(int i = 1; i <= n; i ++){
        cin >> tree682C[i].num;
    }
    for(int i = 1; i < n; i ++){
        cin >> tempNode;
        cin >> tempWeight;
        tree682C[i + 1].edges.push_back(edge682C(tempNode, tempWeight));
        tree682C[tempNode].edges.push_back(edge682C(i + 1, tempWeight));
    }
    countDFS682C(0, 1);
    cout << getAns682C(0, 1, 0) << endl;
}

struct numcount231C {
    numcount231C(long long a, int b, int c){
        this -> num = a;
        this -> begin = b;
        this -> end = c;
    }
    long long num;
    int begin;
    int end;
};

void ans231C(){
    

    

    

    int n, k;
    cin >> n;
    cin >> k;
    int temp;
    vector<long long> number;
    vector<long long> sum;
    sum.push_back(0);
    vector<numcount231C> count;
    for(int i = 0; i < n; i ++){
        cin >> temp;
        number.push_back(temp);
    }
    sort(number.begin(), number.end());
    int begin = 0;
    long long sumall = 0;
    long long num = number[0];
    for(int i = 0; i < n; i ++){
        sumall += number[i];
        sum.push_back(sumall);
        if(number[i] != num){
            count.push_back(numcount231C(num, begin, i));
            begin = i;
            num = number[i];
        }
    }
    count.push_back(numcount231C(num, begin, n));
    int ans = 1145141919;
    int ansCount = -1;
    begin = 0;
    long long steps;
    for(int i = 0; i < count.size(); i ++){
        steps = (count[i].begin - begin) * count[i].num - (sum[count[i].begin] - sum[begin]);
        while(steps > k){
            begin ++;
            steps = (count[i].begin - begin) * count[i].num - (sum[count[i].begin] - sum[begin]);
        }
        if(count[i].end - begin > ansCount){
            ansCount = count[i].end - begin;
            ans = count[i].num;
        }
    }
    cout << ansCount << " " << ans << endl;
}

int main() {
    ans1194D();
    return 0;
}
