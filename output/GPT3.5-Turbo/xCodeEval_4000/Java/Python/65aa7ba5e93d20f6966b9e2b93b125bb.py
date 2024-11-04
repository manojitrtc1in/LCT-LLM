MOD = int(1e9 + 7)
MOD2 = MOD * MOD
pInf = float('inf')
nInf = float('-inf')

def solve():
    s = input()
    t = input()
    n = len(s)
    m = len(t)
    pre = [0] * m
    suf = [0] * m
    for i in range(m):
        j = 0
        while s[j] != t[i]:
            j += 1
        pre[i] = j
        j += 1
    for i in range(m-1, -1, -1):
        j = n - 1
        while s[j] != t[i]:
            j -= 1
        suf[i] = j
        j -= 1
    ans = max(suf[0], n-1-pre[m-1])
    for i in range(m-1):
        ans = max(ans, suf[i+1]-1-pre[i])
    print(ans)

test = 1
while test > 0:
    solve()
    test -= 1
