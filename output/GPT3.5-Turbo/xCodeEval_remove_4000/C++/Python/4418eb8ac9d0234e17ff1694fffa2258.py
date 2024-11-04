import math

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
    i = 0
    j = 0
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
    ra = a
    rb = b
    for i in range(len(a)):
        j = 0
        sum = 0
        while j < len(b) and b[j] >= a[i]:
            sum += b[j].p
            j += 1
        ra[i].p *= sum
        ra[i].p %= mod
    for j in range(len(b)):
        i = 0
        sum = 0
        while i < len(a) and a[i] > b[j]:
            sum += a[i].p
            i += 1
        rb[j].p *= sum
        rb[j].p %= mod
    return merge(ra, rb)

def pow(n, m, mod):
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

def add(a, b, mod):
    if mod == -1:
        mod = 998244353
    a += b
    while a >= mod:
        a -= mod
    while a < 0:
        a += mod
    return a

def main():
    n = int(input())
    orig = []
    for _ in range(n):
        a, b, c = map(int, input().split())
        c *= pow(100, mod - 2, mod)
        c %= mod
        orig.append((a, (b, c)))
    
    all_info = [[[] for _ in range(4)] for _ in range(n - 1)]
    all_size = 0
    
    for l in range(n - 1):
        for cate in range(4):
            r = l + 1
            p = 1
            dv = 0
            p *= orig[l][1][1] if cate & 1 else mod + 1 - orig[l][1][1]
            dv += orig[l][1][0] if cate & 1 else -orig[l][1][0]
            p *= orig[r][1][1] if cate & 2 else mod + 1 - orig[r][1][1]
            dv += -orig[r][1][0] if cate & 2 else orig[r][1][0]
            dv = max(0, dv)
            p %= mod
            all_info[l][cate] = [Info((orig[r][0] - orig[l][0], dv), p)]
            all_size += 1
    
    temp_info = [[] for _ in range(4)]
    
    for i in range(int(math.log2(n - 1))):
        for j in range((n - 1) // (1 << (i + 1))):
            no_a = j * (1 << (i + 1))
            no_b = no_a + (1 << i)
            if no_b >= n - 1:
                continue
            for f1 in range(2):
                for f2 in range(2):
                    rans1 = merge_dp(all_info[no_a][f1], all_info[no_b][f2 << 1])
                    p1 = pow(mod + 1 - orig[no_b][1][1], mod - 2, mod)
                    for it in rans1:
                        it.p *= p1
                        it.p %= mod
                    rans2 = merge_dp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1])
                    p2 = pow(orig[no_b][1][1], mod - 2, mod)
                    for it in rans2:
                        it.p *= p2
                        it.p %= mod
                    temp_info[f1 + (f2 << 1)] = merge(rans1, rans2)
            for i in range(4):
                all_info[no_a][i] = temp_info[i]
    
    ans = 0
    for cate in range(4):
        for it in all_info[0][cate]:
            if it.time[1]:
                ans += it.p * it.time[0] % mod * pow(it.time[1], mod - 2, mod)
                ans %= mod
    print(ans)

if __name__ == "__main__":
    main()
