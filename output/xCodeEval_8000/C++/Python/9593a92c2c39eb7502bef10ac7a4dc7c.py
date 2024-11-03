import sys

def getq():
    buf = sys.stdin.readline().strip()
    ret = 0
    for i in range(len(buf)-1, -1, -1):
        ret |= 1 << (ord(buf[i]) - ord('a'))
    return ret

S = sys.stdin.readline().strip()
n = len(S)
S = [ord(c) - ord('a') for c in S]
S.append(31)

m = int(sys.stdin.readline().strip())
Q = []
Qs = set()
ans = {}

for _ in range(m):
    q = getq()
    Qs.add(q)
    Q.append(q)

stk = []
nn = 0
vis = [False] * 26

for i in range(n):
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
    for j in range(nn-1, -1, -1):
        t |= 1 << stk[j]
        if t & (1 << S[i+1]):
            break
        if t in Qs:
            if t not in ans:
                ans[t] = 1
            else:
                ans[t] += 1

for q in Q:
    print(ans[q])
