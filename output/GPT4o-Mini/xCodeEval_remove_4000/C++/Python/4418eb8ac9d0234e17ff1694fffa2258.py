import sys
from collections import defaultdict
from math import gcd

MOD = 998244353
maxn = 100100

def pow_mod(n, m, mod=0):
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

class Info:
    def __init__(self, time, p):
        self.time = time
        self.p = p

    def __lt__(self, other):
        return self.time[0] * other.time[1] < self.time[1] * other.time[0]

    def __eq__(self, other):
        return self.time[0] * other.time[1] == self.time[1] * other.time[0]

    def __gt__(self, other):
        return other < self

    def __le__(self, other):
        return self < other or self == other

    def __ge__(self, other):
        return other < self or self == other

def merge(a, b):
    ans = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] == b[j]:
            ans.append(Info(a[i].time, (a[i].p + b[j].p) % MOD))
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
    ra = a[:]
    rb = b[:]
    for i in range(len(a)):
        sum_p = 0
        j = 0
        while j < len(b) and b[j] >= a[i]:
            sum_p += b[j].p
            sum_p %= MOD
            j += 1
        ra[i].p *= sum_p
        ra[i].p %= MOD
    for j in range(len(b)):
        sum_p = 0
        i = 0
        while i < len(a) and a[i] > b[j]:
            sum_p += a[i].p
            sum_p %= MOD
            i += 1
        rb[j].p *= sum_p
        rb[j].p %= MOD
    return merge(ra, rb)

n = int(sys.stdin.readline().strip())
orig = [tuple(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]

all_info = [[[] for _ in range(4)] for _ in range(maxn)]
all_size = 0

for l in range(n - 1):
    for cate in range(4):
        r = l + 1
        p = 1
        dv = 0
        p *= (cate & 1) * orig[l][2] + (1 - (cate & 1)) * (MOD + 1 - orig[l][2])
        dv += (cate & 1) * orig[l][1] - (1 - (cate & 1)) * orig[l][1]
        p *= (cate & 2) * orig[r][2] + (1 - (cate & 2)) * (MOD + 1 - orig[r][2])
        dv += (cate & 2) * -orig[r][1] + (1 - (cate & 2)) * orig[r][1]
        dv = max(0, dv)
        p %= MOD
        all_info[l][cate] = [Info((orig[r][0] - orig[l][0], dv), p)]
        all_size += 1

for i in range(20):
    for j in range((n - 1) // (1 << (i + 1)) + 1):
        no_a = j * (1 << (i + 1))
        no_b = no_a + (1 << i)
        if no_b >= n - 1:
            continue
        temp_info = [None] * 4
        for f1 in range(2):
            for f2 in range(2):
                rans1 = merge_dp(all_info[no_a][f1], all_info[no_b][f2 << 1])
                p1 = pow_mod(MOD + 1 - orig[no_b][2], MOD - 2, MOD)
                for it in rans1:
                    it.p *= p1
                    it.p %= MOD
                rans2 = merge_dp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1])
                p2 = pow_mod(orig[no_b][2], MOD - 2, MOD)
                for it in rans2:
                    it.p *= p2
                    it.p %= MOD
                temp_info[f1 + (f2 << 1)] = merge(rans1, rans2)
        for i in range(4):
            all_info[no_a][i] = temp_info[i]

ans = 0
for cate in range(4):
    for it in all_info[0][cate]:
        if it.time[1]:
            ans += it.p * it.time[0] % MOD * pow_mod(it.time[1], MOD - 2, MOD)
            ans %= MOD

print(ans)
