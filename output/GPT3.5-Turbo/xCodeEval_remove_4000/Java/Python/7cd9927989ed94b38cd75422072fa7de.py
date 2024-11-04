from collections import deque

class Pair:
    def __init__(self, val, dist):
        self.val = val
        self.dist = dist

def bfs(arr, visited, start, map):
    q = deque()
    q.append(Pair(start, 0))
    map[start] = 0
    visited[start] = 1
    while q:
        ob = q.popleft()
        for i in range(len(arr[ob.val])):
            curr = arr[ob.val][i]
            if visited[curr] == 0:
                visited[curr] = 1
                q.append(Pair(curr, ob.dist + 1))
                map[curr] = ob.dist + 1

n, m = map(int, input().split())
rarr = [[] for _ in range(n + 1)]
arr = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    rarr[b].append(a)

h = int(input())
path = list(map(int, input().split()))
map = {}
visited = [0] * (n + 1)
bfs(rarr, visited, path[h - 1], map)

min_count = 0
max_count = 0

for i in range(h - 1):
    count = 0
    if map[path[i]] == map[path[i + 1]] + 1:
        for j in range(len(arr[path[i]])):
            curr = arr[path[i]][j]
            if map[curr] == map[path[i]] - 1:
                count += 1
        if count > 1:
            max_count += 1
    else:
        min_count += 1
        max_count += 1

print(min_count, max_count)
