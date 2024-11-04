def getq():
    buf = input().strip()
    ret = 0
    for char in reversed(buf):
        ret |= 1 << (ord(char) - ord('a'))
    return ret

S = input().strip()
n = len(S)
S = [ord(char) - ord('a') for char in S] + [31]
m = int(input())
Q = [getq() for _ in range(m)]
Qs = set(Q)
ans = {}

stk = []
nn = 0
vis = [False] * 26

for i in range(1, n + 1):
    x = S[i]
    if not vis[x]:
        stk.append(x)
        nn += 1
        vis[x] = True
    else:
        j = 0
        while True:
            if stk[j] == x:
                break
            j += 1
        for k in range(j, nn - 1):
            stk[k] = stk[k + 1]
        stk[nn - 1] = x

    t = 0
    for j in range(nn - 1, -1, -1):
        t |= 1 << stk[j]
        if (t & (1 << S[i + 1])) != 0:
            break
        if t in Qs:
            ans[t] = ans.get(t, 0) + 1

for i in range(m):
    print(ans.get(Q[i], 0))
