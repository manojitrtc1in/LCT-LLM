import sys
from typing import List, Tuple, Dict, Any

MOD = int(1e9 + 7)


class Ring:
    def __init__(self, value: int = 0):
        self.value = value % MOD

    def pow(self, p: int) -> 'Ring':
        r = Ring(1)
        x = Ring(self.value)
        while p:
            if p & 1:
                r *= x
            x *= x
            p //= 2
        return r

    def inv(self) -> 'Ring':
        return self.pow(MOD - 2)

    def __mul__(self, b: 'Ring') -> 'Ring':
        return Ring(self.value * b.value)

    def __imul__(self, b: 'Ring') -> None:
        self.value = (self.value * b.value) % MOD

    def __add__(self, b: 'Ring') -> 'Ring':
        return Ring(self.value + b.value)

    def __iadd__(self, b: 'Ring') -> None:
        self.value = (self.value + b.value) % MOD

    def __sub__(self, b: 'Ring') -> 'Ring':
        return Ring(self.value - b.value)

    def __isub__(self, b: 'Ring') -> None:
        self.value = (self.value - b.value + MOD) % MOD

    def __truediv__(self, b: 'Ring') -> 'Ring':
        return self * b.inv()

    def __idiv__(self, b: 'Ring') -> None:
        self *= b.inv()

    def __eq__(self, b: 'Ring') -> bool:
        return self.value == b.value

    def __ne__(self, b: 'Ring') -> bool:
        return self.value != b.value

    def __repr__(self) -> str:
        return str(self.value)


def binom(n: int, k: int) -> Ring:
    if k > n:
        return Ring(0)
    return fact[n] / (fact[n - k] * fact[k])


fact = [Ring(1)]


def main(args: List[str]) -> None:
    n = int(args[0])
    for i in range(n + 100):
        fact.append(fact[-1] * Ring(i + 1))
    v = list(map(int, args[1:n+1]))
    for i in range(n):
        for j in range(2, int(v[i] ** 0.5) + 1):
            while v[i] % j == 0 and (v[i] // j) % j == 0:
                v[i] //= j
                v[i] //= j
    cnt: Dict[int, int] = {}
    for x in v:
        cnt[x] = cnt.get(x, 0) + 1
    c = list(cnt.values())
    dp = [Ring(0)] * (n + 10)
    dp[0] = Ring(1)
    for x in c:
        ndp = [Ring(0)] * (n + 10)
        for i in range(len(dp)):
            if dp[i].value:
                for j in range(x):
                    dist = x - j
                    ndp[i + dist] += dp[i] * binom(x - 1, j) * binom(i + dist, dist)
        dp = ndp
    conds = n - len(c)
    final = Ring(0)
    sign = Ring(1)
    for i in range(conds + 1):
        final += sign * dp[n - i]
        sign = Ring(-1) * sign
    for x in c:
        final *= fact[x]
    print(final)


if __name__ == '__main__':
    main(sys.argv[1:])
