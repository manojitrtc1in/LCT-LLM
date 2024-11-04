import sys
from typing import List

def solve() -> None:
    n = ni()
    tmp = nl()
    if n <= tmp:
        print(0)
        return
    k = int(tmp)
    preFact(400000)
    ans = 0
    si = 1
    t = cmb(n, n-k)
    for i in range(n-k, 0, -1):
        ans += si * cmb(n-k, i) * pow(i, n)
        ans %= mod
        if ans < 0:
            ans += mod
        si *= -1
    ans *= t
    ans %= mod
    if k != 0:
        ans *= 2
    ans %= mod
    if ans < 0:
        ans += mod
    print(ans)

def preFact(n: int) -> None:
    global fact, revFact
    fact = [0] * (n + 1)
    revFact = [0] * (n + 1)
    fact[0] = 1
    for i in range(n):
        fact[i + 1] = mul(i + 1, fact[i])
    revFact[n] = div(1, fact[n])
    for i in range(n - 1, -1, -1):
        revFact[i] = mul(revFact[i + 1], i + 1)

def cmb(a: int, b: int) -> int:
    if a < b:
        return 0
    if len(fact) == 0:
        print("error : factorials has not been culculated!! do [pre_factorial] method", file=sys.stderr)
    af = fact[a]
    bf = revFact[b]
    abf = revFact[a - b]
    res = mul(mul(af, bf), abf)
    return res

inf = sys.maxsize // 2
linf = sys.maxsize // 3
dinf = float('inf')
mod = 998244353
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
eps = 1e-10
pi = 3.141592653589793
sb = []

def reverse(ar: List[int]) -> None:
    for i in range(len(ar) // 2):
        ar[i], ar[len(ar) - 1 - i] = ar[len(ar) - 1 - i], ar[i]

def getReverse(s: str) -> str:
    return s[::-1]

def reverseList(ls: List[int]) -> None:
    for i in range(len(ls) // 2):
        ls[i], ls[len(ls) - 1 - i] = ls[len(ls) - 1 - i], ls[i]

def id2() -> None:
    sb.append("\n")

def lowerBound(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] < x:
            l = c
        else:
            r = c
    return r

def upperBound(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] <= x:
            l = c
        else:
            r = c
    return r

def id3(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def id0(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def lowerBound(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] < x:
            l = c
        else:
            r = c
    return r

def upperBound(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] <= x:
            l = c
        else:
            r = c
    return r

def id3(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def id0(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def lowerBound(a: List[float], x: float) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] < x:
            l = c
        else:
            r = c
    return r

def upperBound(a: List[float], x: float) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] <= x:
            l = c
        else:
            r = c
    return r

def id3(a: List[float], x: float) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def id0(a: List[float], x: float) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def lowerBound(a: List[str], x: str) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] < x:
            l = c
        else:
            r = c
    return r

def upperBound(a: List[str], x: str) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] <= x:
            l = c
        else:
            r = c
    return r

def id3(a: List[str], x: str) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def id0(a: List[str], x: str) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def lowerBound(ls: List[int], x: int) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_left(ls, x))

def upperBound(ls: List[int], x: int) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_right(ls, x))

def id0(ls: List[int], x: int) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_left(ls, x))

def id3(ls: List[int], x: int) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_right(ls, x))

def lowerBound(ls: List[float], x: float) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_left(ls, x))

def upperBound(ls: List[float], x: float) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_right(ls, x))

def id0(ls: List[float], x: float) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_left(ls, x))

def id3(ls: List[float], x: float) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_right(ls, x))

def lowerBound(ls: List[str], x: str) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_left(ls, x))

def upperBound(ls: List[str], x: str) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_right(ls, x))

def id0(ls: List[str], x: str) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_left(ls, x))

def id3(ls: List[str], x: str) -> int:
    if len(ls) == 0:
        return -1
    return ~ls.index(x, bisect_right(ls, x))

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

