import sys

def read():
    return sys.stdin.readline().strip()

def read_int():
    return int(read())

def read_ints():
    return map(int, read().split())

def write(ans):
    sys.stdout.write(str(ans) + '\n')

def solve():
    n, k = read_ints()
    aa = list(read_ints())
    bb = [0] * n
    for i in range(n):
        bb[i-1] = aa[i]
    fac = [0] * (n+1)
    inv = [0] * (n+1)
    fac[0] = 1
    for i in range(1, n+1):
        fac[i] = (fac[i-1] * i) % mod
    inv[n] = ksm(fac[n], mod - 2)
    for i in range(n-1, -1, -1):
        inv[i] = (inv[i+1] * (i+1)) % mod
    ans = 1
    cnt = 0
    for i in range(n):
        if aa[i] == bb[i]:
            ans = (ans * k) % mod
        else:
            cnt += 1
    tmpans = 0
    for i in range(0, cnt+1, 2):
        anss = (ksm(k - 2, cnt - i) * C(i, i >> 1) * C(cnt, i)) % mod
        tmpans = (tmpans + anss) % mod
    ans = (tmpans * ans) % mod
    Ans = ksm(k, n)
    Ans -= ans
    if Ans < 0:
        Ans += mod
    write((Ans * ksm(2, mod - 2)) % mod)

mod = 998244353
solve()
