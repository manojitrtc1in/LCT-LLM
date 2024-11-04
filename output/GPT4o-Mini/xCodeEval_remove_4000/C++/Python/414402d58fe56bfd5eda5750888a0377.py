import sys
from typing import List, Tuple, TypeVar, Generic, Any

T = TypeVar('T')

class Modular:
    def __init__(self, value: int, mod: int):
        self.value = value % mod
        self.mod = mod

    def __add__(self, other: Any) -> 'Modular':
        if isinstance(other, Modular):
            return Modular(self.value + other.value, self.mod)
        return Modular(self.value + other, self.mod)

    def __sub__(self, other: Any) -> 'Modular':
        if isinstance(other, Modular):
            return Modular(self.value - other.value, self.mod)
        return Modular(self.value - other, self.mod)

    def __mul__(self, other: Any) -> 'Modular':
        if isinstance(other, Modular):
            return Modular(self.value * other.value, self.mod)
        return Modular(self.value * other, self.mod)

    def __truediv__(self, other: Any) -> 'Modular':
        if isinstance(other, Modular):
            return self * Modular(inverse(other.value, self.mod), self.mod)
        return self * Modular(other, self.mod)

    def __call__(self) -> int:
        return self.value

    def __str__(self) -> str:
        return str(self.value)

def inverse(a: int, m: int) -> int:
    u, v = 0, 1
    while a != 0:
        t = m // a
        m -= t * a
        u -= t * v
        a, m = m, a
    assert m == 1
    return u % m

def main():
    md = 10**9 + 7
    mint = Modular(0, md)

    d = [0] * 123
    dp = [mint] * 7
    new_dp = [mint] * 7

    input = sys.stdin.read
    data = input().split()
    tt = int(data[0])
    index = 1

    for _ in range(tt):
        m = int(data[index])
        index += 1
        len_d = 0
        while m > 0:
            d[len_d] = m & 1
            m >>= 1
            len_d += 1

        for i in range(7):
            dp[i] = new_dp[i] = Modular(0, md)
        dp[0] = Modular(1, md)

        for it in range(len_d - 1, -1, -1):
            if d[it] == 0:
                new_dp[0] = dp[0] + dp[1] + dp[2] + dp[3]
                new_dp[1] = new_dp[2] = dp[1] + dp[2] + dp[3] + dp[4]
                new_dp[3] = new_dp[4] = dp[2] + dp[3] + dp[4] + dp[5]
                new_dp[5] = new_dp[6] = dp[3] + dp[4] + dp[5] + dp[6]
            else:
                new_dp[0] = new_dp[1] = dp[0] + dp[1] + dp[2] + dp[3]
                new_dp[2] = new_dp[3] = dp[1] + dp[2] + dp[3] + dp[4]
                new_dp[4] = new_dp[5] = dp[2] + dp[3] + dp[4] + dp[5]
                new_dp[6] = dp[3] + dp[4] + dp[5] + dp[6]

            dp, new_dp = new_dp, dp

        print(dp[0]())

if __name__ == "__main__":
    main()
