import sys

S = input()
n = len(S)
m = int(input())
Q = []
Qs = set()
ans = {}

for _ in range(m):
    q = input()
    Qs.add(q)
    Q.append(q)

stk = []
nn = 0
vis = [False] * 26

for i in range(n):
    x = ord(S[i]) - ord('a')
    if not vis[x]:
        stk.append(x)
        nn += 1
        vis[x] = True
    else:
        j = 0
        while stk[j] != x:
            j += 1
        for k in range(j, nn - 1):
            stk[k] = stk[k + 1]
        stk[nn - 1] = x
    t = 0
    for j in range(nn - 1, -1, -1):
        t |= 1 << stk[j]
        if i < n - 1 and t & (1 << (ord(S[i + 1]) - ord('a'))):
            break
        if t in Qs:
            if t in ans:
                ans[t] += 1
            else:
                ans[t] = 1

for q in Q:
    if q in ans:
        print(ans[q])
    else:
        print(0)
