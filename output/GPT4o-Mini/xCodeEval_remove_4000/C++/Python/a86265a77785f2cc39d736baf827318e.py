import sys

mod = 998244353

def gc():
    return sys.stdin.read(1)

def readalpha():
    while True:
        c = gc()
        if c.isalpha():
            return c

def readchar():
    while True:
        c = gc()
        if c != ' ':
            return c

def read():
    flg = False
    x = 0
    while True:
        c = gc()
        if c == '-':
            flg = True
        elif c.isdigit():
            break
        elif c == '':
            return False
    while c.isdigit():
        x = x * 10 + (ord(c) - ord('0'))
        c = gc()
    if flg:
        x = -x
    return x

def write(x):
    if x < 0:
        sys.stdout.write('-')
        x = -x
    if x < 10:
        sys.stdout.write(chr(x + ord('0')))
        return
    write(x // 10)
    sys.stdout.write(chr((x % 10) + ord('0')))

def id0(x):
    write(x)
    sys.stdout.write(' ')

def writeln(x):
    write(x)
    sys.stdout.write('\n')

maxn = 200005

n, k = read(), read()
aa = [0] * (maxn)
bb = [0] * (maxn)

def nxt(x):
    x += 1
    if x > n:
        x = 1
    return x

def pre(x):
    x -= 1
    if x < 1:
        x = n
    return x

def add(x, y):
    x += y
    if x >= mod:
        x -= mod
    return x

def ksm(a, b):
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % mod
        a = a * a % mod
        b >>= 1
    return ans

fac = [0] * (maxn)
inv = [0] * (maxn)

def C(n, m):
    return fac[n] * inv[m] % mod * inv[n - m] % mod

for i in range(1, n + 1):
    aa[i] = read()
    bb[pre(i)] = aa[i]

fac[0] = 1
for i in range(1, n + 1):
    fac[i] = fac[i - 1] * i % mod

inv[n] = ksm(fac[n], mod - 2)
for i in range(n - 1, -1, -1):
    inv[i] = inv[i + 1] * (i + 1) % mod

ans = 1
cnt = 0

for i in range(1, n + 1):
    if aa[i] == bb[i]:
        ans = ans * k % mod
    else:
        cnt += 1

tmpans = 0
for i in range(0, cnt + 1, 2):
    anss = ksm(k - 2, cnt - i) * C(i, i // 2) % mod * C(cnt, i) % mod
    tmpans = add(tmpans, anss)

ans = tmpans * ans % mod

Ans = ksm(k, n)
Ans -= ans
if Ans < 0:
    Ans += mod

writeln(Ans * ksm(2, mod - 2) % mod)
