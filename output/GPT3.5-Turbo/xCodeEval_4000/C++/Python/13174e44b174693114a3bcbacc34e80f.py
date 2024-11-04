import math

def unite_seg(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, (p1[1] - p1[0]) % n)
    np2 = ((p2[0] - p1[0]) % n, (p2[1] - p1[0]) % n)
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return ((np1[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return ((np2[0] + p1[0]) % n, (max(np1[1], np2[1]) + p1[0]) % n)

def count_tro(r):
    return 32 - int(math.log2(r))

def segment(l, r):
    if l == -1 or r == -1:
        return (-1, -1)
    szz = (r - l) % n
    if l == r:
        return sp[0][l]
    g = count_tro(szz) - 1
    return unite_seg(sp[g][l], sp[g][((r + 1 - (1 << g)) % n + n) % n], n)

n = int(input())
if n == 1:
    print("0")
    exit()

r = list(map(int, input().split()))
zz = count_tro(n)
v = [None] * zz
prs = [None] * n

for i in range(n):
    if r[i] >= n - 1:
        prs[i] = (-1, -1)
    else:
        prs[i] = unite_seg(((i - r[i]) % n, i), (i, (i + r[i]) % n), n)

sp = [None] * zz
sp[0] = prs

for i in range(1, zz):
    new_prs = [None] * n
    for j in range(n):
        pairr = segment(j, j)
        new_prs[j] = segment(pairr[0], pairr[1])
    sp[i] = new_prs

for i in range(n):
    my_pr = (i, i)
    ans = 0
    for j in range(zz - 1, -1, -1):
        new_pr = segment(my_pr[0], my_pr[1])
        if new_pr[0] != -1:
            ans += (1 << j)
            my_pr = new_pr
    print(ans + 1, end=' ')
print()
