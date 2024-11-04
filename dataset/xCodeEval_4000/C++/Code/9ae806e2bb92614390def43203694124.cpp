














#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <random>

using namespace std;

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

int main() {
    ans231C();
    return 0;
}
