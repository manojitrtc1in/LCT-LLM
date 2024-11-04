import sys
from collections import namedtuple
from functools import reduce

MOD = 1000000007
maxn = 100100
mod = 998244353

Info = namedtuple('Info', ['time', 'p'])

def pow(n, m, mod=0):
    if m < 0:
        return 0
    ans = 1
    k = n
    while m:
        if m & 1:
            ans *= k
            if mod:
                ans %= mod
        k *= k
        if mod:
            k %= mod
        m >>= 1
    return ans

def add(a, b, mod=-1):
    if mod == -1:
        mod = MOD
    a += b
    while a >= mod:
        a -= mod
    while a < 0:
        a += mod
    return a

def merge(a, b):
    ans = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] == b[j]:
            ans.append(Info(a[i].time, (a[i].p + b[j].p) % mod))
            i += 1
            j += 1
        elif a[i] > b[j]:
            if a[i].p:
                ans.append(a[i])
            i += 1
        else:
            if b[j].p:
                ans.append(b[j])
            j += 1
    while i < len(a):
        ans.append(a[i])
        i += 1
    while j < len(b):
        ans.append(b[j])
        j += 1
    return ans

def merge_dp(a, b):
    ra, rb = a[:], b[:]
    for i in range(len(a)):
        sum_ = 0
        j = 0
        while j < len(b) and b[j] >= a[i]:
            sum_ = add(sum_, b[j].p, mod)
            j += 1
        ra[i] = Info(ra[i].time, ra[i].p * sum_ % mod)
    for j in range(len(b)):
        sum_ = 0
        i = 0
        while i < len(a) and a[i] > b[j]:
            sum_ = add(sum_, a[i].p, mod)
            i += 1
        rb[j] = Info(rb[j].time, rb[j].p * sum_ % mod)
    return merge(ra, rb)

n = int(sys.stdin.readline().strip())
orig = [tuple(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
for i in range(n):
    orig[i] = (orig[i][0], orig[i][1], orig[i][2] * pow(100, mod - 2, mod) % mod)

all_info = [[[] for _ in range(4)] for _ in range(maxn)]
temp_info = [[] for _ in range(4)]
all_size = 0

for l in range(n - 1):
    for cate in range(4):
        r = l + 1
        p = 1
        dv = 0
        p *= orig[l][2] if cate & 1 else mod + 1 - orig[l][2]
        dv += orig[l][1] if cate & 1 else -orig[l][1]
        p *= orig[r][2] if cate & 2 else mod + 1 - orig[r][2]
        dv += -orig[r][1] if cate & 2 else orig[r][1]
        dv = max(0, dv)
        p %= mod
        all_info[l][cate] = [Info((orig[r][0] - orig[l][0], dv), p)]
        all_size += 1

for i in range(1 << (n - 1).bit_length()):
    for j in range((n - 1) // (1 << (i + 1)) + 1):
        no_a = j * (1 << (i + 1))
        no_b = no_a + (1 << i)
        if no_b >= n - 1:
            continue
        for f1 in range(2):
            for f2 in range(2):
                rans1 = merge_dp(all_info[no_a][f1], all_info[no_b][f2 << 1])
                p1 = pow(mod + 1 - orig[no_b][2], mod - 2, mod)
                for it in rans1:
                    it = Info(it.time, it.p * p1 % mod)
                rans2 = merge_dp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1])
                p2 = pow(orig[no_b][2], mod - 2, mod)
                for it in rans2:
                    it = Info(it.time, it.p * p2 % mod)
                temp_info[f1 + (f2 << 1)] = merge(rans1, rans2)
        for i in range(4):
            all_info[no_a][i] = temp_info[i]

ans = 0
for cate in range(4):
    for it in all_info[0][cate]:
        if it.time[1]:
            ans = add(ans, it.p * it.time[0] % mod * pow(it.time[1], mod - 2, mod))

print(ans)
