N = 1000009
M = 10009
Z = 26

A = input().strip()
Q = []
have = set()
ans = {}

n = len(A)
m = int(input())

for _ in range(m):
    query = input().strip()
    q = 0
    for c in query:
        q |= (1 << (ord(c) - ord('a')))
    Q.append(q)
    have.add(q)

stk = [0] * Z
nn = 0
vis = [False] * Z

def push(x):
    global nn
    if not vis[x]:
        vis[x] = True
        stk[nn] = x
        nn += 1
    else:
        j = 0
        while stk[j] != x:
            j += 1
        for k in range(j, nn - 1):
            stk[k] = stk[k + 1]
        stk[nn - 1] = x

for i in range(n):
    push(A[i])
    s = 0
    for j in range(nn, -1, -1):
        s |= (1 << stk[j])
        if s & (1 << A[i + 1]):
            break
        if s in have:
            if s in ans:
                ans[s] += 1
            else:
                ans[s] = 1

for i in range(m):
    print(ans[Q[i]])
