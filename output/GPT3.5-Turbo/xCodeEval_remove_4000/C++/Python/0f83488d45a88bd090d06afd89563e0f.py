import sys
from collections import defaultdict

def undefinedBehaviour():
    pass

def countBits(v):
    v = v - ((v >> 1) & 0x55555555)
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24

def reverseBits(x):
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1))
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2))
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4))
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8))
    return ((x >> 16) | (x << 16))

def sign(x):
    return 1 if x > 0 else -1 if x < 0 else 0

def id4(x):
    return (x != 0 and (x & (x - 1)) == 0)

def power(x, p):
    return 1 if p == 0 else (x * power(x, p - 1))

def inRange(val, min, max):
    return min <= val and val <= max

def id7():
    return __builtin_readcyclecounter()

def readInt():
    c = lambda: sys.stdin.readline().strip()
    c()
    while *__ir and (*__ir < '0' or *__ir > '9') and *__ir != '-':
        ++__ir
        c()
    m = False
    if *__ir == '-':
        ++__ir
        c()
        m = True
    r = 0
    while *__ir >= '0' and *__ir <= '9':
        r = r * 10 + *__ir - '0'
        ++__ir
        c()
    ++__ir
    return -r if m else r

def readString():
    c = lambda: sys.stdin.readline().strip()
    r = ''
    c()
    while *__ir and isspace(*__ir):
        ++__ir
        c()
    while not isspace(*__ir):
        r.push_back(*__ir)
        ++__ir
        c()
    ++__ir
    return r

def readChar():
    c = lambda: sys.stdin.readline().strip()
    c()
    while *__ir and isspace(*__ir):
        ++__ir
        c()
    return *__ir++

def writeInt(x, endc = '\n'):
    if x < 0:
        *__iw++ = '-'
        x = -x
    if x == 0:
        *__iw++ = '0'
    s = __iw
    while x:
        t = x / 10
        c = x - 10 * t + '0'
        *__iw++ = c
        x = t
    f = __iw - 1
    while s < f:
        swap(*s, *f)
        ++s
        --f
    if __iw > __ew:
        sys.stdout.write(id10, __iw - id10)
        __iw = id10
    if endc:
        *__iw++ = endc

def writeStr(str):
    i = 0
    while str[i]:
        *__iw++ = str[i++]
        if __iw > __ew:
            sys.stdout.write(id10, __iw - id10)
            __iw = id10

class __FL__:
    def __del__(self):
        if __iw != id10:
            sys.stdout.write(id10, __iw - id10)
        id2 = __FL__()

def solve():
    w = [[]]
    used = {0: 0}
    dc = [0] * (F * 2)
    g = [[] for _ in range(F * 2)]
    ans = [[0] * 303 for _ in range(303)]
    n = readInt()
    for _ in range(n):
        a = readInt()
        b = readInt()
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        writeInt(ans[a][b])

def main():
    w = [[]]
    used = {0: 0}
    dc = [0] * (F * 2)
    g = [[] for _ in range(F * 2)]
    ans = [[0] * 303 for _ in range(303)]
    n = readInt()
    for _ in range(n):
        a = readInt()
        b = readInt()
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        writeInt(ans[a][b])

if __name__ == "__main__":
    main()
