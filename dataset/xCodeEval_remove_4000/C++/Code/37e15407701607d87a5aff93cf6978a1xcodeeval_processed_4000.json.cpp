






































using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;



































int sparse[logMaxN][maxN];

void id2(int N) {
    

    FOR(i, 1, logMaxN) {
        FOR(j, 0, N) {
            

            sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
            

            sparse[i][j] = sparse[i - 1][j];
            int nextJ = j + (1 << (i - 1));
            if (nextJ < N) sparse[i][j] = max(sparse[i][j], sparse[i - 1][nextJ]);
        }
    }
}















int N;
long long a[maxN], b[maxN],s[maxN];;

void id1(int N) {
    

    

    

    FOR(i, 1, N+1) {
        s[i] = s[i - 1] + a[i - 1];
    }
}



struct Node {
    Node * left, * right;
    int value;
};





struct Node2 {
    

    int v1, v2, v3; 

};







long long segmentTree[3 * maxN], lazy[3 * maxN], ss;
long long segmentTreeSorted[3 * maxN];







void id0(int N) {
    

    memset(lazy, 0, sizeof(lazy));
    FOR(i, 0, ss) {
        segmentTree[ss + i] = 0;
        segmentTreeSorted[ss + i] = 0;
    }
    

    FOR(i, 0, N) {
        segmentTree[ss + i] = a[i];
        segmentTreeSorted[ss + i] = b[i];
    }
    
    

    for (long long i = ss - 1; i; i--) {
        

        

        segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
        segmentTreeSorted[i] = segmentTreeSorted[i << 1] + segmentTreeSorted[i << 1 | 1];
    }
}



void propagate(int n, int d) {
    if (lazy[n]) {
        segmentTree[n] += lazy[n] * d;
        if (n<ss) {
            lazy[n << 1] += lazy[n];
            lazy[n << 1 | 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}













long long query(int n, int l, int r, int d) { 

    

    propagate(n, d);
    

    if (l > r) return 0;
    

    

    if (!l && r == d - 1) {
        return segmentTree[n];
    }
    

    d /= 2;
    return query(n << 1, l, min(d-1, r), d) +
    query(2 * n + 1, max(0, l - d), r - d, d);
}

long long query1(int n, int l, int r, int d) { 

    

    propagate(n, d);
    

    if (l > r) return 0;
    

    

    if (!l && r == d - 1) {
        return segmentTree[n];
    }
    

    d /= 2;
    return query1(n << 1, l, min(d-1, r), d) +
    query1(2 * n + 1, max(0, l - d), r - d, d);
}

ll query2(int n, int l, int r, int d) { 

    

    propagate(n, d);
    

    if (l > r) return 0;
    

    

    if (!l && r == d - 1) {
        return segmentTreeSorted[n];
    }
    

    d /= 2;
    return query2(n << 1, l, min(d-1, r), d) + query2(2 * n + 1, max(0, l - d), r - d, d);
}







void modify(int n, int x) {
    segmentTree[n] = x;
    while (n >>= 1) {
        segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
    }
}





void query3(int n, int l, int r, int d, int x) {
    propagate(n, d);
    

    if (l > r) return;
    

    

    if (!l && r == d - 1) {
        lazy[n] += x;
        propagate(n, d);
        return;
    }
    

    d /= 2;
    query3(n << 1, l, min(d - 1, r), d, x);
    query3(2 * n + 1, max(0, l - d), r - d, d, x);
    

    segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
}


























































int id3(int l, int r) { 

    int sum = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) sum += segmentTree[l++];
        if (r & 1) sum += segmentTree[--r];
    }
    return sum;
}






















int main(int argc, const char * argv[]) {
    
    
    int n;
    cin >> n;
    
    for(int x = 0; x < n; x++)
    {
        int temp;
        cin >> temp;
        a[x] = temp;
        b[x] = temp;
    }
    
    sort(begin(b), begin(b)+n);
    
    ss = 1 << (ll)ceil(log2(n));
    id0(n);
    
    int m;
    cin >> m;
    
    for(int x = 0; x < m; x++)
    {
        int type, l, r;
        cin >> type >> l >> r;
        
        if(type == 1)
        {
            cout << query1(1,l-1,r-1,ss) << endl;
        }
        else
        {
            cout << query2(1,l-1,r-1,ss) << endl;
        }
        
        
    }
    
    return 0;
}
