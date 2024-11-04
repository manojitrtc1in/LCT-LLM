n, k = map(int, input().split())
a = list(map(int, input().split()))
a = [-x for x in a]
a.sort()
ans = 0
res = 0
for i in range(n):
    res -= a[i]
    if res < 0:
        j = i
        break
    if i != n-1:
        ans += res
if 'j' not in locals():
    print(ans)
    exit()
tmp = [res] + [-a[i] for i in range(j+1, n)]
tmp.sort()
w = 0
for c in tmp:
    ans += (w // (k+1)) * c
    w += 1
print(ans)
