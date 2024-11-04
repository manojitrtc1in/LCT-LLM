eps = 1e-8
S = input().strip()
n = len(S)
m = int(input())
Q = []
Qs = set()
ans = {}

def getq():
    buf = input().strip()
    ret = 0
    for i in range(len(buf)-1, -1, -1):
        ret |= 1 << (ord(buf[i]) - ord('a'))
    return ret

for i in range(1, m+1):
    Qs.add(Q[i] = getq())

stk = [0] * 27
nn = 0
vis = [False] * 26

for i in range(1, n+1):
    x = ord(S[i]) - ord('a')
    if not vis[x]:
        nn += 1
        stk[nn] = x
        vis[x] = True
    else:
        j = 1
        while stk[j] != x:
            j += 1
        for k in range(j, nn):
            stk[k] = stk[k+1]
        stk[nn] = x
    t = 0
    for j in range(nn, 0, -1):
        t |= 1 << stk[j]
        if t & (1 << ord(S[i+1]) - ord('a')):
            break
        if t in Qs:
            if t not in ans:
                ans[t] = 1
            else:
                ans[t] += 1

for i in range(1, m+1):
    print(ans[Q[i]])
