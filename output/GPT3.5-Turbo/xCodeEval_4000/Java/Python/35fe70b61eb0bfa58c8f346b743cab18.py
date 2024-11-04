import sys
from typing import List
from math import comb

def solve() -> None:
    n = int(input())
    tmp = int(input())
    if n <= tmp:
        print(0)
        return
    k = tmp
    preFact(400000)
    ans = 0
    si = 1
    t = comb(n, n-k)
    for i in range(n-k, 0, -1):
        ans += si * comb(n-k, i) * pow(i, n)
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
        print("error : factorials has not been calculated!! do [pre_factorial] method", file=sys.stderr)
    af = fact[a]
    bf = revFact[b]
    abf = revFact[a - b]
    res = mul(mul(af, bf), abf)
    return res

inf = float('inf')
linf = float('inf')
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
    len_ar = len(ar)
    for i in range(len_ar // 2):
        ar[i], ar[len_ar - 1 - i] = ar[len_ar - 1 - i], ar[i]

def getReverse(s: str) -> str:
    return s[::-1]

def reverseList(ls: List) -> None:
    sz = len(ls)
    for i in range(sz // 2):
        ls[i], ls[sz - 1 - i] = ls[sz - 1 - i], ls[i]

def sbnl() -> None:
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

def rlowerBound(a: List[int], x: int) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def rupperBound(a: List[int], x: int) -> int:
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

def rlowerBound(a: List[float], x: float) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def rupperBound(a: List[float], x: float) -> int:
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

def rlowerBound(a: List[str], x: str) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def rupperBound(a: List[str], x: str) -> int:
    l = -1
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def concat(x: int, arr: List[int]) -> List[int]:
    return [x] + arr

def concat(arr: List[int], x: int) -> List[int]:
    return arr + [x]

def concat(x: float, arr: List[float]) -> List[float]:
    return [x] + arr

def concat(arr: List[float], x: float) -> List[float]:
    return arr + [x]

def concat(x: str, arr: List[str]) -> List[str]:
    return [x] + arr

def concat(arr: List[str], x: str) -> List[str]:
    return arr + [x]

def maximum(x: int, y: int) -> int:
    return max(x, y)

def minimum(x: int, y: int) -> int:
    return min(x, y)

def maximum(x: int, y: int, z: int) -> int:
    return max(x, y, z)

def minimum(x: int, y: int, z: int) -> int:
    return min(x, y, z)

def maximum(x: float, y: float) -> float:
    return max(x, y)

def minimum(x: float, y: float) -> float:
    return min(x, y)

def maximum(x: float, y: float, z: float) -> float:
    return max(x, y, z)

def minimum(x: float, y: float, z: float) -> float:
    return min(x, y, z)

def plus(x: int, y: int) -> int:
    res = (x + y) % mod
    return res if res >= 0 else res + mod

def sub(x: int, y: int) -> int:
    res = (x - y) % mod
    return res if res >= 0 else res + mod

def mul(x: int, y: int) -> int:
    return (x * y) % mod

def div(x: int, y: int) -> int:
    return (x * pow(y, mod - 2, mod)) % mod

def pow(x: int, y: int) -> int:
    if y < 0:
        return 0
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x * pow(x, y - 1)) % mod
    root = pow(x, y // 2)
    return (root * root) % mod

def main() -> None:
    solve()

if __name__ == "__main__":
    main()
