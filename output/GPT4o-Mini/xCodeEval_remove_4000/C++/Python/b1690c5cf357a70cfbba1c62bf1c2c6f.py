S = input().strip()
n = len(S)
S = [ord(c) - ord('a') for c in S]
m = int(input())
Q = [0] * (m + 1)
Qs = set()
ans = {}

def getq():
    buf = input().strip()
    ret = 0
    for c in buf:
        ret |= 1 << (ord(c) - ord('a'))
    return ret

for i in range(1, m + 1):
    Q[i] = getq()
    Qs.add(Q[i])

stk = []
nn = 0
vis = [False] * 26

for i in range(1, n + 1):
    x = S[i - 1]
    if not vis[x]:
        stk.append(x)
        nn += 1
        vis[x] = True
    else:
        j = 0
        for j in range(nn):
            if stk[j] == x:
                break
        for k in range(j, nn - 1):
            stk[k] = stk[k + 1]
        stk[nn - 1] = x

    t = 0
    for j in range(nn - 1, -1, -1):
        t |= 1 << stk[j]
        if i < n and (t & (1 << S[i])):
            break
        if t in Qs:
            ans[t] = ans.get(t, 0) + 1

for i in range(1, m + 1):
    print(ans.get(Q[i], 0))
