from collections import defaultdict

N = 1000009
M = 10009
Z = 26

A = input().strip()
n = len(A)
A = [ord(c) - ord('a') for c in A] + [Z]

Q = [0] * M
have = set()
ans = defaultdict(int)

def push(stk, vis, nn, x):
    if not vis[x]:
        vis[stk[nn]] = True
        stk[nn] = x
        return nn + 1
    else:
        j = 0
        while True:
            if stk[j] == x:
                break
            j += 1
        for k in range(j, nn - 1):
            stk[k] = stk[k + 1]
        stk[nn - 1] = x
        return nn

stk = [0] * Z
nn = 0
vis = [False] * Z

m = int(input())
for _ in range(m):
    buf = input().strip()
    cur = 0
    for c in buf:
        cur |= 1 << (ord(c) - ord('a'))
    Q[_] = cur
    have.add(Q[_])

for i in range(n):
    nn = push(stk, vis, nn, A[i])
    s = 0
    for j in range(nn - 1, -1, -1):
        s |= 1 << stk[j]
        if (s & (1 << A[i + 1])) != 0:
            break
        if s in have:
            ans[s] += 1

for i in range(m):
    print(ans[Q[i]])
