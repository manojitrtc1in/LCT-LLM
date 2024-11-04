






















using namespace std;

void id24(){
    

    

    int money;
    cin >> money;
    cout << money / 100 + (money % 100) / 20 + (money % 20) / 10 + (money % 10) / 5 + (money % 5) << endl;
}

void id15(){
    

    

    int length;
    cin >> length;
    if(length % 5){
        cout << length / 5 + 1 << endl;
    }
    else{
        cout << length / 5 << endl;
    }
}

void id2(){
    

    

    int num;
    cin >> num;
    int ans = num / 2;
    cout << ans << endl;
    for(int i = 0; i < ans - 1; i ++){
        cout << "2 ";
    }
    cout << num - (ans - 1) * 2 << endl;
}

void id8(){
    

    

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

void id13(){
    

    

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

void id17(){
    

    

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

void id7(){
    

    

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

void id16(){
    

    

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

void id4(){
    

    

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

void id11(){
    

    

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

void id23(){
    

    

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

void id5(){
    

    

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

void id20(){
    

    

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

void id25(){
    

    

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

void id18(){
    

    

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

int id6(node510B* father, node510B* node, int num){
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
            res = id6(node, (node -> edge)[i], num);
            if(res == 1){
                return 1;
            }
        }
    }
    return 0;
}

void id19(){
    

    

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
                int res = id6(NULL, &(nodes[i][j]), count);
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

void id14(){
    

    

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

void id9(){
    

    

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

void id12(int n, node445B* node){
    if(node -> num == n){
        return;
    }
    else{
        node -> num = n;
        for(int i = 0; i < (node -> edge).size(); i ++){
            id12(n, (node -> edge)[i]);
        }
    }
}

void id26(){
    

    

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
            id12(p, &(nodes[i]));
        }
    }
    long long ans  = 1;
    for(int i = 0; i < n - p; i ++){
        ans *= 2;
    }
    cout << ans << endl;
}

void id10(){
    

    

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

void id1(){
    

    

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

void id3(){
    

    

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

void id21(){
    

    

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

int array546D[5000001];
bool prime546D[5000001];

void id22(){
    

    

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


void id27(){
    

    

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

void id0(){
    

    

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

int main() {
    id22();
    return 0;
}
