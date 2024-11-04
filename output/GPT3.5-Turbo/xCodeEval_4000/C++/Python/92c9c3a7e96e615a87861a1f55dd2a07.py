import heapq

adj = [[] for _ in range(200005)]
q = []
vis = [0] * 200005
n, m, t, c = 0, 0, 0, 0

def solve(ind):
    global c
    if ind == n:
        heapq.heappush(q, c)
        if len(q) > t:
            heapq.heappop(q)
        return
    solve(ind + 1)
    for i in range(len(adj[ind])):
        if vis[adj[ind][i][0]] == 0:
            vis[adj[ind][i][0]] = 1
            c += adj[ind][i][1]
            if len(q) < t or c < q[0]:
                solve(ind + 1)
            c -= adj[ind][i][1]
            vis[adj[ind][i][0]] = 0

def main():
    global n, m, t, c
    r, s, x, i, j, k, l, m = 0, 0, 0, 0, 0, 0, 0, 0
    n, m, t = map(int, input().split())
    for _ in range(m):
        x, y, w = map(int, input().split())
        x -= 1
        y -= 1
        adj[x].append((y, w))
    solve(0)
    print(q[0])

if __name__ == "__main__":
    main()
