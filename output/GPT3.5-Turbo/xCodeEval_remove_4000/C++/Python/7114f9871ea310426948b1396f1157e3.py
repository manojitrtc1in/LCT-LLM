import sys
from typing import List, Tuple

MOD = int(1e9 + 7)


class modnum:
    def __init__(self, v: int):
        self.v = v % MOD
        if self.v < 0:
            self.v += MOD

    def __int__(self) -> int:
        return self.v

    def __str__(self) -> str:
        return str(self.v)

    def __eq__(self, other: 'modnum') -> bool:
        return self.v == other.v

    def __ne__(self, other: 'modnum') -> bool:
        return self.v != other.v

    def __add__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v + other.v)

    def __sub__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v - other.v)

    def __mul__(self, other: 'modnum') -> 'modnum':
        return modnum(self.v * other.v)

    def __neg__(self) -> 'modnum':
        return modnum(MOD - self.v)

    def __pow__(self, e: int) -> 'modnum':
        if e < 0:
            return modnum(1) / self.pow(-e)
        if e == 0:
            return modnum(1)
        if e & 1:
            return self * self.pow(e - 1)
        return (self * self).pow(e // 2)

    def inv(self) -> 'modnum':
        g = MOD
        x = 0
        y = 1
        r = self.v
        while r != 0:
            q = g // r
            g %= r
            x -= q * y
            x, y = y, x
            r, g = g, r
        assert g == 1
        assert y == MOD or y == -MOD
        return modnum(x + MOD if x < 0 else x)

    def __truediv__(self, other: 'modnum') -> 'modnum':
        return self * other.inv()

    def __floordiv__(self, other: 'modnum') -> 'modnum':
        return self / other

    def __iadd__(self, other: 'modnum') -> 'modnum':
        self.v += other.v
        if self.v >= MOD:
            self.v -= MOD
        return self

    def __isub__(self, other: 'modnum') -> 'modnum':
        self.v -= other.v
        if self.v < 0:
            self.v += MOD
        return self

    def __imul__(self, other: 'modnum') -> 'modnum':
        self.v = (self.v * other.v) % MOD
        return self

    def __idiv__(self, other: 'modnum') -> 'modnum':
        return self.__imul__(other.inv())

    def __ifloordiv__(self, other: 'modnum') -> 'modnum':
        return self.__idiv__(other)


def ckmin(a: int, b: int) -> None:
    a = min(a, b)


def ckmax(a: int, b: int) -> None:
    a = max(a, b)


def prefixes(v: List[int], id: int, op) -> List[int]:
    r = [id] * (len(v) + 1)
    for i in range(len(v)):
        r[i + 1] = op(r[i], v[i])
    return r


def suffixes(v: List[int], id: int, op) -> List[int]:
    r = [id] * (len(v) + 1)
    for i in range(len(v) - 1, -1, -1):
        r[i] = op(v[i], r[i + 1])
    return r


def dedup(v: List[int]) -> None:
    v.sort()
    v[:] = list(set(v))


def find(v: List[int], x: int) -> int:
    lo = 0
    hi = len(v)
    while lo < hi:
        mid = (lo + hi) // 2
        if v[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo if lo < len(v) and v[lo] == x else -1


def index(v: List[int], x: int) -> int:
    i = find(v, x)
    assert i != -1
    return i


def re(p: Tuple[int, int]) -> None:
    p = tuple(map(int, input().split()))


def re(a: List[int]) -> None:
    a = list(map(int, input().split()))


def re(a: List[int], sz: int) -> None:
    a = list(map(int, input().split()))


def pr(x: int) -> None:
    print(x, end='')


def pr(x: Tuple[int, int]) -> None:
    print(f'{{{x[0]}, {x[1]}}}', end='')


def pr(x: List[int]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        print(a, end='')
    print('}', end='')


def pr(x: List[List[int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
        if i > 0:
            print(', ', end='')
        pr(a)
    print('}', end='')


def pr(x: List[Tuple[int, int]]) -> None:
    print('{', end='')
    for i, a in enumerate(x):
