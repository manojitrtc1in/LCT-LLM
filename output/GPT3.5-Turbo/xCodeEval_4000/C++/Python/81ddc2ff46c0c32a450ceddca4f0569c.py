class ModInt:
    def __init__(self, x, mod):
        self.x = x % mod
        self.mod = mod

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x + other.x, self.mod)
        return ModInt(self.x + other, self.mod)

    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x - other.x, self.mod)
        return ModInt(self.x - other, self.mod)

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * other.x, self.mod)
        return ModInt(self.x * other, self.mod)

    def __pow__(self, n):
        if n == 0:
            return ModInt(1, self.mod)
        if n % 2 == 0:
            return (self * self) ** (n // 2)
        return self * (self ** (n - 1))

    def __str__(self):
        return str(self.x)

def solve():
    n, m = map(int, input().split())

    dp = [ModInt(0, m) for _ in range(n + 1)]
    p = [ModInt(0, m) for _ in range(n + 1)]

    dp[n] = ModInt(1, m)
    p[n] = ModInt(1, m)

    for i in range(n - 1, 0, -1):
        dp[i] += p[i + 1]

        for z in range(2, (n // i) + 1):
            l = i * z
            r = i * z + z
            dp[i] += p[l]
            if r <= n:
                dp[i] -= p[r]

        p[i] = p[i + 1] + dp[i]

    print(dp[1])

solve()
