import math

A = []
pl, pr, vl, vr, k = map(int, input().split())

def dfs(k=0, n=0):
    A.append(n)
    if k == 9:
        return
    else:
        dfs(k+1, n * 10 + 4)
        dfs(k+1, n * 10 + 7)

dfs()
A.sort()
A.append(math.inf)

cnt = 0

for i in range(len(A) - k):
    l1, r1 = A[i-1] + 1, A[i]
    l2, r2 = A[i + k - 1], A[i + k] - 1
    d1 = max(0, r1 - l1 + 1) * max(0, r2 - l2 + 1)
    d2 = max(0, r1 - l1 + 1) * max(0, r2 - l2 + 1)
    cnt += d1 + d2
    if d1 and d2 and k == 1:
        cnt -= 1

result = cnt / ((pr - pl + 1) * (vr - vl + 1))
print("%.12lf" % result)
