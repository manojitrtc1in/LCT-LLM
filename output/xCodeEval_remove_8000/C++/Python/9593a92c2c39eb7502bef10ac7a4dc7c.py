eps = 1e-8
S = input().strip()
n = len(S)
S = [ord(c) - ord('a') for c in S]
S.append(31)
m = int(input())
Q = [int(input(), 2) for _ in range(m)]
Qs = set(Q)
ans = {}

stk = []
nn = 0
vis = [False] * 26

for i in range(1, n+1):
    x = S[i]
    if not vis[x]:
        stk.append(x)
        nn += 1
        vis[x] = True
    else:
        j = 0
        while stk[j] != x:
            j += 1
        for k in range(j, nn-1):
            stk[k] = stk[k+1]
        stk[nn-1] = x
    t = 0
    for j in range(nn, 0, -1):
        t |= 1 << stk[j]
        if t & (1 << S[i+1]):
            break
        if t in Qs:
            ans[t] = ans.get(t, 0) + 1

for i in range(m):
    print(ans.get(Q[i], 0))
