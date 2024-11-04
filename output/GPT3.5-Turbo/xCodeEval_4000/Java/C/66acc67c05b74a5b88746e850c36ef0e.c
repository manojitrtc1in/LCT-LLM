#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 200000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void addEdge(LinkedList* adj[], int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = adj[src]->head;
    adj[src]->head = newNode;
}

void dfs(int start, int root, bool visited[], int par[], LinkedList* adj[]) {
    visited[start] = true;
    par[start] = root;
    Node* curr = adj[start]->head;
    while (curr != NULL) {
        if (!visited[curr->data]) {
            dfs(curr->data, start, visited, par, adj);
        }
        curr = curr->next;
    }
}

void soln() {
    int a, b, x, y, z;
    scanf("%d %d %d %d %d", &a, &b, &x, &y, &z);
    long ans = 0;
    if ((long)a < 2 * (long)x) {
        ans += 2 * (long)x - a;
        a = 0;
    }
    else {
        a = a - 2 * x;
    }
    if ((long)b < 3 * (long)z) {
        ans += 3 * (long)z - b;
        b = 0;
    }
    else {
        b = b - 3 * z;
    }
    if (a < b) {
        y = y - a > 0 ? y - a : 0;
        b = b - a;
        a = 0;
    }
    else {
        y = y - b > 0 ? y - b : 0;
        b = a - b;
        a = 0;
    }
    if (y > b) {
        ans += b + 2 * (y - b);
    }
    else {
        ans += y;
    }
    printf("%ld\n", ans);
}

int main() {
    LinkedList* adj[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        adj[i] = (LinkedList*)malloc(sizeof(LinkedList));
        adj[i]->head = NULL;
    }

    int n;
    scanf("%d", &n);
    bool visited[n];
    int par[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    dfs(1, -1, visited, par, adj);
    soln();

    for (int i = 0; i < MAX_SIZE; i++) {
        free(adj[i]);
    }

    return 0;
}
