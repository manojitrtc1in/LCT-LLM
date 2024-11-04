import sys
from collections import deque

class Pair:
    def __init__(self, idx, val):
        self.idx = idx
        self.val = val

    def __lt__(self, other):
        return self.val > other.val

def dfs(start, root):
    visited[start] = True
    par[start] = root
    for i in adj[start]:
        if not visited[i]:
            dfs(i, start)

def soln():
    global a, b, x, y, z
    a = next_int()
    b = next_int()
    x = next_int()
    y = next_int()
    z = next_int()
    ans = 0
    if a < 2 * x:
        ans += 2 * x - a
        a = 0
    else:
        a -= 2 * x

    if b < 3 * z:
        ans += 3 * z - b
        b = 0
    else:
        b -= 3 * z

    if a < b:
        y = max(0, y - a)
        b -= a
        a = 0
    else:
        y = max(0, y - b)
        b = a - b
        a = 0

    if y > b:
        ans += b + 2 * (y - b)
    else:
        ans += y

    print(ans)

def bfs(gp, s, visited, dist):
    qu = deque()
    level = 1
    id4 = len(gp[s]) + 1 if gp[s] is not None else 0
    visited[s] = True
    qu.append(s)

    while qu:
        temp = qu.popleft()
        id4 -= 1
        dist[temp] = level * 6
        for neighbor in gp[temp]:
            if not visited[neighbor]:
                visited[neighbor] = True
                qu.append(neighbor)

        if id4 == 0:
            level += 1
            id4 = len(qu)

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(n**0.5) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    global visited, par, adj
    visited = [False] * 200000
    par = [0] * 200000
    adj = [[] for _ in range(200000)]
    
    soln()

if __name__ == "__main__":
    main()
