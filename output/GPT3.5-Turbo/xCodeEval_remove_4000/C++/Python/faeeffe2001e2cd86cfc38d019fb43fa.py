import sys
from typing import List
from math import isqrt

class InfInt:
    def __init__(self, val: int = 0):
        self.val = val

    def __str__(self) -> str:
        return str(self.val)

    def __mul__(self, other: 'InfInt') -> 'InfInt':
        return InfInt(self.val * other.val)

    def __add__(self, other: 'InfInt') -> 'InfInt':
        return InfInt(self.val + other.val)

    def __sub__(self, other: 'InfInt') -> 'InfInt':
        return InfInt(self.val - other.val)

    def __eq__(self, other: 'InfInt') -> bool:
        return self.val == other.val

    def __lt__(self, other: 'InfInt') -> bool:
        return self.val < other.val

    def __le__(self, other: 'InfInt') -> bool:
        return self.val <= other.val

    def __gt__(self, other: 'InfInt') -> bool:
        return self.val > other.val

    def __ge__(self, other: 'InfInt') -> bool:
        return self.val >= other.val

    def __bool__(self) -> bool:
        return self.val != 0

    def int_sqrt(self) -> 'InfInt':
        return InfInt(isqrt(self.val))

    def __mul__(self, other: int) -> 'InfInt':
        return InfInt(self.val * other)

    def __rmul__(self, other: int) -> 'InfInt':
        return self * other

    def __add__(self, other: int) -> 'InfInt':
        return InfInt(self.val + other)

    def __radd__(self, other: int) -> 'InfInt':
        return self + other

    def __sub__(self, other: int) -> 'InfInt':
        return InfInt(self.val - other)

    def __rsub__(self, other: int) -> 'InfInt':
        return -(self - other)

    def __neg__(self) -> 'InfInt':
        return InfInt(-self.val)

    def __abs__(self) -> 'InfInt':
        return InfInt(abs(self.val))

    def __pow__(self, power: int) -> 'InfInt':
        return InfInt(self.val ** power)

    def __truediv__(self, other: 'InfInt') -> 'InfInt':
        return InfInt(self.val // other.val)

    def __floordiv__(self, other: 'InfInt') -> 'InfInt':
        return self / other

    def __mod__(self, other: 'InfInt') -> 'InfInt':
        return InfInt(self.val % other.val)

    def __divmod__(self, other: 'InfInt') -> 'InfInt':
        return self // other, self % other

    def __div__(self, other: 'InfInt') -> 'InfInt':
        return self / other

    def __rdiv__(self, other: 'InfInt') -> 'InfInt':
        return other / self

    def __int__(self) -> int:
        return self.val

    def __long__(self) -> int:
        return self.val

    def __float__(self) -> float:
        return float(self.val)

    def __complex__(self) -> complex:
        return complex(self.val)

    def __index__(self) -> int:
        return self.val

    def __hash__(self) -> int:
        return hash(self.val)

    def __repr__(self) -> str:
        return f'InfInt({self.val})'

def alpha(n: int) -> InfInt:
    cnt, res = 10, InfInt(1)
    for i in range(min(n, 11)):
        res *= cnt
        cnt = max(cnt - 1, 0)
    return res

def beta(n: int) -> InfInt:
    cnt, res = 9, InfInt(9)
    for i in range(min(n - 1, 11)):
        res *= cnt
        cnt = max(cnt - 1, 0)
    return res

def power(n: InfInt, p: int) -> InfInt:
    if p <= 0:
        return InfInt(1)
    x = power(n, p // 2)
    if p & 1:
        return x * x * n
    else:
        return x * x

def solve(s: str) -> InfInt:
    leading = s[0]
    if leading.isdigit():
        lead = False
    else:
        lead = True
    bits = [False] * 30
    cnt = 0
    for c in s:
        if c.isalpha():
            bits[ord(c) - ord('A')] = True
        elif c == '?':
            cnt += 1
    if not lead:
        res = alpha(bits.count(True)) * power(10, cnt)
    else:
        if leading == '?':
            res = alpha(bits.count(True)) * power(10, cnt - 1) * 9
        else:
            res = beta(bits.count(True)) * power(10, cnt)
    return res

def main() -> None:
    s = input()
    res = solve(s)
    print(res)

if __name__ == '__main__':
    main()
