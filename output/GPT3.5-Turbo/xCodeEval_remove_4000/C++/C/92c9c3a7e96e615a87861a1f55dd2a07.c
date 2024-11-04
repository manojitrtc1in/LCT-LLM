#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200005

typedef struct {
    int ff;
    int ss;
} pii;

typedef struct {
    int first;
    pii second;
} ver;

typedef long long ll;

typedef struct {
    ll val;
    int ind;
} node;

int adj[MAX_SIZE][MAX_SIZE];
int adjSize[MAX_SIZE];
int vis[MAX_SIZE];
ll q[MAX_SIZE];
int front = 0;
int rear = 0;
int n, m, t, c = 0;

void push(ll val) {
    q[rear++] = val;
}

void pop() {
    front++;
}

ll top() {
    return q[front];
}

int empty() {
    return front == rear;
}

void solve(int ind) {
    if (ind == n) {
        push(c);
        if (rear - front > t) {
            pop();
        }
        return;
    }
    solve(ind + 1);
    for (int i = 0; i < adjSize[ind]; i++) {
        if (vis[adj[ind][i].ff] == 0) {
            vis[adj[ind][i].ff] = 1;
            c += adj[ind][i].ss;
            if (rear - front < t || c < top()) {
                solve(ind + 1);
            }
            c -= adj[ind][i].ss;
            vis[adj[ind][i].ff] = 0;
        }
    }
}

int main() {
    ll r, s = 0, x, i, j, k, l, m;
    scanf("%lld %lld %lld", &n, &m, &t);
    for (i = 0; i < m; i++) {
        ll x, y, w;
        scanf("%lld %lld %lld", &x, &y, &w);
        x--, y--;
        adj[x][adjSize[x]].ff = y;
        adj[x][adjSize[x]].ss = w;
        adjSize[x]++;
    }
    solve(0);
    printf("%lld", top());
    return 0;
}
